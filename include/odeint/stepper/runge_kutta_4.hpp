#ifndef RUNGE_KUTTA_4_HPP
#define RUNGE_KUTTA_4_HPP

#include "odeint/stepper/base_stepper.hpp"

namespace odeint {

template <typename State>
struct runge_kutta_4: base_stepper<State>
{
    typedef typename base_stepper<State>::algebra_type algebra_type;

    template <typename System, typename Time>
    void operator()(System&& sys, Time t, const State& x, State& x_, Time dt)
    {
        Time dt_m = dt / 2.0;

        /* k1 */
        sys(t, x, this->dxdt);

        /* k2 */
        algebra_type::for_each(x, this->dxdt, this->temp, algebra::linear_combination_2<Time>(1.0, dt_m));
        sys(t + dt_m, this->temp, this->k2);

        /* k3 */
        algebra_type::for_each(x, this->k2, this->temp, algebra::linear_combination_2<Time>(1.0, dt_m));
        sys(t + dt_m, this->temp, this->k3);

        /* k4 */
        algebra_type::for_each(x, this->k3, this->temp, algebra::linear_combination_2<Time>(1.0, dt));
        sys(t + dt, this->temp, this->k4);

        algebra_type::for_each(this->dxdt, this->k2, this->k3, this->k4, this->temp, algebra::linear_combination_4<Time>(1.0, 2.0, 2.0, 1.0));
        algebra_type::for_each(x, this->temp, x_, algebra::linear_combination_2<Time>(1.0, dt / 6.0));
    }

    private:

    // State k1;
    State k2;
    State k3;
    State k4;
};

} /* odeint */

#endif