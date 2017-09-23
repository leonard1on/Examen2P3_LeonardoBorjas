#include "Estudiante.h"
#include <typeinfo>
Estudiante::Estudiante() {}

Estudiante::Estudiante(float pPromedio, string pHomeroom, Maestro* pMaestro, string pNombre, int pEdad, string pNacimiento, float pAltura, string pPelo, string pOjo, string pSangre, Quirk* pQuirk) : Ciudadano(pNombre, pEdad, pNacimiento, pAltura, pPelo, pOjo, pSangre, pQuirk){
  promedio=pPromedio;
  homeroom=pHomeroom;
  maestro=pMaestro;
}

float Estudiante::getPromedio(){
  return promedio;
}

string Estudiante::toString(){
  string likess="";
  string dislikess="";
  for (size_t i = 0; i < likes.size(); i++) {
    likess=likess+likes.at(i)+", ";
  }
  for (size_t i = 0; i < dislikes.size(); i++) {
    dislikess=dislikess+likes.at(i)+", ";
  }
  string regreso="Nombre: "+nombre+" Edad: "+to_string(edad)+" Fecha de Nacimiento: "+nacimiento+" Altura: "+to_string(altura)+"\nColor de Pelo: "+colorPelo+" Color de Ojos: "+colorOjos+"Likes: "+likess+"\nDislikes: "+dislikess+" Quirk: "+typeid(*quirk).name()+"\n"+"Promedio: "+to_string(promedio)+" Homeroom: "+homeroom+" Maestro: "+maestro->getNombre();
  return regreso;
}

Estudiante::~Estudiante(){
  delete maestro;
  delete quirk;
}
