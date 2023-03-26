#include <fstream>
#include <vector>

using namespace std;

ifstream in("multimap.in");
ofstream out("multimap.out");

class set
{
private:
    static const int tablesize = 100;
    vector<string> table[tablesize];
    int count = 0;

public:
    static int hash_func(string key)
    {
        int hash = 5381;
        for (int i = 0; i < key.length(); ++i)
        {
            hash = (((hash << 5) + hash) + int(key[i])) % tablesize; // DJB hash
        }
        return hash;
    }

    bool exists(string key)
    {
        int hash = hash_func(key);
        for (int i = 0; i < table[hash].size(); ++i)
        {
            if (table[hash][i] == key)
            {
                return true;
            }
        }
        return false;
    }

    void get()
    {
        out << count << " ";
        if (count == 0)
            return;

        for (int i = 0; i < tablesize; ++i)
        {
            for (int j = 0; j < table[i].size(); ++j)
            {
                out << table[i][j] << " ";
            }
        }
        out << endl;
    }

    void insert(string key)
    {
        int hash = hash_func(key);
        if (!exists(key))
        {
            table[hash].emplace_back(key);
            count++;
        }
    }

    void del(string key)
    {
        int hash = hash_func(key);
        for (int i = 0; i < table[hash].size(); ++i)
        {
            if (table[hash][i] == key)
            {
                table[hash].erase(table[hash].begin() + i);
                table[hash].shrink_to_fit();
                count--;
                break;
            }
        }
    }

    void delall()
    {
        for (int i = 0; i < tablesize; ++i)
        {
            for (int j = 0; j < table[i].size(); ++j)
            {
                table[i].erase(table[i].begin() + j);
                table[i].shrink_to_fit();
                count = 0;
            }
        }
    }
};

struct keyset
{
    string key;
    set value;
};

class multimap
{
private:
    static const int tablesize = 1000;
    vector<keyset> multimap[tablesize];

public:
    static int hash_func(string key)
    {
        int hash = 5381;
        for (int i = 0; i < key.length(); ++i)
        {
            hash = (((hash << 5) + hash) + int(key[i])) % tablesize; // DJB hash
        }
        return hash;
    }

    void get(string key)
    {
        int hash = hash_func(key);
        bool exkey = false;

        for (int i = 0; i < multimap[hash].size(); ++i)
        {
            if (multimap[hash][i].key == key)
            {
                multimap[hash][i].value.get();
                exkey = true;
                return;
            }
        }
        if (!exkey)
        {
            out << "0" << endl;
        }
    }

    void put(string key, string value)
    {
        int hash = hash_func(key);
        bool exkey = false;

        for (int i = 0; i < multimap[hash].size(); ++i)
        {
            if (multimap[hash][i].key == key)
            {
                (multimap[hash][i].value).insert(value);
                exkey = true;
                break;
            }
        }
        if (!exkey)
        {
            keyset newkeyset;
            newkeyset.key = key;
            (newkeyset.value).insert(value);
            multimap[hash].emplace_back(newkeyset);
        }
    }

    void del(string key, string value)
    {
        int hash = hash_func(key);

        for (int i = 0; i < multimap[hash].size(); ++i)
        {
            if (multimap[hash][i].key == key)
            {
                multimap[hash][i].value.del(value);
                break;
            }
        }
    }

    void delall(string key)
    {
        int hash = hash_func(key);

        for (int i = 0; i < multimap[hash].size(); ++i)
        {
            if (multimap[hash][i].key == key)
            {
                multimap[hash][i].value.delall();
                multimap[hash].erase(multimap[hash].begin() + i);
                break;
            }
        }
    }
};

int main()
{
    string command, key, value;
    multimap mm;
    while (in >> command)
    {
        if (command == "put")
        {
            in >> key >> value;
            mm.put(key, value);
        }
        else if (command == "get")
        {
            in >> value;
            mm.get(value);
        }
        else if (command == "delete")
        {
            in >> key >> value;
            mm.del(key, value);
        }
        else
        {
            in >> value;
            mm.delall(value);
        }
    }
    return 0;
}