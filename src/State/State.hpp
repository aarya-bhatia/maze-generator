#ifndef STATE_HPP
#define STATE_HPP

struct State
{
    unsigned int state;

    State() : state(0) {}

    enum flags
    {
        generating = 1,
        exploring,
        tracing,
        paused,
        showMenu,
        autoplay,
        quit,
        help,
        loadError,
        settings
    };

    void on(flags flag)
    {
        state = state | (1 << flag);
    }

    void off(flags flag)
    {
        state = state & ~(state & (1 << flag));
    }

    bool is(flags flag) const
    {
        return state & (1 << flag);
    }

    bool isNot(flags flag) const
    {
        return !is(flag);
    }

    static State *create();
};

#endif