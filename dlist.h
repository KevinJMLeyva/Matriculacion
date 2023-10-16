
#ifndef DLIST_H_
#define DLIST_H_
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include "exception.h"

template <class T> class DList;
template <class T> class DListIterator;
template <class T> class DListSorts;


template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
	friend class DListIterator<T>;
  friend class DListSorts<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
public:
	DList();
	DList(const DList<T>&);
	~DList();

	void addFirst(T);
	void add(T);
	T    getFirst() const ;
	T    removeFirst() ;
	T	 getLast() const ;
	T    removeLast() const;
	int  length() const;
	T    get(int) const;
	bool contains(T) const;
	bool empty() const;
	void clear();
	std::string toString() const;
  std::string toStringMatriculas() const;
	void operator= (const DList&);

	void addBefore(DListIterator<T>&, T);
	void addAfter(DListIterator<T>&, T);
	T    removeCurrent(DListIterator<T>&);

	bool set(int, T);
	int  indexOf(T) const;
	int  lastIndexOf(T) const;
	T    remove(int);
	bool removeFirstOcurrence(T);
	bool removeLastOcurrence(T);
  void mergeSortDlistMascara();

  int search(T) const;
  int busqBinaria (std::string);
  int busqBinaria_aux (int, int, std::string);

private:
  DLink<T>* splitDlist(DLink<T>*);
  DLink<T>* mergeDlist(DLink<T>*,DLink<T>*);
  DLink<T>* mergeSortDlist(DLink<T>*);
  DLink<T> *head;
  int convert(std::string,int);
	DLink<T> *tail;
	int 	 size;
  std::vector<int> vectorASCII(std::string);

	friend class DListIterator<T>;
  friend class DListSorts<T>;
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}


// NO
template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

// NO
template <class T>
int DList<T>::length() const {
	return size;
}

// NO
template <class T>
bool DList<T>::contains(T val) const {
	DLink<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

// NO
template <class T>
T DList<T>::getFirst() const{
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}

template <class T>
void DList<T>::addFirst(T val){
	DLink<T> *newLink;

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		newLink->next = head;
		head->previous = newLink;
		head = newLink;
	}
	size++;
}

