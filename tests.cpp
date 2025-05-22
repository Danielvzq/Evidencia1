#include <gtest/gtest.h>
#include "transmission_impl.h"

TEST(pattern_test, found) {
    std::string t = "ABCDEF";
    std::string p = "CDE";
    auto res = contains_pattern(t, p);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 3);
}

TEST(pattern_test, empty_text) {
    auto res = contains_pattern("", "ABC");
    EXPECT_FALSE(res.first);
}

TEST(pattern_test, empty_pattern) {
    auto res = contains_pattern("ABC", "");
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second, 1);
}

TEST(palindrome_test, empty_string) {
    auto res = longest_palindrome("");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 1);
}

TEST(palindrome_test, even_length) {
    auto res = longest_palindrome("ABBA");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 4);
}

TEST(common_substring_test, no_common) {
    auto res = longest_common_substring("ABC", "XYZ");
    EXPECT_EQ(res.first, 0);
    EXPECT_EQ(res.second, 0);
}

TEST(common_substring_test, full_match) {
    auto res = longest_common_substring("ABC", "ABC");
    EXPECT_EQ(res.first, 1);
    EXPECT_EQ(res.second, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
