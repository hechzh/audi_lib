#ifndef function_audi
#define function_audi
#include <functional>
#include <algorithm>
#include <stack>
#include <cmath>
#include <string>
#include <map>
using namespace std;

typedef double R;
typedef function<double(double)> func_;
typedef function<function<double(double)>(function<double(double)>)> functor_;


struct basic_expression
{
	int type;//0=exp,1=ln,2=sin,3=cos,-1=x (return x itself)
	R scalar;// like 2*exp(x) 2 is the scalar
	func_ value_;
	functor_ _value;
	func_ diff_;
	functor_ _diff;
        basic_expression(int x=-1,double y=1.0);
};
struct node
{
 	int color=0;//0-none ,1 -do
 	node* father=nullptr;
 	basic_expression express=basic_expression(-1);
 	node* leftchild=nullptr;
 	node* rightchild=nullptr;
 	func_ valuefunc;
 	func_ difffunc;
 	int opt=-1;// 0-add ,1-minus,2-multiple,3-division,-1 -none
 	double value;
 	void initial();
};
#endif
