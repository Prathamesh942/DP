// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.


// for each amount upto target:
//     for each coin 

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,amount+1);
    dp[0] = 0;
    int n = coins.size();
    for(int i=1; i<=amount; i++){
        for(int j=0; j<n; j++){
            if(i-coins[j] >= 0) dp[i]=min(dp[i],1+dp[i-coins[j]]);
        }
    }
    if(dp[amount]==amount+1) return -1;
    return dp[amount];
}


int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1,INT_MAX));

    // Base case: 0 amount can be made with 0 coins
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            // Not take the current coin
            dp[i][j] = dp[i-1][j];
            
            // Take the current coin if possible
            if (coins[i-1] <= j && dp[i][j - coins[i-1]] != INT_MAX) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }
    return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
}