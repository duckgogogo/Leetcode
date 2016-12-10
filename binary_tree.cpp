//
//  main.cpp
//  BinaryTree
//
//  Created by Shan He on 12/8/16.
//  Copyright © 2016 Shan He. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

// the defination of binary tree class

class BinaryTree{
private:
    struct Node{
        // the node's left and right pointer and its value
        Node *left, *right;
        int data;
        // the operation of the node, destructor & constructor
        Node():left(NULL),right(NULL){}
        Node(int item,Node *L = NULL, Node *R = NULL):data(item),left(L),right(R){}
        ~Node(){}
    };
    Node *root;
public:
    BinaryTree():root(NULL){}
    BinaryTree(const int &value){root = new Node(value);}
    BinaryTree(Node *p){root = p;}
    ~BinaryTree(){clear();}
    int getRoot() const{return root->data;}
    int getLeft() const{return root->left->data;}
    int getRight() const{return root->right->data;}
    void makeTree(const int &x, BinaryTree &lt, BinaryTree &rt)
    {
        root = new Node(x,lt.root,rt.root);
        lt.root = NULL;rt.root = NULL;
    }
    void delLeft()
    {
        BinaryTree tmp = root->left;
        root->left = NULL;
        tmp.clear();
    }
    void delRight()
    {
        BinaryTree tmp = root->right;
        root->right = NULL;
        tmp.clear();
    }
    bool isEmpty() const{return root == NULL;}
    void clear()
    {
        if(root!=NULL) clear(root);
        root = NULL;
    }
    int size() const{
        return size(root);
    }
    int height() const{
        return height(root);
    }
    void preOrder()
    {
        preOrder(root);
    }
    void postOrder()
    {
        postOrder(root);
    }
    void midOrder()
    {
        midOrder(root);
    }
    void createTree(int flag)
    {
        queue<Node *> que;
        Node *tmp;
        int x, ldata, rdata;
        // construct the tree, flag means blank
        cout<<"give me the root: ";
        cin>>x;
        root = new Node(x);
        que.push(root);
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            cout<<"type in "<<tmp->data<<"'s two sons: ";
            cin>>ldata>>rdata;
            if(ldata != flag)
                que.push(tmp->left = new Node(ldata));
            if(rdata != flag)
                que.push(tmp->right = new Node(rdata));
        }
        cout<<"create completed!\n"<<endl;
    }
private:
    void clear(Node *t)
    {
        if(t->left!=NULL) clear(t->left);
        if(t->right!=NULL) clear(t->right);
        delete t;
    }
    int height(Node *t) const
    {
        if(t == NULL) return 0;
        else return 1 + max(height(t->left),height(t->right));
    }
    int size(Node *t) const
    {
        if(t==NULL) return 0;
        else return 1+size(t->left)+size(t->right);
    }
    void preOrder(Node *t)
    {
        if(t!=NULL){
            cout<<t->data<<' ';
            preOrder(t->left);
            preOrder(t->right);
        }
    }
    void postOrder(Node *t)
    {
        if(t!=NULL){
            postOrder(t->left);
            postOrder(t->right);
            cout<<t->data<<' ';
        }
    }
    void midOrder(Node *t)
    {
        if(t!=NULL){
            midOrder(t->left);
            cout<<t->data<<' ';
            midOrder(t->right);
        }
    }
};

int main() {
    BinaryTree tree, tree1(1),tree2;
    tree.createTree(-1);
    cout<<"The height of the tree is: "<<tree.height()<<endl;
    cout<<"The size of the tree is: "<<tree.size()<<endl;
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    tree2.makeTree(67, tree, tree1);
    cout<<endl;
    cout<<"height is: "<<tree2.height()<<endl;
    cout<<"size is: "<<tree2.size()<<endl;
    tree2.preOrder();
    tree2.midOrder();
    tree2.postOrder();
    return 0;
}
