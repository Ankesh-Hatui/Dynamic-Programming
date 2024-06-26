/*
For Recursion: T.C: o(2^N)
                S.C: o(1)
For Memo: T.C:o(N)
          S.C: o(N+N)

For Tabulation: T.C: O(N)
  S.C:O(N)

For Space-Optimization: 
T.C:O(N)
S.C:O(1)
 */


#include <bits/stdc++.h> 

int solveRec(vector<int>&nums,int index){

    if(index==0){
        return nums[index];
    }
    if(index<0){
        return 0;
    }

    int pick=solveRec(nums,index-2)+nums[index];
    int nonpick=solveRec(nums,index-1)+0;

    return max(pick,nonpick);

}
int solveByMemo(vector<int>&nums,int index,vector<int>&dp){

    if(index==0){
        return nums[index];
    }
    if(index<0){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    int pick=solveByMemo(nums,index-2,dp)+nums[index];
    int nonpick=solveByMemo(nums,index-1,dp)+0;

    return dp[index]=max(pick,nonpick);

}

int solveByTabu(vector<int>&nums){

    vector<int>dp(nums.size(),0);
    dp[0]=nums[0];
    dp[-1]=0;

    for(int i=1;i<nums.size();i++){
        int pick=nums[i]+dp[i-2];
        int nonpick=dp[i-1]+0;

        dp[i]=max(pick,nonpick);
    }
    return dp[nums.size()-1];

}

int solveBysp_Optimization(vector<int>nums){
    int n=nums.size();
    int prev1=0;
    int prev2=nums[0];
    for(int i=1;i<n;i++){

        int pick=nums[i]+prev1;
        int nonpick=prev2+0;

        int ans=max(pick,nonpick);
        prev1=prev2;
        prev2=ans;


    }

    return prev2;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    // int ans=solveRec(nums,n-1);
    // vector<int>dp(n,-1);
    // int ans=solveByMemo(nums,n-1,dp);
    // int ans=solveByTabu(nums);
    int ans=solveBysp_Optimization(nums);
    return ans;
}
