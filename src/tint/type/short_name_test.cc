// Copyright 2022 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

////////////////////////////////////////////////////////////////////////////////
// File generated by tools/src/cmd/gen
// using the template:
//   src/tint/type/short_name_test.cc.tmpl
//
// Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////

#include "src/tint/type/short_name.h"

#include <string>

#include "gtest/gtest.h"

#include "src/tint/utils/string.h"

namespace tint::type {
namespace {

namespace parse_print_tests {

struct Case {
    const char* string;
    ShortName value;
};

inline std::ostream& operator<<(std::ostream& out, Case c) {
    return out << "'" << std::string(c.string) << "'";
}

static constexpr Case kValidCases[] = {
    {"vec2f", ShortName::kVec2F}, {"vec2h", ShortName::kVec2H}, {"vec2i", ShortName::kVec2I},
    {"vec2u", ShortName::kVec2U}, {"vec3f", ShortName::kVec3F}, {"vec3h", ShortName::kVec3H},
    {"vec3i", ShortName::kVec3I}, {"vec3u", ShortName::kVec3U}, {"vec4f", ShortName::kVec4F},
    {"vec4h", ShortName::kVec4H}, {"vec4i", ShortName::kVec4I}, {"vec4u", ShortName::kVec4U},
};

static constexpr Case kInvalidCases[] = {
    {"veccf", ShortName::kUndefined},     {"32", ShortName::kUndefined},
    {"vVc2f", ShortName::kUndefined},     {"vec21", ShortName::kUndefined},
    {"qqeJh", ShortName::kUndefined},     {"vecll7h", ShortName::kUndefined},
    {"veqH2pp", ShortName::kUndefined},   {"vi", ShortName::kUndefined},
    {"Gebi", ShortName::kUndefined},      {"vevi2u", ShortName::kUndefined},
    {"ve8WWu", ShortName::kUndefined},    {"Mxxc2", ShortName::kUndefined},
    {"vgg3f", ShortName::kUndefined},     {"V3X", ShortName::kUndefined},
    {"vec33", ShortName::kUndefined},     {"vec3E", ShortName::kUndefined},
    {"TTeP3h", ShortName::kUndefined},    {"vxxcdd", ShortName::kUndefined},
    {"v44c3i", ShortName::kUndefined},    {"veVVSSi", ShortName::kUndefined},
    {"22RRi", ShortName::kUndefined},     {"vF3u", ShortName::kUndefined},
    {"vecu", ShortName::kUndefined},      {"ROOHVu", ShortName::kUndefined},
    {"ecyf", ShortName::kUndefined},      {"n77rrlcGf", ShortName::kUndefined},
    {"vec440", ShortName::kUndefined},    {"ooh", ShortName::kUndefined},
    {"vezz", ShortName::kUndefined},      {"1ipp4h", ShortName::kUndefined},
    {"XXec4i", ShortName::kUndefined},    {"ve9IInn5i", ShortName::kUndefined},
    {"HHreSSaYi", ShortName::kUndefined}, {"kk4", ShortName::kUndefined},
    {"jgRR", ShortName::kUndefined},      {"veb", ShortName::kUndefined},
};

using ShortNameParseTest = testing::TestWithParam<Case>;

TEST_P(ShortNameParseTest, Parse) {
    const char* string = GetParam().string;
    ShortName expect = GetParam().value;
    EXPECT_EQ(expect, ParseShortName(string));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, ShortNameParseTest, testing::ValuesIn(kValidCases));
INSTANTIATE_TEST_SUITE_P(InvalidCases, ShortNameParseTest, testing::ValuesIn(kInvalidCases));

using ShortNamePrintTest = testing::TestWithParam<Case>;

TEST_P(ShortNamePrintTest, Print) {
    ShortName value = GetParam().value;
    const char* expect = GetParam().string;
    EXPECT_EQ(expect, utils::ToString(value));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, ShortNamePrintTest, testing::ValuesIn(kValidCases));

}  // namespace parse_print_tests

}  // namespace
}  // namespace tint::type
