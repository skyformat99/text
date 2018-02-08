
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
            data::or_::standard_collation_tailoring(),
            "or_::standard_collation_tailoring()", error, warning);
    save_table(table, "table.bin");
    return load_table("table.bin");
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, or__standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b14),
        std::vector<uint32_t>(1, 0x0b01),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b01),
        std::vector<uint32_t>(1, 0x0b02),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b02),
        std::vector<uint32_t>(1, 0x0b03),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b39),
        std::vector<uint32_t>{0x0b15, 0x0b4d, 0x0b37},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b2f),
        std::vector<uint32_t>(1, 0x0b5f),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b2f),
        std::vector<uint32_t>(1, 0x0b5f),
        table(), collation_strength::primary),
        0);
}
