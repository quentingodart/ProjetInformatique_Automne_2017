#ifndef GUIBONUS_HH__
# define GUIBONUS_HH__

# include <irrlicht.h>
# include <iostream>
# include <string>

using namespace irr;

class           GUIBonus
{
private:
  video::ITexture       *_img;
  video::IVideoDriver   *_driver;
  float                 _posX;
  float                 _posY;

public:
  GUIBonus(video::IVideoDriver * const driver);
  ~GUIBonus();

  void                  setImage(std::string const &name_image_file);
  video::ITexture       *getImage() const;
  void                  displayImage(int const &posX, int const &posY, int const &size) const;
};

#endif /* !GUIBONUS_HH__ */
