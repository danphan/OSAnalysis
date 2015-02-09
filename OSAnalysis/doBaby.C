{
  gROOT->ProcessLine(".L /home/users/cgeorge/software/dataMCplotMaker/dataMCplotMaker.cc+");
  gSystem->Load("/home/users/cgeorge/CORE/CORE-run1/libCMS2NtupleMacrosCORE.so");
  gROOT->ProcessLine(".L baby.C+");
  gROOT->ProcessLine("baby()");
}
