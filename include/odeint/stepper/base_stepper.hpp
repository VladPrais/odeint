#ifndef BASE_STEPPER_HPP
#define BASE_STEPPER_HPP

// #include <array>

#include "odeint/algebra/array_algebra.hpp"
#include "odeint/algebra/carray_algebra.hpp"
#include "odeint/algebra/vector_algebra.hpp"

#include "odeint/algebra/dispatcher.hpp"

namespace odeint {

template <typename State>
struct base_stepper
{
    typedef typename algebra::dispatcher<State>::algebra_type algebra_type;

    template <typename System, typename Time>
    void operator()(System&& sys, Time t, const State& x, State& x_, Time dt){}

    protected:

    State dxdt;
    State temp;
};

} /* odeint */

#endif