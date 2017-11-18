#include "MenuCore.hh"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

bomber::MenuCore::MenuCore()
: _device(0), _driver(0), _smgr(0), _guienv(0), _start(false), _secondPlayer(false)
{}
bomber::MenuCore::~MenuCore()
{
}

bool	bomber::MenuCore::run(std::string & map, bool & secondPlayer)
{
  init();
  Creat_Menu();
  map = "map";
  chooseMenu(M_MAIN);
  while(_device->run())
    {
      update();
      draw();
    }
  clear();
  secondPlayer = _secondPlayer;
  return _start;
}

void	bomber::MenuCore::clear()
{}

void	bomber::MenuCore::update()
{}

void	bomber::MenuCore::draw()
{}

void	bomber::MenuCore::init()
{}

void	bomber::MenuCore::Creat_Menu()
{}

void	bomber::MenuCore::chooseMenu(bomber::e_menu menu)
{}

