# OSAnalysis

VARIABLES:


2 opposite sign, same-flavor leptons with pt > 20 GeV and abs(eta) < 2.4 :

(int) lep1_id : lepton 1's ID

(int) lep2_id : lepton 2's ID

(int) lep1_idx : lepton 1's index

(int) lep2_idx : lepton 2's index

(int) lep1_mc_id : The generated lepton 1 closeted to the reco particle (used to see if we correctly reconstructed lepton 1)

(int) lep2_mc_id : The generated lepton 2 closeted to the reco particle (used to see if we correctly reconstructed lepton 2)

(int) hyp_type : hypothesis type (dimuons or dielectrons)

(float) lep1_iso

(float) lep2_iso

(bool) lep1_passes_id : lepton 1's ID and iso

(bool) lep2_passes_id : lepton 2's ID and iso

(LorentzVector) lep1_p4 : lepton 1's four-vector momentum

(LorentzVector) lep2_p4 : lepton 2's four-vector momentum


jets with pt > 30 and abs(eta) < 3, duplicates remove, DeltaR > = 0.1 :

(int) njets : number of jets

(float) ht : The total transverse momentum of jets

(vector <LorentzVector>) jets_p4 : jets' four-vector momentum

(vector <LorentzVector>) jets_disc : the discriminator of jets (If it is high, we kown the jet came from a bottom quark)


(vector <int>) gen_id : generated particle's ID

(vector <int>) gen_status : generated particle's status

(vector <LorentzVector>) gen_p4 : generated particle's four-vector momentum

(int) event : event number

(int) lumi : integrated luminosity

(int) run : run number

(int) nBjets : number of jets came from botton quarks

(TString) filename : file's name

(float) met : missing transverse energy

(float) scale1fb : cross-section/number of events
