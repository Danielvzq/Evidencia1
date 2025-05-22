#include <gtest/gtest.h>
#include "../transmission_utils.h"
#include "../transmission_impl.h"

TEST(PatternTest, Found) {
    std::string t = "ABCDEF";
    std::string p = "CDE";
    auto res = containsPattern(t, p);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 3);
}

TEST(PalindromeTest, Basic) {
    std::string t = "ABBA";
    auto res = longestPalindrome(t);
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 4);
}

TEST(CommonSubstrTest, Match) {
    std::string a = "ABXYZCD";
    std::string b = "XYZABCD";
    auto res = longestCommonSubstring(a, b);
    EXPECT_EQ(res.first, 3);
    EXPECT_EQ(res.second, 5);
}
