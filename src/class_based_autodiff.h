#ifndef class_based_autodiff_
#define class_based_autodiff_
#include <string>
#ifndef mathparameter
#define mathparameter
#define mathe 2.718281828
#define mathpi 3.1415926536
#endif
using namespace std;
int match(string s)
{
	int answer=0;
	int count=0;
	int z_1=s.size();
	int left;
	int right;
	for(;z_1>=0;z_1--){
		if (s[z_1]==")")count++;
		else if(s[z_1]=="(")count--;
		if (z_1==0){
			return answer;
		}else if (count==0){
			if (s[z_1-1]=="+"){
				answer=1;
			}else if (s[z_1-1]=="-"){
				answer=2;
			}else if (s[z_1-1]=="*"){
				answer=3;
			}else if (s[z_1-1]=="/"){
				answer=4;
			}else if (s[z_1-1]=="^"){
				answer=5;
			}else{
				if(z_1==2){//ln
					answer=6;
				}else if(z_1==3){//exp,cos,sin
					if (s[z_1--]=="p"){
						answer=7;
					}else if (s[z_1--]=="s"){
						answer=8
					}else if (s[z_1--]=="p"){
						answer=9;
					}
				}
			}
		}
	}
}
class Expression
{
public:
	Expression diff(){
		if(){
			return 
		}else if(){

		}else if(){

		}
	}
private:
	string s
	diff
}






#endif