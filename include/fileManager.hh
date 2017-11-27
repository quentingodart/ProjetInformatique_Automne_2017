#ifndef FILEMANAGER_HH_
# define FILEMANAGER_HH_

# include <iostream>
# include <fstream>
# include <vector>

class fileManager
{
public:
  fileManager();
  ~fileManager();

public:
  static bool				openOk(std::string const &);
  std::string				openFile(std::string const &);
  static std::vector<std::string>	openFileToVector(std::string const &);
};

#endif /*!FILEMANAGER_HH_*/
