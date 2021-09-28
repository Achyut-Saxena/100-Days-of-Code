/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
*/

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertsorted(stack<int>&s, int val)
{
    if(s.size()==0)
    {
        s.push(val);
        return;
    }
    if(val<s.top())
    {
        int top = s.top();
        s.pop();
        insertsorted(s,val);
        s.push(top);
        return;
    }
    else
    {
        s.push(val);
        return;
    }
}
void SortedStack :: sort()
{
   //Your code here
   if(s.size()==1)
   {
       return;
   }
   int top = s.top();
   s.pop();
   SortedStack::sort();
   insertsorted(s,top);
   return;
}
