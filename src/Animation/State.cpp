#include "State.hpp"

#include "K.hpp"
#include <assert.h>

State *State::create()
{
    State *state = new State;

    if (K::AUTOPLAY)
    {
        state->on(State::autoplay);
        assert(state->is(State::autoplay));
    }

    state->on(State::generating);
    assert(state->is(State::generating));

    state->on(State::paused);
    state->on(State::showMenu);

    assert(state->is(State::paused));
    assert(state->is(State::showMenu));

    return state;
}