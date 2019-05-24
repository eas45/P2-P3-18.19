// 48788593G - Esteban Antón Sellés

#include "Container.h"

unsigned int Container::nextId = 1;

/* CONSTRUCTOR
*/
Container::Container(unsigned int weight, unsigned int value)
{
  if (weight == 0)
  {
    cout << "Container weight: ";
    cin >> weight;
    cin.get();
    checkWeight(weight);
  }
  if (value == 0)
  {
    cout << "Container value: ";
    cin >> value;
    cin.get();
    checkValue(value);
  }
  checkWeight(weight);
  checkValue(value);
  // Se construye el objeto
  this->weight = weight;
  this->value = value;
  id = Container::nextId;
  Container::nextId++;
}

// ##### SETTERs ######
/* Weight
*/
void Container::setWeight(unsigned int weight)
{
  checkWeight(weight);
  this->weight = weight;
}

/* Value
*/
void Container::setValue(unsigned int value)
{
  checkValue(value);
  this->value = value;
}


// ###### Métodos y funciones propias ######

/* Comprueba si el peso está dentro del mínimo permitido
*/
void Container::checkWeight(unsigned int weight)
{
  if (weight < kMINWEIGHT)
  {
    throw ERR_CONTAINER_WEIGHT;
  }
}

/* Comprueba si el valor está dentro del mínimo permitido
*/
void Container::checkValue(unsigned int value)
{
  if (value < kMINVALUE)
  {
    throw ERR_CONTAINER_VALUE;
  }
}

// Operador de salida
ostream& operator<<(ostream &os, const Container &c)
{
  os << "[" << c.id << " "
     << c.weight << ":"
     << c.value << "]";

  return os; 
}