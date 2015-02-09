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
 
  TFile *file = new TFile("baby.root");


  TTree *tree = (TTree*)file->Get("tree");

  //lumi and corr for these events

  float lumi = 19.5;

  float corr = 5872648/40000;

 
  TH1F *hist = new TH1F("hist", "met", 50, 0, 70);
  TH1F *hist_pt = new TH1F("hist_pt", "p_{T}", 50, 0, 100);
  TH1F *hist_eta = new TH1F("hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *hist_phi = new TH1F("hist_phi","phi", 50, -3.5, 3.5);
  TH1F *hist_pt1 = new TH1F("hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *hist_eta1 = new TH1F("hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *hist_mass1 =  new TH1F("hist_mass","mass Z",50,0,150);
  TH1F *hist_phi1 = new TH1F("hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *hist_numjet = new TH1F("hist_numjet","num jets",8,0,8);

  cout << tree->GetEntries() << endl;
  
  Object.Init(tree);

  unsigned int nEventsTree = tree->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTree; evt++) { 
 
    Object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    hist->Fill(met(), scale1fb()*lumi*corr);
    hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
  }
 
  //using dataMCplotMaker to plot the hists made 
  
  TH1F* null = new TH1F("","",1,0,1);
 
  vector <TH1F*> vec1_hist,vec2_hist,vec3_hist,vec4_hist,vec5_hist,vec6_hist,vec7_hist,vec_hist,vec8_hist;

  vector <char*> vec1_titles,vec2_titles,vec3_titles,vec4_titles,vec5_titles,vec6_titles,vec7_titles,vec_titles,vec8_titles;
 
  vec_hist.push_back(hist); 
  vec_titles.push_back("Z #rightarrow l^{+} l^{-}");
  dataMCplotMaker (null,vec_hist,vec_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--legendRight -0.05 --isLinear --outputName met --xAxisLabel MET");
 
  vec1_hist.push_back(hist_pt);
  vec1_titles.push_back("Z #rightarrow l^{+} l^{-}");
  dataMCplotMaker (null,vec1_hist,vec1_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--legendRight -0.05 --isLinear --outputName lep_pt --xAxisLabel pt");
 
  vec2_hist.push_back(hist_eta);
  vec2_titles.push_back("Z #rightarrow l^{+} l^{-}");
  dataMCplotMaker (null,vec2_hist,vec2_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05 --noXaxisUnit --outputName lep_eta --xAxisLabel eta");

  vec3_hist.push_back(hist_phi);
  vec3_titles.push_back("Z #rightarrow l^{+} l^{-}");
  dataMCplotMaker (null,vec3_hist,vec3_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05 --noXaxisUnit --outputName lep_phi --xAxisLabel phi");

  vec4_hist.push_back(hist_pt1);
  vec4_titles.push_back("Z #rightarrow l^{+} l^{-}");
  dataMCplotMaker (null,vec4_hist,vec4_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05 --outputName Z_pt --xAxisLabel Z_pt");

  vec5_hist.push_back(hist_eta1);
  vec5_titles.push_back("Z #rightarrow l^{+} l^{-}"); 
  dataMCplotMaker (null,vec5_hist,vec5_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05 --noXaxisUnit  --outputName Z_eta --xAxisLabel Z_eta"); 

  vec6_hist.push_back(hist_phi1);
  vec6_titles.push_back("Z #rightarrow l^{+} l^{-}");   
  dataMCplotMaker (null,vec6_hist,vec6_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05  --noXaxisUnit --outputName Z_phi --xAxisLabel Z_phi"); 

  vec7_hist.push_back(hist_mass1);
  vec7_titles.push_back("Z #rightarrow l^{+} l^{-}");  
  dataMCplotMaker (null,vec7_hist,vec7_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05  --outputName Z_mass --xAxisLabel Z_mass"); 

  vec8_hist.push_back(hist_numjet);
  vec8_titles.push_back("Z #rightarrow l^{+} l^{-}");   
  dataMCplotMaker (null,vec8_hist,vec8_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05 --noXaxisUnit --xAxisLabel number of jets  --outputName numjets --noDivisionLabel"); 

  return 0;
}
