// one way to solve without dp using bruteforce is to iterate j from current pointer, i to n then if substring(i,j) is palindrom then we have two choices whether to include this palindromic substring in our list or not so make new function call if included else continue
// base case is that when we reach end push curr list in result

//above approach will be used to find all possible combinations of substring which are palindromic

//use dynamic prgramming approach to find minimum number of cuts
// using dynamic programming


// -----------------------------How to precompute to find if substring is palindrome-----------------------------------------
// In the bottom-up approach for checking whether substrings are palindromes, we iteratively fill a table (typically a 2D array) where each entry pal[i][j] represents whether the substring s[i...j] is a palindrome. The idea is to progressively build up information about smaller substrings, then use that information to check larger substrings.

// Step-by-Step Explanation:
// 1. Initialize a Table:
// Create a 2D boolean table pal[n][n], where n is the length of the string.
// pal[i][j] will be true if the substring s[i...j] is a palindrome, and false otherwise.
// 2. Base Case:
// Single characters are palindromes: Every single character is a palindrome by definition. Therefore, pal[i][i] = true for all i.
// Example:

// sql
// Copy code
// "a", "b", "c", ... are all palindromes.
// 3. Substrings of Length 2:
// A substring of length 2 is a palindrome if both characters are the same. Therefore, pal[i][i+1] = true if s[i] == s[i+1].
// Example:

// csharp
// Copy code
// "aa" is a palindrome, but "ab" is not.
// 4. Substrings of Length 3 or More:
// For a substring s[i...j] to be a palindrome, the first and last characters must be the same (s[i] == s[j]), and the substring between them (s[i+1...j-1]) must also be a palindrome. This is where the bottom-up approach is helpful because you can refer to smaller substrings to decide the status of larger ones.
// The relation is:
// pal[i][j] = (s[i] == s[j]) && pal[i+1][j-1]
// -----------------------------------------------------------------------------------------------------------------------------


// TOP DOWN APPROACH
class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> pal;
public:
    int fun(string s,int l,int r){
        if(l>=r) return 0;
        if(pal[l][r]) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int res=INT_MAX;
        for(int k=l; k<r; k++){
            if(pal[l][k]){
                res=min(res, 1+fun(s,k+1,r));
            }
        }
        return dp[l][r]=res;
    }
    int minCut(string s) {
        int n=s.size();
        dp.resize(s.size(), vector<int> (s.size(),-1));
        pal.resize(s.size(), vector<int> (s.size(),0));
        for(int i=0; i<n; i++){
            pal[i][i]=1;
        }
        for (int len = 2; len <= n; len++) {  // Substring lengths
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2 || pal[i+1][j-1]) {  // Check for palindrome
                        pal[i][j] = 1;
                    }
                }
            }
        }
        return fun(s,0,s.size()-1);
    }
};
