#include<iostream>
#include<limits.h>
using namespace std;

// TC: O(n*k)
// SC: O(1)
int getMaxSumSubArray1(int arr[], int k, int n){
    int max_sum=0;
    for(int i=0; i<n-k; i++){
        int curr_sum=0;
        for(int j=i; j<i+k; j++){
            curr_sum+=arr[j];
        }
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

// Sliding Window Technique (Using For Loop)
// TC: O(n)
// SC: O(1)
int getMaxSumSubArray2(int arr[], int k, int n){
    int curr_sum=0;
    int max_sum=0;
    for(int i=0; i<k; i++){
        curr_sum+=arr[i];
    }
    for(int i=k; i<n; i++){
        curr_sum=curr_sum+arr[i]-arr[i-k];
        max_sum=max(curr_sum, max_sum);
    }
    return max_sum;
}

// Sliding Window Technique (Using While Loop)
// TC: O(n)
// SC: O(1)
int getMaxSumSubArray3(int arr[], int k, int n){
    int curr_sum=0;
    int max_sum=0;
    for(int i=0; i<k; i++){
        curr_sum+=arr[i];
    }
    int j=k;
    while(j<n){
        curr_sum-=arr[j-k];
        curr_sum+=arr[j];
        j++;
        max_sum=max(curr_sum, max_sum);
    }
    return max_sum;
}

int main()
{
    int A[]{1,8,30,-5,20,7};
    int k=3;
    int n=6;
    cout<<getMaxSumSubArray1(A, k, n)<<endl; // Naive Approach
    cout<<getMaxSumSubArray2(A, k, n)<<endl; // Sliding Window(Using For Loop)
    cout<<getMaxSumSubArray3(A, k, n)<<endl; // Sliding Window(Using While Loop)

    cout<<endl;
    int A2[]{5,-10, 6, 90, 3};
    cout<<getMaxSumSubArray1(A2, 2, 6)<<endl; // Naive Approach
    cout<<getMaxSumSubArray3(A2, 2, 6)<<endl; // Sliding Window(Using For Loop)
    cout<<getMaxSumSubArray3(A2, 2, 6)<<endl; // Sliding Window(Using While Loop)

    return 0;
}
