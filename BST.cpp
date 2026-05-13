#include<iostream>
#include"BST.h"
using namespace std;

BST::Node::Node(int value):key(value),left(nullptr),right(nullptr){}

BST::Node* BST::insert(Node* node,int key){
    if (node == nullptr){
        return new Node(key);
    }   
    if (key < node->key){
        node->left = insert(node->left,key);
    }
    else if (key > node->key){
        node->right = insert(node->right,key);
    }
    return node;
}
bool BST::search(Node* node , int key)const{
    if (node == nullptr){
        return false;
    }
    if (node->key == key){
        return true;
    }
    if (key< node->key){
        return search(node->left,key);
    }
    else if (key > node->key){
        return search(node->right,key);
    }
    return false;
}
BST::Node* BST::findMin(Node* node)const{
    if (node == nullptr){
        return nullptr;
    }
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}
BST::Node* BST::findMax(Node* node)const{
    if (node == nullptr){
        return nullptr;
    }
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}
BST::Node* BST::remove(Node* node,int key){
    if(node == nullptr){
        return nullptr;
    }
    if(key<node->key){
        node->left = remove(node->left,key);
    }
    else if (key > node->key){
        node->right = remove(node->right,key);
    }
    else{
        if (node->left == nullptr && node->right == nullptr){
            delete node;
            return nullptr;
        }
        if (node ->left == nullptr && node->right != nullptr){
            Node* temp = node->right ;
            delete node;
            return temp;
        }
        if (node ->left != nullptr && node->right == nullptr){
            Node* temp = node->left ;
            delete node;
            return temp;
        }
        if (node-> left != nullptr && node->right != nullptr){
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = remove(node->right,temp->key);
        }
    }
    return node;
}
void BST::inorder(Node* node)const{
    if (node == nullptr){
        return;
    }
    inorder(node->left);
    cout<<node->key<<' ';
    inorder(node->right);
}
void BST::destroy(Node* node){
    if (node == nullptr){
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}
BST::BST(){
    root = nullptr;
}
BST::~BST(){
    destroy(root);
}
void BST::insert(int key){
    root = insert(root,key);
}
bool BST::search(int key)const{
    return search(root,key);
}
void BST::remove(int key){
    root = remove(root,key);
}
void BST::inorder()const{
    inorder(root);
}
int BST::minValue()const{
    Node* temp = findMin(root);
    return temp->key;
}
int BST::maxValue()const{
    Node* temp = findMax(root);
    return temp->key;
}
