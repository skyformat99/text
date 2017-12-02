#!/usr/bin/env python

hpp_file_form = '''\
// Warning! This header is autogenerated.
#ifndef {0}
#define {0}

#include <stdint.h>


namespace boost {{ namespace text {{

    enum class {1}_t {{
        Other,{2}
    }};

    {1}_t {1}(uint32_t cp);

}} }}

#endif
'''

cpp_file_form = decls = '''\
// Warning! This file is autogenerated.
#include <boost/text/{0}.hpp>

#include <algorithm>
#include <array>


namespace boost {{ namespace text {{

struct {0}_interval
{{
    uint32_t lo_;
    uint32_t hi_;
    {0}_t prop_;
}};

bool operator<({0}_interval lhs, {0}_interval rhs)
{{ return lhs.hi_ <= rhs.lo_; }}

static constexpr std::array<{0}_interval, {1}> g_{0}_intervals = {{
{2}
}};

{0}_t {0}(uint32_t cp)
{{
    auto const it = std::lower_bound(g_{0}_intervals.begin(),
                                     g_{0}_intervals.end(),
                                     {0}_interval{{cp, cp + 1}});
    if (it == g_{0}_intervals.end() || cp < it->lo_ || it->hi_ <= cp)
        return {0}_t::Other;
    return it->prop_;
}}

}} }}
'''


def extract_break_properties(filename, prop_):
    intervals = ''
    num_intervals = 0
    prop_enum = prop_ + '_t'
    props = ''
    break_prop_lines = open(filename, 'r').readlines()
    prev_prop = ''
    for line in break_prop_lines:
        line = line[:-1]
        if not line.startswith('#') and len(line) != 0:
            comment_start = line.find('#')
            comment = ''
            if comment_start != -1:
                comment = line[comment_start + 1:].strip()
                line = line[:comment_start]
            fields = map(lambda x: x.strip(), line.split(';'))
            prop = fields[1]
            code_points = fields[0]
            if '..' in code_points:
                cps = code_points.split('.')
                interval = (int(cps[0], 16), int(cps[2], 16) + 1, prop)
            else:
                cp = int(code_points, 16)
                interval = (cp, cp + 1, prop)
            if prop != prev_prop:
                props += '\n        {},'.format(prop)
                intervals += '\n    // {}\n'.format(prop)
                prev_prop = prop
            intervals += '    {}_interval{{ {}, {}, {}::{} }},\n'.format(
                prop_, hex(interval[0]), hex(interval[1]), prop_enum, interval[2]
            )
            num_intervals += 1
    return (intervals, num_intervals, props)

(grapheme_break_intervals, num_grapheme_intervals, grapheme_props) = \
    extract_break_properties('GraphemeBreakProperty.txt', 'grapheme_prop')
hpp_file = open('grapheme_prop.hpp', 'w')
hpp_file.write(hpp_file_form.format('BOOST_GRAPHEME_PROP_HPP', 'grapheme_prop', grapheme_props[:-1]))
cpp_file = open('grapheme_prop.cpp', 'w')
cpp_file.write(cpp_file_form.format('grapheme_prop', num_grapheme_intervals, grapheme_break_intervals))

(word_break_intervals, num_word_intervals, word_props) = \
    extract_break_properties('WordBreakProperty.txt', 'word_prop')
hpp_file = open('word_prop.hpp', 'w')
hpp_file.write(hpp_file_form.format('BOOST_WORD_PROP_HPP', 'word_prop', word_props[:-1]))
cpp_file = open('word_prop.cpp', 'w')
cpp_file.write(cpp_file_form.format('word_prop', num_word_intervals, word_break_intervals))

# TODO: Add sentence breaks?
