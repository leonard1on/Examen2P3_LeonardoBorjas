#include "Quirk.h"
#include "Emmitter.h"
#include <string>
using namespace std;

Emmitter::Emmitter(string pEfecto, int pObjetos, bool pContacto, string pDescripcion) : Quirk(pDescripcion){
  efecto=pEfecto;
  objetosAfectados=pObjetos;
}

string Emmitter::getEfecto(){
  return efecto;
}

Emmitter::~Emmitter(){

}
