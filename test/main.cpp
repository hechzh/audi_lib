#include <iostream>
#include "../src/functionaudi.h"
using namespace std;
using namespace functionaudi;
int main()
{
	defineid(x);
	Function y=asin(x);
	cout<< y.der (0.5)<<endl;
	return 0;
}
