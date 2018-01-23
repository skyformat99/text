#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Point this at the icu4c/source/data/coll directory, and it will create
# several headers containing the collation tailorings found there.

# To get this dumb script to work, I have to spell out some imports in the ICU
# files:

# fi.txt: [import fi-u-co-trad] -> [import fi-u-co-traditional]
# de.txt: [import de-u-co-phonebk] - > [import de-u-co-phonebook]


import argparse
import os
import re


parser = argparse.ArgumentParser(description='Generates headers with tailoring scripts for use with Boost.Text\'s Unicode collation.')
parser.add_argument('icu_dir', type=str, help='the path to icu4c/source/data/coll containing ICU\'s tailoring data')
parser.add_argument('--tests', action='store_true', help='generate lexer and parser tests instead of the data themselves')
args = parser.parse_args()

all_tailorings = {}
tailorings_by_file = {}

for filename in os.listdir(args.icu_dir):
    lines = open(os.path.join(args.icu_dir, filename)).readlines()
    root,ext = os.path.splitext(filename)
    if ext != '.txt':
        continue
    if root == 'root':
        root = 'und'
    name_prefix = root + '-u-co-'
    name = ''
    line_idx = 0
    max_line_idx = len(lines)
    while line_idx < max_line_idx:
        line = lines[line_idx]
        if 'Sequence{' in line:
            seq_end_line_idx = line_idx
            while not line.strip().endswith('}'):
                seq_end_line_idx += 1
                line = lines[seq_end_line_idx]
            sequence = ''.join(lines[line_idx:seq_end_line_idx + 1]).strip()
            if not sequence.startswith('Sequence{'):
                raise Exception('Oops!')
            sequence = sequence[len('Sequence{'):-1]
            sequence = map(lambda x: x.strip()[1:-1], sequence.splitlines())
            sequence = map(lambda x: (x.startswith('&') or x.startswith('[')) and x or '  ' + x, sequence)
            sequence = '\n'.join(sequence)
            if name == '':
                raise Exception('Somehow we got unnamed tailoring rules!')
            all_tailorings[name_prefix + name] = sequence
            if root not in tailorings_by_file:
                tailorings_by_file[root] = {}
            tailorings_by_file[root][name] = sequence
            name = ''
            line_idx = seq_end_line_idx + 1
            continue
        if not 'collations' in line and '{' in line and '"' not in line and '}' not in line:
            name = line.strip()[:-1]
            line_idx += 1
            continue
        line_idx += 1

lexer_tests_form = '''\
// Warning! This file is autogenerated.
#include <boost/text/data/all.hpp>
#include <boost/text/detail/lexer.hpp>

#include <gtest/gtest.h>


TEST(lexer, data)
{{

{0}
}}
'''

parser_tests_form = '''\
// Warning! This file is autogenerated.
#include <boost/text/data/all.hpp>
#include <boost/text/detail/parser.hpp>

#include <gtest/gtest.h>


TEST(parser, data)
{{

    boost::text::detail::collation_tailoring_interface callbacks = {{
        [](boost::text::detail::cp_seq_t const & reset_, bool before_) {{}},
        [](boost::text::detail::relation_t const & rel) {{}},
        [](boost::text::collation_strength strength) {{}},
        [](boost::text::variable_weighting weighting) {{}},
        [](boost::text::l2_weight_order order) {{}},
        [](boost::text::detail::cp_seq_t const & suppressions) {{}},
        [](std::vector<boost::text::detail::reorder_group> const & reorder_groups) {{}},
        [](boost::text::string const & s) {{
            std::cout << s << std::endl;
            throw std::runtime_error("Parser produced an error!");
        }},
        [](boost::text::string const & s) {{
            std::cout << s << std::endl;
            throw std::runtime_error("Parser produced an error!");
        }}
    }};


{0}
}}
'''

if args.tests:
    lex_tests = ''
    parse_tests = ''
    for k0,v0 in sorted(tailorings_by_file.items()):
        file_comment = '    // From {}.txt:\n\n'.format(k0)
        lex_tests += file_comment
        parse_tests += file_comment
        for k,v in sorted(v0.items()):
            if k.startswith('private'):
                continue
            strname = 'boost::text::data::{}::{}_collation_tailoring()'.format(
                k0 == 'or' and 'or_' or k0, k
            )
            lex_tests += '''\
    EXPECT_NO_THROW(
        boost::text::detail::lex(
            {0}.begin(),
            {0}.end(),
            [](boost::text::string const & s) {{
                std::cout << s << std::endl;
                throw std::runtime_error("Lexer produced an error!");
            }},
            "{1}.hpp")
    );
'''.format(strname, k0)
            parse_tests += '''\
    EXPECT_NO_THROW(
        boost::text::detail::parse(
            {0}.begin(),
            {0}.end(),
            callbacks,
            "{1}.hpp")
    );
'''.format(strname, k0)
        lex_tests += '\n\n'
        parse_tests += '\n\n'
    f = open('lexer_data.cpp', 'w')
    f.write(lexer_tests_form.format(lex_tests))
    f = open('parser_data.cpp', 'w')
    f.write(parser_tests_form.format(parse_tests))
    exit(0)

import_regex = re.compile(r'\[ *import +([^ \]]+) *\] *')

single_tailoring_form = '''\
inline string_view {0}_collation_tailoring()
{{
    return string_view(R"(
{1})");
}}

'''

header_form = '''\
// Warning! This file is autogenerated.
#ifndef BOOST_TEXT_DATA_{0}_HPP
#define BOOST_TEXT_DATA_{0}_HPP

#include<boost/text/string_view.hpp>


namespace boost {{ namespace text {{ namespace data {{ namespace {1} {{

{2}
}}}}}}}}

#endif
'''

# Flatten tailorings_by_file by processing the [import]s.
for k0,v0 in sorted(tailorings_by_file.items()):
    done_with_file = False
    tailorings = ''
    for k,v in sorted(v0.items()):
        match = True
        while match:
            match = import_regex.search(v)
            if match:
                import_ = match.group(1)
                if not import_ in all_tailorings:
                    import_ += '-u-co-standard'
                if not import_ in all_tailorings:
                    print '{}.txt: error: Unable to satisfy import "{}".'.format(k0, match.group(1))
                    done = True
                    break
                replacement = all_tailorings[import_]
                v = v.replace(v[match.start(0):match.end(0)], replacement)
        if not k.startswith('private'):
            tailorings += single_tailoring_form.format(k.replace('-', '_'), v)
        if done_with_file:
            break
    if done_with_file:
        break
    f = open(k0 + '.hpp', 'w')
    f.write(header_form.format(k0.upper(), k0 == 'or' and 'or_' or k0, tailorings))
    f.close()