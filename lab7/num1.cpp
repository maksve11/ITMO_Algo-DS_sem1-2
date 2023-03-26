#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream in("balance.in");
ofstream out("balance.out");

struct node
{   
    int value;
    int son[2];
    int balance;
    int height;
};

void checkbalance(vector<node> &arr, int node)
{
    if (node != -1)
    {
        checkbalance(arr, arr[node].son[1]);
        checkbalance(arr, arr[node].son[0]);
        arr[node].height = max(arr[arr[node].son[1]].height, arr[arr[node].son[0]].height) + 1;
        arr[node].balance = arr[arr[node].son[1]].height - arr[arr[node].son[0]].height;
    }
}

int main()
{
    in.tie(NULL)->sync_with_stdio(false);

    int n;
    in>>n;

    vector<node> arr(n);

    for (int i=0; i<n; i++)
    {
        in >> arr[i].value >> arr[i].son[0] >> arr[i].son[1];
        arr[i].height = 0;
        arr[i].son[0]--;
        arr[i].son[1]--;
    }

    checkbalance(arr, 0);

    for (int i=0; i<n; i++)
    out << arr[i].balance << endl;

    return 0;
}