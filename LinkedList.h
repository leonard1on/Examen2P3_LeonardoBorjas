#pragma once
#include <iostream>
#include "Ciudadano.h"
#include "Maestro.h"
#include "Estudiante.h"
#include "Quirk.h"
#include "Emmitter.h"
#include "Transformation.h"
#include "Mutant.h"

using namespace std;

struct Node {
  Ciudadano* ciudadano;
  Node* next;
};

class LinkedList{
  private:
    Node* head;
    Node* tail;
    int size;
  public:
    LinkedList();
    void addCiudadano(Ciudadano*);
    void display();
    void displayMaestros();
    void displayEstudiantes();
    void insert(int, Ciudadano*);
    void remove(int);
    int getSize();
    Ciudadano* get(int);
};
