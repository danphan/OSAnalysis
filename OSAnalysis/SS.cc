#include "SS.h"
SS object;
namespace Jack {
	const float &met() { return object.met(); }
	const float &ht() { return object.ht(); }
	const int &njets() { return object.njets(); }
	const int &lep1_id() { return object.lep1_id(); }
	const int &lep2_id() { return object.lep2_id(); }
	const int &lep1_idx() { return object.lep1_idx(); }
	const int &lep2_idx() { return object.lep2_idx(); }
	const int &lep1_mc_id() { return object.lep1_mc_id(); }
	const int &lep2_mc_id() { return object.lep2_mc_id(); }
	const int &hyp_type() { return object.hyp_type(); }
	const float &lep1_iso() { return object.lep1_iso(); }
	const float &lep2_iso() { return object.lep2_iso(); }
	const bool &lep1_passes_id() { return object.lep1_passes_id(); }
	const bool &lep2_passes_id() { return object.lep2_passes_id(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return object.lep1_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return object.lep2_p4(); }
	const float &scale1fb() { return object.scale1fb(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &pfjets_p4() { return object.pfjets_p4(); }
}
