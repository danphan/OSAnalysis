#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "/home/users/danphan/OSAnalysis/baby.h"
#include "TChain.h"
//runs baby on files that we want it to run over

enum which_baby {DY1, DY2, TT, TTW, TTZ, WZ1, WZ2, EE1, EE2, EE3, MM1, MM2, MM3};


int callsBaby() {

  //which determines which baby.root file we're making
  which_baby which = EE1;

  //for MC files, we'll choose muons first

  //baby_DY1 M50+
  if (which == DY1) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/*.root");

  char* outputName = "baby_DY1";
  evt_type type = ee;  
 
  baby(chain,outputName,type);
  }

  //baby_DY2, M10-50
  if (which == DY2) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/DYJetsToLL_M-10To50filter_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-13_slim/*.root");

  char* outputName = "baby_DY2";
  evt_type type = ee;  
 
  baby(chain,outputName,type);
  }

  //baby_TT
  if (which == TT) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/TTJets_FullLeptMGDecays_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v2/V05-03-24/*.root");

  char* outputName = "baby_TT";
  evt_type type = ee;  
 
  baby(chain,outputName,type);
  }

  //babyTTW
  if (which == TTW) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/TTWJets_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/*.root");
  char* outputName = "baby_TTW";
  evt_type type = mm;  
 
  baby(chain,outputName,type);
  }

  //babyTTZ
  if (which == TTZ) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/TTZJets_8TeV-madgraph_v2_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/*.root");
  char* outputName = "baby_TTZ";
  evt_type type  = mm;  
 
  baby(chain,outputName,type);
  }

  //babyWZ1
  if (which == WZ1) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/WZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/*.root");
  char* outputName = "baby_WZ1";
  evt_type type = mm;  
 
  baby(chain,outputName,type);
  }

  //babyWZ2
  if (which == WZ2) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/WZJetsTo3LNu_TuneZ2_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/*.root");
  char* outputName = "baby_WZ2";
  evt_type type = mm;  
 
  baby(chain,outputName,type);
  }
  
  //baby_MM1
  if (which == MM1) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleMu_Run2012A-recover-06Aug2012-v1_AOD/merged/*.root");
  char* outputName = "baby_MM1";
  evt_type type = mm;  
 
  baby(chain,outputName,type);
  }

  //baby5/MM2  the one with the error on file 50
  if (which == MM2) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleMu_Run2012A-13Jul2012-v1_AOD/merged/*.root");
  char* outputName = "baby_MM2";
  evt_type type = mm;  
 
  baby(chain,outputName,type);
  }

  //baby_MM3
  if (which == MM3) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleMu_Run2012B-13Jul2012-v4_AOD/merged/*.root");
  char* outputName = "baby_MM3";
  evt_type type = mm;  
 
  baby(chain,outputName,type);
  }

  //baby_EE1_
  if (which == EE1) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleElectron_Run2012A-13Jul2012-v1_AOD/merged/*.root");
  char* outputName = "baby_EE1";
  evt_type type = ee;  
 
  baby(chain,outputName,type);
  }

  //baby_EE2_
  if (which == EE2) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleElectron_Run2012A-recover-06Aug2012-v1_AOD/merged/*.root");
  char* outputName = "baby_EE2";
  evt_type type = ee;  
 
  baby(chain,outputName,type);
  }

  //baby_EE3_
  if (which == EE3) { 
  //defines chain to pass to baby, outputName to give baby
  TChain *chain = new TChain("Events");
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleElectron_Run2012B-13Jul2012-v1_AOD/merged/*.root");
  char* outputName = "baby_EE3";
  evt_type type = ee;  
 
  baby(chain,outputName,type);
  }


  return 0;
}
