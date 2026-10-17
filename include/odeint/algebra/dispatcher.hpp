#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include <cstddef>

#include "array_algebra.hpp"
#include "carray_algebra.hpp"
#include "vector_algebra.hpp"

namespace odeint {
namespace algebra {

template <typename>
struct dispatcher;

template <template <typename, std::size_t> class Array, typename T, std::size_t N>
struct dispatcher<Array<T, N>>
{
    typedef algebra::array_algebra algebra_type;
};

template <typename T, std::size_t N>
struct dispatcher<T[N]>
{
    typedef algebra::carray_algebra algebra_type;
};

template <template <typename> class Vector, typename T>
struct dispatcher<Vector<T>>
{
    typedef algebra::vector_algebra algebra_type;
};

} /* algebra */
} /* odeint */


#endif