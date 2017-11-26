//
// HUD.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sat Nov 18 05:22:58 2017 Anaïs Foncel
// Last update Sun Nov 26 18:21:02 2017 Anaïs Foncel
//

#ifndef HUD_HH__
# define HUD_HH__

# include <irrlicht.h>
# include <vector>
# include "Player.hh"

using namespace irr;

class		HUD
{
private:
  IrrlichtDevice		*_device;
  video::IVideoDriver		*_driver;

  std::vector<Bomber::Player>		_players;

  int				_size_windowX;
  int				_size_windowY;
  int				_size_HUD_X;
  int				_size_HUD_Y;

public:
  HUD();
  ~HUD();

  void				display() const;
};

#endif /* HUD_HH__ */
