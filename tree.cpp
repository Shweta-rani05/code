#include<iostream>
#include<queue>

using namespace std ; 

class Node {
    public:
    int data;
    Node* prev;
    Node* right;

    Node (int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;

    }

};

class Binarytree
{
   private:
   Node *root;

   public :
   binarytree(int data)
   {
    root = Node newdata(data);
   } 
  
}

void insertNode(int data)
{
    Node* newNode = new Node(data);
    while(!q.isEmpty())
    {
        Node temp=q.peek();
        if(temp.prev==Null){
            temp.prev=NewNode ;
            q.enque()=NewNode;
            break;
        }
        if(temp.next==Null){
            temp.next=Newnode;
            q.enque()=newNode;
            break;
        }
        if(temp.right==Null){
            temp.right=Newnode;
            q.enque()=newNode;
            break;
        }
        else{
            temp.next=q.deque();
        }
    }
}