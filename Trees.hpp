#ifndef Tree_HPP
#define Tree_HPP
#include <queue>

template <typename T>
class Binary_Tree{
    private:
        struct Node{
            T value;
            Node* left;
            Node* right;
        };

        Node* root;
    public:
        Binary_Tree(){
            root = nullptr;//default constructor
        }
        Binary_Tree(T root_value){
            root = new Node{root_value, nullptr, nullptr};
        }
        void deconstruct_helper(Node* node){
            if(node){//not a nullptr
                deconstruct_helper(node->left);
                deconstruct_helper(node->right);
                delete node;
            }
            else{
                return;
            }

        }
        ~Binary_Tree(){
            deconstruct_helper(root);
        }
        void regular_insert(T value){//this will be a left to right, top to bottom insert
            if (root == nullptr){
                root = new Node{value, nullptr, nullptr};
                return;
            }
            Node* new_node = new Node{value, nullptr, nullptr};
            std::queue<Node*> q;//need to see all pointers on top down
            q.push(root);
            while(!q.empty()){
                Node* current = q.front();
                q.pop();
                if(current->left == nullptr){
                    current->left = new_node;
                    return;
                }
                else{
                    q.push(current->left);
                }
                if(current->right == nullptr){
                    current->right = new_node;
                    return;
                }
                else{
                    q.push(current->right);
                }
            }
        }
};

#endif