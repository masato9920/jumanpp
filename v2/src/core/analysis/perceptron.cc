//
// Created by Arseny Tolmachev on 2017/03/07.
//

#include "core/analysis/perceptron.h"
#include "core/analysis/lattice_types.h"

namespace jumanpp {
namespace core {
namespace analysis {

void HashedFeaturePerceptron::compute(util::MutableArraySlice<float> result,
                                      const Lattice *lattice,
                                      const LatticeBoundary *focus,
                                      LatticeBoundaryConnection *connection) {
  JPP_DCHECK(util::memory::IsPowerOf2(features_.size()));
  u32 mask = static_cast<u32>(features_.size() - 1);
  auto ngrams = connection->ngramFeatures();
  for (int i = 0; i < ngrams.numRows(); ++i) {
    result.at(i) =
        impl::computeUnrolled4Perceptron(features_, ngrams.row(i), mask);
  }
}

Status HashedFeaturePerceptron::load(const model::ModelInfo &model) {
  return Status::NotImplemented();
}

}  // analysis
}  // core
}  // jumanpp