// 1. start with the last cell
// 2. if chars at that index i,j are same include them in lcs
// 3. move to the left or top cell which has more lcs length
// 4. reverse the lcs string formed


int printLcs(vector<vector<int>> dp,string text1, string text2){
    int m=dp.size(), n=dp[0].size();
    int x=m-1,y=n-1;
    string lcs="";
    while(dp[x][y]>0){
        if(text1[x-1]==text2[y-1]){
            lcs+=text1[x-1];
            x--;
            y--;
        }else{
            if(dp[x-1][y]>dp[x][y-1]){
                x-=1;
            }else{
                y-=1;
            }
        }
    }
    int l=0,r=lcs.size()-1;
    while(l<r){
        char temp=lcs[l];
        lcs[l]=lcs[r];
        lcs[r]=temp;
        l++;
        r--;
    }
    if(lcs.size()!=dp[m-1][n-1]) return -1;
    cout<<lcs<<"\n";
    return 1;
}

// solve this 👇🏻
//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem?isFullScreen=true