/*

Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=0,j=0;
    int n,key;
    cin>>n>>key;

    int a[n];
    for(int k=0;k<n;k++)
    {
        cin>>a[k];
    }

    list<int>l;
    vector<int>v;

    while(j<n)
    {
        if(a[j]<0)
        {
            l.push_back(a[j]);
        }

        if(j-i+1<key)
        {
            j++;
        }
        else if(j-i+1==key)
        {
            if(l.size()==0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(l.front());
                if(l.front()==a[i])
                {
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
    }

    for(auto i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
