#pragma once
#include <string>
#include <vector>
#include "Quirk.h"
#include "Emmitter.h"
#include "Transformation.h"
#include "Mutant.h"
using namespace std;

class Ciudadano {
protected:
  string nombre;
  int edad;
  string nacimiento;
  float altura;
  string colorPelo;
  string colorOjos;
  vector<string> likes;
  vector<string> dislikes;
  string sangre;
  Quirk* quirk;

public:
  Ciudadano();
  Ciudadano (string, int, string, float, string, string, string, Quirk*);
  string getNombre();
  Quirk* getQuirk();
  vector<string> getLikes();
  vector<string> getDislikes();
  void setLikes(vector<string>);
  void setDislikes(vector<string>);
  virtual string toString();
  virtual ~Ciudadano ();
};
