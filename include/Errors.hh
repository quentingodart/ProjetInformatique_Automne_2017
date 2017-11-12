//
// Errors.hh for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017/srcs/Common
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Sun Nov 12 09:56:40 2017 Anaïs Foncel
// Last update Sun Nov 12 09:57:38 2017 Anaïs Foncel
//

#ifndef ERRORS_HH__
# define ERRORS_HH__

# include "string"

namespace		Errors
{
  class Exceptions : public std::exception
  {
  private:
    std::string	_message;

  public:
    enum	Exceptions_Type
      {
        unknown = 0,
        FuncFail,
        max_exception
      };

    ~Exceptions() throw();
    explicit		Exceptions(Exceptions_Type const type, const std::string &mess = "");
    virtual const char	*what() const throw();
  };
};

#endif /* !ERRORS_HH__ */
