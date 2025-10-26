#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int studentCount, tourCount;
	std::cin >> studentCount >> tourCount;
	vector<int> weights(studentCount);

	for (size_t i = 0; i < studentCount; i++)
		std::cin >> weights[i];

	sort(weights.begin(), weights.end());

	for (size_t i = 0; i < tourCount; i++) {
		int upper, lower;
		std::cin >> lower >> upper;

		if (lower > upper) {
			cout << 0 << endl;
			continue;
		}
		std::cout << upper_bound(weights.begin(), weights.end(), upper) - lower_bound(weights.begin(), weights.end(), lower) << std::endl;
	}

	return 0;
}