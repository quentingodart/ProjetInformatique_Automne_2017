//
// HUD.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sat Nov 18 05:30:17 2017 Anaïs Foncel
// Last update Mon Nov 27 02:24:40 2017 Anaïs Foncel
//

#include "HUD.hh"

HUD::HUD(video::IVideoDriver * const driver, IrrlichtDevice * const device, std::vector<int> const &size)
{
  _driver = driver;
  _device = device;
  _size_windowX = size[0];
  _size_windowY = size[1];
  _size_HUD_Y = _size_windowY / 4;
  _size_HUD_X = _size_windowX;
  _size_HUD_Y_player = _size_windowY / 4;
  
}

HUD::~HUD()
{

}

void	HUD::displayBonusBomb(bomber::Player const &player, int i)
{
  gui::IGUIFont *font;
  std::string   inter;
  core::stringw res;

  int           posX_Image;
  int           posY_Image;

  int           posX;
  int           posY;
  int           num;

  posY_Image = i * _size_HUD_Y_player;
  posX_Image = _size_HUD_X / 2;


  posY = i * _size_HUD_Y_player + SIZE_IMAGE;
  posX = _size_HUD_X / 2;

  num = player.getBombs();
  inter = std::to_string(num);
  res = core::stringw(inter.c_str());
  _bonus->setImage("assets/img_bonus_bomb.png");
  _bonus->displayImage(posX_Image, posY_Image, SIZE_IMAGE);

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
    font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void	HUD::displayBonusRange(bomber::Player const &player, int i)
{
  gui::IGUIFont *font;
  std::string   inter;
  core::stringw res;

  int           posX_Image;
  int           posY_Image;

  int           posX;
  int           posY;
  int           num;

  posY_Image = i * _size_HUD_Y_player + _size_HUD_Y_player / 3;
  posX_Image = _size_HUD_X / 2;


  posY = i * _size_HUD_Y_player + (_size_HUD_Y_player / 3) + SIZE_IMAGE;
  posX = _size_HUD_X / 2;

  num = player.getRange();
  inter = std::to_string(num);
  res = core::stringw(inter.c_str());
  _bonus->setImage("assets/img_bonus_range.png");
  _bonus->displayImage(posX_Image, posY_Image, SIZE_IMAGE);

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
    font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void	HUD::displayBonusSpeed(bomber::Player const &player, int i)
{
  gui::IGUIFont *font;
  std::string   inter;
  core::stringw res;

  int           posX_Image;
  int           posY_Image;

  int           posX;
  int           posY;
  int           num;

  posY_Image = i * _size_HUD_Y_player + (_size_HUD_Y_player / 3) * 2;
  posX_Image = _size_HUD_X / 2;


  posY = i * _size_HUD_Y_player + ((_size_HUD_Y_player / 3) * 2) + SIZE_IMAGE;
  posX = _size_HUD_X / 2;

  num = player.getSpeed();
  inter = std::to_string(num);
  res = core::stringw(inter.c_str());
  _bonus->setImage("assets/img_bonus_speed.png");
  _bonus->displayImage(posX_Image, posY_Image, SIZE_IMAGE);

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
    font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void	HUD::displayBonus(bomber::Player const &player, int i)
{
  displayBonusBomb(player, i);
  displayBonusRange(player, i);
  displayBonusSpeed(player, i);
}

void	HUD::displayName(bomber::Player const &player, int i)
{
  gui::IGUIFont *font;
  core::stringw res;
  int           posX;
  int           posY;
  std::string   name;

  name = player.getName();
  res = core::stringw(name.c_str());

  posX = i * _size_HUD_X;
  posY = 0;

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
    font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void	HUD::display()
{
  for (unsigned int i = 0; i < _players.size(); ++i)
    {
      displayName(_players[i], i);
      displayBonus(_players[i], i);
    }
}
