#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

class BinaryTreeNode{
    int data;

    public:
    
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
    int getData(){
        return data;
    }
};

class QNode{
    public:
    BinaryTreeNode* queueNode;
    QNode* next;

    QNode(BinaryTreeNode* node){
        queueNode=node;
        next=nullptr;
    }
};

class Queue{
    QNode* front;
    QNode* rear;
    public:
    Queue(){
        front=nullptr;
        rear=nullptr;
    }

    void enqueue(BinaryTreeNode* node){
        QNode* newNode = new QNode(node);
        if(!rear){
            front=rear=newNode;
        }else{
        rear->next= newNode;
        rear= newNode;
        }
    }

    BinaryTreeNode* dequeue(){
        if(!front){
                return nullptr;
        }
        QNode* temp= front;
        front= front->next;

        if(!front){
            rear=nullptr;
        }

        BinaryTreeNode* treeNode= temp->queueNode;
        delete temp;
        return treeNode;

    }
    BinaryTreeNode* peek(){
        if(!front){
            cout<<"Queue underflow"<<endl;
            return nullptr;
        }
        return front->queueNode;
    }

    bool isEmpty(){
        return (front==nullptr);
    }
};


class BinaryTree{
    public:
    BinaryTreeNode* root;
    Queue q;

    BinaryTree(){
        root=nullptr;
    }

    void insertNode(int data){
        BinaryTreeNode* newNode= new BinaryTreeNode(data);
        if(!root){
            root= newNode;
            return;
        }

        q.enqueue(root);

        while(!q.isEmpty()){
            BinaryTreeNode* current= q.peek();
            q.dequeue();

            if(!current->left){
                current->left= newNode;
                // q.enqueue(current->left);
                return;
            }else{
                q.enqueue(current->left);
            }

            if(!current->right){
                current->right= newNode;
                // q.enqueue(current->right);
                return;
            }else{
                q.enqueue(current->right);
            }
        }


    }
    
    void preorder(BinaryTreeNode* node){
        if(!node){
            return;
        }else{
            cout<<node->getData()<<" ";
            preorder(node->left);
            preorder(node->right);
            
        }
    }

    void inorder(BinaryTreeNode* node){
        if(!node){
            return;
        }else{
        inorder(node->left);
        cout<<node->getData()<<" ";
        inorder(node->right);
        
        }
    }

    void postorder(BinaryTreeNode* node){
        if(!node){
            return;
        }else{
            postorder(node->left);
            postorder(node->right);
            cout<<node->getData()<<" ";
            
        }
    }

    void bfs(){
        if(!root){return ;}
        Queue q1;
        q1.enqueue(root);
        while(!q.isEmpty()){
            BinaryTreeNode* deleted= q1.dequeue();
            cout<<deleted->getData()<<" ";
            if(deleted->left){ q1.enqueue(deleted->left);}
            if(deleted->right){q1.enqueue(deleted->right);}
            
        
        }
        
    }

};


int main(){
    BinaryTree tree;

    tree.insertNode(10);
    tree.insertNode(20);
    tree.insertNode(30);
    tree.insertNode(40);
    tree.insertNode(50);
    cout<<"Preorder traversal:"<<endl;
    tree.preorder(tree.root);
    cout<<endl;

    cout<<"Inorder traversal:"<<endl;
    tree.inorder(tree.root);
    cout<<endl;

    cout<<"Postorder traversal:"<<endl;
    tree.postorder(tree.root);
    cout<<endl;

    cout<<"BFS traversal"<<endl;
    tree.bfs();

    return 0;
}