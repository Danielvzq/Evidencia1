#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

string readFileContent(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

pair<bool, size_t> containsPattern(const string &text, const string &pattern) {
    size_t pos = text.find(pattern);
    return (pos != string::npos) ? make_pair(true, pos + 1) : make_pair(false, static_cast<size_t>(0));
}

pair<int, int> longestPalindrome(const string &text) {
    int n = text.size();
    if (n == 0) return {1, 1};

    int maxLen = 1, start = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; (i - j >= 0) && (i + j < n) && (text[i - j] == text[i + j]); ++j) {
            if (2 * j + 1 > maxLen) {
                maxLen = 2 * j + 1;
                start = i - j;
            }
        }
        for (int j = 0; (i - j >= 0) && (i + j + 1 < n) && (text[i - j] == text[i + j + 1]); ++j) {
            if (2 * j + 2 > maxLen) {
                maxLen = 2 * j + 2;
                start = i - j;
            }
        }
    }
    return {start + 1, start + maxLen};
}

pair<int, int> longestCommonSubstring(const string &text1, const string &text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0, endIdx = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIdx = i;
                }
            }
        }
    }
    return {endIdx - maxLen + 1, endIdx};
}

#ifdef UNIT_TESTS
void runTests() {
    // containsPattern
    auto r1 = containsPattern("abcde", "bcd");
    assert(r1.first == true && r1.second == 2);
    auto r2 = containsPattern("abcde", "xyz");
    assert(r2.first == false && r2.second == 0);

    // longestPalindrome
    auto p1 = longestPalindrome("babad"); // "bab" o "aba"
    assert((p1 == make_pair(1, 3) || p1 == make_pair(2, 4)));
    auto p2 = longestPalindrome("cbbd"); // "bb"
    assert(p2 == make_pair(2, 3));

    // longestCommonSubstring
    auto lcs = longestCommonSubstring("abcdef", "zabcf"); // "abc"
    assert(lcs == make_pair(1, 3));

    cout << "All unit tests passed.\n";
}
#endif

#ifndef UNIT_TESTS
int main() {
    string transmission1 = readFileContent("transmission1.txt");
    string transmission2 = readFileContent("transmission2.txt");
    vector<string> mcodes = {
        readFileContent("mcode1.txt"),
        readFileContent("mcode2.txt"),
        readFileContent("mcode3.txt")
    };

    cout << "Parte 1:" << endl;
    for (const auto &mcode : mcodes) {
        auto res1 = containsPattern(transmission1, mcode);
        cout << (res1.first ? "true " + to_string(res1.second) : "false") << endl;
    }
    for (const auto &mcode : mcodes) {
        auto res2 = containsPattern(transmission2, mcode);
        cout << (res2.first ? "true " + to_string(res2.second) : "false") << endl;
    }

    cout << "Parte 2:" << endl;
    auto p1 = longestPalindrome(transmission1);
    auto p2 = longestPalindrome(transmission2);
    cout << p1.first << " " << p1.second << " " << transmission1.substr(p1.first - 1, p1.second - p1.first + 1) << endl;
    cout << p2.first << " " << p2.second << " " << transmission2.substr(p2.first - 1, p2.second - p2.first + 1) << endl;

    cout << "Parte 3:" << endl;
    auto lcs = longestCommonSubstring(transmission1, transmission2);
    cout << lcs.first << " " << lcs.second << " " << transmission1.substr(lcs.first - 1, lcs.second - lcs.first + 1) << endl;

    return 0;
}
#endif
