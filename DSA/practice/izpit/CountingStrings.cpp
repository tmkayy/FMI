#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        unordered_map<char, int> m;
        for (char& c : s) {
            m[c]++;
        }
        unordered_map<int, int> countFreq;
        for (auto& p : m) {
            countFreq[p.second]++;
        }
        if (countFreq.size() == 1) {
            int freq = countFreq.begin()->first;
            int uniqueChars = m.size();
            if (uniqueChars == 1 || freq == 1) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
            continue;
        }

        if (countFreq.size() == 2) {
            auto it = countFreq.begin();
            int f1 = it->first, c1 = it->second;
            it++;
            int f2 = it->first, c2 = it->second;

            if ((f1 == 1 && c1 == 1) ||
                (f2 == 1 && c2 == 1) ||
                (abs(f1 - f2) == 1 && (c1 == 1 || c2 == 1))) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}