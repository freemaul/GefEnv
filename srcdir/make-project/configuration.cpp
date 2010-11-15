#include "configuration.hpp"
#include <iostream>
using namespace std;

#define NAME_BIN "GEF-make-project"

Configuration::Configuration(int argc,char *argv[]) throw(std::string)
{
	string arg=argv[0];
	string message;

	project_dir = "";
	name = "";
	dir = "";
	help = false;
	major = false;

	if(arg != NAME_BIN){
		message += "Error ! name of program is not correct\n";
		message += arg;
		message += " sould be ";
		message += NAME_BIN;
		message += "\n";
		throw(message);
	}

	for(int i=1;i<argc;i++)
	{
		arg = argv[i];
		cout << argv[i] << endl;
		if(arg == "help"){
			if(major == true){
				message += "Error, you could not use '";
				message += arg;
				message += "' here !\n";
				throw(message);
			}else{
				major = true;
				help = true;
			}
		}else if(arg == "--name"){
			i++;
			if(i>=argc){
				message += "option --name what for a name\n";
				throw(message);
			}
			name = argv[i];
		}else if(arg == "--dir"){
			i++;
			if(i>=argc){
				message += "option --dir what for a name directory\n";
				throw(message);
			}
			dir = argv[i];
		}else{
			message += "unknow ";
			message += arg;
			message += "\n";
			throw(message);
		}
	}
}

