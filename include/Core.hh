#ifndef CORE_HH_
# define CORE_HH_

# include <string>

# include "fileManager.hh"
# include "bomber.hh"
# include "map.hh"
# include "Son.hpp"

namespace	bomber
{
  class	Core : public irr::IEventReceiver
  {
  public:
    Core();
    ~Core();

    My_Sound		son;

    virtual bool	OnEvent(irr::SEvent const & event);

    void		init();
    void		clear();
    bool		run(std::string const &, bool = false, bool = false);
    void		update(bool);
    void		draw();

    bool		isKeyPressed(bool, irr::EKEY_CODE, irr::SEvent const &);

  private:
    irr::IrrlichtDevice		*_device;
    irr::video::IVideoDriver	*_driver;
    irr::scene::ISceneManager	*_smgr;

    bool			_pause;
    bool			_run;
    bool			_menu;
    bool			_player;
    irr::u32			_deadTime;
    
    Map			_map;

  public:
  };
}

#endif
