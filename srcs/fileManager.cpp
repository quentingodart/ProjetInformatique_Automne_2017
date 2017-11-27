
#include "fileManager.hh"

fileManager::fileManager()
{
}

fileManager::~fileManager()
{
}
bool		fileManager::openOk(std::string const & file)
{
  std::ifstream sfile(file, std::ifstream::binary);

  if (!sfile)
    {
      sfile.close();
      return false;
    }
  sfile.close();
  return true;
}

std::string	fileManager::openFile(std::string const & filename)
{
  std::string	line;
  std::string	str;
  std::ifstream	file(filename);

  if (file)
    {
      while (getline(file, line))
	str = str + line + '\n';
      file.close();
    }
  return (str);
}

std::vector<std::string> fileManager::openFileToVector(std::string const & name)
{
  std::string	line;
  std::vector<std::string> vfile;
  std::ifstream	file(name);

  if (file)
    {
      while (getline(file, line))
	vfile.push_back(line);
      file.close();
    }
  return (vfile);
}
