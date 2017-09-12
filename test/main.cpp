#include <iostream>
#include "../src/functionaudi.h"
using namespace std;
int main()
{
	basic_expression a(0);
	basic_expression b(1);
	node x;
	node y;
	node z;
	x.express=a;
	x.color=1;
	x.father=&z;
	y.express=b;
	y.color=0;
	y.father=&z;
	z.leftchild=&x;
	z.rightchild=&y;
	z.opt=0;
	z.initial();
	func_ diffrential=z.difffunc;
	cout<< (a.value_)(1)<<endl;
	cout<< (b.value_)(1)<<endl;
	cout<<"v:" <<diffrential(1)<<endl;
	return 0;
}
