// Problem : Given an array of integer of size n, Answer q queries where you need to print the sum of values in a given range of indices from l to r (both included).the values of l and r in queries follow's 1 based indexing.
#include<iostream>
#include<vector>
using namespace std;

int getSum(vector<int>&v, int l, int r){
    int n = v.size();
    vector<int>prefix_sum(n, 0);
    l--, r--; // 1 based indexing

    prefix_sum[0] = v[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    int sum = prefix_sum[r] - prefix_sum[l-1];
    return sum;
}

int main()
{
    vector<int>v{1, 2, 3, 4, 5, 6, 7};
    int l = 0, r = 0;
    cin >> l >> r;

    cout << getSum(v, l, r);
    return 0;
}

