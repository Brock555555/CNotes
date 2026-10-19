#include "Trees.hpp"
#include <string>

int main(){

    Binary_Tree<std::string> Btree("Root_Root");
    Btree.regular_insert("Left_Node");
    Btree.regular_insert("Right_Node");
    return 0;
}