//
// HUD.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sat Nov 18 05:22:58 2017 Anaïs Foncel
// Last update Mon Nov 27 01:27:05 2017 Anaïs Foncel
//

#ifndef HUD_HH__
# define HUD_HH__

# include <irrlicht.h>
# include <vector>
# include "Player.hh"
# include "GUIBonus.hh"

# define SIZE_IMAGE	(40)

using namespace irr;

class		HUD
{
private:
  IrrlichtDevice		*_device;
  video::IVideoDriver		*_driver;

  std::vector<bomber::Player>	_players;
  GUIBonus			*_bonus;

  int				_size_windowX;
  int				_size_windowY;
  int				_size_HUD_X;
  int				_size_HUD_Y;
  int				_size_HUD_Y_player;

public:
  HUD(video::IVideoDriver * const driver, IrrlichtDevice * const device, std::vector<int> const &size);
  ~HUD();

  void				display();
  void				displayName(bomber::Player const &player, int i);
  void				displayBonus(bomber::Player const &player, int i);
  void				displayBonusBomb(bomber::Player const &player, int i);
  void				displayBonusRange(bomber::Player const &player, int i);
  void				displayBonusSpeed(bomber::Player const &player, int i);
};

#endif /* HUD_HH__ */
