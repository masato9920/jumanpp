//
// Created by Arseny Tolmachev on 2017/03/31.
//

#include "trainer.h"
#include "scw.h"
#include "training_test_common.h"

using namespace jumanpp::core::training;

class TrainerEnv : public GoldExampleEnv {
 public:
  static TrainingConfig testConf() {
    TrainingConfig tc;
    tc.numHashedFeatures = 4096;
    return tc;
  }

  core::training::TrainingDataReader rdr;
  Trainer trainer;
  TrainerEnv(StringPiece s, bool kataUnks = false)
      : GoldExampleEnv(s, kataUnks),
        trainer{anaImpl(), &env.saveLoad.training, testConf()} {
    rdr.initialize(env.saveLoad.training, core());
  }

  void parseMrph(StringPiece data) {
    REQUIRE_OK(rdr.initDoubleCsv(data));
    REQUIRE_OK(rdr.readFullExample(anaImpl()->extraNodesContext(),
                                   &trainer.example()));
  }

  std::unique_ptr<testing::TestAnalyzer> newAnalyzer(const ScoreConfig* sconf) {
    std::unique_ptr<testing::TestAnalyzer> ptr{
        new testing::TestAnalyzer{env.core.get(), env.aconf}};
    ptr->initScorers(*sconf);
    return ptr;
  }
};

TEST_CASE("trainer can compute score for a simple sentence") {
  StringPiece dic = "もも,N,0\nも,PRT,1\n";
  StringPiece ex = "もも_N_0 も_PRT_1 もも_N_0\n";
  TrainerEnv env{dic};
  env.parseMrph(ex);
  SoftConfidenceWeighted scw{TrainerEnv::testConf()};
  CHECK(env.trainer.example().numNodes() == 3);
  CHECK(env.trainer.prepare());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  CHECK(env.trainer.lossValue() > 0);
}

TEST_CASE(
    "trainer can compute score for a simple sentence and update weights") {
  StringPiece dic = "もも,N,0\nも,PRT,1\n";
  StringPiece ex = "もも_N_0 も_PRT_1 もも_N_0\n";
  TrainerEnv env{dic};
  env.parseMrph(ex);
  SoftConfidenceWeighted scw{TrainerEnv::testConf()};
  CHECK(env.trainer.example().numNodes() == 3);
  CHECK(env.trainer.prepare());
  auto mem1 = env.anaImpl()->usedMemory();
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  auto mem2 = env.anaImpl()->usedMemory();
  CHECK(env.trainer.lossValue() > 0);
  scw.update(env.trainer.lossValue(), env.trainer.featureDiff());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  auto mem3 = env.anaImpl()->usedMemory();
  CHECK(env.trainer.lossValue() == 0);
  CHECK(mem1 == mem2);
  CHECK(mem1 == mem3);
}

TEST_CASE("trainer can compute score for sentence with full unks") {
  StringPiece dic = "UNK,N,10\nもも,N,0\nも,PRT,1\nモ,PRT,2";
  StringPiece ex = "モモ_N_10 も_PRT_1 もも_N_0\n";
  TrainerEnv env{dic, true};  // use unks
  env.parseMrph(ex);
  SoftConfidenceWeighted scw{TrainerEnv::testConf()};
  CHECK(env.trainer.example().numNodes() == 3);
  CHECK(env.trainer.prepare());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  CHECK(env.trainer.lossValue() > 0);
  scw.update(env.trainer.lossValue(), env.trainer.featureDiff());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  CHECK(env.trainer.lossValue() == 0);
}

TEST_CASE("trainer can compute score for sentence with part unks") {
  StringPiece dic = "UNK,N,5\nもも,N,0\nも,PRT,1\nモ,PRT,2";
  StringPiece ex = "モモ_N_10 も_PRT_1 もも_N_0\n";
  TrainerEnv env{dic, true};  // use unks
  env.parseMrph(ex);
  SoftConfidenceWeighted scw{TrainerEnv::testConf()};
  CHECK(env.trainer.example().numNodes() == 3);
  CHECK(env.trainer.prepare());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  CHECK(env.trainer.lossValue() > 0);
  scw.update(env.trainer.lossValue(), env.trainer.featureDiff());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  CHECK(env.trainer.lossValue() == 0);
  CHECK(env.top1Node(0) == ExampleData("モモ", "N", "5"));
}

TEST_CASE("trainer can compute score for sentence with other POS unks") {
  StringPiece dic = "UNK,N,5\nもも,N,0\nも,PRT,1\nモ,PRT,2\n寝る,V,3";
  StringPiece ex = "モモ_V_10 も_PRT_1 もも_N_0\n";
  TrainerEnv env{dic, true};  // use unks
  env.parseMrph(ex);
  SoftConfidenceWeighted scw{TrainerEnv::testConf()};
  CHECK(env.trainer.example().numNodes() == 3);
  CHECK(env.trainer.prepare());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  CHECK(env.trainer.lossValue() > 0);
  scw.update(env.trainer.lossValue(), env.trainer.featureDiff());
  CHECK(env.trainer.compute(scw.scoreConfig()));
  env.trainer.computeTrainingLoss();
  CHECK(env.trainer.lossValue() == 0);

  auto ana2 = env.newAnalyzer(scw.scoreConfig());
  REQUIRE_OK(ana2->fullAnalyze("モモももも", scw.scoreConfig()));
  AnalyzerMethods am{ana2.get()};
  CHECK(am.top1Node(0) == ExampleData("モモ", "N", "5"));
  CHECK(am.top1Node(1) == ExampleData("も", "PRT", "1"));
  CHECK(am.top1Node(2) == ExampleData("もも", "N", "0"));
}