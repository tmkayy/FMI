#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/contests/sda-hw-1-2025/challenges/just-sorting-1/problem

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }
    std::sort(v.begin(), v.end(), [](pair<string, int>& first, pair<string, int>& second) {
        if (first.second == second.second)
            return first.first < second.first;
        else
            return first.second > second.second;
        });
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
}