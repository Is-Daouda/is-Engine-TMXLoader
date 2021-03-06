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

class IsometricWithConvertCoords : public is::MainObject
{
public:
	//to toggle debug output
	bool debug = false;

    //create map loader and load map
    tmx::MapLoader ml = tmx::MapLoader(is::GameConfig::TMX_RSC_DIR);

    IsometricWithConvertCoords(is::GameDisplay *scene) :
        MainObject(),
        m_scene(scene)
    {
        //sf::RenderWindow renderWindow(sf::VideoMode(800u, 600u), "TMX Loader");
        m_scene->getRenderWindow().setVerticalSyncEnabled(true);

        ml.load("isometric_grass_and_water.tmx");

        //adjust the view to centre on map
        m_scene->setView(0.f, 300.f);
    }

	void event(sf::Event &event)
	{
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
            debug = !debug;
	}

    void draw(sf::RenderTexture &surface)
    {
		//draw map
		surface.draw(ml);
		if(debug)ml.drawLayer(surface, tmx::MapLayer::Debug);

		//print mouse coords to orthographic (screen) coords and world (isometric) coords
		sf::Vector2f mousePosScreen = m_scene->getRenderWindow().mapPixelToCoords(sf::Mouse::getPosition(m_scene->getRenderWindow()));
		sf::Vector2f mousePosWorld = ml.orthogonalToIsometric(mousePosScreen);

		std::stringstream stream;
		stream << "Mouse Position: "<< mousePosScreen.x << ", " << mousePosScreen.y << " World Position: " << mousePosWorld.x << ", " << mousePosWorld.y;

		m_scene->setWindowTitle(stream.str());
	}

private:
    is::GameDisplay *m_scene;
};
