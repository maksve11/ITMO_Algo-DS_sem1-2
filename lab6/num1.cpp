#include <iostream>
 
typedef struct Node Node;
 
struct Node
{
    int value = 0;
    int height = 1;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
};
 
int main()
{
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int n, left, right, max_height;
    max_height = 0;
    std::cin >> n;
    Node a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].value >> left >> right;
        a[left - 1].parent = &a[i];
        a[right - 1].parent = &a[i];
        if (a[i].parent != nullptr)
            a[i].height = a[i].parent->height + 1;
        if (a[i].height > max_height)
            max_height = a[i].height;
    }
    std::cout << max_height;
    return 0;
}