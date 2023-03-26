#include <iostream>

using namespace std;
typedef struct Node
{
    int value = 0;
    int min, max;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
} Node;

int main()
{
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int n, left, right;
    cin >> n;
    Node a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].value >> left >> right;
        if (left != 0)
        {
            a[i].left = &a[left - 1];
            a[i].left->parent = &a[i];
        }
        if (right != 0)
        {
            a[i].right = &a[right - 1];
            a[i].right->parent = &a[i];
        }
        if (i != 0)
        {
            if (a[i].parent == nullptr)
            {
                cout << "NO";
                return 0;
            }
            if (a[i].parent->value == a[i].value)
            {
                cout << "NO";
                return 0;
            }
            else if (a[i].parent->value > a[i].value && &a[i] != a[i].parent->left)
            {
                cout << "NO";
                return 0;
            }
            else if (a[i].parent->value < a[i].value && &a[i] != a[i].parent->right)
            {
                cout << "NO";
                return 0;
            }
            else if (a[i].parent->value > a[i].value && a[i].value <= a[i].parent->min)
            {
                cout << "NO";
                return 0;
            }
            else if (a[i].parent->value < a[i].value && a[i].value >= a[i].parent->max)
            {
                cout << "NO";
                return 0;
            }
            if (a[i].parent->value > a[i].value)
            {
                a[i].max = a[i].parent->value;
                a[i].min = a[i].parent->min;
            }
            else if (a[i].parent->value < a[i].value)
            {
                a[i].min = a[i].parent->value;
                a[i].max = a[i].parent->max;
            }
        }
        else
        {
            a[i].min = INT32_MIN;
            a[i].max = INT32_MAX;
        }
    }
    cout << "YES";
    return 0;
}