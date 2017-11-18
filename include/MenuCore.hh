#ifndef MENUCORE_H_
# define MENUCORE_H_

# include <string>
# include <vector>

# include "bomber.hh"

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
      bool		run(std::string &, bool &);
      void		update();
      void		Creat_Menu();
      void		draw();

      void		chooseMenu(bomber::e_menu menu);

    private:
      irr::IrrlichtDevice	*_device;
      irr::video::IVideoDriver	*_driver;
      irr::scene::ISceneManager	*_smgr;
      irr::gui::IGUIEnvironment	*_guienv;
      std::vector<t_menuNode>	_nMenu;

      bool			_start;
      bool			_secondPlayer;  };
}

#endif // MENUCORE_H_
