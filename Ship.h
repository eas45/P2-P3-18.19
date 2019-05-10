// 48788593G - Esteban Antón Sellés

#ifndef _SHIP_
#define _SHIP_

#include "Container.h"
#include <vector>

class Ship
{
  friend ostream& operator<<(ostream &os, const Ship &s);

  protected:
    string name;
    unsigned int weight;
    unsigned int value;
    unsigned int maxWeight;
    unsigned int maxContainers;
    vector<Container> containers;

  private:  // Métodos y funciones propios
    void checkMaxContainers(unsigned int maxCont) const;
    void checkMaxWeight(unsigned int maxWeight) const;
    bool containerFits_nConts() const;
    bool containerFits_weight(const Container &c) const;

  public:
    static const unsigned int kMINCONTAINERS = 5;
    static const unsigned int kMINWEIGHT = 500;
    Ship();
    Ship(string name, unsigned int maxContainers, unsigned int maxWeight);
    string getName() const { return name; }
    unsigned int getWeight() const { return weight; }
    unsigned int getValue() const { return value; }
    unsigned int getMaxWeight() const { return maxWeight; }
    unsigned int getMaxContainers() const { return maxContainers; }
    unsigned int getNumContainers() const { return containers.size(); }
    int searchContainer(unsigned int id) const;
    bool admitsContainer(const Container &c) const;
    Container getContainer(unsigned int id) const;
    bool addContainer(const Container &c);
    bool removeContainer(unsigned int id);
    vector<Container> releaseContainers();
};

#endif