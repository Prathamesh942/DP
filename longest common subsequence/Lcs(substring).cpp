//idea is if i'th char of str1 and j'th char of str2 are equal then it would be common substring with length 1 now check same for i-1 and j-1 which should be solved already

int longestCommonSubstr(string str1, string str2) {
        string text1=str1,text2=str2;
        int m=text1.size(),n=text2.size();
        int res=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                res=max(res,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
return res;
    }