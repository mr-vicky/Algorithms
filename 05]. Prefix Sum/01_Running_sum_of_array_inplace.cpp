#include <iostream>
#include <vector>
using namespace std;

void runningSum(vector<int>&v){
    for(int i = 1; i < v.size(); i++){
        v[i] = v[i-1]+v[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    runningSum(v);
    for(auto x: v){
        cout << x << " ";
    }
}
