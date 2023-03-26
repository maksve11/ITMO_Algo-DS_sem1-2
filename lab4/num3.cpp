#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename yourtype>
class Stack
{
    class node
    {
    public:
        node *next;
        yourtype data;
        node(yourtype data = yourtype(), node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

    node *head;

public:
    Stack()
    {
        head = nullptr;
    }
    bool IsEmpty()
    {
        if (head == nullptr)
            return true;
        else
            return false;
    }
    void push(yourtype data)
    {
        if (IsEmpty())
            this->head = new node(data);
        else
        {
            node *temp = this->head;
            this->head = new node(data, temp);
            temp = nullptr;
        }
    }
    yourtype pop()
    {

        if (this->head != nullptr)
        {
            node *temp = head;
            yourtype result = this->head->data;
            head = head->next;
            delete[] temp;
            temp = nullptr;
            return result;
        }
    }
    yourtype peek()
    {
        return head->data;
    }
    ~Stack()
    {
        while (!IsEmpty())
            pop();
    }
};
bool checkbrackets(string s)
{
    Stack<char> St;
    char el;
    for (int i = 0; i < s.length(); ++i)
    {
        el = s[i];
        if (el == '(' || el == '[')
        {
            St.push(el);
        }
        else if (!St.IsEmpty())
        {
            if (el == ')' && St.peek() == '(')
            {
                St.pop();
            }
            else if (el == ']' && St.peek() == '[')
            {
                St.pop();
            }
            else
            {
                St.~Stack();
                return false;
            }
        }
        else
        {
            St.~Stack();
            return false;
        }
    }
    if (St.IsEmpty())
    {
        St.~Stack();
        return true;
    }
    else
    {
        St.~Stack();
        return false;
    }
    return true;
}
int main()
{
    ifstream in("brackets.in");
    ofstream out("brackets.out");
    in.tie(NULL)->sync_with_stdio(false);
    string s;
    while (getline(in, s))
    {
        if (checkbrackets(s))
            out << "YES\n";
        else
            out << "NO\n";
    }
    return 0;
}