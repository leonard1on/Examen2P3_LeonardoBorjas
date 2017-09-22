#pragma once
#include "Quirk.h"
#include <string>
using namespace std;

class Transformation : public Quirk {
private:
  string forma;
  int cantImpactos;
  bool afecteOtros;

public:
  Transformation (string, int, bool, string);
  string getForma();
  virtual ~Transformation ();
};
