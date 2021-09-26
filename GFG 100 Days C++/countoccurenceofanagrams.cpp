/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
*/

using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	int search(string pat, string s)
	{
	    // code here
	    int k =pat.length(),ans=0;
    unordered_map<char,int>mp;
    for(int i=0;i<k;i++){
        mp[pat[i]]++;
    }
    int count=mp.size();
    for(int i=0;i<k;i++){
        if(mp.find(s[i])!=mp.end()){
            mp[s[i]]--;
            if(mp[s[i]]==0)count--;
        }
    }
    if(count==0)ans++;
    for(int i=k;i<s.length();i++){
        if(mp.find(s[i-k])!=mp.end()){
            if(mp[s[i-k]]==0)count++;
            mp[s[i-k]]++;
        }
        
        if(mp.find(s[i])!=mp.end()){
            mp[s[i]]--;
            if(mp[s[i]]==0)count--;
            if(count==0)ans++;
        }
    }
    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
