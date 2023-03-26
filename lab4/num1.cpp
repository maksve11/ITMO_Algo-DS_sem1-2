#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int tt(int n)
{
	cout<<n<<endl;
}
int arr[1000000];
int main()
{
	ifstream in("stack.in");
	ofstream out("stack.out");
	int n, t = -1, k, c1=0;
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
			t++;
			arr[t] = k;
		}
		else if (s == "-")
		{
			out<<arr[t]<<endl;
			t--;
		}
	}
	return 0;
}
