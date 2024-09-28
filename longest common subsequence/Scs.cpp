// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

//logic
//1.form lcs table
//2.now same as printing lcs, but
//3.when characters are not same include one which when removed will give longest common subsequence of remaining strings i.e if(dp[x-1][y]>dp[x][y-1]) scs+=text1[x-1];

//in nutshell scs is both string concatenated without repeating characters is LCS thus, length(scs(s1,s2)) = length(s1+s2)-length(lcs(s1,s2))

string printLcs(vector<vector<int>> dp,string& text1, string& text2){
    int m=dp.size(), n=dp[0].size();
    int x=m-1,y=n-1;
    string scs="";
    while(x>0 && y>0){
        if(text1[x-1]==text2[y-1]){
            scs+=text1[x-1];
            x--;
            y--;
        }else{
            if(dp[x-1][y]>dp[x][y-1]){
                scs+=text1[x-1];
                x-=1;
            }else{
                scs+=text2[y-1];
                y-=1;
            }
        }
    }
    while(x>0){
        scs+=text1[x-1];
        x--;
    }
    while(y>0){
        scs+=text2[y-1];
        y--;
    }
    int l=0,r=scs.size()-1;
    while(l<r){
        char temp=scs[l];
        scs[l]=scs[r];
        scs[r]=temp;
        l++;
        r--;
    }
    return scs;
}
string shortestCommonSupersequenceHelper(string& text1, string& text2) {
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
    return printLcs(dp,text1,text2);
}
string shortestCommonSupersequence(string str1, string str2) {
    return shortestCommonSupersequenceHelper(str1,str2);
}