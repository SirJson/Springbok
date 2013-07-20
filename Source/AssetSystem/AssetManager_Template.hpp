// Copyright (C) 2013 Manuel Riecke <m.riecke@mrbeast.org>
//
// TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
// 0. You just DO WHAT THE FUCK YOU WANT TO.

#pragma once

#include "AssetManager.h"

template<typename T>
T*& AssetList<T>::operator[](const std::string& key)
{
	T*& value = mMap[key];
	if(value == nullptr)
	{	
		std::string path = mParent->getPath(key);
		value = new T(path);
	}
	return value;
}