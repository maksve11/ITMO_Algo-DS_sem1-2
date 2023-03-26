#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream in("addition.in");
ofstream out("addition.out");

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
int arr[2000001][3];

void link_nodes(int n)
{
    vector<node *> tt(n);
    for (int oldlink = n - 1; oldlink >= 0; --oldlink)
        tt[oldlink] = new node(arr[oldlink][0], (arr[oldlink][1] != -1 ? tt[arr[oldlink][1]] : nullptr), (arr[oldlink][2] != -1 ? tt[arr[oldlink][2]] : nullptr));
    root = (n ? tt[0] : nullptr);
}

void checkheight(node *x)
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
    checkheight(x);
    checkheight(help);
    return help;
}

node *leftRotate(node *x)
{
    node *help = x->right;
    x->right = help->left;
    help->left = x;
    checkheight(x);
    checkheight(help);
    return help;
}

int getBalance(node *x)
{
    return x->getHeight(x->right) - x->getHeight(x->left);
}

node *rebalance(node *x)
{
    checkheight(x);
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

int newlink = 1;
void insertionForarr(node *x, int oldlink)
{
    arr[oldlink][0] = x->value;
    if (x->left != nullptr)
    {
        ++newlink;
        arr[oldlink][1] = newlink;
        insertionForarr(x->left, newlink - 1);
    }
    else
        arr[oldlink][1] = 0;
    if (x->right != nullptr)
    {
        ++newlink;
        arr[oldlink][2] = newlink;
        insertionForarr(x->right, newlink - 1);
    }
    else
        arr[oldlink][2] = 0;
}

node *insert(node *x, int value)
{
    if (!x)
        return new node(value);
    if (x->value > value)
        x->left = insert(x->left, value);
    else
        x->right = insert(x->right, value);
    return rebalance(x);
}

int main()
{
    in.tie(NULL)->sync_with_stdio(false);
    int n, newElement;
    in >> n;
    if (n == 0)
    {
        in >> newElement;
        out << 1 << '\n';
        out << newElement << ' ' << 0 << ' ' << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        in >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][1]--;
        arr[i][2]--;
    }
    in >> newElement;

    link_nodes(n);
    root = insert(root, newElement);
    insertionForarr(root, 0);

    out << n + 1 << '\n';
    for (int i = 0; i <= n; ++i)
    {
        out << arr[i][0] << ' ' << arr[i][1] << ' ' << arr[i][2] << '\n';
    }
    return 0;
}