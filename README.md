# OSAnalysis

VARIABLES:


2 opposite sign, same-flavor leptons with pt > 20 GeV and abs(eta) < 2.4 :

lep1_id : lepton 1's ID

lep2_id : lepton 2's ID

lep1_idx : lepton 1's index

lep2_idx : lepton 2's index

lep1_mc_id : The generated lepton 1 closeted to the reco particle (used to see if we correctly reconstructed lepton 1)

lep2_mc_id : The generated lepton 2 closeted to the reco particle (used to see if we correctly reconstructed lepton 2)

hyp_type : hypothesis type (dimuons or dielectrons)

lep1_iso

lep2_iso

lep1_passes_id : lepton 1's ID and iso

lep2_passes_id : lepton 2's ID and iso

lep1_p4 : lepton 1's four-vector momentum

lep2_p4 : lepton 2's four-vector momentum


jets with pt > 30 and abs(eta) < 3 :

njets : number of jets

ht : The total transverse momentum of jets

jets_p4 : jets' four-vector momentum

jets_disc : the discriminator of jets (If it is high, we kown the jet came from a bottom quark)


gen_id : generated particle's ID

gen_status : generated particle's status

gen_p4 : generated particle's four-vector momentum

event : event number

lumi : integrated luminosity

run : run number

nBjets : number of jets came from botton quarks

filename : file's name

met : missing transverse energy

scale1fb : cross-section/number of events
