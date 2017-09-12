#include "functionaudi.h"
using namespace std;

basic_expression::basic_expression(int x,double y){
    	type=x;
    	scalar=y;
		if (x==0){
			value_=[y](R i){return y*exp(i);};
			_value=[y](func_ i){return [i,y](R j){return y*exp(i(j));};};
			diff_=[y](R i){return y*exp(i);};
			_diff=[y](func_ i){return [i,y](R j){return y*exp(i(j));};};
		}else if (x==1){
			value_=[y](R i){return y*log(i);};
			_value=[y](func_ i){return [i,y](R j){return y*log(i(j));};};
			diff_=[y](R i){return y/i;};
			_diff=[y](func_ i){return [i,y](R j){return y/i(j);};};
		}else if (x==2){
			value_=[y](R i){return y*sin(i);};
			_value=[y](func_ i){return [i,y](R j){return y*sin(i(j));};};
			diff_=[y](R i){return y*cos(i);};
			_diff=[y](func_ i){return [i,y](R j){return y*cos(i(j));};};
		}else if (x==3){
			value_=[y](R i){return y*cos(i);};
			_value=[y](func_ i){return [i,y](R j){return y*cos(i(j));};};
			diff_=[y](R i){return -y*sin(i);};
			_diff=[y](func_ i){return [i,y](R j){return -y*sin(i(j));};};
		}else if (x==-1){
			value_=[y](R i){return y*i;};
			_value=[y](func_ i){return [i,y](R j){return y*i(j);};};
			diff_=[y](R i){return y;};
			_diff=[y](func_ i){return [i,y](R j){return y;};};
		}
}

void node::initial(){
 		if (leftchild==nullptr&&rightchild==nullptr){
 			valuefunc=[](R i){return i;};
 			difffunc=[](R i){return 1;};
 		}else if(leftchild!=nullptr&&rightchild==nullptr){
 			(*leftchild).initial();
 			node temp=*leftchild;
 			valuefunc=((temp.express)._value)(temp.valuefunc);
 			if (temp.color==1){
 				difffunc=[temp](R v){return ((temp.express)._diff)(temp.valuefunc)(v)*(temp.difffunc)(v);};
 			}else if (temp.color==0){
 				difffunc=[](R v){return 0;};
 			}
 		}else if(leftchild!=nullptr&&rightchild==nullptr){
 			(*rightchild).initial();
 			node temp=*rightchild;
 			valuefunc=((temp.express)._value)(temp.valuefunc);
 			if (temp.color==1){
 				difffunc=[temp](R v){return ((temp.express)._diff)(temp.valuefunc)(v)*(temp.difffunc)(v);};
 			}else if (temp.color==0){
 				difffunc=[](R v){return 0;};
 			}
 		}else if(leftchild!=nullptr&&rightchild!=nullptr){
 			(*leftchild).initial();
 			(*rightchild).initial();
 			node left=*leftchild;
 			node right=*rightchild;
 			if (opt==0){
 				valuefunc=[left,right](R v){
 					return (((left.express)._value)(left.valuefunc))(v)+
 					(((right.express)._value)(right.valuefunc))(v);
 				};
 				if (left.color==1||left.color==1){
 					difffunc=[left,right](R v){
 						return (((left.express)._diff)(left.valuefunc))(v)*(left.difffunc)(v)+
 						(((right.express)._diff)(right.valuefunc))(v)*(right.difffunc)(v);
 					};
 				}else{
 					difffunc=[](R v){return 0;};
 				}
 			}else if (opt==1){
 				valuefunc=[left,right](R v){
 					return (((left.express)._value)(left.valuefunc))(v)-
 					(((right.express)._value)(right.valuefunc))(v);
 				};
 				if (left.color==1||left.color==1){
 					difffunc=[left,right](R v){
 						return (((left.express)._diff)(left.valuefunc))(v)*(left.difffunc)(v)-
 						((right.express)._diff)(right.valuefunc)(v)*(right.difffunc)(v);
 					};
 				}else{
 					difffunc=[](R v){return 0;};
 				}
 			}else if (opt==2){
 				valuefunc=[left,right](R v){
 					return (((left.express)._value)(left.valuefunc))(v)*
 					(((right.express)._value)(right.valuefunc))(v);
 				};
 				if (left.color==1||left.color==1){
 					difffunc=[left,right](R v){
 						return 
 						(((right.express)._value)(right.valuefunc))(v)*
 						(((left.express)._diff)(left.valuefunc))(v)*(left.difffunc)(v)
 						
 						+
 						(((left.express)._value)(left.valuefunc))(v)*
 						(((right.express)._diff)(right.valuefunc))(v)*(right.difffunc)(v);
 					};
 				}else{
 					difffunc=[](R v){return 0;};
 				}
 			}else if (opt==3){
 				valuefunc=[left,right](R v){
 					return (((left.express)._value)(left.valuefunc))(v)/
 					(((right.express)._value)(right.valuefunc))(v);
 				};
 				if (left.color==1||right.color==1){
 				difffunc=[left,right](R v){
 						return (
 						(((right.express)._value)(right.valuefunc))(v)*
 						(((left.express)._diff)(left.valuefunc))(v)*(left.difffunc)(v)
 						
 						+
 						(((left.express)._value)(left.valuefunc))(v)*
 						(((right.express)._diff)(right.valuefunc))(v)*(right.difffunc)(v)
 						)/pow((((right.express)._value)(right.valuefunc))(v),2);
 					};
 				}else{
 					difffunc=[](R v){return 0;};
 				}
 			}else if (opt==-1){
 				exit(1);
 			}
 		}
 }