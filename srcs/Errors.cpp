//
// Errors.cpp for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs/Common
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 09:54:35 2017 Anaïs Foncel
// Last update Sun Nov 12 09:56:05 2017 Anaïs Foncel
//

#include "Errors.hh"

Errors::Exceptions::~Exceptions() throw() {}

Errors::Exceptions::Exceptions(Exceptions_Type const type, const std::string &mess)
  : std::exception()
{
  static std::string	message[max_exception] = {""};

  message[unknown] = mess;
  message[FuncFail] = mess + " failed.";

  _message = message[static_cast<int>(type)];
}

const char	*Errors::Exceptions::what() const throw ()
{
  return _message.c_str();
}
