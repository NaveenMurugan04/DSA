
#include <iostream>
using namespace std;

class Node
{
public:
    char ch;
    Node *next = NULL;
    Node *prev = NULL;

    Node(char newData)
    {
        ch = newData;
    }
};

class DoublyCircularLinkedList
{
public:
    Node *head = NULL;

    void insertAtBeginning(char ch)
    {
        if (head == NULL)
        {
            head = new Node(ch);
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *temp = head->prev;
            Node *newNode = new Node(ch);

            temp->next = newNode;

            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(char ch)
    {
        if (head == NULL)
        {
            head = new Node(ch);
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *temp = head->prev;
            Node *newNode = new Node(ch);
            temp->next = newNode;

            newNode->next = head;

            newNode->prev = temp;
            head->prev = newNode;
        }
    }
    void insertAfter(char pos, char newChar)
    {

        Node *insertNode = head;

        while (insertNode->ch != pos)
        {
            insertNode = insertNode->next;
        }

        Node *newNode = new Node(newChar);

        newNode->prev = insertNode;
        newNode->next = insertNode->next;
        insertNode->next->prev = newNode;
        insertNode->next = newNode;
    }
       void deleteNode(char ch)
       {

          Node *deletionNode = head;

        while (deletionNode->ch != ch)
        {
            deletionNode = deletionNode->next;
        }

        Node * nextNode = deletionNode->next;

        Node * prevNode = deletionNode->prev;

        prevNode->next=nextNode;
        nextNode->prev =prevNode;


        free(deletionNode);
           
       }

    void display()
    {
        Node *traversal = head;

        do
        {
            cout << traversal->ch << "\n";
            traversal = traversal->next;
        } while (traversal != head);
    }
};

int main()
{

    DoublyCircularLinkedList dcl = DoublyCircularLinkedList();

    dcl.insertAtBeginning('0');

    dcl.insertAtBeginning('L');
    dcl.insertAtBeginning('L');
    dcl.insertAtBeginning('E');
    dcl.insertAtBeginning('H');

    dcl.insertAtEnd(' ');
    dcl.insertAfter(' ', 'W');
    dcl.insertAtEnd('O');
    dcl.insertAtEnd('R');
    dcl.insertAfter('R', 'L');
    dcl.insertAtEnd(' D');
    dcl.insertAfter(' ', 'C');
    dcl.insertAfter('C', '+');
    dcl.insertAfter('+', '+');

    dcl.deleteNode('+');
      dcl.deleteNode('+');
           dcl.deleteNode('C');
    dcl.display();
    return 0;
}