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
#include "../../../isEngine/system/display/GameDisplay.h"
#include "../../../isEngine/ext_lib/TMXLoader/tmx/MapLoader.hpp"
#include "../../../isEngine/ext_lib/TMXLoader/tmx/Log.hpp"

class Benchmark : public is::MainObject
{
public:
    const float dt = 0.01f;
    float accumulator = 0.f;

    sf::Font font;
    sf::Text fpsText;

    //create map loader and load map
    tmx::MapLoader ml = tmx::MapLoader(is::GameConfig::TMX_RSC_DIR);

    Benchmark(is::GameDisplay *scene) :
        MainObject(),
        m_scene(scene)
    {
        //sf::RenderWindow renderWindow(sf::VideoMode(800u, 600u), "TMX Loader");
        font = loadFont();
        fpsText = getFpsText(font);

        //set the debugging output mode
        tmx::setLogLevel(tmx::Logger::Info | tmx::Logger::Error);

        ml.load("desert.tmx");
    }

	sf::Vector2f getViewMovement(float dt)
	{
		sf::Vector2f movement;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			movement.x = -1.f;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			movement.x = 1.f;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			movement.y = -1.f;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			movement.y = 1.f;

		movement = Helpers::Vectors::normalize(movement) * 500.f * dt;
		return movement;
	}

	sf::Font loadFont()
	{
		if (!font.loadFromFile(is::GameConfig::FONT_DIR + "Ubuntu-M.ttf"))
		{
			std::cout << "font not loaded for fps count" << std::endl;
			//do nothing its just a test
		}
		return font;
	}

	sf::Text getFpsText(const sf::Font& font)
	{
		fpsText.setFont(font);
		fpsText.setColor(sf::Color::White);
		fpsText.setCharacterSize(25);
		return fpsText;
	}

    void step(float const &DELTA_TIME)
    {
        //update
        float previousUpdateTime = DELTA_TIME;
        float currentTime = DELTA_TIME;
        float frameTime = currentTime - previousUpdateTime;
        previousUpdateTime = currentTime;
        accumulator += frameTime;

        sf::Vector2f movement;
        while ( accumulator >= dt )
        {
            movement = getViewMovement(dt);
            accumulator -= dt;
        }

        //allow moving of view
        //sf::View view = m_scene->getRenderWindow().getView();
        //view.move(movement);
        //m_scene->getRenderWindow().setView(view);
        //m_scene->setView(movement);

        //show fps
        float fpsCount = (1.f / m_scene->getDeltaTime());
        fpsText.setString( "FPS: " + (std::to_string(fpsCount)));
        fpsText.move(movement);
    }

    void draw(sf::RenderTexture &surface)
    {
        //draw
        surface.draw(ml);
        surface.draw(fpsText);
    }

private:
    is::GameDisplay *m_scene;
};
