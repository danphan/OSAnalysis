{

  gSystem->Load("/home/users/yanjunhe/CORE/libCMS2NtupleMacrosCORE.so");
  gROOT->ProcessLine(".L /home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.cc+");
  gROOT->ProcessLine(".L SS.cc+");
  gROOT->ProcessLine(".L allplot.C+");
  gROOT->ProcessLine("allplot()");
}
