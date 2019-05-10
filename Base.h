// 48788593G - Esteban Antón Sellés

#ifndef _BASE_
#define _BASE_

#include "Ship.h"

class Base
{

  protected:
    string name;
    vector<Ship*> ships;
    vector<Container> containers;

  private:  // Métodos y funciones propios
  

  public:
    Base(string name);
    string getName() const { return name; }
    unsigned int getNumContainers() const { return containers.size(); }
    unsigned int getNumShips() const { return ships.size(); }
    Container getContainer(unsigned int id) const;
    Ship* getShip(string name) const;
    int searchContainer(unsigned int id) const;
    int searchShip(string name) const;
    bool addContainer(unsigned int id = 0, unsigned int value = 0);
    bool removeContainer(unsigned int id = 0);
};

#endif