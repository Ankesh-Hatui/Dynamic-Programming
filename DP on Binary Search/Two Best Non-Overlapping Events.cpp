/*
LeetCode: 2054
T.C : O(NlogN)
S.C : O(N*3)
*/

class Solution {
    int dp[100000][3];
    int next_valid(vector<vector<int>>&events,int idx){
        int start=0;
        int end=events.size()-1;
        int res=-1;
        while (start<=end){
            int mid=start+(end-start)/2;
            if (events[mid][0]>events[idx][1]){
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>>& events,int idx,int count){
        if (idx>=events.size() || count>=2){
            return 0;
        }

        if (dp[idx][count]!=-1){
            return dp[idx][count];
        }

        int take=0,skip=0;
        int next_idx=next_valid(events,idx);
        
        take=events[idx][2]+solve(events,next_idx,count+1);
        
        skip=solve(events,idx+1,count);
        return dp[idx][count]=max(take,skip);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp,-1,sizeof(dp));
        sort(events.begin(),events.end());
        return solve(events,0,0);
    }
};
