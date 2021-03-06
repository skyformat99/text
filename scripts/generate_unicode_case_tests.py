#!/usr/bin/env python

test_file_form = '''\
// Warning! This file is autogenerated.
#include <boost/text/case_mapping.hpp>

#include <gtest/gtest.h>


using namespace boost::text;

{0}
'''

test_form = '''\
TEST(case_mapping, {0:03})
{{
{1}}}
'''

test_block = '''\
    {{ // to_{0}
{1}
{2}{3}
    }}
'''


condition_prefixes = {
    'Final_Sigma': [
        # valid
        (['0069'], True),           # 0069 is cased only
        (['0069', '0345'], True),   # 0345 is cased and case-ignorable
        (['0069', '1DFE'], True),   # 1DFE is case-ignorable only
        # invalid
        (['0345', '0345'], False),
        (['0345'], False),
        (['1DFE'], False),
        (['1DFE', '1DFE'], False),
        ([], False)
    ],
    'After_Soft_Dotted': [
        # valid
        (['006A', '006A'], True),   # 006A is soft-dotted (and thus also ccc=0)
        (['006A', '07F3'], True),   # 07F3 is ccc=230 and not soft-dotted
        # invalid
        (['006A'], False),
        (['07F3'], False),
        (['07F3', '07F3'], False),
        ([], False)
    ],
    'More_Above': [                 # none
        ([], True)
    ],
    'Not_Before_Dot': [             # none
        ([], True)
    ],
    'After_I': [
        # valid
        (['0049', '0049'], True),   # 'I' (ccc=0)
        (['0049', '0737'], True),   # 0737 is ccc=220
        # invalid
        (['0049'], False),
        (['004A'], False),          # 'J' (ccc=0)
        ([], False)
    ]
}
condition_suffixes = {
    'Final_Sigma': [
        # valid
        (['0345'], True),
        (['0345', '0345'], True),
        (['1dfe'], True),
        (['1dfe', '1dfe'], True),
        ([], True),
        # invalid
        (['0069'], False),
        (['0345', '0069'], False),
        (['1dfe', '0069'], False)
    ],
    'After_Soft_Dotted': [          # none
        ([], True)
    ],
    'More_Above': [
        # valid
        (['0737', '07F3'], True),   # 0737 is ccc=220, 07F3 is ccc=230
        (['07F3'], True),
        # invalid
        (['0737', '0737'], False),
        (['0737', '006A'], False),  # 006A is ccc=0
        (['006A', '07F3'], False),
        ([], False)
    ],
    'Not_Before_Dot': [
        # valid
        (['0737', '0737'], True),   # 0737 is ccc=220
        (['0737', '006A'], True),   # 006A is ccc=0
        (['006A', '0307'], True),
        ([], True),
        # invalid
        (['0737', '0307'], False),
        (['0307'], False)
    ],
    'After_I': [                    # none
        ([], True)
    ]
}

def to_array(name, l):
    return 'std::vector<uint32_t> {}({{{}}});'.format(
        name, ', '.join(map(lambda x: '0x' + x, l))
    )

def decls(name, l):
    return '''\
        {}
        std::vector<uint32_t> result;
'''.format(to_array(name, l))

def decls_with_from(from_l, name, l):
    return '''\
        {}
        {}
        std::vector<uint32_t> result;
'''.format(to_array('from', from_l), to_array(name, l))

def decls_with_from_and_prefix(from_l, prefix_size):
    return '''\
        {}
        std::vector<uint32_t> expected;
        std::vector<uint32_t> result;
        int const prefix_size = {};
'''.format(to_array('from', from_l), prefix_size)

def checks(name_1, name_2):
    return '''\
        to_{1}({0}, std::back_inserter(result));
        EXPECT_EQ(result, {1});'''.format(name_1, name_2)

def conditioned_checks(op, expected_cps, expect = 'EXPECT_EQ', lang = None):
    return '''\
        to_{0}(from.begin(), from.begin(), from.begin() + prefix_size, std::back_inserter(expected));
        expected.insert(expected.end(), {{{1}}});
        to_{0}(from.begin(), from.begin() + prefix_size + 1, from.end(), std::back_inserter(expected));

        to_{0}(from, std::back_inserter(result){2});
        {3}(result, expected);'''.format(
            op, ', '.join(map(lambda x: '0x' + x, expected_cps)), lang and ', ' + lang or '', expect)

title_prefixes = [
    ([], []),
    (['0020', '0020', '0020'], ['0020', '0020', '0020']),
    (['0061', '0061', '0061'], ['0041', '0061', '0061'])
]

title_suffixes = [
    [],
    ['0020', '0020', '0020'],
    ['0061', '0061', '0061']
]

# TODO: May need to be updated with new conditions when the data change.
def language_condition(conditions):
    retval = None
    for c in conditions:
        if c in ['az', 'lt', 'tr']:
            if retval != None:
                raise Error('Multiple language conditions are not expected')
            cpp_names = {'az': 'case_language::azerbaijani', 'lt': 'case_language::lithuanian', 'tr': 'case_language::turkish'}
            retval = cpp_names[c]
    return retval

