//  Copyright (C) 2014 Manuel Riecke <spell1337@gmail.com>
//  Licensed under the terms of the WTFPL.
//
//  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//  0. You just DO WHAT THE FUCK YOU WANT TO.

#pragma once

#include <string>
#include <Springbok/Containers/List.h>

class CliArgumentParser
{
public:
	struct SwitchDefinition
	{
		List<std::string> Names;
		int AcceptedParameters = 0;
		bool ParametersOptional = true;
		
		bool IsSet = false;
		List<std::string> Parameters;
		
		explicit operator bool(){ return IsSet; };
		std::string operator[](int index) const{ return Parameters[index]; };
		int length() const { return Parameters.UsedLength; };
	};
	using string = const std::string&;
public:
	void addSwitch(string name, string alias, int parameter = 0, bool optionalParameters=false);
	void addSwitch(string name, int parameter = 0, bool optionalParameters=false);
	void addAlias(string name, string alias);
	void addAlias(string name, string alias, string alias2);
	
	std::string getSyntax();
	
	void parse(int argc, char** argv);
	void parse(const List<std::string>& arguments);
	SwitchDefinition& operator[](string name);
public:	
	List<SwitchDefinition> Switches;
	List<std::string> LooseArguments;
protected:
	SwitchDefinition* find(string name);
};