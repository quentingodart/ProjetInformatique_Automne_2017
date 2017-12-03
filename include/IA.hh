#ifndef IA_HH_
# define IA_HH_

#include "Player.hh"

namespace	bomber
{
  class		IA : public bomber::Player
  {
  protected :
    int			_idIA;
    bomber::Map		*_map;
  public:
    IA(bomber::v2d const &pos, bomber::Map *map, bool secondP, int idIA, std::string name);
    ~IA();
    void		play();
    void		moveUp();
    void		moveDown();
    void		moveRight();
    void		moveLeft();
    void		putBomb();
  };
}

#endif /* IA_HH_ */
