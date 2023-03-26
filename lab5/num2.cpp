#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream in("map.in");
ofstream out("map.out");

class tablehash
{
    int buck;
    list<pair<string, string>> *table;

public:
    tablehash(int count);

    long long hash_func(string n)
    {
        int key = 1e5 / 2;
        long long value = 0;
        short prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

        for (int i = 0; i < n.size(); i++)
        {
            value += int(n[i]) * prime[19 - i];
        }
        return (value) % key;
    }

    bool ex(string n);

    void get(string n);

    void ins(string key, string n);

    void er(string key);
};

tablehash::tablehash(int count)
{
    this->buck = count;
    table = new list<pair<string, string>>[buck];
}

bool tablehash::ex(string n)
{
    long long ind = hash_func(n);
    bool flag = false;
    for (list<pair<string, string>>::iterator i = table[ind].begin(); i != table[ind].end(); i++)
    {
        if (i->first == n)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void tablehash::get(string n)
{
    bool flag = ex(n);
    if (flag == false)
    {
        out << "none" << endl;
        return;
    }
    else
    {
        long long ind = hash_func(n);
        for (list<pair<string, string>>::iterator i = table[ind].begin(); i != table[ind].end(); i++)
        {
            if (i->first == n)
            {
                out << i->second << endl;
                return;
            }
        }
    }
}

void tablehash::ins(string key, string n)
{
    if (ex(key))
    {
        long long ind = hash_func(key);
        for (list<pair<string, string>>::iterator i = table[ind].begin(); i != table[ind].end(); i++)
            if (i->first == key)
                i->second = n;
        return;
    }
    long long ind = hash_func(key);

    table[ind].push_back(make_pair(key, n));
}

void tablehash::er(string key)
{
    if (!ex(key))
        return;

    list<pair<string, string>>::iterator i;
    long long ind = hash_func(key);
    for (i = table[ind].begin(); i != table[ind].end(); i++)
    {
        if (i->first == key)
            break;
    }

    if (i != table[ind].end())
        table[ind].erase(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string command, key, value;
    tablehash th(int(1e5)/2);
    while (in >> command)
    {
        if (command == "put")
        {
            in >> key >> value;
            th.ins(key, value);
        }
        else if (command == "delete")
        {
            in >> key;
            th.er(key);
        }
        else if (command == "get")
        {
            in >> key;
            th.get(key);
        }
    }
    return 0;
}