// -*- C++ -*-
#ifndef SS_H
#define SS_H
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std; 
class SS {
private: 
protected: 
	unsigned int index;
	float	met_;
	TBranch *met_branch;
	bool met_isLoaded;
	float	ht_;
	TBranch *ht_branch;
	bool ht_isLoaded;
	int	njets_;
	TBranch *njets_branch;
	bool njets_isLoaded;
	int	lep1_id_;
	TBranch *lep1_id_branch;
	bool lep1_id_isLoaded;
	int	lep2_id_;
	TBranch *lep2_id_branch;
	bool lep2_id_isLoaded;
	int	lep1_idx_;
	TBranch *lep1_idx_branch;
	bool lep1_idx_isLoaded;
	int	lep2_idx_;
	TBranch *lep2_idx_branch;
	bool lep2_idx_isLoaded;
	int	lep1_mc_id_;
	TBranch *lep1_mc_id_branch;
	bool lep1_mc_id_isLoaded;
	int	lep2_mc_id_;
	TBranch *lep2_mc_id_branch;
	bool lep2_mc_id_isLoaded;
	int	hyp_type_;
	TBranch *hyp_type_branch;
	bool hyp_type_isLoaded;
	float	lep1_iso_;
	TBranch *lep1_iso_branch;
	bool lep1_iso_isLoaded;
	float	lep2_iso_;
	TBranch *lep2_iso_branch;
	bool lep2_iso_isLoaded;
	bool	lep1_passes_id_;
	TBranch *lep1_passes_id_branch;
	bool lep1_passes_id_isLoaded;
	bool	lep2_passes_id_;
	TBranch *lep2_passes_id_branch;
	bool lep2_passes_id_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep1_p4_;
	TBranch *lep1_p4_branch;
	bool lep1_p4_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep2_p4_;
	TBranch *lep2_p4_branch;
	bool lep2_p4_isLoaded;
	float	scale1fb_;
	TBranch *scale1fb_branch;
	bool scale1fb_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *jets_p4_;
	TBranch *jets_p4_branch;
	bool jets_p4_isLoaded;
	vector<float> *jets_disc_;
	TBranch *jets_disc_branch;
	bool jets_disc_isLoaded;
	int	event_;
	TBranch *event_branch;
	bool event_isLoaded;
	int	lumi_;
	TBranch *lumi_branch;
	bool lumi_isLoaded;
	int	run_;
	TBranch *run_branch;
	bool run_isLoaded;
	vector<int> *gen_id_;
	TBranch *gen_id_branch;
	bool gen_id_isLoaded;
	vector<int> *gen_status_;
	TBranch *gen_status_branch;
	bool gen_status_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gen_p4_;
	TBranch *gen_p4_branch;
	bool gen_p4_isLoaded;
	TString *filename_;
	TBranch *filename_branch;
	bool filename_isLoaded;
	int	nBjets_;
	TBranch *nBjets_branch;
	bool nBjets_isLoaded;
public: 
void Init(TTree *tree) {
	lep1_p4_branch = 0;
	if (tree->GetBranch("lep1_p4") != 0) {
		lep1_p4_branch = tree->GetBranch("lep1_p4");
		if (lep1_p4_branch) {lep1_p4_branch->SetAddress(&lep1_p4_);}
	}
	lep2_p4_branch = 0;
	if (tree->GetBranch("lep2_p4") != 0) {
		lep2_p4_branch = tree->GetBranch("lep2_p4");
		if (lep2_p4_branch) {lep2_p4_branch->SetAddress(&lep2_p4_);}
	}
	jets_p4_branch = 0;
	if (tree->GetBranch("jets_p4") != 0) {
		jets_p4_branch = tree->GetBranch("jets_p4");
		if (jets_p4_branch) {jets_p4_branch->SetAddress(&jets_p4_);}
	}
	gen_p4_branch = 0;
	if (tree->GetBranch("gen_p4") != 0) {
		gen_p4_branch = tree->GetBranch("gen_p4");
		if (gen_p4_branch) {gen_p4_branch->SetAddress(&gen_p4_);}
	}
  tree->SetMakeClass(1);
	met_branch = 0;
	if (tree->GetBranch("met") != 0) {
		met_branch = tree->GetBranch("met");
		if (met_branch) {met_branch->SetAddress(&met_);}
	}
	ht_branch = 0;
	if (tree->GetBranch("ht") != 0) {
		ht_branch = tree->GetBranch("ht");
		if (ht_branch) {ht_branch->SetAddress(&ht_);}
	}
	njets_branch = 0;
	if (tree->GetBranch("njets") != 0) {
		njets_branch = tree->GetBranch("njets");
		if (njets_branch) {njets_branch->SetAddress(&njets_);}
	}
	lep1_id_branch = 0;
	if (tree->GetBranch("lep1_id") != 0) {
		lep1_id_branch = tree->GetBranch("lep1_id");
		if (lep1_id_branch) {lep1_id_branch->SetAddress(&lep1_id_);}
	}
	lep2_id_branch = 0;
	if (tree->GetBranch("lep2_id") != 0) {
		lep2_id_branch = tree->GetBranch("lep2_id");
		if (lep2_id_branch) {lep2_id_branch->SetAddress(&lep2_id_);}
	}
	lep1_idx_branch = 0;
	if (tree->GetBranch("lep1_idx") != 0) {
		lep1_idx_branch = tree->GetBranch("lep1_idx");
		if (lep1_idx_branch) {lep1_idx_branch->SetAddress(&lep1_idx_);}
	}
	lep2_idx_branch = 0;
	if (tree->GetBranch("lep2_idx") != 0) {
		lep2_idx_branch = tree->GetBranch("lep2_idx");
		if (lep2_idx_branch) {lep2_idx_branch->SetAddress(&lep2_idx_);}
	}
	lep1_mc_id_branch = 0;
	if (tree->GetBranch("lep1_mc_id") != 0) {
		lep1_mc_id_branch = tree->GetBranch("lep1_mc_id");
		if (lep1_mc_id_branch) {lep1_mc_id_branch->SetAddress(&lep1_mc_id_);}
	}
	lep2_mc_id_branch = 0;
	if (tree->GetBranch("lep2_mc_id") != 0) {
		lep2_mc_id_branch = tree->GetBranch("lep2_mc_id");
		if (lep2_mc_id_branch) {lep2_mc_id_branch->SetAddress(&lep2_mc_id_);}
	}
	hyp_type_branch = 0;
	if (tree->GetBranch("hyp_type") != 0) {
		hyp_type_branch = tree->GetBranch("hyp_type");
		if (hyp_type_branch) {hyp_type_branch->SetAddress(&hyp_type_);}
	}
	lep1_iso_branch = 0;
	if (tree->GetBranch("lep1_iso") != 0) {
		lep1_iso_branch = tree->GetBranch("lep1_iso");
		if (lep1_iso_branch) {lep1_iso_branch->SetAddress(&lep1_iso_);}
	}
	lep2_iso_branch = 0;
	if (tree->GetBranch("lep2_iso") != 0) {
		lep2_iso_branch = tree->GetBranch("lep2_iso");
		if (lep2_iso_branch) {lep2_iso_branch->SetAddress(&lep2_iso_);}
	}
	lep1_passes_id_branch = 0;
	if (tree->GetBranch("lep1_passes_id") != 0) {
		lep1_passes_id_branch = tree->GetBranch("lep1_passes_id");
		if (lep1_passes_id_branch) {lep1_passes_id_branch->SetAddress(&lep1_passes_id_);}
	}
	lep2_passes_id_branch = 0;
	if (tree->GetBranch("lep2_passes_id") != 0) {
		lep2_passes_id_branch = tree->GetBranch("lep2_passes_id");
		if (lep2_passes_id_branch) {lep2_passes_id_branch->SetAddress(&lep2_passes_id_);}
	}
	scale1fb_branch = 0;
	if (tree->GetBranch("scale1fb") != 0) {
		scale1fb_branch = tree->GetBranch("scale1fb");
		if (scale1fb_branch) {scale1fb_branch->SetAddress(&scale1fb_);}
	}
	jets_disc_branch = 0;
	if (tree->GetBranch("jets_disc") != 0) {
		jets_disc_branch = tree->GetBranch("jets_disc");
		if (jets_disc_branch) {jets_disc_branch->SetAddress(&jets_disc_);}
	}
	event_branch = 0;
	if (tree->GetBranch("event") != 0) {
		event_branch = tree->GetBranch("event");
		if (event_branch) {event_branch->SetAddress(&event_);}
	}
	lumi_branch = 0;
	if (tree->GetBranch("lumi") != 0) {
		lumi_branch = tree->GetBranch("lumi");
		if (lumi_branch) {lumi_branch->SetAddress(&lumi_);}
	}
	run_branch = 0;
	if (tree->GetBranch("run") != 0) {
		run_branch = tree->GetBranch("run");
		if (run_branch) {run_branch->SetAddress(&run_);}
	}
	gen_id_branch = 0;
	if (tree->GetBranch("gen_id") != 0) {
		gen_id_branch = tree->GetBranch("gen_id");
		if (gen_id_branch) {gen_id_branch->SetAddress(&gen_id_);}
	}
	gen_status_branch = 0;
	if (tree->GetBranch("gen_status") != 0) {
		gen_status_branch = tree->GetBranch("gen_status");
		if (gen_status_branch) {gen_status_branch->SetAddress(&gen_status_);}
	}
	filename_branch = 0;
	if (tree->GetBranch("filename") != 0) {
		filename_branch = tree->GetBranch("filename");
		if (filename_branch) {filename_branch->SetAddress(&filename_);}
	}
	nBjets_branch = 0;
	if (tree->GetBranch("nBjets") != 0) {
		nBjets_branch = tree->GetBranch("nBjets");
		if (nBjets_branch) {nBjets_branch->SetAddress(&nBjets_);}
	}
  tree->SetMakeClass(0);
}
void GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		met_isLoaded = false;
		ht_isLoaded = false;
		njets_isLoaded = false;
		lep1_id_isLoaded = false;
		lep2_id_isLoaded = false;
		lep1_idx_isLoaded = false;
		lep2_idx_isLoaded = false;
		lep1_mc_id_isLoaded = false;
		lep2_mc_id_isLoaded = false;
		hyp_type_isLoaded = false;
		lep1_iso_isLoaded = false;
		lep2_iso_isLoaded = false;
		lep1_passes_id_isLoaded = false;
		lep2_passes_id_isLoaded = false;
		lep1_p4_isLoaded = false;
		lep2_p4_isLoaded = false;
		scale1fb_isLoaded = false;
		jets_p4_isLoaded = false;
		jets_disc_isLoaded = false;
		event_isLoaded = false;
		lumi_isLoaded = false;
		run_isLoaded = false;
		gen_id_isLoaded = false;
		gen_status_isLoaded = false;
		gen_p4_isLoaded = false;
		filename_isLoaded = false;
		nBjets_isLoaded = false;
	}

