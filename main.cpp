#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include "sorts.h"

using namespace std;


template <class T>
string MostrarAlumnos(const vector<T> &v) {
	stringstream aux;
  int n;
  n=1;
	aux<< "\n///Los alumnos inscritos son:/// \n"<<n<<"."<< v[0];
	for (int i = 1; i < v.size(); i++) {
    n++;
		aux << "\n" <<n<<"."<<v[i];
	}
  aux<<"\n"; 
	return aux.str();
}
template <class T>
std::map<T,T> AsignarMatriculas(const vector<T> &v) {
  map<T,T> map2;
  std::string p;
  for (int i =0; i != v.size(); ++i){
    p="A";
    p.append(std::to_string(i));
    map2[p] = v[i];
  }
  return map2;
}

int main(int argc, char* argv[])
{
  int opc;
  string alumnos[] = {"Alejeandro","Mariana","Bruno","Luis","Christiana","Kevin","Jesus","Ricardo","Camila","Alain","Sofia","Ana","Oslvado","Diego","Sara","Alejandra","Karla","Enrique"};
  vector<string> alumnos1 (alumnos, alumnos+ sizeof(alumnos) / sizeof(string) );
  Sorts<string> sorts; 
  sorts.vectorASCII(alumnos1[0]);
  while(opc!=6){
    std::cout<<"\n_________Menú de alumnos_________";
    std::cout<<"\n1.Visualizar alumnos. \n2.Ordenar alumnos por orden alfabetico. \n3.Añadir alumno. \n4.Buscar alumno. \n5.Asignar matrículas.  \n6.Salir.";
    std::cout<<"\nElige una opción:";
    std::cin >> opc;
    if(opc==1){
      std::cout<<MostrarAlumnos(alumnos1);
    }
    else if(opc==2){
      sorts.ordenaMerge(alumnos1);
      std::cout<<"\nSe han ordenado los alumnos en orden alfabetico.\n";
    }
    else if(opc==3){
      std::string nuevo_alumno;
      std::cout<<"\nIngresa el nombre del nuevo alumno:\n";
      std::cin >> nuevo_alumno;
      alumnos1.push_back(nuevo_alumno);
      std::cout<<"\nSe ha agregado a:"<<nuevo_alumno<<" y se ha ordenado la lista.\n";
      sorts.ordenaMerge(alumnos1);
    }
    else if(opc==4){
      std::cout<<"\nOrdenando lista, para inciar busqueda...\n";
      alumnos1.push_back("_");
      int largo=alumnos1.size();
      std::string alumno_buscar;
      int lugar;
      sorts.ordenaMerge(alumnos1);
      std::cout<<"\nIngresa el nombre del alumno que deseas busca:\n";
      std::cin >> alumno_buscar;
      lugar=sorts.busqBinaria(alumnos1,alumno_buscar)+1;
      if (lugar==0){
        std::cout<<"\nEl alumno no se encuentra en la lista.\n";
         alumnos1.erase(alumnos1.begin()+largo); 
      }
      else{
        std::cout<<"\nEl alumno se encuentra en la posición: "<<lugar<<"\n";
         alumnos1.erase(alumnos1.begin()+largo); 
      }
    }
    else if(opc==5){
      map<string, string>  matriculas_nombres;
      matriculas_nombres=AsignarMatriculas(alumnos1);
      std::cout<<"\nLas matrículas han sido asginadas.\n";
      map <string, string>::iterator itr;
      for (itr = matriculas_nombres.begin(); itr != matriculas_nombres.end(); ++itr) {
      cout << itr->first << ": " << itr->second << endl;
   }
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