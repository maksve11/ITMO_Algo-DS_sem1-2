#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;
int max1(int a, int b)
{
	if (a>=b) return a;
	else return b;
}
int main()
{
    int h, w;
    ifstream in("turtle.in");
    ofstream out("turtle.out");
    in >> h >> w;
    int n = h * w;
    int d[1000][1000];
    int matr[1000][1000];
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            in >> matr[i][j];
    d[h][1] = matr[h][1];
    for (int i = h; i >= 1; i--)
        for (int j = 1; j <= w; j++)
        {
            d[i][j] = max1(d[i][j - 1], max1(d[i + 1][j - 1], d[i + 1][j])) + matr[i][j];
        }
    out<<d[1][w];
    return 0;
}
