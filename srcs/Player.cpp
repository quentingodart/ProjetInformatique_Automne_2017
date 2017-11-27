//
// Player.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 07:50:47 2017 Anaïs Foncel
// Last update Mon Nov 27 01:26:22 2017 Anaïs Foncel
//

#include "Player.hh"

bomber::Player::Player(bomber::v2d const &pos, bomber::Map const *map, bool secondP)
  : _bombs(1), _bombsUse(0), _range(1), _speed(1), _pos(pos), _node(0)
{
  irr::scene::IAnimatedMesh	*mesh;

  if (!(mesh = map->getSceneManager()->getMesh("obj/player.b3d")))
    exit(1);
  else if (_node = map->getSceneManager()->addAnimatedMeshSceneNode(mesh))
    {
      this->_node->setPosition(irr::core::vector3df((pos.X * 100) + map->getBaseX() - 40, 110,
						    (pos.Y * 100) + map->getBaseY() + 50));

      this->_node->setAnimationSpeed(5);
      this->_node->setScale(irr::core::vector3df(10));
      this->_node->setRotation(irr::core::vector3df(0, 0, 0));
      if (!secondP)
	this->_node->setMaterialTexture(0, map->getVideoDriver()->getTexture("assets/texture/player1.png"));
      else
	this->_node->setMaterialTexture(0, map->getVideoDriver()->getTexture("assets/texture/player2.png"));
    }
}

bomber::Player::~Player()
{

}

void	bomber::Player::movePlayer(bool move, bomber::e_direction dir, bomber::v2d initPos, irr::u32 time)
{
  if (move)
    {
      _pos += bomber::getMovVector(dir);
      this->_node->setPosition(irr::core::vector3df((_pos.X * 100)
						    + initPos.X - 40, 110,
						    (_pos.Y * 100)
						    + initPos.Y + 50));
    }
  this->_node->setRotation(irr::core::vector3df(0, bomber::getRotValue(dir), 0));
}

void	bomber::Player::giveBonus(e_bonus bonus)
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

void	bomber::Player::addSpeed()
{
  if (_speed < MAX_SPEED)
    _speed++;
}

void	bomber::Player::addRange()
{
  if (_range < MAX_RANGE)
    _range++;
}

void	bomber::Player::addBomb()
{
  if (_bombs < MAX_BOMB)
    _bombs++;
}

/*
** Setter
*/
void	bomber::Player::setBombs(int nb)
{
  _bombs = nb;
}

void	bomber::Player::setBombsUse(int nb)
{
  _bombsUse += nb;
}

void	bomber::Player::setRange(int nb)
{
  _range = nb;
}

/*
** Getter
*/
int	bomber::Player::getBombs() const
{
  return _bombs;
}

int	bomber::Player::getBombsUse() const
{
  return _bombsUse;
}

int	bomber::Player::getRange() const
{
  return _range;
}

int	bomber::Player::getX() const
{
  return _pos.X;
}

int	bomber::Player::getY() const
{
  return _pos.Y;
}

bomber::v2d const	&bomber::Player::getPos() const
{
  return _pos;
}

irr::scene::IAnimatedMeshSceneNode	*bomber::Player::getNode() const
{
  return _node;
}
