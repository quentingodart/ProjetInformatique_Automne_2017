#include "IA.hh"

bomber::IA::IA(bomber::v2d const &pos, bomber::Map const *map, bool secondP, int idIA, std::string name) : Player(pos, map, secondP, idIA, name)
{
  std::cout << "Constructeur IA OK" << std::endl;
}

bomber::IA::~IA()
{
  std::cout << "Destructeur IA OK" << std::endl;
}
