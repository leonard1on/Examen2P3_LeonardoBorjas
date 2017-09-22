#include "Quirk.h"
#include <string>
using namespace std;

Quirk::Quirk(string pDescripcion){
  descripcion=pDescripcion;
}

string Quirk::getDescripcion(){
  return descripcion;
}

Quirk::~Quirk(){
}
