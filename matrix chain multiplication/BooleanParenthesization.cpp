class Solution{
public:
    pair<int,int> par(string exp, int l, int r,vector<vector<pair<int,int>>>& dp){
        if(l==r){
            return exp[l]=='T' ? make_pair(1,0) : make_pair(0,1);
        }
        if(dp[l][r]!=make_pair(-1,-1)) return dp[l][r];
        int totalTrueWays = 0;
        int totalFalseWays = 0;
        for(int k=l+1; k<r; k+=2){
            pair<int,int> lw = par(exp,l,k-1,dp);
            pair<int,int> rw = par(exp,k+1,r,dp);
            if(exp[k]=='&'){
                totalTrueWays+=(lw.first*rw.first)%1003;
                totalFalseWays+=(lw.first*rw.second)%1003 + (lw.second*rw.first)%1003 + (lw.second*rw.second)%1003;
            }else if(exp[k]=='|'){
                totalTrueWays+=(lw.first*rw.first)%1003+(rw.first*lw.second)%1003+(rw.second*lw.first)%1003;
                totalFalseWays+=(lw.second*rw.second)%1003;
            }else{
                totalTrueWays+=(lw.first*rw.second)%1003+(rw.first*lw.second)%1003;
                totalFalseWays+=(lw.first*rw.first)%1003 + (lw.second*rw.second)%1003;
            }
        }
        return dp[l][r] = make_pair(totalTrueWays,totalFalseWays);
    }
    int countWays(int n, string s){
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1,-1}));
        pair<int,int> ways = par(s, 0, n-1,dp);
        return ways.first%1003;
    }
};