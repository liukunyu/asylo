#
# Copyright 2019 Asylo authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

licenses(["notice"])  # Apache v2.0

package(
    default_visibility = ["//asylo:implementation"],
)

exports_files([
    "bridge.edl",
    "errno.edl",
])

load("//asylo/bazel:copts.bzl", "ASYLO_DEFAULT_COPTS")

# Trusted runtime components for SGX.
cc_library(
    name = "trusted_sgx",
    srcs = [
        "trusted_runtime.cc",
        "trusted_sgx.cc",
    ],
    copts = ASYLO_DEFAULT_COPTS,
    tags = ["asylo-sgx"],
    deps = select(
        {
            "//asylo/platform/primitives:asylo_sgx": [
                "//asylo/platform/primitives",
                "//asylo/platform/primitives:trusted_primitives",
                "//asylo/platform/primitives:trusted_runtime",
                "//asylo/platform/primitives/util:primitive_locks",
                "//asylo/platform/primitives/x86:spin_lock",
                "//asylo/util:error_codes",
            ],
        },
        no_match_error = "Trusted SGX components must be built with --define=ASYLO_SGX=1",
    ),
)

cc_library(
    name = "untrusted_sgx",
    srcs = ["untrusted_sgx.cc"],
    hdrs = ["untrusted_sgx.h"],
    copts = ASYLO_DEFAULT_COPTS,
    deps = [
        ":sgx_error_space",
        "//asylo:enclave_proto_cc",
        "//asylo/platform/primitives:untrusted_primitives",
        "//asylo/util:elf_reader",
        "//asylo/util:file_mapping",
        "//asylo/util:status",
        "@linux_sgx//:urts",
    ],
)

# An error space for SGX.
cc_library(
    name = "sgx_error_space",
    srcs = ["sgx_error_space.cc"],
    hdrs = ["sgx_error_space.h"],
    copts = ASYLO_DEFAULT_COPTS,
    deps = [
        "//asylo/util:status",
        "@linux_sgx//:public",
    ],
)
