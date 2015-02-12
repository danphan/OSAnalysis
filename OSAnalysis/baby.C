#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "/home/users/danphan/Jack/CORE/CMS2.h"
#include "/home/users/cgeorge/CORE/CORE-run1/susySelections.h"
#include "/home/users/cgeorge/CORE/CORE-run1/muonSelections.h"
#include "/home/users/cgeorge/CORE/CORE-run1/ssSelections.h"
#include "TFile.h"
#include "TTree.h"
#include "Math/VectorUtil.h" //needed for deltaR stuff
#include "TChain.h"

#include "/home/users/cgeorge/old_stuff/analysis/SS/EXTERNAL/dorky.h"
#include "/home/users/yanjunhe/Tools/goodrun.h"

using namespace std;

//Parameters
//char* input_filename  = "/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/merged_ntuple_100.root";
char* outputName = "baby4";
char* treeName = "babyTree";

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

//switch to choose whether to loop through all events or not
int allEvents = 50; //Set allEvents to whatever you want

int chooseBestHyp(){

  //Vector for passing hyps
  vector <int> goodhyp;
  vector <int> pass1;
  vector <int> pass2;

  for (unsigned int i = 0; i < tas::hyp_ll_p4().size(); i++){  
  
    //Choosing p4, ID
    LorentzVector lep1 = tas::hyp_ll_p4().at(i);
    LorentzVector lep2 = tas::hyp_lt_p4().at(i); 
    int id1 = tas::hyp_ll_id().at(i);
    int id2 = tas::hyp_lt_id().at(i);

    //Throw away SS leptons
    if (id1*id2 > 0) continue;

    //Throw away if leptons are not same flavor
    if (abs(id1) != abs(id2)) continue;
  
    //Kinematic cuts
    if (lep1.pt()<=20) continue;
    if (lep2.pt()<=20) continue; 
    if (abs(lep1.eta()) >= 2.4) continue;
    if (abs(lep2.eta()) >= 2.4) continue; 

    //If we get here, it is a good hyp
    goodhyp.push_back(i);   

  }
  
  //Loop over good hyps 
  for (unsigned int j = 0; j < goodhyp.size(); j++){ 
    int index = goodhyp[j];  
  
    int id1 = tas::hyp_ll_id().at(index);  
    int id2 = tas::hyp_lt_id().at(index);

    bool lep1_passes_id = abs(id1) == 11 ? passElectronSelection_ZMet2012_v3_Iso(tas::hyp_ll_index().at(index)) : muonId(tas::hyp_ll_index().at(index), ZMet2012_v1); 
    bool lep2_passes_id = abs(id2) == 11 ? passElectronSelection_ZMet2012_v3_Iso(tas::hyp_lt_index().at(index)) : muonId(tas::hyp_lt_index().at(index), ZMet2012_v1); 
 
    if (lep1_passes_id && lep2_passes_id) pass1.push_back(goodhyp.at(j));

  }

  //If there is 1 hyp in pass1 vector, then choose that one  
  if (pass1.size() == 1) return pass1[0];

  //N.B. NOW REDEFINE PASS1 TO BE VECTOR OF ALL GOOD HYPS STILL BEING CONSIDERED
  if (pass1.size() == 0)  pass1 = goodhyp;

  //If pass1 empty, return -1;
  if (pass1.size() < 1) return -1;
  
  //If pass1 has just 1 thing, return it
  if (pass1.size() == 1) return pass1[0];

  //If pass1 has 2+ things, need to pick. Pass2 is for dimuon events
  if (pass1.size() > 1){ 
    for (unsigned int k = 0; k < pass1.size(); k++){
      int index2 = pass1[k];
      int id1 = tas::hyp_ll_id().at(index2);
      int id2 = tas::hyp_lt_id().at(index2);
      if  (abs(id1) == 13 && abs(id2) == 13)
      pass2.push_back(index2);
    }
  }
   
  //If there are no dimuon events, go for emu events
  if (pass2.size() == 0){
    for (unsigned int k = 0; k < pass1.size(); k++) {       
      int index2 = pass1[k];
      int id1 = tas::hyp_ll_id().at(index2);
      int id2 = tas::hyp_lt_id().at(index2);
      if ( (abs(id1) == 11 && abs(id2) == 13) || (abs(id1) == 13 && (abs(id2) == 11) )) pass2.push_back(index2);
    }
  }
  
  //If there are also no emu events, for for dielectron 
  if (pass2.size() == 0){
    for (unsigned int k = 0; k < pass1.size(); k++) {       
      int index2 = pass1[k];
      int id1 = tas::hyp_ll_id().at(index2);
      int id2 = tas::hyp_lt_id().at(index2);
      if  (abs(id1) == 11 && abs(id2) == 11) pass2.push_back(index2);
    }   
  }

  //Pass 2 now has all hyps of best class.  If only one entry, done
  if (pass2.size() == 1) return pass2[0];
  
  //If still 2+ options, choose case with highest scalar dilepton pT
  int index4 = -1;
  if (pass2.size() > 1){
    float maxpt = 0;
    int index3 = -1;
   
    for(unsigned int q = 0; q < pass2.size(); q++){
      index3 = pass2[q];
      LorentzVector lp1 = tas::hyp_ll_p4().at(index3);
      LorentzVector lp2 = tas::hyp_lt_p4().at(index3);
      float totalpt = lp1.pt()+lp2.pt();
      if (totalpt>=maxpt){
        maxpt = totalpt; 
        index4 = index3;
      }
    }
  }
  
  return index4;

}


