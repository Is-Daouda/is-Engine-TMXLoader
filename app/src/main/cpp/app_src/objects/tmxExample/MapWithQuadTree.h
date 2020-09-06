/*********************************************************************
Matt Marchant 2013 - 2016
SFML Tiled Map Loader - https://github.com/bjorn/tiled/wiki/TMX-Map-Format
						http://trederia.blogspot.com/2013/05/tiled-map-loader-for-sfml.html

The zlib license has been used to make this software fully compatible
with SFML. See http://www.sfml-dev.org/license.php

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.

2. Altered source versions must be plainly marked as such,
   and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
   source distribution.
*********************************************************************/

#pragma once
#include <sstream>

#include "../../../isEngine/system/display/GameDisplay.h"
#include "../../../isEngine/ext_lib/TMXLoader/tmx/MapLoader.hpp"

class MapWithQuadTree : public is::MainObject
{
public:
    //create map loader and load map
    tmx::MapLoader ml = tmx::MapLoader(is::GameConfig::TMX_RSC_DIR);

    MapWithQuadTree(is::GameDisplay *scene) :
        MainObject(),
        m_scene(scene)
    {
        //sf::RenderWindow renderWindow(sf::VideoMode(800u, 600u), "TMX Loader");
        ml.load("desert.tmx");
    }

	void step(float const &DELTA_TIME)
	{
		//build quad tree by querying visible region
		ml.updateQuadTree(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
		//get a vector of MapObjects contained in the quads intersected by query area
		sf::Vector2f mousePos = m_scene->getRenderWindow().mapPixelToCoords(sf::Mouse::getPosition(m_scene->getRenderWindow()));
		//NOTE quad tree MUST be updated before attempting to query it
		std::vector<tmx::MapObject*> objects = ml.queryQuadTree(sf::FloatRect(mousePos.x - 10.f, mousePos.y - 10.f, 20.f, 20.f));

		//do stuff with returned objects
		std::stringstream stream;
		stream << "Query object count: " << objects.size();
		m_scene->setWindowTitle(stream.str());
	}

    void draw(sf::RenderTexture &surface)
    {
		//draw
		surface.draw(ml);
		ml.drawLayer(surface, tmx::MapLayer::Debug); //draw with debug information shown
	}

private:
    is::GameDisplay *m_scene;
};
