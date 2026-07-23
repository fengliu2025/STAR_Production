#ifndef StPicoLambdaAnaMaker_h
#define StPicoLambdaAnaMaker_h

#include "StPicoHFMaker/StPicoHFMaker.h"
#include "TNtuple.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TTree.h"

//#include "StPicoDpmAnaHists.h"
#include <vector>

#include "TClonesArray.h"

#include "TLorentzVector.h"
#include "TVector3.h"

#include "StPicoEvent/StPicoDst.h"
#include "StPicoDstMaker/StPicoDstMaker.h"
#include "StPicoEvent/StPicoEvent.h"
#include "StPicoEvent/StPicoTrack.h"
#include "StPicoEvent/StPicoBTofPidTraits.h"

#include "StPicoHFMaker/StPicoHFEvent.h"
#include "StPicoHFMaker/StHFCuts.h"
#include "StPicoHFMaker/StHFPair.h"
#include "StPicoHFMaker/StHFTriplet.h"
#include "StBTofUtil/tofPathLength.hh"

#include "phys_constants.h"

#include "TH1F.h"
#include "TH3F.h"


#include <ctime>

/* **************************************************
 *  Sample class fo HF picoDST analysis
 * --------------------------------------------------
 * 
 *  For more info look also in the .h files in StPicoHFMaker/
 *     StPicoHFMaker/StPicoHFMaker.h      <-- Base Class for analysis
 *     StPicoHFMaker/StPicoHFEvent.h      <-- Holds candidates for one event (written to Tree)
 *     StPicoHFMaker/StHFCuts.h           <-- Cuts, can be set in run macro
 *     StPicoHFMaker/StHFPair.h           <-- Holds a pair candidate of a two body decay
 *     StPicoHFMaker/StHFTriplet.h        <-- Holds a triplet of a three body decay
 *
 *  Usage:
 *   - Implement
 *        InitHF()
 *        MakeHF()
 *        ClearHF()
 *        FinishHF()
 *
 *  - Do not ovewrite Init, Make, Clear, Finish which are inhertited from StPicoHFMaker via StMaker 

 *  - Set StHFCuts class via setHFBaseCuts(...) in run macro
 *
 *  - Set use mode of StPicoHFMaker class  via setMakerMode(...)
 *     use enum of StPicoHFMaker::eMakerMode
 *      StPicoHFMaker::kAnalyze - don't write candidate trees, just fill histograms
 *      StPicoHFMaker::kWrite   - write candidate trees
 *      StPicoHFMaker::kRead    - read candidate trees and fill histograms
 *
 *  - Set decay mode of analysis via setDecayMode(...)
 *     use enum of StPicoHFEvent::eHFEventMode (see there for more info)
 *      StPicoHFEvent::kTwoParticleDecay,
 *      StPicoHFEvent::kThreeParticleDecay
 *      StPicoHFEvent::kTwoAndTwoParticleDecay
 *
 *  - Implement these track selection methods used to fill vectors for 'good' identified particles
 *      (methods from StHFCuts utility class can/should be used)
 *       isPion
 *       isKaon
 *       isProton
 *
 *  --------------------------------------------------
 *  
 *  Initial Authors:  
 *            Xin Dong        (xdong@lbl.gov)
 *            Mustafa Mustafa (mmustafa@lbl.gov)
 *          **Jochen Thaeder  (jmthader@lbl.gov) 
 * 
 *  ** Code Maintainer
 *
 * **************************************************
 */

class StPicoDst;
class StPicoDstMaker;
class StPicoEvent;
class StPicoTrack;
class StPicoHFEvent;

class StHFPair;
class StHFTriplet;
class StHFCuts;

class StPicoLambdaAnaMaker : public StPicoHFMaker 
{
 public:
  StPicoLambdaAnaMaker(char const* name, StPicoDstMaker* picoMaker, char const* outputBaseFileName,  
		       char const* inputHFListHFtree);
  virtual ~StPicoLambdaAnaMaker();
  
  virtual Int_t InitHF();
  virtual Int_t MakeHF();
  virtual void  ClearHF(Option_t *opt);
  virtual Int_t FinishHF();
  // -- Lomnitz: Added this cut funtions to to filter iwthout having to make pairs
  virtual bool isCloseTracks(StPicoTrack const*, StPicoTrack const*,TVector3 const & , float) const;
  virtual double DCA(StPicoTrack const*, TVector3 const &) const;

  int createQA();
  
  // -- ADOPT DECAY CHANNELS, if wished ------------------- 
  void setDecayChannel(unsigned int u) { mDecayChannel = u; }

  enum eDecayChannel {kChannel1, kChannel2, kChannel3};


 protected:
  virtual bool isHadron(StPicoTrack const*, int pidFlag) const;
  virtual bool isPion(StPicoTrack const*) const;
  virtual bool isKaon(StPicoTrack const*) const;
  virtual bool isProton(StPicoTrack const*) const;

private:
  int createCandidates();
  int analyzeCandidates();



  // -- private members --------------------------

  unsigned int mDecayChannel;


  // -- ADD USER MEMBERS HERE ------------------- 
  TH1D *heta_pi;
  TH1D *heta_p;

  TTree *ntp_Lambda;
  TTree *ntp_K0s;

  int mRunNumber;
       
  TString mOutFileBaseName;


   //---Variables for TTree---------------------------
	//event stats
  Int_t runId, eventId;
  Float_t Vz, VzVzVPDmax;
  
  //leading and subleading particles
  Float_t lead_pt, lead_eta, lead_phi;
  Float_t sublead_pt, sublead_eta, sublead_phi;

  //
  Int_t mNTrigs;
  Int_t mTrigId[10];

  Int_t mNTrks;
  Float_t high_phi[1000], high_eta[1000], high_pt[1000];

  Int_t NLambda;

  //daughter 1
  Int_t p1_InEventID[1000];
  Float_t p1_phi[1000], p1_eta[1000], p1_pt[1000], p1_dca[1000]; 
  Int_t p1_ch[1000];
  Int_t p1_hasTOFinfo[1000];
  Float_t p1_dedx[1000], p1_beta[1000];

  //daughter 2
  Int_t p2_InEventID[1000];
  Float_t p2_phi[1000], p2_eta[1000], p2_pt[1000], p2_dca[1000];
  Int_t p2_ch[1000];
  Int_t p2_hasTOFinfo[1000];
  Float_t p2_dedx[1000], p2_beta[1000];

  //pair
  Int_t pair_charge[1000];
  Float_t pair_DCAdaughters[1000];
 
  Float_t pair_theta[1000], pair_cosThetaStar[1000], pair_decayL[1000], pair_phi[1000], pair_eta[1000], pair_pt[1000], pair_mass[1000];

  //production plane
  Float_t thetaProdPlane[1000];

  Float_t prodPlane_x[1000], prodPlane_y[1000], prodPlane_z[1000];


	//ZDCx, BBCx
//	Float_t mBBCx, mZDCx;

	

//-------------------------------------------------
  // -- ADD USER MEMBERS HERE -------------------

  ClassDef(StPicoLambdaAnaMaker, 1) //set to 1
};

#endif
