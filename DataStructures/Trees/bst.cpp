
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild = NULL;
    Node *rightChild=NULL;

    Node(char newData)
    {
        data = newData;
    }
};

class BinarySearchTree 
{
  public:
      Node *root=NULL;

      void insert(int newData)
      {
        if(root==NULL)
        {
            root = new Node(newData);
        }
        else{
            Node *insertPos =root;

            while(true)
            {
                if(insertPos->data>newData)
                {
                        insertPos= insertPos->leftChild;
                }
                else{
                    insertPos = insertPos->rightChild;
                }

                if(insertPos==NULL)
                {
                    break;
                }
            }

            insertPos=  new Node(newData);

            cout << root;
        }
      }
};


int main ()
{
      BinarySearchTree bst = BinarySearchTree();

      bst.insert(10);
      bst.insert(5);

    return 0;
}