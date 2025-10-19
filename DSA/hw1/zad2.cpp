#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/contests/sda-hw-1-2025/challenges/walking-median-sorting/problem

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> v[i];
        int current = v[i];
        int j = i;
        while (j > 0 && current < v[j - 1])
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = current;

        int len = i + 1;

        if (len % 2 == 1)
            cout << v[len / 2] << std::endl;
        else
            cout << (double)(v[len / 2 - 1] + v[len / 2]) / 2 << std::endl;
    }
}
