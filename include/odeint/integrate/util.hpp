#ifndef INTEGRATE_UTIL_HPP
#define INTEGRATE_UTIL_HPP

#include <cstddef>

namespace odeint {
namespace util {

template <typename State>
void assign(State& x, const State& x_)
{
    x = x_;
}

template <typename T, std::size_t N>
void assign(T (&x)[N], const T (&x_)[N])
{
    for(std::size_t i = 0; i < N; i++)
    {
        x[i] = x_[i];
    }
}

} /* util */
} /* odeint */

#endif