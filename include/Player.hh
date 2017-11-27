//
// Player.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 07:52:20 2017 Anaïs Foncel
// Last update Mon Nov 27 01:26:37 2017 Anaïs Foncel
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include "bomber.hh"
# include "map.hh"

namespace	bomber
{
  class		Player
  {
  protected:
    int			_bombs;
    int			_bombsUse;
    int			_range;
    irr::u32		_speed;

    bomber::v2d		_pos;

    irr::scene::IAnimatedMeshSceneNode	*_node;

  public:
    Player(bomber::v2d const &pos, bomber::Map const *map, bool secondP);
    ~Player();

    void				movePlayer(bool move, bomber::e_direction dir, bomber::v2d initPos, irr::u32 time);
    void				giveBonus(e_bonus bonus);

    void				addSpeed();
    void				addRange();
    void				addBomb();

    /*
    ** Setter
    */
    void				setBombs(int nb);
    void				setBombsUse(int nb);
    void				setRange(int nb);

    /*
    ** Getter
    */
    int					getBombs() const;
    int					getBombsUse() const;
    int					getRange() const;

    int					getX() const;
    int					getY() const;
    bomber::v2d const			&getPos() const;
    irr::scene::IAnimatedMeshSceneNode	*getNode() const;
  };
}

#endif /* PLAYER_HH_ */
