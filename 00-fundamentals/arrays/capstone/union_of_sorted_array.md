# Aaj se apan shuru kar rahe hain. Actually resume kar rahe hain. 

## To aaj humne just abhi solve kiya  
* ## Find union of two sorted arrays, ie only unique elements. 
 Initial approach thi same as we do in merge sort. But it wasn't enough.
 We also had to take care of duplicate elements within the arrays and in-between the two arrays which for which I had to write some extra logic.

 To implement this, I used ***vector.empty()*** and ***vector.back()*** methods inside a separate function to check union array and element to be inserted. And the rest worked out.

 ```cpp
    	vector<int> findUnion(vector<int> &a, vector<int> &b) {
		// code here
		int i = 0;
		int j = 0;
		vector<int> ans;
		while (i < a.size() && j < b.size()) {
			if (!ans.empty() && min(a[i], b[j]) == ans.back()) {
				if (a[i] == b[j]) {
					i++;
					j++;
				} else if (a[i]>b[j]) {
					j++;
				} else {
					i++;
				}
				
			} else {
			    
				if (a[i] == b[j]) {
					ans.push_back(a[i]);
					i++;
					j++;
				}
				else if (a[i]>b[j]) {
					ans.push_back(b[j]);
				    j++;
				} else{
				    ans.push_back(a[i]);
				    i++;
				}
			}
		}
		while(i<a.size()){
		    if(ans.back() != a[i])
		        ans.push_back(a[i]);
		    i++;
		}
		while(j<b.size()){
		    if(ans.back() != b[j])
		        ans.push_back(b[j]);
		    j++;
		}
		return ans;
	}
 ```