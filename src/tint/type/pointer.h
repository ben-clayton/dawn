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

#ifndef SRC_TINT_TYPE_POINTER_H_
#define SRC_TINT_TYPE_POINTER_H_

#include <string>

#include "src/tint/ast/access.h"
#include "src/tint/ast/address_space.h"
#include "src/tint/type/type.h"

namespace tint::type {

/// A pointer type.
class Pointer final : public Castable<Pointer, Type> {
  public:
    /// Constructor
    /// @param subtype the pointee type
    /// @param address_space the address space of the pointer
    /// @param access the resolved access control of the reference
    Pointer(const Type* subtype, ast::AddressSpace address_space, ast::Access access);

    /// Move constructor
    Pointer(Pointer&&);
    ~Pointer() override;

    /// @returns a hash of the type.
    size_t Hash() const override;

    /// @param other the other type to compare against
    /// @returns true if the this type is equal to the given type
    bool Equals(const Type& other) const override;

    /// @returns the pointee type
    const Type* StoreType() const { return subtype_; }

    /// @returns the address space of the pointer
    ast::AddressSpace AddressSpace() const { return address_space_; }

    /// @returns the access control of the reference
    ast::Access Access() const { return access_; }

    /// @param symbols the program's symbol table
    /// @returns the name for this type that closely resembles how it would be
    /// declared in WGSL.
    std::string FriendlyName(const SymbolTable& symbols) const override;

  private:
    Type const* const subtype_;
    ast::AddressSpace const address_space_;
    ast::Access const access_;
};

}  // namespace tint::type

#endif  // SRC_TINT_TYPE_POINTER_H_
