#pragma once

#include "Scene.hpp"
#include "Generator.hpp"
#include "Solver.hpp"
#include "PathTracer.hpp"
#include "TaskQueue.h"
#include <queue>

static inline Scene *createGenerator(SceneData &data)
{
    return new Generator(data);
}

static inline Scene *createSolver(SceneData &data)
{
    return new Solver(data);
}

static inline Scene *createTracer(SceneData &data)
{
    return new PathTracer(data);
}

class Animation : public Component
{
private:
    SceneData *sceneData;
    TaskQueue *taskQueue;
    Scene *scene;
    std::list<Scene*>scenes;

    void nextScene();
    bool finished() const;

public:
    void init() override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event &event) override;

    Animation();
    ~Animation();
};