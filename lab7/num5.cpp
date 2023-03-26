#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream in("avlset.in");
ofstream out("avlset.out");

class node
{
public:
    int value;
    int height;
    node *left;
    node *right;

    int getHeight(node *x)
    {
        return x ? x->height : 0;
    }

    node(int value, node *left = nullptr, node *right = nullptr)
    {
        this->value = value;
        this->left = left;
        this->right = right;
        height = max(getHeight(left), getHeight(right)) + 1;
    }
};

node *root = nullptr;

void checkHeight(node *x)
{
    int left = x->getHeight(x->left);
    int right = x->getHeight(x->right);
    x->height = (left > right ? left : right) + 1;
}

node *rightRotate(node *x)
{
    node *help = x->left;
    x->left = help->right;
    help->right = x;
    checkHeight(x);
    checkHeight(help);
    return help;
}

node *leftRotate(node *x)
{
    node *help = x->right;
    x->right = help->left;
    help->left = x;
    checkHeight(x);
    checkHeight(help);
    return help;
}

int getBalance(node *x)
{
    return x->getHeight(x->right) - x->getHeight(x->left);
}

node *rebalance(node *x)
{
    checkHeight(x);
    if (getBalance(x) == 2)
    {
        if (getBalance(x->right) < 0)
            x->right = rightRotate(x->right);
        return leftRotate(x);
    }
    if (getBalance(x) == -2)
    {
        if (getBalance(x->left) > 0)
            x->left = leftRotate(x->left);
        return rightRotate(x);
    }
    return x;
}

node *getMax(node *root)
{
    return root->right ? getMax(root->right) : root;
}

node *eraseMax(node *root)
{
    if (!root)
        return nullptr;
    if (root->right == nullptr)
        return root->left;
    root->right = eraseMax(root->right);
    return rebalance(root);
}

node *insert(node *x, int value)
{
    if (!x)
        return new node(value);
    if (x->value > value)
        x->left = insert(x->left, value);
    else if (x->value < value)
        x->right = insert(x->right, value);
    return rebalance(x);
}

node *erase(node *x, int value)
{
    if (!x)
        return nullptr;
    if (value < x->value)
        x->left = erase(x->left, value);
    else if (value > x->value)
        x->right = erase(x->right, value);
    else
    {
        node *l = x->left;
        node *r = x->right;
        delete (x);
        if (!l)
            return r;
        node *max = getMax(l);
        max->left = eraseMax(l);
        max->right = r;
        return rebalance(max);
    }
    return rebalance(x);
}

bool exists(node *x, int key)
{
    if (!x)
        return false;
    if (x->value > key)
        exists(x->left, key);
    else if (x->value < key)
        exists(x->right, key);
    else
        return x->value == key;
}

int main()
{
    in.tie(NULL)->sync_with_stdio(false);
    int n, num;
    in >> n;
    char command;
    for (int i = 0; i < n; ++i)
    {
        in >> command >> num;
        if (command == 'A')
        {
            root = insert(root, num);
            if (root != nullptr)
                out << getBalance(root) << endl;
            else
                out << '0' << endl;
        }
        if (command == 'D')
        {
            root = erase(root, num);
            if (root != nullptr)
                out << getBalance(root) << endl;
            else
                out << '0' << endl;
        }
        if (command == 'C')
        {
            if (exists(root, num))
                out << 'Y' << endl;
            else
                out << 'N' << endl;
        }
    }
    return 0;
}