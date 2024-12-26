'''
Leetcode : 494
'''
class Solution:
    def solve(self,nums,ind,target,dp,max_neg):
        if (ind>=len(nums)):
            return 1 if target==0 else 0
        val=target+max_neg
        if dp[ind][val]!=-1:
            return dp[ind][val]
        plus=self.solve(nums,ind+1,target-nums[ind],dp,max_neg)
        minus=self.solve(nums,ind+1,target+nums[ind],dp,max_neg)
        dp[ind][target+max_neg]=plus+minus
        return plus+minus
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        max_pos=sum(nums)
        max_neg=0
        for el in nums:
            max_neg+=-(el)
        dp=[[-1 for _ in range(abs(2001))] for _ in range(len(nums)+1)]
        
        return self.solve(nums,0,target,dp,max_neg)
