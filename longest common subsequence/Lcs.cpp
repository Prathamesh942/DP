//recursive with memoisation
int fun(string& s1, string& s2, int p1, int p2){
    if(p1<0 || p2<0) return 0;
    if(dp[p1][p2]!=-1) return dp[p1][p2];
    if(s1[p1]==s2[p2]) return dp[p1][p2]=1+fun(s1,s2,p1-1,p2-1);
    return dp[p1][p2] = max(fun(s1,s2,p1-1,p2),fun(s1,s2,p1,p2-1));
}

//bottom up
int m=text1.size(),n=text2.size();
vector<vector<int>> dp(m+1, vector<int>(n+1,0));
for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
        dp[i][j]=dp[i-1][j-1];
        if(text1[i-1]==text2[j-1]){
            dp[i][j]+=1;
        }else{
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
return dp[m][n];