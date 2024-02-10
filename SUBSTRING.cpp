#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonSubstring(const string& X, const string& Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0, endPos = 0;

    // Fill the dp table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i;
                }
            }
        }
    }

    // Extracting the longest common substring
    return X.substr(endPos - maxLength, maxLength);
}

void printDPTable(const string& X, const string& Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Calculate DP values for the table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    // Print the DP table
    cout << "  ";
    for (int j = 0; j < n; ++j) {
        cout << Y[j] << " ";
    }
    cout << endl;

    for (int i = 0; i <= m; ++i) {
        if (i > 0) {
            cout << X[i - 1] << " ";
        } else {
            cout << "  ";
        }
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string X, Y;

    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    // Print the DP table before finding the LCS to show initial values
    cout << "DP Table:" << endl;
    printDPTable(X, Y);

    string lcs = longestCommonSubstring(X, Y);
    cout << "Longest Common Substring: " << lcs << endl;
    cout << "Length: " << lcs.length() << endl;

    return 0;
}
