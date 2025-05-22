#include <cassert>
#include <iostream>
#include "main.h"  // o el archivo donde declares las funciones a testear

void testContainsPattern() {
    auto r1 = containsPattern("abcde", "bcd");
    assert(r1.first == true && r1.second == 2);

    auto r2 = containsPattern("abcde", "xyz");
    assert(r2.first == false && r2.second == 0);
}

void testLongestPalindrome() {
    auto p1 = longestPalindrome("babad");
    // Puede ser "bab" o "aba"
    assert((p1 == std::make_pair(1,3) || p1 == std::make_pair(2,4)));

    auto p2 = longestPalindrome("cbbd");
    assert(p2 == std::make_pair(2,3));
}

void testLongestCommonSubstring() {
    auto lcs = longestCommonSubstring("abcdef", "zabcf");
    assert(lcs == std::make_pair(1,3));
}

int main() {
    testContainsPattern();
    testLongestPalindrome();
    testLongestCommonSubstring();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
