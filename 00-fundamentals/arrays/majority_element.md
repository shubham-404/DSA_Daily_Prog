Today I was solving the problem of 'Majority Element' in array, and got to know about "Moore's Algo"

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Using Moore's, you can solve this in O(n).
freq=0 , ans=0
For each element, check if freq=0, if yes ans=element. Also check if its equal to ans, if yes freq++, else freq--.
At the end ans will be final answer.
As simple as that.

Explaination:
The Majority element is going to always keep the 'freq'>0, so 'ans' will have majority element.
