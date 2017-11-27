//
// Bombe.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 11:02:01 2017 Anaïs Foncel
// Last update Mon Nov 27 01:09:09 2017 Anaïs Foncel
//

#ifndef BOMBE_HH_
# define BOMBE_HH_

# include <irrlicht.h>
# include "bomber.hh"

namespace		bomber
{
  class		Bombe
  {
  public:
    Bombe(bomber::v2d const &pos, int range);
    ~Bombe();

    /*
    ** Getter
    */
    int		getX() const;
    int		getY() const;
    int		getRange() const;
    bomber::v2d	getPos() const;
    irr::u32	getTime() const;

    /*
    ** Setter
    */
    void	setTime(irr::u32 time);

  private:
    int		_x;
    int		_y;
    int		_range;
    irr::u32	_time;
  };
}

#endif /* BOMBE_HH_ */
