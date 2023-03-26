#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct tree
{
    int value;
    int left;
    int right;
};

class node
{
public:
    int height;
    int value;
    node *left;
    node *right;

    int getHeight(node *x)
    {
        return x ? x->height : 0;
    }

    node(int value, int height = 0, node *left = nullptr, node *right = nullptr)
    {
        this->value = value;
        this->height = max(getHeight(left), getHeight(right)) + 1;
        this->left = left;
        this->right = right;
    }
};

void checkHeight(node *x)
{
    int left = x->getHeight(x->left);
    int right = x->getHeight(x->right);
    x->height = (right >= left ? right : left) + 1;
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

node *rightRotate(node *x)
{
    node *help = x->left;
    x->left = help->right;
    help->right = x;
    checkHeight(x);
    checkHeight(help);
    return help;
}

int getFactor(node *x)
{
    return x->getHeight(x->right) - x->getHeight(x->left);
}

node *rebalance(node *x)
{
    checkHeight(x);
    if (getFactor(x->right) < 0)
        x->right = rightRotate(x->right);
    return leftRotate(x);
}

node *root = nullptr;

void link_nodes(vector<tree> &arr)
{
    vector<node *> ff(arr.size());

    for (int i = ff.size() - 1; i >= 0; i--)
    {
        ff[i] = new node(arr[i].value, 1, (arr[i].left != -1 ? ff[arr[i].left] : nullptr), arr[i].right != -1 ? ff[arr[i].right] : nullptr);
    }
    root = ff[0];
}

int newlink = 1;
void bigLeftRotate(vector<tree> &arr, node *root, int oldlink)
{
    arr[oldlink].value = root->value;
    if (root->left == nullptr)
        arr[oldlink].left = 0;
    else
    {
        ++newlink;
        arr[oldlink].left = newlink;
        bigLeftRotate(arr, root->left, newlink - 1);
    }
    if (root->right == nullptr)
        arr[oldlink].right = 0;
    else
    {
        ++newlink;
        arr[oldlink].right = newlink;
        bigLeftRotate(arr, root->right, newlink - 1);
    }
}

int main()
{
    ifstream in("rotation.in");
    ofstream out("rotation.out");

    in.tie(NULL)->sync_with_stdio(false);

    int n;
    in >> n;

    vector<tree> arr(n);

    for (int i = 0; i < n; i++)
    {
        in >> arr[i].value >> arr[i].left >> arr[i].right;
        arr[i].right--;
        arr[i].left--;
    }

    link_nodes(arr);
    root = rebalance(root);
    bigLeftRotate(arr, root, 0);

    out << n << endl;
    for (int i = 0; i < n; i++)
    {
        out << arr[i].value << ' ' << arr[i].left << ' ' << arr[i].right << '\n';
    }

    return 0;
}