#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include "dlist.h"


using namespace std;


int main(int argc, char* argv[])
{
  int opc,index1;
  opc=0;
  std::string alumnos_Texto;
  string nombre;
  DList<string> alumnos;  
  string nombreArchivo = "Nombres.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  while (getline(archivo, linea)) {
    alumnos.add(linea);
  }
  
  while(opc!=6){
    std::cout<<"\n\n_________Menú de alumnos_________";
    std::cout<<"\n1.Visualizar alumnos. \n2.Ordenar alumnos por orden alfabetico. \n3.Añadir alumno. \n4.Buscar alumno. \n5.Asignar matrículas.  \n6.Salir.";
    std::cout<<"\nElige una opción:";
    std::cin >> opc;
    if(opc==1){
      std::cout<<"\n";
      std::cout<<"\n";
      std::cout<<alumnos.toString().c_str();
      std::cout<<"\n";
      std::cout<<"\n";
    }
    else if(opc==2){
      alumnos.mergeSortDlistMascara();
      std::cout<<"\nSe han ordenado los alumnos en orden alfabetico.\n";
    }
    else if(opc==3){
      std::string nuevo_alumno;
      std::cout<<"\nIngresa el nombre del nuevo alumno:\n";
      std::cin >> nuevo_alumno;
      alumnos.addFirst(nuevo_alumno);
      alumnos.mergeSortDlistMascara();
      std::cout<<"\nSe ha agregado a: "<<nuevo_alumno<<" y se ha ordenado la lista.\n";
    }
    else if(opc==4){
      std::cout<<"\nOrdenando lista, para inciar busqueda...\n";
      alumnos.mergeSortDlistMascara();
      std::cout<<"\nIngresa búmero de lista del alumno:\n";
      std::cin >> index1;
      std::cout<<alumnos.get(index1);
    }
    else if(opc==5){
      std::cout<<"\nAsignando matrículas...\n";
      std::cout<<"\n";
      std::cout<<"\n";
      alumnos_Texto=alumnos.toStringMatriculas().c_str();
      std::cout << alumnos_Texto << endl;
      std::cout<<"\n";
      std::cout<<"\n";
    }
    else if(opc==6){
      std::cout<<"Buen día.";
    }
    else{
      std::cout<<"\nElgie una opción válida";
      std::cout<<"\nElige una opción:";
      std::cin >> opc;

    }
  }
}
