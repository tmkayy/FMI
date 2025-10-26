#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long findNum(long long beg, long long end, long long friendNum, int depth = 1) {
    if (beg >= end)
        return depth;

    long long mid1 = beg + (end - beg) / 3;
    long long mid2 = end - (end - beg) / 3;

    if (friendNum > mid1 && friendNum < mid2)
        return depth;

    if (friendNum <= mid1)
        return findNum(beg, mid1, friendNum, depth + 1);

    return findNum(mid2, end, friendNum, depth + 1);
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, n;
    cin >> p >> n;

    long long totalFriends = pow(3, p);
    vector<long long> friendNums(n);

    for (size_t i = 0; i < n; i++)
        cin >> friendNums[i];

    for (long long friendNum : friendNums) {
        cout << findNum(1, totalFriends, friendNum) << endl;
    }

    return 0;
}