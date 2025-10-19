#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

//https://www.hackerrank.com/contests/sda-hw-1-2025/challenges/coachsort/problem

using namespace std;

int CharToNum(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0' + 1;
    }
    else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 11;
    }
    else {
        return c - 'A' + 37;
    }
}

void counting_sort2(std::string& arr) {
    size_t arrLength = arr.length();
    constexpr int MAX_SIZE = 63;
    std::string arr_copy;
    arr_copy = arr;

    int max = CharToNum(arr[0]);
    for (size_t i = 0; i < arrLength; i++)
    {
        if (max < CharToNum(arr[i]))
            max = CharToNum(arr[i]);
    }

    int count[MAX_SIZE];
    for (size_t i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (size_t i = 0; i < arrLength; i++)
    {
        count[CharToNum(arr[i])]++;
    }

    for (size_t i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = arrLength - 1; i >= 0; i--)
    {
        arr[count[CharToNum(arr_copy[i])] - 1] = arr_copy[i];
        count[CharToNum(arr_copy[i])]--;
    }
}

int main() {

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    counting_sort2(s);
    std::cout << s;

}
