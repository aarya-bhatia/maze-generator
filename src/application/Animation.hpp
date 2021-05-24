#pragma once

#include "Scene.hpp"
#include "TaskQueue.h"

class Animation : public Component
{
private:
    SceneData *sceneData; // This data is shared among the scenes
    TaskQueue *taskQueue; // The task queue is used for Lazy Loading
    Scene *scene;         // Pointer to the current scene

    void nextScene();

    void addScene(Task *task) { taskQueue->enqueue(task); }

    //
    // The animation is done if there are no more tasks and the last scene is done.
    //
    bool finished() const
    {
        return taskQueue->finished() && (scene == nullptr || scene->finished());
    }

public:
    // Fill the task queue
    void init() override;

    void update() override;

    // Render the scene
    void render(sf::RenderWindow &window) override
    {
        if (scene != nullptr)
        {
            scene->render(window);
        }
    }

    //
    // pass event handling to scene
    //
    void handleEvent(const sf::Event &event) override
    {
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::M)
        {
            K::MENU = true;
        }
        else if (scene != nullptr)
        {
            scene->handleEvent(event);
        }
    }

    Animation() : sceneData(new SceneData()),
                  taskQueue(new TaskQueue()),
                  scene(nullptr)
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " constructor" << std::endl;
        }
        init();
    }

    ~Animation();
};