// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
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

#pragma once

#include "fastdeploy/vision/common/processors/base.h"
#ifdef ENABLE_CVCUDA
#include <cvcuda/OpReformat.hpp>

#include "fastdeploy/vision/common/processors/cvcuda_utils.h"
#endif

namespace fastdeploy {
namespace vision {

class FASTDEPLOY_DECL HWC2CHW : public Processor {
 public:
  bool ImplByOpenCV(Mat* mat);
#ifdef ENABLE_FLYCV
  bool ImplByFlyCV(Mat* mat);
#endif
#ifdef ENABLE_CVCUDA
  bool ImplByCvCuda(FDMat* mat);
#endif
  std::string Name() { return "HWC2CHW"; }

  static bool Run(Mat* mat, ProcLib lib = ProcLib::DEFAULT);
 private:
#ifdef ENABLE_CVCUDA
  cvcuda::Reformat cvcuda_reformat_op_;
#endif
};
}  // namespace vision
}  // namespace fastdeploy
