#include "Estudiante.h"

Estudiante::Estudiante() {}

Estudiante::Estudiante(float pPromedio, string pHomeroom, Maestro* pMaestro, string pNombre, int pEdad, string pNacimiento, float pAltura, string pPelo, string pOjo, string pSangre, Quirk* pQuirk) : Ciudadano(pNombre, pEdad, pNacimiento, pAltura, pPelo, pOjo, pSangre, pQuirk){
  promedio=pPromedio;
  homeroom=pHomeroom;
  maestro=pMaestro;
}

float Estudiante::getPromedio(){
  return promedio;
}

Estudiante::~Estudiante(){
  delete maestro;
  delete quirk;
}
