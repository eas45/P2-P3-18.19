// 48788593G - Esteban Antón Sellés

#include "Base.h"

Base::Base(string name)
{
  this->name = name;
}

/* Devuelve el contenedor buscado por su ID
  * Return::Container
  * Throw::
    - ERR_CONTAINER_ID
*/
Container Base::getContainer(unsigned int id) const
{
  int pos = searchContainer(id);

  if (pos == -1)
  {
    throw ERR_CONTAINER_ID;
  }

  return containers[pos];
}

/* Devuelve el puntero a la nave buscada por su nombre
  * Return::Ship*
  * Throw::
    - ERR_SHIP_NAME
*/
Ship* Base::getShip(string name) const
{
  int pos = searchShip(name);

  if (pos == -1)
  {
    throw ERR_SHIP_NAME;
  }

  return ships[pos];
}

/* Devuelve la posición del contenedor en el vector 'containers' buscado por el ID
  * Return::int
    - (posición) -> Si encuentra el contenedor
    - (-1) -> Si no encuentra el contenedor
*/
int Base::searchContainer(unsigned int id) const
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

/* Devuelve la posición de la nave en el vector 'ships' buscada por el nombre
  * Return::int
    - (posición) -> Si encuentra la nave
    - (-1) -> Si no encuentra la nave
*/
int Base::searchShip(string name) const
{
  int pos = -1;

  for (unsigned int i = 0; i < ships.size() && pos == -1; i++)
  {
    if (ships[i]->getName() == name)
    {
      pos = i;
    }
  }

  return pos;
}

/* Añade un contenedor a la Base
  * Return::bool
    - True -> Se ha podido añadir
    - False -> No se ha podido añadir
  * Error::
    - ERR_CONTAINER_WEIGHT (Container)
    - ERR_CONTAINER_VALUE (Container)
*/
bool Base::addContainer(unsigned int weight, unsigned int value)
{
  bool added = true;

  try
  {
    Container cont = Container(weight, value);
    containers.push_back(cont);
  }
  catch (Error e)
  {
    added = false;
    Util::error(e);
  }

  return added;
}

/* Elimina el contenedor de la Base
  * Return::bool
    - True -> Se ha eliminado el contenedor
    - False -> No se ha eliminado el contenedor
  * Error::
    - ERR_CONTAINER_ID
*/
bool Base::removeContainer(unsigned int id)
{
  int pos = searchContainer(id);
  bool removed = true;

  if (pos == -1)
  {
    removed = false;
    Util::error(ERR_CONTAINER_ID);
  }
  else
  {
    containers.erase(containers.begin() + pos);
  }

  return removed;
}

/* Añade el puntero a una nave a la Base
  * Return::bool
    - True -> Se ha podido añadir
    - False -> No se ha podido añadir
  * Error::
    - ERR_SHIP_NAME
*/
bool Base::addShip(Ship* s)
{
  int pos = searchShip(s->getName());
  bool added = true;

  if (pos == -1)
  {
    ships.push_back(s);
  }
  else
  {
    added = false;
    Util::error(ERR_SHIP_NAME);
  }

  return added;
}

/* Elimina el puntero a la nave de la Base
  * Return::bool
    - True -> Se ha eliminado el puntero a la nave
    - False -> No se ha eliminado el puntero a la nave
  * Error::
    - ERR_SHIP_NAME
*/
bool Base::removeShip(string name)
{
  int pos = 0;
  bool removed = true;
  vector<Container> conts;

  if (name == "")
  {
    cout << "Ship name: ";
    getline(cin, name);
  }
  pos = searchShip(name);
  if (pos == -1)
  {
    removed = false;
    Util::error(ERR_SHIP_NAME);
  }
  else
  {
    conts = ships[pos]->releaseContainers();
    for (unsigned int i = 0; i < conts.size(); i++)
    {
      containers.push_back(conts[i]);
    }
    ships.erase(ships.begin() + pos);
  }

  return removed;
}

/* Distribuye manualmente contenedores a naves.
  * Return::bool
    - True -> Se ha podido distribuir correctamente
    - False -> No se ha podido distribuir correctamente
  * Error::
    - ERR_CONTAINER_ID
    - ERR_SHIP_NAME
    - ERR_SHIP_NO_MORE_CONTAINERS (addContainer)
    - ERR_SHIP_NO_MORE_WEIGHT (addContainer)
*/
bool Base::manualDistribution(unsigned int id, string name)
{
  bool distributed = false;
  int cont_p = 0;
  int ship_p = 0;

  // Pide valores
  if (id == 0)
  {
    cout << "Container id: " << endl;
    cin >> id;
    cin.get();
  }
  cont_p = searchContainer(id);
  if (name == "")
  {
    cout << "Ship name: " << endl;
    getline(cin, name);
  }
  ship_p = searchShip(name);
  // Comprueba que exista
  if (cont_p == -1)
  {
    Util::error(ERR_CONTAINER_ID);
  }
  else if (ship_p == -1)
  {
    Util::error(ERR_SHIP_NAME);
  }
  else if (ships[ship_p]->addContainer(containers[cont_p]))
  {  // Se borra el contenedor de base porque ahora está en una nave
    containers.erase(containers.begin() + cont_p);
    distributed = true;
  }

  return distributed;
}

/* Desasigna un contenedor de una nave y lo devuelve a la Base
  * Return::bool
    - True -> Lo ha desasignado
    - False -> No lo ha desasignado
  * Error::
    - ERR_SHIP_NAME
    - ERR_CONTAINER_ID (removeContainer)
*/
bool Base::unassignContainer(unsigned int id, string name)
{
  bool unassigned = false;
  int ship_p = 0;

  if (name == "")
  {
    cout << "Ship name: " << endl;
    getline(cin, name);
  }
  ship_p = searchShip(name);
  if (ship_p == -1)
  {
    Util::error(ERR_SHIP_NAME);
  }
  else
  {
    if (id == 0)
    {
      cout << "Container id: ";
      cin >> id;
      cin.get();
    }
    ships[ship_p]->removeContainer(id);
    unassigned = true;
  }

  return unassigned;
}

/* Selecciona un contenedor que cumpla las condiciones de selección del algoritmo
  * Return::int
    - (Posición) -> Posición del contenedor en Base
*/
int selectCont() const
{
  int pos = 0;
  unsigned int maxValue = containers[pos].getValue();
  unsigned int minWeight = containers[pos].getWeight();

  if (cont)

  return pos;
}

/* Distribuye automáticamente los contenedores de Base en nave
  * Return::void
*/
void Base::automaticDistribution()
{
  bool end = false;
  int cont_p = 0;

  while (!containers.empty() && !ships.empty() && !end)
  {
    // 1) Se elige CONTENEDOR de máximo valor y mínimo peso
    cont_p = selectCont();
    // 2) Se elige NAVE de menor valor acumulado
  }
}