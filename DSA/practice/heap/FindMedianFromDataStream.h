#pragma once
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class MedianFinder {
	priority_queue<int> leftHeap;
	priority_queue<int, vector<int>, greater<int>> rightHeap;

public:
	MedianFinder() {

	}

	void addNum(int num) {
		leftHeap.push(num);

		rightHeap.push(leftHeap.top());
		leftHeap.pop();

		if (leftHeap.size() < rightHeap.size()) {
			leftHeap.push(rightHeap.top());
			rightHeap.pop();
		}
	}

	double findMedian() {
		if (leftHeap.size() > rightHeap.size())
			return (double)leftHeap.top();
		else
			return (leftHeap.top() + rightHeap.top()) / 2.0;
	}
};

//*
// * Your MedianFinder object will be instantiated and called as such:
// * MedianFinder* obj = new MedianFinder();
// * obj->addNum(num);
// * double param_2 = obj->findMedian();