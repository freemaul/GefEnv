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
		}else if(arg[0]=='-' and arg[1]=='-'){
			i++;
			if(i>=argc){
				message += "option '";
				message += arg;
				message += "' wait for a argument\n";
				throw(message);
			}
			std::string commande = arg;
			std::string argument = argv[i];
			Commande(commande,argument);
		}else{
			message += "unknow option '";
			message += arg;
			message += "'\n";
			throw(message);
		}
	}
}

void Configuration::Commande(std::string commande,std::string argument) throw (const std::string)
{
	std::string message;

	if(commande == "--name"){
		name = argument;
	}else if(commande == "--dir"){
		dir = argument;
	}else if(commande == "--input"){
		if(major == true){
			message += "Error, you could not use '";
			message += commande;
			message += "' here !\n";
			throw(message);
		}
		major = true;
		input = argument;
	}else if(commande == "--output"){
		if(major == true){
			message += "Error, you could not use '";
			message += commande;
			message += "' here !\n";
			throw(message);
		}
		major = true;
		output = argument;
	}else{
		message += "Error unknow option '";
		message += commande;
		message += "'\n";
		throw(message);
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
		cout << "#" << line << "#" << endl;
		int pos_eg = line.find('=');
		if(pos_eg == string::npos)
		{
			message += "Do not understand line '";
			message += line;
			message += "' in file '";
			message += file_name;
			message += "'\n";
			throw(message);
		}
		std::string commande="--";
		for(int i=0;i<pos_eg;i++)
			commande+=line[i];

		std::string argument;

		Commande(commande,argument);
	}


	myfile.close();
}
