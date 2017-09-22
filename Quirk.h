#pragma once
#include <string>
using namespace std;

class Quirk {
private:
  string descripcion;
public:
  Quirk (string);
  string getDescripcion();
  virtual ~Quirk ();
};
