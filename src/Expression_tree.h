#ifndef FUNCTION_DIFFERENTIAL_LIB_EXPRESSION_TREE_H
#define FUNCTION_DIFFERENTIAL_LIB_EXPRESSION_TREE_H
#include <vector>
#include <map>
#include "functionaudi.h"
std::vector<int> merge(std::vector<int> a,std::vector<int> b);
class Basic_Expression_tree {
public:
    Basic_Expression_tree* lchild;
    Basic_Expression_tree* rchild;
    std::vector<int> related_tags;
    Basic_Expression_tree(Basic_Expression_tree* node1= nullptr,Basic_Expression_tree* node2= nullptr);
};
class function_expression_tree: public Basic_Expression_tree{
public:
    func_ express;
    std::map<int,function_expression_tree> findchilds();

};
class Function_Expression_tree: public Basic_Expression_tree{
public:
    functionaudi::Function composer;
    void update();
    std::map<int,function_expression_tree> diff();

};

#endif //FUNCTION_DIFFERENTIAL_LIB_EXPRESSION_TREE_H
