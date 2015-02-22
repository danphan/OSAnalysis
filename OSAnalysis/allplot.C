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
 
  TFile *file_data = new TFile("/nfs-3/userdata/danphan/baby_data.root");
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
    
    //Check for duplicates 
    if (isData == true){
        duplicate_removal::DorkyEventIdentifier id(run, event, lumi);
        if (duplicate_removal::is_duplicate(id)) continue;
      }

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


  //filling MC hists
  TFile *file_MC = new TFile("/nfs-3/userdata/danphan/baby_MC_all.root");
  TTree *tree_MC = (TTree*)file_MC->Get("tree");
 
  TH1F *MC_hist = new TH1F("data_hist", "met", 50, 0, 70);
  TH1F *MC_hist_pt = new TH1F("data_hist_pt", "p_{T}", 50, 0, 100);
  TH1F *MC_hist_eta = new TH1F("data_hist_eta", "eta", 50, -2.5, 2.5);
  TH1F *MC_hist_phi = new TH1F("data_hist_phi","phi", 50, -3.5, 3.5);
  TH1F *MC_hist_pt1 = new TH1F("data_hist_ptZ", "p_{T} Z", 50, 0, 150);  
  TH1F *MC_hist_eta1 = new TH1F("data_hist_etaZ", "eta Z", 50, -6, 6);
  TH1F *MC_hist_mass1 =  new TH1F("data_hist_mass","mass Z",50,0,150);
  TH1F *MC_hist_phi1 = new TH1F("data_hist_phiZ","phi Z", 50, -3.5, 3.5);
  TH1F *MC_hist_numjet = new TH1F("data_hist_numjet","num jets",8,0,8);

  object.Init(tree_MC);

  unsigned int nEventsTreeMC = tree_MC->GetEntriesFast();

  for(unsigned int evt = 0; evt < nEventsTreeMC; evt++) { 
 
    object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = lep1_p4(); 
    LorentzVector lep2 = lep2_p4(); 
  
    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    MC_hist_pt->Fill(lep1.pt(), scale1fb()*lumi*corr);   
    MC_hist_pt->Fill(lep2.pt(), scale1fb()*lumi*corr);
    MC_hist_eta->Fill(lep1.eta(), scale1fb()*lumi*corr);
    MC_hist_eta->Fill(lep2.eta(), scale1fb()*lumi*corr);
    MC_hist_phi->Fill(lep1.phi(), scale1fb()*lumi*corr);
    MC_hist_phi->Fill(lep2.phi(), scale1fb()*lumi*corr);
    MC_hist_pt1->Fill(z_cand.pt(), scale1fb()*lumi*corr);
    MC_hist_eta1->Fill(z_cand.eta(), scale1fb()*lumi*corr);
    MC_hist_phi1->Fill(z_cand.phi(), scale1fb()*lumi*corr);
    MC_hist_mass1->Fill(z_cand.mass(), scale1fb()*lumi*corr); 
    MC_hist->Fill(met(), scale1fb()*lumi*corr);
    MC_hist_numjet->Fill(njets(), scale1fb()*lumi*corr);
    
  }



 
  //using dataMCplotMaker to plot the hists made 
 
  //data(not used here)
//  TH1F* null = new TH1F("","",1,0,1);
 
  //backgrounds(here we put both data and MC for comparison)
  vector <TH1F*> vec1_hist,vec2_hist,vec3_hist,vec4_hist,vec5_hist,vec6_hist,vec7_hist,vec_hist,vec8_hist;

  //names of all backgrounds
  vector <char*> vec1_titles,vec2_titles,vec3_titles,vec4_titles,vec5_titles,vec6_titles,vec7_titles,vec_titles,vec8_titles;
 
 // vec_hist.push_back(data_hist); 
  vec_hist.push_back(MC_hist); 
  vec_titles.push_back("Z #rightarrow l^{+} l^{-}");
 // vec_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist,vec_hist,vec_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear --outputName met --xAxisLabel MET");
 
 // vec1_hist.push_back(data_hist_pt);
  vec1_hist.push_back(MC_hist_pt);
  vec1_titles.push_back("Z #rightarrow l^{+} l^{-}");
//  vec1_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_pt,vec1_hist,vec1_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear --outputName lep_pt --xAxisLabel pT");
 
 // vec2_hist.push_back(data_hist_eta);
  vec2_hist.push_back(MC_hist_eta);
  vec2_titles.push_back("Z #rightarrow l^{+} l^{-}");
 // vec2_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_eta,vec2_hist,vec2_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear --noXaxisUnit --outputName lep_eta --xAxisLabel #eta");

 // vec3_hist.push_back(data_hist_phi);
  vec3_hist.push_back(MC_hist_phi);
  vec3_titles.push_back("Z #rightarrow l^{+} l^{-}");
 // vec3_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_phi,vec3_hist,vec3_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear --noXaxisUnit --outputName lep_phi --xAxisLabel #phi");

 // vec4_hist.push_back(data_hist_pt1);
  vec4_hist.push_back(MC_hist_pt1);
  vec4_titles.push_back("Z #rightarrow l^{+} l^{-}");
 // vec4_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_pt1,vec4_hist,vec4_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear --outputName Z_pt --xAxisLabel Z pT");

 // vec5_hist.push_back(data_hist_eta1);
  vec5_hist.push_back(MC_hist_eta1);
  vec5_titles.push_back("Z #rightarrow l^{+} l^{-}"); 
//  vec5_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_eta1,vec5_hist,vec5_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear --noXaxisUnit  --outputName Z_eta --xAxisLabel Z #eta"); 

 // vec6_hist.push_back(data_hist_phi1);
  vec6_hist.push_back(MC_hist_phi1);
  vec6_titles.push_back("Z #rightarrow l^{+} l^{-}");   
 // vec6_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_phi1,vec6_hist,vec6_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear  --noXaxisUnit --outputName Z_phi --xAxisLabel Z #phi"); 

 // vec7_hist.push_back(data_hist_mass1);
  vec7_hist.push_back(MC_hist_mass1);
  vec7_titles.push_back("Z #rightarrow l^{+} l^{-}");  
 // vec7_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_mass1,vec7_hist,vec7_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear  --outputName Z_mass --xAxisLabel Z mass"); 

//  vec8_hist.push_back(data_hist_numjet);
  vec8_hist.push_back(MC_hist_numjet);
  vec8_titles.push_back("Z #rightarrow l^{+} l^{-}");   
 // vec8_titles.push_back("Monte Carlo");
  dataMCplotMaker (data_hist_numjet,vec8_hist,vec8_titles,"#geq 1 OS,SF dilepton pairs",""," --energy 8 --lumi 5.2 --isLinear  --noXaxisUnit --xAxisLabel number of jets  --outputName numjets --noDivisionLabel"); 

  return 0;
}
