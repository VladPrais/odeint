#ifndef ALGEBRA_UTIL_HPP
#define ALGEBRA_UTIL_HPP

namespace odeint {
namespace algebra {
namespace util {

template <typename Iter1, typename Iter2, typename Function>
void for_each(Iter1 begin1, Iter1 end1, Iter2 begin2, Function&& f)
{
    while(begin1 != end1)
    {
        f(*begin1++, *begin2++);
    }
}

template <typename Iter1, typename Iter2, typename Iter3, typename Function>
void for_each(Iter1 begin1, Iter1 end1, Iter2 begin2, Iter3 begin3, Function&& f)
{
    while(begin1 != end1)
    {
        f(*begin1++, *begin2++, *begin3++);
    }
}

template <
    typename Iter1,
        typename Iter2,
            typename Iter3,
                typename Iter4,
                    typename Iter5,
                        typename Function>
void for_each(Iter1 begin1, Iter1 end1, Iter2 begin2, Iter3 begin3, Iter4 begin4, Iter5 begin5, Function&& f)
{
    while(begin1 != end1)
    {
        f(*begin1++, *begin2++, *begin3++, *begin4++, *begin5++);
    }
}

} /* util */
} /* algebra */
} /* odeint */

#endif