#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

class Configuration
{
public:
	Configuration(int,char*[]) throw (std::string);
private:
	std::string 	project_dir;
	std::string	name;
	std::string	dir;
	bool 		help;

	bool		major; // option principale definit ?
};

#endif

