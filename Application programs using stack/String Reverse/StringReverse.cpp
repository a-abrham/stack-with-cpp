#include <iostream>
#include <cstring> // this header file is imported just for the strlen function that is used at line 47
using namespace std;

struct Stack
{
    int top;
    char *array;
};

struct Stack *createStack(int capacity)
{
    Stack *stack = new Stack();
    stack->top = -1;
    stack->array = new char[(capacity * sizeof(char))];

    return stack;
}

void push(Stack *stack, char item)
{
    int location = ++stack->top;
    stack->array[location] = item;
}

char pop(Stack *stack)
{
    int location = stack->top--;
    return stack->array[location];
}

void reverse(char str[])
{
    int n = strlen(str);

    Stack *stack = createStack(n);

    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);

    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

int main()
{
    char str[100];

    cout << "Enter the string you want to reverse: ";
    cin.getline(str, 100);

    reverse(str);

    cout << "Reversed string is:  " << str;

    return 0;
}