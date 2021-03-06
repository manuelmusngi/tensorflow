/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_MLIR_TENSORFLOW_TRANSLATE_EXPORT_GRAPHDEF_H_
#define TENSORFLOW_COMPILER_MLIR_TENSORFLOW_TRANSLATE_EXPORT_GRAPHDEF_H_

#include <functional>
#include <memory>
#include <string>

#include "llvm/ADT/StringRef.h"
#include "tensorflow/core/framework/function.h"
#include "tensorflow/core/framework/graph.pb.h"
#include "tensorflow/core/framework/node_def.pb.h"
#include "tensorflow/stream_executor/lib/statusor.h"

namespace mlir {
class Module;
class Operation;
}  // namespace mlir

namespace tensorflow {
class ExporterConfigs;
class Graph;
class GraphDef;
class NodeDef;

using stream_executor::port::StatusOr;

// Given an MLIR module, returns a GraphDef.
StatusOr<std::unique_ptr<GraphDef>> ConvertMlirToGraphdef(
    mlir::Module& module, const ExporterConfigs& configs);

// Converts an MLIR module to TensorFlow graph and FunctionLibraryDefinition.
// The "main" function of the module is stored in the graph and the rest of
// functions are stored in the library.
stream_executor::port::Status ConvertMlirToGraph(
    mlir::Module& module, const ExporterConfigs& confs,
    std::unique_ptr<Graph>* graph, FunctionLibraryDefinition* flib_def);
}  // namespace tensorflow

#endif  // TENSORFLOW_COMPILER_MLIR_TENSORFLOW_TRANSLATE_EXPORT_GRAPHDEF_H_
