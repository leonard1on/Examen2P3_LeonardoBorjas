#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

int menu();
Maestro* crearMaestro();
int main(int argc, char const *argv[]) {
  int resp;
  LinkedList ciudadanos;

  do {
    resp=menu();
    if (resp==1) {

    }
  } while(resp!=11);
  return 0;
}

int menu(){
  int resp;
  cout<<"- Menu -" <<endl
    <<"1.  Contratar Maestro"<<endl
    <<"2.  Despedir Maestro" <<endl
    <<"3.  Matricula Alumno" <<endl
    <<"4.  Expulsar Alumno" <<endl
    <<"5.  Listar maestros en U.A" <<endl
    <<"6.  Listar estudiantes en U.A" <<endl
    <<"7.  Sacar el sueldo promedio de los maestros de U.A" <<endl
    <<"8.  Sacar el promedio general de todos los alumnos de U.A" <<endl
    <<"9.  Listar alumnos por departamento" <<endl
    <<"10. Guardar registros"<<endl
    <<"11. Salir" <<endl
    <<"Escriba su eleccion: ";
  cin>>resp;
  return resp;
}

Maestro* crearMaestro(){

}
