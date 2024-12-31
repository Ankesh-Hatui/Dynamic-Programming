'''
* href : https://leetcode.com/problems/minimum-cost-for-tickets/description/
* Leetcode : 983
* T.C : O(365*3)
* S.C : O(365*365*3)
'''

class Solution:
    def solve(self,days,ind,costs,prev,d,idx,dp):
        if ind>=len(days):
            return 0
        if (dp[ind][prev+1][idx]!=-1):
            return dp[ind][prev+1][idx]
        total_cost=0
        mini=float('inf')
        for i in range(len(costs)):
            if (prev==-1 or days[ind]>=days[prev]+d[idx]):
                total_cost=costs[i]+self.solve(days,ind+1,costs,ind,d,i,dp)
            else:
                total_cost=self.solve(days,ind+1,costs,prev,d,idx,dp)
            mini=min(mini,total_cost)
        dp[ind][prev+1][idx]=mini
        return mini

    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        d={0:1,1:7,2:30}
        dp=[[[-1 for _ in range(3)]for _ in range(367)]for _ in range(365)]
        return self.solve(days,0,costs,-1,d,0,dp)
       
