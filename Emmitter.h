#pragma once
#include "Quirk.h"
#include <string>
using namespace std;

class Emmitter : public Quirk {
private:
  string efecto;
  int objetosAfectados;
  bool contacto;

public:
  Emmitter (string, int, bool, string);
  string getEfecto();
  virtual ~Emmitter ();
};
