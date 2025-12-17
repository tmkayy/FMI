#pragma once
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq(nums.begin(), nums.end());
        for (size_t i = 0; i < k - 1; i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};