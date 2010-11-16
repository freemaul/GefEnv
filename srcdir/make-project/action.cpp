#include "action.hpp"
using namespace std;


Action::Action(Configuration& config) throw(std::string)
{
	if(config.input != "")
		config.ReadFromFile(config.input);


}
