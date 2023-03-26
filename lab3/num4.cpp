#include <fstream>
#include <vector>
#include <string>
using namespace std;
void siftup(vector<int> &el, int i, vector<int> &el_index)
{
    while (i > 0 && el[i] < el[(i - 1) / 2])
    {
        swap(el[i], el[(i - 1) / 2]);
        swap(el_index[i], el_index[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void siftdown(vector<int> &el, int i, vector<int> &el_index)
{
    int left, right, j;
    while (2 * i + 1 < el.size())
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if (right < el.size() && el[right] < el[j])
        {
            j = right;
        }
        if (el[i] < el[j])
        {
            break;
        }
        swap(el[j], el[i]);
        swap(el_index[i], el_index[j]);
        i = j;
    }
}
int main()
{
    ifstream in("priorityqueue.in");
    ofstream out("priorityqueue.out");
    vector<int> el;
    vector<int> el_index;
    string str;
    int flag = 0;
    int count = 0;
    int countpush = 0;
    int num1, num2, index;
    while (in >> str)
    {
        if (str == "push")
        {
            in >> num1;
            el.push_back(num1);
            el_index.push_back(count);
            siftup(el, el.size() - 1, el_index);
        }
        else if (str == "decrease-key")
        {
            in >> num1;
            in >> num2;
            for (int i = 0; i < el_index.size(); i++)
            {
                if (el_index[i] == num1 - 1)
                {
                    index = i;
                    break;
                }
            }
            el[index] = num2;
            siftup(el, index, el_index);
        }
        else if (str == "extract-min")
        {
            if (el.size() != 0)
            {
                out << el[0] << endl;
                swap(el[0], el[el.size() - 1]);
                swap(el_index[0], el_index[el_index.size() - 1]);
                el.pop_back();
                el_index.pop_back();

                siftdown(el, 0, el_index);
            }
            else if (el.size() == 0)
            {
                out << '*' << endl;
            }
        }
        count++;
    }
    return 0;
}