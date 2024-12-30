'''
* Leetcode : 2466
* href: https://leetcode.com/problems/count-ways-to-build-good-strings/description/
* T.C : O(high)
* S.C : O(high)
'''
class Solution:
    def solve(self,low,high,zero,one,length,dp):
        if (length>high):
            return 0
        if (dp[length]!=-1):
            return dp[length]
        cnt=1 if length>=low else 0

        cnt+=self.solve(low,high,zero,one,length+zero,dp)
        cnt+=self.solve(low,high,zero,one,length+one,dp)

        dp[length]=cnt%1000000007
        return cnt%1000000007
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        dp=[-1 for _ in range(high+low)]
        return self.solve(low,high,zero,one,0,dp)
