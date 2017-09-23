#include "LinkedList.h"
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

int menu();
Ciudadano* crearMaestro();
void crearEstudiante(LinkedList*);
int main(int argc, char const *argv[]) {
  int resp;
  int seleccion;
  LinkedList* ciudadanos = new LinkedList();

  do {
    int cont=0;
    resp=menu();
    if (resp==1) {
      ciudadanos->addCiudadano(crearMaestro());
    }

    if (resp==2) {
      cont=0;
      for (size_t i = 0; i < ciudadanos->getSize(); i++) {
        if (typeid(*ciudadanos->get(i))==typeid(Maestro)) {
          cont++;
        }
      }
      if (cont>0) {
        do{
          ciudadanos->displayMaestros();
          cout<<"Elija uno!";
          cin>>seleccion;
        }while(typeid(*ciudadanos->get(seleccion))!=typeid(Maestro));
        ciudadanos->remove(seleccion);
      }else{
        cout<<"No hay maestros" <<endl;
      }
    }

    if (resp==3) {
      cont=0;
      for (size_t i = 0; i < ciudadanos->getSize(); i++) {
        if (typeid(*ciudadanos->get(i))==typeid(Maestro)) {
          cont++;
        }
      }
      if (cont>0) {
        crearEstudiante(ciudadanos);
      }else{
        cout<<"No hay maestros" <<endl;
      }
    }

    if (resp==4) {
      int seleccion2;
      for (size_t i = 0; i < ciudadanos->getSize(); i++) {
        if (typeid(*ciudadanos->get(i))==typeid(Maestro)) {
          cont++;
        }
      }
      if (cont>0) {
        ciudadanos->displayMaestros();
        cout<<"Elija un maestro de quien expulsar uno de sus estudiantes!";
        cin>>seleccion;
        if (dynamic_cast<Maestro*>(ciudadanos->get(seleccion))->getEstudiantes()->getSize() != 0) {
          for (size_t j = 1; j <= dynamic_cast<Maestro*>(ciudadanos->get(seleccion))->getEstudiantes()->getSize(); j++) {
            cout<<j <<". " <<dynamic_cast<Maestro*>(ciudadanos->get(seleccion))->getEstudiantes()->get(j)->getNombre() <<endl;
          }
          cout<<"Cual quiere expulsar";
          cin>>seleccion2;
          dynamic_cast<Maestro*>(ciudadanos->get(seleccion))->getEstudiantes()->remove(seleccion2);

        }else{
          cout<<"Ese maestro no tiene estudiantes"<<endl;
        }
      }else{
        cout<<"No hay Estudiantes"<<endl;
      }
    }

    if (resp==5) {
      ciudadanos->displayMaestros();
    }

    if (resp==6) {
      for (size_t i = 1; i <= ciudadanos->getSize(); i++) {

        if (dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->getSize() != 0 ) {
          for (size_t j = 1; j <= dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->getSize(); j++) {
            cout<<dynamic_cast<Estudiante*>(dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->get(j))->getNombre()<<endl;
          }
        }

      }
    }

    if (resp==7) {
      float sueldo=0;
      int maestrosnum=0;
      for (size_t i = 1; i <= ciudadanos->getSize(); i++) {
        if (typeid(*ciudadanos->get(i)) == typeid(Maestro)) {
          sueldo+= (dynamic_cast<Maestro*>(ciudadanos->get(i)))->getSueldo();
          maestrosnum++;
        }
      }
      cout<<"Promedio de sueldos: "<<sueldo/maestrosnum <<endl;
    }

    if (resp==8) {
      float promedio=0;
      int numero=0;
      for (size_t i = 1; i <= ciudadanos->getSize(); i++) {

        if (dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->getSize() != 0 ) {
          for (size_t j = 1; j <= dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->getSize(); j++) {
            promedio+= dynamic_cast<Estudiante*>(dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->get(j))->getPromedio();
            numero++;
          }
        }

      }
      cout<<"Promedio de sueldos: "<<promedio/numero <<endl;
    }

    if (resp==9) {
      for (size_t i = 1; i <= ciudadanos->getSize(); i++) {

        if (typeid(*ciudadanos->get(i)) == typeid(Maestro)) {
          if(dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->getSize() != 0){

            for (size_t j = 1; j <= dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->getSize() ; j++) {
              cout<<"Departamento: "<<dynamic_cast<Maestro*>(ciudadanos->get(i))->getDepartamento() <<" Alumno: " <<dynamic_cast<Maestro*>(ciudadanos->get(i))->getEstudiantes()->get(j)->getNombre() <<endl;
            }

          }
        }
        cout<<endl;
      }
    }
  } while(resp!=11);
  return 0;
}

