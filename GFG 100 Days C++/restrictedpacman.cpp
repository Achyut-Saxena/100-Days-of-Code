/*
In the game of Restricted Pacman, an infinite linear path is given. Pacman has to start at position 0 and eat as many candies as possible. In one move he can only jump a distance of either M or N.  If M and N are coprime numbers, find how many candies will be left on the board after the game is over.
Note: The result is always finite as after a point X every index in the infinite path can be visited. 

Example 1:

Input: M = 2, N = 5
Output: 2
Explanation: From index 0, the indices that 
can be visited are
0 + 2 = 2
0 + 2 + 2 = 4
0 + 5 = 5
0 + 2 + 2 + 2 = 6
0 + 2 + 5 = 7
0 + 2 + 2 + 2 + 2 = 8
0 + 2 + 2 + 5 = 9
0 + 5 + 5 = 10
and so on.
1 and 3 are the only indices that cannot be 
visited. Therefore the candies at these two 
positions will be left on the board. 
*/

//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int candies(int m, int n) 
    { 
    	// Your code goes here
    	vector<bool> dp(m * n + 1, false);
        dp[0] = true;
        int ans = 0;
        for (int i = 1; i <= m * n; i++) 
        {
            if (i >= m)
                dp[i] = dp[i] | dp[i - m];
            if (i >= n)
                dp[i] = dp[i] | dp[i - n];
            if (!dp[i])
                ans++;
        }
    return ans;
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
		cin>>m>>n;
		Solution obj;
		cout << obj.candies(m,n)<<endl; 
	}
	return 0; 
} 



  // } Driver Code Ends
