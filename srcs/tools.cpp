//
// tools.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 11:36:37 2017 Anaïs Foncel
// Last update Mon Nov 27 01:11:19 2017 Anaïs Foncel
//

# include "bomber.hh"

namespace	bomber
{

  v2d		getMovVector(bomber::e_direction dir)
  {
    switch (dir)
      {
      case D_UP:
	return (bomber::v2d(-1, 0));
      case D_DOWN:
	return (bomber::v2d(1, 0));
      case D_LEFT:
	return (bomber::v2d(0, -1));
      case D_RIGHT:
	return (bomber::v2d(0, 1));
      }
  }

  irr::u32      getRotValue(bomber::e_direction dir)
  {
    switch (dir)
      {
      case D_UP:
	return ROT_FRONT;
      case D_DOWN:
	return ROT_BACK;
      case D_LEFT:
	return ROT_LEFT;
      case D_RIGHT:
	return ROT_RIGHT;
      }
  }

}
