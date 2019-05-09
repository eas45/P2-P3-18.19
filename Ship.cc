// 48788593G - Esteban Antón Sellés

#include "Ship.h"

// CONSTRUCTORES

/* Por defecto
*/
Ship::Ship()
{
  string name = "";
  unsigned int maxCont = 0;
  unsigned int maxWeight = 0;

  cout << "Ship name: ";
  cin >> name;
  cout << "Ship max. containers: ";
  cin >> maxCont;
  checkMaxContainers(maxCont);
  cout << "Ship max. weight: ";
  cin >> maxWeight;
  checkMaxWeight(maxWeight);
  // Se construye el objeto
  this->name = name;
  this->weight = 0;
  this->value = 0;
  this->maxWeight = maxWeight;
  this->maxContainers = maxCont;
}

Ship::Ship(string name, unsigned int maxContainers, unsigned int maxWeight)
{
  checkMaxContainers(maxContainers);
  checkMaxWeight(maxWeight);
  // Se construye el objeto
  this->name = name;
  this->weight = 0;
  this->value = 0;
  this->maxWeight = maxWeight;
  this->maxContainers = maxContainers;
}

// # Métodos y funciones de la práctica #

/* Busca un contenedor por su ID en la nave
  * Return::int
    - (posición) -> Si encuentra el contenedor
    - (-1) -> Si no encuentra el contenedor
*/
int Ship::searchContainer(unsigned int id) const
{
  int pos = -1;

  for (unsigned int i = 0; i < getNumContainers() && pos == -1; i++)
  {
    if (containers[i].getId() == id)
    {
      pos = i;
    }
  }

  return pos;
}

/* Comprueba si cabe un contenedor tanto por espacio como por peso
*/
bool Ship::admitsContainer(const Container &c) const
{
  bool admits = false;

  if (getNumContainers() < getMaxContainers() &&
      getWeight() + c.getWeight() <= getMaxWeight())
  {
    admits = true;
  }

  return admits;
}

/* Devuelve el contenedor buscado por su ID
  * Throw::
    - ERR_CONTAINER_ID
*/
Container Ship::getContainer(unsigned int id) const
{
  int pos = searchContainer(id);

  if (pos == -1)
  {
    throw ERR_CONTAINER_ID;
  }

  return containers[pos];
}

// # Métodos y funciones propias #

/* Comprueba si el número máximo de contenedore está dentro del mínimo permitido.
*/
void Ship::checkMaxContainers(unsigned int maxCont)
{
  if (maxCont < kMINCONTAINERS)
  {
    throw ERR_SHIP_MAXCONTAINERS;
  }
}

void Ship::checkMaxWeight(unsigned int maxWeight)
{
  if (maxWeight < kMINWEIGHT)
  {
    throw ERR_SHIP_MAXWEIGHT;
  }
}

// Operador de salida
ostream& operator<<(ostream &os, const Ship &s)
{
  os << "{" << s.name << ":"
     << " " << s.weight << " "
     << "(" << s.maxWeight << "),"
     << " " << s.containers.size() << " "
     << "(" << s.maxContainers << "),"
     << " " << s.value << endl;
  // Muestra todos los contenedores de la nave
  for (unsigned i = 0; i < s.containers.size(); i++)
  {
    os << s.containers[i];
  }
  if (!s.containers.empty())
  {
    os << endl;
  }
  os << "}" << endl;

  return os;
}