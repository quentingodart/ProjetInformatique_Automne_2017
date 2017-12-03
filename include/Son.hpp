#ifndef SON_HPP_
# define SON_HPP_

#include <iostream>
#include "SFML/Audio.hpp"

class	My_Sound
{
private:
    sf::SoundBuffer	buffer;
    sf::Sound		sound;
    sf::Music		music;

  
public:

  My_Sound();
  ~My_Sound();

  void	Play_Sound(const std::string& filename);
  void	Stop();
};

class	My_Music
{

private:
  sf::Music	music;

public:

  My_Music();
  ~My_Music();

  void	Play_Music(const std::string& filename);

};

#endif /* !SON_HPP_ */
