# OSAnalysis

##VARIABLES:


###2 opposite sign, same-flavor leptons with pt > 20 GeV and abs(eta) < 2.4 :
```
(int) lep1_id : lepton 1's ID

(int) lep2_id : lepton 2's ID

(int) lep1_idx : lepton 1's index

(int) lep2_idx : lepton 2's index

(int) lep1_mc_id : The generated lepton 1 closest to the reco particle (used to see if we correctly reconstructed lepton 1)

(int) lep2_mc_id : The generated lepton 2 closest to the reco particle (used to see if we correctly reconstructed lepton 2)

(int) hyp_type : dilepton type (0 for muon-muon, 3 for electron-electron, 1 or 2 for mixed)

(float) lep1_iso : isolation: (∑pT(relative to track of lep1))/pT lep 1, summing over particles in a cone about lep1. lower is better(lep is pretty well isolated) (The cone size is 0.4)

(float) lep2_iso : same

(bool) lep1_passes_id : lepton 1's ID {muonId(lepton1 index, ZMet2012_v1)} and iso {passElectronSelection_ZMet2012_v3_Iso(lepton1 index)} 

(bool) lep2_passes_id : lepton 2's ID {muonId(lepton2 index, ZMet2012_v1)} and iso {passElectronSelection_ZMet2012_v3_Iso(lepton2 index)} 

(LorentzVector) lep1_p4 : lepton 1's four-vector momentum

(LorentzVector) lep2_p4 : lepton 2's four-vector momentum
```


###Jets with pt > 30 and abs(eta) < 3, duplicates remove, DeltaR > = 0.1 :
```
(int) njets : number of jets

(float) ht : The total transverse momentum of jets

(vector {LorentzVector}) jets_p4 : jets' four-vector momentum

(vector {LorentzVector}) jets_disc : the discriminator of jets (If it is high, we kown the jet came from a bottom quark)

(int) nBjets : number of jets came from botton quarks (disc > 0.679 , pt > 30, abs(eta) < 3, DeltaR >= 0.1)
```

```
(vector {int}) gen_id : generated particle's ID (all of them)

(vector {int}) gen_status : generated particle's status 

   (gen_status numbers meaning:

   3 - "hard scattering" -- the actual things that collide.  In p p > ttW, that would be the t, t, and W only 

   2 - "intermediate particle" -- something that was produced after the hard collision but did not survive to be directly    
   detected by the detector 

   1 - "final state" -- the particles that will live "forever" as far as the simulator is concerned.  These are the ones we      can  detect

   -1 -  for "initial state" -- the protons in our case
   )

(vector {LorentzVector}) gen_p4 : generated particle's four-vector momentum

(int) event : event number

(int) lumi : luminosity

(int) run : run number

(TString) filename : file's name

(float) met : missing transverse energy

(float) scale1fb : cross-section/number of events
```
