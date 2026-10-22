#include "StPicoLambdaAnaMaker.h"
//#include "StPicoHFMaker/StHFCuts.h"
#include <iostream>
#include <cmath>

ClassImp(StPicoLambdaAnaMaker)

using namespace std;

// _________________________________________________________
StPicoLambdaAnaMaker::StPicoLambdaAnaMaker(char const* name, StPicoDstMaker* picoMaker, char const* outputBaseFileName,
               char const* inputHFListHFtree = "") :
  StPicoHFMaker(name, picoMaker, outputBaseFileName, inputHFListHFtree),
  mDecayChannel(kChannel1), mOutFileBaseName(outputBaseFileName){


  // constructor
}

// _________________________________________________________
StPicoLambdaAnaMaker::~StPicoLambdaAnaMaker() {
  // destructor
}

// _________________________________________________________
int StPicoLambdaAnaMaker::InitHF() {
  // -- INITIALIZE USER HISTOGRAMS ETC HERE -------------------
  //    add them to the output list mOutList which is automatically written

  // EXAMPLE //  mOutList->Add(new TH1F(...));
  // EXAMPLE //  TH1F* hist = static_cast<TH1F*>(mOutList->Last());

  //QA histograms and TOF matching histograms
  //mOutList->Add(new TH1F("h_time_per_event","h_time_per_event", 2000., 0., 20.));

  if(isMakerMode() == StPicoHFMaker::kAnalyze)
  {

    mOutFileBaseName = mOutFileBaseName.ReplaceAll(".root", "");

    //add QA histogram
    heta_pi = new TH1D("heta_phi", "heta_pi", 400, -2.0, 2.0);
    heta_p = new TH1D("heta_p", "heta_p", 400, -2.0, 2.0);
    h2D_iTPCPrimaryMult_Trigger      = new TH2D("h2D_iTPCPrimaryMult_Trigger","h2D_iTPCPrimaryMult_Trigger",100,-0.5,99.5,5,-0.5,4.5);
    h2D_iTPCPrimaryMultHighQ_Trigger = new TH2D("h2D_iTPCPrimaryMultHighQ_Trigger","h2D_iTPCPrimaryMultHighQ_Trigger",100,-0.5,99.5,5,-0.5,4.5);

    //create TTree to store Lambda candidates
    ntp_Lambda = new TTree("ntp_Lambda", "Lambda TTree"); //create TTree
    //---Set TTree branches------------------------------------------------------------------------------

    //event
    ntp_Lambda->Branch("eventId", &eventId, "eventId/I");       //Int_t eventId
    ntp_Lambda->Branch("Vz", &Vz, "Vz/F"); //VzVzVPDmax
    ntp_Lambda->Branch("mNTrigs", &mNTrigs, "mNTrigs/I");
    ntp_Lambda->Branch("mTrigId", mTrigId, "mTrigId[mNTrigs]/I");
    
    //add track information here, Feng Liu 2026/7/21
    ntp_Lambda->Branch("track_Number"   ,&track_Number     ,"track_Number/I");
    ntp_Lambda->Branch("track_pt"       ,track_pt         ,"track_pt[track_Number]/F");
    ntp_Lambda->Branch("track_eta"      ,track_eta        ,"track_eta[track_Number]/F");
    ntp_Lambda->Branch("track_phi"      ,track_phi        ,"track_phi[track_Number]/F");
    ntp_Lambda->Branch("track_InEventID",track_InEventID  ,"track_InEventID[track_Number]/I");
    ntp_Lambda->Branch("track_hasTOFinfo",track_hasTOFinfo,"track_hasTOFinfo[track_Number]/I");
    ntp_Lambda->Branch("track_beta"      ,track_beta      ,"track_beta[track_Number]/I");
    ntp_Lambda->Branch("track_dca"      ,track_dca        ,"track_dca[track_Number]/F");
    ntp_Lambda->Branch("track_dcaxy"      ,track_dcaxy        ,"track_dcaxy[track_Number]/F");
    ntp_Lambda->Branch("track_nSigmaPion"   ,track_nSigmaPion     ,"track_nSigmaPion[track_Number]/F");
    ntp_Lambda->Branch("track_nSigmaKaon"   ,track_nSigmaKaon     ,"track_nSigmaKaon[track_Number]/F");
    ntp_Lambda->Branch("track_nSigmaProton" ,track_nSigmaProton   ,"track_nSigmaProton[track_Number]/F");
    ntp_Lambda->Branch("track_dedx"         ,track_dedx           ,"track_dedx[track_Number]/F");
    ntp_Lambda->Branch("track_ch"           ,track_ch             ,"track_ch[track_Number]/I");
    //ntp_Lambda->Branch("track_nHits"        ,track_nHits          ,"track_nHits[track_Number]/I");
    //ntp_Lambda->Branch("track_nHitsnMax"    ,track_nHitsnMax      ,"track_nHitsnMax[track_Number]/F");
    //-----------------------Set branches END-----------------------------------------------------------------------------  
    
  }

  if(isMakerMode() == StPicoHFMaker::kQA)
  {    
      
    mOutList->Add(new TH1F("h_piTPC","h_piTPC",100,0,10));
    mOutList->Add(new TH1F("h_kTPC","h_kTPC",100,0,10));
    mOutList->Add(new TH1F("h_pTPC","h_pTPC",100,0,10));

    mOutList->Add(new TH1F("h_piTPC_prim","h_piTPC_prim",100,0,10));
    mOutList->Add(new TH1F("h_kTPC_prim","h_kTPC_prim",100,0,10));
    mOutList->Add(new TH1F("h_pTPC_prim","h_pTPC_prim",100,0,10));

    mOutList->Add(new TH2F("h_piTOF","h_piTOF",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_kTOF","h_kTOF",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_pTOF","h_pTOF",100,0,10, 2, 0, 2));

    mOutList->Add(new TH2F("h_piTOF_20","h_piTOF_20",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_kTOF_20","h_kTOF_20",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_pTOF_20","h_pTOF_20",100,0,10, 2, 0, 2));
    
    mOutList->Add(new TH2F("h_piTOF_BEMC_match","h_piTOF_BEMC_match",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_kTOF_BEMC_match","h_kTOF_BEMC_match",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_pTOF_BEMC_match","h_pTOF_BEMC_match",100,0,10, 2, 0, 2));

    mOutList->Add(new TH2F("h_piTOF_1sig","h_piTOF_1sig",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_kTOF_1sig","h_kTOF_1sig",100,0,10, 2, 0, 2));
    mOutList->Add(new TH2F("h_pTOF_1sig","h_pTOF_1sig",100,0,10, 2, 0, 2));

    mOutList->Add(new TH2F("h_piTOFbeta","h_piTOFbeta",500,0,10, 500, 0, 5));
    mOutList->Add(new TH2F("h_kTOFbeta","h_kTOFbeta",500,0,10, 500, 0, 5));
    mOutList->Add(new TH2F("h_pTOFbeta","h_pTOFbeta",500,0,10, 500, 0, 5));
    
    
    mOutList->Add(new TH1F("h_piHFT","h_piHFT",100,0,10));
    mOutList->Add(new TH1F("h_kHFT","h_kHFT",100,0,10));
    mOutList->Add(new TH1F("h_pHFT","h_pHFT",100,0,10));
    
    mOutList->Add(new TH1F("h_piHFT_TOF","h_piHFT_TOF",100,0,10));
    mOutList->Add(new TH1F("h_kHFT_TOF","h_kHFT_TOF",100,0,10));
    mOutList->Add(new TH1F("h_pHFT_TOF","h_pHFT_TOF",100,0,10));
    
    

  }


  mRunNumber = 0;
  return kStOK;
}

// _________________________________________________________
void StPicoLambdaAnaMaker::ClearHF(Option_t *opt="") {
  return;
}

// _________________________________________________________
int StPicoLambdaAnaMaker::FinishHF() 
{
   if( isMakerMode() == StPicoHFMaker::kAnalyze )
   {
     heta_pi->Write();
     heta_p->Write();
     //h2D_iTPCPrimaryMult_Trigger      ->Write();
     //h2D_iTPCPrimaryMultHighQ_Trigger ->Write();

     ntp_Lambda->Write(); //for candidates
    //ntp_K0s->Write();
   }

  return kStOK;
}

// _________________________________________________________
int StPicoLambdaAnaMaker::MakeHF() {

  //create and analyze D+- candidates

  //createCandidates() makes triplets of K and pi and checks that they pass cuts
  //analyzeCandidates() saves relevant information about the triplets to TTree

  //std::clock_t start1 = std::clock();//kvapil

  if (isMakerMode() == StPicoHFMaker::kWrite) {
    createCandidates();
  }
  else if (isMakerMode() == StPicoHFMaker::kRead) {
    // -- the reading back of the perviously written trees happens in the background
    analyzeCandidates();
  }
  else if (isMakerMode() == StPicoHFMaker::kAnalyze)
  {
    //createCandidates();
    analyzeCandidates();
  
    /*
      
     */ //end comment TOF histograms

  }// end if (isMakerMode() == StPicoHFMaker::kAnalyze)
  
  else if (isMakerMode() == StPicoHFMaker::kQA)
  {
    createQA();
  }


/*
    double duration = (double) (std::clock() - start1) / (double) CLOCKS_PER_SEC;
  TH1F *h_time_per_event = static_cast<TH1F*>(mOutList->FindObject("h_time_per_event"));
  h_time_per_event->Fill(duration);
*/
  return kStOK;
}


int StPicoLambdaAnaMaker::createQA()
{
 
  //QA and TOF matching histograms
  TH1F *h_piTPC = static_cast<TH1F*>(mOutList->FindObject("h_piTPC"));
  TH1F *h_kTPC = static_cast<TH1F*>(mOutList->FindObject("h_kTPC"));
  TH1F *h_pTPC = static_cast<TH1F*>(mOutList->FindObject("h_pTPC"));

  TH1F *h_piTPC_prim = static_cast<TH1F*>(mOutList->FindObject("h_piTPC_prim"));
  TH1F *h_kTPC_prim = static_cast<TH1F*>(mOutList->FindObject("h_kTPC_prim"));
  TH1F *h_pTPC_prim = static_cast<TH1F*>(mOutList->FindObject("h_pTPC_prim"));

  TH2F *h_piTOF = static_cast<TH2F*>(mOutList->FindObject("h_piTOF"));
  TH2F *h_kTOF = static_cast<TH2F*>(mOutList->FindObject("h_kTOF"));
  TH2F *h_pTOF = static_cast<TH2F*>(mOutList->FindObject("h_pTOF"));

  TH2F *h_piTOF_20 = static_cast<TH2F*>(mOutList->FindObject("h_piTOF_20"));
  TH2F *h_kTOF_20 = static_cast<TH2F*>(mOutList->FindObject("h_kTOF_20"));
  TH2F *h_pTOF_20 = static_cast<TH2F*>(mOutList->FindObject("h_pTOF_20"));
  
  TH2F *h_piTOF_BEMC_match = static_cast<TH2F*>(mOutList->FindObject("h_piTOF_BEMC_match"));
  TH2F *h_kTOF_BEMC_match = static_cast<TH2F*>(mOutList->FindObject("h_kTOF_BEMC_match"));
  TH2F *h_pTOF_BEMC_match = static_cast<TH2F*>(mOutList->FindObject("h_pTOF_BEMC_match"));

  TH2F *h_piTOF_1sig = static_cast<TH2F*>(mOutList->FindObject("h_piTOF_1sig"));
  TH2F *h_kTOF_1sig = static_cast<TH2F*>(mOutList->FindObject("h_kTOF_1sig"));
  TH2F *h_pTOF_1sig = static_cast<TH2F*>(mOutList->FindObject("h_pTOF_1sig"));

  TH2F *h_piTOFbeta = static_cast<TH2F*>(mOutList->FindObject("h_piTOFbeta"));
  TH2F *h_kTOFbeta = static_cast<TH2F*>(mOutList->FindObject("h_kTOFbeta"));
  TH2F *h_pTOFbeta = static_cast<TH2F*>(mOutList->FindObject("h_pTOFbeta"));
  
  
  TH1F *h_piHFT =  static_cast<TH1F*>(mOutList->FindObject("h_piHFT"));
  TH1F *h_kHFT =  static_cast<TH1F*>(mOutList->FindObject("h_kHFT"));
  TH1F *h_pHFT =  static_cast<TH1F*>(mOutList->FindObject("h_pHFT"));
  
  TH1F *h_piHFT_TOF =  static_cast<TH1F*>(mOutList->FindObject("h_piHFT_TOF"));
  TH1F *h_kHFT_TOF =  static_cast<TH1F*>(mOutList->FindObject("h_kHFT_TOF"));
  TH1F *h_pHFT_TOF =  static_cast<TH1F*>(mOutList->FindObject("h_pHFT_TOF"));



  //primary vertex
  TVector3 pVtx = mPicoDst->event()->primaryVertex();

 

  for (unsigned short idxPion = 0; idxPion < mIdxPicoPions.size(); ++idxPion)
  {
    StPicoTrack const *pion = mPicoDst->track(mIdxPicoPions[idxPion]);
   
   
    
    //calculate beta of track from its momentum
    float piBeta = mHFCuts->getTofBetaBase(pion, mPicoDst->event()->bField()); //SL16j, Vanek

    //get beta of track from TOF, if TOF information is available          
    Int_t piTofAvailable = 0;
    if(!isnan(piBeta) && piBeta > 0)
    {
       piTofAvailable = 1;
       float tofPion = fabs(1. / piBeta - sqrt(1+M_PION_PLUS*M_PION_PLUS/(pion->gMom().Mag()*pion->gMom().Mag())));
       h_piTOFbeta->Fill(pion->gPt(),tofPion);
    }

    //fill QA and TOF matching histograms
    h_piTOF->Fill(pion->gPt(),piTofAvailable);
    
    if (mHFCuts->hasGoodNHitsFitMinHist(pion))
    {
      h_piTPC->Fill(pion->gPt());

      if(pion->isPrimary())
      {
        h_piTPC_prim->Fill(pion->pPt());
      }

      h_piTOF_20->Fill(pion->gPt(),piTofAvailable);
      
      if(pion->isBemcTrack())
      {
        h_piTOF_BEMC_match->Fill(pion->gPt(), piTofAvailable);     
      
      }
      
      if(pion->hasIstHit() || pion->hasSstHit())
      {
        h_piHFT->Fill(pion->gPt());
        
        if(piTofAvailable)
        {
          h_piHFT_TOF->Fill(pion->gPt());
        }
      }

    }

    if (mHFCuts->hasGoodNSigmaHist(pion, 1)) h_piTOF_1sig->Fill(pion->gPt(),piTofAvailable); //hasGoodNSigmaHist(pion, 1) => check nSigma of pion
      

  }
  
  
  for (unsigned short idxKaon = 0; idxKaon < mIdxPicoKaons.size(); ++idxKaon)
  {
    StPicoTrack const *kaon = mPicoDst->track(mIdxPicoKaons[idxKaon]);
   
   
    
    float kBeta = mHFCuts->getTofBetaBase(kaon, mPicoDst->event()->bField()); //SL16j, Vanek
    Int_t kTofAvailable = 0;
    if(!isnan(kBeta) && kBeta > 0)
    {
      kTofAvailable = 1;
      float tofKaon = fabs(1. / kBeta - sqrt(1+M_KAON_PLUS*M_KAON_PLUS/(kaon->gMom().Mag()*kaon->gMom().Mag())));
      h_pTOFbeta->Fill(kaon->gPt(),tofKaon);
    }

    h_pTOF->Fill(kaon->gPt(),kTofAvailable);

    if (mHFCuts->hasGoodNHitsFitMinHist(kaon))
    {
      h_pTPC->Fill(kaon->gPt());

      if(kaon->isPrimary())
      {
        h_pTPC_prim->Fill(kaon->pPt());
      }
    
      h_pTOF_20->Fill(kaon->gPt(),kTofAvailable);
      
      if(kaon->isBemcTrack())
      {
        h_kTOF_BEMC_match->Fill(kaon->gPt(), kTofAvailable);      
      }
      
      if(kaon->hasIstHit() || kaon->hasSstHit())
      {
        h_kHFT->Fill(kaon->gPt());
        
        if(kTofAvailable)
        {
          h_kHFT_TOF->Fill(kaon->gPt());
        }
      }
      
    }
        
    if (fabs(mHFCuts->hasGoodNSigmaHist(kaon, 3))) h_pTOF_1sig->Fill(kaon->gPt(),kTofAvailable); //hasGoodNSigmaHist(kaon, 3) => check nSigma of kaon
       

  }
  


  for (unsigned short idxProton = 0; idxProton < mIdxPicoProtons.size(); ++idxProton)
  {
    StPicoTrack const *proton = mPicoDst->track(mIdxPicoProtons[idxProton]);
   
   
    
    float pBeta = mHFCuts->getTofBetaBase(proton, mPicoDst->event()->bField()); //SL16j, Vanek
    Int_t pTofAvailable = 0;
    if(!isnan(pBeta) && pBeta > 0)
    {
      pTofAvailable = 1;
      float tofProton = fabs(1. / pBeta - sqrt(1+M_PROTON*M_PROTON/(proton->gMom().Mag()*proton->gMom().Mag())));
      h_pTOFbeta->Fill(proton->gPt(),tofProton);
    }

    h_pTOF->Fill(proton->gPt(),pTofAvailable);

    if (mHFCuts->hasGoodNHitsFitMinHist(proton))
    {
      h_pTPC->Fill(proton->gPt());

      if(proton->isPrimary())
      {
        h_pTPC_prim->Fill(proton->pPt());
      }
    
      h_pTOF_20->Fill(proton->gPt(),pTofAvailable);
      
      if(proton->isBemcTrack())
      {
        h_pTOF_BEMC_match->Fill(proton->gPt(), pTofAvailable);      
      }
      
      if(proton->hasIstHit() || proton->hasSstHit())
      {
        h_pHFT->Fill(proton->gPt());
        
        if(pTofAvailable)
        {
          h_pHFT_TOF->Fill(proton->gPt());
        }
      }
      
    }
        
    if (fabs(mHFCuts->hasGoodNSigmaHist(proton, 3))) h_pTOF_1sig->Fill(proton->gPt(),pTofAvailable); //hasGoodNSigmaHist(proton, 3) => check nSigma of proton
       

  }


       
  return 0;
}

// _________________________________________________________
int StPicoLambdaAnaMaker::createCandidates() {
  // Creating candidates for Lambda decay
  // Lambda -> p pi- decay
  //cout<<"start createCandidates"<<endl;

  for (unsigned short idxPion = 0; idxPion < mIdxPicoPions.size(); ++idxPion)
  {
      StPicoTrack const *pion = mPicoDst->track(mIdxPicoPions[idxPion]);
      float eta = pion->gMom().PseudoRapidity();;
      heta_pi->Fill(eta);
  }

  for (unsigned short idxProton = 0; idxProton < mIdxPicoProtons.size(); ++idxProton)
  {
      StPicoTrack const *proton = mPicoDst->track(mIdxPicoProtons[idxProton]);
      float eta = proton->gMom().PseudoRapidity();
      heta_p->Fill(eta);
  }

  for (unsigned short idxPion = 0; idxPion < mIdxPicoPions.size(); ++idxPion)
  {
    StPicoTrack const *pion = mPicoDst->track(mIdxPicoPions[idxPion]);
    // -- Pion selection
    //check that pion has TOF info here to speed up the code
    float piBetaBase = -1;
    piBetaBase = mHFCuts->getTofBetaBase(pion, mPicoDst->event()->bField());
    //get beta of track from TOF, if TOF information is available          
    int pi_hasTOFinfo = 0;
    if(!isnan(piBetaBase) && piBetaBase > 0)
    {
      pi_hasTOFinfo = 1;
    }

    if( mHFCuts->requireStrictTOF() && pi_hasTOFinfo == 0 ) continue; //strict TOF matching for pions, turned on/off in run macro
    for (unsigned short idxProton = 0; idxProton < mIdxPicoProtons.size(); ++idxProton)
    {
      StPicoTrack const *proton = mPicoDst->track(mIdxPicoProtons[idxProton]);
      if (mIdxPicoProtons[idxProton] == mIdxPicoPions[idxPion]) continue;
      // -- Making pair, want proton first for cosThetaStar calculation
      StHFPair pair(proton, pion, mHFCuts->getHypotheticalMass(StHFCuts::kProton), mHFCuts->getHypotheticalMass(StHFCuts::kPion), mIdxPicoProtons[idxProton], mIdxPicoPions[idxPion], mPrimVtx, mBField, false);
      //cout<<pair.prodPlane().x()<<endl;
      if(!mHFCuts->isGoodSecondaryVertexPair(pair)) continue;
      mPicoHFEvent->addHFSecondaryVertexPair(&pair);
    } //end for (unsigned short idxProton = 0; idxProton < mIdxPicoProtons.size(); ++idxProton)
  } //end for (unsigned short idxPion = 0; idxPion < mIdxPicoPions.size(); ++idxPion)
  
  //cout<<"done createCandidates"<<endl;

  return kStOK;
}

// _________________________________________________________
int StPicoLambdaAnaMaker::analyzeCandidates() {

  //cout<<"start analyzeCandidates"<<endl;
  // --- Analyze previously constructed pairs and save to ntuple
  // -- Decay channel1
  
  Vz=-9999;

  StPicoEvent *picoEvent = mPicoDst->event();

  //fill trigger
  mNTrigs=0;
  //vector<unsigned int> triggerIds = picoEvent->triggerIds();
  unsigned int mStPhysics_TriggerIDs[5]={910001, 910003, 910013, 910802, 910804};
  for(int itrig=0; itrig<5; itrig++){
    if(picoEvent->isTrigger(mStPhysics_TriggerIDs[itrig])){
      mTrigId[mNTrigs] = mStPhysics_TriggerIDs[itrig];
      mNTrigs++;
    }
  }

 
 
  eventId = mPicoHFEvent->eventId();
  Vz = mPicoDst->event()->primaryVertex().z();
  



  track_Number = 0;
  // only fill the track information when there are at least two lambda candidates. 
  Int_t nTrk = mPicoDst->numberOfTracks();
  TVector3 PrimaryVtxPos          = picoEvent->primaryVertex(); 
  
    for(Int_t i=0;i<nTrk;i++){
        StPicoTrack const* trk = mPicoDst->track(i);
        if(!trk) continue;
        if(!mHFCuts->isGoodTrack(trk) ) continue;
        track_pt[track_Number]          = trk->gPt();
        track_eta[track_Number]         = trk->gMom().PseudoRapidity();
        track_phi[track_Number]         = trk->gMom().Phi();
        track_InEventID[track_Number]   = i;
        track_dca[track_Number]         = trk->gDCA(PrimaryVtxPos).Mag();
        track_dcaxy[track_Number]         = trk->gDCAxy(mPrimVtx.x(), mPrimVtx.y());
        track_nSigmaPion[track_Number]      =trk->nSigmaPion();
        track_nSigmaKaon[track_Number]      =trk->nSigmaKaon();
        track_nSigmaProton[track_Number]    =trk->nSigmaProton();
        track_dedx[track_Number]            =trk->dEdx();
        track_ch[track_Number]              =trk->charge();


        //TOF info 
        float track_BetaBase = -1;
        track_BetaBase = mHFCuts->getTofBetaBase(trk, mPicoDst->event()->bField());
        track_hasTOFinfo[track_Number] = 0 ;
        if(!isnan(track_BetaBase) && track_BetaBase > 0)
        {
          track_hasTOFinfo[NLambda] = 1;      
        }

        track_beta[track_Number] = -999.0;
        Int_t bTofPidTraitsIndex1          = trk->bTofPidTraitsIndex();
  
        if(bTofPidTraitsIndex1>=0){
              StPicoBTofPidTraits *btofPidTraits1 = mPicoDst->btofPidTraits(bTofPidTraitsIndex1);
              if(btofPidTraits1->btofMatchFlag()) {
                 track_beta[track_Number]     = btofPidTraits1->btofBeta();
              }
        }


        track_Number++;             
    }
  return kStOK;
}

// _________________________________________________________
bool StPicoLambdaAnaMaker::isHadron(StPicoTrack const * const trk, int pidFlag) const {
  // -- good hadron
  return (mHFCuts->isGoodTrack(trk) && mHFCuts->isTPCHadron(trk, pidFlag));
}

// _________________________________________________________
bool StPicoLambdaAnaMaker::isPion(StPicoTrack const * const trk) const {
  // -- good pion

   TVector3 t = trk->gMom();
   //if ( !(trk->hasIstHit() || trk->hasSstHit()) ) return false; //for testing - match pions to IST or SST for Run15
   if (!mHFCuts->hasGoodEta(t)) return false; 
   if (!mHFCuts->isHybridTOFHadron(trk, mHFCuts->getTofBetaBase(trk, mPicoDst->event()->bField()), StHFCuts::kPion) ) return false;
   if (!mHFCuts->cutMinDcaToPrimVertex(trk, StPicoCutsBase::kPion)) return false;
   return (mHFCuts->isGoodTrack(trk) && mHFCuts->isTPCHadron(trk, StPicoCutsBase::kPion));
}

// _________________________________________________________
bool StPicoLambdaAnaMaker::isKaon(StPicoTrack const * const trk) const {
  // -- good kaon

  TVector3 t = trk->gMom();
  if (!mHFCuts->hasGoodEta(t)) return false;
  if (!mHFCuts->isHybridTOFHadron(trk, mHFCuts->getTofBetaBase(trk, mPicoDst->event()->bField()), StHFCuts::kKaon) ) return false;
  if (!mHFCuts->cutMinDcaToPrimVertex(trk, StPicoCutsBase::kKaon)) return false;
  return (mHFCuts->isGoodTrack(trk) && mHFCuts->isTPCHadron(trk, StPicoCutsBase::kKaon));
}

// _________________________________________________________
bool StPicoLambdaAnaMaker::isProton(StPicoTrack const * const trk) const {
  // -- good proton
  TVector3 t = trk->gMom();
  //if ( !(trk->hasIstHit() || trk->hasSstHit()) ) return false; //for testing - match pions to IST or SST for Run15
  if (!mHFCuts->hasGoodEta(t)) return false; 
  if (!mHFCuts->isHybridTOFHadron(trk, mHFCuts->getTofBetaBase(trk, mPicoDst->event()->bField()), StHFCuts::kProton) ) return false;
  if (!mHFCuts->cutMinDcaToPrimVertex(trk, StPicoCutsBase::kProton)) return false;
  return (mHFCuts->isGoodTrack(trk) && mHFCuts->isTPCHadron(trk, StPicoCutsBase::kProton));
}

double StPicoLambdaAnaMaker::DCA(StPicoTrack const * const trk, TVector3 const & vtx) const {
  // -- particle DCA

  return ((trk->origin() - vtx).Mag());
}


bool StPicoLambdaAnaMaker::isCloseTracks(StPicoTrack const * const trk1, StPicoTrack const * const trk2, TVector3 const & vtx, float bField) const {
  // -- good pair

  if( ( trk1->origin()-vtx ).Mag()>1.5 || ( trk2->origin()-vtx ).Mag()>1.5 ) return false;

  TVector3 const p1Mom = trk1->gMom();
  TVector3 const p2Mom = trk2->gMom();
  StPicoPhysicalHelix const p1StraightLine(p1Mom, trk1->origin(), 0, trk1->charge());
  StPicoPhysicalHelix const p2StraightLine(p2Mom, trk2->origin(), 0, trk2->charge());

  pair<double, double> const ss = p1StraightLine.pathLengths(p2StraightLine);
  TVector3 const p1AtDcaToP2 = p1StraightLine.at(ss.first);
  TVector3 const p2AtDcaToP1 = p2StraightLine.at(ss.second);
  float const dca = (p1AtDcaToP2-p2AtDcaToP1).Mag();

  if(dca > mHFCuts->cutSecondaryTripletDcaDaughters12Max()) return false; 

  return true;
}

//-----------------------------------------------------------------------------
