/*
Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
*/

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    void mult(int x, vector<int>&temp)
    {
        int c =0;
        for(int i=0;i<temp.size();i++)
        {
            int prod = temp[i]*x+c;
            temp[i] = prod%10;
            c = prod/10;
        }
        while(c)
        {
            temp.push_back(c%10);
            c = c/10;
        }
    }
    vector<int> factorial(int N)
    {
        vector<int> temp;
        temp.push_back(1);
        int s = 1;
        for(int x=2;x<=N;x++)
            mult(x,temp);
        reverse(temp.begin(), temp.end());
        return temp;
        
    }
   
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
