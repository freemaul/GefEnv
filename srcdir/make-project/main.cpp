#include <cstdlib>
#include <iostream>

#include "configuration.hpp"

int main(int argc,char* argv[])
{
	try{
		Configuration config(argc,argv);
	}
	catch(std::string message)
	{
		std::cout << message;
		return -1;
	}


	return 0;
}
