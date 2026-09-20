//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Sep 18 14:49:17 2026 by ROOT version 6.34.08
// from TTree ntp_Lambda/Lambda TTree
// found on file: HRun25122005_00picoDstLambda.root.picoLambdaAnaMaker.root
//////////////////////////////////////////////////////////

#ifndef ntp_Lambda_h
#define ntp_Lambda_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class ntp_Lambda {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           eventId;
   Float_t         Vz;
   Int_t           mNTrigs;
   Int_t           mTrigId[2];   //[mNTrigs]
   Int_t           NLambda;
   Int_t           p1_InEventID[5];   //[NLambda]
   Float_t         p1_pt[5];   //[NLambda]
   Float_t         p1_phi[5];   //[NLambda]
   Float_t         p1_eta[5];   //[NLambda]
   Float_t         p1_dca[5];   //[NLambda]
   Int_t           p1_ch[5];   //[NLambda]
   Int_t           p1_hasTOFinfo[5];   //[NLambda]
   Float_t         p1_dedx[5];   //[NLambda]
   Float_t         p1_beta[5];   //[NLambda]
   Float_t         p1_dcaxy[5];   //[NLambda]
   Float_t         p1_nSigmaProton[5];   //[NLambda]
   Int_t           p2_InEventID[5];   //[NLambda]
   Float_t         p2_pt[5];   //[NLambda]
   Float_t         p2_phi[5];   //[NLambda]
   Float_t         p2_eta[5];   //[NLambda]
   Float_t         p2_dca[5];   //[NLambda]
   Float_t         p2_ch[5];   //[NLambda]
   Int_t           p2_hasTOFinfo[5];   //[NLambda]
   Float_t         p2_dedx[5];   //[NLambda]
   Float_t         p2_beta[5];   //[NLambda]
   Float_t         p2_dcaxy[5];   //[NLambda]
   Float_t         p2_nSigmaPion[5];   //[NLambda]
   Int_t           pair_charge[5];   //[NLambda]
   Float_t         pair_DCAdaughters[5];   //[NLambda]
   Float_t         pair_theta[5];   //[NLambda]
   Float_t         pair_decayL[5];   //[NLambda]
   Float_t         pair_phi[5];   //[NLambda]
   Float_t         pair_eta[5];   //[NLambda]
   Float_t         pair_pt[5];   //[NLambda]
   Float_t         pair_mass[5];   //[NLambda]
   Int_t           NXi;
   Int_t           DauLambda_charge[1];   //[NXi]
   Float_t         DauLambda_DCAdaughters[1];   //[NXi]
   Float_t         DauLambda_theta[1];   //[NXi]
   Float_t         DauLambda_decayL[1];   //[NXi]
   Float_t         DauLambda_pt[1];   //[NXi]
   Float_t         DauLambda_eta[1];   //[NXi]
   Float_t         DauLambda_phi[1];   //[NXi]
   Float_t         DauLambda_mass[1];   //[NXi]
   Int_t           DauLambda_Dau1_InEventID[1];   //[NXi]
   Float_t         DauLambda_Dau1_pt[1];   //[NXi]
   Float_t         DauLambda_Dau1_eta[1];   //[NXi]
   Float_t         DauLambda_Dau1_phi[1];   //[NXi]
   Int_t           DauLambda_Dau1_ch[1];   //[NXi]
   Float_t         DauLambda_Dau1_dca[1];   //[NXi]
   Int_t           DauLambda_Dau2_InEventID[1];   //[NXi]
   Float_t         DauLambda_Dau2_pt[1];   //[NXi]
   Float_t         DauLambda_Dau2_eta[1];   //[NXi]
   Float_t         DauLambda_Dau2_phi[1];   //[NXi]
   Int_t           DauLambda_Dau2_ch[1];   //[NXi]
   Float_t         DauLambda_Dau2_dca[1];   //[NXi]
   Int_t           pion3_InEventID[1];   //[NXi]
   Float_t         pion3_pt[1];   //[NXi]
   Float_t         pion3_eta[1];   //[NXi]
   Float_t         pion3_phi[1];   //[NXi]
   Int_t           pion3_ch[1];   //[NXi]
   Float_t         pion3_dca[1];   //[NXi]
   Int_t           Xi_Charge[1];   //[NXi]
   Float_t         Xi_DCAdaughters[1];   //[NXi]
   Float_t         Xi_theta[1];   //[NXi]
   Float_t         Xi_DecayL[1];   //[NXi]
   Float_t         Xi_pt[1];   //[NXi]
   Float_t         Xi_eta[1];   //[NXi]
   Float_t         Xi_phi[1];   //[NXi]
   Float_t         Xi_mass[1];   //[NXi]
   Float_t         Xi_DCA[1];   //[NXi]
   Int_t           track_Number;
   Float_t         track_pt[132];   //[track_Number]
   Float_t         track_eta[132];   //[track_Number]
   Float_t         track_phi[132];   //[track_Number]
   Int_t           track_InEventID[132];   //[track_Number]
   Float_t         track_dca[132];   //[track_Number]
   Float_t         track_dcaxy[132];   //[track_Number]
   Float_t         track_nSigmaPion[132];   //[track_Number]
   Float_t         track_nSigmaKaon[132];   //[track_Number]
   Float_t         track_nSigmaProton[132];   //[track_Number]
   Float_t         track_dedx[132];   //[track_Number]
   Int_t           track_ch[132];   //[track_Number]

   // List of branches
   TBranch        *b_eventId;   //!
   TBranch        *b_Vz;   //!
   TBranch        *b_mNTrigs;   //!
   TBranch        *b_mTrigId;   //!
   TBranch        *b_NLambda;   //!
   TBranch        *b_p1_InEventID;   //!
   TBranch        *b_p1_pt;   //!
   TBranch        *b_p1_phi;   //!
   TBranch        *b_p1_eta;   //!
   TBranch        *b_p1_dca;   //!
   TBranch        *b_p1_ch;   //!
   TBranch        *b_p1_hasTOFinfo;   //!
   TBranch        *b_p1_dedx;   //!
   TBranch        *b_p1_beta;   //!
   TBranch        *b_p1_dcaxy;   //!
   TBranch        *b_p1_nSigmaProton;   //!
   TBranch        *b_p2_InEventID;   //!
   TBranch        *b_p2_pt;   //!
   TBranch        *b_p2_phi;   //!
   TBranch        *b_p2_eta;   //!
   TBranch        *b_p2_dca;   //!
   TBranch        *b_p2_ch;   //!
   TBranch        *b_p2_hasTOFinfo;   //!
   TBranch        *b_p2_dedx;   //!
   TBranch        *b_p2_beta;   //!
   TBranch        *b_p2_dcaxy;   //!
   TBranch        *b_p2_nSigmaPion;   //!
   TBranch        *b_pair_charge;   //!
   TBranch        *b_pair_DCAdaughters;   //!
   TBranch        *b_pair_theta;   //!
   TBranch        *b_pair_decayL;   //!
   TBranch        *b_pair_phi;   //!
   TBranch        *b_pair_eta;   //!
   TBranch        *b_pair_pt;   //!
   TBranch        *b_pair_mass;   //!
   TBranch        *b_NXi;   //!
   TBranch        *b_DauLambda_charge;   //!
   TBranch        *b_DauLambda_DCAdaughters;   //!
   TBranch        *b_DauLambda_theta;   //!
   TBranch        *b_DauLambda_decayL;   //!
   TBranch        *b_DauLambda_pt;   //!
   TBranch        *b_DauLambda_eta;   //!
   TBranch        *b_DauLambda_phi;   //!
   TBranch        *b_DauLambda_mass;   //!
   TBranch        *b_DauLambda_Dau1_InEventID;   //!
   TBranch        *b_DauLambda_Dau1_pt;   //!
   TBranch        *b_DauLambda_Dau1_eta;   //!
   TBranch        *b_DauLambda_Dau1_phi;   //!
   TBranch        *b_DauLambda_Dau1_ch;   //!
   TBranch        *b_DauLambda_Dau1_dca;   //!
   TBranch        *b_DauLambda_Dau2_InEventID;   //!
   TBranch        *b_DauLambda_Dau2_pt;   //!
   TBranch        *b_DauLambda_Dau2_eta;   //!
   TBranch        *b_DauLambda_Dau2_phi;   //!
   TBranch        *b_DauLambda_Dau2_ch;   //!
   TBranch        *b_DauLambda_Dau2_dca;   //!
   TBranch        *b_pion3_InEventID;   //!
   TBranch        *b_pion3_pt;   //!
   TBranch        *b_pion3_eta;   //!
   TBranch        *b_pion3_phi;   //!
   TBranch        *b_pion3_ch;   //!
   TBranch        *b_pion3_dca;   //!
   TBranch        *b_Xi_Charge;   //!
   TBranch        *b_Xi_DCAdaughters;   //!
   TBranch        *b_Xi_theta;   //!
   TBranch        *b_Xi_DecayL;   //!
   TBranch        *b_Xi_pt;   //!
   TBranch        *b_Xi_eta;   //!
   TBranch        *b_Xi_phi;   //!
   TBranch        *b_Xi_mass;   //!
   TBranch        *b_Xi_DCA;   //!
   TBranch        *b_track_Number;   //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_eta;   //!
   TBranch        *b_track_phi;   //!
   TBranch        *b_track_InEventID;   //!
   TBranch        *b_track_dca;   //!
   TBranch        *b_track_dcaxy;   //!
   TBranch        *b_track_nSigmaPion;   //!
   TBranch        *b_track_nSigmaKaon;   //!
   TBranch        *b_track_nSigmaProton;   //!
   TBranch        *b_track_dedx;   //!
   TBranch        *b_track_ch;   //!

   ntp_Lambda(TTree *tree=0);
   virtual ~ntp_Lambda();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ntp_Lambda_cxx
