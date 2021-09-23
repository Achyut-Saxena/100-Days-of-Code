/*
Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

Example 1:

Input:
N = 5
preorder[] = {1, 2, 4, 5, 3}
inorder[] = {4, 2, 5, 1, 3}
postorder[] = {4, 5, 2, 3, 1}
Output: Yes
Explanation: 
All of the above three traversals 
are of the same tree.
           1
         /   \
        2     3
      /   \
     4     5
*/

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int len) 
    { 
    	// Your code goes here
    	
    // if the array lengths are 0,
    // then all of them are obviously equal
    if (len == 0)
        return 1;
 
    // if array lengths are 1,
    // then check if all of them are equal
    if (len == 1)
        return (preorder[0] == inorder[0])
               && (inorder[0] == postorder[0]);
 
    // search for first element of preorder
    // in inorder array
    int idx = -1, f = 0;
    for (int i = 0; i < len; ++i)
        if (inorder[i] == preorder[0]) {
            idx = i;
            break;
        }
   
    if(idx != -1){
      for(int i = 0; i < len; i++)
        if(preorder[0] == postorder[i]){f = 1; break;}
    }
 
    if (idx == -1 || f == 0)
        return 0;
 
    // check for the left subtree
    int ret1
        = checktree(preorder + 1, inorder, postorder, idx);
 
    // check for the right subtree
    int ret2
        = checktree(preorder + idx + 1, inorder + idx + 1,
                    postorder + idx, len - idx - 1);
 
    // return 1 only if both of them are
    // correct else 0
    return (ret1 && ret2);
}
};
 


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends
