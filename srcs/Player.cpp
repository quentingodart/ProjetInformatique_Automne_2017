//
// Player.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 07:50:47 2017 Anaïs Foncel
// Last update Mon Dec  4 01:35:14 2017 Anaïs Foncel
//

#include "Player.hh"

bomber::Player::Player(bomber::v2d const &pos, bomber::Map const *map, bool secondP, int IA, std::string const name)
  : _name(name), _job("Etudiant à l'UQAR de Rimouski"), _bombs(1), _bombsUse(0), _range(1), _speed(1), _lastTime(0), _pos(pos), _node(0)
{
  irr::scene::IAnimatedMesh	*mesh;

  if (!(mesh = map->getSceneManager()->getMesh("assets/player.b3d")))
    exit(1);
  else if (_node = map->getSceneManager()->addAnimatedMeshSceneNode(mesh))
    {
      this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->_node->setMD2Animation(irr::scene::EMAT_STAND);
      this->_node->setPosition(irr::core::vector3df((pos.X * 100) + map->getBaseX() - 40, 110,
						    (pos.Y * 100) + map->getBaseY() + 50));

      this->_node->setFrameLoop(0, 13);
      this->_node->setAnimationSpeed(5);
      this->_node->setScale(irr::core::vector3df(10));
      this->_node->setRotation(irr::core::vector3df(0, 0, 0));
      if (!secondP && IA == 0)
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
  if (time > (_lastTime + (MOV_SPD / _speed)))
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
      _lastTime = time;
    }
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

int	bomber::Player::getSpeed() const
{
  return _speed;
}

std::string	bomber::Player::getName() const
{
  return _name;
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
