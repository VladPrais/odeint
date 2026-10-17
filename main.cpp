#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

#include "odeint/odeint.hpp"

const double g = 9.807;
const double pi = 3.1415;

typedef double state[4];
// typedef std::array<double, 4> state;
// typedef std::vector<double>

void ode(double t, const state& x, state& x_)
{
    x_[0] = x[2];
    x_[1] = x[3];
    x_[2] = 0;
    x_[3] = -g;
}

void observer(double t, const state& x)
{
    if(t < 9.0)
    {
        return ;
    }
    std::cout << t << ' ' ;
    for(std::size_t i = 0; i < 4; i++)
    {
        std::cout << x[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    double alpha = pi / 6.0;
    double a = 0.0, b = 10.0, dt = 0.2;
    double v_0 = 10.0;
    double x_0 = 0.0;
    double y_0 = 0.0;
    double vx_0 = v_0 * std::cos(alpha);
    double vy_0 = v_0 * std::sin(alpha);

    state ic {x_0, y_0, vx_0, vy_0};
    
    std::cout << "euler" << std::endl;
    odeint::integrate(odeint::euler<state>{}, ode, a, b, ic, dt, observer);

    std::cout << "rk2" << std::endl;
    odeint::integrate(odeint::runge_kutta_2<state>{}, ode, a, b, ic, dt, observer);

    std::cout << "rk4" << std::endl;
    odeint::integrate(odeint::runge_kutta_4<state>{}, ode, a, b, ic, dt, observer);

    return 0;
}