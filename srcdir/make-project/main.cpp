#include <cstdlib>
#include <iostream>

#include "configuration.hpp"
#include "action.hpp"

int main(int argc,char* argv[])
{
	try{
		Configuration config(argc,argv);
		Action action(config);
	}

	catch(std::string message)
	{
		std::cout << message;
		return -1;
	}


	return 0;
}
