#include "Quirk.h"
#include "Transformation.h"
#include <string>
using namespace std;

Transformation::Transformation(string pForma, int pImpactos, bool pAfectar, string pDescripcion) : Quirk(pDescripcion){
  forma=pForma;
  cantImpactos=pImpactos;
  afecteOtros=pAfectar;
}

string Transformation::getForma(){
  return forma;
}

Transformation::~Transformation(){

}
