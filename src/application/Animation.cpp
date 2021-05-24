#include "Animation.hpp"

#include "GeneratorTask.hpp"
#include "SolverTask.hpp"
#include "TracerTask.hpp"

//
// update the scene
//
void Animation::update()
{
    if (!finished())
    {
        // the first time scene is null.
        // After loading the first scene,
        // we only need to change scene when
        // the scene is over..
        if (scene == nullptr || scene->finished())
        {
            nextScene();
        }
        else
        {
            scene->next();
            scene->update();
        }
    }
}

//
// pass event handling to scene
//
void Animation::handleEvent(const sf::Event &event)
{
    if (scene != nullptr)
    {
        scene->handleEvent(event);
    }
}

//
// Deletes the current scene and creates next one.
// The scene is created by invoking the SceneMaker functor,
// which is accessed by retrieving the next task from
// the task queue...
//
void Animation::nextScene()
{
    if (!taskQueue->finished())
    {
        Scene *previousScene = scene;

        Task *task = taskQueue->peek(); // get next task
        taskQueue->dequeue();           // dequeue the next task

        // invoke the scene maker functor to create the next scene

        scene = (*task->maker)(sceneData);
        std::cout << "Starting Next Scene: ID=" << task->id << std::endl;

        // Cleanup

        if (previousScene != nullptr)
        {
            delete previousScene;
        }

        // The task will delete the scene maker
        if (task != nullptr)
        {
            delete task;
        }

        // Not updating scenes list here.. i dont think we need the previous scenes to stay
    }
}

void Animation::init()
{
    // task queue is used for Lazy Loading scenes...
    taskQueue = new TaskQueue();

    taskQueue->enqueue(new GeneratorTask(1));
    taskQueue->enqueue(new SolverTask(2));
    taskQueue->enqueue(new TracerTask(3));

    sceneData = new SceneData(); // This data is shared among the scenes
    scene = nullptr;             // there is no current scene initially
}

// Render the scene
void Animation::render(sf::RenderWindow &window)
{
    if (scene != nullptr)
    {
        scene->render(window);
    }
}

//
// We are done if there are no more task and
// the last scene is done,
// or if there weren't any scenes,
// in which case the scene is null..
//
bool Animation::finished() const
{
    return taskQueue->finished() && (scene == nullptr || scene->finished());
}

Animation::Animation() : scenes()
{
    if (K::DEBUG)
    {
        std::cout << __FILE__ << " constructor" << std::endl;
    }
    init();
}

Animation::~Animation()
{
    if (K::DEBUG)
    {
        std::cout << __FILE__ << " destructor" << std::endl;
    }

    std::cout << __FILE__ << ": Destroying scenes.." << std::endl;

    for (auto it = scenes.begin(); it != scenes.end();)
    {
        if (*it != nullptr)
        {
            delete *it;
            it = scenes.erase(it);
        }
    }

    if (scene != nullptr)
    {
        delete scene;
    }
    if (sceneData != nullptr)
    {
        delete sceneData;
    }
    if (taskQueue != nullptr)
    {
        delete taskQueue;
    }
}