#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
struct Node
{
    string data;
    struct Node *next;
};
struct Node *top = NULL;

bool isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
void push(string value)
{
    struct Node *newnode = new Node;
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    top = top->next;
}

void peek()
{
    cout << top->data;
}

int count()
{
    int count = 0;
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        count++;
        ptr = top->next;
    }
    return count;
}
int main()
{
    int option;
    string str;
    cout << "E T H I O  P I A N     B U S     T R A N S P O R T" << endl;
    cout << "   R E T U R N     P A T H      A N A L I Z E R" << endl;
    cout << "================================================== /n" << endl;
    cout << "Curent location " << endl;
    cin >> str;
    push(str);

k:
    cout << "1. Add your next stop" << endl;
    cout << "2. View return path" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    if (option == 1)
    {
        cout << "Enter destination name: ";
        cin >> str;
        push(str);
        goto k;
    }

    else if (option == 2)
    {
        cout << "Your return path from ";
        peek();
        pop();
        cout << " is: ";
        while (top != NULL)
        {
            peek();
            pop();
            cout << "  ";
        }
    }
}