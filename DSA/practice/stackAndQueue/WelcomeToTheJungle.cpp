#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int treeshit(vector<int> trees) {
	int max = 1;
	int maxIdx = trees.size() - 1;
	stack<int> heights;
	for (int i = trees.size() - 1; i >= 0; i--)
	{
		while (!heights.empty() && trees[i] >= heights.top()) {
			heights.pop();
		}
		heights.push(trees[i]);
		if (max <= heights.size()) {
			maxIdx = i;
			max = heights.size();
		}
	}
	return maxIdx;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::cout << treeshit(arr);
	return 0;
}
