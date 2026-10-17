#ifndef EULER_HPP
#define EULER_HPP

#include "odeint/algebra/array_algebra.hpp"
#include "odeint/algebra/carray_algebra.hpp"
#include "odeint/algebra/vector_algebra.hpp"

#include "odeint/algebra/dispatcher.hpp"

#include "odeint/stepper/base_stepper.hpp"

namespace odeint {

template <typename State>
struct euler: base_stepper<State>
{
    typedef typename base_stepper<State>::algebra_type algebra_type;

    template <typename System, typename Time>
    void operator()(System&& sys, Time t, const State& x, State& x_, Time dt)
    {
        sys(t, x, this->dxdt);
        algebra_type::for_each(x, this->dxdt, x_, algebra::linear_combination_2<Time, Time>(1.0, dt));
    }
};

} /* odeint */

#endif