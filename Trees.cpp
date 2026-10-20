#include "Trees.hpp"
#include <string>

int main(){

    Binary_Tree<std::string> Btree("Root_Root");
    Btree.regular_insert("Left_Node");
    Btree.regular_insert("Right_Node");
    Btree.preorder();
    Btree.postorder();
    Btree.inorder();
    Btree.levelorder();

    Binary_Tree<int> NBtree(40);
    NBtree.regular_insert(20);
    NBtree.regular_insert(60);
    NBtree.regular_insert(10);
    NBtree.regular_insert(30);
    NBtree.regular_insert(50);
    NBtree.regular_insert(70);
    
    NBtree.preorder();
    NBtree.postorder();
    NBtree.inorder();
    NBtree.levelorder();
    return 0;
}