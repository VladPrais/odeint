#ifndef CARRAY_ALGEBRA_HPP
#define CARRAY_ALGEBRA_HPP

#include <cstddef>
#include <iterator>

#include "util.hpp"

namespace odeint {
namespace algebra {

struct carray_algebra
{
    template <typename T, std::size_t N, typename Function>
    static void for_each(const T (&c1)[N], T(&c2)[N], Function&& f)
    {
        util::for_each(std::begin(c1), std::end(c1), std::begin(c2), f);
    }

    template <typename T, std::size_t N, typename Function>
    static void for_each(const T (&c1)[N], const T (&c2)[N], T (&c3)[N], Function&& f)
    {
        util::for_each(std::begin(c1), std::end(c1), std::begin(c2), std::begin(c3), f);
    }

    template <typename T, std::size_t N, typename Function>
    static void for_each(
        const T (&c1)[N],
            const T (&c2)[N],
                const T (&c3)[N],
                    const T (&c4)[N],
                        T (&c5)[N],
                            Function&& f)
    {
        util::for_each(std::begin(c1), std::end(c1), std::begin(c2), std::begin(c3), std::begin(c4), std::begin(c5), f);
    }
};

} /* algebra */
} /* odeint */

#endif