
// Warning! This file is autogenerated.
#include <boost/text/collation_table.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/save_load_table.hpp>
#include <boost/text/data/all.hpp>

#include <boost/filesystem.hpp>

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

collation_table make_save_load_table()
{
    if (!exists(boost::filesystem::path("ln_standard.table"))) {
        string const table_str(data::ln::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "ln::standard_collation_tailoring()", error, warning);
        save_table(table, "ln_standard.table.0");
        boost::filesystem::rename("ln_standard.table.0", "ln_standard.table");
    }
    return load_table("ln_standard.table");
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, ln_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0045),
        std::vector<uint32_t>(1, 0x025b),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x025b),
        std::vector<uint32_t>(1, 0x0190),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x025b),
        std::vector<uint32_t>(1, 0x0190),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004f),
        std::vector<uint32_t>(1, 0x0254),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004f),
        std::vector<uint32_t>(1, 0x0254),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0254),
        std::vector<uint32_t>(1, 0x0186),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0254),
        std::vector<uint32_t>(1, 0x0186),
        table(), collation_strength::secondary),
        0);
}
