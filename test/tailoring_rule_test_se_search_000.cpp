
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
            data::se::search_collation_tailoring(),
            "se::search_collation_tailoring()", error, warning);
    save_table(table, "table.bin");
    return load_table("table.bin");
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, se_search_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x003d),
        std::vector<uint32_t>(1, 0x2260),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0627),
        std::vector<uint32_t>(1, 0xfe8e),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0627),
        std::vector<uint32_t>(1, 0xfe8e),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8e),
        std::vector<uint32_t>(1, 0xfe8d),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8e),
        std::vector<uint32_t>(1, 0xfe8d),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8d),
        std::vector<uint32_t>(1, 0x0622),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8d),
        std::vector<uint32_t>(1, 0x0622),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0622),
        std::vector<uint32_t>(1, 0xfe82),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0622),
        std::vector<uint32_t>(1, 0xfe82),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe82),
        std::vector<uint32_t>(1, 0xfe81),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe82),
        std::vector<uint32_t>(1, 0xfe81),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe81),
        std::vector<uint32_t>(1, 0x0623),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe81),
        std::vector<uint32_t>(1, 0x0623),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0623),
        std::vector<uint32_t>(1, 0xfe84),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0623),
        std::vector<uint32_t>(1, 0xfe84),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe84),
        std::vector<uint32_t>(1, 0xfe83),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe84),
        std::vector<uint32_t>(1, 0xfe83),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe83),
        std::vector<uint32_t>(1, 0x0625),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe83),
        std::vector<uint32_t>(1, 0x0625),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0625),
        std::vector<uint32_t>(1, 0xfe88),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0625),
        std::vector<uint32_t>(1, 0xfe88),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe88),
        std::vector<uint32_t>(1, 0xfe87),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe88),
        std::vector<uint32_t>(1, 0xfe87),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0648),
        std::vector<uint32_t>(1, 0x06e5),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0648),
        std::vector<uint32_t>(1, 0x06e5),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06e5),
        std::vector<uint32_t>(1, 0xfeee),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06e5),
        std::vector<uint32_t>(1, 0xfeee),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeee),
        std::vector<uint32_t>(1, 0xfeed),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeee),
        std::vector<uint32_t>(1, 0xfeed),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeed),
        std::vector<uint32_t>(1, 0x0624),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeed),
        std::vector<uint32_t>(1, 0x0624),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0624),
        std::vector<uint32_t>(1, 0xfe86),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0624),
        std::vector<uint32_t>(1, 0xfe86),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe86),
        std::vector<uint32_t>(1, 0xfe85),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe86),
        std::vector<uint32_t>(1, 0xfe85),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x064a),
        std::vector<uint32_t>(1, 0x06e6),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x064a),
        std::vector<uint32_t>(1, 0x06e6),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06e6),
        std::vector<uint32_t>(1, 0xfef3),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06e6),
        std::vector<uint32_t>(1, 0xfef3),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef3),
        std::vector<uint32_t>(1, 0xfef4),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef3),
        std::vector<uint32_t>(1, 0xfef4),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef4),
        std::vector<uint32_t>(1, 0xfef2),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef4),
        std::vector<uint32_t>(1, 0xfef2),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef2),
        std::vector<uint32_t>(1, 0xfef1),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef2),
        std::vector<uint32_t>(1, 0xfef1),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef1),
        std::vector<uint32_t>(1, 0x0626),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef1),
        std::vector<uint32_t>(1, 0x0626),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0626),
        std::vector<uint32_t>(1, 0xfe8b),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0626),
        std::vector<uint32_t>(1, 0xfe8b),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8b),
        std::vector<uint32_t>(1, 0xfe8c),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8b),
        std::vector<uint32_t>(1, 0xfe8c),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8c),
        std::vector<uint32_t>(1, 0xfe8a),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8c),
        std::vector<uint32_t>(1, 0xfe8a),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8a),
        std::vector<uint32_t>(1, 0xfe89),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe8a),
        std::vector<uint32_t>(1, 0xfe89),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe89),
        std::vector<uint32_t>(1, 0x0649),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe89),
        std::vector<uint32_t>(1, 0x0649),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0649),
        std::vector<uint32_t>(1, 0xfbe8),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0649),
        std::vector<uint32_t>(1, 0xfbe8),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe8),
        std::vector<uint32_t>(1, 0xfbe9),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe8),
        std::vector<uint32_t>(1, 0xfbe9),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe9),
        std::vector<uint32_t>(1, 0xfef0),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe9),
        std::vector<uint32_t>(1, 0xfef0),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef0),
        std::vector<uint32_t>(1, 0xfeef),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfef0),
        std::vector<uint32_t>(1, 0xfeef),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0647),
        std::vector<uint32_t>(1, 0xfeeb),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0647),
        std::vector<uint32_t>(1, 0xfeeb),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeeb),
        std::vector<uint32_t>(1, 0xfeec),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeeb),
        std::vector<uint32_t>(1, 0xfeec),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeec),
        std::vector<uint32_t>(1, 0xfeea),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeec),
        std::vector<uint32_t>(1, 0xfeea),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeea),
        std::vector<uint32_t>(1, 0xfee9),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfeea),
        std::vector<uint32_t>(1, 0xfee9),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfee9),
        std::vector<uint32_t>(1, 0x0629),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfee9),
        std::vector<uint32_t>(1, 0x0629),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0629),
        std::vector<uint32_t>(1, 0xfe94),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0629),
        std::vector<uint32_t>(1, 0xfe94),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe94),
        std::vector<uint32_t>(1, 0xfe93),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfe94),
        std::vector<uint32_t>(1, 0xfe93),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00b7),
        std::vector<uint32_t>(1, 0x05f3),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00b7),
        std::vector<uint32_t>(1, 0x05f3),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05f3),
        std::vector<uint32_t>(1, 0x05f4),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05f3),
        std::vector<uint32_t>(1, 0x05f4),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05f4),
        std::vector<uint32_t>(1, 0x0640),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05f4),
        std::vector<uint32_t>(1, 0x0640),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0640),
        std::vector<uint32_t>(1, 0x0e3a),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0640),
        std::vector<uint32_t>(1, 0x0e3a),
        table(), collation_strength::primary),
        0);
}

