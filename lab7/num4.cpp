#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream in("deletion.in");
ofstream out("deletion.out");

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

int arr[200001][3];
node *root = nullptr;

void link_nodes(int n)
{
    vector<node *> tt(n);
    for (int oldlink = n - 1; oldlink >= 0; --oldlink)
        tt[oldlink] = new node(arr[oldlink][0], (arr[oldlink][1] != -1 ? tt[arr[oldlink][1]] : nullptr), (arr[oldlink][2] != -1 ? tt[arr[oldlink][2]] : nullptr));
    root = (n ? tt[0] : nullptr);
}

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

int newlink = 1;
void deletionForarr(node *x, int oldlink)
{
    arr[oldlink][0] = x->value;
    if (x->left != nullptr)
    {
        ++newlink;
        arr[oldlink][1] = newlink;
        deletionForarr(x->left, newlink - 1);
    }
    else
        arr[oldlink][1] = 0;
    if (x->right != nullptr)
    {
        ++newlink;
        arr[oldlink][2] = newlink;
        deletionForarr(x->right, newlink - 1);
    }
    else
        arr[oldlink][2] = 0;
}

node *eraseMax(node *root)
{
    return root->right ? eraseMax(root->right) : root;
}

node *eraseMin(node *root)
{
    if (!root)
        return nullptr;
    if (root->right == nullptr)
        return root->left;
    root->right = eraseMin(root->right);
    return rebalance(root);
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
        delete x;
        if (!l)
            return r;
        node *min = eraseMax(l);
        min->left = eraseMin(l);
        min->right = r;
        return rebalance(min);
    }
    return rebalance(x);
}

int main()
{
    in.tie(NULL)->sync_with_stdio(false);
    int n, elementForRemoving;
    in >> n;

    if (n == 1)
    {
        out << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        in >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][1]--;
        arr[i][2]--;
    }
    in >> elementForRemoving;

    link_nodes(n);
    root = erase(root, elementForRemoving);
    deletionForarr(root, 0);

    out << n - 1 << '\n';
    for (int i = 0; i < n - 1; ++i)
    {
        out << arr[i][0] << ' ' << arr[i][1] << ' ' << arr[i][2] << '\n';
    }
    return 0;
}