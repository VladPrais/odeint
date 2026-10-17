#ifndef INTEGRATE_HPP
#define INTEGRATE_HPP

#include "odeint/integrate/util.hpp"

namespace odeint {

template <typename Stepper, typename System, typename Time, typename State, typename Observer>
void integrate(Stepper stepper, System&& sys, Time a, Time b, const State& x, Time dt, Observer observer)
{
    State x_in, x_out;
    util::assign(x_in, x);
    
    while(a < b)
    {
        observer(a, x_in);

        dt = dt < (b - a) ? dt : (b - a);

        stepper(sys, a, x_in, x_out, dt);

        a += dt;
        util::assign(x_in, x_out);
    }

    observer(a, x_in);
}

} /* odeint */

#endif