/*********************************************************************
Matt Marchant 2013 - 2015
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
#include "../../../isEngine/system/display/GameDisplay.h"
#include "../../../isEngine/ext_lib/TMXLoader/tmx/MapLoader.hpp"

class DrawMapWithDebug : public is::MainObject
{
public:
	bool showDebug = false;

    //create map loader and load map
    tmx::MapLoader ml = tmx::MapLoader(is::GameConfig::TMX_RSC_DIR);

    DrawMapWithDebug(is::GameDisplay *scene) :
        MainObject(),
        m_scene(scene)
    {
        //sf::RenderWindow renderWindow(sf::VideoMode(800u, 600u), "TMX Loader");
        m_scene->getRenderWindow().setVerticalSyncEnabled(true);
        ml.load("desert.tmx");

        //update the quad tree once so we can see it whe drawing debug
        ml.updateQuadTree(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
    }

    void event(sf::Event &event)
    {
        if(event.type == sf::Event::KeyReleased)
        {
            switch(event.key.code)
            {
            case sf::Keyboard::D:
                showDebug = !showDebug;
                break;
            default: break;
            }
        }
    }

	void step(float const &DELTA_TIME)
	{
		//move objects about
		std::vector<tmx::MapLayer>& layers = ml.getLayers();
		for(auto& l : layers)
		{
			if(l.type == tmx::ObjectGroup)
			{
				for(auto& o : l.objects)
				{
					o.move(0.f, 60.f * DELTA_TIME);
					if(o.getPosition().y > 600.f)
					{
						o.setPosition(o.getPosition().x, 0.f);
					}
				}
			}
		}
		ml.updateQuadTree(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
	}

	void draw(sf::RenderTexture &surface)
	{
		//draw
		surface.draw(ml);
		if(showDebug) ml.drawLayer(surface, tmx::MapLayer::Debug);//draw with debug information shown
		m_scene->setWindowTitle("Press D to Toggle debug shapes. " + std::to_string(1.f / m_scene->getDeltaTime()));
	}

private:
    is::GameDisplay *m_scene;
};
