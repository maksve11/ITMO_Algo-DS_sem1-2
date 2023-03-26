#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
    int a, b;
    ifstream in("aplusb.in");
    ofstream out("aplusb.out");
    in >> a >> b;
    out << a + b;
    return 0;
}