int menu(){
  int resp;
  cout<<endl <<"- Menu -" <<endl
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

Ciudadano* crearMaestro(){
  string nombre;
  int edad;
  string nacimiento;
  float altura;
  string colorPelo;
  string colorOjos;
  vector<string> likes;
  vector<string> dislikes;
  string sangre;
  Quirk* quirk;
  int resp1;
  Ciudadano* ciudadano;

  cout<<"Nombre?: ";
  cin>>nombre;
  cout<<"Edad?: ";
  cin>>edad;
  cout<<"Cuando nacio?: ";
  cin>>nacimiento;
  cout<<"Altura?: ";
  cin>>altura;
  cout<<"Color del pelo?: ";
  cin>>colorPelo;
  cout<<"Color de Ojos?: ";
  cin>>colorOjos;
  do {
    string like;
    cout<<"Que like tiene?: ";
    cin>>like;
    likes.push_back(like);
    cout<<"Tiene otro? 0=Si 1=No: ";
    cin>>resp1;
  } while(resp1!=1);

  do {
    string dislike;
    cout<<"Que dislike tiene?: ";
    cin>>dislike;
    dislikes.push_back(dislike);
    cout<<"Tiene otro? 0=Si 1=No: ";
    cin>>resp1;
  } while(resp1!=1);

  cout<<"Sangre?: ";
  cin>>sangre;
  do {
    cout<<"Que Quirk quiere crear" <<endl
      <<"1. Emmitter" <<endl
      <<"2. Transformation" <<endl
      <<"3. Mutant" <<endl
      <<"//:";
    cin>>resp1;
    string descripcion;
    if (resp1==1) {
      string efecto;
      int objetosAfectados;
      bool contacto=true;
      string fisico;
      cout<<"Descripcion: ";
      cin>>descripcion;
      cout<<"Cual es el efecto?: ";
      cin>>efecto;
      cout<<"Cuantos Objetos Afecta por emision?: ";
      cin>>objetosAfectados;
      cout<<"Necesita contacto fisico? si o no: ";
      cin>>fisico;
      if (fisico=="no") {
        contacto=false;
      }
      quirk=new Emmitter(efecto, objetosAfectados, contacto, descripcion);
    }

    if (resp1==2 ) {
      string forma;
      int cantImpactos;
      bool afecteOtros=true;
      string fisico;
      cout<<"Descripcion: ";
      cin>>descripcion;
      cout<<"Cual es la forma?: ";
      cin>>forma;
      cout<<"Cantidad de Impactos?: ";
      cin>>afecteOtros;
      cout<<"Afecta otros? si o no: ";
      cin>>fisico;
      if (fisico=="no") {
        afecteOtros=false;
      }
      quirk=new Transformation(forma, afecteOtros, afecteOtros, descripcion);
    }

    if (resp1==3 ) {
      string caracteristica;

      string fisico;
      cout<<"Descripcion: ";
      cin>>descripcion;
      cout<<"Cual es su caracteristica?: ";
      cin>>caracteristica;
      quirk=new Mutant(caracteristica, descripcion);
    }
  } while(resp1>3);
  string homeroom;
  string departamento;
  string alias;
  float sueldo;

  cout<<"homeroom?: ";
  cin>>homeroom;
  cout<<"departamento?: ";
  cin>>departamento;
  cout<<"Alias?: ";
  cin>>alias;
  cout<<"Sueldo?: ";
  cin>>sueldo;

  ciudadano=new Maestro(homeroom, departamento, alias, sueldo, nombre, edad, nacimiento, altura, colorPelo, colorOjos, sangre, quirk);
  ciudadano->setLikes(likes);
  ciudadano->setDislikes(dislikes);
  return ciudadano;
}

void crearEstudiante(LinkedList* ciudadanos){
  string nombre;
  int edad;
  string nacimiento;
  float altura;
  string colorPelo;
  string colorOjos;
  vector<string> likes;
  vector<string> dislikes;
  string sangre;
  Quirk* quirk;
  int resp1;
  Ciudadano* ciudadano;

  cout<<"Nombre?: ";
  cin>>nombre;
  cout<<"Edad?: ";
  cin>>edad;
  cout<<"Cuando nacio?: ";
  cin>>nacimiento;
  cout<<"Altura?: ";
  cin>>altura;
  cout<<"Color del pelo?: ";
  cin>>colorPelo;
  cout<<"Color de Ojos?: ";
  cin>>colorOjos;
  do {
    string like;
    cout<<"Que like tiene?: ";
    cin>>like;
    likes.push_back(like);
    cout<<"Tiene otro? 0=Si 1=No: ";
    cin>>resp1;
  } while(resp1!=1);

  do {
    string dislike;
    cout<<"Que dislike tiene?: ";
    cin>>dislike;
    dislikes.push_back(dislike);
    cout<<"Tiene otro? 0=Si 1=No: ";
    cin>>resp1;
  } while(resp1!=1);

  cout<<"Sangre?: ";
  cin>>sangre;
  do {
    cout<<"Que Quirk quiere crear" <<endl
      <<"1. Emmitter" <<endl
      <<"2. Transformation" <<endl
      <<"3. Mutant" <<endl
      <<"//:";
    cin>>resp1;
    string descripcion;
    if (resp1==1) {
      string efecto;
      int objetosAfectados;
      bool contacto=true;
      string fisico;
      cout<<"Descripcion: ";
      cin>>descripcion;
      cout<<"Cual es el efecto?: ";
      cin>>efecto;
      cout<<"Cuantos Objetos Afecta por emision?: ";
      cin>>objetosAfectados;
      cout<<"Necesita contacto fisico? si o no: ";
      cin>>fisico;
      if (fisico=="no") {
        contacto=false;
      }
      quirk=new Emmitter(efecto, objetosAfectados, contacto, descripcion);
    }

    if (resp1==2 ) {
      string forma;
      int cantImpactos;
      bool afecteOtros=true;
      string fisico;
      cout<<"Descripcion: ";
      cin>>descripcion;
      cout<<"Cual es la forma?: ";
      cin>>forma;
      cout<<"Cantidad de Impactos?: ";
      cin>>afecteOtros;
      cout<<"Afecta otros? si o no: ";
      cin>>fisico;
      if (fisico=="no") {
        afecteOtros=false;
      }
      quirk=new Transformation(forma, afecteOtros, afecteOtros, descripcion);
    }

    if (resp1==3 ) {
      string caracteristica;

      string fisico;
      cout<<"Descripcion: ";
      cin>>descripcion;
      cout<<"Cual es su caracteristica?: ";
      cin>>caracteristica;
      quirk=new Mutant(caracteristica, descripcion);
    }
  } while(resp1>3);
  float promedio;
  string homeroom;
  Ciudadano* maestro;
  int seleccion;
  do{
    ciudadanos->displayMaestros();
    cout<<"Elija uno!: ";
    cin>>seleccion;
    maestro=ciudadanos->get(seleccion);
  }while(typeid(*ciudadanos->get(seleccion)) != typeid(Maestro));
  cout<<"Promedio?: ";
  cin>>promedio;
  cout<<"homeroom?: ";
  cin>>homeroom;


  ciudadano=new Estudiante(promedio, homeroom, dynamic_cast<Maestro*>(maestro), nombre, edad, nacimiento, altura, colorPelo, colorOjos, sangre, quirk);
  ciudadano->setLikes(likes);
  ciudadano->setDislikes(dislikes);
  dynamic_cast<Maestro*>(ciudadanos->get(seleccion))->getEstudiantes()->addCiudadano(ciudadano);
}
