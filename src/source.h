
// Copyright 2020 The Tint Authors.
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

#ifndef SRC_SOURCE_H_
#define SRC_SOURCE_H_

#include <stddef.h>

#include <string>
#include <vector>

namespace tint {

/// Source describes a range of characters within a source file.
class Source {
 public:
  /// File describes a source file, including path and content.
  class File {
   public:
    /// Constructs the File with the given file path and content.
    /// @param file_path the path for this file
    /// @param file_content the file contents
    File(const std::string& file_path, const std::string& file_content);
    ~File();

    /// file path (optional)
    const std::string path;
    /// file content
    const std::string content;
    /// |content| split by lines
    const std::vector<std::string> lines;
  };

  /// Location holds a 1-based line and column index.
  /// 0's for |line| or |column| represent invalid values.
  class Location {
   public:
    /// The line number, 1-based
    size_t line = 0;
    /// The column number, 1-based
    size_t column = 0;
  };

  /// Range holds a Location interval described by [begin, end).
  class Range {
   public:
    /// Constructs a zero initialized Range.
    inline Range() = default;

    /// Constructs a zero-length Range starting at |loc|.
    /// @param loc the location to use to build the range
    inline explicit Range(const Location& loc) : begin(loc), end(loc) {}

    /// Constructs the Range beginning at |b| and ending at |e|.
    /// @param b the beginning of the range
    /// @param e the end of the range
    inline Range(const Location& b, const Location& e) : begin(b), end(e) {}

    /// The location of the first character in the range.
    Location begin;
    /// The location of one-past the last character in the range.
    Location end;
  };

  /// Constructs the Source with an zero initialized Range and null File.
  inline Source() = default;

  /// Constructs the Source with the Range |rng| and a null File.
  /// @param rng the range to assign to the source
  inline explicit Source(const Range& rng) : range(rng) {}

  /// Constructs the Source with the Range |loc| and a null File.
  /// @param loc the location to assign to the source
  inline explicit Source(const Location& loc) : range(Range(loc)) {}

  /// Constructs the Source with the Range |rng| and File |f|.
  /// @param rng the range for the source
  /// @param f the file for the source
  inline Source(const Range& rng, File const* f) : range(rng), file(f) {}

  /// Line/column range for this source
  Range range;
  /// Source file
  File const* file = nullptr;
};

}  // namespace tint

#endif  // SRC_SOURCE_H_
