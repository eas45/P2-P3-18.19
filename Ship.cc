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
  getline(cin, name);
  cout << "Ship max. containers: ";
  cin >> maxCont;
  cin.get();
  checkMaxContainers(maxCont);
  cout << "Ship max. weight: ";
  cin >> maxWeight;
  cin.get();
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

  for (unsigned int i = 0; i < containers.size() && pos == -1; i++)
  {
    if (containers[i].getId() == id)
    {
      pos = i;
    }
  }

  return pos;
}

/* Comprueba si cabe un contenedor tanto por espacio como por peso
  * Return::bool
    - True -> Cabe
    - False -> No cabe
*/
bool Ship::admitsContainer(const Container &c) const
{
  bool admits = false;

  if (containerFits_nConts() && containerFits_weight(c))
  {
    admits = true;
  }

  return admits;
}

/* Devuelve el contenedor buscado por su ID
  * Throws::
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

/* Añade un contenedor a la nave
  * Return::bool
    - True -> Se ha podido añadir el contenedor
    - False -> No se ha podido añadir el contenedor
  * Error::
    - ERR_SHIP_NO_MORE_CONTAINERS
    - ERR_SHIP_NO_MORE_WEIGHT
*/
bool Ship::addContainer(const Container &c)
{
  bool added = false;

  if (containerFits_nConts())
  {
    if (containerFits_weight(c))
    {
      containers.push_back(c);
      added = true;
      // Actualiza los datos de la nave
      weight += c.getWeight();
      value += c.getValue();
    }
    else
    {
      Util::error(ERR_SHIP_NO_MORE_WEIGHT);
    }
  }
  else
  {
    Util::error(ERR_SHIP_NO_MORE_CONTAINERS);
  }

  return added;
}

/* Elimina el contenedor de la nave
  * Return::bool
    - True -> Se ha eliminado el contenedor
    - False -> No se ha eliminado el contenedor
  * Error::
    - ERR_CONTAINER_ID
*/
bool Ship::removeContainer(unsigned int id)
{
  bool removed = true;
  int pos = searchContainer(id);

  if (pos == -1)
  {
    removed = false;
    Util::error(ERR_CONTAINER_ID);
  }
  else
  {
    // Actualiza los datos de la nave
    weight -= containers[pos].getWeight();
    value -= containers[pos].getValue();
    // Elimina
    containers.erase(containers.begin() + pos);
  }

  return removed;
}

/* Devuelve los contenedores que hay en la nave y los elimina de esta
  * Return::vector<Container>
*/
vector<Container> Ship::releaseContainers()
{
  vector<Container> conts(containers);

  containers.clear();
  weight = 0;
  value = 0;

  return conts;
}

// # Métodos y funciones propias #

/* Comprueba si el número máximo de contenedores está dentro del mínimo permitido.
  * Throws::
    - ERR_SHIP_MAXCONTAINERS
*/
void Ship::checkMaxContainers(unsigned int maxCont) const
{
  if (maxCont < kMINCONTAINERS)
  {
    throw ERR_SHIP_MAXCONTAINERS;
  }
}

/* Comprueba si el número máximo de peso está dentro del mínimo permitido.
  * Throws::
    - ERR_SHIP_MAXWEIGHT
*/
void Ship::checkMaxWeight(unsigned int maxWeight) const
{
  if (maxWeight < kMINWEIGHT)
  {
    throw ERR_SHIP_MAXWEIGHT;
  }
}

/* Conmprueba que quede sitio para un contenedor
  * Return::bool
    - True -> Cabe
    - False -> No cabe
*/
bool Ship::containerFits_nConts() const
{
  bool fits = false;

  if (containers.size() < maxContainers)
  {
    fits = true;
  }

  return fits;
}

/* Comprueba que quepa un contenedor por su peso
  * Return::bool
    - True -> Cabe
    - False -> No cabe
*/
bool Ship::containerFits_weight(const Container &c) const
{
  bool fits = false;

  if (weight + c.getWeight() <= maxWeight)
  {
    fits = true;
  }

  return fits;
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