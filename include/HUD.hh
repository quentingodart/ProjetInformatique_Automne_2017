//
// HUD.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sat Nov 18 05:22:58 2017 Anaïs Foncel
// Last update Sat Nov 18 06:12:31 2017 Anaïs Foncel
//

#ifndef HUD_HH__
# define HUD_HH__

using namespace irr;

class		HUD
{
private:
  IrrlichtDevice		*_device;
  video::IVideoDriver		*_driver;

  std::vector<Player>		_players;

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
