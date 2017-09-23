#pragma once

#include "Estudiante.h"
#include "LinkedList.h"
#include <string>
using namespace std;
class Estudiante;
class LinkedList;
class Maestro : public Ciudadano{
private:
  LinkedList* estudiantes;
  string homeroom;
  string departamento;
  string alias;
  float sueldo;

public:
  Maestro();
  Maestro (string, string, string, float, string, int, string, float, string, string, string, Quirk*  );
  float getSueldo();
  LinkedList* getEstudiantes();
  string getDepartamento();
  virtual ~Maestro ();
};