int baby(){

 //list of root files
  TChain *chain = new TChain("Events"); 
  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleMu_Run2012A-recover-06Aug2012-v1_AOD/merged/*.root");
// for (int i = 1; i <= 152; i++)
//  chain->Add("/hadoop/cms/store/group/snt/papers2012/Data2012/CMSSW_5_3_2_patch4_V05-03-24/DoubleElectron_Run2012A-13Jul2012-v1_AOD/merged/merged_ntuple_%d.root",i);

  set_goodrun_file("/home/users/jgran/analysis/sswh/fakes/json/final_19p49fb_cms2.txt");

  unsigned int nEventsDone = 0;
  unsigned int nEventsToDo = chain->GetEntries();
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

 //Declare TTree and TFile that will be filled with data
  TFile *file_new = new TFile(Form("%s.root", outputName), "RECREATE");
  TTree *tree_new = new TTree("tree", Form("%s",treeName));  

 while ((currentFile = (TFile*)fileIter.Next())) {

  // TFile *file = new TFile(Form("%s",input_filename)); 
  //open up file that has data in it 
  if (nEventsDone >= nEventsToDo) continue;
  TFile *file = new TFile(currentFile->GetTitle());
  TTree *tree = (TTree*)file->Get("Events");

  cms2.Init(tree);
  bool isData = cms2.evt_isRealData();

 
 
 
  //initializing variable to be filled in tree
  float met = 0;
  int njets = 0;
  float ht = 0;
  float scale1fb = 0; 
  int lep1_id = 0;
  int lep2_id = 0;
  int lep1_idx = 0; 
  int lep2_idx = 0; 
  int lep1_mc_id = 0;
  int lep2_mc_id = 0;
  int hyp_type = -1; 
  float lep1_iso = -1; 
  float lep2_iso = -1;
  bool lep1_passes_id = false; 
  bool lep2_passes_id = false; 
  LorentzVector lep1_p4;
  LorentzVector lep2_p4;
  vector <LorentzVector> jets_p4;
  vector <float> jets_disc;
  vector <int> gen_id;
  vector <int> gen_status;
  vector <LorentzVector> gen_p4;
  int event = 0;
  int lumi = 0;
  int run = 0;
  int nBjets = 0;
  TString filename;

  //Branches
  tree_new->Branch("met", &met);
  tree_new->Branch("ht", &ht);
  tree_new->Branch("njets", &njets);
  tree_new->Branch("lep1_id", &lep1_id);
  tree_new->Branch("lep2_id", &lep2_id);
  tree_new->Branch("lep1_idx", &lep1_idx);
  tree_new->Branch("lep2_idx", &lep2_idx);
  tree_new->Branch("lep1_mc_id", &lep1_mc_id);
  tree_new->Branch("lep2_mc_id", &lep2_mc_id);
  tree_new->Branch("hyp_type", &hyp_type);
  tree_new->Branch("lep1_iso", &lep1_iso);
  tree_new->Branch("lep2_iso", &lep2_iso);
  tree_new->Branch("lep1_passes_id", &lep1_passes_id);
  tree_new->Branch("lep2_passes_id", &lep2_passes_id);
  tree_new->Branch("lep1_p4", &lep1_p4);
  tree_new->Branch("lep2_p4", &lep2_p4);
  tree_new->Branch("scale1fb", &scale1fb);
  tree_new->Branch("jets_p4",&jets_p4);
  tree_new->Branch("jets_disc",&jets_disc);
  tree_new->Branch("event", &event);
  tree_new->Branch("lumi", &lumi);
  tree_new->Branch("run", &run);
  tree_new->Branch("gen_id", &gen_id);
  tree_new->Branch("gen_status", &gen_status);
  tree_new->Branch("gen_p4", &gen_p4);
  tree_new->Branch("filename", &filename);
  tree_new->Branch("nBjets", &nBjets);

  unsigned int nEventsTree = tree->GetEntries(); 

  //Loop over all events in tree of current file
  for(unsigned int evt = 0; evt < (allEvents == -1 ? nEventsTree : allEvents) ; evt++){

    cms2.GetEntry(evt);
  
    //Initialize
    njets = 0;
    nBjets = 0;
    ht = 0; 
    if (tas::hyp_ll_id().size() < 1) continue;
  
    //Choose Best Hypothesis
    int index = chooseBestHyp();
    if (index < 0) continue;
  
    //Progress bar
    CMS2::progress(evt, nEventsTree); 

    //if real data, check to see if on good run list
    if (isData == true && goodrun(cms2.evt_run(), cms2.evt_lumiBlock()) == false) continue;

  
    //Event Stuff
    scale1fb = tas::evt_scale1fb();   
    event = tas::evt_event();
    lumi = tas::evt_lumiBlock();
    run = tas::evt_run();

     //Check for duplicates
     if (isData == true){
               duplicate_removal::DorkyEventIdentifier id(run, event, lumi); 
               if (duplicate_removal::is_duplicate(id)) continue; 
    }


    //Filename
    //filename = currentFile->GetTitle(); 

    //Met Stuff
    met = tas::evt_pfmet();         
                                         
    //Lepton Stuff
    lep1_id = tas::hyp_ll_id().at(index);
    lep2_id = tas::hyp_lt_id().at(index);
    lep1_idx = tas::hyp_ll_index().at(index);
    lep2_idx = tas::hyp_lt_index().at(index);

    if (isData == false) {
    lep1_mc_id = abs(lep1_id) == 11 ? tas::els_mc_id().at(lep1_idx) : tas::mus_mc_id().at(lep1_idx);
    lep2_mc_id = abs(lep2_id) == 11 ? tas::els_mc_id().at(lep2_idx) : tas::mus_mc_id().at(lep2_idx);
    hyp_type = tas::hyp_type().at(index); } 
     else {lep1_mc_id = 1; lep2_mc_id = 1;}

    lep1_iso = abs(lep1_id) == 11 ? samesign::electronIsolationPF2012(lep1_idx) : muonIsoValuePF2012_deltaBeta(lep1_idx);
    lep2_iso = abs(lep2_id) == 11 ? samesign::electronIsolationPF2012(lep2_idx) : muonIsoValuePF2012_deltaBeta(lep2_idx);
    lep1_passes_id = false;  
    lep2_passes_id = false;
    lep1_p4 = tas::hyp_ll_p4().at(index);
    lep2_p4 = tas::hyp_lt_p4().at(index);

  if (isData == false){  //Gen Stuff
    for (unsigned int gidx = 0; gidx < tas::genps_p4().size(); gidx++){
      int status = tas::genps_status().at(gidx);
      int id = tas::genps_id().at(gidx);
      LorentzVector p4 = tas::genps_p4().at(gidx);

      gen_status.push_back(status);
      gen_id.push_back(id);
      gen_p4.push_back(p4);
     }
   } else {
           int status = 1; int id = 1; LorentzVector p4;
           gen_status.push_back(status);             
           gen_id.push_back(id);
           gen_p4.push_back(p4);
   }

    //Jet stuff
    for(unsigned int j = 0; j < tas::pfjets_p4().size(); j++){

      LorentzVector jet = tas::pfjets_p4().at(j);
      if (jet.pt() <= 30) continue; 
      if (abs(jet.eta())>=3 ) continue;
      if (ROOT::Math::VectorUtil::DeltaR(lep1_p4, jet) < 0.1) continue; 
      if (ROOT::Math::VectorUtil::DeltaR(lep2_p4, jet) < 0.1) continue;

      njets++;
      ht += jet.pt();
      jets_p4.push_back(jet);
      float disc = tas::pfjets_combinedSecondaryVertexBJetTag().at(j);
      jets_disc.push_back(disc);

      if (disc > 0.679) nBjets++;

    }
    
      tree_new->Fill();  
  }

}

  file_new->cd();
  tree_new->Write();

 
  return 0;

}
