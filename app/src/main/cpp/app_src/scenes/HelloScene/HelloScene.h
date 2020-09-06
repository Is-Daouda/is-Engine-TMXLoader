#pragma once

#include "../../../isEngine/system/display/GameDisplay.h"
#include "../../objects/SceneLauncher.h"

// Allows to display a text on the screen
class SceneInfo : public is::MainObject
{
public:
    SceneInfo(sf::Font &font, float x, float y) :
        MainObject(x, y)
    {
        is::createText(font, m_text, "Click on a button to launch an example", m_x, m_y);
    }

    void draw(sf::RenderTexture &surface)
    {
        surface.draw(m_text);
    }
private:
    sf::Text m_text;
};

class HelloScene : public is::GameDisplay
{
public:
    HelloScene(sf::RenderWindow &window, sf::View &view, sf::RenderTexture &surface, is::GameSystemExtended &gameSysExt):
        GameDisplay(window, view, surface, gameSysExt, sf::Color::White /* => scene color*/) {}

    void loadResources()
    {
        m_gameSysExt.m_gameLanguage = is::lang::ENGLISH; // set default game language

        // uncomment to change English language in French
        // m_gameSysExt.m_gameLanguage = is::lang::FRANCAIS;

        // load font and texture
        GameDisplay::loadParentResources(); // allows to load system resource (very important never forgot to call him)
        is::loadSFMLObjResource(m_texButton, is::GameConfig::GUI_DIR + "button.png");

        float _X(200.f), _Y(100.f), _BT_SPACE(48.f);
        SDMaddSceneObject(std::make_shared<SceneInfo>(m_fontSystem, _X - 64.f, _Y - 48.f));

        // The name of the button represents the action that will be performed in the scene
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, _X, _Y,                   "Add Remove Objects", this));
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, _X, _Y + _BT_SPACE,       "Benchmark", this));
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, _X, _Y + _BT_SPACE * 2.f, "Box 2D", this));
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, _X, _Y + _BT_SPACE * 3.f, "Draw Map With Debug", this));
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, _X, _Y + _BT_SPACE * 4.f, "Isometric With Convert Coords", this));
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, _X, _Y + _BT_SPACE * 5.f, "Map With QuadTree", this));
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, _X, _Y + _BT_SPACE * 6.f, "Shader Effects", this));
    }

private:
    sf::Texture m_texButton;
};
