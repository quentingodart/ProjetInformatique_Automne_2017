
#include "Core.hh"
#include "MenuCore.hh"
#include <stdlib.h>
#include <time.h>

int	main(int ac, char const *av[])
{
  bomber::MenuCore	menu;
  std::string		map;
  bool			secondPlayer(false);
  bool			IA(false);

  srand(time(NULL));
  if (ac == 2)
    map = av[1];
  while ((menu.run(map, secondPlayer, IA)))
    {
      bomber::Core	core;
      if (!core.run(map, secondPlayer, IA))
	  break;
    }
  return 0;
}
