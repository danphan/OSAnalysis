#include "SS.h"
SS Object;
namespace Jack {
	const float &met() { return Object.met(); }
	const float &ht() { return Object.ht(); }
	const int &njets() { return Object.njets(); }
	const int &lep1_id() { return Object.lep1_id(); }
	const int &lep2_id() { return Object.lep2_id(); }
	const int &lep1_idx() { return Object.lep1_idx(); }
	const int &lep2_idx() { return Object.lep2_idx(); }
	const int &lep1_mc_id() { return Object.lep1_mc_id(); }
	const int &lep2_mc_id() { return Object.lep2_mc_id(); }
	const int &hyp_type() { return Object.hyp_type(); }
	const float &lep1_iso() { return Object.lep1_iso(); }
	const float &lep2_iso() { return Object.lep2_iso(); }
	const bool &lep1_passes_id() { return Object.lep1_passes_id(); }
	const bool &lep2_passes_id() { return Object.lep2_passes_id(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return Object.lep1_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return Object.lep2_p4(); }
	const float &evt_scale1fb() { return Object.evt_scale1fb(); }
	const float &evt_pfmet() { return Object.evt_pfmet(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &pfjets_p4() { return Object.pfjets_p4(); }
}
