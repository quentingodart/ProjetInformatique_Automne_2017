
#include "Core.hh"
#include "MenuCore.hh"

int	main(int ac, char const *av[])
{
  bomber::MenuCore	menu;
  std::string		map;
  bool			secondPlayer(false);
  bool			IA(false);

  while ((menu.run(map, secondPlayer, IA)))
    {
      bomber::Core	core;
      if (!core.run(map, secondPlayer, IA))
	  break;
    }
  return 0;
}
