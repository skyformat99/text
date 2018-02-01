
// Warning! This file is autogenerated.
#include <boost/text/collation_tailoring.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/data/all.hpp>

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

tailored_collation_element_table const & table()
{
    static tailored_collation_element_table retval =
        make_tailored_collation_element_table(
            data::af::standard_collation_tailoring(),
            "af::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, af_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004e),
        std::vector<uint32_t>(1, 0x0149),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004e),
        std::vector<uint32_t>(1, 0x0149),
        table(), collation_strength::secondary),
        0);
}