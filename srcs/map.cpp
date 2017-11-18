#include "map.hh"
#include "Player.hh"

bomber::Map::Map() : _end(0), _time(0) {}

bomber::Map::~Map() {}

// TODO: use throw instead of return and make void methods

int	bomber::Map::buildMap()
{
  initSize();
  for (size_t x = 1; x < map.size() && x != _size.X; x++)
    {
      for (size_t y = 0; y < map[x].size() && y != _size.Y; y++)
	charToObj(bomber::v2d(x - 1, y));
    }
}

bomber::v2d	bomber::Map::getPlayerPosition(bool second) const
{
  // TODO: choose position in map (find char 'p')
  if (second)
    return bomber::v2d(15, 15);
  return bomber::v2d(3, 3);
}

void	bomber::Map::addPlayer(bool second)
{
  _player.push_back(Player(getPlayerPosition(false), this));
  if (second)
    _player.push_back(Player(getPlayerPosition(second), this));
}

int	bomber::Map::putGround(const int x, const int z, const int y,
		       const std::string &texture)
{
  irr::scene::IAnimatedMeshSceneNode*	node;
  irr::scene::IAnimatedMesh*		mesh;
  t_storNodes				mynode;

  if (!(mesh = _smgr->getMesh("obj/box.obj")))
    return 1;
  else if ((node = _smgr->addAnimatedMeshSceneNode(mesh)))
    {
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setMD2Animation(irr::scene::EMAT_STAND);
      node->setPosition(irr::core::vector3df((x * 100) + _base.X, z * 50,
					     (y * 100) + _base.Y));
      node->setRotation(irr::core::vector3df(0,0,0));
      node->setMaterialTexture(0, _driver->getTexture(texture.c_str()));
      mynode.node = node;
      mynode.x = x;
      mynode.y = y;
      if (z == 2)
      	this->_nCrate.push_back(mynode);
      else
	this->_nGround.push_back(mynode);
      if (z > 0)
        putGround(x, 0, y, "obj/texture/ground.jpg");
    }
  return (0);
}

int	bomber::Map::charToObj(bomber::v2d const & pos)
{
  switch(getInfoPosition(pos))
    {
    case ' ':
      return (putGround(pos.X, 0, pos.Y, "obj/texture/ground.jpg"));
      break;
    case '~':
      return (putGround(pos.X, 0, pos.Y, "obj/texture/water.jpg"));
      break;
    case 'i':
      return (putGround(pos.X, 1, pos.Y, "obj/texture/grayground.jpg"));
      break;
    case 'c':
      return (putGround(pos.X, 2, pos.Y, "obj/texture/woodbox.png"));
      break;
    case 'l':
      return (putGround(pos.X, 0, pos.Y, "obj/texture/lavaground.jpg"));
      break;
    }
  return (0);
}

int	bomber::Map::initSize()
{
  std::string	str = map[0];

  int	n = std::stoi(str.substr(0, str.find('-')));
  this->_base.X = (n * -100) / 2 + 100;
  _size.X = n + 1;

  n = std::stoi(str.substr(str.find('-') + 1));
  this->_base.Y = (n * -100) / 2 + 100;
  _size.Y = n;

  if (this->_base.X == 0 || this->_base.Y == 0)
    return (0);
  return (1);
  // NOTE: on error throw 'Size of map incorect'
}

// TODO: Use an enum
char	bomber::Map::getInfoPosition(bomber::v2d const & pos) const { return map[pos.X + 1][pos.Y]; }
void	bomber::Map::setInfoPosition(bomber::v2d const & pos, char c) { map[pos.X + 1][pos.Y] = c; }

int				bomber::Map::getBaseX() const { return _base.X; }
int				bomber::Map::getBaseY() const { return _base.Y; }
int				bomber::Map::getX() const { return _size.X; }
int				bomber::Map::getY() const { return _size.Y; }
bomber::v2d const &		bomber::Map::getBase() const { return _base; }
bomber::v2d const &		bomber::Map::getSize() const { return _size; }
std::vector<std::string>	bomber::Map::getMap() const { return map; }
irr::video::IVideoDriver *	bomber::Map::getVideoDriver() const { return _driver; }
irr::scene::ISceneManager *	bomber::Map::getSceneManager() const { return _smgr; }

void	bomber::Map::setTime(irr::u32 time) { _time = time; }
void	bomber::Map::setMap(const std::vector<std::string> file) { map = file; }
void	bomber::Map::setVideoDriver(irr::video::IVideoDriver *driver) { _driver = driver; }
void	bomber::Map::setSceneManager(irr::scene::ISceneManager* smgr) { _smgr = smgr; }
