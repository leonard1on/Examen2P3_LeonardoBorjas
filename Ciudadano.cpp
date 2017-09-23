#include "Ciudadano.h"
#include <string>
#include <vector>
#include "Quirk.h"
#include "Emmitter.h"
#include "Transformation.h"
#include "Mutant.h"
using namespace std;

Ciudadano::Ciudadano(string pNombre, int pEdad, string pNacimiento, float pAltura, string pPelo, string pOjo, string pSangre, Quirk* pQuirk){
  nombre=pNombre;
  edad=pEdad;
  nacimiento=pNacimiento;
  altura=pAltura;
  colorPelo=pPelo;
  colorOjos=pOjo;
  sangre=pSangre;
  quirk=pQuirk;
}

string Ciudadano::getNombre(){
  return nombre;
}

Quirk* Ciudadano::getQuirk(){
  return quirk;
}

vector<string> Ciudadano::getLikes(){
  return likes;
}

vector<string> Ciudadano::getDislikes(){
  return dislikes;
}

void Ciudadano::setLikes(vector<string> plikes){
  likes=plikes;
}

void Ciudadano::setDislikes(vector<string> pdislikes){
  dislikes=pdislikes;
}

string Ciudadano::toString(){

}

Ciudadano::~Ciudadano(){
  delete quirk;
}

Ciudadano::Ciudadano(){

}
