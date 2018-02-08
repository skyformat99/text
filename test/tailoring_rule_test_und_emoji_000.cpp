
// Warning! This file is autogenerated.
#include <boost/text/collation_table.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/table_serialization.hpp>
#include <boost/text/data/all.hpp>

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

collation_table make_save_load_table()
{
    collation_table table =
        tailored_collation_table(
            data::und::emoji_collation_tailoring(),
            "und::emoji_collation_tailoring()", error, warning);
    save_table(table, "table.bin");
    return load_table("table.bin");
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, und_emoji_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00b7),
        std::vector<uint32_t>(1, 0x1f3fb),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00b7),
        std::vector<uint32_t>(1, 0x1f3fb),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fb),
        std::vector<uint32_t>(1, 0x1f3fc),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fb),
        std::vector<uint32_t>(1, 0x1f3fc),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fc),
        std::vector<uint32_t>(1, 0x1f3fd),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fc),
        std::vector<uint32_t>(1, 0x1f3fd),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fd),
        std::vector<uint32_t>(1, 0x1f3fe),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fd),
        std::vector<uint32_t>(1, 0x1f3fe),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fe),
        std::vector<uint32_t>(1, 0x1f3ff),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1f3fe),
        std::vector<uint32_t>(1, 0x1f3ff),
        table(), collation_strength::primary),
        0);
}

TEST(tailoring, und_emoji_000_002)
{
}

TEST(tailoring, und_emoji_000_003)
{
}

TEST(tailoring, und_emoji_000_004)
{
}

TEST(tailoring, und_emoji_000_005)
{
}

TEST(tailoring, und_emoji_000_006)
{
}

TEST(tailoring, und_emoji_000_007)
{
}

TEST(tailoring, und_emoji_000_008)
{
}

TEST(tailoring, und_emoji_000_009)
{
}

TEST(tailoring, und_emoji_000_010)
{
}

TEST(tailoring, und_emoji_000_011)
{
}

TEST(tailoring, und_emoji_000_012)
{
}

TEST(tailoring, und_emoji_000_013)
{
}

TEST(tailoring, und_emoji_000_014)
{
}

TEST(tailoring, und_emoji_000_015)
{
}

TEST(tailoring, und_emoji_000_016)
{
}

TEST(tailoring, und_emoji_000_017)
{
}

TEST(tailoring, und_emoji_000_018)
{
}

TEST(tailoring, und_emoji_000_019)
{
}

