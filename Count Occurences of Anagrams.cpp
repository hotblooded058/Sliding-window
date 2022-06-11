/*

Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.

*/

class Solution{
public:
int search(string p, string s) {
  map<char, int>m;
int ans=0;
for (auto &x : p){
       m[x]++;
   }

   int count=m.size();
   int k=p.size();
   int i=0, j=0;
   while(j<s.size()){
       if(m.find(s[j])!=m.end()){
           m[s[j]]--;
           if(m[s[j]]==0){
               count--;
           }
       }
       if (j-i+1 < k){
           j++;
       }
         else if (j-i+1 == k){
           //finding the ans
           if (count == 0){
               ans++;
           }
           if (m.find(s[i]) != m.end()){
               m[s[i]]++;
               if (m[s[i]] == 1){
                   count++;
               }
           }

           //slide the window
           i++;
           j++;
       }
   }
return ans;
} 
       
};