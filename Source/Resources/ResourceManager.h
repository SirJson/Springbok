// Copyright (C) 2013 Manuel Riecke <m.riecke@mrbeast.org>
//
// TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
// 0. You just DO WHAT THE FUCK YOU WANT TO.

#pragma once

#include <vector>
#include <map>
#include <string>
#include "../Generic/ObjectPointer.h"

class ResourceManager;

//! @ingroup ResourceManager
class ResourceManager
{
public:
	struct Data
	{
		std::string ResolvedPath;
		std::string RequestedPath;
		ObjectPointer<void> Pointer = nullptr;
	};
//!@name Static
///@{
public:
	static ResourceManager* gInstance;
	static ResourceManager* GetInstance();
///@}
public:
	ResourceManager();
	~ResourceManager();
	template<typename T>
	ObjectPointer<T> getResource(const std::string& path, bool reload=false);
	std::string getPath(const std::string& path);
	std::string findPrimaryResourcePath(const std::vector<std::string>& paths);
	void addModPath(const std::string& path);
private:
	std::map<std::string, Data> Resources;
	std::string PrimaryResourcePath;
	std::string UserSettingsPath;
	std::vector<std::string> ModPaths;
};

#include "ResourceManager_Templates.hpp"