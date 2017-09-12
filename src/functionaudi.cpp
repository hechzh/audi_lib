#ifndef FUNCTION_DIFFERENTIAL_LIB_FUNCTIONAUDI_H
#include "functionaudi.h"
#endif
using namespace functionaudi;
Function Function::operator+(Function &other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)+other.value(x);};
    answer.der=[this,other](R x){return this->value (x)+other.value(x);};
    return answer;
}
Function Function::operator-(Function &other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)-other.value(x);};
    answer.der=[this,other](R x){return this->value (x)-other.value(x);};
    return answer;
}
Function Function::operator*(Function &other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)*other.value(x);};
    answer.der=[this,other](R x){return this->value (x) * other.der(x) + other.value(x) * this->der(x);};
    return answer;
}
Function Function::operator/(Function &other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)/other.value(x);};
    answer.der=[this,other](R x){return (this->value (x) * other.der(x) + other.value(x) * this->der(x))/other.value(x)/other.value(x);};
    return answer;
}
Function Function::operator+(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) + other;};
    answer.der= this->der;
    return answer;
}
Function Function::operator-(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) - other;};
    answer.der= this->der;
    return answer;
}
Function Function::operator*(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) * other;};
    answer.der= [this,other](R x){return this->der (x) * other;};
    return answer;
}
Function Function::operator/(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) / other;};
    answer.der= [this,other](R x){return this->der (x) / other;};
    return answer;
}
Function Function::operator^(R other){
    Function answer;
    answer.value=[this,other](R x){return std::pow(this->value (x) ,other);};
    if(other==1) answer.der=this->der;
    else answer.der= [this,other](R x){return other*std::pow(this->value (x) , other-1) * this->der(x);};
    return answer;
}
Function Function::scalar(R scale,R move){
    this->value = [this,scale,move](R x){ return scale*this->value(x) +move;};
    this->der = [this,scale,move](R x){ return scale*this->der(x);};
}
/*
void Function::scalar(R scale,R move){
    this->value = [this,scale,move](R x){ return scale*this->value(x) +move;};
    this->der = [this,scale,move](R x){ return scale*this->der(x);};
}

void Function::operator+=(Function &other){
    this->value=[this,other](R x){return this->value (x)+other.value(x);};
    this->der=[this,other](R x){return this->value (x)+other.value(x);};
}
void Function::operator-=(Function &other){
    this->value=[this,other](R x){return this->value (x)-other.value(x);};
    this->der=[this,other](R x){return this->value (x)-other.value(x);};
}
void Function::operator*=(Function &other){
    this->value=[this,other](R x){return this->value (x)*other.value(x);};
    this->der=[this,other](R x){return this->value (x) * other.der(x) + other.value(x) * this->der(x);};
}
void Function::operator/=(Function &other){
    this->value=[this,other](R x){return this->value (x)/other.value(x);};
    this->der=[this,other](R x){return (this->value (x) * other.der(x) + other.value(x) * this->der(x))/other.value(x)/other.value(x);};
}
void Function::operator+=(R other){
    this->value=[this,other](R x){return this->value (x) + other;};
}
void Function::operator-=(R other){
    this->value=[this,other](R x){return this->value (x) - other;};
}
void Function::operator*=(R other){
    this->value=[this,other](R x){return this->value (x) * other;};
    this->der=[this,other](R x){return this->value (x) * other;};
}
void Function::operator/=(R other){
    this->value=[this,other](R x){return this->value (x) / other;};
    this->der=[this,other](R x){return this->value (x) / other;};
}

*/
Function functionaudi::exp(Function y){
    Function answer;
    answer.value=[y](R x){return std::exp(y.value(x));};
    answer.der=[y](R x){return y.der(x)*std::exp(y.value(x));};
    return answer;
}

Function functionaudi::sin(Function y){
    Function answer;
    answer.value=[y](R x){return std::sin(y.value(x));};
    answer.der=[y](R x){return y.der(x)*std::cos(y.value(x));};
    return answer;
}
Function functionaudi::cos(Function y){
    Function answer;
    answer.value=[y](R x){return std::cos(y.value(x));};
    answer.der=[y](R x){return -y.der(x)*std::sin(y.value(x));};
    return answer;
}
Function functionaudi::ln(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::log(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / y.value(x); };
    return answer;
}