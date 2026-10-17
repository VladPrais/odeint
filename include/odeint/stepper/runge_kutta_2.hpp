#ifndef RUNGE_KUTTA_2_HPP
#define RUNGE_KUTTA_2_HPP

#include "odeint/stepper/base_stepper.hpp"

namespace odeint {

template <typename State>
struct runge_kutta_2: base_stepper<State>
{
    typedef typename base_stepper<State>::algebra_type algebra_type;

    template <typename System, typename Time>
    void operator()(System&& sys, Time t, const State& x, State& x_, Time dt)
    {
        sys(t, x, this->k1);

        algebra_type::for_each(x, this->k1, this->temp, algebra::linear_combination_2<Time, Time>(1.0, dt));

        sys(t + dt, this->temp, this->k2);

        algebra_type::for_each(this->k1, this->k2, this->temp, algebra::linear_combination_2<Time, Time>(1.0, 1.0));

        algebra_type::for_each(x, this->temp, x_, algebra::linear_combination_2<Time, Time>(1.0, dt / 2.0));
    }

    private:

    State k1;
    State k2;
};


} /* odeint */

#endif