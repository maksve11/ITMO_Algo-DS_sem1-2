#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int arr[1000000];
int main()
{
	ifstream in("queue.in");
	ofstream out("queue.out");
	int n, st = 0, k, end=0;
	string s;
	for (int i = 0; i < 1000000; ++i)
		arr[i] = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		in >> s;
		if (s == "+")
		{
			in >> k;
			arr[end++] = k;
		}
		else if (s == "-")
		{
			out<<arr[st]<<endl;
			st++;
		}
	}
	return 0;
}
