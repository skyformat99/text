// Warning! This file is autogenerated.
#ifndef BOOST_TEXT_DETAIL_COLLATION_CONSTANTS_HPP
#define BOOST_TEXT_DETAIL_COLLATION_CONSTANTS_HPP

#include <boost/text/config.hpp>

#include <array>

#include <cstdint>


namespace boost { namespace text { namespace detail {

    enum collation_constants : uint32_t {
        min_variable_collation_weight = 0x03040000,
        max_variable_collation_weight = 0x0b6d4b00,

        OR_CJK_Compatibility_Ideographs = 0xfa3f,
        OR_CJK_Unified_Ideographs_Extension_D = 0x2bfff,

        // Symbolic sentinel values produced by the parser.
        first_tertiary_ignorable = 0xfffffff2,
        last_tertiary_ignorable = 0xfffffff3,
        first_secondary_ignorable = 0xfffffff4,
        last_secondary_ignorable = 0xfffffff5,
        first_primary_ignorable = 0xfffffff6,
        last_primary_ignorable = 0xfffffff7,
        first_variable = 0xfffffff8,
        last_variable = 0xfffffff9,
        first_regular = 0xfffffffa,
        last_regular = 0xfffffffb,
        first_implicit = 0xfffffffc,
        first_trailing = 0xfffffffd,

        invalid_code_point = 0xffffffff,

        initial_first_tertiary_ignorable = 0,
        initial_last_tertiary_ignorable = 0xfffb,
        initial_first_secondary_ignorable = invalid_code_point,
        initial_last_secondary_ignorable = invalid_code_point,
        initial_first_primary_ignorable = 0x0332,
        initial_last_primary_ignorable = 0x00b7,
        initial_first_variable = 0x0009,
        initial_last_variable = 0x10A7F,
        initial_first_regular = 0x0060,
        initial_last_regular = 0x1B2FB,
        initial_first_implicit = 0x3400,
        initial_first_trailing = 0xfffd,

        common_l2_weight_compressed = 0x0500,
        common_l3_weight_compressed = 0x0500,

        first_tertiary_in_secondary_masked = 0x03,
        last_tertiary_in_secondary_masked = 0x38,
        first_secondary_in_primary = 0x0500,
        last_secondary_in_primary = 0x7c00,

        min_secondary_byte = 0x02,
        min_tertiary_byte = 0x03,
        common_secondary_byte = 0x05,
        common_tertiary_byte = 0x05,
        max_secondary_byte = 0xfe,
        max_tertiary_byte = 0xb8,

        implicit_weights_spacing_times_ten = 80,
        implicit_weights_first_lead_byte = 0xe0,
        implicit_weights_final_lead_byte = 0xe4
    };

    enum itty_bitty_collation_constants : uint16_t {
        case_level_bits_mask = 0xc000u,
        disable_case_level_mask = uint16_t(~0xc000u)
    };

    struct implicit_weights_segment
    {
        uint32_t first_;
        uint32_t last_;
        uint32_t primary_offset_;
    };

    BOOST_TEXT_DECL extern std::array<implicit_weights_segment, 10> const
        g_implicit_weights_segments;

}}}

#endif
