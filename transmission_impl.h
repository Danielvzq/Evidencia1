#ifndef TRANSMISSION_IMPL_H
#define TRANSMISSION_IMPL_H

#include "transmission_utils.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Lee el contenido completo de un archivo, lanza excepción si no se puede abrir
string readFileContent(const string &filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Error al abrir el archivo: " + filename);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

// Busca patrón en texto, devuelve si se encontró y posición 1-based
pair<bool, size_t> containsPattern(const string &text, const string &pattern) {
    if (pattern.empty()) return {true, 1};  // Caso borde: patrón vacío siempre coincide

    size_t pos = text.find(pattern);
    return (pos != string::npos) ? make_pair(true, pos + 1) : make_pair(false, static_cast<size_t>(0));
}

// Encuentra el palíndromo más largo, devuelve posiciones 1-based [start, end]
pair<int, int> longestPalindrome(const string &text) {
    int n = static_cast<int>(text.size());
    if (n == 0) return {1, 1};  // Caso borde: cadena vacía

    int maxLen = 1, start = 0;

    for (int i = 0; i < n; ++i) {
        // Palíndromo impar centrado en i
        for (int j = 0; i - j >= 0 && i + j < n && text[i - j] == text[i + j]; ++j) {
            int len = 2 * j + 1;
            if (len > maxLen) {
                maxLen = len;
                start = i - j;
            }
        }
        // Palíndromo par centrado entre i y i+1
        for (int j = 0; i - j >= 0 && i + j + 1 < n && text[i - j] == text[i + j + 1]; ++j) {
            int len = 2 * j + 2;
            if (len > maxLen) {
                maxLen = len;
                start = i - j;
            }
        }
    }
    return {start + 1, start + maxLen};  // Posiciones 1-based
}

// Encuentra la subcadena común más larga entre text1 y text2
pair<int, int> longestCommonSubstring(const string &text1, const string &text2) {
    int m = static_cast<int>(text1.size()), n = static_cast<int>(text2.size());
    if (m == 0 || n == 0) return {0, 0};  // Caso borde: alguna cadena vacía

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
    if (maxLen == 0) return {0, 0};  // No hay substring común
    return {endIdx - maxLen + 1, endIdx};  // Posiciones 1-based
}

#endif // TRANSMISSION_IMPL_H
