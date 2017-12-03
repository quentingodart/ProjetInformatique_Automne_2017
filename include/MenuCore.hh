#ifndef MENUCORE_H_
# define MENUCORE_H_

# include <string>
# include <vector>
# include <iostream>

# include "bomber.hh"
# include "Son.hpp"


namespace	bomber
{
  enum e_menu
    {
      M_MAIN,
      M_PLAY,
      M_OPTION,
      M_CREDIT
    };
  typedef struct	s_menuNode
    {
      irr::gui::IGUIElement	*btn;
      e_menu			type;
    }			t_menuNode;

  class	MenuCore : public irr::IEventReceiver
    {
    public:
      MenuCore();
      virtual ~MenuCore();

      void		init();
      void		clear();
      bool		run(std::string &, bool &, bool &);
      void		update();
      void		Creat_Menu();
      void		draw();

      void		chooseMenu(bomber::e_menu menu);
      bool		isKeyPressed(irr::EKEY_CODE, irr::SEvent const &);
      virtual bool	OnEvent(irr::SEvent const &);
      
      My_Sound			son;

    private:
      irr::IrrlichtDevice	*_device;
      irr::video::IVideoDriver	*_driver;
      irr::scene::ISceneManager	*_smgr;
      irr::gui::IGUIEnvironment	*_guienv;
      std::vector<t_menuNode>	_nMenu;

      bool			_start;
      bool			_IA;
      bool			_secondPlayer;
      bool			_sound_count; };
}

#endif // MENUCORE_H_
