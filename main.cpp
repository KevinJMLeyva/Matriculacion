#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include "dlist.h"


using namespace std;


int main()
{
//Es importante cambiar las rutas de donde lee los datos.

  int opc,index1,ordenado;
  opc=0;
  ordenado=0;
  std::string alumnos_Texto,nombre_archivo,nombre_archivo_matriculas,nombre_archivo_matriculas_pred;

  string nombre;
  DList alumnos;  


  fstream newfile;
  nombre_archivo="Nombres.txt"; //Cambiar a la ruta donde se tienen los archivos
  nombre_archivo_matriculas_pred= "Nombres_matriculas.txt";//Cambiar a la ruta donde se tienen los archivos
  
   newfile.open(nombre_archivo,ios::in); //Lineas para abrir el arcivo y extraer información de el
if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp)){
          alumnos.addFirst(tp);
      }
      newfile.close();
   }

  while(opc!=8){ ///Menú de 8 opciones, bueno 7 si no contamos el salir
    std::cout<<"\n\n_________Men"<<char(163)<<" de alumnos_________";
    std::cout<<"\n1.Visualizar alumnos. \n2.Ordenar alumnos por orden alfabetico. \n3.A"<<char(164)<<"adir alumno. \n4.Buscar alumno. \n5.Asignar matr"<<char(161)<<"culas.\n6.Guardar cambios. \n7.Modificar alumno.  \n8.Salir.";
    std::cout<<"\nElige una opci"<<char(162)<<"n:";
    std::cin >> opc;
    if(opc==1){
      
      //Muestra la lista de alumnos, en el estado que se ecuentre
      if(ordenado==1){
        std::cout<<"\n La lista a continuación esta ordenada:";
      }
      else{
        std::cout<<"\n La lista no esta ordenada:";
      }
      std::cout<<"\n";
      std::cout<<"Lista de alumnos.\n";
      alumnos.print();
      std::cout<<"\n";

    }
    else if(opc==2){
      //Ordena la lita
      alumnos.ordena();
      std::cout<<"\nSe han ordenado los alumnos en orden alfabetico.\n";
      ordenado=1;
    }
    else if(opc==3){
      //Ingresar nuevo alumno, es más rápido si lo ingresamos en la primera posición, ya que no recorremos el arreglo
      std::string nuevo_alumno;
      std::cout<<"\nIngresa el nombre del nuevo alumno:";
      std::cin >> nuevo_alumno;
      alumnos.addFirst(nuevo_alumno);
      alumnos.ordena();
      std::cout<<"\nSe ha agregado a: "<<nuevo_alumno<<" y se ha ordenado la lista.\n";
      ordenado=1;
    }
    else if(opc==4){
      //Para buscar debemos ordenar la lista y depués usar métodos de la clase, ya que si no ordenamos nos dará resultados erroneos
      std::cout<<"\nOrdenando lista, para inciar busqueda...\n";
      alumnos.ordena();
      std::cout<<"\nIngresa n"<<char(163)<<"mero de lista del alumno:";
      std::cin >> index1;
      index1--;
      if(alumnos.length()>index1 and index1>0){
        std::cout<<"El alumno que se encuentra en ese n"<<char(163)<<"mero de la lista es:"<<alumnos.get(index1);
      }
      else{
        std::cout<<"Ingrese n"<<char(163)<<"mero de lista v"<<char(160)<<"lido";
      }
      ordenado=1;
    }
    else if(opc==5){
      //asginar las matrículas visualmente
      if(ordenado==0){ 
         std::cout<<"Para asginar las matr"<<char(161)<<"culas primero debes ordenar la lista de alumnos";
      }
      else{ 
      std::cout<<"\nAsignando matr"<<char(161)<<"culas...\n";
      std::cout<<"\n";
      std::cout<<"\n";
      alumnos.printMatriculas();
      std::cout << alumnos_Texto << endl;
      std::cout<<"\n";
      std::cout<<"\n";
      ordenado=1;
      }
    }
    else if(opc==6){
      //guardar las matrículas en un archivo de texto, se puede elegir la dirección del archivo de texto
      if(ordenado==0){ 
        std::cout<<"No hay cambios en las matr"<<char(161)<<"culas...\n";
        std::cout<<"\nElige una opci"<<char(162)<<"n:";
        std::cin >> opc;
      }
      else{ 
        std::string eleccion="0";
        std::cout<<"\n"<<char(168)<<"Deseas usar la dirrec"<<char(162)<<"n predeterminadad? (Y/N)";
        std::cin >> eleccion;
        if(eleccion=="Y"){
          alumnos.guardarMatriculas(nombre_archivo_matriculas_pred);
          std::cout<<"Archivo guarado.\n";
        }
        else if(eleccion=="N"){
          std::cout<<"\nIngresa la direcci"<<char(162)<<"n del archivo donde deseas guardar los cambios:";
          std::cin >> nombre_archivo_matriculas;
          if(nombre_archivo_matriculas==nombre_archivo){
              std::cout<<"Ingresa otra dirección.\n";
          }
          else{
            alumnos.guardarMatriculas(nombre_archivo_matriculas);
            std::cout<<"Archivo guarado.\n";
          }
        }
        else{
          std::cout<<"\nElgie una opci"<<char(162)<<"n v"<<char(160)<<"lida";
        }

      }
    }
    else if(opc==7){
     //modificar un alumno con su número de lista, comprobando que la lista este ordenada
      int alumno_modifico=-1;
      string alumno_nombre;
      if(ordenado==1){
      std::cout<<"\nIngrese el n"<<char(163)<<"mero de lista del alumno que desea modificar:";
      std::cin >> alumno_modifico;
      std::cout<<"Ingrese el nuevo nombre (completo) para efectuar el cambio:";
      std::cin.ignore(); // Eliminamos el salto de linea
      std::getline(std::cin, alumno_nombre);
      alumno_modifico--;
        if(alumnos.length()>alumno_modifico and alumno_modifico>-1){
            alumnos.set(alumno_modifico,alumno_nombre);
            std::cout<<"Cambio realizado.";
            ordenado=0; //Es importante marcar que la lsita se ha desoordenado, ya que algunas funciones pueden funcionar de mala manera
        }
        else{
          std::cout<<"Ingrese valores razonables.";
        }
      }
      else{
        std::cout<<"Primero, debe ordenar su lista de alumnos.";
      }
    }
    else if(opc==8){
      std::cout<<"Buen d"<<char(161)<<"a.";
    }
    else{
      std::cout<<"\nElgie una opci"<<char(162)<<"n v"<<char(160)<<"lida";
      std::cout<<"\nElige una opci"<<char(162)<<"n:";
      std::cin >> opc;

    }
    
  }
}
