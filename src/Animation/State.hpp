#include "Bits.hpp"

#ifndef STATE_HPP
#define STATE_HPP

struct State
{
    unsigned int state;

    // todo make a menu state containing quit help settings flags
    // state should have a flag for menu, if menu is on,
    // menu state handles further requests
    // if menu flag is off, state handles general requests
    // todo: use my bits library to set flags on or off

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