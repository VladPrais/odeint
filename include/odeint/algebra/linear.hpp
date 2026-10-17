#ifndef LINEAR_HPP
#define LINEAR_HPP

namespace odeint {
namespace algebra {

template <typename Scal1, typename Scal2=Scal1>
struct linear_combination_2
{
    linear_combination_2(Scal1 s1, Scal2 s2): a1(s1), a2(s2){}

    template <typename Val1, typename Val2, typename Val3>
    void operator()(const Val1& v1, const Val2& v2, Val3& v3)
    {
        v3 = this->a1 * v1 + this->a2 * v2;
    }

    private:

    Scal1 a1;
    Scal2 a2;
};

template <typename Scal1, typename Scal2=Scal1, typename Scal3=Scal1, typename Scal4=Scal1>
struct linear_combination_4
{
    linear_combination_4(Scal1 s1, Scal2 s2, Scal3 s3, Scal4 s4): a1(s1), a2(s2), a3(s3), a4(s4){}

    template <typename Val1, typename Val2, typename Val3, typename Val4, typename Val5>
    void operator()(const Val1& v1, const Val2& v2, const Val3& v3, const Val4& v4, Val5& v5)
    {
        v5 = a1 * v1 + a2 * v2 + a3 * v3 + a4 * v4;
    }

    private:

    Scal1 a1;
    Scal2 a2;
    Scal3 a3;
    Scal4 a4;
};

} /* algebra */
} /* odeint */

#endif