def nonlanguage_condition(conditions):
    retval = None
    for c in conditions:
        if c in ['After_I', 'After_Soft_Dotted', 'Final_Sigma', 'More_Above', 'Not_Before_Dot']:
            if retval != None:
                raise Error('Multiple non-language conditions are not expected')
            retval = c
    return retval

def unconditional_mapping(to_dict, cp):
    mappings = to_dict[cp]

def condition_case(name, to, cp, conditions, blocks):
    lang = language_condition(conditions)
    non_lang = nonlanguage_condition(conditions)
    prefixes = [([], True)]
    suffixes = [([], True)]
    if non_lang in condition_prefixes:
        prefixes = condition_prefixes[non_lang]
        suffixes = condition_suffixes[non_lang]
    to_is_from = to == [cp]
    without_lang_check = ''
    if lang != None:
        without_lang_check = '''

        expected.clear();
        result.clear();

{}
'''.format(conditioned_checks(name, to, to_is_from and 'EXPECT_EQ' or 'EXPECT_NE', None))
    for n in range(len(prefixes) * len(suffixes)):
        pref = prefixes[n / len(suffixes)]
        suff = suffixes[n % len(suffixes)]
        expect = 'EXPECT_EQ'
        if (not pref[1] or not suff[1]) and not to_is_from:
            expect = 'EXPECT_NE'
        blocks += test_block.format(
            name,
            decls_with_from_and_prefix(
                pref[0] + [cp] + suff[0],
                len(pref[0])
            ),
            conditioned_checks(name, to, expect, lang),
            without_lang_check
        )
    return blocks

# TODO: CharRange should check convertible-to-char, not is-same-as-char.
# TODO: Eliminating the default constructions from char *, or justify it in the rationale.
# TODO: Figure out why unencoded_rope::{clear,swap}() are not noexcept; make this consistent with rope.
# TODO: Document the places that have bidi-like proxy iterators, e.g. grapheme_iterator.
# TODO: Make grapheme_iterators and grapheme_iterators-to-const appropriately interconvertible.
# TODO: Find better names for capacity(), max_size(), etc. in text layer types.
# TODO: Add a tagged overload of text::replace(string &&) that indicates that the invariants hold.
# TODO: Remvoe foreach_segment() from segmented_vector.
# TODO: Add extend_match() to trie, to compliment extend_subsequence().
# TODO: foreach_subrange() should return the callable f.
# TODO: Make an overload of foreach_subrange() that produces ranges as its output, writing through an output iterator.
# TODO: Consider using char8_t instead of char (where available), because it does not alias.

def case_mapping_tests(special_casing):
    tests = []
    test_idx = 0

    lines = open(special_casing, 'r').readlines()
    for line in lines:
        line = line[:-1]
        if not line.startswith('#') and len(line) != 0:
            fields = map(lambda x: x.strip(), line.split(';'))
            cp = fields[0].strip()
            lower = fields[1].strip().split(' ')
            if lower == ['']:
                lower = []
            title = fields[2].strip().split(' ')
            if title == ['']:
                title = []
            upper = fields[3].strip().split(' ')
            if upper == ['']:
                upper = []
            conditions_ = []
            if 3 < len(fields) and '#' not in fields[4]:
                conditions_ = fields[4].strip().split(' ')
            blocks = '    // ' + line + '\n'
            if len(conditions_) == 0:
                blocks += '''\
    std::array<uint32_t, 1> const cp = {{{{0x{}}}}};
'''.format(cp)
            blocks += '\n'
            if len(lower):
                if len(conditions_):
                    blocks = condition_case('lower', lower, cp, conditions_, blocks)
                else:
                    blocks += test_block.format(
                        'lower',
                        decls('lower', lower),
                        checks('cp', 'lower'),
                        ''
                    )
            if len(title):
                if len(conditions_) == 0:
                    for n in range(len(title_prefixes) * len(title_suffixes)):
                        pref = n / len(title_suffixes)
                        suff = n % len(title_suffixes)
                        to = title
                        if title_prefixes[pref][0] != title_prefixes[pref][1]:
                            to = lower
                        blocks += test_block.format(
                            'title',
                            decls_with_from(
                                title_prefixes[pref][0] + [cp] + title_suffixes[suff],
                                'title',
                                title_prefixes[pref][1] + to + title_suffixes[suff]
                            ),
                            checks('from', 'title'),
                            ''
                        )
            if len(upper):
                if len(conditions_):
                    blocks = condition_case('upper', upper, cp, conditions_, blocks)
                else:
                    blocks += test_block.format(
                        'upper',
                        decls('upper', upper),
                        checks('cp', 'upper'),
                        ''
                    )
            test = test_form.format(test_idx, blocks)
            test_idx += 1
            tests.append(test)

    cpp_file = open('case_mapping.cpp', 'w')
    cpp_file.write(test_file_form.format('\n'.join(tests)))

case_mapping_tests('SpecialCasing.txt')
