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

#ifndef SRC_TINT_IR_VALUE_H_
#define SRC_TINT_IR_VALUE_H_

#include <ostream>

#include "src/tint/castable.h"

namespace tint::ir {

/// Value in the IR.
class Value : public Castable<Value> {
  public:
    /// Destructor
    ~Value() override;

    Value(const Value&) = delete;
    Value(Value&&) = delete;

    Value& operator=(const Value&) = delete;
    Value& operator=(Value&&) = delete;

    /// Write the value to the given stream
    /// @param out the stream to write to
    /// @returns the stream
    virtual std::ostream& ToString(std::ostream& out) const = 0;

  protected:
    /// Constructor
    Value();
};

}  // namespace tint::ir

#endif  // SRC_TINT_IR_VALUE_H_
