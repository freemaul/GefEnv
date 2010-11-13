#include "configuration.hpp"
#include <iostream>
using namespace std;


Configuration::Configuration(int argc,char *argv[])
{
	project_dir = "";

	for(int i=0;i<argc;i++)
	{
		cout << argv[i] << endl;
	}
}

