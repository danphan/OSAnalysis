#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "/home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.h"
#include "SS.h"
#include "/home/users/yanjunhe/CORE/muonSelections.h"
#include "/home/users/yanjunhe/CORE/susySelections.h"
#include "TFile.h"
#include "TTree.h"
#include "Math/VectorUtil.h"

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

  object.Init(tree_data);

  unsigned int nEventsTreeData = tree_data->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeData; evt++) { 
 
    object.GetEntry(evt);
    
  //  //Check for duplicates 
  //  if (isData == true){
  //      duplicate_removal::DorkyEventIdentifier id(run, event, lumi);
  //      if (duplicate_removal::is_duplicate(id)) continue;
  //    }

    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
    LorentzVector z_cand = lep1 + lep2;

    //fill plots with information about dileptons
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

  object.Init(tree_TT);

  unsigned int nEventsTreeTT = tree_TT->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeTT; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
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

  object.Init(tree_TTW);

  unsigned int nEventsTreeTTW = tree_TTW->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeTTW; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
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

  object.Init(tree_TTZ);

  unsigned int nEventsTreeTTZ = tree_TTZ->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeTTZ; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
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

  object.Init(tree_WZ);

  unsigned int nEventsTreeWZ = tree_WZ->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeWZ; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
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
    
  }

  //filling DY hists
  TFile *file_DY = new TFile("/nfs-3/userdata/danphan/baby_DY.root");
  TTree *tree_DY = (TTree*)file_DY->Get("tree");
 
  TH1F *DY_hist = new TH1F("DY_hist", "met", 50, 0, 70);
  TH1F *DY_hist_pt = new TH1F("DY_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *DY_hist_eta = new TH1F("DY_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *DY_hist_phi = new TH1F("DY_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *DY_hist_pt1 = new TH1F("DY_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *DY_hist_eta1 = new TH1F("DY_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *DY_hist_mass1 =  new TH1F("DY_hist_mass","mass Z",50,0,150);
  TH1F *DY_hist_phi1 = new TH1F("DY_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *DY_hist_numjet = new TH1F("DY_hist_numjet","num jets",8,0,8);

  object.Init(tree_DY);

  unsigned int nEventsTreeDY = tree_DY->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeDY; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    DY_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    DY_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    DY_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    DY_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    DY_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    DY_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    DY_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    DY_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    DY_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    DY_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    DY_hist->Fill(met(), scale1fb()*lumi*corr);
    DY_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
  }




 
  //using dataMCplotMaker to plot the hists made 
 
  //backgrounds
  vector <TH1F*> vec1_hist,vec2_hist,vec3_hist,vec4_hist,vec5_hist,vec6_hist,vec7_hist,vec_hist,vec8_hist;

  //names of all backgrounds
  vector <char*> vec1_titles,vec2_titles,vec3_titles,vec4_titles,vec5_titles,vec6_titles,vec7_titles,vec_titles,vec8_titles;

  //MET 
  vec_hist.push_back(TT_hist); 
  vec_hist.push_back(TTW_hist); 
  vec_hist.push_back(TTZ_hist); 
  vec_hist.push_back(WZ_hist); 
  vec_hist.push_back(DY_hist);
 
  vec_titles.push_back("TT");
  vec_titles.push_back("TTW");
  vec_titles.push_back("TTZ");
  vec_titles.push_back("WZ");
  vec_titles.push_back("DY");

  dataMCplotMaker (data_hist,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --outputName met --xAxisLabel MET --legendUp -0.05 --setMaximum 10e11" );
 
  //Lepton pT
  vec1_hist.push_back(TT_hist_pt);
  vec1_hist.push_back(TTW_hist_pt);
  vec1_hist.push_back(TTZ_hist_pt);
  vec1_hist.push_back(WZ_hist_pt);
  vec1_hist.push_back(DY_hist_pt);

  vec1_titles.push_back("TT");
  vec1_titles.push_back("TTW");
  vec1_titles.push_back("TTZ");
  vec1_titles.push_back("WZ");
  vec1_titles.push_back("DY");

  dataMCplotMaker (data_hist_pt,vec1_hist,vec1_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --outputName lep_pt --xAxisLabel pT --legendUp -0.05 --setMaximum 10e11 ");
 
  //Lepton Eta
  vec2_hist.push_back(TT_hist_eta);
  vec2_hist.push_back(TTW_hist_eta);
  vec2_hist.push_back(TTZ_hist_eta);
  vec2_hist.push_back(WZ_hist_eta);
  vec2_hist.push_back(DY_hist_eta);

  vec2_titles.push_back("TT");
  vec2_titles.push_back("TTW");
  vec2_titles.push_back("TTZ");
  vec2_titles.push_back("WZ");
  vec2_titles.push_back("DY");

  dataMCplotMaker (data_hist_eta,vec2_hist,vec2_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit --outputName lep_eta --xAxisLabel #eta --legendUp -0.05 --setMaximum 10e11" );

  //Lepton Phi 
  vec3_hist.push_back(TT_hist_phi);
  vec3_hist.push_back(TTW_hist_phi);
  vec3_hist.push_back(TTZ_hist_phi);
  vec3_hist.push_back(WZ_hist_phi);
  vec3_hist.push_back(DY_hist_phi);

  vec3_titles.push_back("TT");
  vec3_titles.push_back("TTW");
  vec3_titles.push_back("TTZ");
  vec3_titles.push_back("WZ");
  vec3_titles.push_back("DY");

  dataMCplotMaker (data_hist_phi,vec3_hist,vec3_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit --outputName lep_phi --xAxisLabel #phi --legendUp -0.05 --setMaximum 10e11 ");

  //Z pT
  vec4_hist.push_back(TT_hist_pt1);
  vec4_hist.push_back(TTW_hist_pt1);
  vec4_hist.push_back(TTZ_hist_pt1);
  vec4_hist.push_back(WZ_hist_pt1);
  vec4_hist.push_back(DY_hist_pt1);

  vec4_titles.push_back("TT");
  vec4_titles.push_back("TTW");
  vec4_titles.push_back("TTZ");
  vec4_titles.push_back("WZ");
  vec4_titles.push_back("DY");

  dataMCplotMaker (data_hist_pt1,vec4_hist,vec4_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --outputName Z_pt --xAxisLabel Z pT --legendUp -0.05 --setMaximum 10e11" );

  //Z Eta 
  vec5_hist.push_back(TT_hist_eta1);
  vec5_hist.push_back(TTW_hist_eta1);
  vec5_hist.push_back(TTZ_hist_eta1);
  vec5_hist.push_back(WZ_hist_eta1);
  vec5_hist.push_back(DY_hist_eta1);

  vec5_titles.push_back("TT");
  vec5_titles.push_back("TTW");
  vec5_titles.push_back("TTZ");
  vec5_titles.push_back("WZ");
  vec5_titles.push_back("DY");

  dataMCplotMaker (data_hist_eta1,vec5_hist,vec5_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2  --noXaxisUnit  --outputName Z_eta --xAxisLabel Z #eta --legendRight 0.1 --legendUp -0.05 --setMaximum 10e11 "); 

  //Z Phi
  vec6_hist.push_back(TT_hist_phi1);
  vec6_hist.push_back(TTW_hist_phi1);
  vec6_hist.push_back(TTZ_hist_phi1);
  vec6_hist.push_back(WZ_hist_phi1);
  vec6_hist.push_back(DY_hist_phi1);

  vec6_titles.push_back("TT");
  vec6_titles.push_back("TTW");
  vec6_titles.push_back("TTZ");
  vec6_titles.push_back("WZ");
  vec6_titles.push_back("DY");

  dataMCplotMaker (data_hist_phi1,vec6_hist,vec6_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2   --legendUp -0.05 --setMaximum 10e11  --noXaxisUnit --outputName Z_phi --xAxisLabel Z #phi"); 

  //Z Mass 
  vec7_hist.push_back(TT_hist_mass1);
  vec7_hist.push_back(TTW_hist_mass1);
  vec7_hist.push_back(TTZ_hist_mass1);
  vec7_hist.push_back(WZ_hist_mass1);
  vec7_hist.push_back(DY_hist_mass1);

  vec7_titles.push_back("TT");
  vec7_titles.push_back("TTW");
  vec7_titles.push_back("TTZ");
  vec7_titles.push_back("WZ");
  vec7_titles.push_back("DY");

  dataMCplotMaker (data_hist_mass1,vec7_hist,vec7_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --legendUp -0.05 --setMaximum 10e11  --outputName Z_mass --xAxisLabel Z mass"); 

  //Num Jets 
  vec8_hist.push_back(TT_hist_numjet);
  vec8_hist.push_back(TTW_hist_numjet);
  vec8_hist.push_back(TTZ_hist_numjet);
  vec8_hist.push_back(WZ_hist_numjet);
  vec8_hist.push_back(DY_hist_numjet);

  vec8_titles.push_back("TT");
  vec8_titles.push_back("TTW");
  vec8_titles.push_back("TTZ");
  vec8_titles.push_back("WZ");
  vec8_titles.push_back("DY");

  dataMCplotMaker (data_hist_numjet,vec8_hist,vec8_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --legendUp -0.05 --setMaximum 10e11 --noXaxisUnit --xAxisLabel number of jets  --outputName numjets --noDivisionLabel"); 

  return 0;
}
