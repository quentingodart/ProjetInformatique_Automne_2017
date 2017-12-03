#ifndef IA_HH_
# define IA_HH_

#include "Player.hh"

namespace	bomber
{
  class		IA : public bomber::Player
  {
  public:
    IA(bomber::v2d const &pos, bomber::Map const *map, bool secondP, int idIA, std::string name);
    ~IA();
  };
}

#endif /* IA_HH_ */
