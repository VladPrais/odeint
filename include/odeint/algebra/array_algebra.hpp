#ifndef ARRAY_ALGEBRA_HPP
#define ARRAY_ALGEBRA_HPP

#include <cstddef>

namespace odeint {
namespace algebra {

struct array_algebra
{
    template <template <typename, std::size_t> class Array, typename T, std::size_t N, typename Function>
    static void for_each(const Array<T, N>& a1, Array<T, N>& a2, Function&& f)
    {
        for(std::size_t i = 0; i < N; i++)
        {
            f(a1[i], a2[i]);
        }
    }

    template <template <typename, std::size_t> class Array, typename T, std::size_t N, typename Function>
    static void for_each(const Array<T, N>& a1, const Array<T, N>& a2, Array<T, N>& a3, Function&& f)
    {
        for(std::size_t i = 0; i < N; i++)
        {
            f(a1[i], a2[i], a3[i]);
        }
    }

    template <template <typename, std::size_t> class Array, typename T, std::size_t N, typename Function>
    static void for_each(
        const Array<T, N>& a1,
        const Array<T, N>& a2,
        const Array<T, N>& a3,
        const Array<T, N>& a4,
        Array<T, N>& a5,
        Function&& f)
    {
        for(std::size_t i = 0; i < N; i++)
        {
            f(a1[i], a2[i], a3[i], a4[i], a5[i]);
        }
    }
};

} /* algebra */
} /* odeint */

#endif