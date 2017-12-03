#include "Son.hpp"
#include <unistd.h>

int	main()
{
  My_Sound 	son;

  son.Play_Sound("sono/fire.wav");
  sleep(10);
}
