#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate LCS using memoization (efficient version)
int lcsMem(string &str1, string &str2, int n, int m, vector<vector<int> >& dp) {
    if (n == 0 || m == 0) {
        return 0; // Base case: one of the strings is empty
    }

    if (dp[n][m] != -1) {
        return dp[n][m]; // Return already computed value (memoization)
    }

    if (str1[n - 1] == str2[m - 1]) {
        // If last characters match, consider it and move both indices back
        dp[n][m] = 1 + lcsMem(str1, str2, n - 1, m - 1, dp);
    } else {
        // If last characters don't match, either ignore one character from one of the strings
        int ans1 = lcsMem(str1, str2, n - 1, m, dp);
        int ans2 = lcsMem(str1, str2, n, m - 1, dp);
        dp[n][m] = max(ans1, ans2); // Take the max of ignoring either character
    }

    return dp[n][m];
}    

int main() {
    // Take input from user
    string str1, str2;
    cout << "Enter the first sequence: ";
    cin >> str1;//"abcdge"
    cout << "Enter the second sequence: ";
    cin >> str2;//"abedg"

    int n = str1.length();
    int m = str2.length();

    // DP table initialized to -1 for memoization
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));

    // Call the LCS function with indices for both strings
    cout << "Length of Longest Common Subsequence: " << lcsMem(str1, str2, n, m, dp) << endl;

    return 0;
}
