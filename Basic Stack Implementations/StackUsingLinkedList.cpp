#include <iostream>
using namespace std;
struct Node
{
    int data;
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
void push(int value)
{
    struct Node *newnode = new Node;
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    if (isEmpty())
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

int peek()
{
    return top->data;
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
    int option, value;
K:
    cout << "Which stack operation do you want to perform ? " << endl;
    cout << "1. Add new element to the stack || Push ()" << endl;
    cout << "2. Return top element || Peak()" << endl;
    cout << "3. Remove top element of the stack || Pop()" << endl;
    cout << "4. Clear all elements from the stack || makeEmpty()" << endl;
    cout << "5. Find stack size || getSize()" << endl;
    cout << "6. Exit" << endl;
    cin >> option;
    if (option == 1)
    {
        cout << "Enter the value you want to add : " << endl;
        cin >> value;
        push(value);
        goto K;
    }

    else if (option == 2)
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            goto K;
        }
        else
        {
            cout << "The top value in the stack is :" << peek() << endl;
            goto K;
        }
    }

    else if (option == 3)
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            goto K;
        }
        else
        {
            pop();
            goto K;
        }
    }

    else if (option == 4)
    {
        cout << "Successfully removed all elements from the stack." << endl;
        goto K;
    }

    else if (option == 5)
    {
        cout << "Stack size: " << count() << endl;
        goto K;
    }

    else if (option == 6)
    {
        return 0;
    }
    else
    {
        cout << "Invalid input...try again" << endl;
        goto K;
    }
}