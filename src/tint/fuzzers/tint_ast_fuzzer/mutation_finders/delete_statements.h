// Copyright 2021 The Tint Authors.
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

#ifndef SRC_TINT_FUZZERS_TINT_AST_FUZZER_MUTATION_FINDERS_DELETE_STATEMENTS_H_
#define SRC_TINT_FUZZERS_TINT_AST_FUZZER_MUTATION_FINDERS_DELETE_STATEMENTS_H_

#include "src/tint/fuzzers/tint_ast_fuzzer/mutation_finder.h"

namespace tint::fuzzers::ast_fuzzer {

/// Looks for opportunities to apply
/// `MutationFinderDeleteStatements`.
///
/// Considers statements for deletion if their deletion would not make the module invalid.
class MutationFinderDeleteStatements : public MutationFinder {
  public:
    MutationList FindMutations(const tint::Program& program,
                               NodeIdMap* node_id_map,
                               ProbabilityContext* probability_context) const override;
    uint32_t GetChanceOfApplyingMutation(ProbabilityContext* probability_context) const override;
};

}  // namespace tint::fuzzers::ast_fuzzer

#endif  // SRC_TINT_FUZZERS_TINT_AST_FUZZER_MUTATION_FINDERS_DELETE_STATEMENTS_H_
