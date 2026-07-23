#ifndef StPicoLambdaAnaMaker_h
#define StPicoLambdaAnaMaker_h

#include "StPicoHFMaker/StPicoHFMaker.h"
#include "TNtuple.h"
#include "TH2F.h"
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

  //daughter 1
  Int_t p1_InEventID;
  Float_t p1_phi, p1_eta, p1_pt, p1_dca; 
  Int_t p1_ch;
  Int_t p1_hasTOFinfo;


	//daughter 2
	Int_t p2_InEventID;
  Float_t p2_phi, p2_eta, p2_pt, p2_dca, p2_ch;
  Int_t p2_hasTOFinfo;


	//pair
  Int_t pair_charge;
  Float_t pair_DCAdaughters;
 
  Float_t pair_theta, pair_cosThetaStar, pair_decayL, pair_phi, pair_eta, pair_pt, pair_mass;

  //production plane
  Float_t thetaProdPlane;

  Float_t prodPlane_x, prodPlane_y, prodPlane_z;


	//ZDCx, BBCx
//	Float_t mBBCx, mZDCx;

	

//-------------------------------------------------
  // -- ADD USER MEMBERS HERE -------------------

  ClassDef(StPicoLambdaAnaMaker, 1) //set to 1
};

#endif
