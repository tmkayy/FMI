// Faculty_number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    unordered_map<long long, pair<long long, long long>> m;
    long long count = 0;
    long long maxLen = 0;
    long long prefixsum = 0;
    m[0] = { 1, -1 };
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        prefixsum += el;
        int neededPref = prefixsum - k;
        if (m.find(neededPref) != m.end()) {
            count += m[neededPref].first;
            maxLen = max(maxLen, i - m[neededPref].second);
        }
        if (m.find(prefixsum) == m.end())
            m[prefixsum] = { 1,i };
        else
            m[prefixsum].first++;
    }

    if (count == 0)
        cout << -1;
    else
        cout << maxLen << ' ' << count;
    return 0;
}