/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meet
    {
        int st;
        int en;
        int num;
    };
    static bool compare(struct meet m1, meet m2)
    {
        if(m1.en<m2.en)
            return true;
        else if(m1.en>m2.en)
            return false;
        else if(m1.num<m2.num)
            return true;
        else
            return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meet m[n];
        for(int i=0;i<n;i++)
        {
            m[i].st = start[i];
            m[i].en = end[i];
            m[i].num = i+1;
        }
        sort(m, m+n, compare);
        vector<int> fin;
        int tim = m[0].en;
        fin.push_back(m[0].num);
        for(int i=0;i<n;i++)
        {
            if(m[i].st>tim)
            {
                tim = m[i].en;
                fin.push_back(m[i].num);
            }
        }
        int s = fin.size();
        return s;
        
    }
        
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
