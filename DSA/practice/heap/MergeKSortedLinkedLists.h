#pragma once
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	struct CompareNodes {
		bool operator()(ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, CompareNodes> pq;
		for (auto& l : lists) {
			if (l) {
				pq.push(l);
			}
		}
		ListNode* dummy = new ListNode(0);
		ListNode* tail = dummy;
		while (!pq.empty())
		{
			ListNode* node = pq.top(); pq.pop();
			tail->next = node;
			tail = tail->next;

			if (node->next != nullptr) {
				pq.push(node->next);
			}
		}

		ListNode* result = dummy->next;
		delete dummy;
		return result;
	}
};