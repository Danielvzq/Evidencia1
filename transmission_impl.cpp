#include "transmission_impl.h"

string read_file_content(const string &filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Error al abrir el archivo: " + filename);
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

pair<bool, size_t> contains_pattern(const string &text, const string &pattern) {
    if (pattern.empty()) {
        return {true, 1};
    }

    size_t pos = text.find(pattern);
    return (pos != string::npos) ? make_pair(true, pos + 1) : make_pair(false, static_cast<size_t>(0));
}

pair<int, int> longest_palindrome(const string &text) {
    int max_len = 1;
    int start = 0;
    int n = static_cast<int>(text.size());

    if (n == 0) {
        return {1, 1};
    }

    for (int i = 0; i < n; ++i) {
        // Palíndromo impar
        for (int j = 0; i - j >= 0 && i + j < n && text[i - j] == text[i + j]; ++j) {
            int len = 2 * j + 1;
            if (len > max_len) {
                max_len = len;
                start = i - j;
            }
        }

        // Palíndromo par
        for (int j = 0; i - j >= 0 && i + j + 1 < n && text[i - j] == text[i + j + 1]; ++j) {
            int len = 2 * j + 2;
            if (len > max_len) {
                max_len = len;
                start = i - j;
            }
        }
    }

    return {start + 1, start + max_len};
}

pair<int, int> longest_common_substring(const string &text1, const string &text2) {
    int m = static_cast<int>(text1.size());
    int n = static_cast<int>(text2.size());

    if (m == 0 || n == 0) {
        return {0, 0};
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int max_len = 0;
    int end_idx = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end_idx = i;
                }
            }
        }
    }

    if (max_len == 0) {
        return {0, 0};
    }

    return {end_idx - max_len + 1, end_idx};
}
