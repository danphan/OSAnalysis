
{
  gROOT->ProcessLine(".L /home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.cc+");
  gSystem->Load("/home/users/cgeorge/CORE/CORE-run1/libCMS2NtupleMacrosCORE.so");
  gROOT->ProcessLine(".L /home/users/cgeorge/old_stuff/analysis/SS/EXTERNAL/dorky.cc+"); 

  gROOT->ProcessLine(".L /home/users/cgeorge/old_stuff/analysis/SS/Tools/goodrun.cc+");

  gROOT->ProcessLine(".L baby.C+");
  gROOT->ProcessLine(".L callsBaby.C+");

  gROOT->ProcessLine("callsBaby()");
}
