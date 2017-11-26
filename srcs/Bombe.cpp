//
// Bombe.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 11:02:03 2017 Anaïs Foncel
// Last update Sun Nov 26 18:09:34 2017 Anaïs Foncel
//

#include "Bombe.hh"

Bomber::Bombe::Bombe(Bomber::v2d const &pos, int range)
  : _x(pos.X), _y(pos.Y), _range(range)
{

}

Bomber::Bombe::~Bombe() {}


/*
** Getter
*/
int		Bomber::Bombe::getX() const { return this->_x; }

int		Bomber::Bombe::getY() const { return this->_y; }

int		Bomber::Bombe::getRange() const { return this->_range; }

Bomber::v2d	Bomber::Bombe::getPos() const { return Bomber::v2d(_x, _y); }

irr::u32	Bomber::Bombe::getTime() const { return this->_time; }

/*
** Setter
*/
void		Bomber::Bombe::setTime(irr::u32 time) { this->_time = time; }
