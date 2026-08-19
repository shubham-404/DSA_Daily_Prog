# Aaj se apan shuru kar rahe hain. Actually resume kar rahe hain. 

## To aaj humne just abhi solve kiya  
* ## Find union of two sorted arrays. 
 Initial approach thi same as we do in merge sort. But it wasn't enough.
 We also had to take care of duplicate elements within the arrays and in-between the two arrays which for which I had to write some extra logic.

 To implement this, I used ***vector.empty()*** and ***vector.back()*** methods inside a separate function to check union array and element to be inserted. And the rest worked out.