TEST(tailoring, se_search_000_002)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1100),
        std::vector<uint32_t>(1, 0x11a8),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1100, 0x1100},
        std::vector<uint32_t>(1, 0x1101),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1101),
        std::vector<uint32_t>(1, 0x11a9),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1100, 0x1109},
        std::vector<uint32_t>(1, 0x11aa),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1102),
        std::vector<uint32_t>(1, 0x11ab),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1102, 0x110c},
        std::vector<uint32_t>(1, 0x11ac),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1102, 0x1112},
        std::vector<uint32_t>(1, 0x11ad),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1103),
        std::vector<uint32_t>(1, 0x11ae),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1103, 0x1103},
        std::vector<uint32_t>(1, 0x1104),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1105),
        std::vector<uint32_t>(1, 0x11af),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1105, 0x1100},
        std::vector<uint32_t>(1, 0x11b0),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1105, 0x1106},
        std::vector<uint32_t>(1, 0x11b1),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1105, 0x1107},
        std::vector<uint32_t>(1, 0x11b2),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1105, 0x1109},
        std::vector<uint32_t>(1, 0x11b3),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1105, 0x1110},
        std::vector<uint32_t>(1, 0x11b4),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1105, 0x1111},
        std::vector<uint32_t>(1, 0x11b5),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1105, 0x1112},
        std::vector<uint32_t>(1, 0x11b6),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1106),
        std::vector<uint32_t>(1, 0x11b7),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1107),
        std::vector<uint32_t>(1, 0x11b8),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1107, 0x1107},
        std::vector<uint32_t>(1, 0x1108),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1107, 0x1109},
        std::vector<uint32_t>(1, 0x11b9),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1109),
        std::vector<uint32_t>(1, 0x11ba),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1109, 0x1109},
        std::vector<uint32_t>(1, 0x110a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x110a),
        std::vector<uint32_t>(1, 0x11bb),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x110b),
        std::vector<uint32_t>(1, 0x11bc),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x110c),
        std::vector<uint32_t>(1, 0x11bd),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x110c, 0x110c},
        std::vector<uint32_t>(1, 0x110d),
        table(), collation_strength::quaternary),
        0);
}

TEST(tailoring, se_search_000_003)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x110e),
        std::vector<uint32_t>(1, 0x11be),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x110f),
        std::vector<uint32_t>(1, 0x11bf),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1110),
        std::vector<uint32_t>(1, 0x11c0),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1111),
        std::vector<uint32_t>(1, 0x11c1),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x1112),
        std::vector<uint32_t>(1, 0x11c2),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1161, 0x1175},
        std::vector<uint32_t>(1, 0x1162),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1163, 0x1175},
        std::vector<uint32_t>(1, 0x1164),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1165, 0x1175},
        std::vector<uint32_t>(1, 0x1166),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1167, 0x1175},
        std::vector<uint32_t>(1, 0x1168),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1169, 0x1161},
        std::vector<uint32_t>(1, 0x116a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1169, 0x1161, 0x1175},
        std::vector<uint32_t>(1, 0x116b),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1169, 0x1175},
        std::vector<uint32_t>(1, 0x116c),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x116e, 0x1165},
        std::vector<uint32_t>(1, 0x116f),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x116e, 0x1165, 0x1175},
        std::vector<uint32_t>(1, 0x1170),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x116e, 0x1175},
        std::vector<uint32_t>(1, 0x1171),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x1173, 0x1175},
        std::vector<uint32_t>(1, 0x1174),
        table(), collation_strength::quaternary),
        0);
}

TEST(tailoring, se_search_000_004)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0079),
        std::vector<uint32_t>(1, 0x00fc),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0079),
        std::vector<uint32_t>(1, 0x00fc),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00fc),
        std::vector<uint32_t>(1, 0x00dc),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00fc),
        std::vector<uint32_t>(1, 0x00dc),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00dc),
        std::vector<uint32_t>(1, 0x0171),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00dc),
        std::vector<uint32_t>(1, 0x0171),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0171),
        std::vector<uint32_t>(1, 0x0170),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0171),
        std::vector<uint32_t>(1, 0x0170),
        table(), collation_strength::secondary),
        0);
}