ntp_Lambda::ntp_Lambda(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("HRun25122005_00picoDstLambda.root.picoLambdaAnaMaker.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("HRun25122005_00picoDstLambda.root.picoLambdaAnaMaker.root");
      }
      f->GetObject("ntp_Lambda",tree);

   }
   Init(tree);
}

ntp_Lambda::~ntp_Lambda()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ntp_Lambda::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ntp_Lambda::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ntp_Lambda::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("eventId", &eventId, &b_eventId);
   fChain->SetBranchAddress("Vz", &Vz, &b_Vz);
   fChain->SetBranchAddress("mNTrigs", &mNTrigs, &b_mNTrigs);
   fChain->SetBranchAddress("mTrigId", mTrigId, &b_mTrigId);
   fChain->SetBranchAddress("NLambda", &NLambda, &b_NLambda);
   fChain->SetBranchAddress("p1_InEventID", p1_InEventID, &b_p1_InEventID);
   fChain->SetBranchAddress("p1_pt", p1_pt, &b_p1_pt);
   fChain->SetBranchAddress("p1_phi", p1_phi, &b_p1_phi);
   fChain->SetBranchAddress("p1_eta", p1_eta, &b_p1_eta);
   fChain->SetBranchAddress("p1_dca", p1_dca, &b_p1_dca);
   fChain->SetBranchAddress("p1_ch", p1_ch, &b_p1_ch);
   fChain->SetBranchAddress("p1_hasTOFinfo", p1_hasTOFinfo, &b_p1_hasTOFinfo);
   fChain->SetBranchAddress("p1_dedx", p1_dedx, &b_p1_dedx);
   fChain->SetBranchAddress("p1_beta", p1_beta, &b_p1_beta);
   fChain->SetBranchAddress("p1_dcaxy", p1_dcaxy, &b_p1_dcaxy);
   fChain->SetBranchAddress("p1_nSigmaProton", p1_nSigmaProton, &b_p1_nSigmaProton);
   fChain->SetBranchAddress("p2_InEventID", p2_InEventID, &b_p2_InEventID);
   fChain->SetBranchAddress("p2_pt", p2_pt, &b_p2_pt);
   fChain->SetBranchAddress("p2_phi", p2_phi, &b_p2_phi);
   fChain->SetBranchAddress("p2_eta", p2_eta, &b_p2_eta);
   fChain->SetBranchAddress("p2_dca", p2_dca, &b_p2_dca);
   fChain->SetBranchAddress("p2_ch", p2_ch, &b_p2_ch);
   fChain->SetBranchAddress("p2_hasTOFinfo", p2_hasTOFinfo, &b_p2_hasTOFinfo);
   fChain->SetBranchAddress("p2_dedx", p2_dedx, &b_p2_dedx);
   fChain->SetBranchAddress("p2_beta", p2_beta, &b_p2_beta);
   fChain->SetBranchAddress("p2_dcaxy", p2_dcaxy, &b_p2_dcaxy);
   fChain->SetBranchAddress("p2_nSigmaPion", p2_nSigmaPion, &b_p2_nSigmaPion);
   fChain->SetBranchAddress("pair_charge", pair_charge, &b_pair_charge);
   fChain->SetBranchAddress("pair_DCAdaughters", pair_DCAdaughters, &b_pair_DCAdaughters);
   fChain->SetBranchAddress("pair_theta", pair_theta, &b_pair_theta);
   fChain->SetBranchAddress("pair_decayL", pair_decayL, &b_pair_decayL);
   fChain->SetBranchAddress("pair_phi", pair_phi, &b_pair_phi);
   fChain->SetBranchAddress("pair_eta", pair_eta, &b_pair_eta);
   fChain->SetBranchAddress("pair_pt", pair_pt, &b_pair_pt);
   fChain->SetBranchAddress("pair_mass", pair_mass, &b_pair_mass);
   fChain->SetBranchAddress("NXi", &NXi, &b_NXi);
   fChain->SetBranchAddress("DauLambda_charge", &DauLambda_charge, &b_DauLambda_charge);
   fChain->SetBranchAddress("DauLambda_DCAdaughters", &DauLambda_DCAdaughters, &b_DauLambda_DCAdaughters);
   fChain->SetBranchAddress("DauLambda_theta", &DauLambda_theta, &b_DauLambda_theta);
   fChain->SetBranchAddress("DauLambda_decayL", &DauLambda_decayL, &b_DauLambda_decayL);
   fChain->SetBranchAddress("DauLambda_pt", &DauLambda_pt, &b_DauLambda_pt);
   fChain->SetBranchAddress("DauLambda_eta", &DauLambda_eta, &b_DauLambda_eta);
   fChain->SetBranchAddress("DauLambda_phi", &DauLambda_phi, &b_DauLambda_phi);
   fChain->SetBranchAddress("DauLambda_mass", &DauLambda_mass, &b_DauLambda_mass);
   fChain->SetBranchAddress("DauLambda_Dau1_InEventID", &DauLambda_Dau1_InEventID, &b_DauLambda_Dau1_InEventID);
   fChain->SetBranchAddress("DauLambda_Dau1_pt", &DauLambda_Dau1_pt, &b_DauLambda_Dau1_pt);
   fChain->SetBranchAddress("DauLambda_Dau1_eta", &DauLambda_Dau1_eta, &b_DauLambda_Dau1_eta);
   fChain->SetBranchAddress("DauLambda_Dau1_phi", &DauLambda_Dau1_phi, &b_DauLambda_Dau1_phi);
   fChain->SetBranchAddress("DauLambda_Dau1_ch", &DauLambda_Dau1_ch, &b_DauLambda_Dau1_ch);
   fChain->SetBranchAddress("DauLambda_Dau1_dca", &DauLambda_Dau1_dca, &b_DauLambda_Dau1_dca);
   fChain->SetBranchAddress("DauLambda_Dau2_InEventID", &DauLambda_Dau2_InEventID, &b_DauLambda_Dau2_InEventID);
   fChain->SetBranchAddress("DauLambda_Dau2_pt", &DauLambda_Dau2_pt, &b_DauLambda_Dau2_pt);
   fChain->SetBranchAddress("DauLambda_Dau2_eta", &DauLambda_Dau2_eta, &b_DauLambda_Dau2_eta);
   fChain->SetBranchAddress("DauLambda_Dau2_phi", &DauLambda_Dau2_phi, &b_DauLambda_Dau2_phi);
   fChain->SetBranchAddress("DauLambda_Dau2_ch", &DauLambda_Dau2_ch, &b_DauLambda_Dau2_ch);
   fChain->SetBranchAddress("DauLambda_Dau2_dca", &DauLambda_Dau2_dca, &b_DauLambda_Dau2_dca);
   fChain->SetBranchAddress("pion3_InEventID", &pion3_InEventID, &b_pion3_InEventID);
   fChain->SetBranchAddress("pion3_pt", &pion3_pt, &b_pion3_pt);
   fChain->SetBranchAddress("pion3_eta", &pion3_eta, &b_pion3_eta);
   fChain->SetBranchAddress("pion3_phi", &pion3_phi, &b_pion3_phi);
   fChain->SetBranchAddress("pion3_ch", &pion3_ch, &b_pion3_ch);
   fChain->SetBranchAddress("pion3_dca", &pion3_dca, &b_pion3_dca);
   fChain->SetBranchAddress("Xi_Charge", &Xi_Charge, &b_Xi_Charge);
   fChain->SetBranchAddress("Xi_DCAdaughters", &Xi_DCAdaughters, &b_Xi_DCAdaughters);
   fChain->SetBranchAddress("Xi_theta", &Xi_theta, &b_Xi_theta);
   fChain->SetBranchAddress("Xi_DecayL", &Xi_DecayL, &b_Xi_DecayL);
   fChain->SetBranchAddress("Xi_pt", &Xi_pt, &b_Xi_pt);
   fChain->SetBranchAddress("Xi_eta", &Xi_eta, &b_Xi_eta);
   fChain->SetBranchAddress("Xi_phi", &Xi_phi, &b_Xi_phi);
   fChain->SetBranchAddress("Xi_mass", &Xi_mass, &b_Xi_mass);
   fChain->SetBranchAddress("Xi_DCA", &Xi_DCA, &b_Xi_DCA);
   fChain->SetBranchAddress("track_Number", &track_Number, &b_track_Number);
   fChain->SetBranchAddress("track_pt", track_pt, &b_track_pt);
   fChain->SetBranchAddress("track_eta", track_eta, &b_track_eta);
   fChain->SetBranchAddress("track_phi", track_phi, &b_track_phi);
   fChain->SetBranchAddress("track_InEventID", track_InEventID, &b_track_InEventID);
   fChain->SetBranchAddress("track_dca", track_dca, &b_track_dca);
   fChain->SetBranchAddress("track_dcaxy", track_dcaxy, &b_track_dcaxy);
   fChain->SetBranchAddress("track_nSigmaPion", track_nSigmaPion, &b_track_nSigmaPion);
   fChain->SetBranchAddress("track_nSigmaKaon", track_nSigmaKaon, &b_track_nSigmaKaon);
   fChain->SetBranchAddress("track_nSigmaProton", track_nSigmaProton, &b_track_nSigmaProton);
   fChain->SetBranchAddress("track_dedx", track_dedx, &b_track_dedx);
   fChain->SetBranchAddress("track_ch", track_ch, &b_track_ch);
   Notify();
}

bool ntp_Lambda::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void ntp_Lambda::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ntp_Lambda::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ntp_Lambda_cxx