template <class T>
void DList<T>::add(T val){
	DLink<T> *newLink;

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
T DList<T>::removeFirst(){
	T val;
	DLink<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	val = p->value;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;

	return val;
}

// NO
template <class T>
T DList<T>::get(int index) const {
	int pos;
	DLink<T> *p;

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

    return p->value;
  }
  else if(size<=index/2){
      p = tail;
      pos = size;
      while (pos != index) {
          p = p->next;
          pos--;
      }
      return p->value;
  }
	
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

// NO
template <class T>
std::string DList<T>::toString() const {
	std::stringstream aux;
	DLink<T> *p;
  int i;
  i=1;
	p = head;
	while (p != 0) {
		aux <<i<<"." <<p->value;
    i++;
		if (p->next != 0) {
			aux << "\n";
		}
		p = p->next;
	}
	return aux.str();
}
template <class T>
std::string DList<T>::toStringMatriculas() const {
    std::stringstream aux;
    DLink<T> *p;
    int i,o;
    i=1;
    o=0;
    aux << "\n";
    aux << "\n";
    p = head;
    while (p != 0) {
      aux <<i<<"." <<p->value<<"  A0"<<o;
      i++;
      o++;
      if (p->next != 0) {
        aux << "\n";
      }
      p = p->next;
    }
    aux << "\n";
    aux << "\n";
    return aux.str();
  }

// NO
template <class T>
DList<T>::DList(const DList<T> &source){
	DLink<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new DLink<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new DLink<T>(p->value, q, 0);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

// NO
template <class T>
void DList<T>::operator=(const DList<T> &source){
	DLink<T> *p, *q;

	clear();
	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new DLink<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new DLink<T>(p->value, q, 0);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

// NO
template <class T>
void DList<T>::addBefore(DListIterator<T> &itr, T val) {
	DLink<T> *newLink;

	if (this != itr.theList) {
		throw IllegalAction();
	}

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	// between
	if (itr.previous != 0) {
		newLink->next = itr.current;
		itr.current->previous = newLink;

		itr.previous->next = newLink;
		newLink->previous = itr.previous;

		itr.previous = itr.previous->next;
		size++;
	// start
	} else {
		addFirst(val);
		itr.previous = head;
		itr.current = itr.previous->next;
	}
}

template <class T>
void DList<T>::addAfter(DListIterator<T> &itr, T val) {
	DLink<T> *newLink;

	if (this != itr.theList) {
		throw IllegalAction();
	}

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}


	// between
	if (itr.current != 0) {
		newLink->next = itr.current->next;
		itr.current->next->previous = newLink;

		itr.current->next = newLink;
		newLink->previous = itr.current;
		size++;
	// end
	} else if (itr.previous != 0) {
		itr.previous->next = newLink;
		newLink->previous = itr.previous;

		itr.current = newLink;
		size++;
	// start
	} else {
		addFirst(val);
		itr.current = head;
		itr.previous = 0;
	}
}

template <class T>
T DList<T>::removeCurrent(DListIterator<T> &itr) {
	T val;

	if (this != itr.theList) {
		throw IllegalAction();
	}

	if (itr.current == 0) {
		throw NoSuchElement();
	}

	if (itr.previous == 0) {
		head = itr.current->next;
		itr.current->next->previous = 0;
	} else {
		itr.previous->next = itr.current->next;
		itr.current->next->previous = itr.previous;
	}

	val = itr.current->value;
	delete itr.current;
	itr.current = 0;

	return val;
}

// NO
template <class T>
bool DList<T>::set(int index, T val) {
	int pos;
	DLink<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	p->value = val;
	return true;
}

// NO
template <class T>
int DList<T>::indexOf(T val) const {
	int index;
	DLink<T> *p;

	index = 0;
	p = head;
	while (p != 0) {
		if (p->value == val) {
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

template <class T>
int DList<T>::lastIndexOf(T val) const {
	int index;
	DLink<T> *p;

	index = size - 1;
	p = tail;
	while (p != 0) {
		if (p->value == val) {
			return index;
		}
		index--;
		p = p->previous;
	}
	return -1;
}

// NO
template <class T>
T DList<T>::remove(int index) {
	int pos;
	T val;
	DLink<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return removeFirst();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	val = p->value;
	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	}
	size--;

	delete p;

	return val;
}

template <class T>
bool DList<T>::removeFirstOcurrence(T val) {
	DLink<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			break;
		}
		p = p->next;
	}

	if (p != 0) {
		if (p->previous == 0) {
			head = p->next;
			p->next->previous = 0;
		} else {
			p->previous->next = p->next;
			if (p->next != 0) {
				p->next->previous = p->previous;
			}
		}
		size--;
		return true;
	}

	return false;
}

template <class T>
bool DList<T>::removeLastOcurrence(T val) {
	DLink<T> *p;

	p = tail;
	while (p != 0) {
		if (p->value == val) {
			break;
		}
		p = p->previous;
	}

	if (p != 0) {
		if (p->previous == 0) {
			head = p->next;
			p->next->previous = 0;
		} else {
			p->previous->next = p->next;
			if (p->next != 0) {
				p->next->previous = p->previous;
			}
		}
		size--;
		return true;
	}

	return false;
}

template <class T>
class DListIterator {
public:
	DListIterator(DList<T>*);
	DListIterator(const DListIterator<T>&);

	bool begin();
	bool end();
	T&   operator() ();
	bool operator++ ();
	void operator= (T);

private:
	DLink<T> *current;
	DLink<T> *previous;
	DList<T> *theList;

	friend class DList<T>;
};

template <class T>
int DList<T>::convert(std::string s,int p) { //Convertidor de cáracteres en valores de ASCII
  std::string palabra;
  int b;
  palabra=s;
  b=(int)palabra[p];
  return b;
}
template <class T>
void DList<T>::mergeSortDlistMascara() //Funcion para llamrlos desde el main
{ 
  head = mergeSortDlist(head);
 } 
template <class T>
DLink<T>* DList<T>::mergeSortDlist(DLink<T> *head) //Algortimo de ordenamiento que divide el Dbl en segmentos y posteriomente los ordena para volverlos a juntar, ordenar por pedazos es más rápido y eficiente
{ 
  DLink<T> *second;
  if (!head || !head->next){
    return head;
    }
  second = splitDlist(head); 
  head = mergeSortDlist(head); 
  second = mergeSortDlist(second); 
  return mergeDlist(head,second); 
} 
template <class T>
DLink<T>* DList<T>::mergeDlist(DLink<T> *first,DLink<T> *second) //Junta los nódos que previamente separamos
{ 
  int i;
  i=0;
  if (first==0) 
      return second; 
  if (second==0) 
      return first; 
  while(convert(first->value,i)==convert(second->value,i) and (i<=first->value.size()) and (i<=second->value.size())){//Revisa el ASCII para determinar cuando dejan de ser iguales
    i++;
  }
  if (convert(first->value,i) < convert(second->value,i)) //El convert usa el ASCII para evaluar los valores númericos
  { 
      first->next = mergeDlist(first->next,second); 
      first->next->previous = first; 
      first->previous = 0; 
      return first; 
  } 
  else
  { 
      second->next = mergeDlist(first,second->next); 
      second->next->previous = second; 
      second->previous = 0; 
      return second; 
  } 

} 
template <class T>
DLink<T>* DList<T>::splitDlist(DLink<T> *head) //Separa la lista a la mitad
{ 
    DLink<T> *fast,*slow,*temp;
    fast = head;
    slow = head;  
    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    temp = slow->next; 
    slow->next = 0;  
    return temp;
  
} 
template <class T>
int DList<T>::search(T val) const {
    DLink<T> *p;
    int pos;
    pos=0;
    p = head;
    while (p != 0) {
        if (p->value == val) {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

template <class T>
std::vector<int> DList<T>::vectorASCII(std::string s)  
{
    std::vector <int> nuevo_vector; 
    int valorAscii;
    for (int i = 0; i < s.length(); i++) 
    {
      valorAscii = (int)s[i];
      nuevo_vector.push_back(valorAscii);
    }
    return nuevo_vector;
}

template <class T>
int DList<T>::busqBinaria_aux (int low, int high, std::string valor){
    int mid;
    if(low <= high) {
        mid=(low+high)/2;
      if(vectorASCII(valor)==vectorASCII(get(mid))){
            return mid;
        }
        else if(convert(valor,0)<convert(get(mid),0)){
            return busqBinaria_aux(low,mid-1,valor);
        }
        else{
            return busqBinaria_aux(mid+1,high,valor);
        }
    }
    return -1;
}
template <class T>
int DList<T>::busqBinaria(std::string valor){
    int low=0;
    int longitud=size;
    int high=longitud-1;
    int mid;
    mid=(low+high)/2;
    if(vectorASCII(valor)==vectorASCII(get(mid))){
        return mid;
    }
    else {
        mid = (low+high) / 2;
        if(convert(valor,0)<convert(get(mid),0)){
            return busqBinaria_aux(low,mid-1,valor);
        }
        else{
            return busqBinaria_aux(mid+1,high,valor);
        }
    }
    return busqBinaria_aux(0, longitud - 1, valor);
}

// NO
template <class T>
DListIterator<T>::DListIterator(DList<T> *aList) : theList(aList) {
	begin();
}

// NO
template <class T>
DListIterator<T>::DListIterator(const DListIterator<T> &source) : theList(source.theList) {
	begin();
}

// NO
template <class T>
bool DListIterator<T>::begin() {
	previous = 0;
	current = theList->head;
	return (current != 0);
}

// NO
template <class T>
T& DListIterator<T>::operator() () {
	if (current == 0) {
		throw NoSuchElement();
	}
	return current->value;
}

// NO
template <class T>
bool DListIterator<T>::end() {
	if (current == 0) {
		if (previous != 0) {
			current = previous->next;
		}
	}
	return (current == 0);
}

// NO
template <class T>
bool DListIterator<T>::operator++ () {
	if (current == 0) {
		if (previous == 0) {
			current = theList->head;
		} else {
			current = previous->next;
		}
	} else {
		previous = current;
		current = current->next;
	}
	return (current != 0);
}

// NO
template <class T>
void DListIterator<T>::operator= (T val) {
	if (current == 0) {
		throw NoSuchElement();
	}
	current->value = val;
}

#endif /* DLIST_H_ */
