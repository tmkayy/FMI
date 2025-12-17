#pragma once
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int, vector<int>> pq(stones.begin(), stones.end());
		while (pq.size() > 1) {
			int r1 = pq.top(); pq.pop();
			int r2 = pq.top(); pq.pop();
			int res = r1 - r2;
			if (res != 0) {
				pq.push(res);
			}
		}
		return ((pq.size() > 0) ? pq.top() : 0);
	}
};