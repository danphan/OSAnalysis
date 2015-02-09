{
  gROOT->ProcessLine(".L /home/users/yanjunhe/dataMCplotMaker/dataMCplotMaker.cc+");
  gROOT->ProcessLine(".L /home/users/danphan/Jack/CORE/CMS2.cc+");
  gROOT->ProcessLine(".L baby.C+");
  gROOT->ProcessLine("baby()");
}
