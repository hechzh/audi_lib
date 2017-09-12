#include <iostream>
#include "../src/functionaudi.h"
using namespace std;
using namespace functionaudi;
int main()
{
	Function x;
	x.value=[](R x){return x;};
	x.der=[](R x){return 1;};
	Function y=exp(x);
	cout<< y.der (1)<<endl;
	return 0;
}
