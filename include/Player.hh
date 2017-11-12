//
// Player.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 07:52:20 2017 Anaïs Foncel
// Last update Sun Nov 12 09:23:37 2017 Anaïs Foncel
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include "bomber.hh"

namespace	Bomber
{
  class		Player
  {
  protected:
    int			_bombs;
    int			_bombsUse;
    int			_range;
    irr::u32		_speed;

    Bomber::v2d		_pos;

  public:
    Player(Bomber::v2d const &pos);
    ~Player();

    void		movePlayer();
    void		takeBonus(e_bonus bonus);

    void		addSpeed();
    void		addRange();
    void		addBomb();

    /*
    ** Setter
    */
    void		setBombs(int nb);
    void		setBombsUse(int nb);
    void		setRange(int nb);

    /*
    ** Getter
    */
    int			getBombs() const;
    int			getBombsUse() const;
    int			getRange() const;

    int			getX() const;
    int			getY() const;
    Bomber::v2d const	&getPos() const;
  };
}

#endif /* PLAYER_HH_ */
