#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "/home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.h"
#include "/home/users/yanjunhe/SS.h"
#include "/home/users/yanjunhe/CORE/muonSelections.h"
#include "/home/users/yanjunhe/CORE/susySelections.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "Math/VectorUtil.h"

int allplot(){
 

  TFile *file = new TFile("/home/users/yanjunhe/baby.root");


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
//  TH1F *hist_e = new TH1F("hist_e","num electron",5,0,5);
//  TH1F *hist_m = new TH1F("hist_m","num muon",5,0,5);
//  TH1F *hist_eb = new TH1F("hist_eb","num before electron",5,0,5);
//  TH1F *hist_mb = new TH1F("hist_mb","num before muon",5,0,5);
  



  cout << tree->GetEntries() << endl;
  
  Object.Init(tree);

  unsigned int nEventsTree = tree->GetEntriesFast();

  int dummy = 0;

  for(unsigned int evt = 0; evt < nEventsTree; evt++) { 
 //  int nj = 0; 
 //  int e = 0;
 //  int eb = 0;
 //  int m = 0;
 //  int mb = 0;  
    Object.GetEntry(evt);
   
    //define leptons
    LorentzVector lep1 = Jack::lep1_p4(); 
    LorentzVector lep2 = Jack::lep2_p4(); 
  

    //this dummy variable seems superfluous 
    dummy = 1;   
    
    LorentzVector z_cand = lep1 + lep2;
 
    //fill plots with information about dileptons
    hist_pt->Fill(lep1.pt(),Jack::evt_scale1fb()*lumi*corr);   //Jack::evt_scale1fb()*lumi*corr
    hist_pt->Fill(lep2.pt(),Jack::evt_scale1fb()*lumi*corr);
    hist_eta->Fill(lep1.eta(),Jack::evt_scale1fb()*lumi*corr);
    hist_eta->Fill(lep2.eta(),Jack::evt_scale1fb()*lumi*corr);
    hist_phi->Fill(lep1.phi(),Jack::evt_scale1fb()*lumi*corr);
    hist_phi->Fill(lep2.phi(),Jack::evt_scale1fb()*lumi*corr);
    hist_pt1->Fill(z_cand.pt(),Jack::evt_scale1fb()*lumi*corr);
    hist_eta1->Fill(z_cand.eta(),Jack::evt_scale1fb()*lumi*corr);
    hist_phi1->Fill(z_cand.phi(),Jack::evt_scale1fb()*lumi*corr);
    hist_mass1->Fill(z_cand.mass(),Jack::evt_scale1fb()*lumi*corr); 

           
 // for  (unsigned int q = 0; q < Jack::pfjets_p4().size();q++) {
 // 
 //   LorentzVector jet2 = Jack::pfjets_p4().at(q);     
 //   
 //   bool uu = 1;
 //   
 //   if (jet2.pt()<=30 || abs(jet2.eta())>=3 ) continue;
 //   
 //   for(unsigned int w = 0; w < lepton_cands2.size(); w++) {
 //     if (ROOT::Math::VectorUtil::DeltaR(lepton_cands2.at(w),jet2) < 0.1) {
 //       uu = 0;
 //       break;
 //     }
 //   }  
 //   if (uu == 1) nj++;
 // }
   
    if (dummy == 1) {
      hist->Fill(Jack::evt_pfmet(),Jack::evt_scale1fb()*lumi*corr);
      hist_numjet->Fill(Jack::njets(),Jack::evt_scale1fb()*lumi*corr);
    }
  }
  //hist_e->Fill(e,Jack::evt_scale1fb()*lumi*corr);
  //hist_m->Fill(m,Jack::evt_scale1fb()*lumi*corr);
  //hist_eb->Fill(eb,Jack::evt_scale1fb()*lumi*corr); 
  //hist_mb->Fill(mb,Jack::evt_scale1fb()*lumi*corr);


//}
//}
 
  //using dataMCplotMaker to plot the hists made 
  
  TH1F* null = new TH1F("","",1,0,1);
 
  vector <TH1F*> vec1_hist,vec2_hist,vec3_hist,vec4_hist,vec5_hist,vec6_hist,vec7_hist,vec_hist,vec8_hist;//,vec9_hist,vec10_hist,vec_hist;


  vector <char*> vec1_titles,vec2_titles,vec3_titles,vec4_titles,vec5_titles,vec6_titles,vec7_titles,vec_titles,vec8_titles;//,vec9_titles,vec10_titles;
 
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
  vec5_titles.push_back("Z #rightarrow l^{+} l^{-}");                              dataMCplotMaker (null,vec5_hist,vec5_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05 --noXaxisUnit  --outputName Z_eta --xAxisLabel Z_eta"); 

  vec6_hist.push_back(hist_phi1);
  vec6_titles.push_back("Z #rightarrow l^{+} l^{-}");                             dataMCplotMaker (null,vec6_hist,vec6_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05  --noXaxisUnit --outputName Z_phi --xAxisLabel Z_phi"); 

  vec7_hist.push_back(hist_mass1);
  vec7_titles.push_back("Z #rightarrow l^{+} l^{-}");                             dataMCplotMaker (null,vec7_hist,vec7_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05  --outputName Z_mass --xAxisLabel Z_mass"); 

  vec8_hist.push_back(hist_numjet);
  vec8_titles.push_back("Z #rightarrow l^{+} l^{-}");                              dataMCplotMaker (null,vec8_hist,vec8_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--isLinear --legendRight -0.05 --noXaxisUnit --xAxisLabel number of jets  --outputName numjets --noDivisionLabel"); 


 // vec9_hist.push_back(hist_e);
 // vec9_hist.push_back(hist_eb);
 // vec9_titles.push_back("Z #rightarrow l^{+} l^{-} after ID");
 // vec9_titles.push_back("Z #rightarrow l^{+} l^{-} before ID");                           
 //  dataMCplotMaker (null,vec9_hist,vec9_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--noStack --legendRight -0.1 --setMaximum 10e9  --noXaxisUnit --xAxisLabel number of electron  --outputName numelectrons --noDivisionLabel"); 



 //vec10_hist.push_back(hist_m);
// vec10_hist.push_back(hist_mb);
// vec10_titles.push_back("Z #rightarrow l^{+} l^{-} after ID");  
// vec10_titles.push_back("Z #rightarrow l^{+} l^{-} before ID");                     
// dataMCplotMaker (null,vec10_hist,vec10_titles,"RUN 1 MC Exercise","#geq 1 OS,SF dilepton pairs","--noStack --legendRight -0.1 --setMaximum 10e9 --noXaxisUnit --xAxisLabel number of muon  --outputName nummuons --noDivisionLabel"); 





 //TCanvas *canvas1 = new TCanvas("canvas1");
  //hist->Draw();
  //canvas1->Print("met.pdf");
 
  //TCanvas *canvas2 = new TCanvas("canvas2");
 // hist_pt->Draw();
 // canvas2->Print("lep_pt.pdf");

 // TCanvas *canvas3 = new TCanvas("canvas3");
 // hist_eta->Draw();
 // canvas3->Print("lep_eta.pdf");

  //TCanvas *canvas4 = new TCanvas("canvas4");
 // hist_phi->Draw();
 // canvas4->Print("lep_phi.pdf");

 // TCanvas *canvas5 = new TCanvas("canvas5");
 // hist_pt1->Draw();                
  //canvas5->Print("Z_pt.pdf");
                                
 // TCanvas *canvas6 = new TCanvas("canvas6");
 // hist_eta1->Scale(1.0/hist_eta1->Integral());
  //hist_eta1->Draw();
  //canvas6->Print("Z_eta.pdf");
                                
  //TCanvas *canvas7 = new TCanvas("canvas7");
  //hist_phi1->Draw();
  //canvas7->Print("Z_phi.pdf");
 
  //TCanvas *canvas8 = new TCanvas("canvas8");
  //hist_mass1->Draw();
  //canvas8->Print("Z_mass.pdf");

 // TCanvas *canvas9 = new TCanvas("canvas9");
 // hist_numjet->Draw();
 // canvas9->Print("numjets.pdf");

  return 0;
}
