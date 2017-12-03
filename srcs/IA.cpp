#include "IA.hh"
#include <unistd.h>
#include <stdlib.h>

bomber::IA::IA(bomber::v2d const &pos, bomber::Map *map, bool secondP, int idIA, std::string name) : Player(pos, map, secondP, idIA, name)
{
  _idIA = idIA;
  std::cout << "Constructeur IA OK : IA n° " << _idIA << std::endl;
}

bomber::IA::~IA()
{
  std::cout << "Destructeur IA OK : IA n° " << _idIA << std::endl;
}

void		bomber::IA::moveUp()
{
  _map->movePlayer(_idIA, D_UP);
}

void		bomber::IA::moveDown()
{
  _map->movePlayer(_idIA, D_DOWN);
}

void		bomber::IA::moveRight()
{
  _map->movePlayer(_idIA, D_RIGHT);
}

void		bomber::IA::moveLeft()
{
  _map->movePlayer(_idIA, D_LEFT);
}

void		bomber::IA::putBomb()
{

}

void		bomber::IA::play()
{
  int		dir;

  while (0) {
    dir = rand() % 6 + 1; // nombre aléatoire entre 1 et 6
    if (dir == 1)
      moveUp();
    else if (dir == 2)
      moveDown();
    else if (dir == 3)
      moveRight();
    else if (dir == 4)
      moveLeft();
    else if (dir == 5)
      putBomb();
  }
}
