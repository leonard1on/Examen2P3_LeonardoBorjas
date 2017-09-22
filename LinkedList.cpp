#include "LinkedList.h"
#include <iostream>
#include "Ciudadano.h"
#include "Quirk.h"
#include "Emmitter.h"
#include "Transformation.h"
#include "Mutant.h"
#include <typeinfo>
using namespace std;

LinkedList::LinkedList(){
  head=NULL;
  tail=NULL;
  size=0;
}

void LinkedList::addCiudadano(Ciudadano* ciudadano){
  Node* nuevo = new Node;
  nuevo->ciudadano = ciudadano;
  nuevo->next = NULL;
  if (head==NULL) {
    head=nuevo;
    tail=nuevo;
    nuevo=NULL;
  }else{
    tail->next = nuevo;
    tail = tail->next;
  }
  size++;
}

void LinkedList::display(){
  int cuenta=1;
  Node* nuevo=new Node;
  nuevo=head;
  while (nuevo!=NULL) {
    cout<<cuenta <<". " <<nuevo->ciudadano->getNombre()<<endl;
    nuevo=nuevo->next;
    cuenta++;
  }
}

void LinkedList::displayMaestros(){
  int cuenta=1;
  Node* nuevo=new Node;
  nuevo=head;
  while (nuevo!=NULL) {
    if(typeid (*nuevo->ciudadano) == typeid(Maestro)){
      cout<<cuenta <<". " <<nuevo->ciudadano->getNombre()<<endl;
    }
    nuevo=nuevo->next;
    cuenta++;
  }
}

void LinkedList::displayEstudiantes(){
  int cuenta=1;
  Node* nuevo=new Node;
  nuevo=head;
  while (nuevo!=NULL) {
    if(typeid (*nuevo->ciudadano) == typeid(Estudiante)){
      cout<<cuenta <<". " <<nuevo->ciudadano->getNombre()<<endl;
    }
    nuevo=nuevo->next;
    cuenta++;
  }
}

void LinkedList::insert(int pos, Ciudadano* pCiudadano){
  Node* antes=new Node;
  Node* ahora=new Node;
  Node* nuevo=new Node;
  ahora=head;
  if (pos==1) {
    nuevo->ciudadano=pCiudadano;
    nuevo->next=head;
    head=nuevo;
  }else{
    for (int i = 1; i < pos; i++) {
      antes=ahora;
      ahora=ahora->next;
    }
    nuevo->ciudadano=pCiudadano;
    antes->next=nuevo;
    nuevo->next=ahora;
  }
  size++;
}

void LinkedList::remove(int pos){
  Node* ahora=new Node;
  Node* antes=new Node;
  ahora=head;
  if (pos==1) {
    head=head->next;
    delete ahora;
  }else{
    for (int i = 1; i < pos; i++) {
      antes=ahora;
      ahora=ahora->next;
    }
    antes->next=ahora->next;
  }
  size--;
}

int LinkedList::getSize(){
  return size;
}

Ciudadano* LinkedList::get(int pos){
  Node* nuevo=new Node;
  nuevo=head;
  if (pos!=1) {
    for(int i=1; i<pos; i++) {
      nuevo=nuevo->next;
    }
  }
  return nuevo->ciudadano;
}
