#include "Bits.hpp"

#ifndef STATE_HPP
#define STATE_HPP

struct State
{
    int state;

    // todo make a menu state containing quit help settings flags
    // state should have a flag for menu, if menu is on,
    // menu state handles further requests
    // if menu flag is off, state handles general requests
    // todo: use my bits library to set flags on or off

    State() : state(0) {}

    enum flags
    {
        paused = 1,
        menu,
        quit,
        error
    };

    void on(flags flag)
    {
        Math::Bits::setOn(state, flag);
    }

    void off(flags flag)
    {
        Math::Bits::setOff(state, flag);
    }

    bool is(flags flag) const
    {
        return Math::Bits::contains(state, flag);
    }

    bool isNot(flags flag) const
    {
        return !Math::Bits::contains(state, flag);
    }

    static State *create()
    {
        State *state = new State;

        state->on(State::paused);
        state->on(State::showMenu);

        assert(state->is(State::paused));
        assert(state->is(State::showMenu));

        return state;
    }
};

#endif