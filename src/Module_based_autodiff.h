#include <string>
#include <stack>
#include <cmath>
#include <functional>
#ifndef mathparameter
#define mathparameter
#define mathe 2.718281828
#define mathpi 3.1415926536
#endif
using namespace std;
function<double(double)> exp1=[](double i){return pow(mathe,i);};
stack<function<double(double)> > LL;

//ln-1,cos-2,sin-3,exp-4,asin-5,acos-6,tan-7,atan-8,sqrt-9,powk-10,k*-11,k/-12
/*struct Expression{
	function<string(string)> val,
	function<string(string)> der,
	Expression*,
	int ww,
	string transform(string node)
	{
		if(der){return der(node);}
		else{der=}
	}
}
*/
function<double(double)> int2function(int i){
	if (i==1){return exp1;}
}
function<double(double)> int2diffunction(int i){
	if (i==1){return exp1;}
}
template<int i,int... Args>
class expression;
template<>
class expression<1>;
template<int i,int... Args>
class expression
{
public:
	static constexpr stack<function<double(double)> > value=expression<Args...>::value.push(int2function(i));
	static constexpr stack<function<double(double)> > diff=expression<Args...>::diff.push(int2diffunction(i));
};

template<>
class expression<1>
{
public:
	static constexpr stack<function<double(double)> > value;
	static constexpr stack<function<double(double)> > diff;
	expression<1>(){
		stack<function<double(double)> > V;stack<function<double(double)> > D;
		V.push(int2function(1));D.push(int2difffunction(1));
		value=V;diff=D;
	}
	
};

/*
inline stack<function<double(double)>> value(){
	return (<int... Args>).push(int2function(i));
}
template<int... Args>
inline stack<function<double(double)>> diff(int i,int... Args){
	
}
*/