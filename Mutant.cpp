#include "Quirk.h"
#include "Mutant.h"
#include <string>
using namespace std;

Mutant::Mutant(string pCaracteristica, string pDescripcion) : Quirk(pDescripcion){
  caracteristica=pCaracteristica;
}

string Mutant::getCaracteristica(){
  return caracteristica;
}

Mutant::~Mutant(){

}
