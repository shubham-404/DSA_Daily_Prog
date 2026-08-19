#include<bits/stdc++.h>
using namespace std;

void rev(vector<int> &arr, int l, int r){
    if(l>= r) return;
    swap(arr[l], arr[r]);
    rev(arr, l+1, r-1);
}

int main(){
    vector<int> arr = {1,3,5,6,7};
    for(const auto &i:arr) cout << i << " ";
    cout << endl;
    rev(arr, 0, arr.size()-1);
    for(const auto &i:arr) cout << i << " ";
    return 0;
}