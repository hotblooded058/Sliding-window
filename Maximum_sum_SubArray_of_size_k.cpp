/* 
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

 

Example 1:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
 

Example 2:

Input:
N = 4, K = 4
Arr = [100, 200, 300, 400]
Output:
1000
Explanation:
Arr1 + Arr2 + Arr3  
+ Arr4 =1000,
which is maximum.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,key;
    cin>>n>>key;

    int a[n];
    int i=0,j=0;
    for(int k=0;k<n;k++)
    {
        cin>>a[k];
    }

    int sum=0,mx=0;
    while(j<n)
    {
        sum=sum+a[j];

        if(j-i+1<key)
        {
            j++;
        }
        else if(j-i+1==key)
        {
            mx=max(mx,sum);
            sum=sum-a[i];
            i++;
            j++;
        }
    }
    cout<<"maximum subarray sum ="<<mx<<endl;
    return 0;
}
