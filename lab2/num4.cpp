#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n;
vector<int> arr;
void antiq()
{
    for (int i=2; i<n; i++)
    swap(arr[i], arr[i/2]);
}
int main()
{
    ifstream in("antiqs.in");
    ofstream out("antiqs.out");
    in>>n;
    arr.resize(n);
    for (int i=0; i<n; i++)
    arr[i]=i+1;
    antiq();
    for (int i=0; i<n; i++)
    out<<arr[i]<<" ";
    return 0;
}