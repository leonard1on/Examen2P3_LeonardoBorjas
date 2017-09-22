#include "Maestro.h"

Maestro::Maestro() {}

Maestro::Maestro(string pHomeroom, string pDepartamento, string pAlias, float pSueldo, string pNombre, int pEdad, string pNacimiento, float pAltura, string pPelo, string pOjo, string pSangre, Quirk* pQuirk) : Ciudadano(pNombre, pEdad, pNacimiento, pAltura, pPelo, pOjo, pSangre, pQuirk){
  homeroom=pHomeroom;
  departamento=pDepartamento;
  alias=pAlias;
  sueldo=pSueldo;
  estudiantes = new LinkedList();
}

Maestro::~Maestro(){
  delete quirk;
}
