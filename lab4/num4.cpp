#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct stack
{
    int data;
    struct stack *link;
};

struct stack *top;

void push(long long data)
{
    struct stack *t;
    t = new stack();
    if (!t)
    {
        cout << "Stack Overflow";
        exit(1);
    }
    t->data = data;
    t->link = top;
    top = t;
}
long long isEmpty()
{
    return top == NULL;
}

long long peek()
{
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

long long pop()
{
    struct stack *temp;
    temp = top;
    top = top->link;
    temp->link = NULL;
    return temp->data;
    free(top);
}
int main()
{
    ifstream in("postfix.in");
    ofstream out("postfix.out");
    string s;
    char el;
    getline(in, s);
    for (int i = 0; i < s.length(); i++)
    {
        el = s[i];
        if (el == ' ')
            continue;
        long long a, b;
        switch (el)
        {
        case '+':
            b = pop();
            a = pop();
            push(a + b);
            break;
        case '-':
            b = pop();
            a = pop();
            push(a - b);
            break;
        case '*':
            b = pop();
            a = pop();
            push(a * b);
            break;
        default:
            push(el - '0');
            break;
        }
    }
    out << peek() << endl;
    return 0;
}