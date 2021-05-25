#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int value)
    {
        data = value;
        right = NULL;
        left = NULL;
    }
};

class Tree
{
public:
    Node *head;

    void postorderTraverse(Node *parent)
    {

        if (parent != NULL)
        {
            postorderTraverse(parent->left);
            postorderTraverse(parent->right);
            cout << parent->data << "-> ";
        }
    }

    void preorderTraverse(Node *parent)
    {

        if (parent != NULL)
        {
            cout << parent->data << "-> ";
            preorderTraverse(parent->left);
            preorderTraverse(parent->right);
        }
    }

    void inorderTraverse(Node *parent)
    {
        if (parent != NULL)
        {
            inorderTraverse(parent->left);
            cout << parent->data << "-> ";
            inorderTraverse(parent->right);
        }
    }

    void insert(int newData)
    {
        Node *newNode = new Node(newData);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *traversal = head;
            Node *prev = NULL;

            while (traversal != NULL)
            {
                // to avoid dupplicate  key values
                if (traversal->data == newData)
                {
                    break;
                }
                prev = traversal;
                if (traversal->data > newData)
                {
                    traversal = traversal->left;
                    if (traversal == NULL)

                    {
                        prev->left = newNode;
                    }
                }
                else
                {
                    traversal = traversal->right;

                    if (traversal == NULL)

                    {
                        prev->right = newNode;
                    }
                }
            }
        }
    }

    Node *search(int key, Node *parent)
    {
        Node *retValue;

        if (parent == NULL || (parent != NULL && parent->data == key))
        {
            retValue = parent;
        }
        else
        {

            if (parent->data > key)
            {
                retValue = search(key, parent->left);
            }
            else
            {
                retValue = search(key, parent->right);
            }
        }
        return retValue;
    }
};

int main()
{

    Tree tree = Tree();
    tree.insert(27);
    tree.insert(14);
    tree.insert(35);
    tree.insert(10);
    tree.insert(19);
    tree.insert(31);
    tree.insert(42);
    cout << "Inorder Traversal \n";
    tree.inorderTraverse(tree.head);
    cout << "\n Postorder Traversal \n";
    tree.postorderTraverse(tree.head);
    cout << "\n Preorder Traversal \n";
    tree.preorderTraverse(tree.head);

    Node *searchedNode = tree.search(19, tree.head);

    return 0;
}