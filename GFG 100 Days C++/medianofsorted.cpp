/*
Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5
*/

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
       int l1=nums1.size();
       int l2=nums2.size();
       int s=l1+l2;
       vector<int> a;
       for(int i=0;i<l1;i++)
       {
           a.push_back(nums1[i]);
       }
       for(int i=0;i<l2;i++)
       {
           a.push_back(nums2[i]);
       }
       sort(a.begin(), a.end());
       if(s%2==0)
       {
            int sum = (s/2)-1;
            int x = a[s/2]+a[sum];
            double y = x/2.0;
            return y;
       }
       else
       {
           int sum = a[s/2];
           return sum;
       }
    }
        
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
