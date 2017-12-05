
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void		printMap(char **map)
{
  for (int i = 0; i < 19; i++){
    cout << map[i];
  }
}

char**		initMap()
{
  char	**map = 0;
  int	i = 4;
  int	j = 0;

  map = new char*[19];
  while (j < 19) {
    map[j] = new char[21];
    j++;
  }
  strcpy(map[0], "iiiiiiiiiiiiiiiiiii\n");
  strcpy(map[1], "i xx           xx i\n");
  strcpy(map[2], "i ixi i i i i ixi i\n");
  strcpy(map[3], "i  x           x  i\n");
  strcpy(map[15], "i  x           x  i\n");
  strcpy(map[16], "i ixi i i i i ixi i\n");
  strcpy(map[17], "i xx           xx i\n");
  strcpy(map[18], "iiiiiiiiiiiiiiiiiii\n");
  while (i < 15) {
    if (i % 2 == 0) {
      strcpy(map[i], "i i i i i i i i i i\n");
    }
    else
      strcpy(map[i], "i                 i\n");
    i++;
  }
  return map;
}

char		randomChar()
{
  double val = (double)rand() / RAND_MAX;

  char random;
  if (val < 0.60)  //  60%
    random = 'c';
  else  //  40%
    random = ' ';
  return random;
}

char**		deleteCharFromMap(char **map)
{
  int		i = 1;
  int		j = 1;

  while (i < 18) {
    while (j < 18) {
      if (map[i][j] == 'x') {
	map[i][j] = ' ';
      }
      j++;
    }
    j = 1;
    i++;
  }
  return map;
}

char**		randomMap(char **map)
{
  int		i = 1;
  int		j = 1;

  while (i < 18) {
    while (j < 18) {
      if (map[i][j] != 'x' && map[i][j] != 'i') {
	map[i][j] = randomChar();
      }
      j++;
    }
    j = 1;
    i++;
  }
  map = deleteCharFromMap(map);
  return map;
}

void		openFile(std::string mapname, char **map)
{
  ofstream	newMap(mapname.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
  int		i = 0;

  newMap << "19-19\n";
  while (i < 19) {
    newMap << map[i];
    i++;
  }
  newMap.close();
}

void		freeMap(char **map)
{
  int	i = 0;

  while (i < 19) {
    delete map[i];
    i++;
  }
  delete [] map;
}

int		main(int ac, char const *av[])
{
  std::string	mapname;
  char		**map;
  
  if (ac == 2)
    {
      srand(time(NULL));
      mapname = av[1];
      map = initMap();
      map = randomMap(map);
      openFile(mapname, map);
      //freeMap(map);
      return 0;
    }
  else
    {
      cout << "USAGE : ./mapgenerator [MAPNAME]" << endl;
      return 1;
    }
}
