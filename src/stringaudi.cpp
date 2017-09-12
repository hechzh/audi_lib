/*#include <cmath>
#include <iostream>
//#include "Module_based_autodiff.h"
#include <algorithm>
#include <functional>

#ifndef mathparameter
#define mathparameter
#define mathe 2.718281828
#define mathpi 3.1415926536
#endif

using namespace std;

function<double(double)> ppp(){
  function<double(double)> exp2 = [](double i) { return pow(mathe,i); };
  return exp2;
}
int
main(int argc, char** argv)
{
  cout<<"Hello,world\n"<<endl;
  function<double(double)> exp = ppp();
  //function<double(double)> exp1 =exp|exp(1);
  cout<<exp|exp(1)<<endl;
  return(0);
}

/*
#include <iostream>
#define define_functor_type(func_name) class tfn_##func_name {\
public: template <typename... Args> auto operator()(Args&&... args) const ->decltype(func_name(std::forward<Args>(args)...))\
{ return func_name(std::forward<Args>(args)...); } }
using namespace std;
//test code
int add(int a, int b)
{
    return a + b;
}
int add_one(int a) 
{ 
  return 1 + a; 
}
define_functor_type(add);
define_functor_type(add_one);
int main()
{  
    tfn_add add_functor;
    cout<<add_functor(1, 2); //result is 3

    tfn_add_one add_one_functor;
    cout<<add_one_functor(1)<<endl; //result is 2
    return 0;
}
*/
//#include "Module_based_autodiff.h"
#include "test.h"
#include <functional>
#include <vector>
#include <iostream>
using namespace std;
/*
R computevalue(stack<opt> optstorer)
{

}
func_ selffunc()
{
return [](R x){return x;};
}
func_ comp(func_ a,func_ b)
{
  return [=](R x){return a(b(x));};
}
func_ mul(func_ a,func_ b)
{
  return [=](R x){return a(x)*b(x);}
}
functor_ diff(stack<func_> a)
{
  stack<func_> cp=a;
  if ((cp.pop()).empty()){

  }else{
  return mul(diff(cp.pop()),cp.top());
  }
}
*/
string string2standard(string s,string x)
{
  string k=x;
  for(int size=s.size();size>=0;size--)
  {
    if (s[size]==97){
      k=string("exp(")+k+string(")");
    }
  }
  return k;
}
/*
{
  string k;
  int x=s.size();
  for(int i=0;i<x;i++){
    if (s[i]==string("a")){
      k=string("exp(")
    }
  }
}*/
/*
function<string(string)> diff(string s)
{
if (s==string("a")){
return [](string x){return string("exp(")+x+string(")");};
}else if (s==string("b")){
return [](string x){return string("(1)/(")+x+string(")");};
}else if (s==string("c")){
return [](string x){return string("cos(")+x+string(")");};
}else if (s==string("d")){
return [](string x){return string("-sin(")+x+string(")");};
}else{
return [=](string x){return string("(")+string(diff(s[0])(string2standard(s.substr(1))))+string(")*(")+diff(s.substr(1))(x)+")";};
}
}
*/

function<string(string)> diff(string s)
{
if (s.empty()==1){
return [](string s){return string("1");};
}else{
if (s[0]==97){
return [s](string x){
  return string("(exp(")+string2standard(s.substr(1),x)+string("))*(")+diff(s.substr(1))(x)+string(")");};
}else if (s[0]==98){
return [s](string x){
  return string("(1/(")+string2standard(s.substr(1),x)+string("))*(")+diff(s.substr(1))(x)+string(")");};  
}else if (s[0]==99){
return [s](string x){
  return string("(cos(")+string2standard(s.substr(1),x)+string("))*(")+diff(s.substr(1))(x)+string(")");};
}else if (s[0]==100){
return [s](string x){
  return string("(-sin(")+string2standard(s.substr(1),x)+string("))*(")+diff(s.substr(1))(x)+string(")");};
}
}
}
enum op2
{
  add,
  minus,
  mulitple,
  division,
};
string addtuple(string x){
  return string("(")+x+string(")");
}
string oper(op2 z,string x,string y){
  if(z==add){
    return addtuple(x)+string("+")+addtuple(y);
  }else if (z==minus){
    return addtuple(x)+string("-")+addtuple(y);
  }else if (z==mulitple){
    return addtuple(x)+string("*")+addtuple(y);
  }else if (z==division){
    return addtuple(x)+string("+")+addtuple(y);
  }
}
class node
{
node* father;
node* leftchild;
node* rightchild;
function<string(string)> express;
op2 self;
string value;
}
class graph
{
node root;
void update(node& s){
if(s.leftchild==nullptr&&s.rightchild==nullptr){

}else if (s.leftchild!=nullptr&&s.rightchild==nullptr){
  s.leftchild.update();
  s.value=oper(self,((*leftchild).express)((*leftchild).value),((*leftchild).express)((*leftchild).value))
}
}
}
int main() {

    //dict1value[exp1]=[](R i){return exp(i);};
    //dict2value[add1]=[](func_ i){return [](R a){return i(a);};};
        //cout<< (expression<1>::value)(1) <<endl;
        //LL.push(exp1);
        //cout<<LL.size()<<endl;
    string s=string("x");
    cout<< diff(string("da"))(s)<<endl;    
        return 0;
}
