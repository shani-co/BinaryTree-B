#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <queue>
#include <list>
#include <string>
#include <deque>


using namespace std;

namespace ariel
{
    template <class T>
    class BinaryTree
    {
        struct Node
        {
        public:
            T val;
            Node *left;
            Node *right;

            Node(T val) : val(val), left(nullptr), right(nullptr) {}
        };
        Node *root;

    public:
        BinaryTree<T>() : root(nullptr) {}

        BinaryTree(const BinaryTree &other)
        {
            root = new Node(other.root->val);
            copy_subtree(root, other.root);
        }
        //help func for deep copy:
        void copy_subtree(Node *new_tree, Node *old_tree)
        {
            if (old_tree->left!=nullptr)
            {
                new_tree->left = new Node(old_tree->left->val);
                copy_subtree(new_tree->left, old_tree->left);
            }
            if (old_tree->right!=nullptr)
            {
                new_tree->right = new Node(old_tree->right->val);
                copy_subtree(new_tree->right, old_tree->right);
            }
        }

        BinaryTree &operator=(BinaryTree &&other) noexcept      //shallow copy as requested.
        {
            *this->root = other.root;
        }

        BinaryTree(BinaryTree &&other) noexcept             //move constructor as requested.
        {
            root = other.root;
            other.root = nullptr;
        }

        BinaryTree &operator=(const BinaryTree other)           // deep copy.
        {
            if(root!=nullptr){
                delete (this->root);
            }
            this->root = new Node(other.root->val);
            copy_subtree(root, other.root);
            return *this;
        }


        BinaryTree<T> add_root(T val)
        {
            if (root != nullptr)
            {
                root->val = val;
            }
            else
            {
                root = new Node(val);
            }
            return *this;
        }

        BinaryTree<T> &add_left(T val,T new_val)
        {
            Node *temp = find_node(val);
            if (temp->left == nullptr)
            {
                temp->left = new Node(new_val);
            }
            else
            {
                temp->left->val = new_val;
            }
            return *this;
        }

        BinaryTree<T> add_right(T val,T new_val)
        {
            Node *temp = find_node(val);
            if (temp->right == nullptr)
            {
                temp->right = new Node(new_val);
            }
            else
            {
                temp->right->val = new_val;
            }
            return *this;
        }

        Node *find_node(T val)
        {
            if (root != nullptr)
            {   if(root->val==val){
                    return root;
            }
                deque<Node*> queue;
                queue.push_back(root);
                Node *node = queue.back();
                while (!queue.empty())
                {
                    node = queue.back();
                    queue.pop_back();
                    if (node->val == val)
                    {
                        return node;
                    }
                    if (node->left)
                    {
                        queue.push_back(node->left);
                    }
                    if (node->right)
                    {
                        queue.push_back(node->right);
                    }

                }
                }
                throw("null root");
        }
        ~BinaryTree() {
            delete_tree(root);
             }

        void delete_tree(Node *root)
        {
        if(root!=nullptr)
        {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        }

        }

        class iterator{

        private:
            void postorder(Node* node){
                if(node != nullptr){
                postorder(node->left);
                postorder(node->right);
                node_queue.push(node);
                }
            }
            void preorder(Node* node){
                if(node != nullptr){
                node_queue.push(node);
                preorder(node->left);
                preorder(node->right);
                }
            }
            void inorder(Node* node){
                if(node != nullptr){
                inorder(node->left);
                node_queue.push(node);
                inorder(node->right);
                }
            }

        public:

            queue<Node*> node_queue;
            Node* node;

            iterator():node(nullptr){}

            iterator(Node* node):node(node){}

            iterator &operator++(){     // prefix increment
                if(node_queue.size()==1||node_queue.size()==0){
                    node=nullptr;
                }
                else{
                    node_queue.pop();
                    node = node_queue.front();
                }
                return *this;
            }

            iterator operator++(int){       // postfix increment
                auto temp = node_queue.front();
                iterator it(temp);
                ++*this;
                return it;
            }
            bool operator!=(const iterator &other) const {
                return !(node == other.node);
            }
            bool operator==(const iterator &other) const {
                return node == other.node;
            }
            T &operator*() const {
                return node->val;
            }
            T *operator->() const {
                return &node->val;
            }

            iterator(Node* root ,const string &action){
                if(root != nullptr){
                    if(action == "preorder") {
                        preorder(root);
                        }
                    if(action == "inorder") {
                        inorder(root);
                        }
                    if(action == "postorder") {
                        postorder(root);
                        }
                    node = node_queue.front();
                }
                else{
                    node =nullptr;
                }
            }

        };

        iterator begin(){
            return iterator{root,"inorder"};
        };
        iterator end(){
            return iterator{};
        };
        iterator begin_inorder(){
            return iterator{root,"inorder"};
        }
        iterator end_inorder(){
            return iterator{};
        }
        iterator begin_postorder(){
            return iterator{root,"postorder"};
        }
        iterator end_postorder(){
            return iterator{};
        }
        iterator begin_preorder(){
            return iterator{root,"preorder"};
        }
        iterator end_preorder(){
            return iterator{};
        }
    };

}