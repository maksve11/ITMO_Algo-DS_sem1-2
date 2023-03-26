#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
    long long a, b;
    ifstream in("aplusbb.in");
    ofstream out("aplusbb.out");
    in >> a >> b;
    long long c = b * b;
    out << a + c;
    return 0;
}