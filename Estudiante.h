#pragma once
#include "Ciudadano.h"
#include "Quirk.h"
#include "Emmitter.h"
#include "Transformation.h"
#include "Mutant.h"
#include "Maestro.h"
#include <string>
using namespace std;
class Maestro;

class Estudiante : public Ciudadano{
private:
  float promedio;
  string homeroom;
  Maestro* maestro;

public:
  Estudiante();
  Estudiante (float, string, Maestro*, string, int, string, float, string, string, string, Quirk*);
  float getPromedio();
  string toString();
  virtual ~Estudiante ();
};
