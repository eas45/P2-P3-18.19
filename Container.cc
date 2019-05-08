// 48788593G - Esteban Antón Sellés

#include "Container.h"

Container::Container(unsigned int weight, unsigned int value)
{
  unsigned int aux_weight = weight;
  unsigned int aux_value = value;

  if (weight == 0)
  {
    cout << "Container weight: ";
    cin >> aux_weight;
    if (aux_weight < kMINWEIGHT)
    {
      throw ERR_CONTAINER_WEIGHT;
    }
  }
  if (value == 0)
  {
    cout << "Container value: ";
    cin >> aux_value;
    if (aux_value < kMINVALUE)
    {
      throw ERR_CONTAINER_VALUE;
    }
  }
  if (aux_weight < kMINWEIGHT)
  {
    throw ERR_CONTAINER_WEIGHT;
  }
  if (aux_value < kMINVALUE)
  {
    throw ERR_CONTAINER_VALUE;
  }
  // Se construye el objeto
  this->weight = aux_weight;
  this->value = aux_value;
}

ostream& operator<<(ostream &os, const Container &c)
{
  
  return os; 
}