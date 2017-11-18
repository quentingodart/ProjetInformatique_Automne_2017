//
// Player.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 07:50:47 2017 Anaïs Foncel
// Last update Sat Nov 18 06:14:40 2017 Anaïs Foncel
//

#include "Player.hh"

Bomber::Player::Player(Bomber::v2d const &pos)
  : _bombs(1), _bombsUse(0), _range(1), _speed(1), _pos(pos)
{
  irr::scene::IAnimatedMesh	*mesh;
}

Bomber::Player::~Player()
{

}

void	Bomber::Player::movePlayer(bool move, Bomber::e_direction dir, Bomber::v2d initPos)
{
  if (move)
    {
      _pos += Bomber::getMovVector(dir);
      this->_node->setPosition(irr::core::vector3df((_pos.X * 100)
						    + initPos.X - 40, 110,
						    (_pos.Y * 100)
						    + initPos.Y + 50));
    }
  this->_node->setRotation(irr::core::vector3df(0, Bomber::getRotValue(dir), 0));
}

void	Bomber::Player::takeBonus(e_bonus bonus)
{
  switch (bonus)
    {
    case B_SPEED:
      addSpeed();
      break;
    case B_RANGE:
      addRange();
      break;
    case B_BOMB:
      addBomb();
      break;
    }
}

void	Bomber::Player::addSpeed()
{
  if (_speed < MAX_SPEED)
    _speed++;
}

void	Bomber::Player::addRange()
{
  if (_range < MAX_RANGE)
    _range++;
}

void	Bomber::Player::addBomb()
{
  if (_bombs < MAX_BOMB)
    _bombs++;
}

/*
** Setter
*/
void	Bomber::Player::setBombs(int nb)
{
  _bombs = nb;
}

void	Bomber::Player::setBombsUse(int nb)
{
  _bombsUse += nb;
}

void	Bomber::Player::setRange(int nb)
{
  _range = nb;
}

/*
** Getter
*/
int	Bomber::Player::getBombs() const
{
  return _bombs;
}

int	Bomber::Player::getBombsUse() const
{
  return _bombsUse;
}

int	Bomber::Player::getRange() const
{
  return _range;
}

int	Bomber::Player::getX() const
{
  return _pos.X;
}

int	Bomber::Player::getY() const
{
  return _pos.Y;
}

Bomber::v2d const	&Bomber::Player::getPos() const
{
  return _pos;
}

irr::scene::IAnimatedMeshSceneNode	*Bomber::Player::getNode() const
{
  return _node;
}
