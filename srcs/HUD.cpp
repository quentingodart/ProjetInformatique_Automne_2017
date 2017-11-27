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
  _size_HUD_X = _size_windowX / 4;
  
}

HUD::~HUD()
{

}

void	HUD::display() const
{

}
