#pragma once
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		unordered_map<int, queue<vector<int>>> h;
		priority_queue<int, std::vector<int>, std::greater<int>> pq;
		for (auto& el : points) {
			int dist = el[0] * el[0] + el[1] * el[1];
			pq.push(dist);
			h[dist].push(el);
		}
		vector<vector<int>> res;
		for (size_t i = 0; i < k; i++)
		{
			res.push_back(h[pq.top()].front());
			h[pq.top()].pop();
			pq.pop();
		}
		return res;
	}
};
//faster but not mine:

//class Solution {
//private:
//    static double getDistanceFromOrigin(const vector<int>& point) {
//        return sqrt(point[0] * point[0] + point[1] * point[1]);
//    }
//
//    struct DistanceFromOriginComparator {
//        bool operator()(const vector<int>& first, const vector<int>& second) {
//            return getDistanceFromOrigin(first) > getDistanceFromOrigin(second);
//        }
//    };
//
//public:
//    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//        priority_queue<vector<int>, vector<vector<int>>, DistanceFromOriginComparator> pq(points.begin(), points.end());
//        vector<vector<int>> res(k);
//
//        for (size_t i = 0; i < k; i++)
//        {
//            res[i] = pq.top();
//            pq.pop();
//        }
//
//        return res;
//    }
//};

