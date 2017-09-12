#ifndef FUNCTION_DIFFERENTIAL_LIB_FUNCTIONAUDI_H
#define FUNCTION_DIFFERENTIAL_LIB_FUNCTIONAUDI_H
#include <functional>
#include <cmath>
#include <vector>
typedef double R;
typedef std::function<R(R)> func_;
namespace functionaudi{
    class Function {
    public:
        func_ value;
        func_ der;
        Function(){};
        Function operator+(Function &other);
        Function operator-(Function &other);
        Function operator*(Function &other);
        Function operator/(Function &other);
        Function operator+(R other);
        Function operator-(R other);
        Function operator*(R other);
        Function operator/(R other);
        Function operator^(R other);
        Function scalar(R scale,R move);
        /*
        void operator+=(Function &other);
        void operator-=(Function &other);
        void operator*=(Function &other);
        void operator/=(Function &other);
        void operator+=(R other);
        void operator-=(R other);
        void operator*=(R other);
        void operator/=(R other);
        */
    };
    Function exp(Function x);
    Function sin(Function x);
    Function cos(Function x);
    Function ln(Function x);
    Function tan(Function x);
    Function cot(Function x);
    Function asin(Function x);
    Function acos(Function x);
    Function asin(Function x);
    Function atan(Function x);
    Function acot(Function x);


}


#endif //FUNCTION_DIFFERENTIAL_LIB_FUNCTIONAUDI_H
