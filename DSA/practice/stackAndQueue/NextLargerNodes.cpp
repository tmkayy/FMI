#include <string>
#include <stack>
#include <vector>

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        vector<int> res;
        stack<int> indexes;
        ListNode* curr = head;

        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> res(values.size());
        stack<int> indexes;
       
        for (size_t i = 0; i < values.size(); i++)
        {
            while (!indexes.empty()&&values[i]>values[indexes.top()])
            {
                res[indexes.top()] = values[i];
                indexes.pop();
            }
            indexes.push(i);
        }

        return res;
    }
};