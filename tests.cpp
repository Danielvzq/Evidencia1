#include <gtest/gtest.h>
#include "transmission_utils.h"
#include "transmission_impl.h"

// Tests for containsPattern
TEST(PatternTest, Found) {
    std::string t = "ABCDEF";
    std::string p = "CDE";
    auto res = containsPattern(t, p);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 3);
}

TEST(PatternTest, EmptyText) {
    auto res = containsPattern("", "ABC");
    EXPECT_FALSE(res.first);
}

TEST(PatternTest, EmptyPattern) {
    auto res = containsPattern("ABC", "");
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 1);
}

TEST(PatternTest, PatternAtStart) {
    auto res = containsPattern("ABCDEF", "ABC");
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 1);
}

TEST(PatternTest, PatternAtEnd) {
    auto res = containsPattern("ABCDEF", "DEF");
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 4);
}

TEST(PatternTest, PatternLongerThanText) {
    auto res = containsPattern("ABC", "ABCD");
    EXPECT_FALSE(res.first);
}

// Tests for longestPalindrome
TEST(PalindromeTest, EmptyString) {
    auto res = longestPalindrome("");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 1);
}

TEST(PalindromeTest, SingleChar) {
    auto res = longestPalindrome("A");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 1);
}

TEST(PalindromeTest, NoPalindromeLongerThanOne) {
    auto res = longestPalindrome("ABCDE");
    EXPECT_EQ(res.second - res.first + 1, 1);
}

TEST(PalindromeTest, EvenLengthPalindrome) {
    auto res = longestPalindrome("ABBA");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 4);
}

TEST(PalindromeTest, OddLengthPalindrome) {
    auto res = longestPalindrome("babad");
    // Can be "bab" or "aba"
    EXPECT_TRUE((res == std::make_pair(1,3) || res == std::make_pair(2,4)));
}

TEST(PalindromeTest, PalindromeAtStart) {
    auto res = longestPalindrome("ABAxxx");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 3);
}

TEST(PalindromeTest, PalindromeAtEnd) {
    auto res = longestPalindrome("xxxABA");
    EXPECT_EQ(res.second - res.first + 1, 3);
}

// Tests for longestCommonSubstring
TEST(CommonSubstrTest, EmptyStrings) {
    auto res = longestCommonSubstring("", "");
    EXPECT_EQ(res.first, 0);
    EXPECT_EQ(res.second, 0);
}

TEST(CommonSubstrTest, OneEmptyString) {
    auto res = longestCommonSubstring("ABC", "");
    EXPECT_EQ(res.first, 0);
    EXPECT_EQ(res.second, 0);
}

TEST(CommonSubstrTest, NoCommonSubstring) {
    auto res = longestCommonSubstring("ABC", "XYZ");
    EXPECT_EQ(res.first, 0);
    EXPECT_EQ(res.second, 0);
}

TEST(CommonSubstrTest, FullStringCommon) {
    auto res = longestCommonSubstring("ABC", "ABC");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 3);
}

TEST(CommonSubstrTest, SubstringAtStart) {
    auto res = longestCommonSubstring("ABCD", "ABXY");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 2);
}

TEST(CommonSubstrTest, MultipleEqualLength) {
    auto res = longestCommonSubstring("ABCDXYZ", "XYZABCD");
    // Accept either first or second longest substring
    EXPECT_TRUE(
        (res.first == 1 && res.second == 4) ||
        (res.first == 5 && res.second == 7)
    );
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
