#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream in("linkedmap.in");
ofstream out("linkedmap.out");

class linkn
{
public:
    pair<string, string> tt;

    linkn *next;
    linkn *prev;

    linkn(pair<string, string> tt, linkn *prev, linkn *next = nullptr)
    {
        this->tt = tt;
        this->prev = prev;
        this->next = next;
    }
};

class tablehash
{
    int buck;
    list<linkn> *table;
    linkn *lastadd;
    linkn *prelastadd;

public:
    tablehash(int count);

    long long hash_func(string n)
    {
        int key = 1e5 / 2;
        int p = 1;
        long long value = 0;

        for (int i = 0; i < n.size(); i++)
        {
            value = (((int)n[i] * p) + value) % key;
            p *= 2;
        }
        return (value);
    }

    bool ex(string n);

    void get(string n);

    void ins(string key, string n);

    void er(string key);

    void prev(string key);

    void next(string key);
};

tablehash::tablehash(int count)
{
    this->buck = count;
    table = new list<linkn>[buck];
    this->lastadd = nullptr;
    this->prelastadd = nullptr;
}

bool tablehash::ex(string n)
{
    long long ind = hash_func(n);
    bool flag = false;
    for (auto i : table[ind])
    {
        if (i.tt.first == n)
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
        for (auto i : table[ind])
        {
            if (i.tt.first == n)
            {
                out << i.tt.second << endl;
                return;
            }
        }
    }
}

void tablehash::ins(string key, string n)
{
    long long ind = hash_func(key);
    if (!ex(key))
    {
        linkn *newn = new linkn({key, n}, lastadd);
        table[ind].push_back(*newn);
        linkn *lastp = &table[ind].back();
        if (lastadd != NULL)
            lastadd->next = lastp;
        lastadd = lastp;
        lastp = nullptr;
        newn = nullptr;
    }
    else
    {
        for (auto &i : table[ind])
            if (i.tt.first == key)
            {
                i.tt.second = n;
                break;
            }
    }
}

void tablehash::er(string key)
{
    if (!ex(key))
        return;

    long long ind = hash_func(key);
    for (auto i = table[ind].begin(); i != table[ind].end(); i++)
        if (i->tt.first == key)
        {
            if (i->prev != nullptr)
            {
                i->prev->next = i->next;
            }

            if (i->next != nullptr)
            {
                i->next->prev = i->prev;
            }

            if (lastadd->tt.first == i->tt.first)
            {
                lastadd = i->prev;
            }

            table[ind].erase(i);
            break;
        }
}

void tablehash::prev(string key)
{
    if (!ex(key))
    {
        out << "none" << endl;
        return;
    }

    long long ind = hash_func(key);

    for (auto i : table[ind])
        if (i.tt.first == key)
        {
            if (i.prev != nullptr)
                out << i.prev->tt.second << endl;
            else
                out << "none" << endl;

            return;
        }
}

void tablehash::next(string key)
{
    if (!ex(key))
    {
        out << "none" << endl;
        return;
    }

    long long ind = hash_func(key);

    for (auto i : table[ind])
        if (i.tt.first == key)
        {
            if (i.next != NULL)
                out << i.next->tt.second << endl;
            else
                out << "none" << endl;
            return;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string command, key, value;
    tablehash *th = new tablehash(int(1e5) / 2);
    while (in >> command)
    {
        if (command == "put")
        {
            in >> key >> value;
            th->ins(key, value);
        }
        else if (command == "delete")
        {
            in >> key;
            th->er(key);
        }
        else if (command == "get")
        {
            in >> key;
            th->get(key);
        }
        else if (command == "prev")
        {
            in >> key;
            th->prev(key);
        }
        else if (command == "next")
        {
            in >> key;
            th->next(key);
        }
    }

    delete th;
    return 0;
}