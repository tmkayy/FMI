#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int counter = 0;
        while (true) {
            if (students.front() == sandwiches.front()) {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                counter = 0;
            }
            else {
                counter++;
                students.push_back(students[0]);
                students.erase(students.begin());
            }
            if (counter == students.size() || students.empty())
                break;
        }
        return students.size();
    }
};