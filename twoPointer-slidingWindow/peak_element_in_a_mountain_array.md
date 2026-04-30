## peak element in an array (single or multiple).
### using binary search approach
- first decide when to move high/when to move low.
- usual bs approach.
- handle edge cases, by either
  - adding extra condition in each if-statement to check if mid is 0 or n-1
  - or by adding an extra if at the top to check if the 1st or last element is a peak element.
