#include "Animation.hpp"

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

// Event is handled by the current scene.
void Animation::handleEvent(const sf::Event &event)
{
    if (scene != nullptr)
    {
        scene->handleEvent(event);
    }
}

// Change the scene when the scene is over
void Animation::nextScene()
{
    if (!taskQueue->finished())
    {
        if (scene != nullptr)
        {
            scenes.push_front(scene);
        }

        TaskQueue::Task task = taskQueue->next(); // get next task

        // invoke task function pointer to create the next scene
        scenes.push_front(task.fptr(*sceneData));
        scene = scenes.front();

        std::cout << "Starting Next Scene: ID=" << task.id << std::endl;
    }
}

void Animation::init()
{
    taskQueue = new TaskQueue(); // task queue stores function pointers to allow Lazy Loading.
    taskQueue->add((TaskQueue::Task){1, &createGenerator});
    taskQueue->add((TaskQueue::Task){2, &createSolver});
    taskQueue->add((TaskQueue::Task){3, &createTracer});

    sceneData = new SceneData(); // data shared among the scenes
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
    delete sceneData;
    delete taskQueue;

    while (!scenes.empty())
    {
        Scene *tmp = scenes.front();
        scenes.pop_front();
        delete tmp;
    }
}