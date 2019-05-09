// 48788593G - Esteban Antón Sellés

#include "Container.h"

unsigned int Container::nextId = 1;

/* CONSTRUCTOR
*/
Container::Container(unsigned int weight, unsigned int value)
{
  unsigned int aux_weight = weight;
  unsigned int aux_value = value;

  if (weight == 0)
  {
    cout << "Container weight: ";
    cin >> aux_weight;
    checkWeight(aux_weight);
  }
  if (value == 0)
  {
    cout << "Container value: ";
    cin >> aux_value;
    checkValue(aux_value);
  }
  checkWeight(aux_weight);
  checkValue(aux_value);
  // Se construye el objeto
  this->weight = aux_weight;
  this->value = aux_value;
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

ostream& operator<<(ostream &os, const Container &c)
{
  os << "[" << c.id << " "
     << c.weight << ":"
     << c.value << "]";

  return os; 
}