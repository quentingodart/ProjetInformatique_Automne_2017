#include "Core.hh"

bomber::Core::Core()
  : _device(0), _driver(0), _smgr(0), _run(false), _menu(false), _deadTime(0), _map(), _pause(false)

{
  //  irr::video::EDT_OPENGL;
}
bomber::Core::~Core() {}

void	bomber::Core::init()
{
  if ((_device = irr::createDevice(irr::video::EDT_OPENGL,
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
  _device->drop();
}

void	bomber::Core::update(bool second, bool Ia)
{
  int	player;
  _map.setTime(_device->getTimer()->getTime());
  if (!_pause)
    {
      if (player = _map.checkBombes())
	{
	  // Dead screen
	  if (_deadTime == 0)
	    {
	      son.Play_Sound("./sono/mort.ogg");
	      _deadTime = _device->getTimer()->getTime();
	      irr::gui::IGUIImage	*img = _smgr->getGUIEnvironment()->addImage(irr::core::rect<irr::s32>(0,0,1600,900));
	      _timer = _device->getTimer()->getTime();
	      if (second)
		{
		  if (player == 2)
		    img->setImage(_driver->getTexture("assets/texture/dead_screen_player1.png"));
		  else
		    img->setImage(_driver->getTexture("assets/texture/dead_screen_player2.png"));
		}
	      else if (Ia) {
		if (player == 0)
		  img->setImage(_driver->getTexture("assets/texture/dead_screen_player1.png"));
		else
		  img->setImage(_driver->getTexture("assets/texture/dead_screen.png"));
	      }
	      else
		img->setImage(_driver->getTexture("assets/texture/dead_screen.png"));
	      img->setScaleImage(true);
	    }
	  _menu = true;
	}
      _map.checkExplosion();
      _map.checkBonus();
      if (_deadTime != 0 && _device->getTimer()->getTime() - _timer > 3000)
      _run = false;
    }
}

void	bomber::Core::draw()
{
  if (_device->isWindowActive())
    {
      _driver->beginScene(true, true, irr::video::SColor(255,20,20,24));
      if (!_deadTime && !_pause)
	{
	  _smgr->drawAll();
	}
      else
	_device->getGUIEnvironment()->drawAll();
      _driver->endScene();
    }
  else
    _device->yield();
}

bool	bomber::Core::run(std::string const & mapFile, bool secondPlayer, bool IA)
{
  init();
  _map.setVideoDriver(_driver);
  _map.setSceneManager(_smgr);
  _map.setMap(fileManager::openFileToVector(mapFile));
  _map.buildMap();
  _map.addPlayer(secondPlayer, IA);
  _player = secondPlayer;
  _run = true;
  int y = 2100;
  while (_run && _device->run())
    {
      update(secondPlayer, IA);
      // TODO: use animation
      if (y != 1000)
	{
	  _smgr->addCameraSceneNode(0, irr::core::vector3df(y,1400,0), irr::core::vector3df(0,-800,0));
	  y -= 20;
	}
      draw();
    }
  clear();
  return _menu;
}

bool	bomber::Core::isKeyPressed(bool pressedDown, irr::EKEY_CODE key, irr::SEvent const & event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == key &&
      event.KeyInput.PressedDown == pressedDown)
    return true;
  return false;
}

bool	bomber::Core::OnEvent(irr::SEvent const & e)
{
  if (e.EventType == irr::EET_KEY_INPUT_EVENT)
    {
      irr::u32	time = _device->getTimer()->getTime();
      if (!_pause)
	{
	  switch (e.KeyInput.Key)
	    {
	    case irr::KEY_KEY_Z: // Move forward
	      if (e.KeyInput.PressedDown == true)
		_map.movePlayer(0, D_UP);
	      break;
	    case irr::KEY_KEY_Q:
	      if (e.KeyInput.PressedDown == true)
		_map.movePlayer(0, D_LEFT);
	      break;
	    case irr::KEY_KEY_S: // Move backward
	      if (e.KeyInput.PressedDown == true)
		_map.movePlayer(0, D_DOWN);
	      break;
	    case irr::KEY_KEY_D:
	      if (e.KeyInput.PressedDown == true)
		_map.movePlayer(0, D_RIGHT);
	      break;
	    case irr::KEY_KEY_C:
	      if (e.KeyInput.PressedDown == false)
		_map.actionBomb(0);
	      break;
	    case irr::KEY_KEY_O: // Move forward
	      if (e.KeyInput.PressedDown == true && _player == true)
		_map.movePlayer(1, D_UP);
	      break;
	    case irr::KEY_KEY_K:
	      if (e.KeyInput.PressedDown == true && _player == true)
		_map.movePlayer(1, D_LEFT);
	      break;
	    case irr::KEY_KEY_L: // Move backward
	      if (e.KeyInput.PressedDown == true && _player == true)
		_map.movePlayer(1, D_DOWN);
	      break;
	    case irr::KEY_KEY_M:
	      if (e.KeyInput.PressedDown == true && _player == true)
		_map.movePlayer(1, D_RIGHT);
	      break;
	    case irr::KEY_KEY_N:
	      if (e.KeyInput.PressedDown == false && _player == true)
		_map.actionBomb(1);
	      break;
	    }
	}
      	  switch (e.KeyInput.Key)
	    {
	    case irr::KEY_SPACE:
	      if (e.KeyInput.PressedDown == false)
		{
		  _pause = !_pause;
		  _map.setPause(_pause);
		  if (_pause)
		    {
		      irr::gui::IGUIImage	*img = _smgr->getGUIEnvironment()->addImage(irr::core::rect<irr::s32>(0,0,1600,900));
		      img->setImage(_driver->getTexture("assets/texture/pause_screen.png"));
		      img->setScaleImage(true);
		    }
		}
	      break;
	    case irr::KEY_ESCAPE: // Return to menu
	      _run = false;
	      _menu = true;
	      break;
	    }

    }
  return false;
}
