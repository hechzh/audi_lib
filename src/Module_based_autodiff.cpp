//#include "Module_based_autodiff.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

#ifndef mathparameter
#define mathparameter
#define mathe 2.718281828
#define mathpi 3.1415926536
#endif

using namespace std;
function<double(double)> exp(){
	return ([](double x){return x+1;}) ;
}