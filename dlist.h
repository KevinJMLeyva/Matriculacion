#ifndef DLIST_H_
#define DLIST_H_


#include <cstdio>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include "exception.h"
using namespace std;
class DLink 
{ 
  public:

  std::string data; 
  DLink *next, *prev; 

    DLink();
    DLink(std::string);


    DLink *split(DLink *); 
    void insert(DLink **, std::string ) ;
    DLink *merge(DLink *, DLink *);
    DLink *mergeSort(DLink *);

    void print(DLink *);
    void printMatriculas(DLink *);
    void guardarMatriculas(DLink *,string);

}; 

//Inicializar un nodo vacio
DLink::DLink(){
    data="0";
    prev=0;
    next=0;
}

//Inicializar un nodo con darta
DLink::DLink(std::string val){
    data=val;
    prev=0;
    next=0;
}

//Dvidir una DBL a la mitad para poder realizar el merge sort, en está implementación se visualiza desde los nodos y las operaciones se lelvan acabo en los nosdos
DLink * DLink::split(DLink *head) 
{ 
  DLink *fast = head,*slow = head; 
  while (fast->next && fast->next->next) 
  { 
    fast = fast->next->next; 
    slow = slow->next; 
  } 
  DLink *temp = slow->next; 
  slow->next = NULL; 
  return temp; 
} 

//Se unen las dos parte ordendas o semi ordenadas de un DBL (Double linked list)
DLink * DLink::merge(DLink *first, DLink *second) 
{ 

  if (!first) 
    return second; 


  if (!second) 
    return first; 

  //Toma el valor menot
  if (first->data < second->data) 
  { 
    first->next = merge(first->next,second); 
    first->next->prev = first; 
    first->prev = NULL; 
    return first; 
  } 
  else
  { 
    second->next = merge(first,second->next); 
    second->next->prev = second; 
    second->prev = NULL; 
    return second; 
  } 
} 

//Algoritmo de complejidad log(n) para poder orendar una serie de datos, en este caso con una organización de DBL, este algoritmo
//Divide en parte más pequeñas toda la esctructura y ordena por segementos, para después unirlos
DLink * DLink::mergeSort(DLink *head) 
{ 
  if (!head || !head->next) 
    return head; 
  DLink *second = split(head); 

  // Parte izquierda y derecha de la lista
  head = mergeSort(head); 
  second = mergeSort(second); 

  // Une las dos partes de la lsita
  return merge(head,second); 
} 

//Insertar para crear DBL
void DLink::insert(DLink **head,	std::string data) 
{ 
  DLink *temp = new DLink();
  temp->data = data; 
  temp->next = temp->prev = NULL; 
  if (!(*head)) 
    (*head) = temp; 
  else
  { 
    temp->next = *head; 
    (*head)->prev = temp; 
    (*head) = temp; 
  } 
} 

//FUNCION de print, simplemente recorre de izquiera derecha el arreglo y lo acomoda visualmente
void DLink::print(DLink *head) 
{ 
  int i=1;
  while (head) 
  { 
    cout << i<<". " <<head->data << " "; 
        cout  << "\n";
    head = head->next; 
    i++;
  } 
} 


//Mismo funcionamiento que el print anterior, simplemente agrega más detalles para mostrar las matriculas
void DLink::printMatriculas(DLink *head) 
{ 
  int i=1;
  while (head) 
  { 
    if (i<=9){
    cout << i<<". " <<head->data << "   A00"<<i; //Los ifs hacen que 
        cout  << "\n";
    head = head->next;
    }
    else if (99>=i and i>9){
    cout << i<<". " <<head->data << "   A0"<<i; 
        cout  << "\n";
    head = head->next;
    }
    else if (i>99){
    cout << i<<". " <<head->data << "   A"<<i; 
        cout  << "\n";
    head = head->next;
    }
    i++;
  } 
} 


//Abrimos el archivo donde guardaremos las matrículas, y usamos la forma vista anteriormente
void DLink::guardarMatriculas(DLink *head,string nombre_archivo) 
{ 
  fstream newfile;
  newfile.open(nombre_archivo,ios::out);
  int i=1;
  while (head) 
  { 
    if (i<=9){
    newfile << i<<". " <<head->data << "   A00"<<i; 
        newfile  << "\n";
    head = head->next;
    }
    else if (99>=i and i>9){
    newfile << i<<". " <<head->data << "   A0"<<i; 
        newfile  << "\n";
    head = head->next;
    }
    else if (i>99){
    newfile << i<<". " <<head->data << "   A"<<i; 
        newfile  << "\n";
    head = head->next;
    }
    i++;
  } 
  newfile.close(); 
} 


//Clase que funciona para poder utilizar como una lista al DBL, es decir indices, sizes, etc
class DList
{ 
  public: 
    DList();
    bool empty() const;
    int  length() const;

    bool contains(std::string) const;
    std::string getFirst() const;
    std::string get(int) const;
    int indexOf(std::string) const;
    bool set(int, std::string);

    void addFirst(std::string);
    void add(std::string);

