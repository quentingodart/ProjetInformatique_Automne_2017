//
// Bombe.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 11:02:01 2017 Anaïs Foncel
// Last update Sun Nov 12 11:12:58 2017 Anaïs Foncel
//

#ifndef BOMBE_HH_
# define BOMBE_HH_

# include <irrlicht.h>
# include "bomber.hh"

namespace		Bomber
{
  class		Bombe
  {
  public:
    Bombe(Bomber::v2d const &pos, int range);
    ~Bombe();

    /*
    ** Getter
    */
    int		getX() const;
    int		getY() const;
    int		getRange() const;
    Bomber::v2d	getPos() const;

  private:
    int		_x;
    int		_y;
    int		_range;
  };
}

#endif /* BOMBE_HH_ */
