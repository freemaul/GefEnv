#ifndef GEFENV_ACTION_HPP
#define GEFENV_ACTION_HPP

#include "configuration.hpp"
#include <string>

class Action
{
public:
	Action(Configuration&) throw(std::string);
};

#endif

