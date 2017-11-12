#include "Core.hh"

bomber::Core::Core() : _device, _driver(0), _smgr(0)
{}

bomber::Core::Core()
{}


void	bomber::Core::init()
{}

void	bomber::Core::clear()
{}

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
{}

bool	bomber::Core::isKeyPressed(bool pressedDown, irr::EKEY_CODE key, irr::SEvent const & event)
{}

bool	bomber::Core::OnEvent(irr::SEvent const & e)
{}
