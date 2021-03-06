//  Copyright (C) 2014 Manuel Riecke <spell1337@gmail.com>
//  Licensed under the terms of the WTFPL.
//
//  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//  0. You just DO WHAT THE FUCK YOU WANT TO.

#pragma once
#include <Springbok/Containers/List.h>
#include "Image.h"
#include "RenderContext.h"
#include <Springbok/Graphics/GraphicsBatch.h>

class RenderContext;

class BitmapFont
{
public:
	struct Char
	{
		char32_t Codepoint;
		Image Sprite;
	};
public:
	void loadCharacter(char32_t which, Image sprite);
	void loadRange(Image spriteSheet, char32_t start, char32_t end);
	void loadGrid(Image spriteSheet, char32_t start, Vec2I charSize);
	template<typename T>
	void draw(const std::basic_string< T >& str, const RenderContext& context, GraphicsBatch& batch) const;
public:
	Map<Char, char32_t, &Char::Codepoint> LoadedCharacters;
};

template<typename T>
void BitmapFont::draw(const std::basic_string<T>& str, const RenderContext& context, GraphicsBatch& batch) const
{
	RenderContext r(context);
	int offset = 0;
	for(const auto& c : str)
	{
		Image sprite = LoadedCharacters[c].Sprite;
		batch.draw(sprite.getTexture(),r.transformRect(sprite.getVertices(),{offset,0}));
		offset += sprite.getSize()[0];
	}	
}
