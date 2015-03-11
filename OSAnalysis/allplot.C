#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "/home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.h"
#include "SS.h"
#include "/home/users/yanjunhe/CORE/muonSelections.h"
#include "/home/users/yanjunhe/CORE/susySelections.h"
#include "TFile.h"
#include "TTree.h"
#include "Math/VectorUtil.h"
#include <iostream>

using namespace Jack;

int allplot(){
 
  TFile *file_data = new TFile("/nfs-3/userdata/danphan/baby_data_new.root");
  TTree *tree_data = (TTree*)file_data->Get("tree");

  //lumi and corr for these events
  float lumi = 5.2; 
  float corr = 1; //running over all files now

  //filling data hists
  TH1F *data_hist = new TH1F("data_hist", "met", 50, 0, 70);
  TH1F *data_hist_pt = new TH1F("data_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *data_hist_eta = new TH1F("data_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *data_hist_phi = new TH1F("data_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *data_hist_pt1 = new TH1F("data_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *data_hist_eta1 = new TH1F("data_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *data_hist_mass1 =  new TH1F("data_hist_mass","mass Z",50,0,150);
  TH1F *data_hist_phi1 = new TH1F("data_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *data_hist_numjet = new TH1F("data_hist_numjet","num jets",8,0,8);
  TH1F *data_hist_jet_pt = new TH1F("data_hist_jet_pt","jet pT",100,25,300);
  TH1F *data_hist_jet_eta = new TH1F("data_hist_jet_eta","jet eta",50,-3.2,3.2);

  object.Init(tree_data);

  unsigned int nEventsTreeData = tree_data->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeData; evt++) { 
 
    object.GetEntry(evt);
    
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
 
    //define jets
    vector <LorentzVector> jets = jets_p4(); 

    //skip if leptons don't pass id/iso
    if (lep1_passes_id() == false || lep2_passes_id() == false) continue; 
 
    LorentzVector z_cand = lep1 + lep2;

    //fill lepton stuff
    data_hist_pt->Fill(lep1.pt());   
    data_hist_pt->Fill(lep2.pt());
    data_hist_eta->Fill(lep1.eta());
    data_hist_eta->Fill(lep2.eta());
    data_hist_phi->Fill(lep1.phi());
    data_hist_phi->Fill(lep2.phi());
    data_hist_pt1->Fill(z_cand.pt());
    data_hist_eta1->Fill(z_cand.eta());
    data_hist_phi1->Fill(z_cand.phi());
    data_hist_mass1->Fill(z_cand.mass()); 
    data_hist->Fill(met());
    data_hist_numjet->Fill(njets());

    //fill jet stuff
    for (unsigned int i = 0; i < jets_p4().size(); i++) { 
      data_hist_jet_pt->Fill((jets_p4().at(i)).pt());
      data_hist_jet_eta->Fill((jets_p4().at(i)).eta());
    }
  }


  //filling TT hists
  TFile *file_TT = new TFile("/nfs-3/userdata/danphan/baby_TT.root");
  TTree *tree_TT = (TTree*)file_TT->Get("tree");
 
  TH1F *TT_hist = new TH1F("TT_hist", "met", 50, 0, 70);
  TH1F *TT_hist_pt = new TH1F("TT_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *TT_hist_eta = new TH1F("TT_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *TT_hist_phi = new TH1F("TT_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *TT_hist_pt1 = new TH1F("TT_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *TT_hist_eta1 = new TH1F("TT_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *TT_hist_mass1 =  new TH1F("TT_hist_mass","mass Z",50,0,150);
  TH1F *TT_hist_phi1 = new TH1F("TT_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *TT_hist_numjet = new TH1F("TT_hist_numjet","num jets",8,0,8);
  TH1F *TT_hist_jet_pt = new TH1F("TT_hist_jet_pt","jet pT",100,25,300);
  TH1F *TT_hist_jet_eta = new TH1F("TT_hist_jet_eta","jet eta",50,-3.2,3.2);

  object.Init(tree_TT);

  unsigned int nEventsTreeTT = tree_TT->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeTT; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
    //define jets
    vector <LorentzVector> jets = jets_p4(); 
    
    //skip if leptons don't pass id/iso
    if (lep1_passes_id() == false || lep2_passes_id() == false) continue; 

    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    TT_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    TT_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    TT_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    TT_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    TT_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    TT_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    TT_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    TT_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    TT_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    TT_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    TT_hist->Fill(met(), scale1fb()*lumi*corr);
    TT_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
    //fill jet stuff
    for (unsigned int i = 0; i < jets_p4().size(); i++) { 
      TT_hist_jet_pt->Fill((jets_p4().at(i)).pt());
      TT_hist_jet_eta->Fill((jets_p4().at(i)).eta());
    }
  }

  //filling TTW hists
  TFile *file_TTW = new TFile("/nfs-3/userdata/danphan/baby_TTW.root");
  TTree *tree_TTW = (TTree*)file_TTW->Get("tree");
 
  TH1F *TTW_hist = new TH1F("TTW_hist", "met", 50, 0, 70);
  TH1F *TTW_hist_pt = new TH1F("TTW_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *TTW_hist_eta = new TH1F("TTW_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *TTW_hist_phi = new TH1F("TTW_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *TTW_hist_pt1 = new TH1F("TTW_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *TTW_hist_eta1 = new TH1F("TTW_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *TTW_hist_mass1 =  new TH1F("TTW_hist_mass","mass Z",50,0,150);
  TH1F *TTW_hist_phi1 = new TH1F("TTW_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *TTW_hist_numjet = new TH1F("TTW_hist_numjet","num jets",8,0,8);
  TH1F *TTW_hist_jet_pt = new TH1F("TTW_hist_jet_pt","jet pT",100,25,300);
  TH1F *TTW_hist_jet_eta = new TH1F("TTW_hist_jet_eta","jet eta",50,-3.2,3.2);

  object.Init(tree_TTW);

  unsigned int nEventsTreeTTW = tree_TTW->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeTTW; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
    
    //define jets
    vector <LorentzVector> jets = jets_p4(); 
  
    //skip if leptons don't pass id/iso
    if (lep1_passes_id() == false || lep2_passes_id() == false) continue; 

    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    TTW_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    TTW_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    TTW_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    TTW_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    TTW_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    TTW_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    TTW_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    TTW_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    TTW_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    TTW_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    TTW_hist->Fill(met(), scale1fb()*lumi*corr);
    TTW_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
    //fill jet stuff
    for (unsigned int i = 0; i < jets_p4().size(); i++) { 
      TTW_hist_jet_pt->Fill((jets_p4().at(i)).pt());
      TTW_hist_jet_eta->Fill((jets_p4().at(i)).eta());
    }
  }

  //filling TTZ hists
  TFile *file_TTZ = new TFile("/nfs-3/userdata/danphan/baby_TTZ.root");
  TTree *tree_TTZ = (TTree*)file_TTZ->Get("tree");
 
  TH1F *TTZ_hist = new TH1F("TTZ_hist", "met", 50, 0, 70);
  TH1F *TTZ_hist_pt = new TH1F("TTZ_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *TTZ_hist_eta = new TH1F("TTZ_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *TTZ_hist_phi = new TH1F("TTZ_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *TTZ_hist_pt1 = new TH1F("TTZ_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *TTZ_hist_eta1 = new TH1F("TTZ_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *TTZ_hist_mass1 =  new TH1F("TTZ_hist_mass","mass Z",50,0,150);
  TH1F *TTZ_hist_phi1 = new TH1F("TTZ_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *TTZ_hist_numjet = new TH1F("TTZ_hist_numjet","num jets",8,0,8);
  TH1F *TTZ_hist_jet_pt = new TH1F("TTZ_hist_jet_pt","jet pT",100,25,300);
  TH1F *TTZ_hist_jet_eta = new TH1F("TTZ_hist_jet_eta","jet eta",50,-3.2,3.2);

  object.Init(tree_TTZ);

  unsigned int nEventsTreeTTZ = tree_TTZ->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeTTZ; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
    
    //define jets
    vector <LorentzVector> jets = jets_p4(); 
  
    //skip if leptons don't pass id/iso
    if (lep1_passes_id() == false || lep2_passes_id() == false) continue; 

    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    TTZ_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    TTZ_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    TTZ_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    TTZ_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    TTZ_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    TTZ_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    TTZ_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    TTZ_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    TTZ_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    TTZ_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    TTZ_hist->Fill(met(), scale1fb()*lumi*corr);
    TTZ_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
    //fill jet stuff
    for (unsigned int i = 0; i < jets_p4().size(); i++) { 
      TTZ_hist_jet_pt->Fill((jets_p4().at(i)).pt());
      TTZ_hist_jet_eta->Fill((jets_p4().at(i)).eta());
    }
  }

  //filling WZ hists
  TFile *file_WZ = new TFile("/nfs-3/userdata/danphan/baby_WZ.root");
  TTree *tree_WZ = (TTree*)file_WZ->Get("tree");
 
  TH1F *WZ_hist = new TH1F("WZ_hist", "met", 50, 0, 70);
  TH1F *WZ_hist_pt = new TH1F("WZ_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *WZ_hist_eta = new TH1F("WZ_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *WZ_hist_phi = new TH1F("WZ_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *WZ_hist_pt1 = new TH1F("WZ_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *WZ_hist_eta1 = new TH1F("WZ_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *WZ_hist_mass1 =  new TH1F("WZ_hist_mass","mass Z",50,0,150);
  TH1F *WZ_hist_phi1 = new TH1F("WZ_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *WZ_hist_numjet = new TH1F("WZ_hist_numjet","num jets",8,0,8);
  TH1F *WZ_hist_jet_pt = new TH1F("WZ_hist_jet_pt","jet pT",100,25,300);
  TH1F *WZ_hist_jet_eta = new TH1F("WZ_hist_jet_eta","jet eta",50,-3.2,3.2);

  object.Init(tree_WZ);

  unsigned int nEventsTreeWZ = tree_WZ->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeWZ; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
    
    //define jets
    vector <LorentzVector> jets = jets_p4(); 
  
    //skip if leptons don't pass id/iso
    if (lep1_passes_id() == false || lep2_passes_id() == false) continue; 

    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    WZ_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    WZ_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    WZ_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    WZ_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    WZ_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    WZ_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    WZ_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    WZ_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    WZ_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    WZ_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    WZ_hist->Fill(met(), scale1fb()*lumi*corr);
    WZ_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
    //fill jet stuff
    for (unsigned int i = 0; i < jets_p4().size(); i++) { 
      WZ_hist_jet_pt->Fill((jets_p4().at(i)).pt());
      WZ_hist_jet_eta->Fill((jets_p4().at(i)).eta());
    }
  }

  //filling DY1 hists, M > 50
  TFile *file_DY1 = new TFile("/nfs-3/userdata/danphan/baby_DY1.root");
  TTree *tree_DY1 = (TTree*)file_DY1->Get("tree");
 
  TH1F *DY1_hist = new TH1F("DY1_hist", "met", 50, 0, 70);
  TH1F *DY1_hist_pt = new TH1F("DY1_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *DY1_hist_eta = new TH1F("DY1_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *DY1_hist_phi = new TH1F("DY1_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *DY1_hist_pt1 = new TH1F("DY1_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *DY1_hist_eta1 = new TH1F("DY1_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *DY1_hist_mass1 =  new TH1F("DY1_hist_mass","mass Z",50,0,150);
  TH1F *DY1_hist_phi1 = new TH1F("DY1_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *DY1_hist_numjet = new TH1F("DY1_hist_numjet","num jets",8,0,8);
  TH1F *DY1_hist_jet_pt = new TH1F("DY1_hist_jet_pt","jet pT",100,25,300);
  TH1F *DY1_hist_jet_eta = new TH1F("DY1_hist_jet_eta","jet eta",50,-3.2,3.2);

  object.Init(tree_DY1);

  unsigned int nEventsTreeDY1 = tree_DY1->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeDY1; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
    
    //define jets
    vector <LorentzVector> jets = jets_p4(); 
  
    //skip if leptons don't pass id/iso
    if (lep1_passes_id() == false || lep2_passes_id() == false) continue; 

    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    DY1_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    DY1_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    DY1_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    DY1_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    DY1_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    DY1_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    DY1_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    DY1_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    DY1_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    DY1_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    DY1_hist->Fill(met(), scale1fb()*lumi*corr);
    DY1_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
    //fill jet stuff
    for (unsigned int i = 0; i < jets_p4().size(); i++) { 
      DY1_hist_jet_pt->Fill((jets_p4().at(i)).pt());
      DY1_hist_jet_eta->Fill((jets_p4().at(i)).eta());
    }
  }

  //filling DY2 hists, 10 < M < 50
  TFile *file_DY2 = new TFile("/nfs-3/userdata/danphan/baby_DY2.root");
  TTree *tree_DY2 = (TTree*)file_DY2->Get("tree");
 
  TH1F *DY2_hist = new TH1F("DY2_hist", "met", 50, 0, 70);
  TH1F *DY2_hist_pt = new TH1F("DY2_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *DY2_hist_eta = new TH1F("DY2_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *DY2_hist_phi = new TH1F("DY2_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *DY2_hist_pt1 = new TH1F("DY2_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *DY2_hist_eta1 = new TH1F("DY2_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *DY2_hist_mass1 =  new TH1F("DY2_hist_mass","mass Z",50,0,150);
  TH1F *DY2_hist_phi1 = new TH1F("DY2_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *DY2_hist_numjet = new TH1F("DY2_hist_numjet","num jets",8,0,8);
  TH1F *DY2_hist_jet_pt = new TH1F("DY2_hist_jet_pt","jet pT",100,25,300);
  TH1F *DY2_hist_jet_eta = new TH1F("DY2_hist_jet_eta","jet eta",50,-3.2,3.2);

  object.Init(tree_DY2);

  unsigned int nEventsTreeDY2 = tree_DY2->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeDY2; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
    
    //define jets
    vector <LorentzVector> jets = jets_p4(); 
  
    //skip if leptons don't pass id/iso
    if (lep1_passes_id() == false || lep2_passes_id() == false) continue; 

    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    DY2_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    DY2_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    DY2_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    DY2_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    DY2_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    DY2_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    DY2_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    DY2_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    DY2_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    DY2_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    DY2_hist->Fill(met(), scale1fb()*lumi*corr);
    DY2_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
    //fill jet stuff
    for (unsigned int i = 0; i < jets_p4().size(); i++) { 
      DY2_hist_jet_pt->Fill((jets_p4().at(i)).pt());
      DY2_hist_jet_eta->Fill((jets_p4().at(i)).eta());
    }
  }

  //using dataMCplotMaker to plot the hists made 
 
  //backgrounds
  vector <TH1F*> vec_hist;

  //names of all backgrounds
  vector <char*> vec_titles;

  vec_titles.push_back("TT");
  vec_titles.push_back("TTW");
  vec_titles.push_back("TTZ");
  vec_titles.push_back("WZ");
  vec_titles.push_back("DY1");
  vec_titles.push_back("DY2");

  //MET 
  vec_hist.push_back(TT_hist); 
  vec_hist.push_back(TTW_hist); 
  vec_hist.push_back(TTZ_hist); 
  vec_hist.push_back(WZ_hist); 
  vec_hist.push_back(DY1_hist);
  vec_hist.push_back(DY2_hist);

  dataMCplotMaker (data_hist,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --outputName met --xAxisLabel MET --legendUp -0.05 --setMaximum 10e11" );
 
  vec_hist.clear();

  //Lepton pT
  vec_hist.push_back(TT_hist_pt);
  vec_hist.push_back(TTW_hist_pt);
  vec_hist.push_back(TTZ_hist_pt);
  vec_hist.push_back(WZ_hist_pt);
  vec_hist.push_back(DY1_hist_pt);
  vec_hist.push_back(DY2_hist_pt);

  dataMCplotMaker (data_hist_pt,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --outputName lep_pt --xAxisLabel pT --legendUp -0.05 --setMaximum 10e11 ");
 
  vec_hist.clear();

  //Lepton Eta
  vec_hist.push_back(TT_hist_eta);
  vec_hist.push_back(TTW_hist_eta);
  vec_hist.push_back(TTZ_hist_eta);
  vec_hist.push_back(WZ_hist_eta);
  vec_hist.push_back(DY1_hist_eta);
  vec_hist.push_back(DY2_hist_eta);

  dataMCplotMaker (data_hist_eta,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit --outputName lep_eta --xAxisLabel #eta --legendUp -0.05 --setMaximum 10e11" );

  vec_hist.clear();

  //Lepton Phi 
  vec_hist.push_back(TT_hist_phi);
  vec_hist.push_back(TTW_hist_phi);
  vec_hist.push_back(TTZ_hist_phi);
  vec_hist.push_back(WZ_hist_phi);
  vec_hist.push_back(DY1_hist_phi);
  vec_hist.push_back(DY2_hist_phi);

  dataMCplotMaker (data_hist_phi,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit --outputName lep_phi --xAxisLabel #phi --legendUp -0.05 --setMaximum 10e11 ");

  vec_hist.clear();

  //Z pT
  vec_hist.push_back(TT_hist_pt1);
  vec_hist.push_back(TTW_hist_pt1);
  vec_hist.push_back(TTZ_hist_pt1);
  vec_hist.push_back(WZ_hist_pt1);
  vec_hist.push_back(DY1_hist_pt1);
  vec_hist.push_back(DY2_hist_pt1);

  dataMCplotMaker (data_hist_pt1,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --outputName Z_pt --xAxisLabel Z pT --legendUp -0.05 --setMaximum 10e11" );

  vec_hist.clear();

  //Z Eta 
  vec_hist.push_back(TT_hist_eta1);
  vec_hist.push_back(TTW_hist_eta1);
  vec_hist.push_back(TTZ_hist_eta1);
  vec_hist.push_back(WZ_hist_eta1);
  vec_hist.push_back(DY1_hist_eta1);
  vec_hist.push_back(DY2_hist_eta1);

  dataMCplotMaker (data_hist_eta1,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit  --outputName Z_eta --xAxisLabel Z #eta --legendRight 0.1 --legendUp -0.05 --setMaximum 10e11 "); 

  vec_hist.clear();

  //Z Phi
  vec_hist.push_back(TT_hist_phi1);
  vec_hist.push_back(TTW_hist_phi1);
  vec_hist.push_back(TTZ_hist_phi1);
  vec_hist.push_back(WZ_hist_phi1);
  vec_hist.push_back(DY1_hist_phi1);
  vec_hist.push_back(DY2_hist_phi1);

  dataMCplotMaker (data_hist_phi1,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2   --legendUp -0.05 --setMaximum 10e11  --noXaxisUnit --outputName Z_phi --xAxisLabel Z #phi"); 

  vec_hist.clear();

  //Z Mass 
  vec_hist.push_back(TT_hist_mass1);
  vec_hist.push_back(TTW_hist_mass1);
  vec_hist.push_back(TTZ_hist_mass1);
  vec_hist.push_back(WZ_hist_mass1);
  vec_hist.push_back(DY1_hist_mass1);
  vec_hist.push_back(DY2_hist_mass1);

  dataMCplotMaker (data_hist_mass1,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --legendUp -0.05 --setMaximum 10e11  --outputName Z_mass --xAxisLabel Z mass"); 

  vec_hist.clear();

  //Num Jets 
  vec_hist.push_back(TT_hist_numjet);
  vec_hist.push_back(TTW_hist_numjet);
  vec_hist.push_back(TTZ_hist_numjet);
  vec_hist.push_back(WZ_hist_numjet);
  vec_hist.push_back(DY1_hist_numjet);
  vec_hist.push_back(DY2_hist_numjet);

  dataMCplotMaker (data_hist_numjet,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --legendUp -0.05 --setMaximum 10e11 --noXaxisUnit --xAxisLabel number of jets  --outputName numjets --noDivisionLabel"); 

  vec_hist.clear();

  //Jet Eta
  vec_hist.push_back(TT_hist_jet_eta);
  vec_hist.push_back(TTW_hist_jet_eta);
  vec_hist.push_back(TTZ_hist_jet_eta);
  vec_hist.push_back(WZ_hist_jet_eta);
  vec_hist.push_back(DY1_hist_jet_eta);
  vec_hist.push_back(DY2_hist_jet_eta);

  dataMCplotMaker (data_hist_jet_eta,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit --outputName jet_eta --xAxisLabel #eta --legendUp -0.05 --setMaximum 10e11" );

  vec_hist.clear();

  //Jet pT 
  vec_hist.push_back(TT_hist_jet_pt);
  vec_hist.push_back(TTW_hist_jet_pt);
  vec_hist.push_back(TTZ_hist_jet_pt);
  vec_hist.push_back(WZ_hist_jet_pt);
  vec_hist.push_back(DY1_hist_jet_pt);
  vec_hist.push_back(DY2_hist_jet_pt);

  dataMCplotMaker (data_hist_jet_pt,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit --outputName jet_pt --xAxisLabel #pT --legendUp -0.05 --setMaximum 10e11" );

  return 0;
}
