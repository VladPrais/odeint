#ifndef VECTOR_ALGEBRA_HPP
#define VECTOR_ALGEBRA_HPP

#include <iterator>

#include "util.hpp"

namespace odeint {
namespace algebra {

struct vector_algebra
{
    template <template <typename> class Vector,  typename T, typename Function>
    static void for_each(const Vector<T>& v1, const Vector<T>& v2, Vector<T>& v3, Function&& f)
    {
        util::for_each(std::begin(v1), std::end(v1), std::begin(v2), std::begin(v3), f);
    }
};

} /* algebra */
} /* odeint */

#endif