void LoadAllBranches() 
	// load all branches
{
	if (met_branch != 0) met();
	if (ht_branch != 0) ht();
	if (njets_branch != 0) njets();
	if (lep1_id_branch != 0) lep1_id();
	if (lep2_id_branch != 0) lep2_id();
	if (lep1_idx_branch != 0) lep1_idx();
	if (lep2_idx_branch != 0) lep2_idx();
	if (lep1_mc_id_branch != 0) lep1_mc_id();
	if (lep2_mc_id_branch != 0) lep2_mc_id();
	if (hyp_type_branch != 0) hyp_type();
	if (lep1_iso_branch != 0) lep1_iso();
	if (lep2_iso_branch != 0) lep2_iso();
	if (lep1_passes_id_branch != 0) lep1_passes_id();
	if (lep2_passes_id_branch != 0) lep2_passes_id();
	if (lep1_p4_branch != 0) lep1_p4();
	if (lep2_p4_branch != 0) lep2_p4();
	if (scale1fb_branch != 0) scale1fb();
	if (jets_p4_branch != 0) jets_p4();
	if (jets_disc_branch != 0) jets_disc();
	if (event_branch != 0) event();
	if (lumi_branch != 0) lumi();
	if (run_branch != 0) run();
	if (gen_id_branch != 0) gen_id();
	if (gen_status_branch != 0) gen_status();
	if (gen_p4_branch != 0) gen_p4();
	if (filename_branch != 0) filename();
	if (nBjets_branch != 0) nBjets();
}

	float &met()
	{
		if (not met_isLoaded) {
			if (met_branch != 0) {
				met_branch->GetEntry(index);
			} else { 
				printf("branch met_branch does not exist!\n");
				exit(1);
			}
			met_isLoaded = true;
		}
		return met_;
	}
	float &ht()
	{
		if (not ht_isLoaded) {
			if (ht_branch != 0) {
				ht_branch->GetEntry(index);
			} else { 
				printf("branch ht_branch does not exist!\n");
				exit(1);
			}
			ht_isLoaded = true;
		}
		return ht_;
	}
	int &njets()
	{
		if (not njets_isLoaded) {
			if (njets_branch != 0) {
				njets_branch->GetEntry(index);
			} else { 
				printf("branch njets_branch does not exist!\n");
				exit(1);
			}
			njets_isLoaded = true;
		}
		return njets_;
	}
	int &lep1_id()
	{
		if (not lep1_id_isLoaded) {
			if (lep1_id_branch != 0) {
				lep1_id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_id_branch does not exist!\n");
				exit(1);
			}
			lep1_id_isLoaded = true;
		}
		return lep1_id_;
	}
	int &lep2_id()
	{
		if (not lep2_id_isLoaded) {
			if (lep2_id_branch != 0) {
				lep2_id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_id_branch does not exist!\n");
				exit(1);
			}
			lep2_id_isLoaded = true;
		}
		return lep2_id_;
	}
	int &lep1_idx()
	{
		if (not lep1_idx_isLoaded) {
			if (lep1_idx_branch != 0) {
				lep1_idx_branch->GetEntry(index);
			} else { 
				printf("branch lep1_idx_branch does not exist!\n");
				exit(1);
			}
			lep1_idx_isLoaded = true;
		}
		return lep1_idx_;
	}
	int &lep2_idx()
	{
		if (not lep2_idx_isLoaded) {
			if (lep2_idx_branch != 0) {
				lep2_idx_branch->GetEntry(index);
			} else { 
				printf("branch lep2_idx_branch does not exist!\n");
				exit(1);
			}
			lep2_idx_isLoaded = true;
		}
		return lep2_idx_;
	}
	int &lep1_mc_id()
	{
		if (not lep1_mc_id_isLoaded) {
			if (lep1_mc_id_branch != 0) {
				lep1_mc_id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc_id_branch does not exist!\n");
				exit(1);
			}
			lep1_mc_id_isLoaded = true;
		}
		return lep1_mc_id_;
	}
	int &lep2_mc_id()
	{
		if (not lep2_mc_id_isLoaded) {
			if (lep2_mc_id_branch != 0) {
				lep2_mc_id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc_id_branch does not exist!\n");
				exit(1);
			}
			lep2_mc_id_isLoaded = true;
		}
		return lep2_mc_id_;
	}
	int &hyp_type()
	{
		if (not hyp_type_isLoaded) {
			if (hyp_type_branch != 0) {
				hyp_type_branch->GetEntry(index);
			} else { 
				printf("branch hyp_type_branch does not exist!\n");
				exit(1);
			}
			hyp_type_isLoaded = true;
		}
		return hyp_type_;
	}
	float &lep1_iso()
	{
		if (not lep1_iso_isLoaded) {
			if (lep1_iso_branch != 0) {
				lep1_iso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_iso_branch does not exist!\n");
				exit(1);
			}
			lep1_iso_isLoaded = true;
		}
		return lep1_iso_;
	}
	float &lep2_iso()
	{
		if (not lep2_iso_isLoaded) {
			if (lep2_iso_branch != 0) {
				lep2_iso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_iso_branch does not exist!\n");
				exit(1);
			}
			lep2_iso_isLoaded = true;
		}
		return lep2_iso_;
	}
	bool &	lep1_passes_id()
	{
		if (not lep1_passes_id_isLoaded) {
			if (lep1_passes_id_branch != 0) {
				lep1_passes_id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passes_id_branch does not exist!\n");
				exit(1);
			}
			lep1_passes_id_isLoaded = true;
		}
		return lep1_passes_id_;
	}
	bool &	lep2_passes_id()
	{
		if (not lep2_passes_id_isLoaded) {
			if (lep2_passes_id_branch != 0) {
				lep2_passes_id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passes_id_branch does not exist!\n");
				exit(1);
			}
			lep2_passes_id_isLoaded = true;
		}
		return lep2_passes_id_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4()
	{
		if (not lep1_p4_isLoaded) {
			if (lep1_p4_branch != 0) {
				lep1_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep1_p4_branch does not exist!\n");
				exit(1);
			}
			lep1_p4_isLoaded = true;
		}
		return *lep1_p4_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4()
	{
		if (not lep2_p4_isLoaded) {
			if (lep2_p4_branch != 0) {
				lep2_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep2_p4_branch does not exist!\n");
				exit(1);
			}
			lep2_p4_isLoaded = true;
		}
		return *lep2_p4_;
	}
	float &scale1fb()
	{
		if (not scale1fb_isLoaded) {
			if (scale1fb_branch != 0) {
				scale1fb_branch->GetEntry(index);
			} else { 
				printf("branch scale1fb_branch does not exist!\n");
				exit(1);
			}
			scale1fb_isLoaded = true;
		}
		return scale1fb_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_p4()
	{
		if (not jets_p4_isLoaded) {
			if (jets_p4_branch != 0) {
				jets_p4_branch->GetEntry(index);
			} else { 
				printf("branch jets_p4_branch does not exist!\n");
				exit(1);
			}
			jets_p4_isLoaded = true;
		}
		return *jets_p4_;
	}
	const vector<float> &jets_disc()
	{
		if (not jets_disc_isLoaded) {
			if (jets_disc_branch != 0) {
				jets_disc_branch->GetEntry(index);
			} else { 
				printf("branch jets_disc_branch does not exist!\n");
				exit(1);
			}
			jets_disc_isLoaded = true;
		}
		return *jets_disc_;
	}
	int &event()
	{
		if (not event_isLoaded) {
			if (event_branch != 0) {
				event_branch->GetEntry(index);
			} else { 
				printf("branch event_branch does not exist!\n");
				exit(1);
			}
			event_isLoaded = true;
		}
		return event_;
	}
	int &lumi()
	{
		if (not lumi_isLoaded) {
			if (lumi_branch != 0) {
				lumi_branch->GetEntry(index);
			} else { 
				printf("branch lumi_branch does not exist!\n");
				exit(1);
			}
			lumi_isLoaded = true;
		}
		return lumi_;
	}
	int &run()
	{
		if (not run_isLoaded) {
			if (run_branch != 0) {
				run_branch->GetEntry(index);
			} else { 
				printf("branch run_branch does not exist!\n");
				exit(1);
			}
			run_isLoaded = true;
		}
		return run_;
	}
	const vector<int> &gen_id()
	{
		if (not gen_id_isLoaded) {
			if (gen_id_branch != 0) {
				gen_id_branch->GetEntry(index);
			} else { 
				printf("branch gen_id_branch does not exist!\n");
				exit(1);
			}
			gen_id_isLoaded = true;
		}
		return *gen_id_;
	}
	const vector<int> &gen_status()
	{
		if (not gen_status_isLoaded) {
			if (gen_status_branch != 0) {
				gen_status_branch->GetEntry(index);
			} else { 
				printf("branch gen_status_branch does not exist!\n");
				exit(1);
			}
			gen_status_isLoaded = true;
		}
		return *gen_status_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gen_p4()
	{
		if (not gen_p4_isLoaded) {
			if (gen_p4_branch != 0) {
				gen_p4_branch->GetEntry(index);
			} else { 
				printf("branch gen_p4_branch does not exist!\n");
				exit(1);
			}
			gen_p4_isLoaded = true;
		}
		return *gen_p4_;
	}
	TString &filename()
	{
		if (not filename_isLoaded) {
			if (filename_branch != 0) {
				filename_branch->GetEntry(index);
			} else { 
				printf("branch filename_branch does not exist!\n");
				exit(1);
			}
			filename_isLoaded = true;
		}
		return *filename_;
	}
	int &nBjets()
	{
		if (not nBjets_isLoaded) {
			if (nBjets_branch != 0) {
				nBjets_branch->GetEntry(index);
			} else { 
				printf("branch nBjets_branch does not exist!\n");
				exit(1);
			}
			nBjets_isLoaded = true;
		}
		return nBjets_;
	}

  static void progress( int nEventsTotal, int nEventsChain ){
    int period = 1000;
    if(nEventsTotal%1000 == 0) {
      // xterm magic from L. Vacavant and A. Cerri
      if (isatty(1)) {
        if( ( nEventsChain - nEventsTotal ) > period ){
          float frac = (float)nEventsTotal/(nEventsChain*0.01);
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", frac);
          fflush(stdout);
        }
        else {
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", 100.);
          cout << endl;
        }
      }
    }
  }
  
};

#ifndef __CINT__
extern SS object;
#endif

namespace Jack {
	const float &met();
	const float &ht();
	const int &njets();
	const int &lep1_id();
	const int &lep2_id();
	const int &lep1_idx();
	const int &lep2_idx();
	const int &lep1_mc_id();
	const int &lep2_mc_id();
	const int &hyp_type();
	const float &lep1_iso();
	const float &lep2_iso();
	const bool &lep1_passes_id();
	const bool &lep2_passes_id();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4();
	const float &scale1fb();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_p4();
	const vector<float> &jets_disc();
	const int &event();
	const int &lumi();
	const int &run();
	const vector<int> &gen_id();
	const vector<int> &gen_status();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gen_p4();
	const TString &filename();
	const int &nBjets();
}
#endif
