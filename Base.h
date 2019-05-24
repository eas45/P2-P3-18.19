// 48788593G - Esteban Antón Sellés

#ifndef _BASE_
#define _BASE_

#include "Ship.h"
#include <limits>

class Base
{
  friend ostream& operator<<(ostream &os, const Base &b);

  protected:
  string name;
  vector<Ship*> ships;
  vector<Container> containers;

  private:  // Métodos y funciones propios
  unsigned int selectCont() const;
  int selectShip(unsigned int cont_p) const;
  bool divideContainer(unsigned int cont_p);

  public:
  Base(string name);
  string getName() const { return name; }
  unsigned int getNumContainers() const { return containers.size(); }
  unsigned int getNumShips() const { return ships.size(); }
  Container getContainer(unsigned int id) const;
  Ship* getShip(string name) const;
  int searchContainer(unsigned int id) const;
  int searchShip(string name) const;
  bool addContainer(unsigned int weight = 0, unsigned int value = 0);
  bool removeContainer(unsigned int id = 0);
  bool addShip(Ship* s);
  bool removeShip(string name = "");
  bool manualDistribution(unsigned int id = 0, string name = "");
  bool unassignContainer(unsigned int id = 0, string name = "");
  void automaticDistribution();
  void clearAssignations();
};

#endif