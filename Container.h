// 48788593G - Esteban Antón Sellés

#ifndef _CONTAINER_
#define _CONTAINER_

#include <iostream>
#include "Util.h"


class Container
{
  friend ostream& operator<<(ostream &os, const Container &c);

  protected:
    unsigned int id;
    unsigned int value;
    unsigned int weight;
    static unsigned int nextId;

  private:  // Métodos y funciones propios
    void checkWeight(unsigned int weight);
    void checkValue(unsigned int value);

  public:
    static const unsigned int kMINWEIGHT = 100;
    static const unsigned int kMINVALUE = 100;
    Container(unsigned int weight = 0, unsigned int value = 0);
    static void resetId() { nextId = 1; }
    unsigned int getId() const { return id; }
    unsigned int getWeight() const { return weight; }
    unsigned int getValue() const { return value; }
    void setWeight(unsigned int weight);
    void setValue(unsigned int value);
};

//unsigned int Container::nextId = 1;

#endif