//
// Bombe.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 11:02:03 2017 Anaïs Foncel
// Last update Mon Nov 27 01:08:53 2017 Anaïs Foncel
//

#include "Bombe.hh"

bomber::Bombe::Bombe(bomber::v2d const &pos, int range)
  : _x(pos.X), _y(pos.Y), _range(range)
{

}

bomber::Bombe::~Bombe() {}


/*
** Getter
*/
int		bomber::Bombe::getX() const { return this->_x; }

int		bomber::Bombe::getY() const { return this->_y; }

int		bomber::Bombe::getRange() const { return this->_range; }

bomber::v2d	bomber::Bombe::getPos() const { return bomber::v2d(_x, _y); }

irr::u32	bomber::Bombe::getTime() const { return this->_time; }

/*
** Setter
*/
void		bomber::Bombe::setTime(irr::u32 time) { this->_time = time; }
