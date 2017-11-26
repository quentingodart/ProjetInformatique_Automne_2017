#ifndef CORE_HH_
# define CORE_HH_

# include <string>

# include "bomber.hh"
# include "map.hh"
# include "fileManager.hh"

namespace	bomber
{
  class	Core : public irr::IEventReceiver
    {
      public:
      Core();
      ~Core();
      virtual bool	OnEvent(irr::SEvent const & event);

      void		init();
      void		clear();
      bool		run(std::string const &, bool = false);
      void		update();
      void		draw();

      bool		isKeyPressed(bool, irr::EKEY_CODE, irr::SEvent const &);

      private:
      irr::IrrlichtDevice	*_device;
      irr::video::IVideoDriver	*_driver;
      irr::scene::ISceneManager	*_smgr;

      bool			_run;
      bool			_menu;

      Map			_map;
//      Config                    _config;

      public:
/*      irr::IrrlichtDevice	*getDevice() const;
      irr::video::IVideoDriver	*getDriver() const;
      irr::scene::ISceneManager	*getSmgr() const;
*/    };
}

#endif
