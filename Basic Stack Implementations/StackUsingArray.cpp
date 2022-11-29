#include <iostream>
using namespace std;
const int arraySize = 10;
int top = -1, array[arraySize];
// We have declared the array and the top variable globally.
// so that we don't have to pass them everytime we call functions.

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool isFull()
{
    if (top == arraySize - 1)
        return true;
    else
        return false;
}

void push(int value)
{
    if (!isFull)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        array[top] = value;
    }
}

void pop()
{
    int temp = array[top];
    array[top] = 0;
    top--;
    cout << "The popped element is " << temp << endl;
}

int count()
{
    return (top + 1);
}

int peek()
{
    return array[top];
}

void display()
{
    if (isEmpty())
        cout << "Stack underflow" << endl;
    else
    {
        cout << "The values stored in the stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << "\t";
        }
        cout << endl;
    }
}

void makeEmpty()
{
    top = -1; // this makes the stack empty, since
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
    cout << "6. Print all elements" << endl;
    cout << "7. Exit" << endl;
    cin >> option;
    if (option == 1)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            goto K;
        }
        else
        {
            cout << "Enter the value you want to add : " << endl;
            cin >> value;
            push(value);
            goto K;
        }
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
        makeEmpty();
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
        display();
        goto K;
    }

    else if (option == 6)
    {
        return 0;
    }
}