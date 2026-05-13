#pragma once
#include<iostream>

class BST{
private:
    struct Node{
        int key;
        Node* left;
        Node* right;
        Node(int value);
    };
    Node* root;
    Node* insert(Node* node,int key);
    bool search(Node* node, int key)const;
    Node* findMin(Node* node)const;
    Node* findMax(Node* node)const;
    Node* remove(Node* node,int key);
    void inorder(Node* node)const;
    void destroy(Node* node);

public:
    BST();
    ~BST();
    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void inorder()const;
    int minValue()const;
    int maxValue()const;

};
