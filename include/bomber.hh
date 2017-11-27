//
// bomber.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 09:18:14 2017 Anaïs Foncel
// Last update Mon Nov 27 01:10:35 2017 Anaïs Foncel
//

#ifndef BOMBER_HH_
# define BOMBER_HH_

# include <irrlicht.h>

# define MOV_SPD 250
# define BOMB_TIME 3000
# define EXP_TIME 500

# define BONUS_LUCK 7 // NOTE: Has to be higher than number of bonuses

# define MAX_BOMB 4
# define MAX_RANGE 5
# define MAX_SPEED 5

namespace       bomber
{
  typedef irr::core::position2di      v2d;

    enum        e_rotation
      {
        ROT_FRONT = 270,
        ROT_RIGHT = 0,
        ROT_BACK = 90,
        ROT_LEFT = 180
      };

    enum        e_bonus
      {
        B_SPEED,
        B_RANGE,
        B_BOMB
      };

    enum        e_direction
      {
        D_UP,
        D_DOWN,
        D_RIGHT,
        D_LEFT
      };

  v2d		getMovVector(bomber::e_direction dir);
  irr::u32	getRotValue(bomber::e_direction dir);
}

#endif
