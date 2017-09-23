#include "Maestro.h"
#include <typeinfo>
Maestro::Maestro() {}

Maestro::Maestro(string pHomeroom, string pDepartamento, string pAlias, float pSueldo, string pNombre, int pEdad, string pNacimiento, float pAltura, string pPelo, string pOjo, string pSangre, Quirk* pQuirk) : Ciudadano(pNombre, pEdad, pNacimiento, pAltura, pPelo, pOjo, pSangre, pQuirk){
  homeroom=pHomeroom;
  departamento=pDepartamento;
  alias=pAlias;
  sueldo=pSueldo;
  estudiantes = new LinkedList();
}

float Maestro::getSueldo(){
  return sueldo;
}

LinkedList* Maestro::getEstudiantes(){
  return estudiantes;
}

string Maestro::getDepartamento(){
  return departamento;
}

string Maestro::toString(){
  string likess="";
  string dislikess="";
  string estudiantess="";
  for (size_t i = 0; i < likes.size(); i++) {
    likess=likess+likes.at(i)+", ";
  }
  for (size_t i = 0; i < dislikes.size(); i++) {
    dislikess=dislikess+likes.at(i)+", ";
  }

  for (size_t i = 1; i <= estudiantes->getSize(); i++) {
    estudiantess+=dynamic_cast<Estudiante*>(estudiantes->get(i))->toString()+"\n";
  }
  string regreso="Maestro:\nNombre: "+nombre+" Edad: "+to_string(edad)+" Fecha de Nacimiento: "+nacimiento+" Altura: "+to_string(altura)+"\nColor de Pelo: "+colorPelo+" Color de Ojos: "+colorOjos+"Likes: "+likess+"\nDislikes: "+dislikess+" Quirk: "+typeid(*quirk).name()+"\n"+"homeroom: "+homeroom+" Departamento: "+departamento+" Alias: "+alias+" Sueldo: "+to_string(sueldo);
  regreso+="\nEstudiantes: \n"+estudiantess+"\n";
  return regreso;
}
Maestro::~Maestro(){
  delete quirk;
}
