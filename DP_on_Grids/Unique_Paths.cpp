class Solution {
    int solve(int i,int j,int m,int n, vector<vector<int>>&dp){
        if(i==m-1 & j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=solve(i+1,j,m,n,dp);
        int right=solve(i,j+1,m,n,dp);
        return dp[i][j]=(right+down);
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(101,vector<int>(101,-1));
        // return solve(0,0,m,n,dp);
        

        //Tabulation

        vector<vector<int>>dp(101,vector<int>(101));

        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                else{
                    int down=0,right=0;

                    if(i>0)down=dp[i-1][j];
                    if(j>0)right=dp[i][j-1];


                    dp[i][j]=down+right;

                }
            }
        }

        return dp[m-1][n-1];



        //MEMOIZATION

        //T.C=O(n*m)
        // S.C=O((n-1)+(m-1))+O(n*m);

        // TABULATION

        // T.C =O(n*m);
        //S.C = O(n*m);

    }
};
