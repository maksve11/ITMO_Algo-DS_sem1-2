#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int hash_func(int n)
{
    return n % 10000001;
}

void insert(vector<vector<int>> &arr, int key, int n)
{
    for (int i = 0; i < arr[key].size(); i++)
    {
        if (arr[key][i] == n)
        {
            return;
        }
    }
    arr[key].push_back(n);
}

void del(vector<vector<int>> &arr, int key, int n)
{
    for (int i = 0; i < arr[key].size(); i++)
    {
        if (arr[key][i] == n)
        {
            arr[key].erase(arr[key].begin() + i);
            break;
        }
    }
}

bool ex(vector<vector<int>> &arr, int key, int n)
{
    bool flag = false;
    for (int i = 0; i < arr[key].size(); i++)
    {
        if (arr[key][i] == n)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    ifstream in("set.in");
    ofstream out("set.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> myset(10000001);
    string command;
    int n, key;
    bool flag;
    while (in >> command >> n)
    {
        key = hash_func(abs(n));
        if (command == "insert")
        {
            insert(myset, key, n);
        }
        else if (command == "delete")
        {
            del(myset, key, n);
        }
        else
        {
            flag = ex(myset, key, n);
            if (flag)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    return 0;
}