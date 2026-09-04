// 1. Contains Duplicate -> Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> st;
    for (int i : nums)
    {
        if (st.count(i))
            return true;
        st.insert(i);
    }
    return false;
}
int main() {}

// 2. anagram -> a string that can be formed by rearranging the letters of another string
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    vector<int> chars(26, 0);
    for (char i : s)
    {
        chars[i - 'a'] += 1;
    }
    for (char i : t)
    {
        chars[i - 'a'] -= 1;
    }
    for (int i : chars)
    {
        if (i != 0)
            return false;
    }
    return true;
}
int main() {}

// 3. Two Sum -> Given an array of integers, return indices of the two numbers such that they add up to a specific target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    seen.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        auto it = seen.find(target - nums[i]);
        if (it != seen.end()) {
            return {it->second, i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

