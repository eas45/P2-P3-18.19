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
    - ERR_CONTAINER_WEIGHT
    - ERR_CONTAINER_VALUE
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
  int pos = searchShip(name);
  bool removed = true;

  if (name == "")
  {
    cout << "Ship name: ";
    getline(cin, name);
  }
  if (pos == -1)
  {
    removed = false;
    Util::error(ERR_SHIP_NAME);
  }
  else
  {
    ships.erase(ships.begin() + pos);
  }

  return removed;
}


/* Distribuye manualmente contenedores a naves.
  * Return::bool
    - True -> Se ha podido distribuir correctamente
    - False -> No se ha podido distribuir correctamente
*/
bool Base::manualDistribution(unsigned int id, string name)
{
  bool distributed = true;
  int cont_p = 0;
  int cont_s = 0;

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
  cont_s = searchShip(name);
  // Comprueba que exista
  if (cont_p == -1)
  {
    Util::error(ERR_CONTAINER_ID);
  }
  else if (cont_s == -1)
  {
    Util::error(ERR_SHIP_NAME);
  }
  else
  {

  }

  return distributed;
}