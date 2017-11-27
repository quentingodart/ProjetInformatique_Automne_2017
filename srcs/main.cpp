
#include "Core.hh"
#include "MenuCore.hh"

int	main(int ac, char const *av[])
{
  bomber::MenuCore	menu;
  std::string		map;
  bool			secondPlayer(false);

  while ((menu.run(map, secondPlayer)))
    {
      bomber::Core	core;
      if (!core.run(map, secondPlayer))
	  break;
    }
  return 0;
}
