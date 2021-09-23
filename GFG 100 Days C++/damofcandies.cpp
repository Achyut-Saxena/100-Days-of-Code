/*
Geek wants to make a special space for candies on his bookshelf. Currently, it has N books, each of whose height is represented by the array height[] and has unit width.
Help him select 2 books such that he can store maximum candies between them by removing all the other books from between the selected books. The task is to find out the area between two books that can hold the maximum candies without changing the original position of selected books. 

Example 1:

Input: N = 3, height[] = {1, 3, 4}
Output: 1
Explanation:
1. Area between book of height 1 and book of 
height 3 is 0 as there is no space between 
them.
2. Area between book of height 1 and book of 
height 4 is 1 by removing book of height 3.
3. Area between book of height 3 and book of 
height 4 is 0 as there is no space between them.\
*/

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        int start = 0,end = n-1;
        int a =0, area =0;
        while(start < end)
        {
            if(height[start] < height[end])
                {
                    area = min(height[start],height[end]) *(end-start-1);
                    a = max(a,area);
                    start ++;
                }
            else
                {
                    area = min(height[start],height[end]) *(end-start-1);
                    a = max(a,area);
                    end --;
                }
        }
            return a;
        }
        
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
