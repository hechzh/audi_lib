#include <iostream>
#include "../src/functionaudi.h"
#include "../src/Expression_tree.h"
using namespace std;
using namespace functionaudi;
int main()
{
	defineid(x);
	Function y=asin(x);
	cout<< y.der (0.5)<<endl;
    function_expression_tree x;
	return 0;
}
