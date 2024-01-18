// Problem : Check if we can partition the array in two subarrays with equal sum. more formaly check that the prefix sum of the part of the array is equal to the sufix sum of the rest of the array
# include <iostream>
# include <vector>
using namespace std;


// Concept : 
// prefix_sum + suffix_sum = total_sum 
// suffix_sum = total_sum - prefix_sum
bool checkPartition(vector<int>&v){
    int n = v.size();
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        total_sum += v[i];
    }

    int prefix_sum  = 0;
    int suffix_sum = 0;
    for(int i = 0; i < n; i++){
        prefix_sum += v[i];
        suffix_sum = total_sum - prefix_sum;

        if(prefix_sum == suffix_sum)
            return true;
    }
    return false;
}   

int main(){
    int n;
    cin >> n;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    cout << boolalpha << checkPartition(v) << endl;
    return 0;
}