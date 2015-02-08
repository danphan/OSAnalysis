{
  gROOT->ProcessLine(".L /home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.cc+");
  gROOT->ProcessLine(".L SS.cc+");
  gROOT->ProcessLine(".L baby.C+");
  gROOT->ProcessLine("baby()");
}
