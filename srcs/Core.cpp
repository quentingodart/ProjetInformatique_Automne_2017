#include "Core.hh"

bomber::Core::Core() : _device, _driver(0), _smgr(0)
{}

bomber::Core::Core()
{}


void	bomber::Core::init()
{
  if ((_device = irr::createDevice(video::EDT_OPENGL,
				   irr::core::dimension2d<irr::u32>(GAME_DIM('x'), GAME_DIM('y')),
				   DEFAULT_BPP, false, false, false, this)) == NULL)
    throw 1;
  if ((_driver = _device->getVideoDriver()) == NULL)
    throw 2;
  if ((_smgr = _device->getSceneManager()) == NULL)
    throw 3;
  _device->setWindowCaption(GAME_TITLE);
}

void	bomber::Core::clear()
{
  _device->drop()
}

void	bomber::Core::update()
{
  _device->drop();
}

void	bomber::Core::draw()
{
  if (_device->isWindowActive())
    {
      _driver->beginScene(true, true, irr::video::SColor(255,20,20,24));
      _smgr->drawAll();
      _driver->endScene();
    }
  else
    _device->yield();
}

bool	bomber::Core::run(std::string const & mapFile, bool secondPlayer)
{
  init();
  int y = 2100;
  while (_run && _device->run())
    {
      update();
      // TODO: use animation
      if (y != 1000)
	{
	  _smgr->addCameraSceneNode(0, irr::core::vector3df(y,1400,0), irr::core::vector3df(0,-800,0));
	  y -= 20;
	}
      draw();
    }
  clear();
  return;
}

bool	bomber::Core::isKeyPressed(bool pressedDown, irr::EKEY_CODE key, irr::SEvent const & event)
{}

bool	bomber::Core::OnEvent(irr::SEvent const & e)
{}
