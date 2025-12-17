#pragma once
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> frequencies;
		for (auto& t : tasks) {
			frequencies[t]++;
		}
		priority_queue<int> pq;
		for (auto& f : frequencies) {
			pq.push(f.second);
		}
		queue<pair<int, int>> cooldown;
		int time = 0;
		while (!pq.empty() || !cooldown.empty())
		{
			time++;
			if (!pq.empty()) {
				int count = pq.top();
				pq.pop();
				count--;
				if (count > 0) {
					cooldown.push({ count, time + n });
				}
			}

			while (!cooldown.empty() && cooldown.front().second <= time)
			{
				pq.push(cooldown.front().first);
				cooldown.pop();
			}
		}
		return time;
	}
};