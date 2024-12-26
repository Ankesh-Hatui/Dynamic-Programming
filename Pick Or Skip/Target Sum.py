'''
* LeetCode : 494
* T.C : O(2^N)
* S.C : O(N*target)
'''
class Solution:
    def solve(self,nums,ind,target,dp):
        if (ind>=len(nums)):
            return 1 if target==0 else 0
        string = f'{ind}-{target}'
        if (string in dp):
            return dp[string]
        
        plus=self.solve(nums,ind+1,target-nums[ind],dp)
        minus=self.solve(nums,ind+1,target+nums[ind],dp)
        dp.setdefault(string,plus+minus)
        return dp[string]
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp={}
        return self.solve(nums,0,target,dp)
