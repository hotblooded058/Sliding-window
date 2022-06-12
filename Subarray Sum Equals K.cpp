/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int i=0,j=0;
        int sum=0;
        int cnt=0;
        
        while(j<nums.size())
        {
            sum=sum+nums[j];
            
            if(sum<k)
            {
                j++;
            }
            else if(sum==k)
            {
                cnt++;
                j++;
            }
            else if(sum>k)
            {
                while(sum>k)
                {
                    sum=sum-nums[i];
                    i++;
                }
                if(sum==k)
                {
                    cnt++;
                }
                j++;    
            }
        }
        return cnt;
    }
};