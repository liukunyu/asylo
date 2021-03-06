/*
 *
 * Copyright 2017 Asylo authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef ASYLO_TEST_MISC_EXCEPTION_H_
#define ASYLO_TEST_MISC_EXCEPTION_H_

#include <string>

namespace asylo {

// Simple exception class for testing exceptions inside enclaves.
class TestException {
 public:
  TestException(int code, const std::string &message);
  TestException(const TestException &);
  TestException &operator=(const TestException &);

  int Code() const { return code_; }

 protected:
  int code_;
  std::string message_;
};

}  // namespace asylo

#endif  // ASYLO_TEST_MISC_EXCEPTION_H_
