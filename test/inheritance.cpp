#include <iostream>

using namespace std;

struct Component
{
    void update()
    {
        cout << "Component update called" << endl;
    }

    virtual void render()
    {
        cout << "Component render called" << endl;
    }
};

struct Button : public Component
{
    void update()
    {
        cout << "Button update called" << endl;
    }

    void render() override
    {
        cout << "Button render called" << endl;
    }
};

int main()
{
    Component b;
    Button b1;

    b.update();
    b1.update();

    b.render();
    b1.render();

    return 0;
}