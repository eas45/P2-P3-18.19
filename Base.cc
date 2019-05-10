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
*/
bool Base::addContainer(unsigned int id, unsigned int value)
{
  bool added = false;

  

  return added;
}