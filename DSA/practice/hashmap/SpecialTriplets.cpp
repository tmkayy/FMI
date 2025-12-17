#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int result = 0;
        unordered_map<long long, long long> countBeforeJ, countAfterJ;
        for (int& num : nums) {
            countAfterJ[num]++;
        }
        for (int& num : nums) {
            countAfterJ[num]--;

            int before = countBeforeJ[2 * num];
            int after = countAfterJ[2 * num];

            result = (result + (long long)before * after) % MOD;

            countBeforeJ[num]++;
        }

        return result;
    }
};