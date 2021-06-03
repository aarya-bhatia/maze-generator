#include "Animation.hpp"

//
// -----------Update----------
// In the first update call, scene is null.
// Thereafter, we update the current scene,
// and change it when it is done.
//
void Animation::update()
{
    if (!finished())
    {
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
// Deletes the current scene and creates next one.
// The scene is created by invoking the SceneMaker functor,
// which is accessed by retrieving the next task from
// the task queue...
//
void Animation::nextScene()
{
    if (!taskQueue->finished())
    {
        Scene *tmp = scene;

        Task *task = taskQueue->peek(); // get next task

        taskQueue->dequeue(); // dequeue the next task

        scene = (*task->maker)(sceneData);

        if (K::DEBUG)
        {
            std::cout << "Starting Next Scene: ID=" << task->id << std::endl;
        }

        delete task;

        if (tmp != nullptr)
        {
            delete tmp; // delete previous scene
        }
    }
}

void Animation::init()
{
    addScene(new GeneratorTask(1));
    addScene(new SolverTask(2));
    addScene(new TracerTask(3));
}

Animation::~Animation()
{
    if (K::DEBUG)
    {
        std::cout << __FILE__ << " destructor" << std::endl;
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