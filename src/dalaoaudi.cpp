#include <string>
#include <set>
using namespace std;
union func_;
enum basic_func_T{
	non_basic_func,const_func_T,id_func_T,sin_func_T,cos_func_T
};
struct sum_func{
	static const basic_func_T func_type=non_basic_func;
	set<int> related_vars;
	func_ f,g;
	sum_func(func_ a, func_ b){
		this->related_vars=a.related_vars+b.related_vars;
		this->f=a;
		this->g=b;
	}
	func_ der(int var_id){
		bool flag_f=f.related_vars.has(var_id);
		bool flag_g=g.related_vars.has(var_id);
		if(flag_f){
			if(flag_g){
				return sum_func(f.der(var_id),g.der(var_id));
			}else{
				return f.der(var_id);
			}
		}else{
			if(flag_g){
				return g.der(var_id);
			}else{
				return const_func(0);
			}
		}
	}
}
struct prod_func{
	basic_func_T func_type=non_basic_func;
	set<int> related_vars;
	func_ f,g;
	prod_func(func_ a, func_ b){
		this->related_vars=a.related_vars+b.related_vars;
		this->f=a;
		this->g=b;
	}
	func_ der(int var_id){
		bool flag_f=f.related_vars.has(var_id);
		bool flag_g=g.related_vars.has(var_id);
		if(flag_f){
			if(flag_g){
				return sum_func(prod_func(f.der(var_id),g),prod_func(f,g.der(var_id)));
			}else{
				return prod_func(f.der(var_id),g);
			}
		}else{
			if(flag_g){
				return prod_func(f,g.der(var_id));
			}else{
				return const_func(0);
			}
		}
	}
}

union func_;
struct const_func{
	basic_func_T func_type=const_func_T;
	set<int> related_vars;
	double val;
	const_func(double val){
		this->val=val;
	}
	func_ der(int var_id){
		return const_func(0);
	}
};
struct id_func{
	basic_func_T func_type=id_func_T;
	set<int> related_vars;
	int var_id;
	string var_name;
	static int acc=0;
	id_func(string var_name){
		is_const=false;
		related_vars.push(var_id);
		this->var_name=var_name;
		var_id=acc++;
	}
	func_ der(int var_id){
		if(var_id==this->var_id){
			return const_func(1);
		}else{
			return const_func(0);
		}
	}
};
struct sin_func;
struct cos_func;
struct sin_func{
	basic_func_T func_type=sin_func_T;
	set<int> related_vars;
	func_ x;
	sin_func(func_ a){
		related_vars=a.related_vars;
	}
	func_ der(int var_id){
		if(related_vars.has(var_id)){
			return prod_func(cos_func(x),x.der(var_id));
		}else{
			return const_func(0);
		}
	}
}
struct cos_func{
	basic_func_T func_type=sin_func_T;
	set<int> related_vars;
	func_ x;
	sin_func(func_ a){
		related_vars=a.related_vars;
	}
	func_ der(int var_id){
		if(related_vars.has(var_id)){
			return prod_func(prod_func(const_func(-1),sin_func(x)),x.der(var_id));
		}else{
			return const_func(0);
		}
	}
}




union func_{
	struct{
		basic_func_T func_type;
		bool is_const;
		(func_(int))* der;
	}
	non_basic_func non_basic_func_comp;
	sum_func sum_func_comp;
	prod_func prod_func_comp;
	const_func const_func_comp;
	id_func id_func_comp;
	sin_func sin_func_comp;
	cos_func cos_func_comp;
};