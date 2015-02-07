{

  gSystem->Load("~/CORE/libCMS2NtupleMacrosCORE.so");
  //gROOT->Load("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/merged_ntuple_100.root");
  //gROOT->Load("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/DYJetsToLL_M-10To50filter_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-13_slim/merged_ntuple_100.root");
  gROOT->ProcessLine(".L /home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.cc+");
  gROOT->ProcessLine(".L /home/users/yanjunhe/SS.cc+");
  gROOT->ProcessLine(".L baby.C+");
 // gROOT->ProcessLine("babyMaker()");
  gROOT->ProcessLine("baby()");
  //gROOT->ProcessLine(".exception");
}
