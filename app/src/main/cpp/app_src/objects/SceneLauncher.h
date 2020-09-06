#ifndef SCENELAUNCHER_H_INCLUDED
#define SCENELAUNCHER_H_INCLUDED

#include "../../isEngine/system/entity/Button.h"

class SceneLauncher : public is::Button
{
public:
    // The name of the button represents the action that will be performed in the scene
    SceneLauncher(sf::Texture &tex, float x, float y, std::string name, is::GameDisplay *scene) :
        Button(tex, x, y, name, scene)
    {
        m_strName = name;
    }

    void onClick()
    {
        if (m_scene->getIsRunning())
        {
            m_scene->getGameSystem().m_launchOption = is::DisplayOption::TMX_DEMO_SCENE;

            // Here the variable "m_currentLevel" is used to run the corresponding example
            if (m_strName == "Add Remove Objects") m_scene->getGameSystem().m_currentLevel = 0;
            else if (m_strName == "Benchmark") m_scene->getGameSystem().m_currentLevel = 1;
            else if (m_strName == "Box 2D") m_scene->getGameSystem().m_currentLevel = 2;
            else if (m_strName == "Draw Map With Debug") m_scene->getGameSystem().m_currentLevel = 3;
            else if (m_strName == "Isometric With Convert Coords") m_scene->getGameSystem().m_currentLevel = 4;
            else if (m_strName == "Map With QuadTree") m_scene->getGameSystem().m_currentLevel = 5;
            else if (m_strName == "Shader Effects") m_scene->getGameSystem().m_currentLevel = 6;
            else if (m_strName == "Back To Hello Scene") m_scene->getGameSystem().m_launchOption = is::DisplayOption::HELLO_SCENE;
            m_scene->setIsRunning(false);
        }
    }
};

#endif // SCENELAUNCHER_H_INCLUDED
