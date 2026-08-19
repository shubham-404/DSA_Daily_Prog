# Problem
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

# Solution
Can be solved with traditional methods as its an easy lvl problem, but the most optimal way is by using hashing in O(n).

1. Traverse through the array, and maintain an unordered_map with all the elements and their indices.
2. While traversing, consider current element as the first element and find the value of second element by: `second = target - first`. 
3. Now look for the second element in the map, if found, return a vector/array with first and second.
4. If not found in the map, add the current element in the map with its index as its value, and move to next element.
