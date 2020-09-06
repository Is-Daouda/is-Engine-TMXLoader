#pragma once

#include "../../../isEngine/system/display/GameDisplay.h"
#include "../../objects/tmxExample/Box2D.h"
#include "../../objects/tmxExample/Benchmark.h"
#include "../../objects/tmxExample/AddRemoveObjects.h"
#include "../../objects/tmxExample/DrawMapWithDebug.h"
#include "../../objects/tmxExample/IsometricWithConvertCoords.h"
#include "../../objects/tmxExample/MapWithQuadTree.h"
#include "../../objects/tmxExample/ShaderEffects.h"
#include "../../objects/SceneLauncher.h"

class TMXDemoScene : public is::GameDisplay
{
public:
    TMXDemoScene(sf::RenderWindow &window, sf::View &view, sf::RenderTexture &surface, is::GameSystemExtended &gameSysExt):
        GameDisplay(window, view, surface, gameSysExt, sf::Color::Black /* => scene color*/) {}

    void loadResources()
    {
        // load font and texture
        GameDisplay::loadParentResources(); // allows to load system resource (very important never forgot to call him)
        is::loadSFMLObjResource(m_texButton, is::GameConfig::GUI_DIR + "button.png");

        // run the corresponding example according to the chosen option in the Hello scene
        switch (m_gameSysExt.m_currentLevel)
        {
            case 0: SDMaddSceneObject(std::make_shared<AddRemoveObjects>(this), true, true, "", true); break;
            case 1: SDMaddSceneObject(std::make_shared<Benchmark>(this)); break;
            case 2: SDMaddSceneObject(std::make_shared<Box2D>(this)); break;
            case 3: SDMaddSceneObject(std::make_shared<DrawMapWithDebug>(this), true, true, "", true); break;
            case 4: SDMaddSceneObject(std::make_shared<IsometricWithConvertCoords>(this), true, true, "", true); break;
            case 5: SDMaddSceneObject(std::make_shared<MapWithQuadTree>(this)); break;
            case 6: SDMaddSceneObject(std::make_shared<ShaderEffects>(this), true, true, "", true); break;
        }
        SDMaddSceneObject(std::make_shared<SceneLauncher>(m_texButton, 202.f, 0.f, "Back To Hello Scene", this));
    }

private:
    sf::Texture m_texButton;
};
