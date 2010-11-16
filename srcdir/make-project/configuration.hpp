#ifndef GEFENV_CONFIGURATION_HPP
#define GEFENV_CONFIGURATION_HPP

#include <string>

class Configuration
{
	friend class Action;
public:
	Configuration(int,char*[]) throw (const std::string);
	void ReadFromFile(const std::string) throw (const std::string);
protected:
	std::string 	project_dir;
	std::string	name;
	std::string	dir;
	std::string	output;
	std::string	input;
	bool 		help;

	bool		major; // option principale definit ?
};

#endif

