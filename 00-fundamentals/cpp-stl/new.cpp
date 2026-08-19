#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<pair<int, string>> p1 = {{1, "hello"}, {2, "lelo"}};
    cout << p1[0].first <<" "<< p1[0].second;
    return 0;
}