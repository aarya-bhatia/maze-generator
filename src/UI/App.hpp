#include "Component.hpp"
#include <list>

#pragma once

class App
{
private:
    std::list<Component *> components;

public:
    typedef std::list<Component>::iterator iterator;

    bool hasComponent(const std::string &name)
    {
        for (Component *c : components)
        {
            if (c->name == name)
            {
                return true;
            }
        }

        return false;
    }

    Component *getComponent(const std::string &name)
    {
        for (Component *c : components)
        {
            if (c->name == name)
            {
                return c;
            }
        }
        return nullptr;
    }

    void addComponent(Component *component)
    {
        components.push_back(component);
    }

    void removeComponent(const std::string &name)
    {
        for (Component *c : components)
        {
            if (c->name == name)
            {
                delete c;
                components.remove(c);
                break;
            }
        }
    }

    void update()
    {
        for (Component *c : components)
        {
            c->update();
        }
    }

    void render(sf::RenderWindow &window)
    {
        for (Component *c : components)
        {
            c->render(window);
        }
    }

    void handleEvent(const sf::Event &event)
    {
        for (Component *c : components)
        {
            c->handleEvent(event);
        }
    }

    void init()
    {
        components = std::list<Component *>();
    }

    void destroy()
    {
        while (!components.empty())
        {
            Component *c = components.back();
            delete c;
            components.pop_back();
        }
    }

    App()
    {
        init();
    }

    ~App()
    {
        destroy();
    }
};