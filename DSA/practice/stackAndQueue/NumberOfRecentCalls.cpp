#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> pings;
    RecentCounter() {
    }

    int ping(int t) {
        int lowerBound = t - 3000;
        int upperBound = t;
        while (!pings.empty() && lowerBound > pings.front()) {
            pings.pop();
        }
        pings.push(t);
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */