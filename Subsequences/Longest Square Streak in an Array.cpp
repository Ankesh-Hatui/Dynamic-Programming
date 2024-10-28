// LC 2501
// Time Complexity: O(NlogN) and Space complexity : O(N)

class Solution {
    int solve(vector<int>& nums,int ind,int prev,vector<vector<int>>&dp){
        if(ind>=nums.size()){
            
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        int pick=0,np=0;
        if(prev==-1 || (long long)((long long)nums[prev]*nums[prev])==nums[ind]){
            pick=1+solve(nums,ind+1,ind,dp);
            np=solve(nums,ind+1,prev,dp);
            
        }
        else{
            np=solve(nums,ind+1,prev,dp);
        }
        
        return dp[ind][prev+1]=max(pick,np);
  
    }
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        /*
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int ans=solve(nums,0,-1,dp);
        return ans>=2?ans:-1;
        */
        int maxSteak=0;

        unordered_map<int,int>mp;
        for (auto&num:nums){
            int root=(int)sqrt(num);

            if(root*root==num && mp.find(root)!=mp.end()){
                mp[num]=mp[root]+1;
            }
            else{
                mp[num]=1;
            }

            maxSteak=max(maxSteak,mp[num]);
        }

        return maxSteak>=2?maxSteak:-1;

    }
};
