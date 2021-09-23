/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B becomes a substring of the repeated A. If B cannot be a substring of A no matter how many times it is repeated, return -1.

Example 1:

Input: A = "abcd", B = "cdabcdab"
Output: 3
Explanation: After repeating A three times, 
we get "abcdabcdabcd".
*/

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{

    public:
    int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        int c = 1;
        string s = A;
        while(A.find(B) == string::npos && A.size()<=B.size()+s.size())
        {
            A+=s;
            c++;
        }
        if(A.find(B)!=string::npos)
            return c;
        return -1;
    }
  
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends
