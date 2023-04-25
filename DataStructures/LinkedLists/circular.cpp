#include <iostream>
using namespace std;

class Node
{
public:
    char ch;
    Node *next = NULL;

    Node(char newData)
    {
        ch = newData;
    }
};

class SinglyCircularList
{
public:
    Node *last = NULL;//pointing to last node

    void deleteNode(char key)
    {
        if (last != NULL && last->next->ch == key)
        {

            Node *del = last->next;
            last->next = del->next;

            free(del);
        }
        else
        {

            Node *traversal = last;

            do
            {

                if (traversal != NULL && traversal->next->ch == key)
                {
                    Node *del = traversal->next;
                    traversal->next = del->next;
                    break;
                }
                traversal = traversal->next;
            } while (traversal != last);
        }
    }

    void insert(char newData)

    {
        Node *newNode = new Node(newData);

        if (last == NULL)
        {

            newNode->next = newNode;
            last = newNode;
        }

        else
        {

            Node *temp = last->next;

            newNode->next = temp;
            last->next = newNode;
            last = newNode;
        }
    }

    void display()
    {
        Node  *traversal =  last;

        do{
            cout<<traversal->ch<<" ";
            traversal = traversal->next;
        }while (traversal!=last);
        
        
    }
};

int main()
{

    SinglyCircularList scl = SinglyCircularList();

    scl.insert('H');
    scl.insert('E');
    scl.insert('L');
    scl.insert('L');
     
    scl.insert('0');
  
    scl.display();
    return 0;
}