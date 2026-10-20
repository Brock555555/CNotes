#ifndef Tree_HPP
#define Tree_HPP
#include <queue>
#include <iostream>

template <typename T>
class Binary_Tree{
    private:
        struct Node{
            T value;
            Node* left;
            Node* right;
        };

        Node* root;

        //moved into private to allow function overloading, i.e. so we can call it with the root node
        void preorder(const Node* t){//performs a preorder traversal of the tree and prints its values
                    //visits first then goes down subtrees
                    if(t){
                        std::cout << t->value << " ";
                        preorder(t->left);
                        preorder(t->right);
                    }
                    else{
                        return;
                    }
                }
        
        void postorder(const Node* t){
            if(t){
                postorder(t->left);
                postorder(t->right);
                std::cout << t->value << " ";
            }
            else{
                return;
            }
        }

        void inorder(const Node* t){
            if(t){
                inorder(t->left);
                std::cout << t->value << " ";
                inorder(t->right);
            }
            else{
                return;
            }
        }

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

        //time for traversals
        //2 main types: depth and breadth
        //depth has inorder, preorder, postorder
        //inorder goes down entire left subtree, then root, then right subtree (producing sorted order in bst)
        //preorder starts with the root, left subtree, then right subtree
        //post order traverses left, then right, then root
        void preorder(){//performs a preorder traversal of the tree and prints its values
            preorder(root);
            std::cout << std::endl;
        }

        void postorder(){
            postorder(root);
            std::cout << std::endl;
        }

        void inorder(){
            inorder(root);
            std::cout << std::endl;
        }

        void levelorder(){//is technically breadth first
            std::queue<Node*> q;
            if(root){
                q.push(root);
                while(!q.empty()){
                    Node* current = q.front();
                    q.pop();
                    std::cout << current->value << " ";
                    if(current->left){q.push(current->left);}
                    if(current->right){q.push(current->right);}
                }
                std::cout << std::endl;
            }
            else{
                return;
            }
        }
};

//implement another version where each node is a tree itself

#endif