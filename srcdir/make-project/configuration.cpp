#include "configuration.hpp"
#include <iostream>
#include <fstream>
using namespace std;

#define NAME_BIN "GEF-make-project"

Configuration::Configuration(int argc,char *argv[]) throw(const std::string)
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
		}else if(arg == "--input"){
			i++;
			if(i>=argc){
				message += "option --input what for a name of a file\n";
				throw(message);
			}
			if(major == true){
				message += "Error, you could not use '";
				message += arg;
				message += "' here !\n";
				throw(message);
			}
			major = true;
			input = argv[i];
		}else if(arg == "--output"){
			i++;
			if(i>=argc){
				message += "option --output what for a name of a file\n";
				throw(message);
			}
			if(major == true){
				message += "Error, you could not use '";
				message += arg;
				message += "' here !\n";
				throw(message);
			}
			major = true;
			output = argv[i];
		}else{
			message += "unknow option '";
			message += arg;
			message += "'\n";
			throw(message);
		}
	}
}



void Configuration::ReadFromFile(const std::string file_name) throw(const std::string)
{
	ifstream myfile(file_name.c_str());
	string message;
	string line;

	if(!myfile.is_open())
	{
		message += "Error, could not open file '";
		message += file_name;
		message += "'\n";
		throw(message);
	}

	while(myfile.good())
	{
		getline(myfile,line);
		cout << line << endl;
	}


	myfile.close();
}