    std::string removeFirst();
    std::string remove(int);

    void ordena();

    void print();
    void printMatriculas();
    void guardarMatriculas(std::string);

  DLink *head; 
  DLink *tail;
  int size;
}; 

//Inicializar la lista
DList::DList() : head(0), tail(0), size(0) {}
bool DList::empty() const {
  return (head == 0 && tail == 0);
}
int DList::length() const {
  return size;
}

//Comprueba si un elemento se enceutra dentro de la lista
bool DList::contains(std::string val) const {
  DLink *p;
  p = head;
  while (p != 0) {
    if (p->data == val) {
      return true;
    }
    p = p->next;
  }
  return false;
}

//Devuelve el valor de un indice dado, se tiene una complejidad de n/2, ya que parte de la mita y toma en cuenta si el
//indice es mayor o menor a la mitda
std::string DList::get(int index) const {
  int pos;
  DLink *p;

  if (index < 0 || index >= size) {
    throw IndexOutOfBounds();
  }

  if (index == 0) {
    return getFirst();
    }

    if(index/2<size){
    p = head;
    pos = 0;
        while (pos != index) {
        p = p->next;
        pos++;
        }
            return p->data;
    }
    else if(size<=index/2){
        p = tail;
        pos = size;
        while (pos != index) {
            p = p->next;
            pos--;
        }
        return p->data;
    }
    return "0";
}

//Devuelve el primer valor de la lista
std::string DList::getFirst() const{
  if (empty()) {
    throw NoSuchElement();
  }
  return head->data;
}

//Recorre toda la lista y devuelve el valor del indice de un dato que se busque, en caso de que
// el dato no se encuentre devolverá menos uno
int DList::indexOf(std::string val) const {
  int index;
  DLink *p;

  index = 0;
  p = head;
  while (p != 0) {
    if (p->data== val) {
      return index;
    }
    index++;
    p = p->next;
  }
  return -1;
}

//Sumar a la lista
void DList::addFirst(std::string val){
  DLink *newLink;

  newLink = new DLink(val);
  if (newLink == 0) {
    throw OutOfMemory();
  }

  if (empty()) {
    head = newLink;
    tail = newLink;
  } else {
    newLink->next = head;
    head->prev = newLink;
    head = newLink;
  }
  size++;
}

//Añade a la lista, para lo cual la recorre completamente
void DList::add(std::string val){
  DLink *newLink;

  newLink = new DLink(val);
  if (newLink == 0) {
    throw OutOfMemory();
  }

  if (empty()) {
    head = newLink;
    tail = newLink;
  } else {
    tail->next = newLink;
    newLink->prev = tail;
    tail = newLink;
  }
  size++;
}

//Elimina el primer valor de la lista
std::string DList::removeFirst(){

  DLink *p;
    std::string val;

  if (empty()) {
    throw NoSuchElement();
  }

  p = head;
  val = p->data;

  if (head == tail) {
    head = 0;
    tail = 0;
  } else {
    head = p->next;
    p->next->prev = 0;
  }
  delete p;
  size--;

  return val;
}
//Cambia el valor de un indice dado, se tiene una complejidad de n/2, ya que parte de la mita y toma en cuenta si el
//indice es mayor o menor a la mitda
bool DList::set(int index, std::string val) {
  int pos;
  DLink *p;

  if (index < 0 || index >= size) {
    throw IndexOutOfBounds();
  }

  p = head;
  pos = 0;
     if(index/2<size){
  while (pos != index) {
    p = p->next;
    pos++;
  }
    }
    else if(size<=index/2){
      p = tail;
      pos = size;
      while (pos != index) {
          p = p->next;
          pos--;
      }
    }
  p->data = val;
  return true;
}
//Elimina el valor de un indice dado, se tiene una complejidad de n/2, ya que parte de la mita y toma en cuenta si el
//indice es mayor o menor a la mitda
std::string DList::remove(int index) {
  int pos;
  std::string val;
  DLink*p;

  if (index < 0 || index >= size) {
    throw IndexOutOfBounds();
  }

  if (index == 0) {
    return removeFirst();
  }

  p = head;
  pos = 0;
    if(index/2<size){
        p = head;
        pos = 0;
        while (pos != index) {
        p = p->next;
        pos++;
        }
    }


    else if(size<=index/2){
        p = tail;
        pos = size;
        while (pos != index) {
            p = p->next;
            pos--;
        }
    }

  val = p->data;
  p->prev->next = p->next;
  if (p->next != 0) {
    p->next->prev = p->prev;
  }
  size--;
  delete p;
  return val;
}

//Las funciones a continuacion sirven para llamar a las funciones de los Dlink desde el main y poder usarlas
void DList::ordena(){
    head=head->mergeSort(head);
}
void DList::print(){
    head->print(head);
}
void DList::printMatriculas(){
    head->printMatriculas(head);
}
void DList::guardarMatriculas(std::string archivo){
    head->guardarMatriculas(head, archivo);
}
#endif /* DLIST_H_ */
