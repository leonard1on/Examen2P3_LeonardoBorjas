#pragma once
#include "Quirk.h"
#include <string>
using namespace std;

class Mutant : public Quirk {
private:
  string caracteristica;

public:
  Mutant (string, string);
  string getCaracteristica();
  virtual ~Mutant ();
};
