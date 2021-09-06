//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul  9 19:16:12 2021 by ROOT version 6.22/08
// from TTree events/Events tree
// found on file: /eos/experiment/fcc/hh/generation/DelphesEvents/fcc_v02/mgp8_pp_jj012j_5f_HT_1000_2000/events_166472898.root
//////////////////////////////////////////////////////////

#ifndef events_h
#define events_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class events {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxmePsMatchingVars = 9;
   static constexpr Int_t kMaxmcEventWeights = 1;
   static constexpr Int_t kMaxskimmedGenParticles = 252;
   static constexpr Int_t kMaxskimmedGenParticles#0 = 252;
   static constexpr Int_t kMaxskimmedGenParticles#1 = 252;
   static constexpr Int_t kMaxmuons = 4;
   static constexpr Int_t kMaxmuons#0 = 1;
   static constexpr Int_t kMaxmuons#1 = 1;
   static constexpr Int_t kMaxmuonsToMC#0 = 4;
   static constexpr Int_t kMaxmuonsToMC#1 = 4;
   static constexpr Int_t kMaxmuonITags = 4;
   static constexpr Int_t kMaxmuonITags#0 = 4;
   static constexpr Int_t kMaxelectrons = 10;
   static constexpr Int_t kMaxelectrons#0 = 1;
   static constexpr Int_t kMaxelectrons#1 = 1;
   static constexpr Int_t kMaxelectronsToMC#0 = 10;
   static constexpr Int_t kMaxelectronsToMC#1 = 10;
   static constexpr Int_t kMaxelectronITags = 10;
   static constexpr Int_t kMaxelectronITags#0 = 10;
   static constexpr Int_t kMaxphotons = 104;
   static constexpr Int_t kMaxphotons#0 = 1;
   static constexpr Int_t kMaxphotons#1 = 1;
   static constexpr Int_t kMaxphotonsToMC#0 = 39;
   static constexpr Int_t kMaxphotonsToMC#1 = 39;
   static constexpr Int_t kMaxphotonITags = 104;
   static constexpr Int_t kMaxphotonITags#0 = 104;
   static constexpr Int_t kMaxpfcharged = 525;
   static constexpr Int_t kMaxpfcharged#0 = 1;
   static constexpr Int_t kMaxpfcharged#1 = 1;
   static constexpr Int_t kMaxchargedToMC#0 = 525;
   static constexpr Int_t kMaxchargedToMC#1 = 525;
   static constexpr Int_t kMaxpfphotons = 672;
   static constexpr Int_t kMaxpfphotons#0 = 1;
   static constexpr Int_t kMaxpfphotons#1 = 1;
   static constexpr Int_t kMaxpfphotonsToMC#0 = 44;
   static constexpr Int_t kMaxpfphotonsToMC#1 = 44;
   static constexpr Int_t kMaxpfneutrals = 352;
   static constexpr Int_t kMaxpfneutrals#0 = 1;
   static constexpr Int_t kMaxpfneutrals#1 = 1;
   static constexpr Int_t kMaxpfneutralsToMC#0 = 28;
   static constexpr Int_t kMaxpfneutralsToMC#1 = 28;
   static constexpr Int_t kMaxgenjets02 = 13;
   static constexpr Int_t kMaxgenjets02#0 = 1;
   static constexpr Int_t kMaxgenjetsFlavor02 = 13;
   static constexpr Int_t kMaxgenjetsFlavor02#0 = 13;
   static constexpr Int_t kMaxgenjets04 = 16;
   static constexpr Int_t kMaxgenjets04#0 = 1;
   static constexpr Int_t kMaxgenjetsFlavor04 = 16;
   static constexpr Int_t kMaxgenjetsFlavor04#0 = 16;
   static constexpr Int_t kMaxgenjets08 = 22;
   static constexpr Int_t kMaxgenjets08#0 = 1;
   static constexpr Int_t kMaxgenjetsFlavor08 = 22;
   static constexpr Int_t kMaxgenjetsFlavor08#0 = 22;
   static constexpr Int_t kMaxgenjets15 = 15;
   static constexpr Int_t kMaxgenjets15#0 = 1;
   static constexpr Int_t kMaxgenjetsFlavor15 = 15;
   static constexpr Int_t kMaxgenjetsFlavor15#0 = 15;
   static constexpr Int_t kMaxcalojets02 = 14;
   static constexpr Int_t kMaxcalojets02#0 = 234;
   static constexpr Int_t kMaxcalojetsFlavor02 = 14;
   static constexpr Int_t kMaxcalojetsFlavor02#0 = 14;
   static constexpr Int_t kMaxcalobTags02 = 14;
   static constexpr Int_t kMaxcalobTags02#0 = 14;
   static constexpr Int_t kMaxcalocTags02 = 14;
   static constexpr Int_t kMaxcalocTags02#0 = 14;
   static constexpr Int_t kMaxcalotauTags02 = 14;
   static constexpr Int_t kMaxcalotauTags02#0 = 14;
   static constexpr Int_t kMaxcalojetParts02 = 234;
   static constexpr Int_t kMaxcalojetParts02#0 = 1;
   static constexpr Int_t kMaxcalojetParts02#1 = 1;
   static constexpr Int_t kMaxcalojetsOneSubJettiness02 = 14;
   static constexpr Int_t kMaxcalojetsOneSubJettiness02#0 = 14;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness02 = 14;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness02#0 = 14;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness02 = 14;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness02#0 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged02 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged02#0 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged02#1 = 14;
   static constexpr Int_t kMaxcalosubjetsPruningTagged02 = 14;
   static constexpr Int_t kMaxcalosubjetsPruningTagged02#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruningTagged02#1 = 14;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged02 = 14;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged02#0 = 42;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged02#1 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimming02 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimming02#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning02 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning02#0 = 1;
   static constexpr Int_t kMaxcalosubjetsSoftDrop02 = 42;
   static constexpr Int_t kMaxcalosubjetsSoftDrop02#0 = 1;
   static constexpr Int_t kMaxcalojets04 = 14;
   static constexpr Int_t kMaxcalojets04#0 = 349;
   static constexpr Int_t kMaxcalojetsFlavor04 = 14;
   static constexpr Int_t kMaxcalojetsFlavor04#0 = 14;
   static constexpr Int_t kMaxcalobTags04 = 14;
   static constexpr Int_t kMaxcalobTags04#0 = 14;
   static constexpr Int_t kMaxcalocTags04 = 14;
   static constexpr Int_t kMaxcalocTags04#0 = 14;
   static constexpr Int_t kMaxcalotauTags04 = 14;
   static constexpr Int_t kMaxcalotauTags04#0 = 14;
   static constexpr Int_t kMaxcalojetParts04 = 349;
   static constexpr Int_t kMaxcalojetParts04#0 = 1;
   static constexpr Int_t kMaxcalojetParts04#1 = 1;
   static constexpr Int_t kMaxcalojetsOneSubJettiness04 = 14;
   static constexpr Int_t kMaxcalojetsOneSubJettiness04#0 = 14;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness04 = 14;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness04#0 = 14;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness04 = 14;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness04#0 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged04 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged04#0 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged04#1 = 14;
   static constexpr Int_t kMaxcalosubjetsPruningTagged04 = 14;
   static constexpr Int_t kMaxcalosubjetsPruningTagged04#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruningTagged04#1 = 14;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged04 = 14;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged04#0 = 42;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged04#1 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimming04 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimming04#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning04 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning04#0 = 1;
   static constexpr Int_t kMaxcalosubjetsSoftDrop04 = 42;
   static constexpr Int_t kMaxcalosubjetsSoftDrop04#0 = 1;
   static constexpr Int_t kMaxcalojets08 = 20;
   static constexpr Int_t kMaxcalojets08#0 = 942;
   static constexpr Int_t kMaxcalojetsFlavor08 = 20;
   static constexpr Int_t kMaxcalojetsFlavor08#0 = 20;
   static constexpr Int_t kMaxcalobTags08 = 20;
   static constexpr Int_t kMaxcalobTags08#0 = 20;
   static constexpr Int_t kMaxcalocTags08 = 20;
   static constexpr Int_t kMaxcalocTags08#0 = 20;
   static constexpr Int_t kMaxcalotauTags08 = 20;
   static constexpr Int_t kMaxcalotauTags08#0 = 20;
   static constexpr Int_t kMaxcalojetParts08 = 942;
   static constexpr Int_t kMaxcalojetParts08#0 = 1;
   static constexpr Int_t kMaxcalojetParts08#1 = 1;
   static constexpr Int_t kMaxcalojetsOneSubJettiness08 = 20;
   static constexpr Int_t kMaxcalojetsOneSubJettiness08#0 = 20;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness08 = 20;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness08#0 = 20;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness08 = 20;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness08#0 = 20;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged08 = 20;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged08#0 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged08#1 = 20;
   static constexpr Int_t kMaxcalosubjetsPruningTagged08 = 20;
   static constexpr Int_t kMaxcalosubjetsPruningTagged08#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruningTagged08#1 = 20;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged08 = 20;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged08#0 = 60;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged08#1 = 20;
   static constexpr Int_t kMaxcalosubjetsTrimming08 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimming08#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning08 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning08#0 = 1;
   static constexpr Int_t kMaxcalosubjetsSoftDrop08 = 60;
   static constexpr Int_t kMaxcalosubjetsSoftDrop08#0 = 1;
   static constexpr Int_t kMaxcalojets15 = 14;
   static constexpr Int_t kMaxcalojets15#0 = 1364;
   static constexpr Int_t kMaxcalojetsFlavor15 = 14;
   static constexpr Int_t kMaxcalojetsFlavor15#0 = 14;
   static constexpr Int_t kMaxcalobTags15 = 14;
   static constexpr Int_t kMaxcalobTags15#0 = 14;
   static constexpr Int_t kMaxcalocTags15 = 14;
   static constexpr Int_t kMaxcalocTags15#0 = 14;
   static constexpr Int_t kMaxcalotauTags15 = 14;
   static constexpr Int_t kMaxcalotauTags15#0 = 14;
   static constexpr Int_t kMaxcalojetParts15 = 1364;
   static constexpr Int_t kMaxcalojetParts15#0 = 1;
   static constexpr Int_t kMaxcalojetParts15#1 = 1;
   static constexpr Int_t kMaxcalojetsOneSubJettiness15 = 14;
   static constexpr Int_t kMaxcalojetsOneSubJettiness15#0 = 14;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness15 = 14;
   static constexpr Int_t kMaxcalojetsTwoSubJettiness15#0 = 14;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness15 = 14;
   static constexpr Int_t kMaxcalojetsThreeSubJettiness15#0 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged15 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged15#0 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimmingTagged15#1 = 14;
   static constexpr Int_t kMaxcalosubjetsPruningTagged15 = 14;
   static constexpr Int_t kMaxcalosubjetsPruningTagged15#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruningTagged15#1 = 14;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged15 = 14;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged15#0 = 42;
   static constexpr Int_t kMaxcalosubjetsSoftDropTagged15#1 = 14;
   static constexpr Int_t kMaxcalosubjetsTrimming15 = 1;
   static constexpr Int_t kMaxcalosubjetsTrimming15#0 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning15 = 1;
   static constexpr Int_t kMaxcalosubjetsPruning15#0 = 1;
   static constexpr Int_t kMaxcalosubjetsSoftDrop15 = 42;
   static constexpr Int_t kMaxcalosubjetsSoftDrop15#0 = 1;
   static constexpr Int_t kMaxpfjets02 = 14;
   static constexpr Int_t kMaxpfjets02#0 = 258;
   static constexpr Int_t kMaxpfjetsFlavor02 = 14;
   static constexpr Int_t kMaxpfjetsFlavor02#0 = 14;
   static constexpr Int_t kMaxpfbTags02 = 14;
   static constexpr Int_t kMaxpfbTags02#0 = 14;
   static constexpr Int_t kMaxpfcTags02 = 14;
   static constexpr Int_t kMaxpfcTags02#0 = 14;
   static constexpr Int_t kMaxpftauTags02 = 14;
   static constexpr Int_t kMaxpftauTags02#0 = 14;
   static constexpr Int_t kMaxpfjetParts02 = 258;
   static constexpr Int_t kMaxpfjetParts02#0 = 1;
   static constexpr Int_t kMaxpfjetParts02#1 = 1;
   static constexpr Int_t kMaxpfjetsOneSubJettiness02 = 14;
   static constexpr Int_t kMaxpfjetsOneSubJettiness02#0 = 14;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness02 = 14;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness02#0 = 14;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness02 = 14;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness02#0 = 14;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged02 = 14;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged02#0 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged02#1 = 14;
   static constexpr Int_t kMaxpfsubjetsPruningTagged02 = 14;
   static constexpr Int_t kMaxpfsubjetsPruningTagged02#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruningTagged02#1 = 14;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged02 = 14;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged02#0 = 42;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged02#1 = 14;
   static constexpr Int_t kMaxpfsubjetsTrimming02 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimming02#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning02 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning02#0 = 1;
   static constexpr Int_t kMaxpfsubjetsSoftDrop02 = 42;
   static constexpr Int_t kMaxpfsubjetsSoftDrop02#0 = 1;
   static constexpr Int_t kMaxpfjets04 = 15;
   static constexpr Int_t kMaxpfjets04#0 = 400;
   static constexpr Int_t kMaxpfjetsFlavor04 = 15;
   static constexpr Int_t kMaxpfjetsFlavor04#0 = 15;
   static constexpr Int_t kMaxpfbTags04 = 15;
   static constexpr Int_t kMaxpfbTags04#0 = 15;
   static constexpr Int_t kMaxpfcTags04 = 15;
   static constexpr Int_t kMaxpfcTags04#0 = 15;
   static constexpr Int_t kMaxpftauTags04 = 15;
   static constexpr Int_t kMaxpftauTags04#0 = 15;
   static constexpr Int_t kMaxpfjetParts04 = 400;
   static constexpr Int_t kMaxpfjetParts04#0 = 1;
   static constexpr Int_t kMaxpfjetParts04#1 = 1;
   static constexpr Int_t kMaxpfjetsOneSubJettiness04 = 15;
   static constexpr Int_t kMaxpfjetsOneSubJettiness04#0 = 15;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness04 = 15;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness04#0 = 15;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness04 = 15;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness04#0 = 15;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged04 = 15;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged04#0 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged04#1 = 15;
   static constexpr Int_t kMaxpfsubjetsPruningTagged04 = 15;
   static constexpr Int_t kMaxpfsubjetsPruningTagged04#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruningTagged04#1 = 15;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged04 = 15;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged04#0 = 45;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged04#1 = 15;
   static constexpr Int_t kMaxpfsubjetsTrimming04 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimming04#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning04 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning04#0 = 1;
   static constexpr Int_t kMaxpfsubjetsSoftDrop04 = 45;
   static constexpr Int_t kMaxpfsubjetsSoftDrop04#0 = 1;
   static constexpr Int_t kMaxpfjets08 = 20;
   static constexpr Int_t kMaxpfjets08#0 = 958;
   static constexpr Int_t kMaxpfjetsFlavor08 = 20;
   static constexpr Int_t kMaxpfjetsFlavor08#0 = 20;
   static constexpr Int_t kMaxpfbTags08 = 20;
   static constexpr Int_t kMaxpfbTags08#0 = 20;
   static constexpr Int_t kMaxpfcTags08 = 20;
   static constexpr Int_t kMaxpfcTags08#0 = 20;
   static constexpr Int_t kMaxpftauTags08 = 20;
   static constexpr Int_t kMaxpftauTags08#0 = 20;
   static constexpr Int_t kMaxpfjetParts08 = 958;
   static constexpr Int_t kMaxpfjetParts08#0 = 1;
   static constexpr Int_t kMaxpfjetParts08#1 = 1;
   static constexpr Int_t kMaxpfjetsOneSubJettiness08 = 20;
   static constexpr Int_t kMaxpfjetsOneSubJettiness08#0 = 20;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness08 = 20;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness08#0 = 20;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness08 = 20;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness08#0 = 20;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged08 = 20;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged08#0 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged08#1 = 20;
   static constexpr Int_t kMaxpfsubjetsPruningTagged08 = 20;
   static constexpr Int_t kMaxpfsubjetsPruningTagged08#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruningTagged08#1 = 20;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged08 = 20;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged08#0 = 60;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged08#1 = 20;
   static constexpr Int_t kMaxpfsubjetsTrimming08 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimming08#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning08 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning08#0 = 1;
   static constexpr Int_t kMaxpfsubjetsSoftDrop08 = 60;
   static constexpr Int_t kMaxpfsubjetsSoftDrop08#0 = 1;
   static constexpr Int_t kMaxpfjets15 = 12;
   static constexpr Int_t kMaxpfjets15#0 = 1454;
   static constexpr Int_t kMaxpfjetsFlavor15 = 12;
   static constexpr Int_t kMaxpfjetsFlavor15#0 = 12;
   static constexpr Int_t kMaxpfbTags15 = 12;
   static constexpr Int_t kMaxpfbTags15#0 = 12;
   static constexpr Int_t kMaxpfcTags15 = 12;
   static constexpr Int_t kMaxpfcTags15#0 = 12;
   static constexpr Int_t kMaxpftauTags15 = 12;
   static constexpr Int_t kMaxpftauTags15#0 = 12;
   static constexpr Int_t kMaxpfjetParts15 = 1454;
   static constexpr Int_t kMaxpfjetParts15#0 = 1;
   static constexpr Int_t kMaxpfjetParts15#1 = 1;
   static constexpr Int_t kMaxpfjetsOneSubJettiness15 = 12;
   static constexpr Int_t kMaxpfjetsOneSubJettiness15#0 = 12;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness15 = 12;
   static constexpr Int_t kMaxpfjetsTwoSubJettiness15#0 = 12;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness15 = 12;
   static constexpr Int_t kMaxpfjetsThreeSubJettiness15#0 = 12;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged15 = 12;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged15#0 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimmingTagged15#1 = 12;
   static constexpr Int_t kMaxpfsubjetsPruningTagged15 = 12;
   static constexpr Int_t kMaxpfsubjetsPruningTagged15#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruningTagged15#1 = 12;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged15 = 12;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged15#0 = 36;
   static constexpr Int_t kMaxpfsubjetsSoftDropTagged15#1 = 12;
   static constexpr Int_t kMaxpfsubjetsTrimming15 = 1;
   static constexpr Int_t kMaxpfsubjetsTrimming15#0 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning15 = 1;
   static constexpr Int_t kMaxpfsubjetsPruning15#0 = 1;
   static constexpr Int_t kMaxpfsubjetsSoftDrop15 = 36;
   static constexpr Int_t kMaxpfsubjetsSoftDrop15#0 = 1;
   static constexpr Int_t kMaxtrkjets02 = 12;
   static constexpr Int_t kMaxtrkjets02#0 = 118;
   static constexpr Int_t kMaxtrkjetsFlavor02 = 12;
   static constexpr Int_t kMaxtrkjetsFlavor02#0 = 12;
   static constexpr Int_t kMaxtrkbTags02 = 12;
   static constexpr Int_t kMaxtrkbTags02#0 = 12;
   static constexpr Int_t kMaxtrkcTags02 = 12;
   static constexpr Int_t kMaxtrkcTags02#0 = 12;
   static constexpr Int_t kMaxtrktauTags02 = 12;
   static constexpr Int_t kMaxtrktauTags02#0 = 12;
   static constexpr Int_t kMaxtrkjetParts02 = 118;
   static constexpr Int_t kMaxtrkjetParts02#0 = 1;
   static constexpr Int_t kMaxtrkjetParts02#1 = 1;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness02 = 12;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness02#0 = 12;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness02 = 12;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness02#0 = 12;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness02 = 12;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness02#0 = 12;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged02 = 12;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged02#0 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged02#1 = 12;
   static constexpr Int_t kMaxtrksubjetsPruningTagged02 = 12;
   static constexpr Int_t kMaxtrksubjetsPruningTagged02#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruningTagged02#1 = 12;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged02 = 12;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged02#0 = 36;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged02#1 = 12;
   static constexpr Int_t kMaxtrksubjetsTrimming02 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimming02#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning02 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning02#0 = 1;
   static constexpr Int_t kMaxtrksubjetsSoftDrop02 = 36;
   static constexpr Int_t kMaxtrksubjetsSoftDrop02#0 = 1;
   static constexpr Int_t kMaxtrkjets04 = 10;
   static constexpr Int_t kMaxtrkjets04#0 = 146;
   static constexpr Int_t kMaxtrkjetsFlavor04 = 10;
   static constexpr Int_t kMaxtrkjetsFlavor04#0 = 10;
   static constexpr Int_t kMaxtrkbTags04 = 10;
   static constexpr Int_t kMaxtrkbTags04#0 = 10;
   static constexpr Int_t kMaxtrkcTags04 = 10;
   static constexpr Int_t kMaxtrkcTags04#0 = 10;
   static constexpr Int_t kMaxtrktauTags04 = 10;
   static constexpr Int_t kMaxtrktauTags04#0 = 10;
   static constexpr Int_t kMaxtrkjetParts04 = 146;
   static constexpr Int_t kMaxtrkjetParts04#0 = 1;
   static constexpr Int_t kMaxtrkjetParts04#1 = 1;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness04 = 10;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness04#0 = 10;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness04 = 10;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness04#0 = 10;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness04 = 10;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness04#0 = 10;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged04 = 10;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged04#0 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged04#1 = 10;
   static constexpr Int_t kMaxtrksubjetsPruningTagged04 = 10;
   static constexpr Int_t kMaxtrksubjetsPruningTagged04#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruningTagged04#1 = 10;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged04 = 10;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged04#0 = 30;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged04#1 = 10;
   static constexpr Int_t kMaxtrksubjetsTrimming04 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimming04#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning04 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning04#0 = 1;
   static constexpr Int_t kMaxtrksubjetsSoftDrop04 = 30;
   static constexpr Int_t kMaxtrksubjetsSoftDrop04#0 = 1;
   static constexpr Int_t kMaxtrkjets08 = 12;
   static constexpr Int_t kMaxtrkjets08#0 = 275;
   static constexpr Int_t kMaxtrkjetsFlavor08 = 12;
   static constexpr Int_t kMaxtrkjetsFlavor08#0 = 12;
   static constexpr Int_t kMaxtrkbTags08 = 12;
   static constexpr Int_t kMaxtrkbTags08#0 = 12;
   static constexpr Int_t kMaxtrkcTags08 = 12;
   static constexpr Int_t kMaxtrkcTags08#0 = 12;
   static constexpr Int_t kMaxtrktauTags08 = 12;
   static constexpr Int_t kMaxtrktauTags08#0 = 12;
   static constexpr Int_t kMaxtrkjetParts08 = 275;
   static constexpr Int_t kMaxtrkjetParts08#0 = 1;
   static constexpr Int_t kMaxtrkjetParts08#1 = 1;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness08 = 12;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness08#0 = 12;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness08 = 12;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness08#0 = 12;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness08 = 12;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness08#0 = 12;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged08 = 12;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged08#0 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged08#1 = 12;
   static constexpr Int_t kMaxtrksubjetsPruningTagged08 = 12;
   static constexpr Int_t kMaxtrksubjetsPruningTagged08#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruningTagged08#1 = 12;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged08 = 12;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged08#0 = 36;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged08#1 = 12;
   static constexpr Int_t kMaxtrksubjetsTrimming08 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimming08#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning08 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning08#0 = 1;
   static constexpr Int_t kMaxtrksubjetsSoftDrop08 = 36;
   static constexpr Int_t kMaxtrksubjetsSoftDrop08#0 = 1;
   static constexpr Int_t kMaxtrkjets15 = 9;
   static constexpr Int_t kMaxtrkjets15#0 = 445;
   static constexpr Int_t kMaxtrkjetsFlavor15 = 9;
   static constexpr Int_t kMaxtrkjetsFlavor15#0 = 9;
   static constexpr Int_t kMaxtrkbTags15 = 9;
   static constexpr Int_t kMaxtrkbTags15#0 = 9;
   static constexpr Int_t kMaxtrkcTags15 = 9;
   static constexpr Int_t kMaxtrkcTags15#0 = 9;
   static constexpr Int_t kMaxtrktauTags15 = 9;
   static constexpr Int_t kMaxtrktauTags15#0 = 9;
   static constexpr Int_t kMaxtrkjetParts15 = 445;
   static constexpr Int_t kMaxtrkjetParts15#0 = 1;
   static constexpr Int_t kMaxtrkjetParts15#1 = 1;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness15 = 9;
   static constexpr Int_t kMaxtrkjetsOneSubJettiness15#0 = 9;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness15 = 9;
   static constexpr Int_t kMaxtrkjetsTwoSubJettiness15#0 = 9;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness15 = 9;
   static constexpr Int_t kMaxtrkjetsThreeSubJettiness15#0 = 9;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged15 = 9;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged15#0 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimmingTagged15#1 = 9;
   static constexpr Int_t kMaxtrksubjetsPruningTagged15 = 9;
   static constexpr Int_t kMaxtrksubjetsPruningTagged15#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruningTagged15#1 = 9;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged15 = 9;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged15#0 = 27;
   static constexpr Int_t kMaxtrksubjetsSoftDropTagged15#1 = 9;
   static constexpr Int_t kMaxtrksubjetsTrimming15 = 1;
   static constexpr Int_t kMaxtrksubjetsTrimming15#0 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning15 = 1;
   static constexpr Int_t kMaxtrksubjetsPruning15#0 = 1;
   static constexpr Int_t kMaxtrksubjetsSoftDrop15 = 27;
   static constexpr Int_t kMaxtrksubjetsSoftDrop15#0 = 1;
   static constexpr Int_t kMaxmet = 1;

   // Declaration of leaf types
   Int_t           mePsMatchingVars_;
   Float_t         mePsMatchingVars_value[kMaxmePsMatchingVars];   //[mePsMatchingVars_]
   Int_t           mcEventWeights_;
   Float_t         mcEventWeights_value[kMaxmcEventWeights];   //[mcEventWeights_]
   Int_t           skimmedGenParticles_;
   UInt_t          skimmedGenParticles_core_bits[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Int_t           skimmedGenParticles_core_charge[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Float_t         skimmedGenParticles_core_p4_mass[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Float_t         skimmedGenParticles_core_p4_px[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Float_t         skimmedGenParticles_core_p4_py[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Float_t         skimmedGenParticles_core_p4_pz[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Int_t           skimmedGenParticles_core_pdgId[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   UInt_t          skimmedGenParticles_core_status[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Float_t         skimmedGenParticles_core_vertex_x[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Float_t         skimmedGenParticles_core_vertex_y[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Float_t         skimmedGenParticles_core_vertex_z[kMaxskimmedGenParticles];   //[skimmedGenParticles_]
   Int_t           skimmedGenParticles#0_;
   Int_t           skimmedGenParticles#0_index[kMaxskimmedGenParticles#0];   //[skimmedGenParticles#0_]
   Int_t           skimmedGenParticles#0_collectionID[kMaxskimmedGenParticles#0];   //[skimmedGenParticles#0_]
   Int_t           skimmedGenParticles#1_;
   Int_t           skimmedGenParticles#1_index[kMaxskimmedGenParticles#1];   //[skimmedGenParticles#1_]
   Int_t           skimmedGenParticles#1_collectionID[kMaxskimmedGenParticles#1];   //[skimmedGenParticles#1_]
   Int_t           muons_;
   UInt_t          muons_core_bits[kMaxmuons];   //[muons_]
   Int_t           muons_core_charge[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_mass[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_px[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_py[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_pz[kMaxmuons];   //[muons_]
   Int_t           muons_core_pdgId[kMaxmuons];   //[muons_]
   UInt_t          muons_core_status[kMaxmuons];   //[muons_]
   Float_t         muons_core_vertex_x[kMaxmuons];   //[muons_]
   Float_t         muons_core_vertex_y[kMaxmuons];   //[muons_]
   Float_t         muons_core_vertex_z[kMaxmuons];   //[muons_]
   UInt_t          muons_tracks_begin[kMaxmuons];   //[muons_]
   UInt_t          muons_tracks_end[kMaxmuons];   //[muons_]
   UInt_t          muons_clusters_begin[kMaxmuons];   //[muons_]
   UInt_t          muons_clusters_end[kMaxmuons];   //[muons_]
   Int_t           muons#0_;
   Int_t           muons#0_index[kMaxmuons#0];   //[muons#0_]
   Int_t           muons#0_collectionID[kMaxmuons#0];   //[muons#0_]
   Int_t           muons#1_;
   Int_t           muons#1_index[kMaxmuons#1];   //[muons#1_]
   Int_t           muons#1_collectionID[kMaxmuons#1];   //[muons#1_]
   vector<fcc::ParticleMCParticleAssociationData> *muonsToMC;
   Int_t           muonsToMC#0_;
   Int_t           muonsToMC#0_index[kMaxmuonsToMC#0];   //[muonsToMC#0_]
   Int_t           muonsToMC#0_collectionID[kMaxmuonsToMC#0];   //[muonsToMC#0_]
   Int_t           muonsToMC#1_;
   Int_t           muonsToMC#1_index[kMaxmuonsToMC#1];   //[muonsToMC#1_]
   Int_t           muonsToMC#1_collectionID[kMaxmuonsToMC#1];   //[muonsToMC#1_]
   Int_t           muonITags_;
   Float_t         muonITags_tag[kMaxmuonITags];   //[muonITags_]
   Int_t           muonITags#0_;
   Int_t           muonITags#0_index[kMaxmuonITags#0];   //[muonITags#0_]
   Int_t           muonITags#0_collectionID[kMaxmuonITags#0];   //[muonITags#0_]
   Int_t           electrons_;
   UInt_t          electrons_core_bits[kMaxelectrons];   //[electrons_]
   Int_t           electrons_core_charge[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_mass[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_px[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_py[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_pz[kMaxelectrons];   //[electrons_]
   Int_t           electrons_core_pdgId[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_core_status[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_vertex_x[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_vertex_y[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_vertex_z[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_tracks_begin[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_tracks_end[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_clusters_begin[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_clusters_end[kMaxelectrons];   //[electrons_]
   Int_t           electrons#0_;
   Int_t           electrons#0_index[kMaxelectrons#0];   //[electrons#0_]
   Int_t           electrons#0_collectionID[kMaxelectrons#0];   //[electrons#0_]
   Int_t           electrons#1_;
   Int_t           electrons#1_index[kMaxelectrons#1];   //[electrons#1_]
   Int_t           electrons#1_collectionID[kMaxelectrons#1];   //[electrons#1_]
   vector<fcc::ParticleMCParticleAssociationData> *electronsToMC;
   Int_t           electronsToMC#0_;
   Int_t           electronsToMC#0_index[kMaxelectronsToMC#0];   //[electronsToMC#0_]
   Int_t           electronsToMC#0_collectionID[kMaxelectronsToMC#0];   //[electronsToMC#0_]
   Int_t           electronsToMC#1_;
   Int_t           electronsToMC#1_index[kMaxelectronsToMC#1];   //[electronsToMC#1_]
   Int_t           electronsToMC#1_collectionID[kMaxelectronsToMC#1];   //[electronsToMC#1_]
   Int_t           electronITags_;
   Float_t         electronITags_tag[kMaxelectronITags];   //[electronITags_]
   Int_t           electronITags#0_;
   Int_t           electronITags#0_index[kMaxelectronITags#0];   //[electronITags#0_]
   Int_t           electronITags#0_collectionID[kMaxelectronITags#0];   //[electronITags#0_]
   Int_t           photons_;
   UInt_t          photons_core_bits[kMaxphotons];   //[photons_]
   Int_t           photons_core_charge[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_mass[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_px[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_py[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_pz[kMaxphotons];   //[photons_]
   Int_t           photons_core_pdgId[kMaxphotons];   //[photons_]
   UInt_t          photons_core_status[kMaxphotons];   //[photons_]
   Float_t         photons_core_vertex_x[kMaxphotons];   //[photons_]
   Float_t         photons_core_vertex_y[kMaxphotons];   //[photons_]
   Float_t         photons_core_vertex_z[kMaxphotons];   //[photons_]
   UInt_t          photons_tracks_begin[kMaxphotons];   //[photons_]
   UInt_t          photons_tracks_end[kMaxphotons];   //[photons_]
   UInt_t          photons_clusters_begin[kMaxphotons];   //[photons_]
   UInt_t          photons_clusters_end[kMaxphotons];   //[photons_]
   Int_t           photons#0_;
   Int_t           photons#0_index[kMaxphotons#0];   //[photons#0_]
   Int_t           photons#0_collectionID[kMaxphotons#0];   //[photons#0_]
   Int_t           photons#1_;
   Int_t           photons#1_index[kMaxphotons#1];   //[photons#1_]
   Int_t           photons#1_collectionID[kMaxphotons#1];   //[photons#1_]
   vector<fcc::ParticleMCParticleAssociationData> *photonsToMC;
   Int_t           photonsToMC#0_;
   Int_t           photonsToMC#0_index[kMaxphotonsToMC#0];   //[photonsToMC#0_]
   Int_t           photonsToMC#0_collectionID[kMaxphotonsToMC#0];   //[photonsToMC#0_]
   Int_t           photonsToMC#1_;
   Int_t           photonsToMC#1_index[kMaxphotonsToMC#1];   //[photonsToMC#1_]
   Int_t           photonsToMC#1_collectionID[kMaxphotonsToMC#1];   //[photonsToMC#1_]
   Int_t           photonITags_;
   Float_t         photonITags_tag[kMaxphotonITags];   //[photonITags_]
   Int_t           photonITags#0_;
   Int_t           photonITags#0_index[kMaxphotonITags#0];   //[photonITags#0_]
   Int_t           photonITags#0_collectionID[kMaxphotonITags#0];   //[photonITags#0_]
   Int_t           pfcharged_;
   UInt_t          pfcharged_core_bits[kMaxpfcharged];   //[pfcharged_]
   Int_t           pfcharged_core_charge[kMaxpfcharged];   //[pfcharged_]
   Float_t         pfcharged_core_p4_mass[kMaxpfcharged];   //[pfcharged_]
   Float_t         pfcharged_core_p4_px[kMaxpfcharged];   //[pfcharged_]
   Float_t         pfcharged_core_p4_py[kMaxpfcharged];   //[pfcharged_]
   Float_t         pfcharged_core_p4_pz[kMaxpfcharged];   //[pfcharged_]
   Int_t           pfcharged_core_pdgId[kMaxpfcharged];   //[pfcharged_]
   UInt_t          pfcharged_core_status[kMaxpfcharged];   //[pfcharged_]
   Float_t         pfcharged_core_vertex_x[kMaxpfcharged];   //[pfcharged_]
   Float_t         pfcharged_core_vertex_y[kMaxpfcharged];   //[pfcharged_]
   Float_t         pfcharged_core_vertex_z[kMaxpfcharged];   //[pfcharged_]
   UInt_t          pfcharged_tracks_begin[kMaxpfcharged];   //[pfcharged_]
   UInt_t          pfcharged_tracks_end[kMaxpfcharged];   //[pfcharged_]
   UInt_t          pfcharged_clusters_begin[kMaxpfcharged];   //[pfcharged_]
   UInt_t          pfcharged_clusters_end[kMaxpfcharged];   //[pfcharged_]
   Int_t           pfcharged#0_;
   Int_t           pfcharged#0_index[kMaxpfcharged#0];   //[pfcharged#0_]
   Int_t           pfcharged#0_collectionID[kMaxpfcharged#0];   //[pfcharged#0_]
   Int_t           pfcharged#1_;
   Int_t           pfcharged#1_index[kMaxpfcharged#1];   //[pfcharged#1_]
   Int_t           pfcharged#1_collectionID[kMaxpfcharged#1];   //[pfcharged#1_]
   vector<fcc::ParticleMCParticleAssociationData> *chargedToMC;
   Int_t           chargedToMC#0_;
   Int_t           chargedToMC#0_index[kMaxchargedToMC#0];   //[chargedToMC#0_]
   Int_t           chargedToMC#0_collectionID[kMaxchargedToMC#0];   //[chargedToMC#0_]
   Int_t           chargedToMC#1_;
   Int_t           chargedToMC#1_index[kMaxchargedToMC#1];   //[chargedToMC#1_]
   Int_t           chargedToMC#1_collectionID[kMaxchargedToMC#1];   //[chargedToMC#1_]
   Int_t           pfphotons_;
   UInt_t          pfphotons_core_bits[kMaxpfphotons];   //[pfphotons_]
   Int_t           pfphotons_core_charge[kMaxpfphotons];   //[pfphotons_]
   Float_t         pfphotons_core_p4_mass[kMaxpfphotons];   //[pfphotons_]
   Float_t         pfphotons_core_p4_px[kMaxpfphotons];   //[pfphotons_]
   Float_t         pfphotons_core_p4_py[kMaxpfphotons];   //[pfphotons_]
   Float_t         pfphotons_core_p4_pz[kMaxpfphotons];   //[pfphotons_]
   Int_t           pfphotons_core_pdgId[kMaxpfphotons];   //[pfphotons_]
   UInt_t          pfphotons_core_status[kMaxpfphotons];   //[pfphotons_]
   Float_t         pfphotons_core_vertex_x[kMaxpfphotons];   //[pfphotons_]
   Float_t         pfphotons_core_vertex_y[kMaxpfphotons];   //[pfphotons_]
   Float_t         pfphotons_core_vertex_z[kMaxpfphotons];   //[pfphotons_]
   UInt_t          pfphotons_tracks_begin[kMaxpfphotons];   //[pfphotons_]
   UInt_t          pfphotons_tracks_end[kMaxpfphotons];   //[pfphotons_]
   UInt_t          pfphotons_clusters_begin[kMaxpfphotons];   //[pfphotons_]
   UInt_t          pfphotons_clusters_end[kMaxpfphotons];   //[pfphotons_]
   Int_t           pfphotons#0_;
   Int_t           pfphotons#0_index[kMaxpfphotons#0];   //[pfphotons#0_]
   Int_t           pfphotons#0_collectionID[kMaxpfphotons#0];   //[pfphotons#0_]
   Int_t           pfphotons#1_;
   Int_t           pfphotons#1_index[kMaxpfphotons#1];   //[pfphotons#1_]
   Int_t           pfphotons#1_collectionID[kMaxpfphotons#1];   //[pfphotons#1_]
   vector<fcc::ParticleMCParticleAssociationData> *pfphotonsToMC;
   Int_t           pfphotonsToMC#0_;
   Int_t           pfphotonsToMC#0_index[kMaxpfphotonsToMC#0];   //[pfphotonsToMC#0_]
   Int_t           pfphotonsToMC#0_collectionID[kMaxpfphotonsToMC#0];   //[pfphotonsToMC#0_]
   Int_t           pfphotonsToMC#1_;
   Int_t           pfphotonsToMC#1_index[kMaxpfphotonsToMC#1];   //[pfphotonsToMC#1_]
   Int_t           pfphotonsToMC#1_collectionID[kMaxpfphotonsToMC#1];   //[pfphotonsToMC#1_]
   Int_t           pfneutrals_;
   UInt_t          pfneutrals_core_bits[kMaxpfneutrals];   //[pfneutrals_]
   Int_t           pfneutrals_core_charge[kMaxpfneutrals];   //[pfneutrals_]
   Float_t         pfneutrals_core_p4_mass[kMaxpfneutrals];   //[pfneutrals_]
   Float_t         pfneutrals_core_p4_px[kMaxpfneutrals];   //[pfneutrals_]
   Float_t         pfneutrals_core_p4_py[kMaxpfneutrals];   //[pfneutrals_]
   Float_t         pfneutrals_core_p4_pz[kMaxpfneutrals];   //[pfneutrals_]
   Int_t           pfneutrals_core_pdgId[kMaxpfneutrals];   //[pfneutrals_]
   UInt_t          pfneutrals_core_status[kMaxpfneutrals];   //[pfneutrals_]
   Float_t         pfneutrals_core_vertex_x[kMaxpfneutrals];   //[pfneutrals_]
   Float_t         pfneutrals_core_vertex_y[kMaxpfneutrals];   //[pfneutrals_]
   Float_t         pfneutrals_core_vertex_z[kMaxpfneutrals];   //[pfneutrals_]
   UInt_t          pfneutrals_tracks_begin[kMaxpfneutrals];   //[pfneutrals_]
   UInt_t          pfneutrals_tracks_end[kMaxpfneutrals];   //[pfneutrals_]
   UInt_t          pfneutrals_clusters_begin[kMaxpfneutrals];   //[pfneutrals_]
   UInt_t          pfneutrals_clusters_end[kMaxpfneutrals];   //[pfneutrals_]
   Int_t           pfneutrals#0_;
   Int_t           pfneutrals#0_index[kMaxpfneutrals#0];   //[pfneutrals#0_]
   Int_t           pfneutrals#0_collectionID[kMaxpfneutrals#0];   //[pfneutrals#0_]
   Int_t           pfneutrals#1_;
   Int_t           pfneutrals#1_index[kMaxpfneutrals#1];   //[pfneutrals#1_]
   Int_t           pfneutrals#1_collectionID[kMaxpfneutrals#1];   //[pfneutrals#1_]
   vector<fcc::ParticleMCParticleAssociationData> *pfneutralsToMC;
   Int_t           pfneutralsToMC#0_;
   Int_t           pfneutralsToMC#0_index[kMaxpfneutralsToMC#0];   //[pfneutralsToMC#0_]
   Int_t           pfneutralsToMC#0_collectionID[kMaxpfneutralsToMC#0];   //[pfneutralsToMC#0_]
   Int_t           pfneutralsToMC#1_;
   Int_t           pfneutralsToMC#1_index[kMaxpfneutralsToMC#1];   //[pfneutralsToMC#1_]
   Int_t           pfneutralsToMC#1_collectionID[kMaxpfneutralsToMC#1];   //[pfneutralsToMC#1_]
   Int_t           genjets02_;
   Float_t         genjets02_core_area[kMaxgenjets02];   //[genjets02_]
   UInt_t          genjets02_core_bits[kMaxgenjets02];   //[genjets02_]
   Float_t         genjets02_core_p4_mass[kMaxgenjets02];   //[genjets02_]
   Float_t         genjets02_core_p4_px[kMaxgenjets02];   //[genjets02_]
   Float_t         genjets02_core_p4_py[kMaxgenjets02];   //[genjets02_]
   Float_t         genjets02_core_p4_pz[kMaxgenjets02];   //[genjets02_]
   UInt_t          genjets02_particles_begin[kMaxgenjets02];   //[genjets02_]
   UInt_t          genjets02_particles_end[kMaxgenjets02];   //[genjets02_]
   Int_t           genjets02#0_;
   Int_t           genjets02#0_index[kMaxgenjets02#0];   //[genjets02#0_]
   Int_t           genjets02#0_collectionID[kMaxgenjets02#0];   //[genjets02#0_]
   Int_t           genjetsFlavor02_;
   Float_t         genjetsFlavor02_tag[kMaxgenjetsFlavor02];   //[genjetsFlavor02_]
   Int_t           genjetsFlavor02#0_;
   Int_t           genjetsFlavor02#0_index[kMaxgenjetsFlavor02#0];   //[genjetsFlavor02#0_]
   Int_t           genjetsFlavor02#0_collectionID[kMaxgenjetsFlavor02#0];   //[genjetsFlavor02#0_]
   Int_t           genjets04_;
   Float_t         genjets04_core_area[kMaxgenjets04];   //[genjets04_]
   UInt_t          genjets04_core_bits[kMaxgenjets04];   //[genjets04_]
   Float_t         genjets04_core_p4_mass[kMaxgenjets04];   //[genjets04_]
   Float_t         genjets04_core_p4_px[kMaxgenjets04];   //[genjets04_]
   Float_t         genjets04_core_p4_py[kMaxgenjets04];   //[genjets04_]
   Float_t         genjets04_core_p4_pz[kMaxgenjets04];   //[genjets04_]
   UInt_t          genjets04_particles_begin[kMaxgenjets04];   //[genjets04_]
   UInt_t          genjets04_particles_end[kMaxgenjets04];   //[genjets04_]
   Int_t           genjets04#0_;
   Int_t           genjets04#0_index[kMaxgenjets04#0];   //[genjets04#0_]
   Int_t           genjets04#0_collectionID[kMaxgenjets04#0];   //[genjets04#0_]
   Int_t           genjetsFlavor04_;
   Float_t         genjetsFlavor04_tag[kMaxgenjetsFlavor04];   //[genjetsFlavor04_]
   Int_t           genjetsFlavor04#0_;
   Int_t           genjetsFlavor04#0_index[kMaxgenjetsFlavor04#0];   //[genjetsFlavor04#0_]
   Int_t           genjetsFlavor04#0_collectionID[kMaxgenjetsFlavor04#0];   //[genjetsFlavor04#0_]
   Int_t           genjets08_;
   Float_t         genjets08_core_area[kMaxgenjets08];   //[genjets08_]
   UInt_t          genjets08_core_bits[kMaxgenjets08];   //[genjets08_]
   Float_t         genjets08_core_p4_mass[kMaxgenjets08];   //[genjets08_]
   Float_t         genjets08_core_p4_px[kMaxgenjets08];   //[genjets08_]
   Float_t         genjets08_core_p4_py[kMaxgenjets08];   //[genjets08_]
   Float_t         genjets08_core_p4_pz[kMaxgenjets08];   //[genjets08_]
   UInt_t          genjets08_particles_begin[kMaxgenjets08];   //[genjets08_]
   UInt_t          genjets08_particles_end[kMaxgenjets08];   //[genjets08_]
   Int_t           genjets08#0_;
   Int_t           genjets08#0_index[kMaxgenjets08#0];   //[genjets08#0_]
   Int_t           genjets08#0_collectionID[kMaxgenjets08#0];   //[genjets08#0_]
   Int_t           genjetsFlavor08_;
   Float_t         genjetsFlavor08_tag[kMaxgenjetsFlavor08];   //[genjetsFlavor08_]
   Int_t           genjetsFlavor08#0_;
   Int_t           genjetsFlavor08#0_index[kMaxgenjetsFlavor08#0];   //[genjetsFlavor08#0_]
   Int_t           genjetsFlavor08#0_collectionID[kMaxgenjetsFlavor08#0];   //[genjetsFlavor08#0_]
   Int_t           genjets15_;
   Float_t         genjets15_core_area[kMaxgenjets15];   //[genjets15_]
   UInt_t          genjets15_core_bits[kMaxgenjets15];   //[genjets15_]
   Float_t         genjets15_core_p4_mass[kMaxgenjets15];   //[genjets15_]
   Float_t         genjets15_core_p4_px[kMaxgenjets15];   //[genjets15_]
   Float_t         genjets15_core_p4_py[kMaxgenjets15];   //[genjets15_]
   Float_t         genjets15_core_p4_pz[kMaxgenjets15];   //[genjets15_]
   UInt_t          genjets15_particles_begin[kMaxgenjets15];   //[genjets15_]
   UInt_t          genjets15_particles_end[kMaxgenjets15];   //[genjets15_]
   Int_t           genjets15#0_;
   Int_t           genjets15#0_index[kMaxgenjets15#0];   //[genjets15#0_]
   Int_t           genjets15#0_collectionID[kMaxgenjets15#0];   //[genjets15#0_]
   Int_t           genjetsFlavor15_;
   Float_t         genjetsFlavor15_tag[kMaxgenjetsFlavor15];   //[genjetsFlavor15_]
   Int_t           genjetsFlavor15#0_;
   Int_t           genjetsFlavor15#0_index[kMaxgenjetsFlavor15#0];   //[genjetsFlavor15#0_]
   Int_t           genjetsFlavor15#0_collectionID[kMaxgenjetsFlavor15#0];   //[genjetsFlavor15#0_]
   Int_t           calojets02_;
   Float_t         calojets02_core_area[kMaxcalojets02];   //[calojets02_]
   UInt_t          calojets02_core_bits[kMaxcalojets02];   //[calojets02_]
   Float_t         calojets02_core_p4_mass[kMaxcalojets02];   //[calojets02_]
   Float_t         calojets02_core_p4_px[kMaxcalojets02];   //[calojets02_]
   Float_t         calojets02_core_p4_py[kMaxcalojets02];   //[calojets02_]
   Float_t         calojets02_core_p4_pz[kMaxcalojets02];   //[calojets02_]
   UInt_t          calojets02_particles_begin[kMaxcalojets02];   //[calojets02_]
   UInt_t          calojets02_particles_end[kMaxcalojets02];   //[calojets02_]
   Int_t           calojets02#0_;
   Int_t           calojets02#0_index[kMaxcalojets02#0];   //[calojets02#0_]
   Int_t           calojets02#0_collectionID[kMaxcalojets02#0];   //[calojets02#0_]
   Int_t           calojetsFlavor02_;
   Float_t         calojetsFlavor02_tag[kMaxcalojetsFlavor02];   //[calojetsFlavor02_]
   Int_t           calojetsFlavor02#0_;
   Int_t           calojetsFlavor02#0_index[kMaxcalojetsFlavor02#0];   //[calojetsFlavor02#0_]
   Int_t           calojetsFlavor02#0_collectionID[kMaxcalojetsFlavor02#0];   //[calojetsFlavor02#0_]
   Int_t           calobTags02_;
   Float_t         calobTags02_tag[kMaxcalobTags02];   //[calobTags02_]
   Int_t           calobTags02#0_;
   Int_t           calobTags02#0_index[kMaxcalobTags02#0];   //[calobTags02#0_]
   Int_t           calobTags02#0_collectionID[kMaxcalobTags02#0];   //[calobTags02#0_]
   Int_t           calocTags02_;
   Float_t         calocTags02_tag[kMaxcalocTags02];   //[calocTags02_]
   Int_t           calocTags02#0_;
   Int_t           calocTags02#0_index[kMaxcalocTags02#0];   //[calocTags02#0_]
   Int_t           calocTags02#0_collectionID[kMaxcalocTags02#0];   //[calocTags02#0_]
   Int_t           calotauTags02_;
   Float_t         calotauTags02_tag[kMaxcalotauTags02];   //[calotauTags02_]
   Int_t           calotauTags02#0_;
   Int_t           calotauTags02#0_index[kMaxcalotauTags02#0];   //[calotauTags02#0_]
   Int_t           calotauTags02#0_collectionID[kMaxcalotauTags02#0];   //[calotauTags02#0_]
   Int_t           calojetParts02_;
   UInt_t          calojetParts02_core_bits[kMaxcalojetParts02];   //[calojetParts02_]
   Int_t           calojetParts02_core_charge[kMaxcalojetParts02];   //[calojetParts02_]
   Float_t         calojetParts02_core_p4_mass[kMaxcalojetParts02];   //[calojetParts02_]
   Float_t         calojetParts02_core_p4_px[kMaxcalojetParts02];   //[calojetParts02_]
   Float_t         calojetParts02_core_p4_py[kMaxcalojetParts02];   //[calojetParts02_]
   Float_t         calojetParts02_core_p4_pz[kMaxcalojetParts02];   //[calojetParts02_]
   Int_t           calojetParts02_core_pdgId[kMaxcalojetParts02];   //[calojetParts02_]
   UInt_t          calojetParts02_core_status[kMaxcalojetParts02];   //[calojetParts02_]
   Float_t         calojetParts02_core_vertex_x[kMaxcalojetParts02];   //[calojetParts02_]
   Float_t         calojetParts02_core_vertex_y[kMaxcalojetParts02];   //[calojetParts02_]
   Float_t         calojetParts02_core_vertex_z[kMaxcalojetParts02];   //[calojetParts02_]
   UInt_t          calojetParts02_tracks_begin[kMaxcalojetParts02];   //[calojetParts02_]
   UInt_t          calojetParts02_tracks_end[kMaxcalojetParts02];   //[calojetParts02_]
   UInt_t          calojetParts02_clusters_begin[kMaxcalojetParts02];   //[calojetParts02_]
   UInt_t          calojetParts02_clusters_end[kMaxcalojetParts02];   //[calojetParts02_]
   Int_t           calojetParts02#0_;
   Int_t           calojetParts02#0_index[kMaxcalojetParts02#0];   //[calojetParts02#0_]
   Int_t           calojetParts02#0_collectionID[kMaxcalojetParts02#0];   //[calojetParts02#0_]
   Int_t           calojetParts02#1_;
   Int_t           calojetParts02#1_index[kMaxcalojetParts02#1];   //[calojetParts02#1_]
   Int_t           calojetParts02#1_collectionID[kMaxcalojetParts02#1];   //[calojetParts02#1_]
   Int_t           calojetsOneSubJettiness02_;
   Float_t         calojetsOneSubJettiness02_tag[kMaxcalojetsOneSubJettiness02];   //[calojetsOneSubJettiness02_]
   Int_t           calojetsOneSubJettiness02#0_;
   Int_t           calojetsOneSubJettiness02#0_index[kMaxcalojetsOneSubJettiness02#0];   //[calojetsOneSubJettiness02#0_]
   Int_t           calojetsOneSubJettiness02#0_collectionID[kMaxcalojetsOneSubJettiness02#0];   //[calojetsOneSubJettiness02#0_]
   Int_t           calojetsTwoSubJettiness02_;
   Float_t         calojetsTwoSubJettiness02_tag[kMaxcalojetsTwoSubJettiness02];   //[calojetsTwoSubJettiness02_]
   Int_t           calojetsTwoSubJettiness02#0_;
   Int_t           calojetsTwoSubJettiness02#0_index[kMaxcalojetsTwoSubJettiness02#0];   //[calojetsTwoSubJettiness02#0_]
   Int_t           calojetsTwoSubJettiness02#0_collectionID[kMaxcalojetsTwoSubJettiness02#0];   //[calojetsTwoSubJettiness02#0_]
   Int_t           calojetsThreeSubJettiness02_;
   Float_t         calojetsThreeSubJettiness02_tag[kMaxcalojetsThreeSubJettiness02];   //[calojetsThreeSubJettiness02_]
   Int_t           calojetsThreeSubJettiness02#0_;
   Int_t           calojetsThreeSubJettiness02#0_index[kMaxcalojetsThreeSubJettiness02#0];   //[calojetsThreeSubJettiness02#0_]
   Int_t           calojetsThreeSubJettiness02#0_collectionID[kMaxcalojetsThreeSubJettiness02#0];   //[calojetsThreeSubJettiness02#0_]
   Int_t           calosubjetsTrimmingTagged02_;
   UInt_t          calosubjetsTrimmingTagged02_subjets_begin[kMaxcalosubjetsTrimmingTagged02];   //[calosubjetsTrimmingTagged02_]
   UInt_t          calosubjetsTrimmingTagged02_subjets_end[kMaxcalosubjetsTrimmingTagged02];   //[calosubjetsTrimmingTagged02_]
   Int_t           calosubjetsTrimmingTagged02#0_;
   Int_t           calosubjetsTrimmingTagged02#0_index[kMaxcalosubjetsTrimmingTagged02#0];   //[calosubjetsTrimmingTagged02#0_]
   Int_t           calosubjetsTrimmingTagged02#0_collectionID[kMaxcalosubjetsTrimmingTagged02#0];   //[calosubjetsTrimmingTagged02#0_]
   Int_t           calosubjetsTrimmingTagged02#1_;
   Int_t           calosubjetsTrimmingTagged02#1_index[kMaxcalosubjetsTrimmingTagged02#1];   //[calosubjetsTrimmingTagged02#1_]
   Int_t           calosubjetsTrimmingTagged02#1_collectionID[kMaxcalosubjetsTrimmingTagged02#1];   //[calosubjetsTrimmingTagged02#1_]
   Int_t           calosubjetsPruningTagged02_;
   UInt_t          calosubjetsPruningTagged02_subjets_begin[kMaxcalosubjetsPruningTagged02];   //[calosubjetsPruningTagged02_]
   UInt_t          calosubjetsPruningTagged02_subjets_end[kMaxcalosubjetsPruningTagged02];   //[calosubjetsPruningTagged02_]
   Int_t           calosubjetsPruningTagged02#0_;
   Int_t           calosubjetsPruningTagged02#0_index[kMaxcalosubjetsPruningTagged02#0];   //[calosubjetsPruningTagged02#0_]
   Int_t           calosubjetsPruningTagged02#0_collectionID[kMaxcalosubjetsPruningTagged02#0];   //[calosubjetsPruningTagged02#0_]
   Int_t           calosubjetsPruningTagged02#1_;
   Int_t           calosubjetsPruningTagged02#1_index[kMaxcalosubjetsPruningTagged02#1];   //[calosubjetsPruningTagged02#1_]
   Int_t           calosubjetsPruningTagged02#1_collectionID[kMaxcalosubjetsPruningTagged02#1];   //[calosubjetsPruningTagged02#1_]
   Int_t           calosubjetsSoftDropTagged02_;
   UInt_t          calosubjetsSoftDropTagged02_subjets_begin[kMaxcalosubjetsSoftDropTagged02];   //[calosubjetsSoftDropTagged02_]
   UInt_t          calosubjetsSoftDropTagged02_subjets_end[kMaxcalosubjetsSoftDropTagged02];   //[calosubjetsSoftDropTagged02_]
   Int_t           calosubjetsSoftDropTagged02#0_;
   Int_t           calosubjetsSoftDropTagged02#0_index[kMaxcalosubjetsSoftDropTagged02#0];   //[calosubjetsSoftDropTagged02#0_]
   Int_t           calosubjetsSoftDropTagged02#0_collectionID[kMaxcalosubjetsSoftDropTagged02#0];   //[calosubjetsSoftDropTagged02#0_]
   Int_t           calosubjetsSoftDropTagged02#1_;
   Int_t           calosubjetsSoftDropTagged02#1_index[kMaxcalosubjetsSoftDropTagged02#1];   //[calosubjetsSoftDropTagged02#1_]
   Int_t           calosubjetsSoftDropTagged02#1_collectionID[kMaxcalosubjetsSoftDropTagged02#1];   //[calosubjetsSoftDropTagged02#1_]
   Int_t           calosubjetsTrimming02_;
   Float_t         calosubjetsTrimming02_core_area[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   UInt_t          calosubjetsTrimming02_core_bits[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   Float_t         calosubjetsTrimming02_core_p4_mass[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   Float_t         calosubjetsTrimming02_core_p4_px[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   Float_t         calosubjetsTrimming02_core_p4_py[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   Float_t         calosubjetsTrimming02_core_p4_pz[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   UInt_t          calosubjetsTrimming02_particles_begin[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   UInt_t          calosubjetsTrimming02_particles_end[kMaxcalosubjetsTrimming02];   //[calosubjetsTrimming02_]
   Int_t           calosubjetsTrimming02#0_;
   Int_t           calosubjetsTrimming02#0_index[kMaxcalosubjetsTrimming02#0];   //[calosubjetsTrimming02#0_]
   Int_t           calosubjetsTrimming02#0_collectionID[kMaxcalosubjetsTrimming02#0];   //[calosubjetsTrimming02#0_]
   Int_t           calosubjetsPruning02_;
   Float_t         calosubjetsPruning02_core_area[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   UInt_t          calosubjetsPruning02_core_bits[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   Float_t         calosubjetsPruning02_core_p4_mass[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   Float_t         calosubjetsPruning02_core_p4_px[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   Float_t         calosubjetsPruning02_core_p4_py[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   Float_t         calosubjetsPruning02_core_p4_pz[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   UInt_t          calosubjetsPruning02_particles_begin[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   UInt_t          calosubjetsPruning02_particles_end[kMaxcalosubjetsPruning02];   //[calosubjetsPruning02_]
   Int_t           calosubjetsPruning02#0_;
   Int_t           calosubjetsPruning02#0_index[kMaxcalosubjetsPruning02#0];   //[calosubjetsPruning02#0_]
   Int_t           calosubjetsPruning02#0_collectionID[kMaxcalosubjetsPruning02#0];   //[calosubjetsPruning02#0_]
   Int_t           calosubjetsSoftDrop02_;
   Float_t         calosubjetsSoftDrop02_core_area[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   UInt_t          calosubjetsSoftDrop02_core_bits[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   Float_t         calosubjetsSoftDrop02_core_p4_mass[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   Float_t         calosubjetsSoftDrop02_core_p4_px[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   Float_t         calosubjetsSoftDrop02_core_p4_py[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   Float_t         calosubjetsSoftDrop02_core_p4_pz[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   UInt_t          calosubjetsSoftDrop02_particles_begin[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   UInt_t          calosubjetsSoftDrop02_particles_end[kMaxcalosubjetsSoftDrop02];   //[calosubjetsSoftDrop02_]
   Int_t           calosubjetsSoftDrop02#0_;
   Int_t           calosubjetsSoftDrop02#0_index[kMaxcalosubjetsSoftDrop02#0];   //[calosubjetsSoftDrop02#0_]
   Int_t           calosubjetsSoftDrop02#0_collectionID[kMaxcalosubjetsSoftDrop02#0];   //[calosubjetsSoftDrop02#0_]
   Int_t           calojets04_;
   Float_t         calojets04_core_area[kMaxcalojets04];   //[calojets04_]
   UInt_t          calojets04_core_bits[kMaxcalojets04];   //[calojets04_]
   Float_t         calojets04_core_p4_mass[kMaxcalojets04];   //[calojets04_]
   Float_t         calojets04_core_p4_px[kMaxcalojets04];   //[calojets04_]
   Float_t         calojets04_core_p4_py[kMaxcalojets04];   //[calojets04_]
   Float_t         calojets04_core_p4_pz[kMaxcalojets04];   //[calojets04_]
   UInt_t          calojets04_particles_begin[kMaxcalojets04];   //[calojets04_]
   UInt_t          calojets04_particles_end[kMaxcalojets04];   //[calojets04_]
   Int_t           calojets04#0_;
   Int_t           calojets04#0_index[kMaxcalojets04#0];   //[calojets04#0_]
   Int_t           calojets04#0_collectionID[kMaxcalojets04#0];   //[calojets04#0_]
   Int_t           calojetsFlavor04_;
   Float_t         calojetsFlavor04_tag[kMaxcalojetsFlavor04];   //[calojetsFlavor04_]
   Int_t           calojetsFlavor04#0_;
   Int_t           calojetsFlavor04#0_index[kMaxcalojetsFlavor04#0];   //[calojetsFlavor04#0_]
   Int_t           calojetsFlavor04#0_collectionID[kMaxcalojetsFlavor04#0];   //[calojetsFlavor04#0_]
   Int_t           calobTags04_;
   Float_t         calobTags04_tag[kMaxcalobTags04];   //[calobTags04_]
   Int_t           calobTags04#0_;
   Int_t           calobTags04#0_index[kMaxcalobTags04#0];   //[calobTags04#0_]
   Int_t           calobTags04#0_collectionID[kMaxcalobTags04#0];   //[calobTags04#0_]
   Int_t           calocTags04_;
   Float_t         calocTags04_tag[kMaxcalocTags04];   //[calocTags04_]
   Int_t           calocTags04#0_;
   Int_t           calocTags04#0_index[kMaxcalocTags04#0];   //[calocTags04#0_]
   Int_t           calocTags04#0_collectionID[kMaxcalocTags04#0];   //[calocTags04#0_]
   Int_t           calotauTags04_;
   Float_t         calotauTags04_tag[kMaxcalotauTags04];   //[calotauTags04_]
   Int_t           calotauTags04#0_;
   Int_t           calotauTags04#0_index[kMaxcalotauTags04#0];   //[calotauTags04#0_]
   Int_t           calotauTags04#0_collectionID[kMaxcalotauTags04#0];   //[calotauTags04#0_]
   Int_t           calojetParts04_;
   UInt_t          calojetParts04_core_bits[kMaxcalojetParts04];   //[calojetParts04_]
   Int_t           calojetParts04_core_charge[kMaxcalojetParts04];   //[calojetParts04_]
   Float_t         calojetParts04_core_p4_mass[kMaxcalojetParts04];   //[calojetParts04_]
   Float_t         calojetParts04_core_p4_px[kMaxcalojetParts04];   //[calojetParts04_]
   Float_t         calojetParts04_core_p4_py[kMaxcalojetParts04];   //[calojetParts04_]
   Float_t         calojetParts04_core_p4_pz[kMaxcalojetParts04];   //[calojetParts04_]
   Int_t           calojetParts04_core_pdgId[kMaxcalojetParts04];   //[calojetParts04_]
   UInt_t          calojetParts04_core_status[kMaxcalojetParts04];   //[calojetParts04_]
   Float_t         calojetParts04_core_vertex_x[kMaxcalojetParts04];   //[calojetParts04_]
   Float_t         calojetParts04_core_vertex_y[kMaxcalojetParts04];   //[calojetParts04_]
   Float_t         calojetParts04_core_vertex_z[kMaxcalojetParts04];   //[calojetParts04_]
   UInt_t          calojetParts04_tracks_begin[kMaxcalojetParts04];   //[calojetParts04_]
   UInt_t          calojetParts04_tracks_end[kMaxcalojetParts04];   //[calojetParts04_]
   UInt_t          calojetParts04_clusters_begin[kMaxcalojetParts04];   //[calojetParts04_]
   UInt_t          calojetParts04_clusters_end[kMaxcalojetParts04];   //[calojetParts04_]
   Int_t           calojetParts04#0_;
   Int_t           calojetParts04#0_index[kMaxcalojetParts04#0];   //[calojetParts04#0_]
   Int_t           calojetParts04#0_collectionID[kMaxcalojetParts04#0];   //[calojetParts04#0_]
   Int_t           calojetParts04#1_;
   Int_t           calojetParts04#1_index[kMaxcalojetParts04#1];   //[calojetParts04#1_]
   Int_t           calojetParts04#1_collectionID[kMaxcalojetParts04#1];   //[calojetParts04#1_]
   Int_t           calojetsOneSubJettiness04_;
   Float_t         calojetsOneSubJettiness04_tag[kMaxcalojetsOneSubJettiness04];   //[calojetsOneSubJettiness04_]
   Int_t           calojetsOneSubJettiness04#0_;
   Int_t           calojetsOneSubJettiness04#0_index[kMaxcalojetsOneSubJettiness04#0];   //[calojetsOneSubJettiness04#0_]
   Int_t           calojetsOneSubJettiness04#0_collectionID[kMaxcalojetsOneSubJettiness04#0];   //[calojetsOneSubJettiness04#0_]
   Int_t           calojetsTwoSubJettiness04_;
   Float_t         calojetsTwoSubJettiness04_tag[kMaxcalojetsTwoSubJettiness04];   //[calojetsTwoSubJettiness04_]
   Int_t           calojetsTwoSubJettiness04#0_;
   Int_t           calojetsTwoSubJettiness04#0_index[kMaxcalojetsTwoSubJettiness04#0];   //[calojetsTwoSubJettiness04#0_]
   Int_t           calojetsTwoSubJettiness04#0_collectionID[kMaxcalojetsTwoSubJettiness04#0];   //[calojetsTwoSubJettiness04#0_]
   Int_t           calojetsThreeSubJettiness04_;
   Float_t         calojetsThreeSubJettiness04_tag[kMaxcalojetsThreeSubJettiness04];   //[calojetsThreeSubJettiness04_]
   Int_t           calojetsThreeSubJettiness04#0_;
   Int_t           calojetsThreeSubJettiness04#0_index[kMaxcalojetsThreeSubJettiness04#0];   //[calojetsThreeSubJettiness04#0_]
   Int_t           calojetsThreeSubJettiness04#0_collectionID[kMaxcalojetsThreeSubJettiness04#0];   //[calojetsThreeSubJettiness04#0_]
   Int_t           calosubjetsTrimmingTagged04_;
   UInt_t          calosubjetsTrimmingTagged04_subjets_begin[kMaxcalosubjetsTrimmingTagged04];   //[calosubjetsTrimmingTagged04_]
   UInt_t          calosubjetsTrimmingTagged04_subjets_end[kMaxcalosubjetsTrimmingTagged04];   //[calosubjetsTrimmingTagged04_]
   Int_t           calosubjetsTrimmingTagged04#0_;
   Int_t           calosubjetsTrimmingTagged04#0_index[kMaxcalosubjetsTrimmingTagged04#0];   //[calosubjetsTrimmingTagged04#0_]
   Int_t           calosubjetsTrimmingTagged04#0_collectionID[kMaxcalosubjetsTrimmingTagged04#0];   //[calosubjetsTrimmingTagged04#0_]
   Int_t           calosubjetsTrimmingTagged04#1_;
   Int_t           calosubjetsTrimmingTagged04#1_index[kMaxcalosubjetsTrimmingTagged04#1];   //[calosubjetsTrimmingTagged04#1_]
   Int_t           calosubjetsTrimmingTagged04#1_collectionID[kMaxcalosubjetsTrimmingTagged04#1];   //[calosubjetsTrimmingTagged04#1_]
   Int_t           calosubjetsPruningTagged04_;
   UInt_t          calosubjetsPruningTagged04_subjets_begin[kMaxcalosubjetsPruningTagged04];   //[calosubjetsPruningTagged04_]
   UInt_t          calosubjetsPruningTagged04_subjets_end[kMaxcalosubjetsPruningTagged04];   //[calosubjetsPruningTagged04_]
   Int_t           calosubjetsPruningTagged04#0_;
   Int_t           calosubjetsPruningTagged04#0_index[kMaxcalosubjetsPruningTagged04#0];   //[calosubjetsPruningTagged04#0_]
   Int_t           calosubjetsPruningTagged04#0_collectionID[kMaxcalosubjetsPruningTagged04#0];   //[calosubjetsPruningTagged04#0_]
   Int_t           calosubjetsPruningTagged04#1_;
   Int_t           calosubjetsPruningTagged04#1_index[kMaxcalosubjetsPruningTagged04#1];   //[calosubjetsPruningTagged04#1_]
   Int_t           calosubjetsPruningTagged04#1_collectionID[kMaxcalosubjetsPruningTagged04#1];   //[calosubjetsPruningTagged04#1_]
   Int_t           calosubjetsSoftDropTagged04_;
   UInt_t          calosubjetsSoftDropTagged04_subjets_begin[kMaxcalosubjetsSoftDropTagged04];   //[calosubjetsSoftDropTagged04_]
   UInt_t          calosubjetsSoftDropTagged04_subjets_end[kMaxcalosubjetsSoftDropTagged04];   //[calosubjetsSoftDropTagged04_]
   Int_t           calosubjetsSoftDropTagged04#0_;
   Int_t           calosubjetsSoftDropTagged04#0_index[kMaxcalosubjetsSoftDropTagged04#0];   //[calosubjetsSoftDropTagged04#0_]
   Int_t           calosubjetsSoftDropTagged04#0_collectionID[kMaxcalosubjetsSoftDropTagged04#0];   //[calosubjetsSoftDropTagged04#0_]
   Int_t           calosubjetsSoftDropTagged04#1_;
   Int_t           calosubjetsSoftDropTagged04#1_index[kMaxcalosubjetsSoftDropTagged04#1];   //[calosubjetsSoftDropTagged04#1_]
   Int_t           calosubjetsSoftDropTagged04#1_collectionID[kMaxcalosubjetsSoftDropTagged04#1];   //[calosubjetsSoftDropTagged04#1_]
   Int_t           calosubjetsTrimming04_;
   Float_t         calosubjetsTrimming04_core_area[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   UInt_t          calosubjetsTrimming04_core_bits[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   Float_t         calosubjetsTrimming04_core_p4_mass[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   Float_t         calosubjetsTrimming04_core_p4_px[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   Float_t         calosubjetsTrimming04_core_p4_py[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   Float_t         calosubjetsTrimming04_core_p4_pz[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   UInt_t          calosubjetsTrimming04_particles_begin[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   UInt_t          calosubjetsTrimming04_particles_end[kMaxcalosubjetsTrimming04];   //[calosubjetsTrimming04_]
   Int_t           calosubjetsTrimming04#0_;
   Int_t           calosubjetsTrimming04#0_index[kMaxcalosubjetsTrimming04#0];   //[calosubjetsTrimming04#0_]
   Int_t           calosubjetsTrimming04#0_collectionID[kMaxcalosubjetsTrimming04#0];   //[calosubjetsTrimming04#0_]
   Int_t           calosubjetsPruning04_;
   Float_t         calosubjetsPruning04_core_area[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   UInt_t          calosubjetsPruning04_core_bits[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   Float_t         calosubjetsPruning04_core_p4_mass[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   Float_t         calosubjetsPruning04_core_p4_px[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   Float_t         calosubjetsPruning04_core_p4_py[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   Float_t         calosubjetsPruning04_core_p4_pz[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   UInt_t          calosubjetsPruning04_particles_begin[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   UInt_t          calosubjetsPruning04_particles_end[kMaxcalosubjetsPruning04];   //[calosubjetsPruning04_]
   Int_t           calosubjetsPruning04#0_;
   Int_t           calosubjetsPruning04#0_index[kMaxcalosubjetsPruning04#0];   //[calosubjetsPruning04#0_]
   Int_t           calosubjetsPruning04#0_collectionID[kMaxcalosubjetsPruning04#0];   //[calosubjetsPruning04#0_]
   Int_t           calosubjetsSoftDrop04_;
   Float_t         calosubjetsSoftDrop04_core_area[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   UInt_t          calosubjetsSoftDrop04_core_bits[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   Float_t         calosubjetsSoftDrop04_core_p4_mass[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   Float_t         calosubjetsSoftDrop04_core_p4_px[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   Float_t         calosubjetsSoftDrop04_core_p4_py[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   Float_t         calosubjetsSoftDrop04_core_p4_pz[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   UInt_t          calosubjetsSoftDrop04_particles_begin[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   UInt_t          calosubjetsSoftDrop04_particles_end[kMaxcalosubjetsSoftDrop04];   //[calosubjetsSoftDrop04_]
   Int_t           calosubjetsSoftDrop04#0_;
   Int_t           calosubjetsSoftDrop04#0_index[kMaxcalosubjetsSoftDrop04#0];   //[calosubjetsSoftDrop04#0_]
   Int_t           calosubjetsSoftDrop04#0_collectionID[kMaxcalosubjetsSoftDrop04#0];   //[calosubjetsSoftDrop04#0_]
   Int_t           calojets08_;
   Float_t         calojets08_core_area[kMaxcalojets08];   //[calojets08_]
   UInt_t          calojets08_core_bits[kMaxcalojets08];   //[calojets08_]
   Float_t         calojets08_core_p4_mass[kMaxcalojets08];   //[calojets08_]
   Float_t         calojets08_core_p4_px[kMaxcalojets08];   //[calojets08_]
   Float_t         calojets08_core_p4_py[kMaxcalojets08];   //[calojets08_]
   Float_t         calojets08_core_p4_pz[kMaxcalojets08];   //[calojets08_]
   UInt_t          calojets08_particles_begin[kMaxcalojets08];   //[calojets08_]
   UInt_t          calojets08_particles_end[kMaxcalojets08];   //[calojets08_]
   Int_t           calojets08#0_;
   Int_t           calojets08#0_index[kMaxcalojets08#0];   //[calojets08#0_]
   Int_t           calojets08#0_collectionID[kMaxcalojets08#0];   //[calojets08#0_]
   Int_t           calojetsFlavor08_;
   Float_t         calojetsFlavor08_tag[kMaxcalojetsFlavor08];   //[calojetsFlavor08_]
   Int_t           calojetsFlavor08#0_;
   Int_t           calojetsFlavor08#0_index[kMaxcalojetsFlavor08#0];   //[calojetsFlavor08#0_]
   Int_t           calojetsFlavor08#0_collectionID[kMaxcalojetsFlavor08#0];   //[calojetsFlavor08#0_]
   Int_t           calobTags08_;
   Float_t         calobTags08_tag[kMaxcalobTags08];   //[calobTags08_]
   Int_t           calobTags08#0_;
   Int_t           calobTags08#0_index[kMaxcalobTags08#0];   //[calobTags08#0_]
   Int_t           calobTags08#0_collectionID[kMaxcalobTags08#0];   //[calobTags08#0_]
   Int_t           calocTags08_;
   Float_t         calocTags08_tag[kMaxcalocTags08];   //[calocTags08_]
   Int_t           calocTags08#0_;
   Int_t           calocTags08#0_index[kMaxcalocTags08#0];   //[calocTags08#0_]
   Int_t           calocTags08#0_collectionID[kMaxcalocTags08#0];   //[calocTags08#0_]
   Int_t           calotauTags08_;
   Float_t         calotauTags08_tag[kMaxcalotauTags08];   //[calotauTags08_]
   Int_t           calotauTags08#0_;
   Int_t           calotauTags08#0_index[kMaxcalotauTags08#0];   //[calotauTags08#0_]
   Int_t           calotauTags08#0_collectionID[kMaxcalotauTags08#0];   //[calotauTags08#0_]
   Int_t           calojetParts08_;
   UInt_t          calojetParts08_core_bits[kMaxcalojetParts08];   //[calojetParts08_]
   Int_t           calojetParts08_core_charge[kMaxcalojetParts08];   //[calojetParts08_]
   Float_t         calojetParts08_core_p4_mass[kMaxcalojetParts08];   //[calojetParts08_]
   Float_t         calojetParts08_core_p4_px[kMaxcalojetParts08];   //[calojetParts08_]
   Float_t         calojetParts08_core_p4_py[kMaxcalojetParts08];   //[calojetParts08_]
   Float_t         calojetParts08_core_p4_pz[kMaxcalojetParts08];   //[calojetParts08_]
   Int_t           calojetParts08_core_pdgId[kMaxcalojetParts08];   //[calojetParts08_]
   UInt_t          calojetParts08_core_status[kMaxcalojetParts08];   //[calojetParts08_]
   Float_t         calojetParts08_core_vertex_x[kMaxcalojetParts08];   //[calojetParts08_]
   Float_t         calojetParts08_core_vertex_y[kMaxcalojetParts08];   //[calojetParts08_]
   Float_t         calojetParts08_core_vertex_z[kMaxcalojetParts08];   //[calojetParts08_]
   UInt_t          calojetParts08_tracks_begin[kMaxcalojetParts08];   //[calojetParts08_]
   UInt_t          calojetParts08_tracks_end[kMaxcalojetParts08];   //[calojetParts08_]
   UInt_t          calojetParts08_clusters_begin[kMaxcalojetParts08];   //[calojetParts08_]
   UInt_t          calojetParts08_clusters_end[kMaxcalojetParts08];   //[calojetParts08_]
   Int_t           calojetParts08#0_;
   Int_t           calojetParts08#0_index[kMaxcalojetParts08#0];   //[calojetParts08#0_]
   Int_t           calojetParts08#0_collectionID[kMaxcalojetParts08#0];   //[calojetParts08#0_]
   Int_t           calojetParts08#1_;
   Int_t           calojetParts08#1_index[kMaxcalojetParts08#1];   //[calojetParts08#1_]
   Int_t           calojetParts08#1_collectionID[kMaxcalojetParts08#1];   //[calojetParts08#1_]
   Int_t           calojetsOneSubJettiness08_;
   Float_t         calojetsOneSubJettiness08_tag[kMaxcalojetsOneSubJettiness08];   //[calojetsOneSubJettiness08_]
   Int_t           calojetsOneSubJettiness08#0_;
   Int_t           calojetsOneSubJettiness08#0_index[kMaxcalojetsOneSubJettiness08#0];   //[calojetsOneSubJettiness08#0_]
   Int_t           calojetsOneSubJettiness08#0_collectionID[kMaxcalojetsOneSubJettiness08#0];   //[calojetsOneSubJettiness08#0_]
   Int_t           calojetsTwoSubJettiness08_;
   Float_t         calojetsTwoSubJettiness08_tag[kMaxcalojetsTwoSubJettiness08];   //[calojetsTwoSubJettiness08_]
   Int_t           calojetsTwoSubJettiness08#0_;
   Int_t           calojetsTwoSubJettiness08#0_index[kMaxcalojetsTwoSubJettiness08#0];   //[calojetsTwoSubJettiness08#0_]
   Int_t           calojetsTwoSubJettiness08#0_collectionID[kMaxcalojetsTwoSubJettiness08#0];   //[calojetsTwoSubJettiness08#0_]
   Int_t           calojetsThreeSubJettiness08_;
   Float_t         calojetsThreeSubJettiness08_tag[kMaxcalojetsThreeSubJettiness08];   //[calojetsThreeSubJettiness08_]
   Int_t           calojetsThreeSubJettiness08#0_;
   Int_t           calojetsThreeSubJettiness08#0_index[kMaxcalojetsThreeSubJettiness08#0];   //[calojetsThreeSubJettiness08#0_]
   Int_t           calojetsThreeSubJettiness08#0_collectionID[kMaxcalojetsThreeSubJettiness08#0];   //[calojetsThreeSubJettiness08#0_]
   Int_t           calosubjetsTrimmingTagged08_;
   UInt_t          calosubjetsTrimmingTagged08_subjets_begin[kMaxcalosubjetsTrimmingTagged08];   //[calosubjetsTrimmingTagged08_]
   UInt_t          calosubjetsTrimmingTagged08_subjets_end[kMaxcalosubjetsTrimmingTagged08];   //[calosubjetsTrimmingTagged08_]
   Int_t           calosubjetsTrimmingTagged08#0_;
   Int_t           calosubjetsTrimmingTagged08#0_index[kMaxcalosubjetsTrimmingTagged08#0];   //[calosubjetsTrimmingTagged08#0_]
   Int_t           calosubjetsTrimmingTagged08#0_collectionID[kMaxcalosubjetsTrimmingTagged08#0];   //[calosubjetsTrimmingTagged08#0_]
   Int_t           calosubjetsTrimmingTagged08#1_;
   Int_t           calosubjetsTrimmingTagged08#1_index[kMaxcalosubjetsTrimmingTagged08#1];   //[calosubjetsTrimmingTagged08#1_]
   Int_t           calosubjetsTrimmingTagged08#1_collectionID[kMaxcalosubjetsTrimmingTagged08#1];   //[calosubjetsTrimmingTagged08#1_]
   Int_t           calosubjetsPruningTagged08_;
   UInt_t          calosubjetsPruningTagged08_subjets_begin[kMaxcalosubjetsPruningTagged08];   //[calosubjetsPruningTagged08_]
   UInt_t          calosubjetsPruningTagged08_subjets_end[kMaxcalosubjetsPruningTagged08];   //[calosubjetsPruningTagged08_]
   Int_t           calosubjetsPruningTagged08#0_;
   Int_t           calosubjetsPruningTagged08#0_index[kMaxcalosubjetsPruningTagged08#0];   //[calosubjetsPruningTagged08#0_]
   Int_t           calosubjetsPruningTagged08#0_collectionID[kMaxcalosubjetsPruningTagged08#0];   //[calosubjetsPruningTagged08#0_]
   Int_t           calosubjetsPruningTagged08#1_;
   Int_t           calosubjetsPruningTagged08#1_index[kMaxcalosubjetsPruningTagged08#1];   //[calosubjetsPruningTagged08#1_]
   Int_t           calosubjetsPruningTagged08#1_collectionID[kMaxcalosubjetsPruningTagged08#1];   //[calosubjetsPruningTagged08#1_]
   Int_t           calosubjetsSoftDropTagged08_;
   UInt_t          calosubjetsSoftDropTagged08_subjets_begin[kMaxcalosubjetsSoftDropTagged08];   //[calosubjetsSoftDropTagged08_]
   UInt_t          calosubjetsSoftDropTagged08_subjets_end[kMaxcalosubjetsSoftDropTagged08];   //[calosubjetsSoftDropTagged08_]
   Int_t           calosubjetsSoftDropTagged08#0_;
   Int_t           calosubjetsSoftDropTagged08#0_index[kMaxcalosubjetsSoftDropTagged08#0];   //[calosubjetsSoftDropTagged08#0_]
   Int_t           calosubjetsSoftDropTagged08#0_collectionID[kMaxcalosubjetsSoftDropTagged08#0];   //[calosubjetsSoftDropTagged08#0_]
   Int_t           calosubjetsSoftDropTagged08#1_;
   Int_t           calosubjetsSoftDropTagged08#1_index[kMaxcalosubjetsSoftDropTagged08#1];   //[calosubjetsSoftDropTagged08#1_]
   Int_t           calosubjetsSoftDropTagged08#1_collectionID[kMaxcalosubjetsSoftDropTagged08#1];   //[calosubjetsSoftDropTagged08#1_]
   Int_t           calosubjetsTrimming08_;
   Float_t         calosubjetsTrimming08_core_area[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   UInt_t          calosubjetsTrimming08_core_bits[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   Float_t         calosubjetsTrimming08_core_p4_mass[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   Float_t         calosubjetsTrimming08_core_p4_px[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   Float_t         calosubjetsTrimming08_core_p4_py[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   Float_t         calosubjetsTrimming08_core_p4_pz[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   UInt_t          calosubjetsTrimming08_particles_begin[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   UInt_t          calosubjetsTrimming08_particles_end[kMaxcalosubjetsTrimming08];   //[calosubjetsTrimming08_]
   Int_t           calosubjetsTrimming08#0_;
   Int_t           calosubjetsTrimming08#0_index[kMaxcalosubjetsTrimming08#0];   //[calosubjetsTrimming08#0_]
   Int_t           calosubjetsTrimming08#0_collectionID[kMaxcalosubjetsTrimming08#0];   //[calosubjetsTrimming08#0_]
   Int_t           calosubjetsPruning08_;
   Float_t         calosubjetsPruning08_core_area[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   UInt_t          calosubjetsPruning08_core_bits[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   Float_t         calosubjetsPruning08_core_p4_mass[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   Float_t         calosubjetsPruning08_core_p4_px[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   Float_t         calosubjetsPruning08_core_p4_py[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   Float_t         calosubjetsPruning08_core_p4_pz[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   UInt_t          calosubjetsPruning08_particles_begin[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   UInt_t          calosubjetsPruning08_particles_end[kMaxcalosubjetsPruning08];   //[calosubjetsPruning08_]
   Int_t           calosubjetsPruning08#0_;
   Int_t           calosubjetsPruning08#0_index[kMaxcalosubjetsPruning08#0];   //[calosubjetsPruning08#0_]
   Int_t           calosubjetsPruning08#0_collectionID[kMaxcalosubjetsPruning08#0];   //[calosubjetsPruning08#0_]
   Int_t           calosubjetsSoftDrop08_;
   Float_t         calosubjetsSoftDrop08_core_area[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   UInt_t          calosubjetsSoftDrop08_core_bits[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   Float_t         calosubjetsSoftDrop08_core_p4_mass[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   Float_t         calosubjetsSoftDrop08_core_p4_px[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   Float_t         calosubjetsSoftDrop08_core_p4_py[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   Float_t         calosubjetsSoftDrop08_core_p4_pz[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   UInt_t          calosubjetsSoftDrop08_particles_begin[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   UInt_t          calosubjetsSoftDrop08_particles_end[kMaxcalosubjetsSoftDrop08];   //[calosubjetsSoftDrop08_]
   Int_t           calosubjetsSoftDrop08#0_;
   Int_t           calosubjetsSoftDrop08#0_index[kMaxcalosubjetsSoftDrop08#0];   //[calosubjetsSoftDrop08#0_]
   Int_t           calosubjetsSoftDrop08#0_collectionID[kMaxcalosubjetsSoftDrop08#0];   //[calosubjetsSoftDrop08#0_]
   Int_t           calojets15_;
   Float_t         calojets15_core_area[kMaxcalojets15];   //[calojets15_]
   UInt_t          calojets15_core_bits[kMaxcalojets15];   //[calojets15_]
   Float_t         calojets15_core_p4_mass[kMaxcalojets15];   //[calojets15_]
   Float_t         calojets15_core_p4_px[kMaxcalojets15];   //[calojets15_]
   Float_t         calojets15_core_p4_py[kMaxcalojets15];   //[calojets15_]
   Float_t         calojets15_core_p4_pz[kMaxcalojets15];   //[calojets15_]
   UInt_t          calojets15_particles_begin[kMaxcalojets15];   //[calojets15_]
   UInt_t          calojets15_particles_end[kMaxcalojets15];   //[calojets15_]
   Int_t           calojets15#0_;
   Int_t           calojets15#0_index[kMaxcalojets15#0];   //[calojets15#0_]
   Int_t           calojets15#0_collectionID[kMaxcalojets15#0];   //[calojets15#0_]
   Int_t           calojetsFlavor15_;
   Float_t         calojetsFlavor15_tag[kMaxcalojetsFlavor15];   //[calojetsFlavor15_]
   Int_t           calojetsFlavor15#0_;
   Int_t           calojetsFlavor15#0_index[kMaxcalojetsFlavor15#0];   //[calojetsFlavor15#0_]
   Int_t           calojetsFlavor15#0_collectionID[kMaxcalojetsFlavor15#0];   //[calojetsFlavor15#0_]
   Int_t           calobTags15_;
   Float_t         calobTags15_tag[kMaxcalobTags15];   //[calobTags15_]
   Int_t           calobTags15#0_;
   Int_t           calobTags15#0_index[kMaxcalobTags15#0];   //[calobTags15#0_]
   Int_t           calobTags15#0_collectionID[kMaxcalobTags15#0];   //[calobTags15#0_]
   Int_t           calocTags15_;
   Float_t         calocTags15_tag[kMaxcalocTags15];   //[calocTags15_]
   Int_t           calocTags15#0_;
   Int_t           calocTags15#0_index[kMaxcalocTags15#0];   //[calocTags15#0_]
   Int_t           calocTags15#0_collectionID[kMaxcalocTags15#0];   //[calocTags15#0_]
   Int_t           calotauTags15_;
   Float_t         calotauTags15_tag[kMaxcalotauTags15];   //[calotauTags15_]
   Int_t           calotauTags15#0_;
   Int_t           calotauTags15#0_index[kMaxcalotauTags15#0];   //[calotauTags15#0_]
   Int_t           calotauTags15#0_collectionID[kMaxcalotauTags15#0];   //[calotauTags15#0_]
   Int_t           calojetParts15_;
   UInt_t          calojetParts15_core_bits[kMaxcalojetParts15];   //[calojetParts15_]
   Int_t           calojetParts15_core_charge[kMaxcalojetParts15];   //[calojetParts15_]
   Float_t         calojetParts15_core_p4_mass[kMaxcalojetParts15];   //[calojetParts15_]
   Float_t         calojetParts15_core_p4_px[kMaxcalojetParts15];   //[calojetParts15_]
   Float_t         calojetParts15_core_p4_py[kMaxcalojetParts15];   //[calojetParts15_]
   Float_t         calojetParts15_core_p4_pz[kMaxcalojetParts15];   //[calojetParts15_]
   Int_t           calojetParts15_core_pdgId[kMaxcalojetParts15];   //[calojetParts15_]
   UInt_t          calojetParts15_core_status[kMaxcalojetParts15];   //[calojetParts15_]
   Float_t         calojetParts15_core_vertex_x[kMaxcalojetParts15];   //[calojetParts15_]
   Float_t         calojetParts15_core_vertex_y[kMaxcalojetParts15];   //[calojetParts15_]
   Float_t         calojetParts15_core_vertex_z[kMaxcalojetParts15];   //[calojetParts15_]
   UInt_t          calojetParts15_tracks_begin[kMaxcalojetParts15];   //[calojetParts15_]
   UInt_t          calojetParts15_tracks_end[kMaxcalojetParts15];   //[calojetParts15_]
   UInt_t          calojetParts15_clusters_begin[kMaxcalojetParts15];   //[calojetParts15_]
   UInt_t          calojetParts15_clusters_end[kMaxcalojetParts15];   //[calojetParts15_]
   Int_t           calojetParts15#0_;
   Int_t           calojetParts15#0_index[kMaxcalojetParts15#0];   //[calojetParts15#0_]
   Int_t           calojetParts15#0_collectionID[kMaxcalojetParts15#0];   //[calojetParts15#0_]
   Int_t           calojetParts15#1_;
   Int_t           calojetParts15#1_index[kMaxcalojetParts15#1];   //[calojetParts15#1_]
   Int_t           calojetParts15#1_collectionID[kMaxcalojetParts15#1];   //[calojetParts15#1_]
   Int_t           calojetsOneSubJettiness15_;
   Float_t         calojetsOneSubJettiness15_tag[kMaxcalojetsOneSubJettiness15];   //[calojetsOneSubJettiness15_]
   Int_t           calojetsOneSubJettiness15#0_;
   Int_t           calojetsOneSubJettiness15#0_index[kMaxcalojetsOneSubJettiness15#0];   //[calojetsOneSubJettiness15#0_]
   Int_t           calojetsOneSubJettiness15#0_collectionID[kMaxcalojetsOneSubJettiness15#0];   //[calojetsOneSubJettiness15#0_]
   Int_t           calojetsTwoSubJettiness15_;
   Float_t         calojetsTwoSubJettiness15_tag[kMaxcalojetsTwoSubJettiness15];   //[calojetsTwoSubJettiness15_]
   Int_t           calojetsTwoSubJettiness15#0_;
   Int_t           calojetsTwoSubJettiness15#0_index[kMaxcalojetsTwoSubJettiness15#0];   //[calojetsTwoSubJettiness15#0_]
   Int_t           calojetsTwoSubJettiness15#0_collectionID[kMaxcalojetsTwoSubJettiness15#0];   //[calojetsTwoSubJettiness15#0_]
   Int_t           calojetsThreeSubJettiness15_;
   Float_t         calojetsThreeSubJettiness15_tag[kMaxcalojetsThreeSubJettiness15];   //[calojetsThreeSubJettiness15_]
   Int_t           calojetsThreeSubJettiness15#0_;
   Int_t           calojetsThreeSubJettiness15#0_index[kMaxcalojetsThreeSubJettiness15#0];   //[calojetsThreeSubJettiness15#0_]
   Int_t           calojetsThreeSubJettiness15#0_collectionID[kMaxcalojetsThreeSubJettiness15#0];   //[calojetsThreeSubJettiness15#0_]
   Int_t           calosubjetsTrimmingTagged15_;
   UInt_t          calosubjetsTrimmingTagged15_subjets_begin[kMaxcalosubjetsTrimmingTagged15];   //[calosubjetsTrimmingTagged15_]
   UInt_t          calosubjetsTrimmingTagged15_subjets_end[kMaxcalosubjetsTrimmingTagged15];   //[calosubjetsTrimmingTagged15_]
   Int_t           calosubjetsTrimmingTagged15#0_;
   Int_t           calosubjetsTrimmingTagged15#0_index[kMaxcalosubjetsTrimmingTagged15#0];   //[calosubjetsTrimmingTagged15#0_]
   Int_t           calosubjetsTrimmingTagged15#0_collectionID[kMaxcalosubjetsTrimmingTagged15#0];   //[calosubjetsTrimmingTagged15#0_]
   Int_t           calosubjetsTrimmingTagged15#1_;
   Int_t           calosubjetsTrimmingTagged15#1_index[kMaxcalosubjetsTrimmingTagged15#1];   //[calosubjetsTrimmingTagged15#1_]
   Int_t           calosubjetsTrimmingTagged15#1_collectionID[kMaxcalosubjetsTrimmingTagged15#1];   //[calosubjetsTrimmingTagged15#1_]
   Int_t           calosubjetsPruningTagged15_;
   UInt_t          calosubjetsPruningTagged15_subjets_begin[kMaxcalosubjetsPruningTagged15];   //[calosubjetsPruningTagged15_]
   UInt_t          calosubjetsPruningTagged15_subjets_end[kMaxcalosubjetsPruningTagged15];   //[calosubjetsPruningTagged15_]
   Int_t           calosubjetsPruningTagged15#0_;
   Int_t           calosubjetsPruningTagged15#0_index[kMaxcalosubjetsPruningTagged15#0];   //[calosubjetsPruningTagged15#0_]
   Int_t           calosubjetsPruningTagged15#0_collectionID[kMaxcalosubjetsPruningTagged15#0];   //[calosubjetsPruningTagged15#0_]
   Int_t           calosubjetsPruningTagged15#1_;
   Int_t           calosubjetsPruningTagged15#1_index[kMaxcalosubjetsPruningTagged15#1];   //[calosubjetsPruningTagged15#1_]
   Int_t           calosubjetsPruningTagged15#1_collectionID[kMaxcalosubjetsPruningTagged15#1];   //[calosubjetsPruningTagged15#1_]
   Int_t           calosubjetsSoftDropTagged15_;
   UInt_t          calosubjetsSoftDropTagged15_subjets_begin[kMaxcalosubjetsSoftDropTagged15];   //[calosubjetsSoftDropTagged15_]
   UInt_t          calosubjetsSoftDropTagged15_subjets_end[kMaxcalosubjetsSoftDropTagged15];   //[calosubjetsSoftDropTagged15_]
   Int_t           calosubjetsSoftDropTagged15#0_;
   Int_t           calosubjetsSoftDropTagged15#0_index[kMaxcalosubjetsSoftDropTagged15#0];   //[calosubjetsSoftDropTagged15#0_]
   Int_t           calosubjetsSoftDropTagged15#0_collectionID[kMaxcalosubjetsSoftDropTagged15#0];   //[calosubjetsSoftDropTagged15#0_]
   Int_t           calosubjetsSoftDropTagged15#1_;
   Int_t           calosubjetsSoftDropTagged15#1_index[kMaxcalosubjetsSoftDropTagged15#1];   //[calosubjetsSoftDropTagged15#1_]
   Int_t           calosubjetsSoftDropTagged15#1_collectionID[kMaxcalosubjetsSoftDropTagged15#1];   //[calosubjetsSoftDropTagged15#1_]
   Int_t           calosubjetsTrimming15_;
   Float_t         calosubjetsTrimming15_core_area[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   UInt_t          calosubjetsTrimming15_core_bits[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   Float_t         calosubjetsTrimming15_core_p4_mass[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   Float_t         calosubjetsTrimming15_core_p4_px[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   Float_t         calosubjetsTrimming15_core_p4_py[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   Float_t         calosubjetsTrimming15_core_p4_pz[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   UInt_t          calosubjetsTrimming15_particles_begin[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   UInt_t          calosubjetsTrimming15_particles_end[kMaxcalosubjetsTrimming15];   //[calosubjetsTrimming15_]
   Int_t           calosubjetsTrimming15#0_;
   Int_t           calosubjetsTrimming15#0_index[kMaxcalosubjetsTrimming15#0];   //[calosubjetsTrimming15#0_]
   Int_t           calosubjetsTrimming15#0_collectionID[kMaxcalosubjetsTrimming15#0];   //[calosubjetsTrimming15#0_]
   Int_t           calosubjetsPruning15_;
   Float_t         calosubjetsPruning15_core_area[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   UInt_t          calosubjetsPruning15_core_bits[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   Float_t         calosubjetsPruning15_core_p4_mass[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   Float_t         calosubjetsPruning15_core_p4_px[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   Float_t         calosubjetsPruning15_core_p4_py[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   Float_t         calosubjetsPruning15_core_p4_pz[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   UInt_t          calosubjetsPruning15_particles_begin[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   UInt_t          calosubjetsPruning15_particles_end[kMaxcalosubjetsPruning15];   //[calosubjetsPruning15_]
   Int_t           calosubjetsPruning15#0_;
   Int_t           calosubjetsPruning15#0_index[kMaxcalosubjetsPruning15#0];   //[calosubjetsPruning15#0_]
   Int_t           calosubjetsPruning15#0_collectionID[kMaxcalosubjetsPruning15#0];   //[calosubjetsPruning15#0_]
   Int_t           calosubjetsSoftDrop15_;
   Float_t         calosubjetsSoftDrop15_core_area[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   UInt_t          calosubjetsSoftDrop15_core_bits[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   Float_t         calosubjetsSoftDrop15_core_p4_mass[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   Float_t         calosubjetsSoftDrop15_core_p4_px[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   Float_t         calosubjetsSoftDrop15_core_p4_py[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   Float_t         calosubjetsSoftDrop15_core_p4_pz[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   UInt_t          calosubjetsSoftDrop15_particles_begin[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   UInt_t          calosubjetsSoftDrop15_particles_end[kMaxcalosubjetsSoftDrop15];   //[calosubjetsSoftDrop15_]
   Int_t           calosubjetsSoftDrop15#0_;
   Int_t           calosubjetsSoftDrop15#0_index[kMaxcalosubjetsSoftDrop15#0];   //[calosubjetsSoftDrop15#0_]
   Int_t           calosubjetsSoftDrop15#0_collectionID[kMaxcalosubjetsSoftDrop15#0];   //[calosubjetsSoftDrop15#0_]
   Int_t           pfjets02_;
   Float_t         pfjets02_core_area[kMaxpfjets02];   //[pfjets02_]
   UInt_t          pfjets02_core_bits[kMaxpfjets02];   //[pfjets02_]
   Float_t         pfjets02_core_p4_mass[kMaxpfjets02];   //[pfjets02_]
   Float_t         pfjets02_core_p4_px[kMaxpfjets02];   //[pfjets02_]
   Float_t         pfjets02_core_p4_py[kMaxpfjets02];   //[pfjets02_]
   Float_t         pfjets02_core_p4_pz[kMaxpfjets02];   //[pfjets02_]
   UInt_t          pfjets02_particles_begin[kMaxpfjets02];   //[pfjets02_]
   UInt_t          pfjets02_particles_end[kMaxpfjets02];   //[pfjets02_]
   Int_t           pfjets02#0_;
   Int_t           pfjets02#0_index[kMaxpfjets02#0];   //[pfjets02#0_]
   Int_t           pfjets02#0_collectionID[kMaxpfjets02#0];   //[pfjets02#0_]
   Int_t           pfjetsFlavor02_;
   Float_t         pfjetsFlavor02_tag[kMaxpfjetsFlavor02];   //[pfjetsFlavor02_]
   Int_t           pfjetsFlavor02#0_;
   Int_t           pfjetsFlavor02#0_index[kMaxpfjetsFlavor02#0];   //[pfjetsFlavor02#0_]
   Int_t           pfjetsFlavor02#0_collectionID[kMaxpfjetsFlavor02#0];   //[pfjetsFlavor02#0_]
   Int_t           pfbTags02_;
   Float_t         pfbTags02_tag[kMaxpfbTags02];   //[pfbTags02_]
   Int_t           pfbTags02#0_;
   Int_t           pfbTags02#0_index[kMaxpfbTags02#0];   //[pfbTags02#0_]
   Int_t           pfbTags02#0_collectionID[kMaxpfbTags02#0];   //[pfbTags02#0_]
   Int_t           pfcTags02_;
   Float_t         pfcTags02_tag[kMaxpfcTags02];   //[pfcTags02_]
   Int_t           pfcTags02#0_;
   Int_t           pfcTags02#0_index[kMaxpfcTags02#0];   //[pfcTags02#0_]
   Int_t           pfcTags02#0_collectionID[kMaxpfcTags02#0];   //[pfcTags02#0_]
   Int_t           pftauTags02_;
   Float_t         pftauTags02_tag[kMaxpftauTags02];   //[pftauTags02_]
   Int_t           pftauTags02#0_;
   Int_t           pftauTags02#0_index[kMaxpftauTags02#0];   //[pftauTags02#0_]
   Int_t           pftauTags02#0_collectionID[kMaxpftauTags02#0];   //[pftauTags02#0_]
   Int_t           pfjetParts02_;
   UInt_t          pfjetParts02_core_bits[kMaxpfjetParts02];   //[pfjetParts02_]
   Int_t           pfjetParts02_core_charge[kMaxpfjetParts02];   //[pfjetParts02_]
   Float_t         pfjetParts02_core_p4_mass[kMaxpfjetParts02];   //[pfjetParts02_]
   Float_t         pfjetParts02_core_p4_px[kMaxpfjetParts02];   //[pfjetParts02_]
   Float_t         pfjetParts02_core_p4_py[kMaxpfjetParts02];   //[pfjetParts02_]
   Float_t         pfjetParts02_core_p4_pz[kMaxpfjetParts02];   //[pfjetParts02_]
   Int_t           pfjetParts02_core_pdgId[kMaxpfjetParts02];   //[pfjetParts02_]
   UInt_t          pfjetParts02_core_status[kMaxpfjetParts02];   //[pfjetParts02_]
   Float_t         pfjetParts02_core_vertex_x[kMaxpfjetParts02];   //[pfjetParts02_]
   Float_t         pfjetParts02_core_vertex_y[kMaxpfjetParts02];   //[pfjetParts02_]
   Float_t         pfjetParts02_core_vertex_z[kMaxpfjetParts02];   //[pfjetParts02_]
   UInt_t          pfjetParts02_tracks_begin[kMaxpfjetParts02];   //[pfjetParts02_]
   UInt_t          pfjetParts02_tracks_end[kMaxpfjetParts02];   //[pfjetParts02_]
   UInt_t          pfjetParts02_clusters_begin[kMaxpfjetParts02];   //[pfjetParts02_]
   UInt_t          pfjetParts02_clusters_end[kMaxpfjetParts02];   //[pfjetParts02_]
   Int_t           pfjetParts02#0_;
   Int_t           pfjetParts02#0_index[kMaxpfjetParts02#0];   //[pfjetParts02#0_]
   Int_t           pfjetParts02#0_collectionID[kMaxpfjetParts02#0];   //[pfjetParts02#0_]
   Int_t           pfjetParts02#1_;
   Int_t           pfjetParts02#1_index[kMaxpfjetParts02#1];   //[pfjetParts02#1_]
   Int_t           pfjetParts02#1_collectionID[kMaxpfjetParts02#1];   //[pfjetParts02#1_]
   Int_t           pfjetsOneSubJettiness02_;
   Float_t         pfjetsOneSubJettiness02_tag[kMaxpfjetsOneSubJettiness02];   //[pfjetsOneSubJettiness02_]
   Int_t           pfjetsOneSubJettiness02#0_;
   Int_t           pfjetsOneSubJettiness02#0_index[kMaxpfjetsOneSubJettiness02#0];   //[pfjetsOneSubJettiness02#0_]
   Int_t           pfjetsOneSubJettiness02#0_collectionID[kMaxpfjetsOneSubJettiness02#0];   //[pfjetsOneSubJettiness02#0_]
   Int_t           pfjetsTwoSubJettiness02_;
   Float_t         pfjetsTwoSubJettiness02_tag[kMaxpfjetsTwoSubJettiness02];   //[pfjetsTwoSubJettiness02_]
   Int_t           pfjetsTwoSubJettiness02#0_;
   Int_t           pfjetsTwoSubJettiness02#0_index[kMaxpfjetsTwoSubJettiness02#0];   //[pfjetsTwoSubJettiness02#0_]
   Int_t           pfjetsTwoSubJettiness02#0_collectionID[kMaxpfjetsTwoSubJettiness02#0];   //[pfjetsTwoSubJettiness02#0_]
   Int_t           pfjetsThreeSubJettiness02_;
   Float_t         pfjetsThreeSubJettiness02_tag[kMaxpfjetsThreeSubJettiness02];   //[pfjetsThreeSubJettiness02_]
   Int_t           pfjetsThreeSubJettiness02#0_;
   Int_t           pfjetsThreeSubJettiness02#0_index[kMaxpfjetsThreeSubJettiness02#0];   //[pfjetsThreeSubJettiness02#0_]
   Int_t           pfjetsThreeSubJettiness02#0_collectionID[kMaxpfjetsThreeSubJettiness02#0];   //[pfjetsThreeSubJettiness02#0_]
   Int_t           pfsubjetsTrimmingTagged02_;
   UInt_t          pfsubjetsTrimmingTagged02_subjets_begin[kMaxpfsubjetsTrimmingTagged02];   //[pfsubjetsTrimmingTagged02_]
   UInt_t          pfsubjetsTrimmingTagged02_subjets_end[kMaxpfsubjetsTrimmingTagged02];   //[pfsubjetsTrimmingTagged02_]
   Int_t           pfsubjetsTrimmingTagged02#0_;
   Int_t           pfsubjetsTrimmingTagged02#0_index[kMaxpfsubjetsTrimmingTagged02#0];   //[pfsubjetsTrimmingTagged02#0_]
   Int_t           pfsubjetsTrimmingTagged02#0_collectionID[kMaxpfsubjetsTrimmingTagged02#0];   //[pfsubjetsTrimmingTagged02#0_]
   Int_t           pfsubjetsTrimmingTagged02#1_;
   Int_t           pfsubjetsTrimmingTagged02#1_index[kMaxpfsubjetsTrimmingTagged02#1];   //[pfsubjetsTrimmingTagged02#1_]
   Int_t           pfsubjetsTrimmingTagged02#1_collectionID[kMaxpfsubjetsTrimmingTagged02#1];   //[pfsubjetsTrimmingTagged02#1_]
   Int_t           pfsubjetsPruningTagged02_;
   UInt_t          pfsubjetsPruningTagged02_subjets_begin[kMaxpfsubjetsPruningTagged02];   //[pfsubjetsPruningTagged02_]
   UInt_t          pfsubjetsPruningTagged02_subjets_end[kMaxpfsubjetsPruningTagged02];   //[pfsubjetsPruningTagged02_]
   Int_t           pfsubjetsPruningTagged02#0_;
   Int_t           pfsubjetsPruningTagged02#0_index[kMaxpfsubjetsPruningTagged02#0];   //[pfsubjetsPruningTagged02#0_]
   Int_t           pfsubjetsPruningTagged02#0_collectionID[kMaxpfsubjetsPruningTagged02#0];   //[pfsubjetsPruningTagged02#0_]
   Int_t           pfsubjetsPruningTagged02#1_;
   Int_t           pfsubjetsPruningTagged02#1_index[kMaxpfsubjetsPruningTagged02#1];   //[pfsubjetsPruningTagged02#1_]
   Int_t           pfsubjetsPruningTagged02#1_collectionID[kMaxpfsubjetsPruningTagged02#1];   //[pfsubjetsPruningTagged02#1_]
   Int_t           pfsubjetsSoftDropTagged02_;
   UInt_t          pfsubjetsSoftDropTagged02_subjets_begin[kMaxpfsubjetsSoftDropTagged02];   //[pfsubjetsSoftDropTagged02_]
   UInt_t          pfsubjetsSoftDropTagged02_subjets_end[kMaxpfsubjetsSoftDropTagged02];   //[pfsubjetsSoftDropTagged02_]
   Int_t           pfsubjetsSoftDropTagged02#0_;
   Int_t           pfsubjetsSoftDropTagged02#0_index[kMaxpfsubjetsSoftDropTagged02#0];   //[pfsubjetsSoftDropTagged02#0_]
   Int_t           pfsubjetsSoftDropTagged02#0_collectionID[kMaxpfsubjetsSoftDropTagged02#0];   //[pfsubjetsSoftDropTagged02#0_]
   Int_t           pfsubjetsSoftDropTagged02#1_;
   Int_t           pfsubjetsSoftDropTagged02#1_index[kMaxpfsubjetsSoftDropTagged02#1];   //[pfsubjetsSoftDropTagged02#1_]
   Int_t           pfsubjetsSoftDropTagged02#1_collectionID[kMaxpfsubjetsSoftDropTagged02#1];   //[pfsubjetsSoftDropTagged02#1_]
   Int_t           pfsubjetsTrimming02_;
   Float_t         pfsubjetsTrimming02_core_area[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   UInt_t          pfsubjetsTrimming02_core_bits[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   Float_t         pfsubjetsTrimming02_core_p4_mass[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   Float_t         pfsubjetsTrimming02_core_p4_px[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   Float_t         pfsubjetsTrimming02_core_p4_py[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   Float_t         pfsubjetsTrimming02_core_p4_pz[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   UInt_t          pfsubjetsTrimming02_particles_begin[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   UInt_t          pfsubjetsTrimming02_particles_end[kMaxpfsubjetsTrimming02];   //[pfsubjetsTrimming02_]
   Int_t           pfsubjetsTrimming02#0_;
   Int_t           pfsubjetsTrimming02#0_index[kMaxpfsubjetsTrimming02#0];   //[pfsubjetsTrimming02#0_]
   Int_t           pfsubjetsTrimming02#0_collectionID[kMaxpfsubjetsTrimming02#0];   //[pfsubjetsTrimming02#0_]
   Int_t           pfsubjetsPruning02_;
   Float_t         pfsubjetsPruning02_core_area[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   UInt_t          pfsubjetsPruning02_core_bits[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   Float_t         pfsubjetsPruning02_core_p4_mass[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   Float_t         pfsubjetsPruning02_core_p4_px[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   Float_t         pfsubjetsPruning02_core_p4_py[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   Float_t         pfsubjetsPruning02_core_p4_pz[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   UInt_t          pfsubjetsPruning02_particles_begin[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   UInt_t          pfsubjetsPruning02_particles_end[kMaxpfsubjetsPruning02];   //[pfsubjetsPruning02_]
   Int_t           pfsubjetsPruning02#0_;
   Int_t           pfsubjetsPruning02#0_index[kMaxpfsubjetsPruning02#0];   //[pfsubjetsPruning02#0_]
   Int_t           pfsubjetsPruning02#0_collectionID[kMaxpfsubjetsPruning02#0];   //[pfsubjetsPruning02#0_]
   Int_t           pfsubjetsSoftDrop02_;
   Float_t         pfsubjetsSoftDrop02_core_area[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   UInt_t          pfsubjetsSoftDrop02_core_bits[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   Float_t         pfsubjetsSoftDrop02_core_p4_mass[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   Float_t         pfsubjetsSoftDrop02_core_p4_px[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   Float_t         pfsubjetsSoftDrop02_core_p4_py[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   Float_t         pfsubjetsSoftDrop02_core_p4_pz[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   UInt_t          pfsubjetsSoftDrop02_particles_begin[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   UInt_t          pfsubjetsSoftDrop02_particles_end[kMaxpfsubjetsSoftDrop02];   //[pfsubjetsSoftDrop02_]
   Int_t           pfsubjetsSoftDrop02#0_;
   Int_t           pfsubjetsSoftDrop02#0_index[kMaxpfsubjetsSoftDrop02#0];   //[pfsubjetsSoftDrop02#0_]
   Int_t           pfsubjetsSoftDrop02#0_collectionID[kMaxpfsubjetsSoftDrop02#0];   //[pfsubjetsSoftDrop02#0_]
   Int_t           pfjets04_;
   Float_t         pfjets04_core_area[kMaxpfjets04];   //[pfjets04_]
   UInt_t          pfjets04_core_bits[kMaxpfjets04];   //[pfjets04_]
   Float_t         pfjets04_core_p4_mass[kMaxpfjets04];   //[pfjets04_]
   Float_t         pfjets04_core_p4_px[kMaxpfjets04];   //[pfjets04_]
   Float_t         pfjets04_core_p4_py[kMaxpfjets04];   //[pfjets04_]
   Float_t         pfjets04_core_p4_pz[kMaxpfjets04];   //[pfjets04_]
   UInt_t          pfjets04_particles_begin[kMaxpfjets04];   //[pfjets04_]
   UInt_t          pfjets04_particles_end[kMaxpfjets04];   //[pfjets04_]
   Int_t           pfjets04#0_;
   Int_t           pfjets04#0_index[kMaxpfjets04#0];   //[pfjets04#0_]
   Int_t           pfjets04#0_collectionID[kMaxpfjets04#0];   //[pfjets04#0_]
   Int_t           pfjetsFlavor04_;
   Float_t         pfjetsFlavor04_tag[kMaxpfjetsFlavor04];   //[pfjetsFlavor04_]
   Int_t           pfjetsFlavor04#0_;
   Int_t           pfjetsFlavor04#0_index[kMaxpfjetsFlavor04#0];   //[pfjetsFlavor04#0_]
   Int_t           pfjetsFlavor04#0_collectionID[kMaxpfjetsFlavor04#0];   //[pfjetsFlavor04#0_]
   Int_t           pfbTags04_;
   Float_t         pfbTags04_tag[kMaxpfbTags04];   //[pfbTags04_]
   Int_t           pfbTags04#0_;
   Int_t           pfbTags04#0_index[kMaxpfbTags04#0];   //[pfbTags04#0_]
   Int_t           pfbTags04#0_collectionID[kMaxpfbTags04#0];   //[pfbTags04#0_]
   Int_t           pfcTags04_;
   Float_t         pfcTags04_tag[kMaxpfcTags04];   //[pfcTags04_]
   Int_t           pfcTags04#0_;
   Int_t           pfcTags04#0_index[kMaxpfcTags04#0];   //[pfcTags04#0_]
   Int_t           pfcTags04#0_collectionID[kMaxpfcTags04#0];   //[pfcTags04#0_]
   Int_t           pftauTags04_;
   Float_t         pftauTags04_tag[kMaxpftauTags04];   //[pftauTags04_]
   Int_t           pftauTags04#0_;
   Int_t           pftauTags04#0_index[kMaxpftauTags04#0];   //[pftauTags04#0_]
   Int_t           pftauTags04#0_collectionID[kMaxpftauTags04#0];   //[pftauTags04#0_]
   Int_t           pfjetParts04_;
   UInt_t          pfjetParts04_core_bits[kMaxpfjetParts04];   //[pfjetParts04_]
   Int_t           pfjetParts04_core_charge[kMaxpfjetParts04];   //[pfjetParts04_]
   Float_t         pfjetParts04_core_p4_mass[kMaxpfjetParts04];   //[pfjetParts04_]
   Float_t         pfjetParts04_core_p4_px[kMaxpfjetParts04];   //[pfjetParts04_]
   Float_t         pfjetParts04_core_p4_py[kMaxpfjetParts04];   //[pfjetParts04_]
   Float_t         pfjetParts04_core_p4_pz[kMaxpfjetParts04];   //[pfjetParts04_]
   Int_t           pfjetParts04_core_pdgId[kMaxpfjetParts04];   //[pfjetParts04_]
   UInt_t          pfjetParts04_core_status[kMaxpfjetParts04];   //[pfjetParts04_]
   Float_t         pfjetParts04_core_vertex_x[kMaxpfjetParts04];   //[pfjetParts04_]
   Float_t         pfjetParts04_core_vertex_y[kMaxpfjetParts04];   //[pfjetParts04_]
   Float_t         pfjetParts04_core_vertex_z[kMaxpfjetParts04];   //[pfjetParts04_]
   UInt_t          pfjetParts04_tracks_begin[kMaxpfjetParts04];   //[pfjetParts04_]
   UInt_t          pfjetParts04_tracks_end[kMaxpfjetParts04];   //[pfjetParts04_]
   UInt_t          pfjetParts04_clusters_begin[kMaxpfjetParts04];   //[pfjetParts04_]
   UInt_t          pfjetParts04_clusters_end[kMaxpfjetParts04];   //[pfjetParts04_]
   Int_t           pfjetParts04#0_;
   Int_t           pfjetParts04#0_index[kMaxpfjetParts04#0];   //[pfjetParts04#0_]
   Int_t           pfjetParts04#0_collectionID[kMaxpfjetParts04#0];   //[pfjetParts04#0_]
   Int_t           pfjetParts04#1_;
   Int_t           pfjetParts04#1_index[kMaxpfjetParts04#1];   //[pfjetParts04#1_]
   Int_t           pfjetParts04#1_collectionID[kMaxpfjetParts04#1];   //[pfjetParts04#1_]
   Int_t           pfjetsOneSubJettiness04_;
   Float_t         pfjetsOneSubJettiness04_tag[kMaxpfjetsOneSubJettiness04];   //[pfjetsOneSubJettiness04_]
   Int_t           pfjetsOneSubJettiness04#0_;
   Int_t           pfjetsOneSubJettiness04#0_index[kMaxpfjetsOneSubJettiness04#0];   //[pfjetsOneSubJettiness04#0_]
   Int_t           pfjetsOneSubJettiness04#0_collectionID[kMaxpfjetsOneSubJettiness04#0];   //[pfjetsOneSubJettiness04#0_]
   Int_t           pfjetsTwoSubJettiness04_;
   Float_t         pfjetsTwoSubJettiness04_tag[kMaxpfjetsTwoSubJettiness04];   //[pfjetsTwoSubJettiness04_]
   Int_t           pfjetsTwoSubJettiness04#0_;
   Int_t           pfjetsTwoSubJettiness04#0_index[kMaxpfjetsTwoSubJettiness04#0];   //[pfjetsTwoSubJettiness04#0_]
   Int_t           pfjetsTwoSubJettiness04#0_collectionID[kMaxpfjetsTwoSubJettiness04#0];   //[pfjetsTwoSubJettiness04#0_]
   Int_t           pfjetsThreeSubJettiness04_;
   Float_t         pfjetsThreeSubJettiness04_tag[kMaxpfjetsThreeSubJettiness04];   //[pfjetsThreeSubJettiness04_]
   Int_t           pfjetsThreeSubJettiness04#0_;
   Int_t           pfjetsThreeSubJettiness04#0_index[kMaxpfjetsThreeSubJettiness04#0];   //[pfjetsThreeSubJettiness04#0_]
   Int_t           pfjetsThreeSubJettiness04#0_collectionID[kMaxpfjetsThreeSubJettiness04#0];   //[pfjetsThreeSubJettiness04#0_]
   Int_t           pfsubjetsTrimmingTagged04_;
   UInt_t          pfsubjetsTrimmingTagged04_subjets_begin[kMaxpfsubjetsTrimmingTagged04];   //[pfsubjetsTrimmingTagged04_]
   UInt_t          pfsubjetsTrimmingTagged04_subjets_end[kMaxpfsubjetsTrimmingTagged04];   //[pfsubjetsTrimmingTagged04_]
   Int_t           pfsubjetsTrimmingTagged04#0_;
   Int_t           pfsubjetsTrimmingTagged04#0_index[kMaxpfsubjetsTrimmingTagged04#0];   //[pfsubjetsTrimmingTagged04#0_]
   Int_t           pfsubjetsTrimmingTagged04#0_collectionID[kMaxpfsubjetsTrimmingTagged04#0];   //[pfsubjetsTrimmingTagged04#0_]
   Int_t           pfsubjetsTrimmingTagged04#1_;
   Int_t           pfsubjetsTrimmingTagged04#1_index[kMaxpfsubjetsTrimmingTagged04#1];   //[pfsubjetsTrimmingTagged04#1_]
   Int_t           pfsubjetsTrimmingTagged04#1_collectionID[kMaxpfsubjetsTrimmingTagged04#1];   //[pfsubjetsTrimmingTagged04#1_]
   Int_t           pfsubjetsPruningTagged04_;
   UInt_t          pfsubjetsPruningTagged04_subjets_begin[kMaxpfsubjetsPruningTagged04];   //[pfsubjetsPruningTagged04_]
   UInt_t          pfsubjetsPruningTagged04_subjets_end[kMaxpfsubjetsPruningTagged04];   //[pfsubjetsPruningTagged04_]
   Int_t           pfsubjetsPruningTagged04#0_;
   Int_t           pfsubjetsPruningTagged04#0_index[kMaxpfsubjetsPruningTagged04#0];   //[pfsubjetsPruningTagged04#0_]
   Int_t           pfsubjetsPruningTagged04#0_collectionID[kMaxpfsubjetsPruningTagged04#0];   //[pfsubjetsPruningTagged04#0_]
   Int_t           pfsubjetsPruningTagged04#1_;
   Int_t           pfsubjetsPruningTagged04#1_index[kMaxpfsubjetsPruningTagged04#1];   //[pfsubjetsPruningTagged04#1_]
   Int_t           pfsubjetsPruningTagged04#1_collectionID[kMaxpfsubjetsPruningTagged04#1];   //[pfsubjetsPruningTagged04#1_]
   Int_t           pfsubjetsSoftDropTagged04_;
   UInt_t          pfsubjetsSoftDropTagged04_subjets_begin[kMaxpfsubjetsSoftDropTagged04];   //[pfsubjetsSoftDropTagged04_]
   UInt_t          pfsubjetsSoftDropTagged04_subjets_end[kMaxpfsubjetsSoftDropTagged04];   //[pfsubjetsSoftDropTagged04_]
   Int_t           pfsubjetsSoftDropTagged04#0_;
   Int_t           pfsubjetsSoftDropTagged04#0_index[kMaxpfsubjetsSoftDropTagged04#0];   //[pfsubjetsSoftDropTagged04#0_]
   Int_t           pfsubjetsSoftDropTagged04#0_collectionID[kMaxpfsubjetsSoftDropTagged04#0];   //[pfsubjetsSoftDropTagged04#0_]
   Int_t           pfsubjetsSoftDropTagged04#1_;
   Int_t           pfsubjetsSoftDropTagged04#1_index[kMaxpfsubjetsSoftDropTagged04#1];   //[pfsubjetsSoftDropTagged04#1_]
   Int_t           pfsubjetsSoftDropTagged04#1_collectionID[kMaxpfsubjetsSoftDropTagged04#1];   //[pfsubjetsSoftDropTagged04#1_]
   Int_t           pfsubjetsTrimming04_;
   Float_t         pfsubjetsTrimming04_core_area[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   UInt_t          pfsubjetsTrimming04_core_bits[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   Float_t         pfsubjetsTrimming04_core_p4_mass[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   Float_t         pfsubjetsTrimming04_core_p4_px[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   Float_t         pfsubjetsTrimming04_core_p4_py[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   Float_t         pfsubjetsTrimming04_core_p4_pz[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   UInt_t          pfsubjetsTrimming04_particles_begin[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   UInt_t          pfsubjetsTrimming04_particles_end[kMaxpfsubjetsTrimming04];   //[pfsubjetsTrimming04_]
   Int_t           pfsubjetsTrimming04#0_;
   Int_t           pfsubjetsTrimming04#0_index[kMaxpfsubjetsTrimming04#0];   //[pfsubjetsTrimming04#0_]
   Int_t           pfsubjetsTrimming04#0_collectionID[kMaxpfsubjetsTrimming04#0];   //[pfsubjetsTrimming04#0_]
   Int_t           pfsubjetsPruning04_;
   Float_t         pfsubjetsPruning04_core_area[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   UInt_t          pfsubjetsPruning04_core_bits[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   Float_t         pfsubjetsPruning04_core_p4_mass[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   Float_t         pfsubjetsPruning04_core_p4_px[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   Float_t         pfsubjetsPruning04_core_p4_py[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   Float_t         pfsubjetsPruning04_core_p4_pz[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   UInt_t          pfsubjetsPruning04_particles_begin[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   UInt_t          pfsubjetsPruning04_particles_end[kMaxpfsubjetsPruning04];   //[pfsubjetsPruning04_]
   Int_t           pfsubjetsPruning04#0_;
   Int_t           pfsubjetsPruning04#0_index[kMaxpfsubjetsPruning04#0];   //[pfsubjetsPruning04#0_]
   Int_t           pfsubjetsPruning04#0_collectionID[kMaxpfsubjetsPruning04#0];   //[pfsubjetsPruning04#0_]
   Int_t           pfsubjetsSoftDrop04_;
   Float_t         pfsubjetsSoftDrop04_core_area[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   UInt_t          pfsubjetsSoftDrop04_core_bits[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   Float_t         pfsubjetsSoftDrop04_core_p4_mass[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   Float_t         pfsubjetsSoftDrop04_core_p4_px[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   Float_t         pfsubjetsSoftDrop04_core_p4_py[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   Float_t         pfsubjetsSoftDrop04_core_p4_pz[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   UInt_t          pfsubjetsSoftDrop04_particles_begin[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   UInt_t          pfsubjetsSoftDrop04_particles_end[kMaxpfsubjetsSoftDrop04];   //[pfsubjetsSoftDrop04_]
   Int_t           pfsubjetsSoftDrop04#0_;
   Int_t           pfsubjetsSoftDrop04#0_index[kMaxpfsubjetsSoftDrop04#0];   //[pfsubjetsSoftDrop04#0_]
   Int_t           pfsubjetsSoftDrop04#0_collectionID[kMaxpfsubjetsSoftDrop04#0];   //[pfsubjetsSoftDrop04#0_]
   Int_t           pfjets08_;
   Float_t         pfjets08_core_area[kMaxpfjets08];   //[pfjets08_]
   UInt_t          pfjets08_core_bits[kMaxpfjets08];   //[pfjets08_]
   Float_t         pfjets08_core_p4_mass[kMaxpfjets08];   //[pfjets08_]
   Float_t         pfjets08_core_p4_px[kMaxpfjets08];   //[pfjets08_]
   Float_t         pfjets08_core_p4_py[kMaxpfjets08];   //[pfjets08_]
   Float_t         pfjets08_core_p4_pz[kMaxpfjets08];   //[pfjets08_]
   UInt_t          pfjets08_particles_begin[kMaxpfjets08];   //[pfjets08_]
   UInt_t          pfjets08_particles_end[kMaxpfjets08];   //[pfjets08_]
   Int_t           pfjets08#0_;
   Int_t           pfjets08#0_index[kMaxpfjets08#0];   //[pfjets08#0_]
   Int_t           pfjets08#0_collectionID[kMaxpfjets08#0];   //[pfjets08#0_]
   Int_t           pfjetsFlavor08_;
   Float_t         pfjetsFlavor08_tag[kMaxpfjetsFlavor08];   //[pfjetsFlavor08_]
   Int_t           pfjetsFlavor08#0_;
   Int_t           pfjetsFlavor08#0_index[kMaxpfjetsFlavor08#0];   //[pfjetsFlavor08#0_]
   Int_t           pfjetsFlavor08#0_collectionID[kMaxpfjetsFlavor08#0];   //[pfjetsFlavor08#0_]
   Int_t           pfbTags08_;
   Float_t         pfbTags08_tag[kMaxpfbTags08];   //[pfbTags08_]
   Int_t           pfbTags08#0_;
   Int_t           pfbTags08#0_index[kMaxpfbTags08#0];   //[pfbTags08#0_]
   Int_t           pfbTags08#0_collectionID[kMaxpfbTags08#0];   //[pfbTags08#0_]
   Int_t           pfcTags08_;
   Float_t         pfcTags08_tag[kMaxpfcTags08];   //[pfcTags08_]
   Int_t           pfcTags08#0_;
   Int_t           pfcTags08#0_index[kMaxpfcTags08#0];   //[pfcTags08#0_]
   Int_t           pfcTags08#0_collectionID[kMaxpfcTags08#0];   //[pfcTags08#0_]
   Int_t           pftauTags08_;
   Float_t         pftauTags08_tag[kMaxpftauTags08];   //[pftauTags08_]
   Int_t           pftauTags08#0_;
   Int_t           pftauTags08#0_index[kMaxpftauTags08#0];   //[pftauTags08#0_]
   Int_t           pftauTags08#0_collectionID[kMaxpftauTags08#0];   //[pftauTags08#0_]
   Int_t           pfjetParts08_;
   UInt_t          pfjetParts08_core_bits[kMaxpfjetParts08];   //[pfjetParts08_]
   Int_t           pfjetParts08_core_charge[kMaxpfjetParts08];   //[pfjetParts08_]
   Float_t         pfjetParts08_core_p4_mass[kMaxpfjetParts08];   //[pfjetParts08_]
   Float_t         pfjetParts08_core_p4_px[kMaxpfjetParts08];   //[pfjetParts08_]
   Float_t         pfjetParts08_core_p4_py[kMaxpfjetParts08];   //[pfjetParts08_]
   Float_t         pfjetParts08_core_p4_pz[kMaxpfjetParts08];   //[pfjetParts08_]
   Int_t           pfjetParts08_core_pdgId[kMaxpfjetParts08];   //[pfjetParts08_]
   UInt_t          pfjetParts08_core_status[kMaxpfjetParts08];   //[pfjetParts08_]
   Float_t         pfjetParts08_core_vertex_x[kMaxpfjetParts08];   //[pfjetParts08_]
   Float_t         pfjetParts08_core_vertex_y[kMaxpfjetParts08];   //[pfjetParts08_]
   Float_t         pfjetParts08_core_vertex_z[kMaxpfjetParts08];   //[pfjetParts08_]
   UInt_t          pfjetParts08_tracks_begin[kMaxpfjetParts08];   //[pfjetParts08_]
   UInt_t          pfjetParts08_tracks_end[kMaxpfjetParts08];   //[pfjetParts08_]
   UInt_t          pfjetParts08_clusters_begin[kMaxpfjetParts08];   //[pfjetParts08_]
   UInt_t          pfjetParts08_clusters_end[kMaxpfjetParts08];   //[pfjetParts08_]
   Int_t           pfjetParts08#0_;
   Int_t           pfjetParts08#0_index[kMaxpfjetParts08#0];   //[pfjetParts08#0_]
   Int_t           pfjetParts08#0_collectionID[kMaxpfjetParts08#0];   //[pfjetParts08#0_]
   Int_t           pfjetParts08#1_;
   Int_t           pfjetParts08#1_index[kMaxpfjetParts08#1];   //[pfjetParts08#1_]
   Int_t           pfjetParts08#1_collectionID[kMaxpfjetParts08#1];   //[pfjetParts08#1_]
   Int_t           pfjetsOneSubJettiness08_;
   Float_t         pfjetsOneSubJettiness08_tag[kMaxpfjetsOneSubJettiness08];   //[pfjetsOneSubJettiness08_]
   Int_t           pfjetsOneSubJettiness08#0_;
   Int_t           pfjetsOneSubJettiness08#0_index[kMaxpfjetsOneSubJettiness08#0];   //[pfjetsOneSubJettiness08#0_]
   Int_t           pfjetsOneSubJettiness08#0_collectionID[kMaxpfjetsOneSubJettiness08#0];   //[pfjetsOneSubJettiness08#0_]
   Int_t           pfjetsTwoSubJettiness08_;
   Float_t         pfjetsTwoSubJettiness08_tag[kMaxpfjetsTwoSubJettiness08];   //[pfjetsTwoSubJettiness08_]
   Int_t           pfjetsTwoSubJettiness08#0_;
   Int_t           pfjetsTwoSubJettiness08#0_index[kMaxpfjetsTwoSubJettiness08#0];   //[pfjetsTwoSubJettiness08#0_]
   Int_t           pfjetsTwoSubJettiness08#0_collectionID[kMaxpfjetsTwoSubJettiness08#0];   //[pfjetsTwoSubJettiness08#0_]
   Int_t           pfjetsThreeSubJettiness08_;
   Float_t         pfjetsThreeSubJettiness08_tag[kMaxpfjetsThreeSubJettiness08];   //[pfjetsThreeSubJettiness08_]
   Int_t           pfjetsThreeSubJettiness08#0_;
   Int_t           pfjetsThreeSubJettiness08#0_index[kMaxpfjetsThreeSubJettiness08#0];   //[pfjetsThreeSubJettiness08#0_]
   Int_t           pfjetsThreeSubJettiness08#0_collectionID[kMaxpfjetsThreeSubJettiness08#0];   //[pfjetsThreeSubJettiness08#0_]
   Int_t           pfsubjetsTrimmingTagged08_;
   UInt_t          pfsubjetsTrimmingTagged08_subjets_begin[kMaxpfsubjetsTrimmingTagged08];   //[pfsubjetsTrimmingTagged08_]
   UInt_t          pfsubjetsTrimmingTagged08_subjets_end[kMaxpfsubjetsTrimmingTagged08];   //[pfsubjetsTrimmingTagged08_]
   Int_t           pfsubjetsTrimmingTagged08#0_;
   Int_t           pfsubjetsTrimmingTagged08#0_index[kMaxpfsubjetsTrimmingTagged08#0];   //[pfsubjetsTrimmingTagged08#0_]
   Int_t           pfsubjetsTrimmingTagged08#0_collectionID[kMaxpfsubjetsTrimmingTagged08#0];   //[pfsubjetsTrimmingTagged08#0_]
   Int_t           pfsubjetsTrimmingTagged08#1_;
   Int_t           pfsubjetsTrimmingTagged08#1_index[kMaxpfsubjetsTrimmingTagged08#1];   //[pfsubjetsTrimmingTagged08#1_]
   Int_t           pfsubjetsTrimmingTagged08#1_collectionID[kMaxpfsubjetsTrimmingTagged08#1];   //[pfsubjetsTrimmingTagged08#1_]
   Int_t           pfsubjetsPruningTagged08_;
   UInt_t          pfsubjetsPruningTagged08_subjets_begin[kMaxpfsubjetsPruningTagged08];   //[pfsubjetsPruningTagged08_]
   UInt_t          pfsubjetsPruningTagged08_subjets_end[kMaxpfsubjetsPruningTagged08];   //[pfsubjetsPruningTagged08_]
   Int_t           pfsubjetsPruningTagged08#0_;
   Int_t           pfsubjetsPruningTagged08#0_index[kMaxpfsubjetsPruningTagged08#0];   //[pfsubjetsPruningTagged08#0_]
   Int_t           pfsubjetsPruningTagged08#0_collectionID[kMaxpfsubjetsPruningTagged08#0];   //[pfsubjetsPruningTagged08#0_]
   Int_t           pfsubjetsPruningTagged08#1_;
   Int_t           pfsubjetsPruningTagged08#1_index[kMaxpfsubjetsPruningTagged08#1];   //[pfsubjetsPruningTagged08#1_]
   Int_t           pfsubjetsPruningTagged08#1_collectionID[kMaxpfsubjetsPruningTagged08#1];   //[pfsubjetsPruningTagged08#1_]
   Int_t           pfsubjetsSoftDropTagged08_;
   UInt_t          pfsubjetsSoftDropTagged08_subjets_begin[kMaxpfsubjetsSoftDropTagged08];   //[pfsubjetsSoftDropTagged08_]
   UInt_t          pfsubjetsSoftDropTagged08_subjets_end[kMaxpfsubjetsSoftDropTagged08];   //[pfsubjetsSoftDropTagged08_]
   Int_t           pfsubjetsSoftDropTagged08#0_;
   Int_t           pfsubjetsSoftDropTagged08#0_index[kMaxpfsubjetsSoftDropTagged08#0];   //[pfsubjetsSoftDropTagged08#0_]
   Int_t           pfsubjetsSoftDropTagged08#0_collectionID[kMaxpfsubjetsSoftDropTagged08#0];   //[pfsubjetsSoftDropTagged08#0_]
   Int_t           pfsubjetsSoftDropTagged08#1_;
   Int_t           pfsubjetsSoftDropTagged08#1_index[kMaxpfsubjetsSoftDropTagged08#1];   //[pfsubjetsSoftDropTagged08#1_]
   Int_t           pfsubjetsSoftDropTagged08#1_collectionID[kMaxpfsubjetsSoftDropTagged08#1];   //[pfsubjetsSoftDropTagged08#1_]
   Int_t           pfsubjetsTrimming08_;
   Float_t         pfsubjetsTrimming08_core_area[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   UInt_t          pfsubjetsTrimming08_core_bits[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   Float_t         pfsubjetsTrimming08_core_p4_mass[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   Float_t         pfsubjetsTrimming08_core_p4_px[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   Float_t         pfsubjetsTrimming08_core_p4_py[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   Float_t         pfsubjetsTrimming08_core_p4_pz[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   UInt_t          pfsubjetsTrimming08_particles_begin[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   UInt_t          pfsubjetsTrimming08_particles_end[kMaxpfsubjetsTrimming08];   //[pfsubjetsTrimming08_]
   Int_t           pfsubjetsTrimming08#0_;
   Int_t           pfsubjetsTrimming08#0_index[kMaxpfsubjetsTrimming08#0];   //[pfsubjetsTrimming08#0_]
   Int_t           pfsubjetsTrimming08#0_collectionID[kMaxpfsubjetsTrimming08#0];   //[pfsubjetsTrimming08#0_]
   Int_t           pfsubjetsPruning08_;
   Float_t         pfsubjetsPruning08_core_area[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   UInt_t          pfsubjetsPruning08_core_bits[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   Float_t         pfsubjetsPruning08_core_p4_mass[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   Float_t         pfsubjetsPruning08_core_p4_px[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   Float_t         pfsubjetsPruning08_core_p4_py[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   Float_t         pfsubjetsPruning08_core_p4_pz[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   UInt_t          pfsubjetsPruning08_particles_begin[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   UInt_t          pfsubjetsPruning08_particles_end[kMaxpfsubjetsPruning08];   //[pfsubjetsPruning08_]
   Int_t           pfsubjetsPruning08#0_;
   Int_t           pfsubjetsPruning08#0_index[kMaxpfsubjetsPruning08#0];   //[pfsubjetsPruning08#0_]
   Int_t           pfsubjetsPruning08#0_collectionID[kMaxpfsubjetsPruning08#0];   //[pfsubjetsPruning08#0_]
   Int_t           pfsubjetsSoftDrop08_;
   Float_t         pfsubjetsSoftDrop08_core_area[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   UInt_t          pfsubjetsSoftDrop08_core_bits[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   Float_t         pfsubjetsSoftDrop08_core_p4_mass[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   Float_t         pfsubjetsSoftDrop08_core_p4_px[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   Float_t         pfsubjetsSoftDrop08_core_p4_py[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   Float_t         pfsubjetsSoftDrop08_core_p4_pz[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   UInt_t          pfsubjetsSoftDrop08_particles_begin[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   UInt_t          pfsubjetsSoftDrop08_particles_end[kMaxpfsubjetsSoftDrop08];   //[pfsubjetsSoftDrop08_]
   Int_t           pfsubjetsSoftDrop08#0_;
   Int_t           pfsubjetsSoftDrop08#0_index[kMaxpfsubjetsSoftDrop08#0];   //[pfsubjetsSoftDrop08#0_]
   Int_t           pfsubjetsSoftDrop08#0_collectionID[kMaxpfsubjetsSoftDrop08#0];   //[pfsubjetsSoftDrop08#0_]
   Int_t           pfjets15_;
   Float_t         pfjets15_core_area[kMaxpfjets15];   //[pfjets15_]
   UInt_t          pfjets15_core_bits[kMaxpfjets15];   //[pfjets15_]
   Float_t         pfjets15_core_p4_mass[kMaxpfjets15];   //[pfjets15_]
   Float_t         pfjets15_core_p4_px[kMaxpfjets15];   //[pfjets15_]
   Float_t         pfjets15_core_p4_py[kMaxpfjets15];   //[pfjets15_]
   Float_t         pfjets15_core_p4_pz[kMaxpfjets15];   //[pfjets15_]
   UInt_t          pfjets15_particles_begin[kMaxpfjets15];   //[pfjets15_]
   UInt_t          pfjets15_particles_end[kMaxpfjets15];   //[pfjets15_]
   Int_t           pfjets15#0_;
   Int_t           pfjets15#0_index[kMaxpfjets15#0];   //[pfjets15#0_]
   Int_t           pfjets15#0_collectionID[kMaxpfjets15#0];   //[pfjets15#0_]
   Int_t           pfjetsFlavor15_;
   Float_t         pfjetsFlavor15_tag[kMaxpfjetsFlavor15];   //[pfjetsFlavor15_]
   Int_t           pfjetsFlavor15#0_;
   Int_t           pfjetsFlavor15#0_index[kMaxpfjetsFlavor15#0];   //[pfjetsFlavor15#0_]
   Int_t           pfjetsFlavor15#0_collectionID[kMaxpfjetsFlavor15#0];   //[pfjetsFlavor15#0_]
   Int_t           pfbTags15_;
   Float_t         pfbTags15_tag[kMaxpfbTags15];   //[pfbTags15_]
   Int_t           pfbTags15#0_;
   Int_t           pfbTags15#0_index[kMaxpfbTags15#0];   //[pfbTags15#0_]
   Int_t           pfbTags15#0_collectionID[kMaxpfbTags15#0];   //[pfbTags15#0_]
   Int_t           pfcTags15_;
   Float_t         pfcTags15_tag[kMaxpfcTags15];   //[pfcTags15_]
   Int_t           pfcTags15#0_;
   Int_t           pfcTags15#0_index[kMaxpfcTags15#0];   //[pfcTags15#0_]
   Int_t           pfcTags15#0_collectionID[kMaxpfcTags15#0];   //[pfcTags15#0_]
   Int_t           pftauTags15_;
   Float_t         pftauTags15_tag[kMaxpftauTags15];   //[pftauTags15_]
   Int_t           pftauTags15#0_;
   Int_t           pftauTags15#0_index[kMaxpftauTags15#0];   //[pftauTags15#0_]
   Int_t           pftauTags15#0_collectionID[kMaxpftauTags15#0];   //[pftauTags15#0_]
   Int_t           pfjetParts15_;
   UInt_t          pfjetParts15_core_bits[kMaxpfjetParts15];   //[pfjetParts15_]
   Int_t           pfjetParts15_core_charge[kMaxpfjetParts15];   //[pfjetParts15_]
   Float_t         pfjetParts15_core_p4_mass[kMaxpfjetParts15];   //[pfjetParts15_]
   Float_t         pfjetParts15_core_p4_px[kMaxpfjetParts15];   //[pfjetParts15_]
   Float_t         pfjetParts15_core_p4_py[kMaxpfjetParts15];   //[pfjetParts15_]
   Float_t         pfjetParts15_core_p4_pz[kMaxpfjetParts15];   //[pfjetParts15_]
   Int_t           pfjetParts15_core_pdgId[kMaxpfjetParts15];   //[pfjetParts15_]
   UInt_t          pfjetParts15_core_status[kMaxpfjetParts15];   //[pfjetParts15_]
   Float_t         pfjetParts15_core_vertex_x[kMaxpfjetParts15];   //[pfjetParts15_]
   Float_t         pfjetParts15_core_vertex_y[kMaxpfjetParts15];   //[pfjetParts15_]
   Float_t         pfjetParts15_core_vertex_z[kMaxpfjetParts15];   //[pfjetParts15_]
   UInt_t          pfjetParts15_tracks_begin[kMaxpfjetParts15];   //[pfjetParts15_]
   UInt_t          pfjetParts15_tracks_end[kMaxpfjetParts15];   //[pfjetParts15_]
   UInt_t          pfjetParts15_clusters_begin[kMaxpfjetParts15];   //[pfjetParts15_]
   UInt_t          pfjetParts15_clusters_end[kMaxpfjetParts15];   //[pfjetParts15_]
   Int_t           pfjetParts15#0_;
   Int_t           pfjetParts15#0_index[kMaxpfjetParts15#0];   //[pfjetParts15#0_]
   Int_t           pfjetParts15#0_collectionID[kMaxpfjetParts15#0];   //[pfjetParts15#0_]
   Int_t           pfjetParts15#1_;
   Int_t           pfjetParts15#1_index[kMaxpfjetParts15#1];   //[pfjetParts15#1_]
   Int_t           pfjetParts15#1_collectionID[kMaxpfjetParts15#1];   //[pfjetParts15#1_]
   Int_t           pfjetsOneSubJettiness15_;
   Float_t         pfjetsOneSubJettiness15_tag[kMaxpfjetsOneSubJettiness15];   //[pfjetsOneSubJettiness15_]
   Int_t           pfjetsOneSubJettiness15#0_;
   Int_t           pfjetsOneSubJettiness15#0_index[kMaxpfjetsOneSubJettiness15#0];   //[pfjetsOneSubJettiness15#0_]
   Int_t           pfjetsOneSubJettiness15#0_collectionID[kMaxpfjetsOneSubJettiness15#0];   //[pfjetsOneSubJettiness15#0_]
   Int_t           pfjetsTwoSubJettiness15_;
   Float_t         pfjetsTwoSubJettiness15_tag[kMaxpfjetsTwoSubJettiness15];   //[pfjetsTwoSubJettiness15_]
   Int_t           pfjetsTwoSubJettiness15#0_;
   Int_t           pfjetsTwoSubJettiness15#0_index[kMaxpfjetsTwoSubJettiness15#0];   //[pfjetsTwoSubJettiness15#0_]
   Int_t           pfjetsTwoSubJettiness15#0_collectionID[kMaxpfjetsTwoSubJettiness15#0];   //[pfjetsTwoSubJettiness15#0_]
   Int_t           pfjetsThreeSubJettiness15_;
   Float_t         pfjetsThreeSubJettiness15_tag[kMaxpfjetsThreeSubJettiness15];   //[pfjetsThreeSubJettiness15_]
   Int_t           pfjetsThreeSubJettiness15#0_;
   Int_t           pfjetsThreeSubJettiness15#0_index[kMaxpfjetsThreeSubJettiness15#0];   //[pfjetsThreeSubJettiness15#0_]
   Int_t           pfjetsThreeSubJettiness15#0_collectionID[kMaxpfjetsThreeSubJettiness15#0];   //[pfjetsThreeSubJettiness15#0_]
   Int_t           pfsubjetsTrimmingTagged15_;
   UInt_t          pfsubjetsTrimmingTagged15_subjets_begin[kMaxpfsubjetsTrimmingTagged15];   //[pfsubjetsTrimmingTagged15_]
   UInt_t          pfsubjetsTrimmingTagged15_subjets_end[kMaxpfsubjetsTrimmingTagged15];   //[pfsubjetsTrimmingTagged15_]
   Int_t           pfsubjetsTrimmingTagged15#0_;
   Int_t           pfsubjetsTrimmingTagged15#0_index[kMaxpfsubjetsTrimmingTagged15#0];   //[pfsubjetsTrimmingTagged15#0_]
   Int_t           pfsubjetsTrimmingTagged15#0_collectionID[kMaxpfsubjetsTrimmingTagged15#0];   //[pfsubjetsTrimmingTagged15#0_]
   Int_t           pfsubjetsTrimmingTagged15#1_;
   Int_t           pfsubjetsTrimmingTagged15#1_index[kMaxpfsubjetsTrimmingTagged15#1];   //[pfsubjetsTrimmingTagged15#1_]
   Int_t           pfsubjetsTrimmingTagged15#1_collectionID[kMaxpfsubjetsTrimmingTagged15#1];   //[pfsubjetsTrimmingTagged15#1_]
   Int_t           pfsubjetsPruningTagged15_;
   UInt_t          pfsubjetsPruningTagged15_subjets_begin[kMaxpfsubjetsPruningTagged15];   //[pfsubjetsPruningTagged15_]
   UInt_t          pfsubjetsPruningTagged15_subjets_end[kMaxpfsubjetsPruningTagged15];   //[pfsubjetsPruningTagged15_]
   Int_t           pfsubjetsPruningTagged15#0_;
   Int_t           pfsubjetsPruningTagged15#0_index[kMaxpfsubjetsPruningTagged15#0];   //[pfsubjetsPruningTagged15#0_]
   Int_t           pfsubjetsPruningTagged15#0_collectionID[kMaxpfsubjetsPruningTagged15#0];   //[pfsubjetsPruningTagged15#0_]
   Int_t           pfsubjetsPruningTagged15#1_;
   Int_t           pfsubjetsPruningTagged15#1_index[kMaxpfsubjetsPruningTagged15#1];   //[pfsubjetsPruningTagged15#1_]
   Int_t           pfsubjetsPruningTagged15#1_collectionID[kMaxpfsubjetsPruningTagged15#1];   //[pfsubjetsPruningTagged15#1_]
   Int_t           pfsubjetsSoftDropTagged15_;
   UInt_t          pfsubjetsSoftDropTagged15_subjets_begin[kMaxpfsubjetsSoftDropTagged15];   //[pfsubjetsSoftDropTagged15_]
   UInt_t          pfsubjetsSoftDropTagged15_subjets_end[kMaxpfsubjetsSoftDropTagged15];   //[pfsubjetsSoftDropTagged15_]
   Int_t           pfsubjetsSoftDropTagged15#0_;
   Int_t           pfsubjetsSoftDropTagged15#0_index[kMaxpfsubjetsSoftDropTagged15#0];   //[pfsubjetsSoftDropTagged15#0_]
   Int_t           pfsubjetsSoftDropTagged15#0_collectionID[kMaxpfsubjetsSoftDropTagged15#0];   //[pfsubjetsSoftDropTagged15#0_]
   Int_t           pfsubjetsSoftDropTagged15#1_;
   Int_t           pfsubjetsSoftDropTagged15#1_index[kMaxpfsubjetsSoftDropTagged15#1];   //[pfsubjetsSoftDropTagged15#1_]
   Int_t           pfsubjetsSoftDropTagged15#1_collectionID[kMaxpfsubjetsSoftDropTagged15#1];   //[pfsubjetsSoftDropTagged15#1_]
   Int_t           pfsubjetsTrimming15_;
   Float_t         pfsubjetsTrimming15_core_area[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   UInt_t          pfsubjetsTrimming15_core_bits[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   Float_t         pfsubjetsTrimming15_core_p4_mass[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   Float_t         pfsubjetsTrimming15_core_p4_px[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   Float_t         pfsubjetsTrimming15_core_p4_py[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   Float_t         pfsubjetsTrimming15_core_p4_pz[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   UInt_t          pfsubjetsTrimming15_particles_begin[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   UInt_t          pfsubjetsTrimming15_particles_end[kMaxpfsubjetsTrimming15];   //[pfsubjetsTrimming15_]
   Int_t           pfsubjetsTrimming15#0_;
   Int_t           pfsubjetsTrimming15#0_index[kMaxpfsubjetsTrimming15#0];   //[pfsubjetsTrimming15#0_]
   Int_t           pfsubjetsTrimming15#0_collectionID[kMaxpfsubjetsTrimming15#0];   //[pfsubjetsTrimming15#0_]
   Int_t           pfsubjetsPruning15_;
   Float_t         pfsubjetsPruning15_core_area[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   UInt_t          pfsubjetsPruning15_core_bits[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   Float_t         pfsubjetsPruning15_core_p4_mass[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   Float_t         pfsubjetsPruning15_core_p4_px[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   Float_t         pfsubjetsPruning15_core_p4_py[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   Float_t         pfsubjetsPruning15_core_p4_pz[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   UInt_t          pfsubjetsPruning15_particles_begin[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   UInt_t          pfsubjetsPruning15_particles_end[kMaxpfsubjetsPruning15];   //[pfsubjetsPruning15_]
   Int_t           pfsubjetsPruning15#0_;
   Int_t           pfsubjetsPruning15#0_index[kMaxpfsubjetsPruning15#0];   //[pfsubjetsPruning15#0_]
   Int_t           pfsubjetsPruning15#0_collectionID[kMaxpfsubjetsPruning15#0];   //[pfsubjetsPruning15#0_]
   Int_t           pfsubjetsSoftDrop15_;
   Float_t         pfsubjetsSoftDrop15_core_area[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   UInt_t          pfsubjetsSoftDrop15_core_bits[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   Float_t         pfsubjetsSoftDrop15_core_p4_mass[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   Float_t         pfsubjetsSoftDrop15_core_p4_px[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   Float_t         pfsubjetsSoftDrop15_core_p4_py[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   Float_t         pfsubjetsSoftDrop15_core_p4_pz[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   UInt_t          pfsubjetsSoftDrop15_particles_begin[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   UInt_t          pfsubjetsSoftDrop15_particles_end[kMaxpfsubjetsSoftDrop15];   //[pfsubjetsSoftDrop15_]
   Int_t           pfsubjetsSoftDrop15#0_;
   Int_t           pfsubjetsSoftDrop15#0_index[kMaxpfsubjetsSoftDrop15#0];   //[pfsubjetsSoftDrop15#0_]
   Int_t           pfsubjetsSoftDrop15#0_collectionID[kMaxpfsubjetsSoftDrop15#0];   //[pfsubjetsSoftDrop15#0_]
   Int_t           trkjets02_;
   Float_t         trkjets02_core_area[kMaxtrkjets02];   //[trkjets02_]
   UInt_t          trkjets02_core_bits[kMaxtrkjets02];   //[trkjets02_]
   Float_t         trkjets02_core_p4_mass[kMaxtrkjets02];   //[trkjets02_]
   Float_t         trkjets02_core_p4_px[kMaxtrkjets02];   //[trkjets02_]
   Float_t         trkjets02_core_p4_py[kMaxtrkjets02];   //[trkjets02_]
   Float_t         trkjets02_core_p4_pz[kMaxtrkjets02];   //[trkjets02_]
   UInt_t          trkjets02_particles_begin[kMaxtrkjets02];   //[trkjets02_]
   UInt_t          trkjets02_particles_end[kMaxtrkjets02];   //[trkjets02_]
   Int_t           trkjets02#0_;
   Int_t           trkjets02#0_index[kMaxtrkjets02#0];   //[trkjets02#0_]
   Int_t           trkjets02#0_collectionID[kMaxtrkjets02#0];   //[trkjets02#0_]
   Int_t           trkjetsFlavor02_;
   Float_t         trkjetsFlavor02_tag[kMaxtrkjetsFlavor02];   //[trkjetsFlavor02_]
   Int_t           trkjetsFlavor02#0_;
   Int_t           trkjetsFlavor02#0_index[kMaxtrkjetsFlavor02#0];   //[trkjetsFlavor02#0_]
   Int_t           trkjetsFlavor02#0_collectionID[kMaxtrkjetsFlavor02#0];   //[trkjetsFlavor02#0_]
   Int_t           trkbTags02_;
   Float_t         trkbTags02_tag[kMaxtrkbTags02];   //[trkbTags02_]
   Int_t           trkbTags02#0_;
   Int_t           trkbTags02#0_index[kMaxtrkbTags02#0];   //[trkbTags02#0_]
   Int_t           trkbTags02#0_collectionID[kMaxtrkbTags02#0];   //[trkbTags02#0_]
   Int_t           trkcTags02_;
   Float_t         trkcTags02_tag[kMaxtrkcTags02];   //[trkcTags02_]
   Int_t           trkcTags02#0_;
   Int_t           trkcTags02#0_index[kMaxtrkcTags02#0];   //[trkcTags02#0_]
   Int_t           trkcTags02#0_collectionID[kMaxtrkcTags02#0];   //[trkcTags02#0_]
   Int_t           trktauTags02_;
   Float_t         trktauTags02_tag[kMaxtrktauTags02];   //[trktauTags02_]
   Int_t           trktauTags02#0_;
   Int_t           trktauTags02#0_index[kMaxtrktauTags02#0];   //[trktauTags02#0_]
   Int_t           trktauTags02#0_collectionID[kMaxtrktauTags02#0];   //[trktauTags02#0_]
   Int_t           trkjetParts02_;
   UInt_t          trkjetParts02_core_bits[kMaxtrkjetParts02];   //[trkjetParts02_]
   Int_t           trkjetParts02_core_charge[kMaxtrkjetParts02];   //[trkjetParts02_]
   Float_t         trkjetParts02_core_p4_mass[kMaxtrkjetParts02];   //[trkjetParts02_]
   Float_t         trkjetParts02_core_p4_px[kMaxtrkjetParts02];   //[trkjetParts02_]
   Float_t         trkjetParts02_core_p4_py[kMaxtrkjetParts02];   //[trkjetParts02_]
   Float_t         trkjetParts02_core_p4_pz[kMaxtrkjetParts02];   //[trkjetParts02_]
   Int_t           trkjetParts02_core_pdgId[kMaxtrkjetParts02];   //[trkjetParts02_]
   UInt_t          trkjetParts02_core_status[kMaxtrkjetParts02];   //[trkjetParts02_]
   Float_t         trkjetParts02_core_vertex_x[kMaxtrkjetParts02];   //[trkjetParts02_]
   Float_t         trkjetParts02_core_vertex_y[kMaxtrkjetParts02];   //[trkjetParts02_]
   Float_t         trkjetParts02_core_vertex_z[kMaxtrkjetParts02];   //[trkjetParts02_]
   UInt_t          trkjetParts02_tracks_begin[kMaxtrkjetParts02];   //[trkjetParts02_]
   UInt_t          trkjetParts02_tracks_end[kMaxtrkjetParts02];   //[trkjetParts02_]
   UInt_t          trkjetParts02_clusters_begin[kMaxtrkjetParts02];   //[trkjetParts02_]
   UInt_t          trkjetParts02_clusters_end[kMaxtrkjetParts02];   //[trkjetParts02_]
   Int_t           trkjetParts02#0_;
   Int_t           trkjetParts02#0_index[kMaxtrkjetParts02#0];   //[trkjetParts02#0_]
   Int_t           trkjetParts02#0_collectionID[kMaxtrkjetParts02#0];   //[trkjetParts02#0_]
   Int_t           trkjetParts02#1_;
   Int_t           trkjetParts02#1_index[kMaxtrkjetParts02#1];   //[trkjetParts02#1_]
   Int_t           trkjetParts02#1_collectionID[kMaxtrkjetParts02#1];   //[trkjetParts02#1_]
   Int_t           trkjetsOneSubJettiness02_;
   Float_t         trkjetsOneSubJettiness02_tag[kMaxtrkjetsOneSubJettiness02];   //[trkjetsOneSubJettiness02_]
   Int_t           trkjetsOneSubJettiness02#0_;
   Int_t           trkjetsOneSubJettiness02#0_index[kMaxtrkjetsOneSubJettiness02#0];   //[trkjetsOneSubJettiness02#0_]
   Int_t           trkjetsOneSubJettiness02#0_collectionID[kMaxtrkjetsOneSubJettiness02#0];   //[trkjetsOneSubJettiness02#0_]
   Int_t           trkjetsTwoSubJettiness02_;
   Float_t         trkjetsTwoSubJettiness02_tag[kMaxtrkjetsTwoSubJettiness02];   //[trkjetsTwoSubJettiness02_]
   Int_t           trkjetsTwoSubJettiness02#0_;
   Int_t           trkjetsTwoSubJettiness02#0_index[kMaxtrkjetsTwoSubJettiness02#0];   //[trkjetsTwoSubJettiness02#0_]
   Int_t           trkjetsTwoSubJettiness02#0_collectionID[kMaxtrkjetsTwoSubJettiness02#0];   //[trkjetsTwoSubJettiness02#0_]
   Int_t           trkjetsThreeSubJettiness02_;
   Float_t         trkjetsThreeSubJettiness02_tag[kMaxtrkjetsThreeSubJettiness02];   //[trkjetsThreeSubJettiness02_]
   Int_t           trkjetsThreeSubJettiness02#0_;
   Int_t           trkjetsThreeSubJettiness02#0_index[kMaxtrkjetsThreeSubJettiness02#0];   //[trkjetsThreeSubJettiness02#0_]
   Int_t           trkjetsThreeSubJettiness02#0_collectionID[kMaxtrkjetsThreeSubJettiness02#0];   //[trkjetsThreeSubJettiness02#0_]
   Int_t           trksubjetsTrimmingTagged02_;
   UInt_t          trksubjetsTrimmingTagged02_subjets_begin[kMaxtrksubjetsTrimmingTagged02];   //[trksubjetsTrimmingTagged02_]
   UInt_t          trksubjetsTrimmingTagged02_subjets_end[kMaxtrksubjetsTrimmingTagged02];   //[trksubjetsTrimmingTagged02_]
   Int_t           trksubjetsTrimmingTagged02#0_;
   Int_t           trksubjetsTrimmingTagged02#0_index[kMaxtrksubjetsTrimmingTagged02#0];   //[trksubjetsTrimmingTagged02#0_]
   Int_t           trksubjetsTrimmingTagged02#0_collectionID[kMaxtrksubjetsTrimmingTagged02#0];   //[trksubjetsTrimmingTagged02#0_]
   Int_t           trksubjetsTrimmingTagged02#1_;
   Int_t           trksubjetsTrimmingTagged02#1_index[kMaxtrksubjetsTrimmingTagged02#1];   //[trksubjetsTrimmingTagged02#1_]
   Int_t           trksubjetsTrimmingTagged02#1_collectionID[kMaxtrksubjetsTrimmingTagged02#1];   //[trksubjetsTrimmingTagged02#1_]
   Int_t           trksubjetsPruningTagged02_;
   UInt_t          trksubjetsPruningTagged02_subjets_begin[kMaxtrksubjetsPruningTagged02];   //[trksubjetsPruningTagged02_]
   UInt_t          trksubjetsPruningTagged02_subjets_end[kMaxtrksubjetsPruningTagged02];   //[trksubjetsPruningTagged02_]
   Int_t           trksubjetsPruningTagged02#0_;
   Int_t           trksubjetsPruningTagged02#0_index[kMaxtrksubjetsPruningTagged02#0];   //[trksubjetsPruningTagged02#0_]
   Int_t           trksubjetsPruningTagged02#0_collectionID[kMaxtrksubjetsPruningTagged02#0];   //[trksubjetsPruningTagged02#0_]
   Int_t           trksubjetsPruningTagged02#1_;
   Int_t           trksubjetsPruningTagged02#1_index[kMaxtrksubjetsPruningTagged02#1];   //[trksubjetsPruningTagged02#1_]
   Int_t           trksubjetsPruningTagged02#1_collectionID[kMaxtrksubjetsPruningTagged02#1];   //[trksubjetsPruningTagged02#1_]
   Int_t           trksubjetsSoftDropTagged02_;
   UInt_t          trksubjetsSoftDropTagged02_subjets_begin[kMaxtrksubjetsSoftDropTagged02];   //[trksubjetsSoftDropTagged02_]
   UInt_t          trksubjetsSoftDropTagged02_subjets_end[kMaxtrksubjetsSoftDropTagged02];   //[trksubjetsSoftDropTagged02_]
   Int_t           trksubjetsSoftDropTagged02#0_;
   Int_t           trksubjetsSoftDropTagged02#0_index[kMaxtrksubjetsSoftDropTagged02#0];   //[trksubjetsSoftDropTagged02#0_]
   Int_t           trksubjetsSoftDropTagged02#0_collectionID[kMaxtrksubjetsSoftDropTagged02#0];   //[trksubjetsSoftDropTagged02#0_]
   Int_t           trksubjetsSoftDropTagged02#1_;
   Int_t           trksubjetsSoftDropTagged02#1_index[kMaxtrksubjetsSoftDropTagged02#1];   //[trksubjetsSoftDropTagged02#1_]
   Int_t           trksubjetsSoftDropTagged02#1_collectionID[kMaxtrksubjetsSoftDropTagged02#1];   //[trksubjetsSoftDropTagged02#1_]
   Int_t           trksubjetsTrimming02_;
   Float_t         trksubjetsTrimming02_core_area[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   UInt_t          trksubjetsTrimming02_core_bits[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   Float_t         trksubjetsTrimming02_core_p4_mass[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   Float_t         trksubjetsTrimming02_core_p4_px[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   Float_t         trksubjetsTrimming02_core_p4_py[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   Float_t         trksubjetsTrimming02_core_p4_pz[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   UInt_t          trksubjetsTrimming02_particles_begin[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   UInt_t          trksubjetsTrimming02_particles_end[kMaxtrksubjetsTrimming02];   //[trksubjetsTrimming02_]
   Int_t           trksubjetsTrimming02#0_;
   Int_t           trksubjetsTrimming02#0_index[kMaxtrksubjetsTrimming02#0];   //[trksubjetsTrimming02#0_]
   Int_t           trksubjetsTrimming02#0_collectionID[kMaxtrksubjetsTrimming02#0];   //[trksubjetsTrimming02#0_]
   Int_t           trksubjetsPruning02_;
   Float_t         trksubjetsPruning02_core_area[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   UInt_t          trksubjetsPruning02_core_bits[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   Float_t         trksubjetsPruning02_core_p4_mass[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   Float_t         trksubjetsPruning02_core_p4_px[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   Float_t         trksubjetsPruning02_core_p4_py[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   Float_t         trksubjetsPruning02_core_p4_pz[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   UInt_t          trksubjetsPruning02_particles_begin[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   UInt_t          trksubjetsPruning02_particles_end[kMaxtrksubjetsPruning02];   //[trksubjetsPruning02_]
   Int_t           trksubjetsPruning02#0_;
   Int_t           trksubjetsPruning02#0_index[kMaxtrksubjetsPruning02#0];   //[trksubjetsPruning02#0_]
   Int_t           trksubjetsPruning02#0_collectionID[kMaxtrksubjetsPruning02#0];   //[trksubjetsPruning02#0_]
   Int_t           trksubjetsSoftDrop02_;
   Float_t         trksubjetsSoftDrop02_core_area[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   UInt_t          trksubjetsSoftDrop02_core_bits[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   Float_t         trksubjetsSoftDrop02_core_p4_mass[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   Float_t         trksubjetsSoftDrop02_core_p4_px[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   Float_t         trksubjetsSoftDrop02_core_p4_py[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   Float_t         trksubjetsSoftDrop02_core_p4_pz[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   UInt_t          trksubjetsSoftDrop02_particles_begin[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   UInt_t          trksubjetsSoftDrop02_particles_end[kMaxtrksubjetsSoftDrop02];   //[trksubjetsSoftDrop02_]
   Int_t           trksubjetsSoftDrop02#0_;
   Int_t           trksubjetsSoftDrop02#0_index[kMaxtrksubjetsSoftDrop02#0];   //[trksubjetsSoftDrop02#0_]
   Int_t           trksubjetsSoftDrop02#0_collectionID[kMaxtrksubjetsSoftDrop02#0];   //[trksubjetsSoftDrop02#0_]
   Int_t           trkjets04_;
   Float_t         trkjets04_core_area[kMaxtrkjets04];   //[trkjets04_]
   UInt_t          trkjets04_core_bits[kMaxtrkjets04];   //[trkjets04_]
   Float_t         trkjets04_core_p4_mass[kMaxtrkjets04];   //[trkjets04_]
   Float_t         trkjets04_core_p4_px[kMaxtrkjets04];   //[trkjets04_]
   Float_t         trkjets04_core_p4_py[kMaxtrkjets04];   //[trkjets04_]
   Float_t         trkjets04_core_p4_pz[kMaxtrkjets04];   //[trkjets04_]
   UInt_t          trkjets04_particles_begin[kMaxtrkjets04];   //[trkjets04_]
   UInt_t          trkjets04_particles_end[kMaxtrkjets04];   //[trkjets04_]
   Int_t           trkjets04#0_;
   Int_t           trkjets04#0_index[kMaxtrkjets04#0];   //[trkjets04#0_]
   Int_t           trkjets04#0_collectionID[kMaxtrkjets04#0];   //[trkjets04#0_]
   Int_t           trkjetsFlavor04_;
   Float_t         trkjetsFlavor04_tag[kMaxtrkjetsFlavor04];   //[trkjetsFlavor04_]
   Int_t           trkjetsFlavor04#0_;
   Int_t           trkjetsFlavor04#0_index[kMaxtrkjetsFlavor04#0];   //[trkjetsFlavor04#0_]
   Int_t           trkjetsFlavor04#0_collectionID[kMaxtrkjetsFlavor04#0];   //[trkjetsFlavor04#0_]
   Int_t           trkbTags04_;
   Float_t         trkbTags04_tag[kMaxtrkbTags04];   //[trkbTags04_]
   Int_t           trkbTags04#0_;
   Int_t           trkbTags04#0_index[kMaxtrkbTags04#0];   //[trkbTags04#0_]
   Int_t           trkbTags04#0_collectionID[kMaxtrkbTags04#0];   //[trkbTags04#0_]
   Int_t           trkcTags04_;
   Float_t         trkcTags04_tag[kMaxtrkcTags04];   //[trkcTags04_]
   Int_t           trkcTags04#0_;
   Int_t           trkcTags04#0_index[kMaxtrkcTags04#0];   //[trkcTags04#0_]
   Int_t           trkcTags04#0_collectionID[kMaxtrkcTags04#0];   //[trkcTags04#0_]
   Int_t           trktauTags04_;
   Float_t         trktauTags04_tag[kMaxtrktauTags04];   //[trktauTags04_]
   Int_t           trktauTags04#0_;
   Int_t           trktauTags04#0_index[kMaxtrktauTags04#0];   //[trktauTags04#0_]
   Int_t           trktauTags04#0_collectionID[kMaxtrktauTags04#0];   //[trktauTags04#0_]
   Int_t           trkjetParts04_;
   UInt_t          trkjetParts04_core_bits[kMaxtrkjetParts04];   //[trkjetParts04_]
   Int_t           trkjetParts04_core_charge[kMaxtrkjetParts04];   //[trkjetParts04_]
   Float_t         trkjetParts04_core_p4_mass[kMaxtrkjetParts04];   //[trkjetParts04_]
   Float_t         trkjetParts04_core_p4_px[kMaxtrkjetParts04];   //[trkjetParts04_]
   Float_t         trkjetParts04_core_p4_py[kMaxtrkjetParts04];   //[trkjetParts04_]
   Float_t         trkjetParts04_core_p4_pz[kMaxtrkjetParts04];   //[trkjetParts04_]
   Int_t           trkjetParts04_core_pdgId[kMaxtrkjetParts04];   //[trkjetParts04_]
   UInt_t          trkjetParts04_core_status[kMaxtrkjetParts04];   //[trkjetParts04_]
   Float_t         trkjetParts04_core_vertex_x[kMaxtrkjetParts04];   //[trkjetParts04_]
   Float_t         trkjetParts04_core_vertex_y[kMaxtrkjetParts04];   //[trkjetParts04_]
   Float_t         trkjetParts04_core_vertex_z[kMaxtrkjetParts04];   //[trkjetParts04_]
   UInt_t          trkjetParts04_tracks_begin[kMaxtrkjetParts04];   //[trkjetParts04_]
   UInt_t          trkjetParts04_tracks_end[kMaxtrkjetParts04];   //[trkjetParts04_]
   UInt_t          trkjetParts04_clusters_begin[kMaxtrkjetParts04];   //[trkjetParts04_]
   UInt_t          trkjetParts04_clusters_end[kMaxtrkjetParts04];   //[trkjetParts04_]
   Int_t           trkjetParts04#0_;
   Int_t           trkjetParts04#0_index[kMaxtrkjetParts04#0];   //[trkjetParts04#0_]
   Int_t           trkjetParts04#0_collectionID[kMaxtrkjetParts04#0];   //[trkjetParts04#0_]
   Int_t           trkjetParts04#1_;
   Int_t           trkjetParts04#1_index[kMaxtrkjetParts04#1];   //[trkjetParts04#1_]
   Int_t           trkjetParts04#1_collectionID[kMaxtrkjetParts04#1];   //[trkjetParts04#1_]
   Int_t           trkjetsOneSubJettiness04_;
   Float_t         trkjetsOneSubJettiness04_tag[kMaxtrkjetsOneSubJettiness04];   //[trkjetsOneSubJettiness04_]
   Int_t           trkjetsOneSubJettiness04#0_;
   Int_t           trkjetsOneSubJettiness04#0_index[kMaxtrkjetsOneSubJettiness04#0];   //[trkjetsOneSubJettiness04#0_]
   Int_t           trkjetsOneSubJettiness04#0_collectionID[kMaxtrkjetsOneSubJettiness04#0];   //[trkjetsOneSubJettiness04#0_]
   Int_t           trkjetsTwoSubJettiness04_;
   Float_t         trkjetsTwoSubJettiness04_tag[kMaxtrkjetsTwoSubJettiness04];   //[trkjetsTwoSubJettiness04_]
   Int_t           trkjetsTwoSubJettiness04#0_;
   Int_t           trkjetsTwoSubJettiness04#0_index[kMaxtrkjetsTwoSubJettiness04#0];   //[trkjetsTwoSubJettiness04#0_]
   Int_t           trkjetsTwoSubJettiness04#0_collectionID[kMaxtrkjetsTwoSubJettiness04#0];   //[trkjetsTwoSubJettiness04#0_]
   Int_t           trkjetsThreeSubJettiness04_;
   Float_t         trkjetsThreeSubJettiness04_tag[kMaxtrkjetsThreeSubJettiness04];   //[trkjetsThreeSubJettiness04_]
   Int_t           trkjetsThreeSubJettiness04#0_;
   Int_t           trkjetsThreeSubJettiness04#0_index[kMaxtrkjetsThreeSubJettiness04#0];   //[trkjetsThreeSubJettiness04#0_]
   Int_t           trkjetsThreeSubJettiness04#0_collectionID[kMaxtrkjetsThreeSubJettiness04#0];   //[trkjetsThreeSubJettiness04#0_]
   Int_t           trksubjetsTrimmingTagged04_;
   UInt_t          trksubjetsTrimmingTagged04_subjets_begin[kMaxtrksubjetsTrimmingTagged04];   //[trksubjetsTrimmingTagged04_]
   UInt_t          trksubjetsTrimmingTagged04_subjets_end[kMaxtrksubjetsTrimmingTagged04];   //[trksubjetsTrimmingTagged04_]
   Int_t           trksubjetsTrimmingTagged04#0_;
   Int_t           trksubjetsTrimmingTagged04#0_index[kMaxtrksubjetsTrimmingTagged04#0];   //[trksubjetsTrimmingTagged04#0_]
   Int_t           trksubjetsTrimmingTagged04#0_collectionID[kMaxtrksubjetsTrimmingTagged04#0];   //[trksubjetsTrimmingTagged04#0_]
   Int_t           trksubjetsTrimmingTagged04#1_;
   Int_t           trksubjetsTrimmingTagged04#1_index[kMaxtrksubjetsTrimmingTagged04#1];   //[trksubjetsTrimmingTagged04#1_]
   Int_t           trksubjetsTrimmingTagged04#1_collectionID[kMaxtrksubjetsTrimmingTagged04#1];   //[trksubjetsTrimmingTagged04#1_]
   Int_t           trksubjetsPruningTagged04_;
   UInt_t          trksubjetsPruningTagged04_subjets_begin[kMaxtrksubjetsPruningTagged04];   //[trksubjetsPruningTagged04_]
   UInt_t          trksubjetsPruningTagged04_subjets_end[kMaxtrksubjetsPruningTagged04];   //[trksubjetsPruningTagged04_]
   Int_t           trksubjetsPruningTagged04#0_;
   Int_t           trksubjetsPruningTagged04#0_index[kMaxtrksubjetsPruningTagged04#0];   //[trksubjetsPruningTagged04#0_]
   Int_t           trksubjetsPruningTagged04#0_collectionID[kMaxtrksubjetsPruningTagged04#0];   //[trksubjetsPruningTagged04#0_]
   Int_t           trksubjetsPruningTagged04#1_;
   Int_t           trksubjetsPruningTagged04#1_index[kMaxtrksubjetsPruningTagged04#1];   //[trksubjetsPruningTagged04#1_]
   Int_t           trksubjetsPruningTagged04#1_collectionID[kMaxtrksubjetsPruningTagged04#1];   //[trksubjetsPruningTagged04#1_]
   Int_t           trksubjetsSoftDropTagged04_;
   UInt_t          trksubjetsSoftDropTagged04_subjets_begin[kMaxtrksubjetsSoftDropTagged04];   //[trksubjetsSoftDropTagged04_]
   UInt_t          trksubjetsSoftDropTagged04_subjets_end[kMaxtrksubjetsSoftDropTagged04];   //[trksubjetsSoftDropTagged04_]
   Int_t           trksubjetsSoftDropTagged04#0_;
   Int_t           trksubjetsSoftDropTagged04#0_index[kMaxtrksubjetsSoftDropTagged04#0];   //[trksubjetsSoftDropTagged04#0_]
   Int_t           trksubjetsSoftDropTagged04#0_collectionID[kMaxtrksubjetsSoftDropTagged04#0];   //[trksubjetsSoftDropTagged04#0_]
   Int_t           trksubjetsSoftDropTagged04#1_;
   Int_t           trksubjetsSoftDropTagged04#1_index[kMaxtrksubjetsSoftDropTagged04#1];   //[trksubjetsSoftDropTagged04#1_]
   Int_t           trksubjetsSoftDropTagged04#1_collectionID[kMaxtrksubjetsSoftDropTagged04#1];   //[trksubjetsSoftDropTagged04#1_]
   Int_t           trksubjetsTrimming04_;
   Float_t         trksubjetsTrimming04_core_area[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   UInt_t          trksubjetsTrimming04_core_bits[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   Float_t         trksubjetsTrimming04_core_p4_mass[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   Float_t         trksubjetsTrimming04_core_p4_px[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   Float_t         trksubjetsTrimming04_core_p4_py[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   Float_t         trksubjetsTrimming04_core_p4_pz[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   UInt_t          trksubjetsTrimming04_particles_begin[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   UInt_t          trksubjetsTrimming04_particles_end[kMaxtrksubjetsTrimming04];   //[trksubjetsTrimming04_]
   Int_t           trksubjetsTrimming04#0_;
   Int_t           trksubjetsTrimming04#0_index[kMaxtrksubjetsTrimming04#0];   //[trksubjetsTrimming04#0_]
   Int_t           trksubjetsTrimming04#0_collectionID[kMaxtrksubjetsTrimming04#0];   //[trksubjetsTrimming04#0_]
   Int_t           trksubjetsPruning04_;
   Float_t         trksubjetsPruning04_core_area[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   UInt_t          trksubjetsPruning04_core_bits[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   Float_t         trksubjetsPruning04_core_p4_mass[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   Float_t         trksubjetsPruning04_core_p4_px[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   Float_t         trksubjetsPruning04_core_p4_py[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   Float_t         trksubjetsPruning04_core_p4_pz[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   UInt_t          trksubjetsPruning04_particles_begin[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   UInt_t          trksubjetsPruning04_particles_end[kMaxtrksubjetsPruning04];   //[trksubjetsPruning04_]
   Int_t           trksubjetsPruning04#0_;
   Int_t           trksubjetsPruning04#0_index[kMaxtrksubjetsPruning04#0];   //[trksubjetsPruning04#0_]
   Int_t           trksubjetsPruning04#0_collectionID[kMaxtrksubjetsPruning04#0];   //[trksubjetsPruning04#0_]
   Int_t           trksubjetsSoftDrop04_;
   Float_t         trksubjetsSoftDrop04_core_area[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   UInt_t          trksubjetsSoftDrop04_core_bits[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   Float_t         trksubjetsSoftDrop04_core_p4_mass[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   Float_t         trksubjetsSoftDrop04_core_p4_px[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   Float_t         trksubjetsSoftDrop04_core_p4_py[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   Float_t         trksubjetsSoftDrop04_core_p4_pz[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   UInt_t          trksubjetsSoftDrop04_particles_begin[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   UInt_t          trksubjetsSoftDrop04_particles_end[kMaxtrksubjetsSoftDrop04];   //[trksubjetsSoftDrop04_]
   Int_t           trksubjetsSoftDrop04#0_;
   Int_t           trksubjetsSoftDrop04#0_index[kMaxtrksubjetsSoftDrop04#0];   //[trksubjetsSoftDrop04#0_]
   Int_t           trksubjetsSoftDrop04#0_collectionID[kMaxtrksubjetsSoftDrop04#0];   //[trksubjetsSoftDrop04#0_]
   Int_t           trkjets08_;
   Float_t         trkjets08_core_area[kMaxtrkjets08];   //[trkjets08_]
   UInt_t          trkjets08_core_bits[kMaxtrkjets08];   //[trkjets08_]
   Float_t         trkjets08_core_p4_mass[kMaxtrkjets08];   //[trkjets08_]
   Float_t         trkjets08_core_p4_px[kMaxtrkjets08];   //[trkjets08_]
   Float_t         trkjets08_core_p4_py[kMaxtrkjets08];   //[trkjets08_]
   Float_t         trkjets08_core_p4_pz[kMaxtrkjets08];   //[trkjets08_]
   UInt_t          trkjets08_particles_begin[kMaxtrkjets08];   //[trkjets08_]
   UInt_t          trkjets08_particles_end[kMaxtrkjets08];   //[trkjets08_]
   Int_t           trkjets08#0_;
   Int_t           trkjets08#0_index[kMaxtrkjets08#0];   //[trkjets08#0_]
   Int_t           trkjets08#0_collectionID[kMaxtrkjets08#0];   //[trkjets08#0_]
   Int_t           trkjetsFlavor08_;
   Float_t         trkjetsFlavor08_tag[kMaxtrkjetsFlavor08];   //[trkjetsFlavor08_]
   Int_t           trkjetsFlavor08#0_;
   Int_t           trkjetsFlavor08#0_index[kMaxtrkjetsFlavor08#0];   //[trkjetsFlavor08#0_]
   Int_t           trkjetsFlavor08#0_collectionID[kMaxtrkjetsFlavor08#0];   //[trkjetsFlavor08#0_]
   Int_t           trkbTags08_;
   Float_t         trkbTags08_tag[kMaxtrkbTags08];   //[trkbTags08_]
   Int_t           trkbTags08#0_;
   Int_t           trkbTags08#0_index[kMaxtrkbTags08#0];   //[trkbTags08#0_]
   Int_t           trkbTags08#0_collectionID[kMaxtrkbTags08#0];   //[trkbTags08#0_]
   Int_t           trkcTags08_;
   Float_t         trkcTags08_tag[kMaxtrkcTags08];   //[trkcTags08_]
   Int_t           trkcTags08#0_;
   Int_t           trkcTags08#0_index[kMaxtrkcTags08#0];   //[trkcTags08#0_]
   Int_t           trkcTags08#0_collectionID[kMaxtrkcTags08#0];   //[trkcTags08#0_]
   Int_t           trktauTags08_;
   Float_t         trktauTags08_tag[kMaxtrktauTags08];   //[trktauTags08_]
   Int_t           trktauTags08#0_;
   Int_t           trktauTags08#0_index[kMaxtrktauTags08#0];   //[trktauTags08#0_]
   Int_t           trktauTags08#0_collectionID[kMaxtrktauTags08#0];   //[trktauTags08#0_]
   Int_t           trkjetParts08_;
   UInt_t          trkjetParts08_core_bits[kMaxtrkjetParts08];   //[trkjetParts08_]
   Int_t           trkjetParts08_core_charge[kMaxtrkjetParts08];   //[trkjetParts08_]
   Float_t         trkjetParts08_core_p4_mass[kMaxtrkjetParts08];   //[trkjetParts08_]
   Float_t         trkjetParts08_core_p4_px[kMaxtrkjetParts08];   //[trkjetParts08_]
   Float_t         trkjetParts08_core_p4_py[kMaxtrkjetParts08];   //[trkjetParts08_]
   Float_t         trkjetParts08_core_p4_pz[kMaxtrkjetParts08];   //[trkjetParts08_]
   Int_t           trkjetParts08_core_pdgId[kMaxtrkjetParts08];   //[trkjetParts08_]
   UInt_t          trkjetParts08_core_status[kMaxtrkjetParts08];   //[trkjetParts08_]
   Float_t         trkjetParts08_core_vertex_x[kMaxtrkjetParts08];   //[trkjetParts08_]
   Float_t         trkjetParts08_core_vertex_y[kMaxtrkjetParts08];   //[trkjetParts08_]
   Float_t         trkjetParts08_core_vertex_z[kMaxtrkjetParts08];   //[trkjetParts08_]
   UInt_t          trkjetParts08_tracks_begin[kMaxtrkjetParts08];   //[trkjetParts08_]
   UInt_t          trkjetParts08_tracks_end[kMaxtrkjetParts08];   //[trkjetParts08_]
   UInt_t          trkjetParts08_clusters_begin[kMaxtrkjetParts08];   //[trkjetParts08_]
   UInt_t          trkjetParts08_clusters_end[kMaxtrkjetParts08];   //[trkjetParts08_]
   Int_t           trkjetParts08#0_;
   Int_t           trkjetParts08#0_index[kMaxtrkjetParts08#0];   //[trkjetParts08#0_]
   Int_t           trkjetParts08#0_collectionID[kMaxtrkjetParts08#0];   //[trkjetParts08#0_]
   Int_t           trkjetParts08#1_;
   Int_t           trkjetParts08#1_index[kMaxtrkjetParts08#1];   //[trkjetParts08#1_]
   Int_t           trkjetParts08#1_collectionID[kMaxtrkjetParts08#1];   //[trkjetParts08#1_]
   Int_t           trkjetsOneSubJettiness08_;
   Float_t         trkjetsOneSubJettiness08_tag[kMaxtrkjetsOneSubJettiness08];   //[trkjetsOneSubJettiness08_]
   Int_t           trkjetsOneSubJettiness08#0_;
   Int_t           trkjetsOneSubJettiness08#0_index[kMaxtrkjetsOneSubJettiness08#0];   //[trkjetsOneSubJettiness08#0_]
   Int_t           trkjetsOneSubJettiness08#0_collectionID[kMaxtrkjetsOneSubJettiness08#0];   //[trkjetsOneSubJettiness08#0_]
   Int_t           trkjetsTwoSubJettiness08_;
   Float_t         trkjetsTwoSubJettiness08_tag[kMaxtrkjetsTwoSubJettiness08];   //[trkjetsTwoSubJettiness08_]
   Int_t           trkjetsTwoSubJettiness08#0_;
   Int_t           trkjetsTwoSubJettiness08#0_index[kMaxtrkjetsTwoSubJettiness08#0];   //[trkjetsTwoSubJettiness08#0_]
   Int_t           trkjetsTwoSubJettiness08#0_collectionID[kMaxtrkjetsTwoSubJettiness08#0];   //[trkjetsTwoSubJettiness08#0_]
   Int_t           trkjetsThreeSubJettiness08_;
   Float_t         trkjetsThreeSubJettiness08_tag[kMaxtrkjetsThreeSubJettiness08];   //[trkjetsThreeSubJettiness08_]
   Int_t           trkjetsThreeSubJettiness08#0_;
   Int_t           trkjetsThreeSubJettiness08#0_index[kMaxtrkjetsThreeSubJettiness08#0];   //[trkjetsThreeSubJettiness08#0_]
   Int_t           trkjetsThreeSubJettiness08#0_collectionID[kMaxtrkjetsThreeSubJettiness08#0];   //[trkjetsThreeSubJettiness08#0_]
   Int_t           trksubjetsTrimmingTagged08_;
   UInt_t          trksubjetsTrimmingTagged08_subjets_begin[kMaxtrksubjetsTrimmingTagged08];   //[trksubjetsTrimmingTagged08_]
   UInt_t          trksubjetsTrimmingTagged08_subjets_end[kMaxtrksubjetsTrimmingTagged08];   //[trksubjetsTrimmingTagged08_]
   Int_t           trksubjetsTrimmingTagged08#0_;
   Int_t           trksubjetsTrimmingTagged08#0_index[kMaxtrksubjetsTrimmingTagged08#0];   //[trksubjetsTrimmingTagged08#0_]
   Int_t           trksubjetsTrimmingTagged08#0_collectionID[kMaxtrksubjetsTrimmingTagged08#0];   //[trksubjetsTrimmingTagged08#0_]
   Int_t           trksubjetsTrimmingTagged08#1_;
   Int_t           trksubjetsTrimmingTagged08#1_index[kMaxtrksubjetsTrimmingTagged08#1];   //[trksubjetsTrimmingTagged08#1_]
   Int_t           trksubjetsTrimmingTagged08#1_collectionID[kMaxtrksubjetsTrimmingTagged08#1];   //[trksubjetsTrimmingTagged08#1_]
   Int_t           trksubjetsPruningTagged08_;
   UInt_t          trksubjetsPruningTagged08_subjets_begin[kMaxtrksubjetsPruningTagged08];   //[trksubjetsPruningTagged08_]
   UInt_t          trksubjetsPruningTagged08_subjets_end[kMaxtrksubjetsPruningTagged08];   //[trksubjetsPruningTagged08_]
   Int_t           trksubjetsPruningTagged08#0_;
   Int_t           trksubjetsPruningTagged08#0_index[kMaxtrksubjetsPruningTagged08#0];   //[trksubjetsPruningTagged08#0_]
   Int_t           trksubjetsPruningTagged08#0_collectionID[kMaxtrksubjetsPruningTagged08#0];   //[trksubjetsPruningTagged08#0_]
   Int_t           trksubjetsPruningTagged08#1_;
   Int_t           trksubjetsPruningTagged08#1_index[kMaxtrksubjetsPruningTagged08#1];   //[trksubjetsPruningTagged08#1_]
   Int_t           trksubjetsPruningTagged08#1_collectionID[kMaxtrksubjetsPruningTagged08#1];   //[trksubjetsPruningTagged08#1_]
   Int_t           trksubjetsSoftDropTagged08_;
   UInt_t          trksubjetsSoftDropTagged08_subjets_begin[kMaxtrksubjetsSoftDropTagged08];   //[trksubjetsSoftDropTagged08_]
   UInt_t          trksubjetsSoftDropTagged08_subjets_end[kMaxtrksubjetsSoftDropTagged08];   //[trksubjetsSoftDropTagged08_]
   Int_t           trksubjetsSoftDropTagged08#0_;
   Int_t           trksubjetsSoftDropTagged08#0_index[kMaxtrksubjetsSoftDropTagged08#0];   //[trksubjetsSoftDropTagged08#0_]
   Int_t           trksubjetsSoftDropTagged08#0_collectionID[kMaxtrksubjetsSoftDropTagged08#0];   //[trksubjetsSoftDropTagged08#0_]
   Int_t           trksubjetsSoftDropTagged08#1_;
   Int_t           trksubjetsSoftDropTagged08#1_index[kMaxtrksubjetsSoftDropTagged08#1];   //[trksubjetsSoftDropTagged08#1_]
   Int_t           trksubjetsSoftDropTagged08#1_collectionID[kMaxtrksubjetsSoftDropTagged08#1];   //[trksubjetsSoftDropTagged08#1_]
   Int_t           trksubjetsTrimming08_;
   Float_t         trksubjetsTrimming08_core_area[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   UInt_t          trksubjetsTrimming08_core_bits[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   Float_t         trksubjetsTrimming08_core_p4_mass[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   Float_t         trksubjetsTrimming08_core_p4_px[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   Float_t         trksubjetsTrimming08_core_p4_py[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   Float_t         trksubjetsTrimming08_core_p4_pz[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   UInt_t          trksubjetsTrimming08_particles_begin[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   UInt_t          trksubjetsTrimming08_particles_end[kMaxtrksubjetsTrimming08];   //[trksubjetsTrimming08_]
   Int_t           trksubjetsTrimming08#0_;
   Int_t           trksubjetsTrimming08#0_index[kMaxtrksubjetsTrimming08#0];   //[trksubjetsTrimming08#0_]
   Int_t           trksubjetsTrimming08#0_collectionID[kMaxtrksubjetsTrimming08#0];   //[trksubjetsTrimming08#0_]
   Int_t           trksubjetsPruning08_;
   Float_t         trksubjetsPruning08_core_area[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   UInt_t          trksubjetsPruning08_core_bits[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   Float_t         trksubjetsPruning08_core_p4_mass[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   Float_t         trksubjetsPruning08_core_p4_px[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   Float_t         trksubjetsPruning08_core_p4_py[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   Float_t         trksubjetsPruning08_core_p4_pz[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   UInt_t          trksubjetsPruning08_particles_begin[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   UInt_t          trksubjetsPruning08_particles_end[kMaxtrksubjetsPruning08];   //[trksubjetsPruning08_]
   Int_t           trksubjetsPruning08#0_;
   Int_t           trksubjetsPruning08#0_index[kMaxtrksubjetsPruning08#0];   //[trksubjetsPruning08#0_]
   Int_t           trksubjetsPruning08#0_collectionID[kMaxtrksubjetsPruning08#0];   //[trksubjetsPruning08#0_]
   Int_t           trksubjetsSoftDrop08_;
   Float_t         trksubjetsSoftDrop08_core_area[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   UInt_t          trksubjetsSoftDrop08_core_bits[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   Float_t         trksubjetsSoftDrop08_core_p4_mass[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   Float_t         trksubjetsSoftDrop08_core_p4_px[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   Float_t         trksubjetsSoftDrop08_core_p4_py[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   Float_t         trksubjetsSoftDrop08_core_p4_pz[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   UInt_t          trksubjetsSoftDrop08_particles_begin[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   UInt_t          trksubjetsSoftDrop08_particles_end[kMaxtrksubjetsSoftDrop08];   //[trksubjetsSoftDrop08_]
   Int_t           trksubjetsSoftDrop08#0_;
   Int_t           trksubjetsSoftDrop08#0_index[kMaxtrksubjetsSoftDrop08#0];   //[trksubjetsSoftDrop08#0_]
   Int_t           trksubjetsSoftDrop08#0_collectionID[kMaxtrksubjetsSoftDrop08#0];   //[trksubjetsSoftDrop08#0_]
   Int_t           trkjets15_;
   Float_t         trkjets15_core_area[kMaxtrkjets15];   //[trkjets15_]
   UInt_t          trkjets15_core_bits[kMaxtrkjets15];   //[trkjets15_]
   Float_t         trkjets15_core_p4_mass[kMaxtrkjets15];   //[trkjets15_]
   Float_t         trkjets15_core_p4_px[kMaxtrkjets15];   //[trkjets15_]
   Float_t         trkjets15_core_p4_py[kMaxtrkjets15];   //[trkjets15_]
   Float_t         trkjets15_core_p4_pz[kMaxtrkjets15];   //[trkjets15_]
   UInt_t          trkjets15_particles_begin[kMaxtrkjets15];   //[trkjets15_]
   UInt_t          trkjets15_particles_end[kMaxtrkjets15];   //[trkjets15_]
   Int_t           trkjets15#0_;
   Int_t           trkjets15#0_index[kMaxtrkjets15#0];   //[trkjets15#0_]
   Int_t           trkjets15#0_collectionID[kMaxtrkjets15#0];   //[trkjets15#0_]
   Int_t           trkjetsFlavor15_;
   Float_t         trkjetsFlavor15_tag[kMaxtrkjetsFlavor15];   //[trkjetsFlavor15_]
   Int_t           trkjetsFlavor15#0_;
   Int_t           trkjetsFlavor15#0_index[kMaxtrkjetsFlavor15#0];   //[trkjetsFlavor15#0_]
   Int_t           trkjetsFlavor15#0_collectionID[kMaxtrkjetsFlavor15#0];   //[trkjetsFlavor15#0_]
   Int_t           trkbTags15_;
   Float_t         trkbTags15_tag[kMaxtrkbTags15];   //[trkbTags15_]
   Int_t           trkbTags15#0_;
   Int_t           trkbTags15#0_index[kMaxtrkbTags15#0];   //[trkbTags15#0_]
   Int_t           trkbTags15#0_collectionID[kMaxtrkbTags15#0];   //[trkbTags15#0_]
   Int_t           trkcTags15_;
   Float_t         trkcTags15_tag[kMaxtrkcTags15];   //[trkcTags15_]
   Int_t           trkcTags15#0_;
   Int_t           trkcTags15#0_index[kMaxtrkcTags15#0];   //[trkcTags15#0_]
   Int_t           trkcTags15#0_collectionID[kMaxtrkcTags15#0];   //[trkcTags15#0_]
   Int_t           trktauTags15_;
   Float_t         trktauTags15_tag[kMaxtrktauTags15];   //[trktauTags15_]
   Int_t           trktauTags15#0_;
   Int_t           trktauTags15#0_index[kMaxtrktauTags15#0];   //[trktauTags15#0_]
   Int_t           trktauTags15#0_collectionID[kMaxtrktauTags15#0];   //[trktauTags15#0_]
   Int_t           trkjetParts15_;
   UInt_t          trkjetParts15_core_bits[kMaxtrkjetParts15];   //[trkjetParts15_]
   Int_t           trkjetParts15_core_charge[kMaxtrkjetParts15];   //[trkjetParts15_]
   Float_t         trkjetParts15_core_p4_mass[kMaxtrkjetParts15];   //[trkjetParts15_]
   Float_t         trkjetParts15_core_p4_px[kMaxtrkjetParts15];   //[trkjetParts15_]
   Float_t         trkjetParts15_core_p4_py[kMaxtrkjetParts15];   //[trkjetParts15_]
   Float_t         trkjetParts15_core_p4_pz[kMaxtrkjetParts15];   //[trkjetParts15_]
   Int_t           trkjetParts15_core_pdgId[kMaxtrkjetParts15];   //[trkjetParts15_]
   UInt_t          trkjetParts15_core_status[kMaxtrkjetParts15];   //[trkjetParts15_]
   Float_t         trkjetParts15_core_vertex_x[kMaxtrkjetParts15];   //[trkjetParts15_]
   Float_t         trkjetParts15_core_vertex_y[kMaxtrkjetParts15];   //[trkjetParts15_]
   Float_t         trkjetParts15_core_vertex_z[kMaxtrkjetParts15];   //[trkjetParts15_]
   UInt_t          trkjetParts15_tracks_begin[kMaxtrkjetParts15];   //[trkjetParts15_]
   UInt_t          trkjetParts15_tracks_end[kMaxtrkjetParts15];   //[trkjetParts15_]
   UInt_t          trkjetParts15_clusters_begin[kMaxtrkjetParts15];   //[trkjetParts15_]
   UInt_t          trkjetParts15_clusters_end[kMaxtrkjetParts15];   //[trkjetParts15_]
   Int_t           trkjetParts15#0_;
   Int_t           trkjetParts15#0_index[kMaxtrkjetParts15#0];   //[trkjetParts15#0_]
   Int_t           trkjetParts15#0_collectionID[kMaxtrkjetParts15#0];   //[trkjetParts15#0_]
   Int_t           trkjetParts15#1_;
   Int_t           trkjetParts15#1_index[kMaxtrkjetParts15#1];   //[trkjetParts15#1_]
   Int_t           trkjetParts15#1_collectionID[kMaxtrkjetParts15#1];   //[trkjetParts15#1_]
   Int_t           trkjetsOneSubJettiness15_;
   Float_t         trkjetsOneSubJettiness15_tag[kMaxtrkjetsOneSubJettiness15];   //[trkjetsOneSubJettiness15_]
   Int_t           trkjetsOneSubJettiness15#0_;
   Int_t           trkjetsOneSubJettiness15#0_index[kMaxtrkjetsOneSubJettiness15#0];   //[trkjetsOneSubJettiness15#0_]
   Int_t           trkjetsOneSubJettiness15#0_collectionID[kMaxtrkjetsOneSubJettiness15#0];   //[trkjetsOneSubJettiness15#0_]
   Int_t           trkjetsTwoSubJettiness15_;
   Float_t         trkjetsTwoSubJettiness15_tag[kMaxtrkjetsTwoSubJettiness15];   //[trkjetsTwoSubJettiness15_]
   Int_t           trkjetsTwoSubJettiness15#0_;
   Int_t           trkjetsTwoSubJettiness15#0_index[kMaxtrkjetsTwoSubJettiness15#0];   //[trkjetsTwoSubJettiness15#0_]
   Int_t           trkjetsTwoSubJettiness15#0_collectionID[kMaxtrkjetsTwoSubJettiness15#0];   //[trkjetsTwoSubJettiness15#0_]
   Int_t           trkjetsThreeSubJettiness15_;
   Float_t         trkjetsThreeSubJettiness15_tag[kMaxtrkjetsThreeSubJettiness15];   //[trkjetsThreeSubJettiness15_]
   Int_t           trkjetsThreeSubJettiness15#0_;
   Int_t           trkjetsThreeSubJettiness15#0_index[kMaxtrkjetsThreeSubJettiness15#0];   //[trkjetsThreeSubJettiness15#0_]
   Int_t           trkjetsThreeSubJettiness15#0_collectionID[kMaxtrkjetsThreeSubJettiness15#0];   //[trkjetsThreeSubJettiness15#0_]
   Int_t           trksubjetsTrimmingTagged15_;
   UInt_t          trksubjetsTrimmingTagged15_subjets_begin[kMaxtrksubjetsTrimmingTagged15];   //[trksubjetsTrimmingTagged15_]
   UInt_t          trksubjetsTrimmingTagged15_subjets_end[kMaxtrksubjetsTrimmingTagged15];   //[trksubjetsTrimmingTagged15_]
   Int_t           trksubjetsTrimmingTagged15#0_;
   Int_t           trksubjetsTrimmingTagged15#0_index[kMaxtrksubjetsTrimmingTagged15#0];   //[trksubjetsTrimmingTagged15#0_]
   Int_t           trksubjetsTrimmingTagged15#0_collectionID[kMaxtrksubjetsTrimmingTagged15#0];   //[trksubjetsTrimmingTagged15#0_]
   Int_t           trksubjetsTrimmingTagged15#1_;
   Int_t           trksubjetsTrimmingTagged15#1_index[kMaxtrksubjetsTrimmingTagged15#1];   //[trksubjetsTrimmingTagged15#1_]
   Int_t           trksubjetsTrimmingTagged15#1_collectionID[kMaxtrksubjetsTrimmingTagged15#1];   //[trksubjetsTrimmingTagged15#1_]
   Int_t           trksubjetsPruningTagged15_;
   UInt_t          trksubjetsPruningTagged15_subjets_begin[kMaxtrksubjetsPruningTagged15];   //[trksubjetsPruningTagged15_]
   UInt_t          trksubjetsPruningTagged15_subjets_end[kMaxtrksubjetsPruningTagged15];   //[trksubjetsPruningTagged15_]
   Int_t           trksubjetsPruningTagged15#0_;
   Int_t           trksubjetsPruningTagged15#0_index[kMaxtrksubjetsPruningTagged15#0];   //[trksubjetsPruningTagged15#0_]
   Int_t           trksubjetsPruningTagged15#0_collectionID[kMaxtrksubjetsPruningTagged15#0];   //[trksubjetsPruningTagged15#0_]
   Int_t           trksubjetsPruningTagged15#1_;
   Int_t           trksubjetsPruningTagged15#1_index[kMaxtrksubjetsPruningTagged15#1];   //[trksubjetsPruningTagged15#1_]
   Int_t           trksubjetsPruningTagged15#1_collectionID[kMaxtrksubjetsPruningTagged15#1];   //[trksubjetsPruningTagged15#1_]
   Int_t           trksubjetsSoftDropTagged15_;
   UInt_t          trksubjetsSoftDropTagged15_subjets_begin[kMaxtrksubjetsSoftDropTagged15];   //[trksubjetsSoftDropTagged15_]
   UInt_t          trksubjetsSoftDropTagged15_subjets_end[kMaxtrksubjetsSoftDropTagged15];   //[trksubjetsSoftDropTagged15_]
   Int_t           trksubjetsSoftDropTagged15#0_;
   Int_t           trksubjetsSoftDropTagged15#0_index[kMaxtrksubjetsSoftDropTagged15#0];   //[trksubjetsSoftDropTagged15#0_]
   Int_t           trksubjetsSoftDropTagged15#0_collectionID[kMaxtrksubjetsSoftDropTagged15#0];   //[trksubjetsSoftDropTagged15#0_]
   Int_t           trksubjetsSoftDropTagged15#1_;
   Int_t           trksubjetsSoftDropTagged15#1_index[kMaxtrksubjetsSoftDropTagged15#1];   //[trksubjetsSoftDropTagged15#1_]
   Int_t           trksubjetsSoftDropTagged15#1_collectionID[kMaxtrksubjetsSoftDropTagged15#1];   //[trksubjetsSoftDropTagged15#1_]
   Int_t           trksubjetsTrimming15_;
   Float_t         trksubjetsTrimming15_core_area[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   UInt_t          trksubjetsTrimming15_core_bits[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   Float_t         trksubjetsTrimming15_core_p4_mass[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   Float_t         trksubjetsTrimming15_core_p4_px[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   Float_t         trksubjetsTrimming15_core_p4_py[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   Float_t         trksubjetsTrimming15_core_p4_pz[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   UInt_t          trksubjetsTrimming15_particles_begin[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   UInt_t          trksubjetsTrimming15_particles_end[kMaxtrksubjetsTrimming15];   //[trksubjetsTrimming15_]
   Int_t           trksubjetsTrimming15#0_;
   Int_t           trksubjetsTrimming15#0_index[kMaxtrksubjetsTrimming15#0];   //[trksubjetsTrimming15#0_]
   Int_t           trksubjetsTrimming15#0_collectionID[kMaxtrksubjetsTrimming15#0];   //[trksubjetsTrimming15#0_]
   Int_t           trksubjetsPruning15_;
   Float_t         trksubjetsPruning15_core_area[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   UInt_t          trksubjetsPruning15_core_bits[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   Float_t         trksubjetsPruning15_core_p4_mass[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   Float_t         trksubjetsPruning15_core_p4_px[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   Float_t         trksubjetsPruning15_core_p4_py[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   Float_t         trksubjetsPruning15_core_p4_pz[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   UInt_t          trksubjetsPruning15_particles_begin[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   UInt_t          trksubjetsPruning15_particles_end[kMaxtrksubjetsPruning15];   //[trksubjetsPruning15_]
   Int_t           trksubjetsPruning15#0_;
   Int_t           trksubjetsPruning15#0_index[kMaxtrksubjetsPruning15#0];   //[trksubjetsPruning15#0_]
   Int_t           trksubjetsPruning15#0_collectionID[kMaxtrksubjetsPruning15#0];   //[trksubjetsPruning15#0_]
   Int_t           trksubjetsSoftDrop15_;
   Float_t         trksubjetsSoftDrop15_core_area[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   UInt_t          trksubjetsSoftDrop15_core_bits[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   Float_t         trksubjetsSoftDrop15_core_p4_mass[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   Float_t         trksubjetsSoftDrop15_core_p4_px[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   Float_t         trksubjetsSoftDrop15_core_p4_py[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   Float_t         trksubjetsSoftDrop15_core_p4_pz[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   UInt_t          trksubjetsSoftDrop15_particles_begin[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   UInt_t          trksubjetsSoftDrop15_particles_end[kMaxtrksubjetsSoftDrop15];   //[trksubjetsSoftDrop15_]
   Int_t           trksubjetsSoftDrop15#0_;
   Int_t           trksubjetsSoftDrop15#0_index[kMaxtrksubjetsSoftDrop15#0];   //[trksubjetsSoftDrop15#0_]
   Int_t           trksubjetsSoftDrop15#0_collectionID[kMaxtrksubjetsSoftDrop15#0];   //[trksubjetsSoftDrop15#0_]
   Int_t           met_;
   Float_t         met_magnitude[kMaxmet];   //[met_]
   Float_t         met_phi[kMaxmet];   //[met_]
   Float_t         met_scalarSum[kMaxmet];   //[met_]

   // List of branches
   TBranch        *b_mePsMatchingVars_;   //!
   TBranch        *b_mePsMatchingVars_value;   //!
   TBranch        *b_mcEventWeights_;   //!
   TBranch        *b_mcEventWeights_value;   //!
   TBranch        *b_skimmedGenParticles_;   //!
   TBranch        *b_skimmedGenParticles_core_bits;   //!
   TBranch        *b_skimmedGenParticles_core_charge;   //!
   TBranch        *b_skimmedGenParticles_core_p4_mass;   //!
   TBranch        *b_skimmedGenParticles_core_p4_px;   //!
   TBranch        *b_skimmedGenParticles_core_p4_py;   //!
   TBranch        *b_skimmedGenParticles_core_p4_pz;   //!
   TBranch        *b_skimmedGenParticles_core_pdgId;   //!
   TBranch        *b_skimmedGenParticles_core_status;   //!
   TBranch        *b_skimmedGenParticles_core_vertex_x;   //!
   TBranch        *b_skimmedGenParticles_core_vertex_y;   //!
   TBranch        *b_skimmedGenParticles_core_vertex_z;   //!
   TBranch        *b_skimmedGenParticles#0_;   //!
   TBranch        *b_skimmedGenParticles#0_index;   //!
   TBranch        *b_skimmedGenParticles#0_collectionID;   //!
   TBranch        *b_skimmedGenParticles#1_;   //!
   TBranch        *b_skimmedGenParticles#1_index;   //!
   TBranch        *b_skimmedGenParticles#1_collectionID;   //!
   TBranch        *b_muons_;   //!
   TBranch        *b_muons_core_bits;   //!
   TBranch        *b_muons_core_charge;   //!
   TBranch        *b_muons_core_p4_mass;   //!
   TBranch        *b_muons_core_p4_px;   //!
   TBranch        *b_muons_core_p4_py;   //!
   TBranch        *b_muons_core_p4_pz;   //!
   TBranch        *b_muons_core_pdgId;   //!
   TBranch        *b_muons_core_status;   //!
   TBranch        *b_muons_core_vertex_x;   //!
   TBranch        *b_muons_core_vertex_y;   //!
   TBranch        *b_muons_core_vertex_z;   //!
   TBranch        *b_muons_tracks_begin;   //!
   TBranch        *b_muons_tracks_end;   //!
   TBranch        *b_muons_clusters_begin;   //!
   TBranch        *b_muons_clusters_end;   //!
   TBranch        *b_muons#0_;   //!
   TBranch        *b_muons#0_index;   //!
   TBranch        *b_muons#0_collectionID;   //!
   TBranch        *b_muons#1_;   //!
   TBranch        *b_muons#1_index;   //!
   TBranch        *b_muons#1_collectionID;   //!
   TBranch        *b_muonsToMC;   //!
   TBranch        *b_muonsToMC#0_;   //!
   TBranch        *b_muonsToMC#0_index;   //!
   TBranch        *b_muonsToMC#0_collectionID;   //!
   TBranch        *b_muonsToMC#1_;   //!
   TBranch        *b_muonsToMC#1_index;   //!
   TBranch        *b_muonsToMC#1_collectionID;   //!
   TBranch        *b_muonITags_;   //!
   TBranch        *b_muonITags_tag;   //!
   TBranch        *b_muonITags#0_;   //!
   TBranch        *b_muonITags#0_index;   //!
   TBranch        *b_muonITags#0_collectionID;   //!
   TBranch        *b_electrons_;   //!
   TBranch        *b_electrons_core_bits;   //!
   TBranch        *b_electrons_core_charge;   //!
   TBranch        *b_electrons_core_p4_mass;   //!
   TBranch        *b_electrons_core_p4_px;   //!
   TBranch        *b_electrons_core_p4_py;   //!
   TBranch        *b_electrons_core_p4_pz;   //!
   TBranch        *b_electrons_core_pdgId;   //!
   TBranch        *b_electrons_core_status;   //!
   TBranch        *b_electrons_core_vertex_x;   //!
   TBranch        *b_electrons_core_vertex_y;   //!
   TBranch        *b_electrons_core_vertex_z;   //!
   TBranch        *b_electrons_tracks_begin;   //!
   TBranch        *b_electrons_tracks_end;   //!
   TBranch        *b_electrons_clusters_begin;   //!
   TBranch        *b_electrons_clusters_end;   //!
   TBranch        *b_electrons#0_;   //!
   TBranch        *b_electrons#0_index;   //!
   TBranch        *b_electrons#0_collectionID;   //!
   TBranch        *b_electrons#1_;   //!
   TBranch        *b_electrons#1_index;   //!
   TBranch        *b_electrons#1_collectionID;   //!
   TBranch        *b_electronsToMC;   //!
   TBranch        *b_electronsToMC#0_;   //!
   TBranch        *b_electronsToMC#0_index;   //!
   TBranch        *b_electronsToMC#0_collectionID;   //!
   TBranch        *b_electronsToMC#1_;   //!
   TBranch        *b_electronsToMC#1_index;   //!
   TBranch        *b_electronsToMC#1_collectionID;   //!
   TBranch        *b_electronITags_;   //!
   TBranch        *b_electronITags_tag;   //!
   TBranch        *b_electronITags#0_;   //!
   TBranch        *b_electronITags#0_index;   //!
   TBranch        *b_electronITags#0_collectionID;   //!
   TBranch        *b_photons_;   //!
   TBranch        *b_photons_core_bits;   //!
   TBranch        *b_photons_core_charge;   //!
   TBranch        *b_photons_core_p4_mass;   //!
   TBranch        *b_photons_core_p4_px;   //!
   TBranch        *b_photons_core_p4_py;   //!
   TBranch        *b_photons_core_p4_pz;   //!
   TBranch        *b_photons_core_pdgId;   //!
   TBranch        *b_photons_core_status;   //!
   TBranch        *b_photons_core_vertex_x;   //!
   TBranch        *b_photons_core_vertex_y;   //!
   TBranch        *b_photons_core_vertex_z;   //!
   TBranch        *b_photons_tracks_begin;   //!
   TBranch        *b_photons_tracks_end;   //!
   TBranch        *b_photons_clusters_begin;   //!
   TBranch        *b_photons_clusters_end;   //!
   TBranch        *b_photons#0_;   //!
   TBranch        *b_photons#0_index;   //!
   TBranch        *b_photons#0_collectionID;   //!
   TBranch        *b_photons#1_;   //!
   TBranch        *b_photons#1_index;   //!
   TBranch        *b_photons#1_collectionID;   //!
   TBranch        *b_photonsToMC;   //!
   TBranch        *b_photonsToMC#0_;   //!
   TBranch        *b_photonsToMC#0_index;   //!
   TBranch        *b_photonsToMC#0_collectionID;   //!
   TBranch        *b_photonsToMC#1_;   //!
   TBranch        *b_photonsToMC#1_index;   //!
   TBranch        *b_photonsToMC#1_collectionID;   //!
   TBranch        *b_photonITags_;   //!
   TBranch        *b_photonITags_tag;   //!
   TBranch        *b_photonITags#0_;   //!
   TBranch        *b_photonITags#0_index;   //!
   TBranch        *b_photonITags#0_collectionID;   //!
   TBranch        *b_pfcharged_;   //!
   TBranch        *b_pfcharged_core_bits;   //!
   TBranch        *b_pfcharged_core_charge;   //!
   TBranch        *b_pfcharged_core_p4_mass;   //!
   TBranch        *b_pfcharged_core_p4_px;   //!
   TBranch        *b_pfcharged_core_p4_py;   //!
   TBranch        *b_pfcharged_core_p4_pz;   //!
   TBranch        *b_pfcharged_core_pdgId;   //!
   TBranch        *b_pfcharged_core_status;   //!
   TBranch        *b_pfcharged_core_vertex_x;   //!
   TBranch        *b_pfcharged_core_vertex_y;   //!
   TBranch        *b_pfcharged_core_vertex_z;   //!
   TBranch        *b_pfcharged_tracks_begin;   //!
   TBranch        *b_pfcharged_tracks_end;   //!
   TBranch        *b_pfcharged_clusters_begin;   //!
   TBranch        *b_pfcharged_clusters_end;   //!
   TBranch        *b_pfcharged#0_;   //!
   TBranch        *b_pfcharged#0_index;   //!
   TBranch        *b_pfcharged#0_collectionID;   //!
   TBranch        *b_pfcharged#1_;   //!
   TBranch        *b_pfcharged#1_index;   //!
   TBranch        *b_pfcharged#1_collectionID;   //!
   TBranch        *b_chargedToMC;   //!
   TBranch        *b_chargedToMC#0_;   //!
   TBranch        *b_chargedToMC#0_index;   //!
   TBranch        *b_chargedToMC#0_collectionID;   //!
   TBranch        *b_chargedToMC#1_;   //!
   TBranch        *b_chargedToMC#1_index;   //!
   TBranch        *b_chargedToMC#1_collectionID;   //!
   TBranch        *b_pfphotons_;   //!
   TBranch        *b_pfphotons_core_bits;   //!
   TBranch        *b_pfphotons_core_charge;   //!
   TBranch        *b_pfphotons_core_p4_mass;   //!
   TBranch        *b_pfphotons_core_p4_px;   //!
   TBranch        *b_pfphotons_core_p4_py;   //!
   TBranch        *b_pfphotons_core_p4_pz;   //!
   TBranch        *b_pfphotons_core_pdgId;   //!
   TBranch        *b_pfphotons_core_status;   //!
   TBranch        *b_pfphotons_core_vertex_x;   //!
   TBranch        *b_pfphotons_core_vertex_y;   //!
   TBranch        *b_pfphotons_core_vertex_z;   //!
   TBranch        *b_pfphotons_tracks_begin;   //!
   TBranch        *b_pfphotons_tracks_end;   //!
   TBranch        *b_pfphotons_clusters_begin;   //!
   TBranch        *b_pfphotons_clusters_end;   //!
   TBranch        *b_pfphotons#0_;   //!
   TBranch        *b_pfphotons#0_index;   //!
   TBranch        *b_pfphotons#0_collectionID;   //!
   TBranch        *b_pfphotons#1_;   //!
   TBranch        *b_pfphotons#1_index;   //!
   TBranch        *b_pfphotons#1_collectionID;   //!
   TBranch        *b_pfphotonsToMC;   //!
   TBranch        *b_pfphotonsToMC#0_;   //!
   TBranch        *b_pfphotonsToMC#0_index;   //!
   TBranch        *b_pfphotonsToMC#0_collectionID;   //!
   TBranch        *b_pfphotonsToMC#1_;   //!
   TBranch        *b_pfphotonsToMC#1_index;   //!
   TBranch        *b_pfphotonsToMC#1_collectionID;   //!
   TBranch        *b_pfneutrals_;   //!
   TBranch        *b_pfneutrals_core_bits;   //!
   TBranch        *b_pfneutrals_core_charge;   //!
   TBranch        *b_pfneutrals_core_p4_mass;   //!
   TBranch        *b_pfneutrals_core_p4_px;   //!
   TBranch        *b_pfneutrals_core_p4_py;   //!
   TBranch        *b_pfneutrals_core_p4_pz;   //!
   TBranch        *b_pfneutrals_core_pdgId;   //!
   TBranch        *b_pfneutrals_core_status;   //!
   TBranch        *b_pfneutrals_core_vertex_x;   //!
   TBranch        *b_pfneutrals_core_vertex_y;   //!
   TBranch        *b_pfneutrals_core_vertex_z;   //!
   TBranch        *b_pfneutrals_tracks_begin;   //!
   TBranch        *b_pfneutrals_tracks_end;   //!
   TBranch        *b_pfneutrals_clusters_begin;   //!
   TBranch        *b_pfneutrals_clusters_end;   //!
   TBranch        *b_pfneutrals#0_;   //!
   TBranch        *b_pfneutrals#0_index;   //!
   TBranch        *b_pfneutrals#0_collectionID;   //!
   TBranch        *b_pfneutrals#1_;   //!
   TBranch        *b_pfneutrals#1_index;   //!
   TBranch        *b_pfneutrals#1_collectionID;   //!
   TBranch        *b_pfneutralsToMC;   //!
   TBranch        *b_pfneutralsToMC#0_;   //!
   TBranch        *b_pfneutralsToMC#0_index;   //!
   TBranch        *b_pfneutralsToMC#0_collectionID;   //!
   TBranch        *b_pfneutralsToMC#1_;   //!
   TBranch        *b_pfneutralsToMC#1_index;   //!
   TBranch        *b_pfneutralsToMC#1_collectionID;   //!
   TBranch        *b_genjets02_;   //!
   TBranch        *b_genjets02_core_area;   //!
   TBranch        *b_genjets02_core_bits;   //!
   TBranch        *b_genjets02_core_p4_mass;   //!
   TBranch        *b_genjets02_core_p4_px;   //!
   TBranch        *b_genjets02_core_p4_py;   //!
   TBranch        *b_genjets02_core_p4_pz;   //!
   TBranch        *b_genjets02_particles_begin;   //!
   TBranch        *b_genjets02_particles_end;   //!
   TBranch        *b_genjets02#0_;   //!
   TBranch        *b_genjets02#0_index;   //!
   TBranch        *b_genjets02#0_collectionID;   //!
   TBranch        *b_genjetsFlavor02_;   //!
   TBranch        *b_genjetsFlavor02_tag;   //!
   TBranch        *b_genjetsFlavor02#0_;   //!
   TBranch        *b_genjetsFlavor02#0_index;   //!
   TBranch        *b_genjetsFlavor02#0_collectionID;   //!
   TBranch        *b_genjets04_;   //!
   TBranch        *b_genjets04_core_area;   //!
   TBranch        *b_genjets04_core_bits;   //!
   TBranch        *b_genjets04_core_p4_mass;   //!
   TBranch        *b_genjets04_core_p4_px;   //!
   TBranch        *b_genjets04_core_p4_py;   //!
   TBranch        *b_genjets04_core_p4_pz;   //!
   TBranch        *b_genjets04_particles_begin;   //!
   TBranch        *b_genjets04_particles_end;   //!
   TBranch        *b_genjets04#0_;   //!
   TBranch        *b_genjets04#0_index;   //!
   TBranch        *b_genjets04#0_collectionID;   //!
   TBranch        *b_genjetsFlavor04_;   //!
   TBranch        *b_genjetsFlavor04_tag;   //!
   TBranch        *b_genjetsFlavor04#0_;   //!
   TBranch        *b_genjetsFlavor04#0_index;   //!
   TBranch        *b_genjetsFlavor04#0_collectionID;   //!
   TBranch        *b_genjets08_;   //!
   TBranch        *b_genjets08_core_area;   //!
   TBranch        *b_genjets08_core_bits;   //!
   TBranch        *b_genjets08_core_p4_mass;   //!
   TBranch        *b_genjets08_core_p4_px;   //!
   TBranch        *b_genjets08_core_p4_py;   //!
   TBranch        *b_genjets08_core_p4_pz;   //!
   TBranch        *b_genjets08_particles_begin;   //!
   TBranch        *b_genjets08_particles_end;   //!
   TBranch        *b_genjets08#0_;   //!
   TBranch        *b_genjets08#0_index;   //!
   TBranch        *b_genjets08#0_collectionID;   //!
   TBranch        *b_genjetsFlavor08_;   //!
   TBranch        *b_genjetsFlavor08_tag;   //!
   TBranch        *b_genjetsFlavor08#0_;   //!
   TBranch        *b_genjetsFlavor08#0_index;   //!
   TBranch        *b_genjetsFlavor08#0_collectionID;   //!
   TBranch        *b_genjets15_;   //!
   TBranch        *b_genjets15_core_area;   //!
   TBranch        *b_genjets15_core_bits;   //!
   TBranch        *b_genjets15_core_p4_mass;   //!
   TBranch        *b_genjets15_core_p4_px;   //!
   TBranch        *b_genjets15_core_p4_py;   //!
   TBranch        *b_genjets15_core_p4_pz;   //!
   TBranch        *b_genjets15_particles_begin;   //!
   TBranch        *b_genjets15_particles_end;   //!
   TBranch        *b_genjets15#0_;   //!
   TBranch        *b_genjets15#0_index;   //!
   TBranch        *b_genjets15#0_collectionID;   //!
   TBranch        *b_genjetsFlavor15_;   //!
   TBranch        *b_genjetsFlavor15_tag;   //!
   TBranch        *b_genjetsFlavor15#0_;   //!
   TBranch        *b_genjetsFlavor15#0_index;   //!
   TBranch        *b_genjetsFlavor15#0_collectionID;   //!
   TBranch        *b_calojets02_;   //!
   TBranch        *b_calojets02_core_area;   //!
   TBranch        *b_calojets02_core_bits;   //!
   TBranch        *b_calojets02_core_p4_mass;   //!
   TBranch        *b_calojets02_core_p4_px;   //!
   TBranch        *b_calojets02_core_p4_py;   //!
   TBranch        *b_calojets02_core_p4_pz;   //!
   TBranch        *b_calojets02_particles_begin;   //!
   TBranch        *b_calojets02_particles_end;   //!
   TBranch        *b_calojets02#0_;   //!
   TBranch        *b_calojets02#0_index;   //!
   TBranch        *b_calojets02#0_collectionID;   //!
   TBranch        *b_calojetsFlavor02_;   //!
   TBranch        *b_calojetsFlavor02_tag;   //!
   TBranch        *b_calojetsFlavor02#0_;   //!
   TBranch        *b_calojetsFlavor02#0_index;   //!
   TBranch        *b_calojetsFlavor02#0_collectionID;   //!
   TBranch        *b_calobTags02_;   //!
   TBranch        *b_calobTags02_tag;   //!
   TBranch        *b_calobTags02#0_;   //!
   TBranch        *b_calobTags02#0_index;   //!
   TBranch        *b_calobTags02#0_collectionID;   //!
   TBranch        *b_calocTags02_;   //!
   TBranch        *b_calocTags02_tag;   //!
   TBranch        *b_calocTags02#0_;   //!
   TBranch        *b_calocTags02#0_index;   //!
   TBranch        *b_calocTags02#0_collectionID;   //!
   TBranch        *b_calotauTags02_;   //!
   TBranch        *b_calotauTags02_tag;   //!
   TBranch        *b_calotauTags02#0_;   //!
   TBranch        *b_calotauTags02#0_index;   //!
   TBranch        *b_calotauTags02#0_collectionID;   //!
   TBranch        *b_calojetParts02_;   //!
   TBranch        *b_calojetParts02_core_bits;   //!
   TBranch        *b_calojetParts02_core_charge;   //!
   TBranch        *b_calojetParts02_core_p4_mass;   //!
   TBranch        *b_calojetParts02_core_p4_px;   //!
   TBranch        *b_calojetParts02_core_p4_py;   //!
   TBranch        *b_calojetParts02_core_p4_pz;   //!
   TBranch        *b_calojetParts02_core_pdgId;   //!
   TBranch        *b_calojetParts02_core_status;   //!
   TBranch        *b_calojetParts02_core_vertex_x;   //!
   TBranch        *b_calojetParts02_core_vertex_y;   //!
   TBranch        *b_calojetParts02_core_vertex_z;   //!
   TBranch        *b_calojetParts02_tracks_begin;   //!
   TBranch        *b_calojetParts02_tracks_end;   //!
   TBranch        *b_calojetParts02_clusters_begin;   //!
   TBranch        *b_calojetParts02_clusters_end;   //!
   TBranch        *b_calojetParts02#0_;   //!
   TBranch        *b_calojetParts02#0_index;   //!
   TBranch        *b_calojetParts02#0_collectionID;   //!
   TBranch        *b_calojetParts02#1_;   //!
   TBranch        *b_calojetParts02#1_index;   //!
   TBranch        *b_calojetParts02#1_collectionID;   //!
   TBranch        *b_calojetsOneSubJettiness02_;   //!
   TBranch        *b_calojetsOneSubJettiness02_tag;   //!
   TBranch        *b_calojetsOneSubJettiness02#0_;   //!
   TBranch        *b_calojetsOneSubJettiness02#0_index;   //!
   TBranch        *b_calojetsOneSubJettiness02#0_collectionID;   //!
   TBranch        *b_calojetsTwoSubJettiness02_;   //!
   TBranch        *b_calojetsTwoSubJettiness02_tag;   //!
   TBranch        *b_calojetsTwoSubJettiness02#0_;   //!
   TBranch        *b_calojetsTwoSubJettiness02#0_index;   //!
   TBranch        *b_calojetsTwoSubJettiness02#0_collectionID;   //!
   TBranch        *b_calojetsThreeSubJettiness02_;   //!
   TBranch        *b_calojetsThreeSubJettiness02_tag;   //!
   TBranch        *b_calojetsThreeSubJettiness02#0_;   //!
   TBranch        *b_calojetsThreeSubJettiness02#0_index;   //!
   TBranch        *b_calojetsThreeSubJettiness02#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged02_;   //!
   TBranch        *b_calosubjetsTrimmingTagged02_subjets_begin;   //!
   TBranch        *b_calosubjetsTrimmingTagged02_subjets_end;   //!
   TBranch        *b_calosubjetsTrimmingTagged02#0_;   //!
   TBranch        *b_calosubjetsTrimmingTagged02#0_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged02#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged02#1_;   //!
   TBranch        *b_calosubjetsTrimmingTagged02#1_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged02#1_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged02_;   //!
   TBranch        *b_calosubjetsPruningTagged02_subjets_begin;   //!
   TBranch        *b_calosubjetsPruningTagged02_subjets_end;   //!
   TBranch        *b_calosubjetsPruningTagged02#0_;   //!
   TBranch        *b_calosubjetsPruningTagged02#0_index;   //!
   TBranch        *b_calosubjetsPruningTagged02#0_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged02#1_;   //!
   TBranch        *b_calosubjetsPruningTagged02#1_index;   //!
   TBranch        *b_calosubjetsPruningTagged02#1_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged02_;   //!
   TBranch        *b_calosubjetsSoftDropTagged02_subjets_begin;   //!
   TBranch        *b_calosubjetsSoftDropTagged02_subjets_end;   //!
   TBranch        *b_calosubjetsSoftDropTagged02#0_;   //!
   TBranch        *b_calosubjetsSoftDropTagged02#0_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged02#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged02#1_;   //!
   TBranch        *b_calosubjetsSoftDropTagged02#1_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged02#1_collectionID;   //!
   TBranch        *b_calosubjetsTrimming02_;   //!
   TBranch        *b_calosubjetsTrimming02_core_area;   //!
   TBranch        *b_calosubjetsTrimming02_core_bits;   //!
   TBranch        *b_calosubjetsTrimming02_core_p4_mass;   //!
   TBranch        *b_calosubjetsTrimming02_core_p4_px;   //!
   TBranch        *b_calosubjetsTrimming02_core_p4_py;   //!
   TBranch        *b_calosubjetsTrimming02_core_p4_pz;   //!
   TBranch        *b_calosubjetsTrimming02_particles_begin;   //!
   TBranch        *b_calosubjetsTrimming02_particles_end;   //!
   TBranch        *b_calosubjetsTrimming02#0_;   //!
   TBranch        *b_calosubjetsTrimming02#0_index;   //!
   TBranch        *b_calosubjetsTrimming02#0_collectionID;   //!
   TBranch        *b_calosubjetsPruning02_;   //!
   TBranch        *b_calosubjetsPruning02_core_area;   //!
   TBranch        *b_calosubjetsPruning02_core_bits;   //!
   TBranch        *b_calosubjetsPruning02_core_p4_mass;   //!
   TBranch        *b_calosubjetsPruning02_core_p4_px;   //!
   TBranch        *b_calosubjetsPruning02_core_p4_py;   //!
   TBranch        *b_calosubjetsPruning02_core_p4_pz;   //!
   TBranch        *b_calosubjetsPruning02_particles_begin;   //!
   TBranch        *b_calosubjetsPruning02_particles_end;   //!
   TBranch        *b_calosubjetsPruning02#0_;   //!
   TBranch        *b_calosubjetsPruning02#0_index;   //!
   TBranch        *b_calosubjetsPruning02#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDrop02_;   //!
   TBranch        *b_calosubjetsSoftDrop02_core_area;   //!
   TBranch        *b_calosubjetsSoftDrop02_core_bits;   //!
   TBranch        *b_calosubjetsSoftDrop02_core_p4_mass;   //!
   TBranch        *b_calosubjetsSoftDrop02_core_p4_px;   //!
   TBranch        *b_calosubjetsSoftDrop02_core_p4_py;   //!
   TBranch        *b_calosubjetsSoftDrop02_core_p4_pz;   //!
   TBranch        *b_calosubjetsSoftDrop02_particles_begin;   //!
   TBranch        *b_calosubjetsSoftDrop02_particles_end;   //!
   TBranch        *b_calosubjetsSoftDrop02#0_;   //!
   TBranch        *b_calosubjetsSoftDrop02#0_index;   //!
   TBranch        *b_calosubjetsSoftDrop02#0_collectionID;   //!
   TBranch        *b_calojets04_;   //!
   TBranch        *b_calojets04_core_area;   //!
   TBranch        *b_calojets04_core_bits;   //!
   TBranch        *b_calojets04_core_p4_mass;   //!
   TBranch        *b_calojets04_core_p4_px;   //!
   TBranch        *b_calojets04_core_p4_py;   //!
   TBranch        *b_calojets04_core_p4_pz;   //!
   TBranch        *b_calojets04_particles_begin;   //!
   TBranch        *b_calojets04_particles_end;   //!
   TBranch        *b_calojets04#0_;   //!
   TBranch        *b_calojets04#0_index;   //!
   TBranch        *b_calojets04#0_collectionID;   //!
   TBranch        *b_calojetsFlavor04_;   //!
   TBranch        *b_calojetsFlavor04_tag;   //!
   TBranch        *b_calojetsFlavor04#0_;   //!
   TBranch        *b_calojetsFlavor04#0_index;   //!
   TBranch        *b_calojetsFlavor04#0_collectionID;   //!
   TBranch        *b_calobTags04_;   //!
   TBranch        *b_calobTags04_tag;   //!
   TBranch        *b_calobTags04#0_;   //!
   TBranch        *b_calobTags04#0_index;   //!
   TBranch        *b_calobTags04#0_collectionID;   //!
   TBranch        *b_calocTags04_;   //!
   TBranch        *b_calocTags04_tag;   //!
   TBranch        *b_calocTags04#0_;   //!
   TBranch        *b_calocTags04#0_index;   //!
   TBranch        *b_calocTags04#0_collectionID;   //!
   TBranch        *b_calotauTags04_;   //!
   TBranch        *b_calotauTags04_tag;   //!
   TBranch        *b_calotauTags04#0_;   //!
   TBranch        *b_calotauTags04#0_index;   //!
   TBranch        *b_calotauTags04#0_collectionID;   //!
   TBranch        *b_calojetParts04_;   //!
   TBranch        *b_calojetParts04_core_bits;   //!
   TBranch        *b_calojetParts04_core_charge;   //!
   TBranch        *b_calojetParts04_core_p4_mass;   //!
   TBranch        *b_calojetParts04_core_p4_px;   //!
   TBranch        *b_calojetParts04_core_p4_py;   //!
   TBranch        *b_calojetParts04_core_p4_pz;   //!
   TBranch        *b_calojetParts04_core_pdgId;   //!
   TBranch        *b_calojetParts04_core_status;   //!
   TBranch        *b_calojetParts04_core_vertex_x;   //!
   TBranch        *b_calojetParts04_core_vertex_y;   //!
   TBranch        *b_calojetParts04_core_vertex_z;   //!
   TBranch        *b_calojetParts04_tracks_begin;   //!
   TBranch        *b_calojetParts04_tracks_end;   //!
   TBranch        *b_calojetParts04_clusters_begin;   //!
   TBranch        *b_calojetParts04_clusters_end;   //!
   TBranch        *b_calojetParts04#0_;   //!
   TBranch        *b_calojetParts04#0_index;   //!
   TBranch        *b_calojetParts04#0_collectionID;   //!
   TBranch        *b_calojetParts04#1_;   //!
   TBranch        *b_calojetParts04#1_index;   //!
   TBranch        *b_calojetParts04#1_collectionID;   //!
   TBranch        *b_calojetsOneSubJettiness04_;   //!
   TBranch        *b_calojetsOneSubJettiness04_tag;   //!
   TBranch        *b_calojetsOneSubJettiness04#0_;   //!
   TBranch        *b_calojetsOneSubJettiness04#0_index;   //!
   TBranch        *b_calojetsOneSubJettiness04#0_collectionID;   //!
   TBranch        *b_calojetsTwoSubJettiness04_;   //!
   TBranch        *b_calojetsTwoSubJettiness04_tag;   //!
   TBranch        *b_calojetsTwoSubJettiness04#0_;   //!
   TBranch        *b_calojetsTwoSubJettiness04#0_index;   //!
   TBranch        *b_calojetsTwoSubJettiness04#0_collectionID;   //!
   TBranch        *b_calojetsThreeSubJettiness04_;   //!
   TBranch        *b_calojetsThreeSubJettiness04_tag;   //!
   TBranch        *b_calojetsThreeSubJettiness04#0_;   //!
   TBranch        *b_calojetsThreeSubJettiness04#0_index;   //!
   TBranch        *b_calojetsThreeSubJettiness04#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged04_;   //!
   TBranch        *b_calosubjetsTrimmingTagged04_subjets_begin;   //!
   TBranch        *b_calosubjetsTrimmingTagged04_subjets_end;   //!
   TBranch        *b_calosubjetsTrimmingTagged04#0_;   //!
   TBranch        *b_calosubjetsTrimmingTagged04#0_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged04#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged04#1_;   //!
   TBranch        *b_calosubjetsTrimmingTagged04#1_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged04#1_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged04_;   //!
   TBranch        *b_calosubjetsPruningTagged04_subjets_begin;   //!
   TBranch        *b_calosubjetsPruningTagged04_subjets_end;   //!
   TBranch        *b_calosubjetsPruningTagged04#0_;   //!
   TBranch        *b_calosubjetsPruningTagged04#0_index;   //!
   TBranch        *b_calosubjetsPruningTagged04#0_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged04#1_;   //!
   TBranch        *b_calosubjetsPruningTagged04#1_index;   //!
   TBranch        *b_calosubjetsPruningTagged04#1_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged04_;   //!
   TBranch        *b_calosubjetsSoftDropTagged04_subjets_begin;   //!
   TBranch        *b_calosubjetsSoftDropTagged04_subjets_end;   //!
   TBranch        *b_calosubjetsSoftDropTagged04#0_;   //!
   TBranch        *b_calosubjetsSoftDropTagged04#0_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged04#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged04#1_;   //!
   TBranch        *b_calosubjetsSoftDropTagged04#1_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged04#1_collectionID;   //!
   TBranch        *b_calosubjetsTrimming04_;   //!
   TBranch        *b_calosubjetsTrimming04_core_area;   //!
   TBranch        *b_calosubjetsTrimming04_core_bits;   //!
   TBranch        *b_calosubjetsTrimming04_core_p4_mass;   //!
   TBranch        *b_calosubjetsTrimming04_core_p4_px;   //!
   TBranch        *b_calosubjetsTrimming04_core_p4_py;   //!
   TBranch        *b_calosubjetsTrimming04_core_p4_pz;   //!
   TBranch        *b_calosubjetsTrimming04_particles_begin;   //!
   TBranch        *b_calosubjetsTrimming04_particles_end;   //!
   TBranch        *b_calosubjetsTrimming04#0_;   //!
   TBranch        *b_calosubjetsTrimming04#0_index;   //!
   TBranch        *b_calosubjetsTrimming04#0_collectionID;   //!
   TBranch        *b_calosubjetsPruning04_;   //!
   TBranch        *b_calosubjetsPruning04_core_area;   //!
   TBranch        *b_calosubjetsPruning04_core_bits;   //!
   TBranch        *b_calosubjetsPruning04_core_p4_mass;   //!
   TBranch        *b_calosubjetsPruning04_core_p4_px;   //!
   TBranch        *b_calosubjetsPruning04_core_p4_py;   //!
   TBranch        *b_calosubjetsPruning04_core_p4_pz;   //!
   TBranch        *b_calosubjetsPruning04_particles_begin;   //!
   TBranch        *b_calosubjetsPruning04_particles_end;   //!
   TBranch        *b_calosubjetsPruning04#0_;   //!
   TBranch        *b_calosubjetsPruning04#0_index;   //!
   TBranch        *b_calosubjetsPruning04#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDrop04_;   //!
   TBranch        *b_calosubjetsSoftDrop04_core_area;   //!
   TBranch        *b_calosubjetsSoftDrop04_core_bits;   //!
   TBranch        *b_calosubjetsSoftDrop04_core_p4_mass;   //!
   TBranch        *b_calosubjetsSoftDrop04_core_p4_px;   //!
   TBranch        *b_calosubjetsSoftDrop04_core_p4_py;   //!
   TBranch        *b_calosubjetsSoftDrop04_core_p4_pz;   //!
   TBranch        *b_calosubjetsSoftDrop04_particles_begin;   //!
   TBranch        *b_calosubjetsSoftDrop04_particles_end;   //!
   TBranch        *b_calosubjetsSoftDrop04#0_;   //!
   TBranch        *b_calosubjetsSoftDrop04#0_index;   //!
   TBranch        *b_calosubjetsSoftDrop04#0_collectionID;   //!
   TBranch        *b_calojets08_;   //!
   TBranch        *b_calojets08_core_area;   //!
   TBranch        *b_calojets08_core_bits;   //!
   TBranch        *b_calojets08_core_p4_mass;   //!
   TBranch        *b_calojets08_core_p4_px;   //!
   TBranch        *b_calojets08_core_p4_py;   //!
   TBranch        *b_calojets08_core_p4_pz;   //!
   TBranch        *b_calojets08_particles_begin;   //!
   TBranch        *b_calojets08_particles_end;   //!
   TBranch        *b_calojets08#0_;   //!
   TBranch        *b_calojets08#0_index;   //!
   TBranch        *b_calojets08#0_collectionID;   //!
   TBranch        *b_calojetsFlavor08_;   //!
   TBranch        *b_calojetsFlavor08_tag;   //!
   TBranch        *b_calojetsFlavor08#0_;   //!
   TBranch        *b_calojetsFlavor08#0_index;   //!
   TBranch        *b_calojetsFlavor08#0_collectionID;   //!
   TBranch        *b_calobTags08_;   //!
   TBranch        *b_calobTags08_tag;   //!
   TBranch        *b_calobTags08#0_;   //!
   TBranch        *b_calobTags08#0_index;   //!
   TBranch        *b_calobTags08#0_collectionID;   //!
   TBranch        *b_calocTags08_;   //!
   TBranch        *b_calocTags08_tag;   //!
   TBranch        *b_calocTags08#0_;   //!
   TBranch        *b_calocTags08#0_index;   //!
   TBranch        *b_calocTags08#0_collectionID;   //!
   TBranch        *b_calotauTags08_;   //!
   TBranch        *b_calotauTags08_tag;   //!
   TBranch        *b_calotauTags08#0_;   //!
   TBranch        *b_calotauTags08#0_index;   //!
   TBranch        *b_calotauTags08#0_collectionID;   //!
   TBranch        *b_calojetParts08_;   //!
   TBranch        *b_calojetParts08_core_bits;   //!
   TBranch        *b_calojetParts08_core_charge;   //!
   TBranch        *b_calojetParts08_core_p4_mass;   //!
   TBranch        *b_calojetParts08_core_p4_px;   //!
   TBranch        *b_calojetParts08_core_p4_py;   //!
   TBranch        *b_calojetParts08_core_p4_pz;   //!
   TBranch        *b_calojetParts08_core_pdgId;   //!
   TBranch        *b_calojetParts08_core_status;   //!
   TBranch        *b_calojetParts08_core_vertex_x;   //!
   TBranch        *b_calojetParts08_core_vertex_y;   //!
   TBranch        *b_calojetParts08_core_vertex_z;   //!
   TBranch        *b_calojetParts08_tracks_begin;   //!
   TBranch        *b_calojetParts08_tracks_end;   //!
   TBranch        *b_calojetParts08_clusters_begin;   //!
   TBranch        *b_calojetParts08_clusters_end;   //!
   TBranch        *b_calojetParts08#0_;   //!
   TBranch        *b_calojetParts08#0_index;   //!
   TBranch        *b_calojetParts08#0_collectionID;   //!
   TBranch        *b_calojetParts08#1_;   //!
   TBranch        *b_calojetParts08#1_index;   //!
   TBranch        *b_calojetParts08#1_collectionID;   //!
   TBranch        *b_calojetsOneSubJettiness08_;   //!
   TBranch        *b_calojetsOneSubJettiness08_tag;   //!
   TBranch        *b_calojetsOneSubJettiness08#0_;   //!
   TBranch        *b_calojetsOneSubJettiness08#0_index;   //!
   TBranch        *b_calojetsOneSubJettiness08#0_collectionID;   //!
   TBranch        *b_calojetsTwoSubJettiness08_;   //!
   TBranch        *b_calojetsTwoSubJettiness08_tag;   //!
   TBranch        *b_calojetsTwoSubJettiness08#0_;   //!
   TBranch        *b_calojetsTwoSubJettiness08#0_index;   //!
   TBranch        *b_calojetsTwoSubJettiness08#0_collectionID;   //!
   TBranch        *b_calojetsThreeSubJettiness08_;   //!
   TBranch        *b_calojetsThreeSubJettiness08_tag;   //!
   TBranch        *b_calojetsThreeSubJettiness08#0_;   //!
   TBranch        *b_calojetsThreeSubJettiness08#0_index;   //!
   TBranch        *b_calojetsThreeSubJettiness08#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged08_;   //!
   TBranch        *b_calosubjetsTrimmingTagged08_subjets_begin;   //!
   TBranch        *b_calosubjetsTrimmingTagged08_subjets_end;   //!
   TBranch        *b_calosubjetsTrimmingTagged08#0_;   //!
   TBranch        *b_calosubjetsTrimmingTagged08#0_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged08#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged08#1_;   //!
   TBranch        *b_calosubjetsTrimmingTagged08#1_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged08#1_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged08_;   //!
   TBranch        *b_calosubjetsPruningTagged08_subjets_begin;   //!
   TBranch        *b_calosubjetsPruningTagged08_subjets_end;   //!
   TBranch        *b_calosubjetsPruningTagged08#0_;   //!
   TBranch        *b_calosubjetsPruningTagged08#0_index;   //!
   TBranch        *b_calosubjetsPruningTagged08#0_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged08#1_;   //!
   TBranch        *b_calosubjetsPruningTagged08#1_index;   //!
   TBranch        *b_calosubjetsPruningTagged08#1_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged08_;   //!
   TBranch        *b_calosubjetsSoftDropTagged08_subjets_begin;   //!
   TBranch        *b_calosubjetsSoftDropTagged08_subjets_end;   //!
   TBranch        *b_calosubjetsSoftDropTagged08#0_;   //!
   TBranch        *b_calosubjetsSoftDropTagged08#0_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged08#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged08#1_;   //!
   TBranch        *b_calosubjetsSoftDropTagged08#1_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged08#1_collectionID;   //!
   TBranch        *b_calosubjetsTrimming08_;   //!
   TBranch        *b_calosubjetsTrimming08_core_area;   //!
   TBranch        *b_calosubjetsTrimming08_core_bits;   //!
   TBranch        *b_calosubjetsTrimming08_core_p4_mass;   //!
   TBranch        *b_calosubjetsTrimming08_core_p4_px;   //!
   TBranch        *b_calosubjetsTrimming08_core_p4_py;   //!
   TBranch        *b_calosubjetsTrimming08_core_p4_pz;   //!
   TBranch        *b_calosubjetsTrimming08_particles_begin;   //!
   TBranch        *b_calosubjetsTrimming08_particles_end;   //!
   TBranch        *b_calosubjetsTrimming08#0_;   //!
   TBranch        *b_calosubjetsTrimming08#0_index;   //!
   TBranch        *b_calosubjetsTrimming08#0_collectionID;   //!
   TBranch        *b_calosubjetsPruning08_;   //!
   TBranch        *b_calosubjetsPruning08_core_area;   //!
   TBranch        *b_calosubjetsPruning08_core_bits;   //!
   TBranch        *b_calosubjetsPruning08_core_p4_mass;   //!
   TBranch        *b_calosubjetsPruning08_core_p4_px;   //!
   TBranch        *b_calosubjetsPruning08_core_p4_py;   //!
   TBranch        *b_calosubjetsPruning08_core_p4_pz;   //!
   TBranch        *b_calosubjetsPruning08_particles_begin;   //!
   TBranch        *b_calosubjetsPruning08_particles_end;   //!
   TBranch        *b_calosubjetsPruning08#0_;   //!
   TBranch        *b_calosubjetsPruning08#0_index;   //!
   TBranch        *b_calosubjetsPruning08#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDrop08_;   //!
   TBranch        *b_calosubjetsSoftDrop08_core_area;   //!
   TBranch        *b_calosubjetsSoftDrop08_core_bits;   //!
   TBranch        *b_calosubjetsSoftDrop08_core_p4_mass;   //!
   TBranch        *b_calosubjetsSoftDrop08_core_p4_px;   //!
   TBranch        *b_calosubjetsSoftDrop08_core_p4_py;   //!
   TBranch        *b_calosubjetsSoftDrop08_core_p4_pz;   //!
   TBranch        *b_calosubjetsSoftDrop08_particles_begin;   //!
   TBranch        *b_calosubjetsSoftDrop08_particles_end;   //!
   TBranch        *b_calosubjetsSoftDrop08#0_;   //!
   TBranch        *b_calosubjetsSoftDrop08#0_index;   //!
   TBranch        *b_calosubjetsSoftDrop08#0_collectionID;   //!
   TBranch        *b_calojets15_;   //!
   TBranch        *b_calojets15_core_area;   //!
   TBranch        *b_calojets15_core_bits;   //!
   TBranch        *b_calojets15_core_p4_mass;   //!
   TBranch        *b_calojets15_core_p4_px;   //!
   TBranch        *b_calojets15_core_p4_py;   //!
   TBranch        *b_calojets15_core_p4_pz;   //!
   TBranch        *b_calojets15_particles_begin;   //!
   TBranch        *b_calojets15_particles_end;   //!
   TBranch        *b_calojets15#0_;   //!
   TBranch        *b_calojets15#0_index;   //!
   TBranch        *b_calojets15#0_collectionID;   //!
   TBranch        *b_calojetsFlavor15_;   //!
   TBranch        *b_calojetsFlavor15_tag;   //!
   TBranch        *b_calojetsFlavor15#0_;   //!
   TBranch        *b_calojetsFlavor15#0_index;   //!
   TBranch        *b_calojetsFlavor15#0_collectionID;   //!
   TBranch        *b_calobTags15_;   //!
   TBranch        *b_calobTags15_tag;   //!
   TBranch        *b_calobTags15#0_;   //!
   TBranch        *b_calobTags15#0_index;   //!
   TBranch        *b_calobTags15#0_collectionID;   //!
   TBranch        *b_calocTags15_;   //!
   TBranch        *b_calocTags15_tag;   //!
   TBranch        *b_calocTags15#0_;   //!
   TBranch        *b_calocTags15#0_index;   //!
   TBranch        *b_calocTags15#0_collectionID;   //!
   TBranch        *b_calotauTags15_;   //!
   TBranch        *b_calotauTags15_tag;   //!
   TBranch        *b_calotauTags15#0_;   //!
   TBranch        *b_calotauTags15#0_index;   //!
   TBranch        *b_calotauTags15#0_collectionID;   //!
   TBranch        *b_calojetParts15_;   //!
   TBranch        *b_calojetParts15_core_bits;   //!
   TBranch        *b_calojetParts15_core_charge;   //!
   TBranch        *b_calojetParts15_core_p4_mass;   //!
   TBranch        *b_calojetParts15_core_p4_px;   //!
   TBranch        *b_calojetParts15_core_p4_py;   //!
   TBranch        *b_calojetParts15_core_p4_pz;   //!
   TBranch        *b_calojetParts15_core_pdgId;   //!
   TBranch        *b_calojetParts15_core_status;   //!
   TBranch        *b_calojetParts15_core_vertex_x;   //!
   TBranch        *b_calojetParts15_core_vertex_y;   //!
   TBranch        *b_calojetParts15_core_vertex_z;   //!
   TBranch        *b_calojetParts15_tracks_begin;   //!
   TBranch        *b_calojetParts15_tracks_end;   //!
   TBranch        *b_calojetParts15_clusters_begin;   //!
   TBranch        *b_calojetParts15_clusters_end;   //!
   TBranch        *b_calojetParts15#0_;   //!
   TBranch        *b_calojetParts15#0_index;   //!
   TBranch        *b_calojetParts15#0_collectionID;   //!
   TBranch        *b_calojetParts15#1_;   //!
   TBranch        *b_calojetParts15#1_index;   //!
   TBranch        *b_calojetParts15#1_collectionID;   //!
   TBranch        *b_calojetsOneSubJettiness15_;   //!
   TBranch        *b_calojetsOneSubJettiness15_tag;   //!
   TBranch        *b_calojetsOneSubJettiness15#0_;   //!
   TBranch        *b_calojetsOneSubJettiness15#0_index;   //!
   TBranch        *b_calojetsOneSubJettiness15#0_collectionID;   //!
   TBranch        *b_calojetsTwoSubJettiness15_;   //!
   TBranch        *b_calojetsTwoSubJettiness15_tag;   //!
   TBranch        *b_calojetsTwoSubJettiness15#0_;   //!
   TBranch        *b_calojetsTwoSubJettiness15#0_index;   //!
   TBranch        *b_calojetsTwoSubJettiness15#0_collectionID;   //!
   TBranch        *b_calojetsThreeSubJettiness15_;   //!
   TBranch        *b_calojetsThreeSubJettiness15_tag;   //!
   TBranch        *b_calojetsThreeSubJettiness15#0_;   //!
   TBranch        *b_calojetsThreeSubJettiness15#0_index;   //!
   TBranch        *b_calojetsThreeSubJettiness15#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged15_;   //!
   TBranch        *b_calosubjetsTrimmingTagged15_subjets_begin;   //!
   TBranch        *b_calosubjetsTrimmingTagged15_subjets_end;   //!
   TBranch        *b_calosubjetsTrimmingTagged15#0_;   //!
   TBranch        *b_calosubjetsTrimmingTagged15#0_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged15#0_collectionID;   //!
   TBranch        *b_calosubjetsTrimmingTagged15#1_;   //!
   TBranch        *b_calosubjetsTrimmingTagged15#1_index;   //!
   TBranch        *b_calosubjetsTrimmingTagged15#1_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged15_;   //!
   TBranch        *b_calosubjetsPruningTagged15_subjets_begin;   //!
   TBranch        *b_calosubjetsPruningTagged15_subjets_end;   //!
   TBranch        *b_calosubjetsPruningTagged15#0_;   //!
   TBranch        *b_calosubjetsPruningTagged15#0_index;   //!
   TBranch        *b_calosubjetsPruningTagged15#0_collectionID;   //!
   TBranch        *b_calosubjetsPruningTagged15#1_;   //!
   TBranch        *b_calosubjetsPruningTagged15#1_index;   //!
   TBranch        *b_calosubjetsPruningTagged15#1_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged15_;   //!
   TBranch        *b_calosubjetsSoftDropTagged15_subjets_begin;   //!
   TBranch        *b_calosubjetsSoftDropTagged15_subjets_end;   //!
   TBranch        *b_calosubjetsSoftDropTagged15#0_;   //!
   TBranch        *b_calosubjetsSoftDropTagged15#0_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged15#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDropTagged15#1_;   //!
   TBranch        *b_calosubjetsSoftDropTagged15#1_index;   //!
   TBranch        *b_calosubjetsSoftDropTagged15#1_collectionID;   //!
   TBranch        *b_calosubjetsTrimming15_;   //!
   TBranch        *b_calosubjetsTrimming15_core_area;   //!
   TBranch        *b_calosubjetsTrimming15_core_bits;   //!
   TBranch        *b_calosubjetsTrimming15_core_p4_mass;   //!
   TBranch        *b_calosubjetsTrimming15_core_p4_px;   //!
   TBranch        *b_calosubjetsTrimming15_core_p4_py;   //!
   TBranch        *b_calosubjetsTrimming15_core_p4_pz;   //!
   TBranch        *b_calosubjetsTrimming15_particles_begin;   //!
   TBranch        *b_calosubjetsTrimming15_particles_end;   //!
   TBranch        *b_calosubjetsTrimming15#0_;   //!
   TBranch        *b_calosubjetsTrimming15#0_index;   //!
   TBranch        *b_calosubjetsTrimming15#0_collectionID;   //!
   TBranch        *b_calosubjetsPruning15_;   //!
   TBranch        *b_calosubjetsPruning15_core_area;   //!
   TBranch        *b_calosubjetsPruning15_core_bits;   //!
   TBranch        *b_calosubjetsPruning15_core_p4_mass;   //!
   TBranch        *b_calosubjetsPruning15_core_p4_px;   //!
   TBranch        *b_calosubjetsPruning15_core_p4_py;   //!
   TBranch        *b_calosubjetsPruning15_core_p4_pz;   //!
   TBranch        *b_calosubjetsPruning15_particles_begin;   //!
   TBranch        *b_calosubjetsPruning15_particles_end;   //!
   TBranch        *b_calosubjetsPruning15#0_;   //!
   TBranch        *b_calosubjetsPruning15#0_index;   //!
   TBranch        *b_calosubjetsPruning15#0_collectionID;   //!
   TBranch        *b_calosubjetsSoftDrop15_;   //!
   TBranch        *b_calosubjetsSoftDrop15_core_area;   //!
   TBranch        *b_calosubjetsSoftDrop15_core_bits;   //!
   TBranch        *b_calosubjetsSoftDrop15_core_p4_mass;   //!
   TBranch        *b_calosubjetsSoftDrop15_core_p4_px;   //!
   TBranch        *b_calosubjetsSoftDrop15_core_p4_py;   //!
   TBranch        *b_calosubjetsSoftDrop15_core_p4_pz;   //!
   TBranch        *b_calosubjetsSoftDrop15_particles_begin;   //!
   TBranch        *b_calosubjetsSoftDrop15_particles_end;   //!
   TBranch        *b_calosubjetsSoftDrop15#0_;   //!
   TBranch        *b_calosubjetsSoftDrop15#0_index;   //!
   TBranch        *b_calosubjetsSoftDrop15#0_collectionID;   //!
   TBranch        *b_pfjets02_;   //!
   TBranch        *b_pfjets02_core_area;   //!
   TBranch        *b_pfjets02_core_bits;   //!
   TBranch        *b_pfjets02_core_p4_mass;   //!
   TBranch        *b_pfjets02_core_p4_px;   //!
   TBranch        *b_pfjets02_core_p4_py;   //!
   TBranch        *b_pfjets02_core_p4_pz;   //!
   TBranch        *b_pfjets02_particles_begin;   //!
   TBranch        *b_pfjets02_particles_end;   //!
   TBranch        *b_pfjets02#0_;   //!
   TBranch        *b_pfjets02#0_index;   //!
   TBranch        *b_pfjets02#0_collectionID;   //!
   TBranch        *b_pfjetsFlavor02_;   //!
   TBranch        *b_pfjetsFlavor02_tag;   //!
   TBranch        *b_pfjetsFlavor02#0_;   //!
   TBranch        *b_pfjetsFlavor02#0_index;   //!
   TBranch        *b_pfjetsFlavor02#0_collectionID;   //!
   TBranch        *b_pfbTags02_;   //!
   TBranch        *b_pfbTags02_tag;   //!
   TBranch        *b_pfbTags02#0_;   //!
   TBranch        *b_pfbTags02#0_index;   //!
   TBranch        *b_pfbTags02#0_collectionID;   //!
   TBranch        *b_pfcTags02_;   //!
   TBranch        *b_pfcTags02_tag;   //!
   TBranch        *b_pfcTags02#0_;   //!
   TBranch        *b_pfcTags02#0_index;   //!
   TBranch        *b_pfcTags02#0_collectionID;   //!
   TBranch        *b_pftauTags02_;   //!
   TBranch        *b_pftauTags02_tag;   //!
   TBranch        *b_pftauTags02#0_;   //!
   TBranch        *b_pftauTags02#0_index;   //!
   TBranch        *b_pftauTags02#0_collectionID;   //!
   TBranch        *b_pfjetParts02_;   //!
   TBranch        *b_pfjetParts02_core_bits;   //!
   TBranch        *b_pfjetParts02_core_charge;   //!
   TBranch        *b_pfjetParts02_core_p4_mass;   //!
   TBranch        *b_pfjetParts02_core_p4_px;   //!
   TBranch        *b_pfjetParts02_core_p4_py;   //!
   TBranch        *b_pfjetParts02_core_p4_pz;   //!
   TBranch        *b_pfjetParts02_core_pdgId;   //!
   TBranch        *b_pfjetParts02_core_status;   //!
   TBranch        *b_pfjetParts02_core_vertex_x;   //!
   TBranch        *b_pfjetParts02_core_vertex_y;   //!
   TBranch        *b_pfjetParts02_core_vertex_z;   //!
   TBranch        *b_pfjetParts02_tracks_begin;   //!
   TBranch        *b_pfjetParts02_tracks_end;   //!
   TBranch        *b_pfjetParts02_clusters_begin;   //!
   TBranch        *b_pfjetParts02_clusters_end;   //!
   TBranch        *b_pfjetParts02#0_;   //!
   TBranch        *b_pfjetParts02#0_index;   //!
   TBranch        *b_pfjetParts02#0_collectionID;   //!
   TBranch        *b_pfjetParts02#1_;   //!
   TBranch        *b_pfjetParts02#1_index;   //!
   TBranch        *b_pfjetParts02#1_collectionID;   //!
   TBranch        *b_pfjetsOneSubJettiness02_;   //!
   TBranch        *b_pfjetsOneSubJettiness02_tag;   //!
   TBranch        *b_pfjetsOneSubJettiness02#0_;   //!
   TBranch        *b_pfjetsOneSubJettiness02#0_index;   //!
   TBranch        *b_pfjetsOneSubJettiness02#0_collectionID;   //!
   TBranch        *b_pfjetsTwoSubJettiness02_;   //!
   TBranch        *b_pfjetsTwoSubJettiness02_tag;   //!
   TBranch        *b_pfjetsTwoSubJettiness02#0_;   //!
   TBranch        *b_pfjetsTwoSubJettiness02#0_index;   //!
   TBranch        *b_pfjetsTwoSubJettiness02#0_collectionID;   //!
   TBranch        *b_pfjetsThreeSubJettiness02_;   //!
   TBranch        *b_pfjetsThreeSubJettiness02_tag;   //!
   TBranch        *b_pfjetsThreeSubJettiness02#0_;   //!
   TBranch        *b_pfjetsThreeSubJettiness02#0_index;   //!
   TBranch        *b_pfjetsThreeSubJettiness02#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02_subjets_begin;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02_subjets_end;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02#0_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02#0_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02#1_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02#1_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged02#1_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged02_;   //!
   TBranch        *b_pfsubjetsPruningTagged02_subjets_begin;   //!
   TBranch        *b_pfsubjetsPruningTagged02_subjets_end;   //!
   TBranch        *b_pfsubjetsPruningTagged02#0_;   //!
   TBranch        *b_pfsubjetsPruningTagged02#0_index;   //!
   TBranch        *b_pfsubjetsPruningTagged02#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged02#1_;   //!
   TBranch        *b_pfsubjetsPruningTagged02#1_index;   //!
   TBranch        *b_pfsubjetsPruningTagged02#1_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02_subjets_begin;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02_subjets_end;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02#0_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02#0_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02#1_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02#1_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged02#1_collectionID;   //!
   TBranch        *b_pfsubjetsTrimming02_;   //!
   TBranch        *b_pfsubjetsTrimming02_core_area;   //!
   TBranch        *b_pfsubjetsTrimming02_core_bits;   //!
   TBranch        *b_pfsubjetsTrimming02_core_p4_mass;   //!
   TBranch        *b_pfsubjetsTrimming02_core_p4_px;   //!
   TBranch        *b_pfsubjetsTrimming02_core_p4_py;   //!
   TBranch        *b_pfsubjetsTrimming02_core_p4_pz;   //!
   TBranch        *b_pfsubjetsTrimming02_particles_begin;   //!
   TBranch        *b_pfsubjetsTrimming02_particles_end;   //!
   TBranch        *b_pfsubjetsTrimming02#0_;   //!
   TBranch        *b_pfsubjetsTrimming02#0_index;   //!
   TBranch        *b_pfsubjetsTrimming02#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruning02_;   //!
   TBranch        *b_pfsubjetsPruning02_core_area;   //!
   TBranch        *b_pfsubjetsPruning02_core_bits;   //!
   TBranch        *b_pfsubjetsPruning02_core_p4_mass;   //!
   TBranch        *b_pfsubjetsPruning02_core_p4_px;   //!
   TBranch        *b_pfsubjetsPruning02_core_p4_py;   //!
   TBranch        *b_pfsubjetsPruning02_core_p4_pz;   //!
   TBranch        *b_pfsubjetsPruning02_particles_begin;   //!
   TBranch        *b_pfsubjetsPruning02_particles_end;   //!
   TBranch        *b_pfsubjetsPruning02#0_;   //!
   TBranch        *b_pfsubjetsPruning02#0_index;   //!
   TBranch        *b_pfsubjetsPruning02#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDrop02_;   //!
   TBranch        *b_pfsubjetsSoftDrop02_core_area;   //!
   TBranch        *b_pfsubjetsSoftDrop02_core_bits;   //!
   TBranch        *b_pfsubjetsSoftDrop02_core_p4_mass;   //!
   TBranch        *b_pfsubjetsSoftDrop02_core_p4_px;   //!
   TBranch        *b_pfsubjetsSoftDrop02_core_p4_py;   //!
   TBranch        *b_pfsubjetsSoftDrop02_core_p4_pz;   //!
   TBranch        *b_pfsubjetsSoftDrop02_particles_begin;   //!
   TBranch        *b_pfsubjetsSoftDrop02_particles_end;   //!
   TBranch        *b_pfsubjetsSoftDrop02#0_;   //!
   TBranch        *b_pfsubjetsSoftDrop02#0_index;   //!
   TBranch        *b_pfsubjetsSoftDrop02#0_collectionID;   //!
   TBranch        *b_pfjets04_;   //!
   TBranch        *b_pfjets04_core_area;   //!
   TBranch        *b_pfjets04_core_bits;   //!
   TBranch        *b_pfjets04_core_p4_mass;   //!
   TBranch        *b_pfjets04_core_p4_px;   //!
   TBranch        *b_pfjets04_core_p4_py;   //!
   TBranch        *b_pfjets04_core_p4_pz;   //!
   TBranch        *b_pfjets04_particles_begin;   //!
   TBranch        *b_pfjets04_particles_end;   //!
   TBranch        *b_pfjets04#0_;   //!
   TBranch        *b_pfjets04#0_index;   //!
   TBranch        *b_pfjets04#0_collectionID;   //!
   TBranch        *b_pfjetsFlavor04_;   //!
   TBranch        *b_pfjetsFlavor04_tag;   //!
   TBranch        *b_pfjetsFlavor04#0_;   //!
   TBranch        *b_pfjetsFlavor04#0_index;   //!
   TBranch        *b_pfjetsFlavor04#0_collectionID;   //!
   TBranch        *b_pfbTags04_;   //!
   TBranch        *b_pfbTags04_tag;   //!
   TBranch        *b_pfbTags04#0_;   //!
   TBranch        *b_pfbTags04#0_index;   //!
   TBranch        *b_pfbTags04#0_collectionID;   //!
   TBranch        *b_pfcTags04_;   //!
   TBranch        *b_pfcTags04_tag;   //!
   TBranch        *b_pfcTags04#0_;   //!
   TBranch        *b_pfcTags04#0_index;   //!
   TBranch        *b_pfcTags04#0_collectionID;   //!
   TBranch        *b_pftauTags04_;   //!
   TBranch        *b_pftauTags04_tag;   //!
   TBranch        *b_pftauTags04#0_;   //!
   TBranch        *b_pftauTags04#0_index;   //!
   TBranch        *b_pftauTags04#0_collectionID;   //!
   TBranch        *b_pfjetParts04_;   //!
   TBranch        *b_pfjetParts04_core_bits;   //!
   TBranch        *b_pfjetParts04_core_charge;   //!
   TBranch        *b_pfjetParts04_core_p4_mass;   //!
   TBranch        *b_pfjetParts04_core_p4_px;   //!
   TBranch        *b_pfjetParts04_core_p4_py;   //!
   TBranch        *b_pfjetParts04_core_p4_pz;   //!
   TBranch        *b_pfjetParts04_core_pdgId;   //!
   TBranch        *b_pfjetParts04_core_status;   //!
   TBranch        *b_pfjetParts04_core_vertex_x;   //!
   TBranch        *b_pfjetParts04_core_vertex_y;   //!
   TBranch        *b_pfjetParts04_core_vertex_z;   //!
   TBranch        *b_pfjetParts04_tracks_begin;   //!
   TBranch        *b_pfjetParts04_tracks_end;   //!
   TBranch        *b_pfjetParts04_clusters_begin;   //!
   TBranch        *b_pfjetParts04_clusters_end;   //!
   TBranch        *b_pfjetParts04#0_;   //!
   TBranch        *b_pfjetParts04#0_index;   //!
   TBranch        *b_pfjetParts04#0_collectionID;   //!
   TBranch        *b_pfjetParts04#1_;   //!
   TBranch        *b_pfjetParts04#1_index;   //!
   TBranch        *b_pfjetParts04#1_collectionID;   //!
   TBranch        *b_pfjetsOneSubJettiness04_;   //!
   TBranch        *b_pfjetsOneSubJettiness04_tag;   //!
   TBranch        *b_pfjetsOneSubJettiness04#0_;   //!
   TBranch        *b_pfjetsOneSubJettiness04#0_index;   //!
   TBranch        *b_pfjetsOneSubJettiness04#0_collectionID;   //!
   TBranch        *b_pfjetsTwoSubJettiness04_;   //!
   TBranch        *b_pfjetsTwoSubJettiness04_tag;   //!
   TBranch        *b_pfjetsTwoSubJettiness04#0_;   //!
   TBranch        *b_pfjetsTwoSubJettiness04#0_index;   //!
   TBranch        *b_pfjetsTwoSubJettiness04#0_collectionID;   //!
   TBranch        *b_pfjetsThreeSubJettiness04_;   //!
   TBranch        *b_pfjetsThreeSubJettiness04_tag;   //!
   TBranch        *b_pfjetsThreeSubJettiness04#0_;   //!
   TBranch        *b_pfjetsThreeSubJettiness04#0_index;   //!
   TBranch        *b_pfjetsThreeSubJettiness04#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04_subjets_begin;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04_subjets_end;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04#0_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04#0_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04#1_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04#1_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged04#1_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged04_;   //!
   TBranch        *b_pfsubjetsPruningTagged04_subjets_begin;   //!
   TBranch        *b_pfsubjetsPruningTagged04_subjets_end;   //!
   TBranch        *b_pfsubjetsPruningTagged04#0_;   //!
   TBranch        *b_pfsubjetsPruningTagged04#0_index;   //!
   TBranch        *b_pfsubjetsPruningTagged04#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged04#1_;   //!
   TBranch        *b_pfsubjetsPruningTagged04#1_index;   //!
   TBranch        *b_pfsubjetsPruningTagged04#1_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04_subjets_begin;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04_subjets_end;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04#0_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04#0_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04#1_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04#1_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged04#1_collectionID;   //!
   TBranch        *b_pfsubjetsTrimming04_;   //!
   TBranch        *b_pfsubjetsTrimming04_core_area;   //!
   TBranch        *b_pfsubjetsTrimming04_core_bits;   //!
   TBranch        *b_pfsubjetsTrimming04_core_p4_mass;   //!
   TBranch        *b_pfsubjetsTrimming04_core_p4_px;   //!
   TBranch        *b_pfsubjetsTrimming04_core_p4_py;   //!
   TBranch        *b_pfsubjetsTrimming04_core_p4_pz;   //!
   TBranch        *b_pfsubjetsTrimming04_particles_begin;   //!
   TBranch        *b_pfsubjetsTrimming04_particles_end;   //!
   TBranch        *b_pfsubjetsTrimming04#0_;   //!
   TBranch        *b_pfsubjetsTrimming04#0_index;   //!
   TBranch        *b_pfsubjetsTrimming04#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruning04_;   //!
   TBranch        *b_pfsubjetsPruning04_core_area;   //!
   TBranch        *b_pfsubjetsPruning04_core_bits;   //!
   TBranch        *b_pfsubjetsPruning04_core_p4_mass;   //!
   TBranch        *b_pfsubjetsPruning04_core_p4_px;   //!
   TBranch        *b_pfsubjetsPruning04_core_p4_py;   //!
   TBranch        *b_pfsubjetsPruning04_core_p4_pz;   //!
   TBranch        *b_pfsubjetsPruning04_particles_begin;   //!
   TBranch        *b_pfsubjetsPruning04_particles_end;   //!
   TBranch        *b_pfsubjetsPruning04#0_;   //!
   TBranch        *b_pfsubjetsPruning04#0_index;   //!
   TBranch        *b_pfsubjetsPruning04#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDrop04_;   //!
   TBranch        *b_pfsubjetsSoftDrop04_core_area;   //!
   TBranch        *b_pfsubjetsSoftDrop04_core_bits;   //!
   TBranch        *b_pfsubjetsSoftDrop04_core_p4_mass;   //!
   TBranch        *b_pfsubjetsSoftDrop04_core_p4_px;   //!
   TBranch        *b_pfsubjetsSoftDrop04_core_p4_py;   //!
   TBranch        *b_pfsubjetsSoftDrop04_core_p4_pz;   //!
   TBranch        *b_pfsubjetsSoftDrop04_particles_begin;   //!
   TBranch        *b_pfsubjetsSoftDrop04_particles_end;   //!
   TBranch        *b_pfsubjetsSoftDrop04#0_;   //!
   TBranch        *b_pfsubjetsSoftDrop04#0_index;   //!
   TBranch        *b_pfsubjetsSoftDrop04#0_collectionID;   //!
   TBranch        *b_pfjets08_;   //!
   TBranch        *b_pfjets08_core_area;   //!
   TBranch        *b_pfjets08_core_bits;   //!
   TBranch        *b_pfjets08_core_p4_mass;   //!
   TBranch        *b_pfjets08_core_p4_px;   //!
   TBranch        *b_pfjets08_core_p4_py;   //!
   TBranch        *b_pfjets08_core_p4_pz;   //!
   TBranch        *b_pfjets08_particles_begin;   //!
   TBranch        *b_pfjets08_particles_end;   //!
   TBranch        *b_pfjets08#0_;   //!
   TBranch        *b_pfjets08#0_index;   //!
   TBranch        *b_pfjets08#0_collectionID;   //!
   TBranch        *b_pfjetsFlavor08_;   //!
   TBranch        *b_pfjetsFlavor08_tag;   //!
   TBranch        *b_pfjetsFlavor08#0_;   //!
   TBranch        *b_pfjetsFlavor08#0_index;   //!
   TBranch        *b_pfjetsFlavor08#0_collectionID;   //!
   TBranch        *b_pfbTags08_;   //!
   TBranch        *b_pfbTags08_tag;   //!
   TBranch        *b_pfbTags08#0_;   //!
   TBranch        *b_pfbTags08#0_index;   //!
   TBranch        *b_pfbTags08#0_collectionID;   //!
   TBranch        *b_pfcTags08_;   //!
   TBranch        *b_pfcTags08_tag;   //!
   TBranch        *b_pfcTags08#0_;   //!
   TBranch        *b_pfcTags08#0_index;   //!
   TBranch        *b_pfcTags08#0_collectionID;   //!
   TBranch        *b_pftauTags08_;   //!
   TBranch        *b_pftauTags08_tag;   //!
   TBranch        *b_pftauTags08#0_;   //!
   TBranch        *b_pftauTags08#0_index;   //!
   TBranch        *b_pftauTags08#0_collectionID;   //!
   TBranch        *b_pfjetParts08_;   //!
   TBranch        *b_pfjetParts08_core_bits;   //!
   TBranch        *b_pfjetParts08_core_charge;   //!
   TBranch        *b_pfjetParts08_core_p4_mass;   //!
   TBranch        *b_pfjetParts08_core_p4_px;   //!
   TBranch        *b_pfjetParts08_core_p4_py;   //!
   TBranch        *b_pfjetParts08_core_p4_pz;   //!
   TBranch        *b_pfjetParts08_core_pdgId;   //!
   TBranch        *b_pfjetParts08_core_status;   //!
   TBranch        *b_pfjetParts08_core_vertex_x;   //!
   TBranch        *b_pfjetParts08_core_vertex_y;   //!
   TBranch        *b_pfjetParts08_core_vertex_z;   //!
   TBranch        *b_pfjetParts08_tracks_begin;   //!
   TBranch        *b_pfjetParts08_tracks_end;   //!
   TBranch        *b_pfjetParts08_clusters_begin;   //!
   TBranch        *b_pfjetParts08_clusters_end;   //!
   TBranch        *b_pfjetParts08#0_;   //!
   TBranch        *b_pfjetParts08#0_index;   //!
   TBranch        *b_pfjetParts08#0_collectionID;   //!
   TBranch        *b_pfjetParts08#1_;   //!
   TBranch        *b_pfjetParts08#1_index;   //!
   TBranch        *b_pfjetParts08#1_collectionID;   //!
   TBranch        *b_pfjetsOneSubJettiness08_;   //!
   TBranch        *b_pfjetsOneSubJettiness08_tag;   //!
   TBranch        *b_pfjetsOneSubJettiness08#0_;   //!
   TBranch        *b_pfjetsOneSubJettiness08#0_index;   //!
   TBranch        *b_pfjetsOneSubJettiness08#0_collectionID;   //!
   TBranch        *b_pfjetsTwoSubJettiness08_;   //!
   TBranch        *b_pfjetsTwoSubJettiness08_tag;   //!
   TBranch        *b_pfjetsTwoSubJettiness08#0_;   //!
   TBranch        *b_pfjetsTwoSubJettiness08#0_index;   //!
   TBranch        *b_pfjetsTwoSubJettiness08#0_collectionID;   //!
   TBranch        *b_pfjetsThreeSubJettiness08_;   //!
   TBranch        *b_pfjetsThreeSubJettiness08_tag;   //!
   TBranch        *b_pfjetsThreeSubJettiness08#0_;   //!
   TBranch        *b_pfjetsThreeSubJettiness08#0_index;   //!
   TBranch        *b_pfjetsThreeSubJettiness08#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08_subjets_begin;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08_subjets_end;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08#0_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08#0_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08#1_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08#1_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged08#1_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged08_;   //!
   TBranch        *b_pfsubjetsPruningTagged08_subjets_begin;   //!
   TBranch        *b_pfsubjetsPruningTagged08_subjets_end;   //!
   TBranch        *b_pfsubjetsPruningTagged08#0_;   //!
   TBranch        *b_pfsubjetsPruningTagged08#0_index;   //!
   TBranch        *b_pfsubjetsPruningTagged08#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged08#1_;   //!
   TBranch        *b_pfsubjetsPruningTagged08#1_index;   //!
   TBranch        *b_pfsubjetsPruningTagged08#1_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08_subjets_begin;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08_subjets_end;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08#0_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08#0_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08#1_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08#1_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged08#1_collectionID;   //!
   TBranch        *b_pfsubjetsTrimming08_;   //!
   TBranch        *b_pfsubjetsTrimming08_core_area;   //!
   TBranch        *b_pfsubjetsTrimming08_core_bits;   //!
   TBranch        *b_pfsubjetsTrimming08_core_p4_mass;   //!
   TBranch        *b_pfsubjetsTrimming08_core_p4_px;   //!
   TBranch        *b_pfsubjetsTrimming08_core_p4_py;   //!
   TBranch        *b_pfsubjetsTrimming08_core_p4_pz;   //!
   TBranch        *b_pfsubjetsTrimming08_particles_begin;   //!
   TBranch        *b_pfsubjetsTrimming08_particles_end;   //!
   TBranch        *b_pfsubjetsTrimming08#0_;   //!
   TBranch        *b_pfsubjetsTrimming08#0_index;   //!
   TBranch        *b_pfsubjetsTrimming08#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruning08_;   //!
   TBranch        *b_pfsubjetsPruning08_core_area;   //!
   TBranch        *b_pfsubjetsPruning08_core_bits;   //!
   TBranch        *b_pfsubjetsPruning08_core_p4_mass;   //!
   TBranch        *b_pfsubjetsPruning08_core_p4_px;   //!
   TBranch        *b_pfsubjetsPruning08_core_p4_py;   //!
   TBranch        *b_pfsubjetsPruning08_core_p4_pz;   //!
   TBranch        *b_pfsubjetsPruning08_particles_begin;   //!
   TBranch        *b_pfsubjetsPruning08_particles_end;   //!
   TBranch        *b_pfsubjetsPruning08#0_;   //!
   TBranch        *b_pfsubjetsPruning08#0_index;   //!
   TBranch        *b_pfsubjetsPruning08#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDrop08_;   //!
   TBranch        *b_pfsubjetsSoftDrop08_core_area;   //!
   TBranch        *b_pfsubjetsSoftDrop08_core_bits;   //!
   TBranch        *b_pfsubjetsSoftDrop08_core_p4_mass;   //!
   TBranch        *b_pfsubjetsSoftDrop08_core_p4_px;   //!
   TBranch        *b_pfsubjetsSoftDrop08_core_p4_py;   //!
   TBranch        *b_pfsubjetsSoftDrop08_core_p4_pz;   //!
   TBranch        *b_pfsubjetsSoftDrop08_particles_begin;   //!
   TBranch        *b_pfsubjetsSoftDrop08_particles_end;   //!
   TBranch        *b_pfsubjetsSoftDrop08#0_;   //!
   TBranch        *b_pfsubjetsSoftDrop08#0_index;   //!
   TBranch        *b_pfsubjetsSoftDrop08#0_collectionID;   //!
   TBranch        *b_pfjets15_;   //!
   TBranch        *b_pfjets15_core_area;   //!
   TBranch        *b_pfjets15_core_bits;   //!
   TBranch        *b_pfjets15_core_p4_mass;   //!
   TBranch        *b_pfjets15_core_p4_px;   //!
   TBranch        *b_pfjets15_core_p4_py;   //!
   TBranch        *b_pfjets15_core_p4_pz;   //!
   TBranch        *b_pfjets15_particles_begin;   //!
   TBranch        *b_pfjets15_particles_end;   //!
   TBranch        *b_pfjets15#0_;   //!
   TBranch        *b_pfjets15#0_index;   //!
   TBranch        *b_pfjets15#0_collectionID;   //!
   TBranch        *b_pfjetsFlavor15_;   //!
   TBranch        *b_pfjetsFlavor15_tag;   //!
   TBranch        *b_pfjetsFlavor15#0_;   //!
   TBranch        *b_pfjetsFlavor15#0_index;   //!
   TBranch        *b_pfjetsFlavor15#0_collectionID;   //!
   TBranch        *b_pfbTags15_;   //!
   TBranch        *b_pfbTags15_tag;   //!
   TBranch        *b_pfbTags15#0_;   //!
   TBranch        *b_pfbTags15#0_index;   //!
   TBranch        *b_pfbTags15#0_collectionID;   //!
   TBranch        *b_pfcTags15_;   //!
   TBranch        *b_pfcTags15_tag;   //!
   TBranch        *b_pfcTags15#0_;   //!
   TBranch        *b_pfcTags15#0_index;   //!
   TBranch        *b_pfcTags15#0_collectionID;   //!
   TBranch        *b_pftauTags15_;   //!
   TBranch        *b_pftauTags15_tag;   //!
   TBranch        *b_pftauTags15#0_;   //!
   TBranch        *b_pftauTags15#0_index;   //!
   TBranch        *b_pftauTags15#0_collectionID;   //!
   TBranch        *b_pfjetParts15_;   //!
   TBranch        *b_pfjetParts15_core_bits;   //!
   TBranch        *b_pfjetParts15_core_charge;   //!
   TBranch        *b_pfjetParts15_core_p4_mass;   //!
   TBranch        *b_pfjetParts15_core_p4_px;   //!
   TBranch        *b_pfjetParts15_core_p4_py;   //!
   TBranch        *b_pfjetParts15_core_p4_pz;   //!
   TBranch        *b_pfjetParts15_core_pdgId;   //!
   TBranch        *b_pfjetParts15_core_status;   //!
   TBranch        *b_pfjetParts15_core_vertex_x;   //!
   TBranch        *b_pfjetParts15_core_vertex_y;   //!
   TBranch        *b_pfjetParts15_core_vertex_z;   //!
   TBranch        *b_pfjetParts15_tracks_begin;   //!
   TBranch        *b_pfjetParts15_tracks_end;   //!
   TBranch        *b_pfjetParts15_clusters_begin;   //!
   TBranch        *b_pfjetParts15_clusters_end;   //!
   TBranch        *b_pfjetParts15#0_;   //!
   TBranch        *b_pfjetParts15#0_index;   //!
   TBranch        *b_pfjetParts15#0_collectionID;   //!
   TBranch        *b_pfjetParts15#1_;   //!
   TBranch        *b_pfjetParts15#1_index;   //!
   TBranch        *b_pfjetParts15#1_collectionID;   //!
   TBranch        *b_pfjetsOneSubJettiness15_;   //!
   TBranch        *b_pfjetsOneSubJettiness15_tag;   //!
   TBranch        *b_pfjetsOneSubJettiness15#0_;   //!
   TBranch        *b_pfjetsOneSubJettiness15#0_index;   //!
   TBranch        *b_pfjetsOneSubJettiness15#0_collectionID;   //!
   TBranch        *b_pfjetsTwoSubJettiness15_;   //!
   TBranch        *b_pfjetsTwoSubJettiness15_tag;   //!
   TBranch        *b_pfjetsTwoSubJettiness15#0_;   //!
   TBranch        *b_pfjetsTwoSubJettiness15#0_index;   //!
   TBranch        *b_pfjetsTwoSubJettiness15#0_collectionID;   //!
   TBranch        *b_pfjetsThreeSubJettiness15_;   //!
   TBranch        *b_pfjetsThreeSubJettiness15_tag;   //!
   TBranch        *b_pfjetsThreeSubJettiness15#0_;   //!
   TBranch        *b_pfjetsThreeSubJettiness15#0_index;   //!
   TBranch        *b_pfjetsThreeSubJettiness15#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15_subjets_begin;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15_subjets_end;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15#0_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15#0_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15#0_collectionID;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15#1_;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15#1_index;   //!
   TBranch        *b_pfsubjetsTrimmingTagged15#1_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged15_;   //!
   TBranch        *b_pfsubjetsPruningTagged15_subjets_begin;   //!
   TBranch        *b_pfsubjetsPruningTagged15_subjets_end;   //!
   TBranch        *b_pfsubjetsPruningTagged15#0_;   //!
   TBranch        *b_pfsubjetsPruningTagged15#0_index;   //!
   TBranch        *b_pfsubjetsPruningTagged15#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruningTagged15#1_;   //!
   TBranch        *b_pfsubjetsPruningTagged15#1_index;   //!
   TBranch        *b_pfsubjetsPruningTagged15#1_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15_subjets_begin;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15_subjets_end;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15#0_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15#0_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15#1_;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15#1_index;   //!
   TBranch        *b_pfsubjetsSoftDropTagged15#1_collectionID;   //!
   TBranch        *b_pfsubjetsTrimming15_;   //!
   TBranch        *b_pfsubjetsTrimming15_core_area;   //!
   TBranch        *b_pfsubjetsTrimming15_core_bits;   //!
   TBranch        *b_pfsubjetsTrimming15_core_p4_mass;   //!
   TBranch        *b_pfsubjetsTrimming15_core_p4_px;   //!
   TBranch        *b_pfsubjetsTrimming15_core_p4_py;   //!
   TBranch        *b_pfsubjetsTrimming15_core_p4_pz;   //!
   TBranch        *b_pfsubjetsTrimming15_particles_begin;   //!
   TBranch        *b_pfsubjetsTrimming15_particles_end;   //!
   TBranch        *b_pfsubjetsTrimming15#0_;   //!
   TBranch        *b_pfsubjetsTrimming15#0_index;   //!
   TBranch        *b_pfsubjetsTrimming15#0_collectionID;   //!
   TBranch        *b_pfsubjetsPruning15_;   //!
   TBranch        *b_pfsubjetsPruning15_core_area;   //!
   TBranch        *b_pfsubjetsPruning15_core_bits;   //!
   TBranch        *b_pfsubjetsPruning15_core_p4_mass;   //!
   TBranch        *b_pfsubjetsPruning15_core_p4_px;   //!
   TBranch        *b_pfsubjetsPruning15_core_p4_py;   //!
   TBranch        *b_pfsubjetsPruning15_core_p4_pz;   //!
   TBranch        *b_pfsubjetsPruning15_particles_begin;   //!
   TBranch        *b_pfsubjetsPruning15_particles_end;   //!
   TBranch        *b_pfsubjetsPruning15#0_;   //!
   TBranch        *b_pfsubjetsPruning15#0_index;   //!
   TBranch        *b_pfsubjetsPruning15#0_collectionID;   //!
   TBranch        *b_pfsubjetsSoftDrop15_;   //!
   TBranch        *b_pfsubjetsSoftDrop15_core_area;   //!
   TBranch        *b_pfsubjetsSoftDrop15_core_bits;   //!
   TBranch        *b_pfsubjetsSoftDrop15_core_p4_mass;   //!
   TBranch        *b_pfsubjetsSoftDrop15_core_p4_px;   //!
   TBranch        *b_pfsubjetsSoftDrop15_core_p4_py;   //!
   TBranch        *b_pfsubjetsSoftDrop15_core_p4_pz;   //!
   TBranch        *b_pfsubjetsSoftDrop15_particles_begin;   //!
   TBranch        *b_pfsubjetsSoftDrop15_particles_end;   //!
   TBranch        *b_pfsubjetsSoftDrop15#0_;   //!
   TBranch        *b_pfsubjetsSoftDrop15#0_index;   //!
   TBranch        *b_pfsubjetsSoftDrop15#0_collectionID;   //!
   TBranch        *b_trkjets02_;   //!
   TBranch        *b_trkjets02_core_area;   //!
   TBranch        *b_trkjets02_core_bits;   //!
   TBranch        *b_trkjets02_core_p4_mass;   //!
   TBranch        *b_trkjets02_core_p4_px;   //!
   TBranch        *b_trkjets02_core_p4_py;   //!
   TBranch        *b_trkjets02_core_p4_pz;   //!
   TBranch        *b_trkjets02_particles_begin;   //!
   TBranch        *b_trkjets02_particles_end;   //!
   TBranch        *b_trkjets02#0_;   //!
   TBranch        *b_trkjets02#0_index;   //!
   TBranch        *b_trkjets02#0_collectionID;   //!
   TBranch        *b_trkjetsFlavor02_;   //!
   TBranch        *b_trkjetsFlavor02_tag;   //!
   TBranch        *b_trkjetsFlavor02#0_;   //!
   TBranch        *b_trkjetsFlavor02#0_index;   //!
   TBranch        *b_trkjetsFlavor02#0_collectionID;   //!
   TBranch        *b_trkbTags02_;   //!
   TBranch        *b_trkbTags02_tag;   //!
   TBranch        *b_trkbTags02#0_;   //!
   TBranch        *b_trkbTags02#0_index;   //!
   TBranch        *b_trkbTags02#0_collectionID;   //!
   TBranch        *b_trkcTags02_;   //!
   TBranch        *b_trkcTags02_tag;   //!
   TBranch        *b_trkcTags02#0_;   //!
   TBranch        *b_trkcTags02#0_index;   //!
   TBranch        *b_trkcTags02#0_collectionID;   //!
   TBranch        *b_trktauTags02_;   //!
   TBranch        *b_trktauTags02_tag;   //!
   TBranch        *b_trktauTags02#0_;   //!
   TBranch        *b_trktauTags02#0_index;   //!
   TBranch        *b_trktauTags02#0_collectionID;   //!
   TBranch        *b_trkjetParts02_;   //!
   TBranch        *b_trkjetParts02_core_bits;   //!
   TBranch        *b_trkjetParts02_core_charge;   //!
   TBranch        *b_trkjetParts02_core_p4_mass;   //!
   TBranch        *b_trkjetParts02_core_p4_px;   //!
   TBranch        *b_trkjetParts02_core_p4_py;   //!
   TBranch        *b_trkjetParts02_core_p4_pz;   //!
   TBranch        *b_trkjetParts02_core_pdgId;   //!
   TBranch        *b_trkjetParts02_core_status;   //!
   TBranch        *b_trkjetParts02_core_vertex_x;   //!
   TBranch        *b_trkjetParts02_core_vertex_y;   //!
   TBranch        *b_trkjetParts02_core_vertex_z;   //!
   TBranch        *b_trkjetParts02_tracks_begin;   //!
   TBranch        *b_trkjetParts02_tracks_end;   //!
   TBranch        *b_trkjetParts02_clusters_begin;   //!
   TBranch        *b_trkjetParts02_clusters_end;   //!
   TBranch        *b_trkjetParts02#0_;   //!
   TBranch        *b_trkjetParts02#0_index;   //!
   TBranch        *b_trkjetParts02#0_collectionID;   //!
   TBranch        *b_trkjetParts02#1_;   //!
   TBranch        *b_trkjetParts02#1_index;   //!
   TBranch        *b_trkjetParts02#1_collectionID;   //!
   TBranch        *b_trkjetsOneSubJettiness02_;   //!
   TBranch        *b_trkjetsOneSubJettiness02_tag;   //!
   TBranch        *b_trkjetsOneSubJettiness02#0_;   //!
   TBranch        *b_trkjetsOneSubJettiness02#0_index;   //!
   TBranch        *b_trkjetsOneSubJettiness02#0_collectionID;   //!
   TBranch        *b_trkjetsTwoSubJettiness02_;   //!
   TBranch        *b_trkjetsTwoSubJettiness02_tag;   //!
   TBranch        *b_trkjetsTwoSubJettiness02#0_;   //!
   TBranch        *b_trkjetsTwoSubJettiness02#0_index;   //!
   TBranch        *b_trkjetsTwoSubJettiness02#0_collectionID;   //!
   TBranch        *b_trkjetsThreeSubJettiness02_;   //!
   TBranch        *b_trkjetsThreeSubJettiness02_tag;   //!
   TBranch        *b_trkjetsThreeSubJettiness02#0_;   //!
   TBranch        *b_trkjetsThreeSubJettiness02#0_index;   //!
   TBranch        *b_trkjetsThreeSubJettiness02#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged02_;   //!
   TBranch        *b_trksubjetsTrimmingTagged02_subjets_begin;   //!
   TBranch        *b_trksubjetsTrimmingTagged02_subjets_end;   //!
   TBranch        *b_trksubjetsTrimmingTagged02#0_;   //!
   TBranch        *b_trksubjetsTrimmingTagged02#0_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged02#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged02#1_;   //!
   TBranch        *b_trksubjetsTrimmingTagged02#1_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged02#1_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged02_;   //!
   TBranch        *b_trksubjetsPruningTagged02_subjets_begin;   //!
   TBranch        *b_trksubjetsPruningTagged02_subjets_end;   //!
   TBranch        *b_trksubjetsPruningTagged02#0_;   //!
   TBranch        *b_trksubjetsPruningTagged02#0_index;   //!
   TBranch        *b_trksubjetsPruningTagged02#0_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged02#1_;   //!
   TBranch        *b_trksubjetsPruningTagged02#1_index;   //!
   TBranch        *b_trksubjetsPruningTagged02#1_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged02_;   //!
   TBranch        *b_trksubjetsSoftDropTagged02_subjets_begin;   //!
   TBranch        *b_trksubjetsSoftDropTagged02_subjets_end;   //!
   TBranch        *b_trksubjetsSoftDropTagged02#0_;   //!
   TBranch        *b_trksubjetsSoftDropTagged02#0_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged02#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged02#1_;   //!
   TBranch        *b_trksubjetsSoftDropTagged02#1_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged02#1_collectionID;   //!
   TBranch        *b_trksubjetsTrimming02_;   //!
   TBranch        *b_trksubjetsTrimming02_core_area;   //!
   TBranch        *b_trksubjetsTrimming02_core_bits;   //!
   TBranch        *b_trksubjetsTrimming02_core_p4_mass;   //!
   TBranch        *b_trksubjetsTrimming02_core_p4_px;   //!
   TBranch        *b_trksubjetsTrimming02_core_p4_py;   //!
   TBranch        *b_trksubjetsTrimming02_core_p4_pz;   //!
   TBranch        *b_trksubjetsTrimming02_particles_begin;   //!
   TBranch        *b_trksubjetsTrimming02_particles_end;   //!
   TBranch        *b_trksubjetsTrimming02#0_;   //!
   TBranch        *b_trksubjetsTrimming02#0_index;   //!
   TBranch        *b_trksubjetsTrimming02#0_collectionID;   //!
   TBranch        *b_trksubjetsPruning02_;   //!
   TBranch        *b_trksubjetsPruning02_core_area;   //!
   TBranch        *b_trksubjetsPruning02_core_bits;   //!
   TBranch        *b_trksubjetsPruning02_core_p4_mass;   //!
   TBranch        *b_trksubjetsPruning02_core_p4_px;   //!
   TBranch        *b_trksubjetsPruning02_core_p4_py;   //!
   TBranch        *b_trksubjetsPruning02_core_p4_pz;   //!
   TBranch        *b_trksubjetsPruning02_particles_begin;   //!
   TBranch        *b_trksubjetsPruning02_particles_end;   //!
   TBranch        *b_trksubjetsPruning02#0_;   //!
   TBranch        *b_trksubjetsPruning02#0_index;   //!
   TBranch        *b_trksubjetsPruning02#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDrop02_;   //!
   TBranch        *b_trksubjetsSoftDrop02_core_area;   //!
   TBranch        *b_trksubjetsSoftDrop02_core_bits;   //!
   TBranch        *b_trksubjetsSoftDrop02_core_p4_mass;   //!
   TBranch        *b_trksubjetsSoftDrop02_core_p4_px;   //!
   TBranch        *b_trksubjetsSoftDrop02_core_p4_py;   //!
   TBranch        *b_trksubjetsSoftDrop02_core_p4_pz;   //!
   TBranch        *b_trksubjetsSoftDrop02_particles_begin;   //!
   TBranch        *b_trksubjetsSoftDrop02_particles_end;   //!
   TBranch        *b_trksubjetsSoftDrop02#0_;   //!
   TBranch        *b_trksubjetsSoftDrop02#0_index;   //!
   TBranch        *b_trksubjetsSoftDrop02#0_collectionID;   //!
   TBranch        *b_trkjets04_;   //!
   TBranch        *b_trkjets04_core_area;   //!
   TBranch        *b_trkjets04_core_bits;   //!
   TBranch        *b_trkjets04_core_p4_mass;   //!
   TBranch        *b_trkjets04_core_p4_px;   //!
   TBranch        *b_trkjets04_core_p4_py;   //!
   TBranch        *b_trkjets04_core_p4_pz;   //!
   TBranch        *b_trkjets04_particles_begin;   //!
   TBranch        *b_trkjets04_particles_end;   //!
   TBranch        *b_trkjets04#0_;   //!
   TBranch        *b_trkjets04#0_index;   //!
   TBranch        *b_trkjets04#0_collectionID;   //!
   TBranch        *b_trkjetsFlavor04_;   //!
   TBranch        *b_trkjetsFlavor04_tag;   //!
   TBranch        *b_trkjetsFlavor04#0_;   //!
   TBranch        *b_trkjetsFlavor04#0_index;   //!
   TBranch        *b_trkjetsFlavor04#0_collectionID;   //!
   TBranch        *b_trkbTags04_;   //!
   TBranch        *b_trkbTags04_tag;   //!
   TBranch        *b_trkbTags04#0_;   //!
   TBranch        *b_trkbTags04#0_index;   //!
   TBranch        *b_trkbTags04#0_collectionID;   //!
   TBranch        *b_trkcTags04_;   //!
   TBranch        *b_trkcTags04_tag;   //!
   TBranch        *b_trkcTags04#0_;   //!
   TBranch        *b_trkcTags04#0_index;   //!
   TBranch        *b_trkcTags04#0_collectionID;   //!
   TBranch        *b_trktauTags04_;   //!
   TBranch        *b_trktauTags04_tag;   //!
   TBranch        *b_trktauTags04#0_;   //!
   TBranch        *b_trktauTags04#0_index;   //!
   TBranch        *b_trktauTags04#0_collectionID;   //!
   TBranch        *b_trkjetParts04_;   //!
   TBranch        *b_trkjetParts04_core_bits;   //!
   TBranch        *b_trkjetParts04_core_charge;   //!
   TBranch        *b_trkjetParts04_core_p4_mass;   //!
   TBranch        *b_trkjetParts04_core_p4_px;   //!
   TBranch        *b_trkjetParts04_core_p4_py;   //!
   TBranch        *b_trkjetParts04_core_p4_pz;   //!
   TBranch        *b_trkjetParts04_core_pdgId;   //!
   TBranch        *b_trkjetParts04_core_status;   //!
   TBranch        *b_trkjetParts04_core_vertex_x;   //!
   TBranch        *b_trkjetParts04_core_vertex_y;   //!
   TBranch        *b_trkjetParts04_core_vertex_z;   //!
   TBranch        *b_trkjetParts04_tracks_begin;   //!
   TBranch        *b_trkjetParts04_tracks_end;   //!
   TBranch        *b_trkjetParts04_clusters_begin;   //!
   TBranch        *b_trkjetParts04_clusters_end;   //!
   TBranch        *b_trkjetParts04#0_;   //!
   TBranch        *b_trkjetParts04#0_index;   //!
   TBranch        *b_trkjetParts04#0_collectionID;   //!
   TBranch        *b_trkjetParts04#1_;   //!
   TBranch        *b_trkjetParts04#1_index;   //!
   TBranch        *b_trkjetParts04#1_collectionID;   //!
   TBranch        *b_trkjetsOneSubJettiness04_;   //!
   TBranch        *b_trkjetsOneSubJettiness04_tag;   //!
   TBranch        *b_trkjetsOneSubJettiness04#0_;   //!
   TBranch        *b_trkjetsOneSubJettiness04#0_index;   //!
   TBranch        *b_trkjetsOneSubJettiness04#0_collectionID;   //!
   TBranch        *b_trkjetsTwoSubJettiness04_;   //!
   TBranch        *b_trkjetsTwoSubJettiness04_tag;   //!
   TBranch        *b_trkjetsTwoSubJettiness04#0_;   //!
   TBranch        *b_trkjetsTwoSubJettiness04#0_index;   //!
   TBranch        *b_trkjetsTwoSubJettiness04#0_collectionID;   //!
   TBranch        *b_trkjetsThreeSubJettiness04_;   //!
   TBranch        *b_trkjetsThreeSubJettiness04_tag;   //!
   TBranch        *b_trkjetsThreeSubJettiness04#0_;   //!
   TBranch        *b_trkjetsThreeSubJettiness04#0_index;   //!
   TBranch        *b_trkjetsThreeSubJettiness04#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged04_;   //!
   TBranch        *b_trksubjetsTrimmingTagged04_subjets_begin;   //!
   TBranch        *b_trksubjetsTrimmingTagged04_subjets_end;   //!
   TBranch        *b_trksubjetsTrimmingTagged04#0_;   //!
   TBranch        *b_trksubjetsTrimmingTagged04#0_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged04#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged04#1_;   //!
   TBranch        *b_trksubjetsTrimmingTagged04#1_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged04#1_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged04_;   //!
   TBranch        *b_trksubjetsPruningTagged04_subjets_begin;   //!
   TBranch        *b_trksubjetsPruningTagged04_subjets_end;   //!
   TBranch        *b_trksubjetsPruningTagged04#0_;   //!
   TBranch        *b_trksubjetsPruningTagged04#0_index;   //!
   TBranch        *b_trksubjetsPruningTagged04#0_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged04#1_;   //!
   TBranch        *b_trksubjetsPruningTagged04#1_index;   //!
   TBranch        *b_trksubjetsPruningTagged04#1_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged04_;   //!
   TBranch        *b_trksubjetsSoftDropTagged04_subjets_begin;   //!
   TBranch        *b_trksubjetsSoftDropTagged04_subjets_end;   //!
   TBranch        *b_trksubjetsSoftDropTagged04#0_;   //!
   TBranch        *b_trksubjetsSoftDropTagged04#0_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged04#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged04#1_;   //!
   TBranch        *b_trksubjetsSoftDropTagged04#1_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged04#1_collectionID;   //!
   TBranch        *b_trksubjetsTrimming04_;   //!
   TBranch        *b_trksubjetsTrimming04_core_area;   //!
   TBranch        *b_trksubjetsTrimming04_core_bits;   //!
   TBranch        *b_trksubjetsTrimming04_core_p4_mass;   //!
   TBranch        *b_trksubjetsTrimming04_core_p4_px;   //!
   TBranch        *b_trksubjetsTrimming04_core_p4_py;   //!
   TBranch        *b_trksubjetsTrimming04_core_p4_pz;   //!
   TBranch        *b_trksubjetsTrimming04_particles_begin;   //!
   TBranch        *b_trksubjetsTrimming04_particles_end;   //!
   TBranch        *b_trksubjetsTrimming04#0_;   //!
   TBranch        *b_trksubjetsTrimming04#0_index;   //!
   TBranch        *b_trksubjetsTrimming04#0_collectionID;   //!
   TBranch        *b_trksubjetsPruning04_;   //!
   TBranch        *b_trksubjetsPruning04_core_area;   //!
   TBranch        *b_trksubjetsPruning04_core_bits;   //!
   TBranch        *b_trksubjetsPruning04_core_p4_mass;   //!
   TBranch        *b_trksubjetsPruning04_core_p4_px;   //!
   TBranch        *b_trksubjetsPruning04_core_p4_py;   //!
   TBranch        *b_trksubjetsPruning04_core_p4_pz;   //!
   TBranch        *b_trksubjetsPruning04_particles_begin;   //!
   TBranch        *b_trksubjetsPruning04_particles_end;   //!
   TBranch        *b_trksubjetsPruning04#0_;   //!
   TBranch        *b_trksubjetsPruning04#0_index;   //!
   TBranch        *b_trksubjetsPruning04#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDrop04_;   //!
   TBranch        *b_trksubjetsSoftDrop04_core_area;   //!
   TBranch        *b_trksubjetsSoftDrop04_core_bits;   //!
   TBranch        *b_trksubjetsSoftDrop04_core_p4_mass;   //!
   TBranch        *b_trksubjetsSoftDrop04_core_p4_px;   //!
   TBranch        *b_trksubjetsSoftDrop04_core_p4_py;   //!
   TBranch        *b_trksubjetsSoftDrop04_core_p4_pz;   //!
   TBranch        *b_trksubjetsSoftDrop04_particles_begin;   //!
   TBranch        *b_trksubjetsSoftDrop04_particles_end;   //!
   TBranch        *b_trksubjetsSoftDrop04#0_;   //!
   TBranch        *b_trksubjetsSoftDrop04#0_index;   //!
   TBranch        *b_trksubjetsSoftDrop04#0_collectionID;   //!
   TBranch        *b_trkjets08_;   //!
   TBranch        *b_trkjets08_core_area;   //!
   TBranch        *b_trkjets08_core_bits;   //!
   TBranch        *b_trkjets08_core_p4_mass;   //!
   TBranch        *b_trkjets08_core_p4_px;   //!
   TBranch        *b_trkjets08_core_p4_py;   //!
   TBranch        *b_trkjets08_core_p4_pz;   //!
   TBranch        *b_trkjets08_particles_begin;   //!
   TBranch        *b_trkjets08_particles_end;   //!
   TBranch        *b_trkjets08#0_;   //!
   TBranch        *b_trkjets08#0_index;   //!
   TBranch        *b_trkjets08#0_collectionID;   //!
   TBranch        *b_trkjetsFlavor08_;   //!
   TBranch        *b_trkjetsFlavor08_tag;   //!
   TBranch        *b_trkjetsFlavor08#0_;   //!
   TBranch        *b_trkjetsFlavor08#0_index;   //!
   TBranch        *b_trkjetsFlavor08#0_collectionID;   //!
   TBranch        *b_trkbTags08_;   //!
   TBranch        *b_trkbTags08_tag;   //!
   TBranch        *b_trkbTags08#0_;   //!
   TBranch        *b_trkbTags08#0_index;   //!
   TBranch        *b_trkbTags08#0_collectionID;   //!
   TBranch        *b_trkcTags08_;   //!
   TBranch        *b_trkcTags08_tag;   //!
   TBranch        *b_trkcTags08#0_;   //!
   TBranch        *b_trkcTags08#0_index;   //!
   TBranch        *b_trkcTags08#0_collectionID;   //!
   TBranch        *b_trktauTags08_;   //!
   TBranch        *b_trktauTags08_tag;   //!
   TBranch        *b_trktauTags08#0_;   //!
   TBranch        *b_trktauTags08#0_index;   //!
   TBranch        *b_trktauTags08#0_collectionID;   //!
   TBranch        *b_trkjetParts08_;   //!
   TBranch        *b_trkjetParts08_core_bits;   //!
   TBranch        *b_trkjetParts08_core_charge;   //!
   TBranch        *b_trkjetParts08_core_p4_mass;   //!
   TBranch        *b_trkjetParts08_core_p4_px;   //!
   TBranch        *b_trkjetParts08_core_p4_py;   //!
   TBranch        *b_trkjetParts08_core_p4_pz;   //!
   TBranch        *b_trkjetParts08_core_pdgId;   //!
   TBranch        *b_trkjetParts08_core_status;   //!
   TBranch        *b_trkjetParts08_core_vertex_x;   //!
   TBranch        *b_trkjetParts08_core_vertex_y;   //!
   TBranch        *b_trkjetParts08_core_vertex_z;   //!
   TBranch        *b_trkjetParts08_tracks_begin;   //!
   TBranch        *b_trkjetParts08_tracks_end;   //!
   TBranch        *b_trkjetParts08_clusters_begin;   //!
   TBranch        *b_trkjetParts08_clusters_end;   //!
   TBranch        *b_trkjetParts08#0_;   //!
   TBranch        *b_trkjetParts08#0_index;   //!
   TBranch        *b_trkjetParts08#0_collectionID;   //!
   TBranch        *b_trkjetParts08#1_;   //!
   TBranch        *b_trkjetParts08#1_index;   //!
   TBranch        *b_trkjetParts08#1_collectionID;   //!
   TBranch        *b_trkjetsOneSubJettiness08_;   //!
   TBranch        *b_trkjetsOneSubJettiness08_tag;   //!
   TBranch        *b_trkjetsOneSubJettiness08#0_;   //!
   TBranch        *b_trkjetsOneSubJettiness08#0_index;   //!
   TBranch        *b_trkjetsOneSubJettiness08#0_collectionID;   //!
   TBranch        *b_trkjetsTwoSubJettiness08_;   //!
   TBranch        *b_trkjetsTwoSubJettiness08_tag;   //!
   TBranch        *b_trkjetsTwoSubJettiness08#0_;   //!
   TBranch        *b_trkjetsTwoSubJettiness08#0_index;   //!
   TBranch        *b_trkjetsTwoSubJettiness08#0_collectionID;   //!
   TBranch        *b_trkjetsThreeSubJettiness08_;   //!
   TBranch        *b_trkjetsThreeSubJettiness08_tag;   //!
   TBranch        *b_trkjetsThreeSubJettiness08#0_;   //!
   TBranch        *b_trkjetsThreeSubJettiness08#0_index;   //!
   TBranch        *b_trkjetsThreeSubJettiness08#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged08_;   //!
   TBranch        *b_trksubjetsTrimmingTagged08_subjets_begin;   //!
   TBranch        *b_trksubjetsTrimmingTagged08_subjets_end;   //!
   TBranch        *b_trksubjetsTrimmingTagged08#0_;   //!
   TBranch        *b_trksubjetsTrimmingTagged08#0_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged08#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged08#1_;   //!
   TBranch        *b_trksubjetsTrimmingTagged08#1_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged08#1_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged08_;   //!
   TBranch        *b_trksubjetsPruningTagged08_subjets_begin;   //!
   TBranch        *b_trksubjetsPruningTagged08_subjets_end;   //!
   TBranch        *b_trksubjetsPruningTagged08#0_;   //!
   TBranch        *b_trksubjetsPruningTagged08#0_index;   //!
   TBranch        *b_trksubjetsPruningTagged08#0_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged08#1_;   //!
   TBranch        *b_trksubjetsPruningTagged08#1_index;   //!
   TBranch        *b_trksubjetsPruningTagged08#1_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged08_;   //!
   TBranch        *b_trksubjetsSoftDropTagged08_subjets_begin;   //!
   TBranch        *b_trksubjetsSoftDropTagged08_subjets_end;   //!
   TBranch        *b_trksubjetsSoftDropTagged08#0_;   //!
   TBranch        *b_trksubjetsSoftDropTagged08#0_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged08#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged08#1_;   //!
   TBranch        *b_trksubjetsSoftDropTagged08#1_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged08#1_collectionID;   //!
   TBranch        *b_trksubjetsTrimming08_;   //!
   TBranch        *b_trksubjetsTrimming08_core_area;   //!
   TBranch        *b_trksubjetsTrimming08_core_bits;   //!
   TBranch        *b_trksubjetsTrimming08_core_p4_mass;   //!
   TBranch        *b_trksubjetsTrimming08_core_p4_px;   //!
   TBranch        *b_trksubjetsTrimming08_core_p4_py;   //!
   TBranch        *b_trksubjetsTrimming08_core_p4_pz;   //!
   TBranch        *b_trksubjetsTrimming08_particles_begin;   //!
   TBranch        *b_trksubjetsTrimming08_particles_end;   //!
   TBranch        *b_trksubjetsTrimming08#0_;   //!
   TBranch        *b_trksubjetsTrimming08#0_index;   //!
   TBranch        *b_trksubjetsTrimming08#0_collectionID;   //!
   TBranch        *b_trksubjetsPruning08_;   //!
   TBranch        *b_trksubjetsPruning08_core_area;   //!
   TBranch        *b_trksubjetsPruning08_core_bits;   //!
   TBranch        *b_trksubjetsPruning08_core_p4_mass;   //!
   TBranch        *b_trksubjetsPruning08_core_p4_px;   //!
   TBranch        *b_trksubjetsPruning08_core_p4_py;   //!
   TBranch        *b_trksubjetsPruning08_core_p4_pz;   //!
   TBranch        *b_trksubjetsPruning08_particles_begin;   //!
   TBranch        *b_trksubjetsPruning08_particles_end;   //!
   TBranch        *b_trksubjetsPruning08#0_;   //!
   TBranch        *b_trksubjetsPruning08#0_index;   //!
   TBranch        *b_trksubjetsPruning08#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDrop08_;   //!
   TBranch        *b_trksubjetsSoftDrop08_core_area;   //!
   TBranch        *b_trksubjetsSoftDrop08_core_bits;   //!
   TBranch        *b_trksubjetsSoftDrop08_core_p4_mass;   //!
   TBranch        *b_trksubjetsSoftDrop08_core_p4_px;   //!
   TBranch        *b_trksubjetsSoftDrop08_core_p4_py;   //!
   TBranch        *b_trksubjetsSoftDrop08_core_p4_pz;   //!
   TBranch        *b_trksubjetsSoftDrop08_particles_begin;   //!
   TBranch        *b_trksubjetsSoftDrop08_particles_end;   //!
   TBranch        *b_trksubjetsSoftDrop08#0_;   //!
   TBranch        *b_trksubjetsSoftDrop08#0_index;   //!
   TBranch        *b_trksubjetsSoftDrop08#0_collectionID;   //!
   TBranch        *b_trkjets15_;   //!
   TBranch        *b_trkjets15_core_area;   //!
   TBranch        *b_trkjets15_core_bits;   //!
   TBranch        *b_trkjets15_core_p4_mass;   //!
   TBranch        *b_trkjets15_core_p4_px;   //!
   TBranch        *b_trkjets15_core_p4_py;   //!
   TBranch        *b_trkjets15_core_p4_pz;   //!
   TBranch        *b_trkjets15_particles_begin;   //!
   TBranch        *b_trkjets15_particles_end;   //!
   TBranch        *b_trkjets15#0_;   //!
   TBranch        *b_trkjets15#0_index;   //!
   TBranch        *b_trkjets15#0_collectionID;   //!
   TBranch        *b_trkjetsFlavor15_;   //!
   TBranch        *b_trkjetsFlavor15_tag;   //!
   TBranch        *b_trkjetsFlavor15#0_;   //!
   TBranch        *b_trkjetsFlavor15#0_index;   //!
   TBranch        *b_trkjetsFlavor15#0_collectionID;   //!
   TBranch        *b_trkbTags15_;   //!
   TBranch        *b_trkbTags15_tag;   //!
   TBranch        *b_trkbTags15#0_;   //!
   TBranch        *b_trkbTags15#0_index;   //!
   TBranch        *b_trkbTags15#0_collectionID;   //!
   TBranch        *b_trkcTags15_;   //!
   TBranch        *b_trkcTags15_tag;   //!
   TBranch        *b_trkcTags15#0_;   //!
   TBranch        *b_trkcTags15#0_index;   //!
   TBranch        *b_trkcTags15#0_collectionID;   //!
   TBranch        *b_trktauTags15_;   //!
   TBranch        *b_trktauTags15_tag;   //!
   TBranch        *b_trktauTags15#0_;   //!
   TBranch        *b_trktauTags15#0_index;   //!
   TBranch        *b_trktauTags15#0_collectionID;   //!
   TBranch        *b_trkjetParts15_;   //!
   TBranch        *b_trkjetParts15_core_bits;   //!
   TBranch        *b_trkjetParts15_core_charge;   //!
   TBranch        *b_trkjetParts15_core_p4_mass;   //!
   TBranch        *b_trkjetParts15_core_p4_px;   //!
   TBranch        *b_trkjetParts15_core_p4_py;   //!
   TBranch        *b_trkjetParts15_core_p4_pz;   //!
   TBranch        *b_trkjetParts15_core_pdgId;   //!
   TBranch        *b_trkjetParts15_core_status;   //!
   TBranch        *b_trkjetParts15_core_vertex_x;   //!
   TBranch        *b_trkjetParts15_core_vertex_y;   //!
   TBranch        *b_trkjetParts15_core_vertex_z;   //!
   TBranch        *b_trkjetParts15_tracks_begin;   //!
   TBranch        *b_trkjetParts15_tracks_end;   //!
   TBranch        *b_trkjetParts15_clusters_begin;   //!
   TBranch        *b_trkjetParts15_clusters_end;   //!
   TBranch        *b_trkjetParts15#0_;   //!
   TBranch        *b_trkjetParts15#0_index;   //!
   TBranch        *b_trkjetParts15#0_collectionID;   //!
   TBranch        *b_trkjetParts15#1_;   //!
   TBranch        *b_trkjetParts15#1_index;   //!
   TBranch        *b_trkjetParts15#1_collectionID;   //!
   TBranch        *b_trkjetsOneSubJettiness15_;   //!
   TBranch        *b_trkjetsOneSubJettiness15_tag;   //!
   TBranch        *b_trkjetsOneSubJettiness15#0_;   //!
   TBranch        *b_trkjetsOneSubJettiness15#0_index;   //!
   TBranch        *b_trkjetsOneSubJettiness15#0_collectionID;   //!
   TBranch        *b_trkjetsTwoSubJettiness15_;   //!
   TBranch        *b_trkjetsTwoSubJettiness15_tag;   //!
   TBranch        *b_trkjetsTwoSubJettiness15#0_;   //!
   TBranch        *b_trkjetsTwoSubJettiness15#0_index;   //!
   TBranch        *b_trkjetsTwoSubJettiness15#0_collectionID;   //!
   TBranch        *b_trkjetsThreeSubJettiness15_;   //!
   TBranch        *b_trkjetsThreeSubJettiness15_tag;   //!
   TBranch        *b_trkjetsThreeSubJettiness15#0_;   //!
   TBranch        *b_trkjetsThreeSubJettiness15#0_index;   //!
   TBranch        *b_trkjetsThreeSubJettiness15#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged15_;   //!
   TBranch        *b_trksubjetsTrimmingTagged15_subjets_begin;   //!
   TBranch        *b_trksubjetsTrimmingTagged15_subjets_end;   //!
   TBranch        *b_trksubjetsTrimmingTagged15#0_;   //!
   TBranch        *b_trksubjetsTrimmingTagged15#0_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged15#0_collectionID;   //!
   TBranch        *b_trksubjetsTrimmingTagged15#1_;   //!
   TBranch        *b_trksubjetsTrimmingTagged15#1_index;   //!
   TBranch        *b_trksubjetsTrimmingTagged15#1_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged15_;   //!
   TBranch        *b_trksubjetsPruningTagged15_subjets_begin;   //!
   TBranch        *b_trksubjetsPruningTagged15_subjets_end;   //!
   TBranch        *b_trksubjetsPruningTagged15#0_;   //!
   TBranch        *b_trksubjetsPruningTagged15#0_index;   //!
   TBranch        *b_trksubjetsPruningTagged15#0_collectionID;   //!
   TBranch        *b_trksubjetsPruningTagged15#1_;   //!
   TBranch        *b_trksubjetsPruningTagged15#1_index;   //!
   TBranch        *b_trksubjetsPruningTagged15#1_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged15_;   //!
   TBranch        *b_trksubjetsSoftDropTagged15_subjets_begin;   //!
   TBranch        *b_trksubjetsSoftDropTagged15_subjets_end;   //!
   TBranch        *b_trksubjetsSoftDropTagged15#0_;   //!
   TBranch        *b_trksubjetsSoftDropTagged15#0_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged15#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDropTagged15#1_;   //!
   TBranch        *b_trksubjetsSoftDropTagged15#1_index;   //!
   TBranch        *b_trksubjetsSoftDropTagged15#1_collectionID;   //!
   TBranch        *b_trksubjetsTrimming15_;   //!
   TBranch        *b_trksubjetsTrimming15_core_area;   //!
   TBranch        *b_trksubjetsTrimming15_core_bits;   //!
   TBranch        *b_trksubjetsTrimming15_core_p4_mass;   //!
   TBranch        *b_trksubjetsTrimming15_core_p4_px;   //!
   TBranch        *b_trksubjetsTrimming15_core_p4_py;   //!
   TBranch        *b_trksubjetsTrimming15_core_p4_pz;   //!
   TBranch        *b_trksubjetsTrimming15_particles_begin;   //!
   TBranch        *b_trksubjetsTrimming15_particles_end;   //!
   TBranch        *b_trksubjetsTrimming15#0_;   //!
   TBranch        *b_trksubjetsTrimming15#0_index;   //!
   TBranch        *b_trksubjetsTrimming15#0_collectionID;   //!
   TBranch        *b_trksubjetsPruning15_;   //!
   TBranch        *b_trksubjetsPruning15_core_area;   //!
   TBranch        *b_trksubjetsPruning15_core_bits;   //!
   TBranch        *b_trksubjetsPruning15_core_p4_mass;   //!
   TBranch        *b_trksubjetsPruning15_core_p4_px;   //!
   TBranch        *b_trksubjetsPruning15_core_p4_py;   //!
   TBranch        *b_trksubjetsPruning15_core_p4_pz;   //!
   TBranch        *b_trksubjetsPruning15_particles_begin;   //!
   TBranch        *b_trksubjetsPruning15_particles_end;   //!
   TBranch        *b_trksubjetsPruning15#0_;   //!
   TBranch        *b_trksubjetsPruning15#0_index;   //!
   TBranch        *b_trksubjetsPruning15#0_collectionID;   //!
   TBranch        *b_trksubjetsSoftDrop15_;   //!
   TBranch        *b_trksubjetsSoftDrop15_core_area;   //!
   TBranch        *b_trksubjetsSoftDrop15_core_bits;   //!
   TBranch        *b_trksubjetsSoftDrop15_core_p4_mass;   //!
   TBranch        *b_trksubjetsSoftDrop15_core_p4_px;   //!
   TBranch        *b_trksubjetsSoftDrop15_core_p4_py;   //!
   TBranch        *b_trksubjetsSoftDrop15_core_p4_pz;   //!
   TBranch        *b_trksubjetsSoftDrop15_particles_begin;   //!
   TBranch        *b_trksubjetsSoftDrop15_particles_end;   //!
   TBranch        *b_trksubjetsSoftDrop15#0_;   //!
   TBranch        *b_trksubjetsSoftDrop15#0_index;   //!
   TBranch        *b_trksubjetsSoftDrop15#0_collectionID;   //!
   TBranch        *b_met_;   //!
   TBranch        *b_met_magnitude;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_scalarSum;   //!

   events(TTree *tree=0);
   virtual ~events();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef events_cxx
events::events(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/experiment/fcc/hh/generation/DelphesEvents/fcc_v02/mgp8_pp_jj012j_5f_HT_1000_2000/events_166472898.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/experiment/fcc/hh/generation/DelphesEvents/fcc_v02/mgp8_pp_jj012j_5f_HT_1000_2000/events_166472898.root");
      }
      f->GetObject("events",tree);

   }
   Init(tree);
}

events::~events()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t events::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t events::LoadTree(Long64_t entry)
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

void events::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   muonsToMC = 0;
   electronsToMC = 0;
   photonsToMC = 0;
   chargedToMC = 0;
   pfphotonsToMC = 0;
   pfneutralsToMC = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("mePsMatchingVars", &mePsMatchingVars_, &b_mePsMatchingVars_);
   fChain->SetBranchAddress("mePsMatchingVars.value", mePsMatchingVars_value, &b_mePsMatchingVars_value);
   fChain->SetBranchAddress("mcEventWeights", &mcEventWeights_, &b_mcEventWeights_);
   fChain->SetBranchAddress("mcEventWeights.value", mcEventWeights_value, &b_mcEventWeights_value);
   fChain->SetBranchAddress("skimmedGenParticles", &skimmedGenParticles_, &b_skimmedGenParticles_);
   fChain->SetBranchAddress("skimmedGenParticles.core.bits", skimmedGenParticles_core_bits, &b_skimmedGenParticles_core_bits);
   fChain->SetBranchAddress("skimmedGenParticles.core.charge", skimmedGenParticles_core_charge, &b_skimmedGenParticles_core_charge);
   fChain->SetBranchAddress("skimmedGenParticles.core.p4.mass", skimmedGenParticles_core_p4_mass, &b_skimmedGenParticles_core_p4_mass);
   fChain->SetBranchAddress("skimmedGenParticles.core.p4.px", skimmedGenParticles_core_p4_px, &b_skimmedGenParticles_core_p4_px);
   fChain->SetBranchAddress("skimmedGenParticles.core.p4.py", skimmedGenParticles_core_p4_py, &b_skimmedGenParticles_core_p4_py);
   fChain->SetBranchAddress("skimmedGenParticles.core.p4.pz", skimmedGenParticles_core_p4_pz, &b_skimmedGenParticles_core_p4_pz);
   fChain->SetBranchAddress("skimmedGenParticles.core.pdgId", skimmedGenParticles_core_pdgId, &b_skimmedGenParticles_core_pdgId);
   fChain->SetBranchAddress("skimmedGenParticles.core.status", skimmedGenParticles_core_status, &b_skimmedGenParticles_core_status);
   fChain->SetBranchAddress("skimmedGenParticles.core.vertex.x", skimmedGenParticles_core_vertex_x, &b_skimmedGenParticles_core_vertex_x);
   fChain->SetBranchAddress("skimmedGenParticles.core.vertex.y", skimmedGenParticles_core_vertex_y, &b_skimmedGenParticles_core_vertex_y);
   fChain->SetBranchAddress("skimmedGenParticles.core.vertex.z", skimmedGenParticles_core_vertex_z, &b_skimmedGenParticles_core_vertex_z);
   fChain->SetBranchAddress("skimmedGenParticles#0", &skimmedGenParticles#0_, &b_skimmedGenParticles#0_);
   fChain->SetBranchAddress("skimmedGenParticles#0.index", skimmedGenParticles#0_index, &b_skimmedGenParticles#0_index);
   fChain->SetBranchAddress("skimmedGenParticles#0.collectionID", skimmedGenParticles#0_collectionID, &b_skimmedGenParticles#0_collectionID);
   fChain->SetBranchAddress("skimmedGenParticles#1", &skimmedGenParticles#1_, &b_skimmedGenParticles#1_);
   fChain->SetBranchAddress("skimmedGenParticles#1.index", skimmedGenParticles#1_index, &b_skimmedGenParticles#1_index);
   fChain->SetBranchAddress("skimmedGenParticles#1.collectionID", skimmedGenParticles#1_collectionID, &b_skimmedGenParticles#1_collectionID);
   fChain->SetBranchAddress("muons", &muons_, &b_muons_);
   fChain->SetBranchAddress("muons.core.bits", muons_core_bits, &b_muons_core_bits);
   fChain->SetBranchAddress("muons.core.charge", muons_core_charge, &b_muons_core_charge);
   fChain->SetBranchAddress("muons.core.p4.mass", muons_core_p4_mass, &b_muons_core_p4_mass);
   fChain->SetBranchAddress("muons.core.p4.px", muons_core_p4_px, &b_muons_core_p4_px);
   fChain->SetBranchAddress("muons.core.p4.py", muons_core_p4_py, &b_muons_core_p4_py);
   fChain->SetBranchAddress("muons.core.p4.pz", muons_core_p4_pz, &b_muons_core_p4_pz);
   fChain->SetBranchAddress("muons.core.pdgId", muons_core_pdgId, &b_muons_core_pdgId);
   fChain->SetBranchAddress("muons.core.status", muons_core_status, &b_muons_core_status);
   fChain->SetBranchAddress("muons.core.vertex.x", muons_core_vertex_x, &b_muons_core_vertex_x);
   fChain->SetBranchAddress("muons.core.vertex.y", muons_core_vertex_y, &b_muons_core_vertex_y);
   fChain->SetBranchAddress("muons.core.vertex.z", muons_core_vertex_z, &b_muons_core_vertex_z);
   fChain->SetBranchAddress("muons.tracks_begin", muons_tracks_begin, &b_muons_tracks_begin);
   fChain->SetBranchAddress("muons.tracks_end", muons_tracks_end, &b_muons_tracks_end);
   fChain->SetBranchAddress("muons.clusters_begin", muons_clusters_begin, &b_muons_clusters_begin);
   fChain->SetBranchAddress("muons.clusters_end", muons_clusters_end, &b_muons_clusters_end);
   fChain->SetBranchAddress("muons#0", &muons#0_, &b_muons#0_);
   fChain->SetBranchAddress("muons#0.index", &muons#0_index, &b_muons#0_index);
   fChain->SetBranchAddress("muons#0.collectionID", &muons#0_collectionID, &b_muons#0_collectionID);
   fChain->SetBranchAddress("muons#1", &muons#1_, &b_muons#1_);
   fChain->SetBranchAddress("muons#1.index", &muons#1_index, &b_muons#1_index);
   fChain->SetBranchAddress("muons#1.collectionID", &muons#1_collectionID, &b_muons#1_collectionID);
   fChain->SetBranchAddress("muonsToMC", &muonsToMC, &b_muonsToMC);
   fChain->SetBranchAddress("muonsToMC#0", &muonsToMC#0_, &b_muonsToMC#0_);
   fChain->SetBranchAddress("muonsToMC#0.index", muonsToMC#0_index, &b_muonsToMC#0_index);
   fChain->SetBranchAddress("muonsToMC#0.collectionID", muonsToMC#0_collectionID, &b_muonsToMC#0_collectionID);
   fChain->SetBranchAddress("muonsToMC#1", &muonsToMC#1_, &b_muonsToMC#1_);
   fChain->SetBranchAddress("muonsToMC#1.index", muonsToMC#1_index, &b_muonsToMC#1_index);
   fChain->SetBranchAddress("muonsToMC#1.collectionID", muonsToMC#1_collectionID, &b_muonsToMC#1_collectionID);
   fChain->SetBranchAddress("muonITags", &muonITags_, &b_muonITags_);
   fChain->SetBranchAddress("muonITags.tag", muonITags_tag, &b_muonITags_tag);
   fChain->SetBranchAddress("muonITags#0", &muonITags#0_, &b_muonITags#0_);
   fChain->SetBranchAddress("muonITags#0.index", muonITags#0_index, &b_muonITags#0_index);
   fChain->SetBranchAddress("muonITags#0.collectionID", muonITags#0_collectionID, &b_muonITags#0_collectionID);
   fChain->SetBranchAddress("electrons", &electrons_, &b_electrons_);
   fChain->SetBranchAddress("electrons.core.bits", electrons_core_bits, &b_electrons_core_bits);
   fChain->SetBranchAddress("electrons.core.charge", electrons_core_charge, &b_electrons_core_charge);
   fChain->SetBranchAddress("electrons.core.p4.mass", electrons_core_p4_mass, &b_electrons_core_p4_mass);
   fChain->SetBranchAddress("electrons.core.p4.px", electrons_core_p4_px, &b_electrons_core_p4_px);
   fChain->SetBranchAddress("electrons.core.p4.py", electrons_core_p4_py, &b_electrons_core_p4_py);
   fChain->SetBranchAddress("electrons.core.p4.pz", electrons_core_p4_pz, &b_electrons_core_p4_pz);
   fChain->SetBranchAddress("electrons.core.pdgId", electrons_core_pdgId, &b_electrons_core_pdgId);
   fChain->SetBranchAddress("electrons.core.status", electrons_core_status, &b_electrons_core_status);
   fChain->SetBranchAddress("electrons.core.vertex.x", electrons_core_vertex_x, &b_electrons_core_vertex_x);
   fChain->SetBranchAddress("electrons.core.vertex.y", electrons_core_vertex_y, &b_electrons_core_vertex_y);
   fChain->SetBranchAddress("electrons.core.vertex.z", electrons_core_vertex_z, &b_electrons_core_vertex_z);
   fChain->SetBranchAddress("electrons.tracks_begin", electrons_tracks_begin, &b_electrons_tracks_begin);
   fChain->SetBranchAddress("electrons.tracks_end", electrons_tracks_end, &b_electrons_tracks_end);
   fChain->SetBranchAddress("electrons.clusters_begin", electrons_clusters_begin, &b_electrons_clusters_begin);
   fChain->SetBranchAddress("electrons.clusters_end", electrons_clusters_end, &b_electrons_clusters_end);
   fChain->SetBranchAddress("electrons#0", &electrons#0_, &b_electrons#0_);
   fChain->SetBranchAddress("electrons#0.index", &electrons#0_index, &b_electrons#0_index);
   fChain->SetBranchAddress("electrons#0.collectionID", &electrons#0_collectionID, &b_electrons#0_collectionID);
   fChain->SetBranchAddress("electrons#1", &electrons#1_, &b_electrons#1_);
   fChain->SetBranchAddress("electrons#1.index", &electrons#1_index, &b_electrons#1_index);
   fChain->SetBranchAddress("electrons#1.collectionID", &electrons#1_collectionID, &b_electrons#1_collectionID);
   fChain->SetBranchAddress("electronsToMC", &electronsToMC, &b_electronsToMC);
   fChain->SetBranchAddress("electronsToMC#0", &electronsToMC#0_, &b_electronsToMC#0_);
   fChain->SetBranchAddress("electronsToMC#0.index", electronsToMC#0_index, &b_electronsToMC#0_index);
   fChain->SetBranchAddress("electronsToMC#0.collectionID", electronsToMC#0_collectionID, &b_electronsToMC#0_collectionID);
   fChain->SetBranchAddress("electronsToMC#1", &electronsToMC#1_, &b_electronsToMC#1_);
   fChain->SetBranchAddress("electronsToMC#1.index", electronsToMC#1_index, &b_electronsToMC#1_index);
   fChain->SetBranchAddress("electronsToMC#1.collectionID", electronsToMC#1_collectionID, &b_electronsToMC#1_collectionID);
   fChain->SetBranchAddress("electronITags", &electronITags_, &b_electronITags_);
   fChain->SetBranchAddress("electronITags.tag", electronITags_tag, &b_electronITags_tag);
   fChain->SetBranchAddress("electronITags#0", &electronITags#0_, &b_electronITags#0_);
   fChain->SetBranchAddress("electronITags#0.index", electronITags#0_index, &b_electronITags#0_index);
   fChain->SetBranchAddress("electronITags#0.collectionID", electronITags#0_collectionID, &b_electronITags#0_collectionID);
   fChain->SetBranchAddress("photons", &photons_, &b_photons_);
   fChain->SetBranchAddress("photons.core.bits", photons_core_bits, &b_photons_core_bits);
   fChain->SetBranchAddress("photons.core.charge", photons_core_charge, &b_photons_core_charge);
   fChain->SetBranchAddress("photons.core.p4.mass", photons_core_p4_mass, &b_photons_core_p4_mass);
   fChain->SetBranchAddress("photons.core.p4.px", photons_core_p4_px, &b_photons_core_p4_px);
   fChain->SetBranchAddress("photons.core.p4.py", photons_core_p4_py, &b_photons_core_p4_py);
   fChain->SetBranchAddress("photons.core.p4.pz", photons_core_p4_pz, &b_photons_core_p4_pz);
   fChain->SetBranchAddress("photons.core.pdgId", photons_core_pdgId, &b_photons_core_pdgId);
   fChain->SetBranchAddress("photons.core.status", photons_core_status, &b_photons_core_status);
   fChain->SetBranchAddress("photons.core.vertex.x", photons_core_vertex_x, &b_photons_core_vertex_x);
   fChain->SetBranchAddress("photons.core.vertex.y", photons_core_vertex_y, &b_photons_core_vertex_y);
   fChain->SetBranchAddress("photons.core.vertex.z", photons_core_vertex_z, &b_photons_core_vertex_z);
   fChain->SetBranchAddress("photons.tracks_begin", photons_tracks_begin, &b_photons_tracks_begin);
   fChain->SetBranchAddress("photons.tracks_end", photons_tracks_end, &b_photons_tracks_end);
   fChain->SetBranchAddress("photons.clusters_begin", photons_clusters_begin, &b_photons_clusters_begin);
   fChain->SetBranchAddress("photons.clusters_end", photons_clusters_end, &b_photons_clusters_end);
   fChain->SetBranchAddress("photons#0", &photons#0_, &b_photons#0_);
   fChain->SetBranchAddress("photons#0.index", &photons#0_index, &b_photons#0_index);
   fChain->SetBranchAddress("photons#0.collectionID", &photons#0_collectionID, &b_photons#0_collectionID);
   fChain->SetBranchAddress("photons#1", &photons#1_, &b_photons#1_);
   fChain->SetBranchAddress("photons#1.index", &photons#1_index, &b_photons#1_index);
   fChain->SetBranchAddress("photons#1.collectionID", &photons#1_collectionID, &b_photons#1_collectionID);
   fChain->SetBranchAddress("photonsToMC", &photonsToMC, &b_photonsToMC);
   fChain->SetBranchAddress("photonsToMC#0", &photonsToMC#0_, &b_photonsToMC#0_);
   fChain->SetBranchAddress("photonsToMC#0.index", photonsToMC#0_index, &b_photonsToMC#0_index);
   fChain->SetBranchAddress("photonsToMC#0.collectionID", photonsToMC#0_collectionID, &b_photonsToMC#0_collectionID);
   fChain->SetBranchAddress("photonsToMC#1", &photonsToMC#1_, &b_photonsToMC#1_);
   fChain->SetBranchAddress("photonsToMC#1.index", photonsToMC#1_index, &b_photonsToMC#1_index);
   fChain->SetBranchAddress("photonsToMC#1.collectionID", photonsToMC#1_collectionID, &b_photonsToMC#1_collectionID);
   fChain->SetBranchAddress("photonITags", &photonITags_, &b_photonITags_);
   fChain->SetBranchAddress("photonITags.tag", photonITags_tag, &b_photonITags_tag);
   fChain->SetBranchAddress("photonITags#0", &photonITags#0_, &b_photonITags#0_);
   fChain->SetBranchAddress("photonITags#0.index", photonITags#0_index, &b_photonITags#0_index);
   fChain->SetBranchAddress("photonITags#0.collectionID", photonITags#0_collectionID, &b_photonITags#0_collectionID);
   fChain->SetBranchAddress("pfcharged", &pfcharged_, &b_pfcharged_);
   fChain->SetBranchAddress("pfcharged.core.bits", pfcharged_core_bits, &b_pfcharged_core_bits);
   fChain->SetBranchAddress("pfcharged.core.charge", pfcharged_core_charge, &b_pfcharged_core_charge);
   fChain->SetBranchAddress("pfcharged.core.p4.mass", pfcharged_core_p4_mass, &b_pfcharged_core_p4_mass);
   fChain->SetBranchAddress("pfcharged.core.p4.px", pfcharged_core_p4_px, &b_pfcharged_core_p4_px);
   fChain->SetBranchAddress("pfcharged.core.p4.py", pfcharged_core_p4_py, &b_pfcharged_core_p4_py);
   fChain->SetBranchAddress("pfcharged.core.p4.pz", pfcharged_core_p4_pz, &b_pfcharged_core_p4_pz);
   fChain->SetBranchAddress("pfcharged.core.pdgId", pfcharged_core_pdgId, &b_pfcharged_core_pdgId);
   fChain->SetBranchAddress("pfcharged.core.status", pfcharged_core_status, &b_pfcharged_core_status);
   fChain->SetBranchAddress("pfcharged.core.vertex.x", pfcharged_core_vertex_x, &b_pfcharged_core_vertex_x);
   fChain->SetBranchAddress("pfcharged.core.vertex.y", pfcharged_core_vertex_y, &b_pfcharged_core_vertex_y);
   fChain->SetBranchAddress("pfcharged.core.vertex.z", pfcharged_core_vertex_z, &b_pfcharged_core_vertex_z);
   fChain->SetBranchAddress("pfcharged.tracks_begin", pfcharged_tracks_begin, &b_pfcharged_tracks_begin);
   fChain->SetBranchAddress("pfcharged.tracks_end", pfcharged_tracks_end, &b_pfcharged_tracks_end);
   fChain->SetBranchAddress("pfcharged.clusters_begin", pfcharged_clusters_begin, &b_pfcharged_clusters_begin);
   fChain->SetBranchAddress("pfcharged.clusters_end", pfcharged_clusters_end, &b_pfcharged_clusters_end);
   fChain->SetBranchAddress("pfcharged#0", &pfcharged#0_, &b_pfcharged#0_);
   fChain->SetBranchAddress("pfcharged#0.index", &pfcharged#0_index, &b_pfcharged#0_index);
   fChain->SetBranchAddress("pfcharged#0.collectionID", &pfcharged#0_collectionID, &b_pfcharged#0_collectionID);
   fChain->SetBranchAddress("pfcharged#1", &pfcharged#1_, &b_pfcharged#1_);
   fChain->SetBranchAddress("pfcharged#1.index", &pfcharged#1_index, &b_pfcharged#1_index);
   fChain->SetBranchAddress("pfcharged#1.collectionID", &pfcharged#1_collectionID, &b_pfcharged#1_collectionID);
   fChain->SetBranchAddress("chargedToMC", &chargedToMC, &b_chargedToMC);
   fChain->SetBranchAddress("chargedToMC#0", &chargedToMC#0_, &b_chargedToMC#0_);
   fChain->SetBranchAddress("chargedToMC#0.index", chargedToMC#0_index, &b_chargedToMC#0_index);
   fChain->SetBranchAddress("chargedToMC#0.collectionID", chargedToMC#0_collectionID, &b_chargedToMC#0_collectionID);
   fChain->SetBranchAddress("chargedToMC#1", &chargedToMC#1_, &b_chargedToMC#1_);
   fChain->SetBranchAddress("chargedToMC#1.index", chargedToMC#1_index, &b_chargedToMC#1_index);
   fChain->SetBranchAddress("chargedToMC#1.collectionID", chargedToMC#1_collectionID, &b_chargedToMC#1_collectionID);
   fChain->SetBranchAddress("pfphotons", &pfphotons_, &b_pfphotons_);
   fChain->SetBranchAddress("pfphotons.core.bits", pfphotons_core_bits, &b_pfphotons_core_bits);
   fChain->SetBranchAddress("pfphotons.core.charge", pfphotons_core_charge, &b_pfphotons_core_charge);
   fChain->SetBranchAddress("pfphotons.core.p4.mass", pfphotons_core_p4_mass, &b_pfphotons_core_p4_mass);
   fChain->SetBranchAddress("pfphotons.core.p4.px", pfphotons_core_p4_px, &b_pfphotons_core_p4_px);
   fChain->SetBranchAddress("pfphotons.core.p4.py", pfphotons_core_p4_py, &b_pfphotons_core_p4_py);
   fChain->SetBranchAddress("pfphotons.core.p4.pz", pfphotons_core_p4_pz, &b_pfphotons_core_p4_pz);
   fChain->SetBranchAddress("pfphotons.core.pdgId", pfphotons_core_pdgId, &b_pfphotons_core_pdgId);
   fChain->SetBranchAddress("pfphotons.core.status", pfphotons_core_status, &b_pfphotons_core_status);
   fChain->SetBranchAddress("pfphotons.core.vertex.x", pfphotons_core_vertex_x, &b_pfphotons_core_vertex_x);
   fChain->SetBranchAddress("pfphotons.core.vertex.y", pfphotons_core_vertex_y, &b_pfphotons_core_vertex_y);
   fChain->SetBranchAddress("pfphotons.core.vertex.z", pfphotons_core_vertex_z, &b_pfphotons_core_vertex_z);
   fChain->SetBranchAddress("pfphotons.tracks_begin", pfphotons_tracks_begin, &b_pfphotons_tracks_begin);
   fChain->SetBranchAddress("pfphotons.tracks_end", pfphotons_tracks_end, &b_pfphotons_tracks_end);
   fChain->SetBranchAddress("pfphotons.clusters_begin", pfphotons_clusters_begin, &b_pfphotons_clusters_begin);
   fChain->SetBranchAddress("pfphotons.clusters_end", pfphotons_clusters_end, &b_pfphotons_clusters_end);
   fChain->SetBranchAddress("pfphotons#0", &pfphotons#0_, &b_pfphotons#0_);
   fChain->SetBranchAddress("pfphotons#0.index", &pfphotons#0_index, &b_pfphotons#0_index);
   fChain->SetBranchAddress("pfphotons#0.collectionID", &pfphotons#0_collectionID, &b_pfphotons#0_collectionID);
   fChain->SetBranchAddress("pfphotons#1", &pfphotons#1_, &b_pfphotons#1_);
   fChain->SetBranchAddress("pfphotons#1.index", &pfphotons#1_index, &b_pfphotons#1_index);
   fChain->SetBranchAddress("pfphotons#1.collectionID", &pfphotons#1_collectionID, &b_pfphotons#1_collectionID);
   fChain->SetBranchAddress("pfphotonsToMC", &pfphotonsToMC, &b_pfphotonsToMC);
   fChain->SetBranchAddress("pfphotonsToMC#0", &pfphotonsToMC#0_, &b_pfphotonsToMC#0_);
   fChain->SetBranchAddress("pfphotonsToMC#0.index", pfphotonsToMC#0_index, &b_pfphotonsToMC#0_index);
   fChain->SetBranchAddress("pfphotonsToMC#0.collectionID", pfphotonsToMC#0_collectionID, &b_pfphotonsToMC#0_collectionID);
   fChain->SetBranchAddress("pfphotonsToMC#1", &pfphotonsToMC#1_, &b_pfphotonsToMC#1_);
   fChain->SetBranchAddress("pfphotonsToMC#1.index", pfphotonsToMC#1_index, &b_pfphotonsToMC#1_index);
   fChain->SetBranchAddress("pfphotonsToMC#1.collectionID", pfphotonsToMC#1_collectionID, &b_pfphotonsToMC#1_collectionID);
   fChain->SetBranchAddress("pfneutrals", &pfneutrals_, &b_pfneutrals_);
   fChain->SetBranchAddress("pfneutrals.core.bits", pfneutrals_core_bits, &b_pfneutrals_core_bits);
   fChain->SetBranchAddress("pfneutrals.core.charge", pfneutrals_core_charge, &b_pfneutrals_core_charge);
   fChain->SetBranchAddress("pfneutrals.core.p4.mass", pfneutrals_core_p4_mass, &b_pfneutrals_core_p4_mass);
   fChain->SetBranchAddress("pfneutrals.core.p4.px", pfneutrals_core_p4_px, &b_pfneutrals_core_p4_px);
   fChain->SetBranchAddress("pfneutrals.core.p4.py", pfneutrals_core_p4_py, &b_pfneutrals_core_p4_py);
   fChain->SetBranchAddress("pfneutrals.core.p4.pz", pfneutrals_core_p4_pz, &b_pfneutrals_core_p4_pz);
   fChain->SetBranchAddress("pfneutrals.core.pdgId", pfneutrals_core_pdgId, &b_pfneutrals_core_pdgId);
   fChain->SetBranchAddress("pfneutrals.core.status", pfneutrals_core_status, &b_pfneutrals_core_status);
   fChain->SetBranchAddress("pfneutrals.core.vertex.x", pfneutrals_core_vertex_x, &b_pfneutrals_core_vertex_x);
   fChain->SetBranchAddress("pfneutrals.core.vertex.y", pfneutrals_core_vertex_y, &b_pfneutrals_core_vertex_y);
   fChain->SetBranchAddress("pfneutrals.core.vertex.z", pfneutrals_core_vertex_z, &b_pfneutrals_core_vertex_z);
   fChain->SetBranchAddress("pfneutrals.tracks_begin", pfneutrals_tracks_begin, &b_pfneutrals_tracks_begin);
   fChain->SetBranchAddress("pfneutrals.tracks_end", pfneutrals_tracks_end, &b_pfneutrals_tracks_end);
   fChain->SetBranchAddress("pfneutrals.clusters_begin", pfneutrals_clusters_begin, &b_pfneutrals_clusters_begin);
   fChain->SetBranchAddress("pfneutrals.clusters_end", pfneutrals_clusters_end, &b_pfneutrals_clusters_end);
   fChain->SetBranchAddress("pfneutrals#0", &pfneutrals#0_, &b_pfneutrals#0_);
   fChain->SetBranchAddress("pfneutrals#0.index", &pfneutrals#0_index, &b_pfneutrals#0_index);
   fChain->SetBranchAddress("pfneutrals#0.collectionID", &pfneutrals#0_collectionID, &b_pfneutrals#0_collectionID);
   fChain->SetBranchAddress("pfneutrals#1", &pfneutrals#1_, &b_pfneutrals#1_);
   fChain->SetBranchAddress("pfneutrals#1.index", &pfneutrals#1_index, &b_pfneutrals#1_index);
   fChain->SetBranchAddress("pfneutrals#1.collectionID", &pfneutrals#1_collectionID, &b_pfneutrals#1_collectionID);
   fChain->SetBranchAddress("pfneutralsToMC", &pfneutralsToMC, &b_pfneutralsToMC);
   fChain->SetBranchAddress("pfneutralsToMC#0", &pfneutralsToMC#0_, &b_pfneutralsToMC#0_);
   fChain->SetBranchAddress("pfneutralsToMC#0.index", pfneutralsToMC#0_index, &b_pfneutralsToMC#0_index);
   fChain->SetBranchAddress("pfneutralsToMC#0.collectionID", pfneutralsToMC#0_collectionID, &b_pfneutralsToMC#0_collectionID);
   fChain->SetBranchAddress("pfneutralsToMC#1", &pfneutralsToMC#1_, &b_pfneutralsToMC#1_);
   fChain->SetBranchAddress("pfneutralsToMC#1.index", pfneutralsToMC#1_index, &b_pfneutralsToMC#1_index);
   fChain->SetBranchAddress("pfneutralsToMC#1.collectionID", pfneutralsToMC#1_collectionID, &b_pfneutralsToMC#1_collectionID);
   fChain->SetBranchAddress("genjets02", &genjets02_, &b_genjets02_);
   fChain->SetBranchAddress("genjets02.core.area", genjets02_core_area, &b_genjets02_core_area);
   fChain->SetBranchAddress("genjets02.core.bits", genjets02_core_bits, &b_genjets02_core_bits);
   fChain->SetBranchAddress("genjets02.core.p4.mass", genjets02_core_p4_mass, &b_genjets02_core_p4_mass);
   fChain->SetBranchAddress("genjets02.core.p4.px", genjets02_core_p4_px, &b_genjets02_core_p4_px);
   fChain->SetBranchAddress("genjets02.core.p4.py", genjets02_core_p4_py, &b_genjets02_core_p4_py);
   fChain->SetBranchAddress("genjets02.core.p4.pz", genjets02_core_p4_pz, &b_genjets02_core_p4_pz);
   fChain->SetBranchAddress("genjets02.particles_begin", genjets02_particles_begin, &b_genjets02_particles_begin);
   fChain->SetBranchAddress("genjets02.particles_end", genjets02_particles_end, &b_genjets02_particles_end);
   fChain->SetBranchAddress("genjets02#0", &genjets02#0_, &b_genjets02#0_);
   fChain->SetBranchAddress("genjets02#0.index", &genjets02#0_index, &b_genjets02#0_index);
   fChain->SetBranchAddress("genjets02#0.collectionID", &genjets02#0_collectionID, &b_genjets02#0_collectionID);
   fChain->SetBranchAddress("genjetsFlavor02", &genjetsFlavor02_, &b_genjetsFlavor02_);
   fChain->SetBranchAddress("genjetsFlavor02.tag", genjetsFlavor02_tag, &b_genjetsFlavor02_tag);
   fChain->SetBranchAddress("genjetsFlavor02#0", &genjetsFlavor02#0_, &b_genjetsFlavor02#0_);
   fChain->SetBranchAddress("genjetsFlavor02#0.index", genjetsFlavor02#0_index, &b_genjetsFlavor02#0_index);
   fChain->SetBranchAddress("genjetsFlavor02#0.collectionID", genjetsFlavor02#0_collectionID, &b_genjetsFlavor02#0_collectionID);
   fChain->SetBranchAddress("genjets04", &genjets04_, &b_genjets04_);
   fChain->SetBranchAddress("genjets04.core.area", genjets04_core_area, &b_genjets04_core_area);
   fChain->SetBranchAddress("genjets04.core.bits", genjets04_core_bits, &b_genjets04_core_bits);
   fChain->SetBranchAddress("genjets04.core.p4.mass", genjets04_core_p4_mass, &b_genjets04_core_p4_mass);
   fChain->SetBranchAddress("genjets04.core.p4.px", genjets04_core_p4_px, &b_genjets04_core_p4_px);
   fChain->SetBranchAddress("genjets04.core.p4.py", genjets04_core_p4_py, &b_genjets04_core_p4_py);
   fChain->SetBranchAddress("genjets04.core.p4.pz", genjets04_core_p4_pz, &b_genjets04_core_p4_pz);
   fChain->SetBranchAddress("genjets04.particles_begin", genjets04_particles_begin, &b_genjets04_particles_begin);
   fChain->SetBranchAddress("genjets04.particles_end", genjets04_particles_end, &b_genjets04_particles_end);
   fChain->SetBranchAddress("genjets04#0", &genjets04#0_, &b_genjets04#0_);
   fChain->SetBranchAddress("genjets04#0.index", &genjets04#0_index, &b_genjets04#0_index);
   fChain->SetBranchAddress("genjets04#0.collectionID", &genjets04#0_collectionID, &b_genjets04#0_collectionID);
   fChain->SetBranchAddress("genjetsFlavor04", &genjetsFlavor04_, &b_genjetsFlavor04_);
   fChain->SetBranchAddress("genjetsFlavor04.tag", genjetsFlavor04_tag, &b_genjetsFlavor04_tag);
   fChain->SetBranchAddress("genjetsFlavor04#0", &genjetsFlavor04#0_, &b_genjetsFlavor04#0_);
   fChain->SetBranchAddress("genjetsFlavor04#0.index", genjetsFlavor04#0_index, &b_genjetsFlavor04#0_index);
   fChain->SetBranchAddress("genjetsFlavor04#0.collectionID", genjetsFlavor04#0_collectionID, &b_genjetsFlavor04#0_collectionID);
   fChain->SetBranchAddress("genjets08", &genjets08_, &b_genjets08_);
   fChain->SetBranchAddress("genjets08.core.area", genjets08_core_area, &b_genjets08_core_area);
   fChain->SetBranchAddress("genjets08.core.bits", genjets08_core_bits, &b_genjets08_core_bits);
   fChain->SetBranchAddress("genjets08.core.p4.mass", genjets08_core_p4_mass, &b_genjets08_core_p4_mass);
   fChain->SetBranchAddress("genjets08.core.p4.px", genjets08_core_p4_px, &b_genjets08_core_p4_px);
   fChain->SetBranchAddress("genjets08.core.p4.py", genjets08_core_p4_py, &b_genjets08_core_p4_py);
   fChain->SetBranchAddress("genjets08.core.p4.pz", genjets08_core_p4_pz, &b_genjets08_core_p4_pz);
   fChain->SetBranchAddress("genjets08.particles_begin", genjets08_particles_begin, &b_genjets08_particles_begin);
   fChain->SetBranchAddress("genjets08.particles_end", genjets08_particles_end, &b_genjets08_particles_end);
   fChain->SetBranchAddress("genjets08#0", &genjets08#0_, &b_genjets08#0_);
   fChain->SetBranchAddress("genjets08#0.index", &genjets08#0_index, &b_genjets08#0_index);
   fChain->SetBranchAddress("genjets08#0.collectionID", &genjets08#0_collectionID, &b_genjets08#0_collectionID);
   fChain->SetBranchAddress("genjetsFlavor08", &genjetsFlavor08_, &b_genjetsFlavor08_);
   fChain->SetBranchAddress("genjetsFlavor08.tag", genjetsFlavor08_tag, &b_genjetsFlavor08_tag);
   fChain->SetBranchAddress("genjetsFlavor08#0", &genjetsFlavor08#0_, &b_genjetsFlavor08#0_);
   fChain->SetBranchAddress("genjetsFlavor08#0.index", genjetsFlavor08#0_index, &b_genjetsFlavor08#0_index);
   fChain->SetBranchAddress("genjetsFlavor08#0.collectionID", genjetsFlavor08#0_collectionID, &b_genjetsFlavor08#0_collectionID);
   fChain->SetBranchAddress("genjets15", &genjets15_, &b_genjets15_);
   fChain->SetBranchAddress("genjets15.core.area", genjets15_core_area, &b_genjets15_core_area);
   fChain->SetBranchAddress("genjets15.core.bits", genjets15_core_bits, &b_genjets15_core_bits);
   fChain->SetBranchAddress("genjets15.core.p4.mass", genjets15_core_p4_mass, &b_genjets15_core_p4_mass);
   fChain->SetBranchAddress("genjets15.core.p4.px", genjets15_core_p4_px, &b_genjets15_core_p4_px);
   fChain->SetBranchAddress("genjets15.core.p4.py", genjets15_core_p4_py, &b_genjets15_core_p4_py);
   fChain->SetBranchAddress("genjets15.core.p4.pz", genjets15_core_p4_pz, &b_genjets15_core_p4_pz);
   fChain->SetBranchAddress("genjets15.particles_begin", genjets15_particles_begin, &b_genjets15_particles_begin);
   fChain->SetBranchAddress("genjets15.particles_end", genjets15_particles_end, &b_genjets15_particles_end);
   fChain->SetBranchAddress("genjets15#0", &genjets15#0_, &b_genjets15#0_);
   fChain->SetBranchAddress("genjets15#0.index", &genjets15#0_index, &b_genjets15#0_index);
   fChain->SetBranchAddress("genjets15#0.collectionID", &genjets15#0_collectionID, &b_genjets15#0_collectionID);
   fChain->SetBranchAddress("genjetsFlavor15", &genjetsFlavor15_, &b_genjetsFlavor15_);
   fChain->SetBranchAddress("genjetsFlavor15.tag", genjetsFlavor15_tag, &b_genjetsFlavor15_tag);
   fChain->SetBranchAddress("genjetsFlavor15#0", &genjetsFlavor15#0_, &b_genjetsFlavor15#0_);
   fChain->SetBranchAddress("genjetsFlavor15#0.index", genjetsFlavor15#0_index, &b_genjetsFlavor15#0_index);
   fChain->SetBranchAddress("genjetsFlavor15#0.collectionID", genjetsFlavor15#0_collectionID, &b_genjetsFlavor15#0_collectionID);
   fChain->SetBranchAddress("calojets02", &calojets02_, &b_calojets02_);
   fChain->SetBranchAddress("calojets02.core.area", calojets02_core_area, &b_calojets02_core_area);
   fChain->SetBranchAddress("calojets02.core.bits", calojets02_core_bits, &b_calojets02_core_bits);
   fChain->SetBranchAddress("calojets02.core.p4.mass", calojets02_core_p4_mass, &b_calojets02_core_p4_mass);
   fChain->SetBranchAddress("calojets02.core.p4.px", calojets02_core_p4_px, &b_calojets02_core_p4_px);
   fChain->SetBranchAddress("calojets02.core.p4.py", calojets02_core_p4_py, &b_calojets02_core_p4_py);
   fChain->SetBranchAddress("calojets02.core.p4.pz", calojets02_core_p4_pz, &b_calojets02_core_p4_pz);
   fChain->SetBranchAddress("calojets02.particles_begin", calojets02_particles_begin, &b_calojets02_particles_begin);
   fChain->SetBranchAddress("calojets02.particles_end", calojets02_particles_end, &b_calojets02_particles_end);
   fChain->SetBranchAddress("calojets02#0", &calojets02#0_, &b_calojets02#0_);
   fChain->SetBranchAddress("calojets02#0.index", calojets02#0_index, &b_calojets02#0_index);
   fChain->SetBranchAddress("calojets02#0.collectionID", calojets02#0_collectionID, &b_calojets02#0_collectionID);
   fChain->SetBranchAddress("calojetsFlavor02", &calojetsFlavor02_, &b_calojetsFlavor02_);
   fChain->SetBranchAddress("calojetsFlavor02.tag", calojetsFlavor02_tag, &b_calojetsFlavor02_tag);
   fChain->SetBranchAddress("calojetsFlavor02#0", &calojetsFlavor02#0_, &b_calojetsFlavor02#0_);
   fChain->SetBranchAddress("calojetsFlavor02#0.index", calojetsFlavor02#0_index, &b_calojetsFlavor02#0_index);
   fChain->SetBranchAddress("calojetsFlavor02#0.collectionID", calojetsFlavor02#0_collectionID, &b_calojetsFlavor02#0_collectionID);
   fChain->SetBranchAddress("calobTags02", &calobTags02_, &b_calobTags02_);
   fChain->SetBranchAddress("calobTags02.tag", calobTags02_tag, &b_calobTags02_tag);
   fChain->SetBranchAddress("calobTags02#0", &calobTags02#0_, &b_calobTags02#0_);
   fChain->SetBranchAddress("calobTags02#0.index", calobTags02#0_index, &b_calobTags02#0_index);
   fChain->SetBranchAddress("calobTags02#0.collectionID", calobTags02#0_collectionID, &b_calobTags02#0_collectionID);
   fChain->SetBranchAddress("calocTags02", &calocTags02_, &b_calocTags02_);
   fChain->SetBranchAddress("calocTags02.tag", calocTags02_tag, &b_calocTags02_tag);
   fChain->SetBranchAddress("calocTags02#0", &calocTags02#0_, &b_calocTags02#0_);
   fChain->SetBranchAddress("calocTags02#0.index", calocTags02#0_index, &b_calocTags02#0_index);
   fChain->SetBranchAddress("calocTags02#0.collectionID", calocTags02#0_collectionID, &b_calocTags02#0_collectionID);
   fChain->SetBranchAddress("calotauTags02", &calotauTags02_, &b_calotauTags02_);
   fChain->SetBranchAddress("calotauTags02.tag", calotauTags02_tag, &b_calotauTags02_tag);
   fChain->SetBranchAddress("calotauTags02#0", &calotauTags02#0_, &b_calotauTags02#0_);
   fChain->SetBranchAddress("calotauTags02#0.index", calotauTags02#0_index, &b_calotauTags02#0_index);
   fChain->SetBranchAddress("calotauTags02#0.collectionID", calotauTags02#0_collectionID, &b_calotauTags02#0_collectionID);
   fChain->SetBranchAddress("calojetParts02", &calojetParts02_, &b_calojetParts02_);
   fChain->SetBranchAddress("calojetParts02.core.bits", calojetParts02_core_bits, &b_calojetParts02_core_bits);
   fChain->SetBranchAddress("calojetParts02.core.charge", calojetParts02_core_charge, &b_calojetParts02_core_charge);
   fChain->SetBranchAddress("calojetParts02.core.p4.mass", calojetParts02_core_p4_mass, &b_calojetParts02_core_p4_mass);
   fChain->SetBranchAddress("calojetParts02.core.p4.px", calojetParts02_core_p4_px, &b_calojetParts02_core_p4_px);
   fChain->SetBranchAddress("calojetParts02.core.p4.py", calojetParts02_core_p4_py, &b_calojetParts02_core_p4_py);
   fChain->SetBranchAddress("calojetParts02.core.p4.pz", calojetParts02_core_p4_pz, &b_calojetParts02_core_p4_pz);
   fChain->SetBranchAddress("calojetParts02.core.pdgId", calojetParts02_core_pdgId, &b_calojetParts02_core_pdgId);
   fChain->SetBranchAddress("calojetParts02.core.status", calojetParts02_core_status, &b_calojetParts02_core_status);
   fChain->SetBranchAddress("calojetParts02.core.vertex.x", calojetParts02_core_vertex_x, &b_calojetParts02_core_vertex_x);
   fChain->SetBranchAddress("calojetParts02.core.vertex.y", calojetParts02_core_vertex_y, &b_calojetParts02_core_vertex_y);
   fChain->SetBranchAddress("calojetParts02.core.vertex.z", calojetParts02_core_vertex_z, &b_calojetParts02_core_vertex_z);
   fChain->SetBranchAddress("calojetParts02.tracks_begin", calojetParts02_tracks_begin, &b_calojetParts02_tracks_begin);
   fChain->SetBranchAddress("calojetParts02.tracks_end", calojetParts02_tracks_end, &b_calojetParts02_tracks_end);
   fChain->SetBranchAddress("calojetParts02.clusters_begin", calojetParts02_clusters_begin, &b_calojetParts02_clusters_begin);
   fChain->SetBranchAddress("calojetParts02.clusters_end", calojetParts02_clusters_end, &b_calojetParts02_clusters_end);
   fChain->SetBranchAddress("calojetParts02#0", &calojetParts02#0_, &b_calojetParts02#0_);
   fChain->SetBranchAddress("calojetParts02#0.index", &calojetParts02#0_index, &b_calojetParts02#0_index);
   fChain->SetBranchAddress("calojetParts02#0.collectionID", &calojetParts02#0_collectionID, &b_calojetParts02#0_collectionID);
   fChain->SetBranchAddress("calojetParts02#1", &calojetParts02#1_, &b_calojetParts02#1_);
   fChain->SetBranchAddress("calojetParts02#1.index", &calojetParts02#1_index, &b_calojetParts02#1_index);
   fChain->SetBranchAddress("calojetParts02#1.collectionID", &calojetParts02#1_collectionID, &b_calojetParts02#1_collectionID);
   fChain->SetBranchAddress("calojetsOneSubJettiness02", &calojetsOneSubJettiness02_, &b_calojetsOneSubJettiness02_);
   fChain->SetBranchAddress("calojetsOneSubJettiness02.tag", calojetsOneSubJettiness02_tag, &b_calojetsOneSubJettiness02_tag);
   fChain->SetBranchAddress("calojetsOneSubJettiness02#0", &calojetsOneSubJettiness02#0_, &b_calojetsOneSubJettiness02#0_);
   fChain->SetBranchAddress("calojetsOneSubJettiness02#0.index", calojetsOneSubJettiness02#0_index, &b_calojetsOneSubJettiness02#0_index);
   fChain->SetBranchAddress("calojetsOneSubJettiness02#0.collectionID", calojetsOneSubJettiness02#0_collectionID, &b_calojetsOneSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("calojetsTwoSubJettiness02", &calojetsTwoSubJettiness02_, &b_calojetsTwoSubJettiness02_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness02.tag", calojetsTwoSubJettiness02_tag, &b_calojetsTwoSubJettiness02_tag);
   fChain->SetBranchAddress("calojetsTwoSubJettiness02#0", &calojetsTwoSubJettiness02#0_, &b_calojetsTwoSubJettiness02#0_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness02#0.index", calojetsTwoSubJettiness02#0_index, &b_calojetsTwoSubJettiness02#0_index);
   fChain->SetBranchAddress("calojetsTwoSubJettiness02#0.collectionID", calojetsTwoSubJettiness02#0_collectionID, &b_calojetsTwoSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("calojetsThreeSubJettiness02", &calojetsThreeSubJettiness02_, &b_calojetsThreeSubJettiness02_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness02.tag", calojetsThreeSubJettiness02_tag, &b_calojetsThreeSubJettiness02_tag);
   fChain->SetBranchAddress("calojetsThreeSubJettiness02#0", &calojetsThreeSubJettiness02#0_, &b_calojetsThreeSubJettiness02#0_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness02#0.index", calojetsThreeSubJettiness02#0_index, &b_calojetsThreeSubJettiness02#0_index);
   fChain->SetBranchAddress("calojetsThreeSubJettiness02#0.collectionID", calojetsThreeSubJettiness02#0_collectionID, &b_calojetsThreeSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02", &calosubjetsTrimmingTagged02_, &b_calosubjetsTrimmingTagged02_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02.subjets_begin", calosubjetsTrimmingTagged02_subjets_begin, &b_calosubjetsTrimmingTagged02_subjets_begin);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02.subjets_end", calosubjetsTrimmingTagged02_subjets_end, &b_calosubjetsTrimmingTagged02_subjets_end);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02#0", &calosubjetsTrimmingTagged02#0_, &b_calosubjetsTrimmingTagged02#0_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02#0.index", &calosubjetsTrimmingTagged02#0_index, &b_calosubjetsTrimmingTagged02#0_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02#0.collectionID", &calosubjetsTrimmingTagged02#0_collectionID, &b_calosubjetsTrimmingTagged02#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02#1", &calosubjetsTrimmingTagged02#1_, &b_calosubjetsTrimmingTagged02#1_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02#1.index", calosubjetsTrimmingTagged02#1_index, &b_calosubjetsTrimmingTagged02#1_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged02#1.collectionID", calosubjetsTrimmingTagged02#1_collectionID, &b_calosubjetsTrimmingTagged02#1_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged02", &calosubjetsPruningTagged02_, &b_calosubjetsPruningTagged02_);
   fChain->SetBranchAddress("calosubjetsPruningTagged02.subjets_begin", calosubjetsPruningTagged02_subjets_begin, &b_calosubjetsPruningTagged02_subjets_begin);
   fChain->SetBranchAddress("calosubjetsPruningTagged02.subjets_end", calosubjetsPruningTagged02_subjets_end, &b_calosubjetsPruningTagged02_subjets_end);
   fChain->SetBranchAddress("calosubjetsPruningTagged02#0", &calosubjetsPruningTagged02#0_, &b_calosubjetsPruningTagged02#0_);
   fChain->SetBranchAddress("calosubjetsPruningTagged02#0.index", &calosubjetsPruningTagged02#0_index, &b_calosubjetsPruningTagged02#0_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged02#0.collectionID", &calosubjetsPruningTagged02#0_collectionID, &b_calosubjetsPruningTagged02#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged02#1", &calosubjetsPruningTagged02#1_, &b_calosubjetsPruningTagged02#1_);
   fChain->SetBranchAddress("calosubjetsPruningTagged02#1.index", calosubjetsPruningTagged02#1_index, &b_calosubjetsPruningTagged02#1_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged02#1.collectionID", calosubjetsPruningTagged02#1_collectionID, &b_calosubjetsPruningTagged02#1_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02", &calosubjetsSoftDropTagged02_, &b_calosubjetsSoftDropTagged02_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02.subjets_begin", calosubjetsSoftDropTagged02_subjets_begin, &b_calosubjetsSoftDropTagged02_subjets_begin);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02.subjets_end", calosubjetsSoftDropTagged02_subjets_end, &b_calosubjetsSoftDropTagged02_subjets_end);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02#0", &calosubjetsSoftDropTagged02#0_, &b_calosubjetsSoftDropTagged02#0_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02#0.index", calosubjetsSoftDropTagged02#0_index, &b_calosubjetsSoftDropTagged02#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02#0.collectionID", calosubjetsSoftDropTagged02#0_collectionID, &b_calosubjetsSoftDropTagged02#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02#1", &calosubjetsSoftDropTagged02#1_, &b_calosubjetsSoftDropTagged02#1_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02#1.index", calosubjetsSoftDropTagged02#1_index, &b_calosubjetsSoftDropTagged02#1_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged02#1.collectionID", calosubjetsSoftDropTagged02#1_collectionID, &b_calosubjetsSoftDropTagged02#1_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimming02", &calosubjetsTrimming02_, &b_calosubjetsTrimming02_);
   fChain->SetBranchAddress("calosubjetsTrimming02.core.area", &calosubjetsTrimming02_core_area, &b_calosubjetsTrimming02_core_area);
   fChain->SetBranchAddress("calosubjetsTrimming02.core.bits", &calosubjetsTrimming02_core_bits, &b_calosubjetsTrimming02_core_bits);
   fChain->SetBranchAddress("calosubjetsTrimming02.core.p4.mass", &calosubjetsTrimming02_core_p4_mass, &b_calosubjetsTrimming02_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsTrimming02.core.p4.px", &calosubjetsTrimming02_core_p4_px, &b_calosubjetsTrimming02_core_p4_px);
   fChain->SetBranchAddress("calosubjetsTrimming02.core.p4.py", &calosubjetsTrimming02_core_p4_py, &b_calosubjetsTrimming02_core_p4_py);
   fChain->SetBranchAddress("calosubjetsTrimming02.core.p4.pz", &calosubjetsTrimming02_core_p4_pz, &b_calosubjetsTrimming02_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsTrimming02.particles_begin", &calosubjetsTrimming02_particles_begin, &b_calosubjetsTrimming02_particles_begin);
   fChain->SetBranchAddress("calosubjetsTrimming02.particles_end", &calosubjetsTrimming02_particles_end, &b_calosubjetsTrimming02_particles_end);
   fChain->SetBranchAddress("calosubjetsTrimming02#0", &calosubjetsTrimming02#0_, &b_calosubjetsTrimming02#0_);
   fChain->SetBranchAddress("calosubjetsTrimming02#0.index", &calosubjetsTrimming02#0_index, &b_calosubjetsTrimming02#0_index);
   fChain->SetBranchAddress("calosubjetsTrimming02#0.collectionID", &calosubjetsTrimming02#0_collectionID, &b_calosubjetsTrimming02#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruning02", &calosubjetsPruning02_, &b_calosubjetsPruning02_);
   fChain->SetBranchAddress("calosubjetsPruning02.core.area", &calosubjetsPruning02_core_area, &b_calosubjetsPruning02_core_area);
   fChain->SetBranchAddress("calosubjetsPruning02.core.bits", &calosubjetsPruning02_core_bits, &b_calosubjetsPruning02_core_bits);
   fChain->SetBranchAddress("calosubjetsPruning02.core.p4.mass", &calosubjetsPruning02_core_p4_mass, &b_calosubjetsPruning02_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsPruning02.core.p4.px", &calosubjetsPruning02_core_p4_px, &b_calosubjetsPruning02_core_p4_px);
   fChain->SetBranchAddress("calosubjetsPruning02.core.p4.py", &calosubjetsPruning02_core_p4_py, &b_calosubjetsPruning02_core_p4_py);
   fChain->SetBranchAddress("calosubjetsPruning02.core.p4.pz", &calosubjetsPruning02_core_p4_pz, &b_calosubjetsPruning02_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsPruning02.particles_begin", &calosubjetsPruning02_particles_begin, &b_calosubjetsPruning02_particles_begin);
   fChain->SetBranchAddress("calosubjetsPruning02.particles_end", &calosubjetsPruning02_particles_end, &b_calosubjetsPruning02_particles_end);
   fChain->SetBranchAddress("calosubjetsPruning02#0", &calosubjetsPruning02#0_, &b_calosubjetsPruning02#0_);
   fChain->SetBranchAddress("calosubjetsPruning02#0.index", &calosubjetsPruning02#0_index, &b_calosubjetsPruning02#0_index);
   fChain->SetBranchAddress("calosubjetsPruning02#0.collectionID", &calosubjetsPruning02#0_collectionID, &b_calosubjetsPruning02#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDrop02", &calosubjetsSoftDrop02_, &b_calosubjetsSoftDrop02_);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.core.area", calosubjetsSoftDrop02_core_area, &b_calosubjetsSoftDrop02_core_area);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.core.bits", calosubjetsSoftDrop02_core_bits, &b_calosubjetsSoftDrop02_core_bits);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.core.p4.mass", calosubjetsSoftDrop02_core_p4_mass, &b_calosubjetsSoftDrop02_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.core.p4.px", calosubjetsSoftDrop02_core_p4_px, &b_calosubjetsSoftDrop02_core_p4_px);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.core.p4.py", calosubjetsSoftDrop02_core_p4_py, &b_calosubjetsSoftDrop02_core_p4_py);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.core.p4.pz", calosubjetsSoftDrop02_core_p4_pz, &b_calosubjetsSoftDrop02_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.particles_begin", calosubjetsSoftDrop02_particles_begin, &b_calosubjetsSoftDrop02_particles_begin);
   fChain->SetBranchAddress("calosubjetsSoftDrop02.particles_end", calosubjetsSoftDrop02_particles_end, &b_calosubjetsSoftDrop02_particles_end);
   fChain->SetBranchAddress("calosubjetsSoftDrop02#0", &calosubjetsSoftDrop02#0_, &b_calosubjetsSoftDrop02#0_);
   fChain->SetBranchAddress("calosubjetsSoftDrop02#0.index", &calosubjetsSoftDrop02#0_index, &b_calosubjetsSoftDrop02#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDrop02#0.collectionID", &calosubjetsSoftDrop02#0_collectionID, &b_calosubjetsSoftDrop02#0_collectionID);
   fChain->SetBranchAddress("calojets04", &calojets04_, &b_calojets04_);
   fChain->SetBranchAddress("calojets04.core.area", calojets04_core_area, &b_calojets04_core_area);
   fChain->SetBranchAddress("calojets04.core.bits", calojets04_core_bits, &b_calojets04_core_bits);
   fChain->SetBranchAddress("calojets04.core.p4.mass", calojets04_core_p4_mass, &b_calojets04_core_p4_mass);
   fChain->SetBranchAddress("calojets04.core.p4.px", calojets04_core_p4_px, &b_calojets04_core_p4_px);
   fChain->SetBranchAddress("calojets04.core.p4.py", calojets04_core_p4_py, &b_calojets04_core_p4_py);
   fChain->SetBranchAddress("calojets04.core.p4.pz", calojets04_core_p4_pz, &b_calojets04_core_p4_pz);
   fChain->SetBranchAddress("calojets04.particles_begin", calojets04_particles_begin, &b_calojets04_particles_begin);
   fChain->SetBranchAddress("calojets04.particles_end", calojets04_particles_end, &b_calojets04_particles_end);
   fChain->SetBranchAddress("calojets04#0", &calojets04#0_, &b_calojets04#0_);
   fChain->SetBranchAddress("calojets04#0.index", calojets04#0_index, &b_calojets04#0_index);
   fChain->SetBranchAddress("calojets04#0.collectionID", calojets04#0_collectionID, &b_calojets04#0_collectionID);
   fChain->SetBranchAddress("calojetsFlavor04", &calojetsFlavor04_, &b_calojetsFlavor04_);
   fChain->SetBranchAddress("calojetsFlavor04.tag", calojetsFlavor04_tag, &b_calojetsFlavor04_tag);
   fChain->SetBranchAddress("calojetsFlavor04#0", &calojetsFlavor04#0_, &b_calojetsFlavor04#0_);
   fChain->SetBranchAddress("calojetsFlavor04#0.index", calojetsFlavor04#0_index, &b_calojetsFlavor04#0_index);
   fChain->SetBranchAddress("calojetsFlavor04#0.collectionID", calojetsFlavor04#0_collectionID, &b_calojetsFlavor04#0_collectionID);
   fChain->SetBranchAddress("calobTags04", &calobTags04_, &b_calobTags04_);
   fChain->SetBranchAddress("calobTags04.tag", calobTags04_tag, &b_calobTags04_tag);
   fChain->SetBranchAddress("calobTags04#0", &calobTags04#0_, &b_calobTags04#0_);
   fChain->SetBranchAddress("calobTags04#0.index", calobTags04#0_index, &b_calobTags04#0_index);
   fChain->SetBranchAddress("calobTags04#0.collectionID", calobTags04#0_collectionID, &b_calobTags04#0_collectionID);
   fChain->SetBranchAddress("calocTags04", &calocTags04_, &b_calocTags04_);
   fChain->SetBranchAddress("calocTags04.tag", calocTags04_tag, &b_calocTags04_tag);
   fChain->SetBranchAddress("calocTags04#0", &calocTags04#0_, &b_calocTags04#0_);
   fChain->SetBranchAddress("calocTags04#0.index", calocTags04#0_index, &b_calocTags04#0_index);
   fChain->SetBranchAddress("calocTags04#0.collectionID", calocTags04#0_collectionID, &b_calocTags04#0_collectionID);
   fChain->SetBranchAddress("calotauTags04", &calotauTags04_, &b_calotauTags04_);
   fChain->SetBranchAddress("calotauTags04.tag", calotauTags04_tag, &b_calotauTags04_tag);
   fChain->SetBranchAddress("calotauTags04#0", &calotauTags04#0_, &b_calotauTags04#0_);
   fChain->SetBranchAddress("calotauTags04#0.index", calotauTags04#0_index, &b_calotauTags04#0_index);
   fChain->SetBranchAddress("calotauTags04#0.collectionID", calotauTags04#0_collectionID, &b_calotauTags04#0_collectionID);
   fChain->SetBranchAddress("calojetParts04", &calojetParts04_, &b_calojetParts04_);
   fChain->SetBranchAddress("calojetParts04.core.bits", calojetParts04_core_bits, &b_calojetParts04_core_bits);
   fChain->SetBranchAddress("calojetParts04.core.charge", calojetParts04_core_charge, &b_calojetParts04_core_charge);
   fChain->SetBranchAddress("calojetParts04.core.p4.mass", calojetParts04_core_p4_mass, &b_calojetParts04_core_p4_mass);
   fChain->SetBranchAddress("calojetParts04.core.p4.px", calojetParts04_core_p4_px, &b_calojetParts04_core_p4_px);
   fChain->SetBranchAddress("calojetParts04.core.p4.py", calojetParts04_core_p4_py, &b_calojetParts04_core_p4_py);
   fChain->SetBranchAddress("calojetParts04.core.p4.pz", calojetParts04_core_p4_pz, &b_calojetParts04_core_p4_pz);
   fChain->SetBranchAddress("calojetParts04.core.pdgId", calojetParts04_core_pdgId, &b_calojetParts04_core_pdgId);
   fChain->SetBranchAddress("calojetParts04.core.status", calojetParts04_core_status, &b_calojetParts04_core_status);
   fChain->SetBranchAddress("calojetParts04.core.vertex.x", calojetParts04_core_vertex_x, &b_calojetParts04_core_vertex_x);
   fChain->SetBranchAddress("calojetParts04.core.vertex.y", calojetParts04_core_vertex_y, &b_calojetParts04_core_vertex_y);
   fChain->SetBranchAddress("calojetParts04.core.vertex.z", calojetParts04_core_vertex_z, &b_calojetParts04_core_vertex_z);
   fChain->SetBranchAddress("calojetParts04.tracks_begin", calojetParts04_tracks_begin, &b_calojetParts04_tracks_begin);
   fChain->SetBranchAddress("calojetParts04.tracks_end", calojetParts04_tracks_end, &b_calojetParts04_tracks_end);
   fChain->SetBranchAddress("calojetParts04.clusters_begin", calojetParts04_clusters_begin, &b_calojetParts04_clusters_begin);
   fChain->SetBranchAddress("calojetParts04.clusters_end", calojetParts04_clusters_end, &b_calojetParts04_clusters_end);
   fChain->SetBranchAddress("calojetParts04#0", &calojetParts04#0_, &b_calojetParts04#0_);
   fChain->SetBranchAddress("calojetParts04#0.index", &calojetParts04#0_index, &b_calojetParts04#0_index);
   fChain->SetBranchAddress("calojetParts04#0.collectionID", &calojetParts04#0_collectionID, &b_calojetParts04#0_collectionID);
   fChain->SetBranchAddress("calojetParts04#1", &calojetParts04#1_, &b_calojetParts04#1_);
   fChain->SetBranchAddress("calojetParts04#1.index", &calojetParts04#1_index, &b_calojetParts04#1_index);
   fChain->SetBranchAddress("calojetParts04#1.collectionID", &calojetParts04#1_collectionID, &b_calojetParts04#1_collectionID);
   fChain->SetBranchAddress("calojetsOneSubJettiness04", &calojetsOneSubJettiness04_, &b_calojetsOneSubJettiness04_);
   fChain->SetBranchAddress("calojetsOneSubJettiness04.tag", calojetsOneSubJettiness04_tag, &b_calojetsOneSubJettiness04_tag);
   fChain->SetBranchAddress("calojetsOneSubJettiness04#0", &calojetsOneSubJettiness04#0_, &b_calojetsOneSubJettiness04#0_);
   fChain->SetBranchAddress("calojetsOneSubJettiness04#0.index", calojetsOneSubJettiness04#0_index, &b_calojetsOneSubJettiness04#0_index);
   fChain->SetBranchAddress("calojetsOneSubJettiness04#0.collectionID", calojetsOneSubJettiness04#0_collectionID, &b_calojetsOneSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("calojetsTwoSubJettiness04", &calojetsTwoSubJettiness04_, &b_calojetsTwoSubJettiness04_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness04.tag", calojetsTwoSubJettiness04_tag, &b_calojetsTwoSubJettiness04_tag);
   fChain->SetBranchAddress("calojetsTwoSubJettiness04#0", &calojetsTwoSubJettiness04#0_, &b_calojetsTwoSubJettiness04#0_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness04#0.index", calojetsTwoSubJettiness04#0_index, &b_calojetsTwoSubJettiness04#0_index);
   fChain->SetBranchAddress("calojetsTwoSubJettiness04#0.collectionID", calojetsTwoSubJettiness04#0_collectionID, &b_calojetsTwoSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("calojetsThreeSubJettiness04", &calojetsThreeSubJettiness04_, &b_calojetsThreeSubJettiness04_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness04.tag", calojetsThreeSubJettiness04_tag, &b_calojetsThreeSubJettiness04_tag);
   fChain->SetBranchAddress("calojetsThreeSubJettiness04#0", &calojetsThreeSubJettiness04#0_, &b_calojetsThreeSubJettiness04#0_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness04#0.index", calojetsThreeSubJettiness04#0_index, &b_calojetsThreeSubJettiness04#0_index);
   fChain->SetBranchAddress("calojetsThreeSubJettiness04#0.collectionID", calojetsThreeSubJettiness04#0_collectionID, &b_calojetsThreeSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04", &calosubjetsTrimmingTagged04_, &b_calosubjetsTrimmingTagged04_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04.subjets_begin", calosubjetsTrimmingTagged04_subjets_begin, &b_calosubjetsTrimmingTagged04_subjets_begin);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04.subjets_end", calosubjetsTrimmingTagged04_subjets_end, &b_calosubjetsTrimmingTagged04_subjets_end);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04#0", &calosubjetsTrimmingTagged04#0_, &b_calosubjetsTrimmingTagged04#0_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04#0.index", &calosubjetsTrimmingTagged04#0_index, &b_calosubjetsTrimmingTagged04#0_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04#0.collectionID", &calosubjetsTrimmingTagged04#0_collectionID, &b_calosubjetsTrimmingTagged04#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04#1", &calosubjetsTrimmingTagged04#1_, &b_calosubjetsTrimmingTagged04#1_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04#1.index", calosubjetsTrimmingTagged04#1_index, &b_calosubjetsTrimmingTagged04#1_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged04#1.collectionID", calosubjetsTrimmingTagged04#1_collectionID, &b_calosubjetsTrimmingTagged04#1_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged04", &calosubjetsPruningTagged04_, &b_calosubjetsPruningTagged04_);
   fChain->SetBranchAddress("calosubjetsPruningTagged04.subjets_begin", calosubjetsPruningTagged04_subjets_begin, &b_calosubjetsPruningTagged04_subjets_begin);
   fChain->SetBranchAddress("calosubjetsPruningTagged04.subjets_end", calosubjetsPruningTagged04_subjets_end, &b_calosubjetsPruningTagged04_subjets_end);
   fChain->SetBranchAddress("calosubjetsPruningTagged04#0", &calosubjetsPruningTagged04#0_, &b_calosubjetsPruningTagged04#0_);
   fChain->SetBranchAddress("calosubjetsPruningTagged04#0.index", &calosubjetsPruningTagged04#0_index, &b_calosubjetsPruningTagged04#0_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged04#0.collectionID", &calosubjetsPruningTagged04#0_collectionID, &b_calosubjetsPruningTagged04#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged04#1", &calosubjetsPruningTagged04#1_, &b_calosubjetsPruningTagged04#1_);
   fChain->SetBranchAddress("calosubjetsPruningTagged04#1.index", calosubjetsPruningTagged04#1_index, &b_calosubjetsPruningTagged04#1_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged04#1.collectionID", calosubjetsPruningTagged04#1_collectionID, &b_calosubjetsPruningTagged04#1_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04", &calosubjetsSoftDropTagged04_, &b_calosubjetsSoftDropTagged04_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04.subjets_begin", calosubjetsSoftDropTagged04_subjets_begin, &b_calosubjetsSoftDropTagged04_subjets_begin);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04.subjets_end", calosubjetsSoftDropTagged04_subjets_end, &b_calosubjetsSoftDropTagged04_subjets_end);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04#0", &calosubjetsSoftDropTagged04#0_, &b_calosubjetsSoftDropTagged04#0_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04#0.index", calosubjetsSoftDropTagged04#0_index, &b_calosubjetsSoftDropTagged04#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04#0.collectionID", calosubjetsSoftDropTagged04#0_collectionID, &b_calosubjetsSoftDropTagged04#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04#1", &calosubjetsSoftDropTagged04#1_, &b_calosubjetsSoftDropTagged04#1_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04#1.index", calosubjetsSoftDropTagged04#1_index, &b_calosubjetsSoftDropTagged04#1_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged04#1.collectionID", calosubjetsSoftDropTagged04#1_collectionID, &b_calosubjetsSoftDropTagged04#1_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimming04", &calosubjetsTrimming04_, &b_calosubjetsTrimming04_);
   fChain->SetBranchAddress("calosubjetsTrimming04.core.area", &calosubjetsTrimming04_core_area, &b_calosubjetsTrimming04_core_area);
   fChain->SetBranchAddress("calosubjetsTrimming04.core.bits", &calosubjetsTrimming04_core_bits, &b_calosubjetsTrimming04_core_bits);
   fChain->SetBranchAddress("calosubjetsTrimming04.core.p4.mass", &calosubjetsTrimming04_core_p4_mass, &b_calosubjetsTrimming04_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsTrimming04.core.p4.px", &calosubjetsTrimming04_core_p4_px, &b_calosubjetsTrimming04_core_p4_px);
   fChain->SetBranchAddress("calosubjetsTrimming04.core.p4.py", &calosubjetsTrimming04_core_p4_py, &b_calosubjetsTrimming04_core_p4_py);
   fChain->SetBranchAddress("calosubjetsTrimming04.core.p4.pz", &calosubjetsTrimming04_core_p4_pz, &b_calosubjetsTrimming04_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsTrimming04.particles_begin", &calosubjetsTrimming04_particles_begin, &b_calosubjetsTrimming04_particles_begin);
   fChain->SetBranchAddress("calosubjetsTrimming04.particles_end", &calosubjetsTrimming04_particles_end, &b_calosubjetsTrimming04_particles_end);
   fChain->SetBranchAddress("calosubjetsTrimming04#0", &calosubjetsTrimming04#0_, &b_calosubjetsTrimming04#0_);
   fChain->SetBranchAddress("calosubjetsTrimming04#0.index", &calosubjetsTrimming04#0_index, &b_calosubjetsTrimming04#0_index);
   fChain->SetBranchAddress("calosubjetsTrimming04#0.collectionID", &calosubjetsTrimming04#0_collectionID, &b_calosubjetsTrimming04#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruning04", &calosubjetsPruning04_, &b_calosubjetsPruning04_);
   fChain->SetBranchAddress("calosubjetsPruning04.core.area", &calosubjetsPruning04_core_area, &b_calosubjetsPruning04_core_area);
   fChain->SetBranchAddress("calosubjetsPruning04.core.bits", &calosubjetsPruning04_core_bits, &b_calosubjetsPruning04_core_bits);
   fChain->SetBranchAddress("calosubjetsPruning04.core.p4.mass", &calosubjetsPruning04_core_p4_mass, &b_calosubjetsPruning04_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsPruning04.core.p4.px", &calosubjetsPruning04_core_p4_px, &b_calosubjetsPruning04_core_p4_px);
   fChain->SetBranchAddress("calosubjetsPruning04.core.p4.py", &calosubjetsPruning04_core_p4_py, &b_calosubjetsPruning04_core_p4_py);
   fChain->SetBranchAddress("calosubjetsPruning04.core.p4.pz", &calosubjetsPruning04_core_p4_pz, &b_calosubjetsPruning04_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsPruning04.particles_begin", &calosubjetsPruning04_particles_begin, &b_calosubjetsPruning04_particles_begin);
   fChain->SetBranchAddress("calosubjetsPruning04.particles_end", &calosubjetsPruning04_particles_end, &b_calosubjetsPruning04_particles_end);
   fChain->SetBranchAddress("calosubjetsPruning04#0", &calosubjetsPruning04#0_, &b_calosubjetsPruning04#0_);
   fChain->SetBranchAddress("calosubjetsPruning04#0.index", &calosubjetsPruning04#0_index, &b_calosubjetsPruning04#0_index);
   fChain->SetBranchAddress("calosubjetsPruning04#0.collectionID", &calosubjetsPruning04#0_collectionID, &b_calosubjetsPruning04#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDrop04", &calosubjetsSoftDrop04_, &b_calosubjetsSoftDrop04_);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.core.area", calosubjetsSoftDrop04_core_area, &b_calosubjetsSoftDrop04_core_area);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.core.bits", calosubjetsSoftDrop04_core_bits, &b_calosubjetsSoftDrop04_core_bits);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.core.p4.mass", calosubjetsSoftDrop04_core_p4_mass, &b_calosubjetsSoftDrop04_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.core.p4.px", calosubjetsSoftDrop04_core_p4_px, &b_calosubjetsSoftDrop04_core_p4_px);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.core.p4.py", calosubjetsSoftDrop04_core_p4_py, &b_calosubjetsSoftDrop04_core_p4_py);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.core.p4.pz", calosubjetsSoftDrop04_core_p4_pz, &b_calosubjetsSoftDrop04_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.particles_begin", calosubjetsSoftDrop04_particles_begin, &b_calosubjetsSoftDrop04_particles_begin);
   fChain->SetBranchAddress("calosubjetsSoftDrop04.particles_end", calosubjetsSoftDrop04_particles_end, &b_calosubjetsSoftDrop04_particles_end);
   fChain->SetBranchAddress("calosubjetsSoftDrop04#0", &calosubjetsSoftDrop04#0_, &b_calosubjetsSoftDrop04#0_);
   fChain->SetBranchAddress("calosubjetsSoftDrop04#0.index", &calosubjetsSoftDrop04#0_index, &b_calosubjetsSoftDrop04#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDrop04#0.collectionID", &calosubjetsSoftDrop04#0_collectionID, &b_calosubjetsSoftDrop04#0_collectionID);
   fChain->SetBranchAddress("calojets08", &calojets08_, &b_calojets08_);
   fChain->SetBranchAddress("calojets08.core.area", calojets08_core_area, &b_calojets08_core_area);
   fChain->SetBranchAddress("calojets08.core.bits", calojets08_core_bits, &b_calojets08_core_bits);
   fChain->SetBranchAddress("calojets08.core.p4.mass", calojets08_core_p4_mass, &b_calojets08_core_p4_mass);
   fChain->SetBranchAddress("calojets08.core.p4.px", calojets08_core_p4_px, &b_calojets08_core_p4_px);
   fChain->SetBranchAddress("calojets08.core.p4.py", calojets08_core_p4_py, &b_calojets08_core_p4_py);
   fChain->SetBranchAddress("calojets08.core.p4.pz", calojets08_core_p4_pz, &b_calojets08_core_p4_pz);
   fChain->SetBranchAddress("calojets08.particles_begin", calojets08_particles_begin, &b_calojets08_particles_begin);
   fChain->SetBranchAddress("calojets08.particles_end", calojets08_particles_end, &b_calojets08_particles_end);
   fChain->SetBranchAddress("calojets08#0", &calojets08#0_, &b_calojets08#0_);
   fChain->SetBranchAddress("calojets08#0.index", calojets08#0_index, &b_calojets08#0_index);
   fChain->SetBranchAddress("calojets08#0.collectionID", calojets08#0_collectionID, &b_calojets08#0_collectionID);
   fChain->SetBranchAddress("calojetsFlavor08", &calojetsFlavor08_, &b_calojetsFlavor08_);
   fChain->SetBranchAddress("calojetsFlavor08.tag", calojetsFlavor08_tag, &b_calojetsFlavor08_tag);
   fChain->SetBranchAddress("calojetsFlavor08#0", &calojetsFlavor08#0_, &b_calojetsFlavor08#0_);
   fChain->SetBranchAddress("calojetsFlavor08#0.index", calojetsFlavor08#0_index, &b_calojetsFlavor08#0_index);
   fChain->SetBranchAddress("calojetsFlavor08#0.collectionID", calojetsFlavor08#0_collectionID, &b_calojetsFlavor08#0_collectionID);
   fChain->SetBranchAddress("calobTags08", &calobTags08_, &b_calobTags08_);
   fChain->SetBranchAddress("calobTags08.tag", calobTags08_tag, &b_calobTags08_tag);
   fChain->SetBranchAddress("calobTags08#0", &calobTags08#0_, &b_calobTags08#0_);
   fChain->SetBranchAddress("calobTags08#0.index", calobTags08#0_index, &b_calobTags08#0_index);
   fChain->SetBranchAddress("calobTags08#0.collectionID", calobTags08#0_collectionID, &b_calobTags08#0_collectionID);
   fChain->SetBranchAddress("calocTags08", &calocTags08_, &b_calocTags08_);
   fChain->SetBranchAddress("calocTags08.tag", calocTags08_tag, &b_calocTags08_tag);
   fChain->SetBranchAddress("calocTags08#0", &calocTags08#0_, &b_calocTags08#0_);
   fChain->SetBranchAddress("calocTags08#0.index", calocTags08#0_index, &b_calocTags08#0_index);
   fChain->SetBranchAddress("calocTags08#0.collectionID", calocTags08#0_collectionID, &b_calocTags08#0_collectionID);
   fChain->SetBranchAddress("calotauTags08", &calotauTags08_, &b_calotauTags08_);
   fChain->SetBranchAddress("calotauTags08.tag", calotauTags08_tag, &b_calotauTags08_tag);
   fChain->SetBranchAddress("calotauTags08#0", &calotauTags08#0_, &b_calotauTags08#0_);
   fChain->SetBranchAddress("calotauTags08#0.index", calotauTags08#0_index, &b_calotauTags08#0_index);
   fChain->SetBranchAddress("calotauTags08#0.collectionID", calotauTags08#0_collectionID, &b_calotauTags08#0_collectionID);
   fChain->SetBranchAddress("calojetParts08", &calojetParts08_, &b_calojetParts08_);
   fChain->SetBranchAddress("calojetParts08.core.bits", calojetParts08_core_bits, &b_calojetParts08_core_bits);
   fChain->SetBranchAddress("calojetParts08.core.charge", calojetParts08_core_charge, &b_calojetParts08_core_charge);
   fChain->SetBranchAddress("calojetParts08.core.p4.mass", calojetParts08_core_p4_mass, &b_calojetParts08_core_p4_mass);
   fChain->SetBranchAddress("calojetParts08.core.p4.px", calojetParts08_core_p4_px, &b_calojetParts08_core_p4_px);
   fChain->SetBranchAddress("calojetParts08.core.p4.py", calojetParts08_core_p4_py, &b_calojetParts08_core_p4_py);
   fChain->SetBranchAddress("calojetParts08.core.p4.pz", calojetParts08_core_p4_pz, &b_calojetParts08_core_p4_pz);
   fChain->SetBranchAddress("calojetParts08.core.pdgId", calojetParts08_core_pdgId, &b_calojetParts08_core_pdgId);
   fChain->SetBranchAddress("calojetParts08.core.status", calojetParts08_core_status, &b_calojetParts08_core_status);
   fChain->SetBranchAddress("calojetParts08.core.vertex.x", calojetParts08_core_vertex_x, &b_calojetParts08_core_vertex_x);
   fChain->SetBranchAddress("calojetParts08.core.vertex.y", calojetParts08_core_vertex_y, &b_calojetParts08_core_vertex_y);
   fChain->SetBranchAddress("calojetParts08.core.vertex.z", calojetParts08_core_vertex_z, &b_calojetParts08_core_vertex_z);
   fChain->SetBranchAddress("calojetParts08.tracks_begin", calojetParts08_tracks_begin, &b_calojetParts08_tracks_begin);
   fChain->SetBranchAddress("calojetParts08.tracks_end", calojetParts08_tracks_end, &b_calojetParts08_tracks_end);
   fChain->SetBranchAddress("calojetParts08.clusters_begin", calojetParts08_clusters_begin, &b_calojetParts08_clusters_begin);
   fChain->SetBranchAddress("calojetParts08.clusters_end", calojetParts08_clusters_end, &b_calojetParts08_clusters_end);
   fChain->SetBranchAddress("calojetParts08#0", &calojetParts08#0_, &b_calojetParts08#0_);
   fChain->SetBranchAddress("calojetParts08#0.index", &calojetParts08#0_index, &b_calojetParts08#0_index);
   fChain->SetBranchAddress("calojetParts08#0.collectionID", &calojetParts08#0_collectionID, &b_calojetParts08#0_collectionID);
   fChain->SetBranchAddress("calojetParts08#1", &calojetParts08#1_, &b_calojetParts08#1_);
   fChain->SetBranchAddress("calojetParts08#1.index", &calojetParts08#1_index, &b_calojetParts08#1_index);
   fChain->SetBranchAddress("calojetParts08#1.collectionID", &calojetParts08#1_collectionID, &b_calojetParts08#1_collectionID);
   fChain->SetBranchAddress("calojetsOneSubJettiness08", &calojetsOneSubJettiness08_, &b_calojetsOneSubJettiness08_);
   fChain->SetBranchAddress("calojetsOneSubJettiness08.tag", calojetsOneSubJettiness08_tag, &b_calojetsOneSubJettiness08_tag);
   fChain->SetBranchAddress("calojetsOneSubJettiness08#0", &calojetsOneSubJettiness08#0_, &b_calojetsOneSubJettiness08#0_);
   fChain->SetBranchAddress("calojetsOneSubJettiness08#0.index", calojetsOneSubJettiness08#0_index, &b_calojetsOneSubJettiness08#0_index);
   fChain->SetBranchAddress("calojetsOneSubJettiness08#0.collectionID", calojetsOneSubJettiness08#0_collectionID, &b_calojetsOneSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("calojetsTwoSubJettiness08", &calojetsTwoSubJettiness08_, &b_calojetsTwoSubJettiness08_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness08.tag", calojetsTwoSubJettiness08_tag, &b_calojetsTwoSubJettiness08_tag);
   fChain->SetBranchAddress("calojetsTwoSubJettiness08#0", &calojetsTwoSubJettiness08#0_, &b_calojetsTwoSubJettiness08#0_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness08#0.index", calojetsTwoSubJettiness08#0_index, &b_calojetsTwoSubJettiness08#0_index);
   fChain->SetBranchAddress("calojetsTwoSubJettiness08#0.collectionID", calojetsTwoSubJettiness08#0_collectionID, &b_calojetsTwoSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("calojetsThreeSubJettiness08", &calojetsThreeSubJettiness08_, &b_calojetsThreeSubJettiness08_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness08.tag", calojetsThreeSubJettiness08_tag, &b_calojetsThreeSubJettiness08_tag);
   fChain->SetBranchAddress("calojetsThreeSubJettiness08#0", &calojetsThreeSubJettiness08#0_, &b_calojetsThreeSubJettiness08#0_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness08#0.index", calojetsThreeSubJettiness08#0_index, &b_calojetsThreeSubJettiness08#0_index);
   fChain->SetBranchAddress("calojetsThreeSubJettiness08#0.collectionID", calojetsThreeSubJettiness08#0_collectionID, &b_calojetsThreeSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08", &calosubjetsTrimmingTagged08_, &b_calosubjetsTrimmingTagged08_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08.subjets_begin", calosubjetsTrimmingTagged08_subjets_begin, &b_calosubjetsTrimmingTagged08_subjets_begin);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08.subjets_end", calosubjetsTrimmingTagged08_subjets_end, &b_calosubjetsTrimmingTagged08_subjets_end);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08#0", &calosubjetsTrimmingTagged08#0_, &b_calosubjetsTrimmingTagged08#0_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08#0.index", &calosubjetsTrimmingTagged08#0_index, &b_calosubjetsTrimmingTagged08#0_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08#0.collectionID", &calosubjetsTrimmingTagged08#0_collectionID, &b_calosubjetsTrimmingTagged08#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08#1", &calosubjetsTrimmingTagged08#1_, &b_calosubjetsTrimmingTagged08#1_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08#1.index", calosubjetsTrimmingTagged08#1_index, &b_calosubjetsTrimmingTagged08#1_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged08#1.collectionID", calosubjetsTrimmingTagged08#1_collectionID, &b_calosubjetsTrimmingTagged08#1_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged08", &calosubjetsPruningTagged08_, &b_calosubjetsPruningTagged08_);
   fChain->SetBranchAddress("calosubjetsPruningTagged08.subjets_begin", calosubjetsPruningTagged08_subjets_begin, &b_calosubjetsPruningTagged08_subjets_begin);
   fChain->SetBranchAddress("calosubjetsPruningTagged08.subjets_end", calosubjetsPruningTagged08_subjets_end, &b_calosubjetsPruningTagged08_subjets_end);
   fChain->SetBranchAddress("calosubjetsPruningTagged08#0", &calosubjetsPruningTagged08#0_, &b_calosubjetsPruningTagged08#0_);
   fChain->SetBranchAddress("calosubjetsPruningTagged08#0.index", &calosubjetsPruningTagged08#0_index, &b_calosubjetsPruningTagged08#0_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged08#0.collectionID", &calosubjetsPruningTagged08#0_collectionID, &b_calosubjetsPruningTagged08#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged08#1", &calosubjetsPruningTagged08#1_, &b_calosubjetsPruningTagged08#1_);
   fChain->SetBranchAddress("calosubjetsPruningTagged08#1.index", calosubjetsPruningTagged08#1_index, &b_calosubjetsPruningTagged08#1_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged08#1.collectionID", calosubjetsPruningTagged08#1_collectionID, &b_calosubjetsPruningTagged08#1_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08", &calosubjetsSoftDropTagged08_, &b_calosubjetsSoftDropTagged08_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08.subjets_begin", calosubjetsSoftDropTagged08_subjets_begin, &b_calosubjetsSoftDropTagged08_subjets_begin);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08.subjets_end", calosubjetsSoftDropTagged08_subjets_end, &b_calosubjetsSoftDropTagged08_subjets_end);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08#0", &calosubjetsSoftDropTagged08#0_, &b_calosubjetsSoftDropTagged08#0_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08#0.index", calosubjetsSoftDropTagged08#0_index, &b_calosubjetsSoftDropTagged08#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08#0.collectionID", calosubjetsSoftDropTagged08#0_collectionID, &b_calosubjetsSoftDropTagged08#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08#1", &calosubjetsSoftDropTagged08#1_, &b_calosubjetsSoftDropTagged08#1_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08#1.index", calosubjetsSoftDropTagged08#1_index, &b_calosubjetsSoftDropTagged08#1_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged08#1.collectionID", calosubjetsSoftDropTagged08#1_collectionID, &b_calosubjetsSoftDropTagged08#1_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimming08", &calosubjetsTrimming08_, &b_calosubjetsTrimming08_);
   fChain->SetBranchAddress("calosubjetsTrimming08.core.area", &calosubjetsTrimming08_core_area, &b_calosubjetsTrimming08_core_area);
   fChain->SetBranchAddress("calosubjetsTrimming08.core.bits", &calosubjetsTrimming08_core_bits, &b_calosubjetsTrimming08_core_bits);
   fChain->SetBranchAddress("calosubjetsTrimming08.core.p4.mass", &calosubjetsTrimming08_core_p4_mass, &b_calosubjetsTrimming08_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsTrimming08.core.p4.px", &calosubjetsTrimming08_core_p4_px, &b_calosubjetsTrimming08_core_p4_px);
   fChain->SetBranchAddress("calosubjetsTrimming08.core.p4.py", &calosubjetsTrimming08_core_p4_py, &b_calosubjetsTrimming08_core_p4_py);
   fChain->SetBranchAddress("calosubjetsTrimming08.core.p4.pz", &calosubjetsTrimming08_core_p4_pz, &b_calosubjetsTrimming08_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsTrimming08.particles_begin", &calosubjetsTrimming08_particles_begin, &b_calosubjetsTrimming08_particles_begin);
   fChain->SetBranchAddress("calosubjetsTrimming08.particles_end", &calosubjetsTrimming08_particles_end, &b_calosubjetsTrimming08_particles_end);
   fChain->SetBranchAddress("calosubjetsTrimming08#0", &calosubjetsTrimming08#0_, &b_calosubjetsTrimming08#0_);
   fChain->SetBranchAddress("calosubjetsTrimming08#0.index", &calosubjetsTrimming08#0_index, &b_calosubjetsTrimming08#0_index);
   fChain->SetBranchAddress("calosubjetsTrimming08#0.collectionID", &calosubjetsTrimming08#0_collectionID, &b_calosubjetsTrimming08#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruning08", &calosubjetsPruning08_, &b_calosubjetsPruning08_);
   fChain->SetBranchAddress("calosubjetsPruning08.core.area", &calosubjetsPruning08_core_area, &b_calosubjetsPruning08_core_area);
   fChain->SetBranchAddress("calosubjetsPruning08.core.bits", &calosubjetsPruning08_core_bits, &b_calosubjetsPruning08_core_bits);
   fChain->SetBranchAddress("calosubjetsPruning08.core.p4.mass", &calosubjetsPruning08_core_p4_mass, &b_calosubjetsPruning08_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsPruning08.core.p4.px", &calosubjetsPruning08_core_p4_px, &b_calosubjetsPruning08_core_p4_px);
   fChain->SetBranchAddress("calosubjetsPruning08.core.p4.py", &calosubjetsPruning08_core_p4_py, &b_calosubjetsPruning08_core_p4_py);
   fChain->SetBranchAddress("calosubjetsPruning08.core.p4.pz", &calosubjetsPruning08_core_p4_pz, &b_calosubjetsPruning08_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsPruning08.particles_begin", &calosubjetsPruning08_particles_begin, &b_calosubjetsPruning08_particles_begin);
   fChain->SetBranchAddress("calosubjetsPruning08.particles_end", &calosubjetsPruning08_particles_end, &b_calosubjetsPruning08_particles_end);
   fChain->SetBranchAddress("calosubjetsPruning08#0", &calosubjetsPruning08#0_, &b_calosubjetsPruning08#0_);
   fChain->SetBranchAddress("calosubjetsPruning08#0.index", &calosubjetsPruning08#0_index, &b_calosubjetsPruning08#0_index);
   fChain->SetBranchAddress("calosubjetsPruning08#0.collectionID", &calosubjetsPruning08#0_collectionID, &b_calosubjetsPruning08#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDrop08", &calosubjetsSoftDrop08_, &b_calosubjetsSoftDrop08_);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.core.area", calosubjetsSoftDrop08_core_area, &b_calosubjetsSoftDrop08_core_area);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.core.bits", calosubjetsSoftDrop08_core_bits, &b_calosubjetsSoftDrop08_core_bits);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.core.p4.mass", calosubjetsSoftDrop08_core_p4_mass, &b_calosubjetsSoftDrop08_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.core.p4.px", calosubjetsSoftDrop08_core_p4_px, &b_calosubjetsSoftDrop08_core_p4_px);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.core.p4.py", calosubjetsSoftDrop08_core_p4_py, &b_calosubjetsSoftDrop08_core_p4_py);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.core.p4.pz", calosubjetsSoftDrop08_core_p4_pz, &b_calosubjetsSoftDrop08_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.particles_begin", calosubjetsSoftDrop08_particles_begin, &b_calosubjetsSoftDrop08_particles_begin);
   fChain->SetBranchAddress("calosubjetsSoftDrop08.particles_end", calosubjetsSoftDrop08_particles_end, &b_calosubjetsSoftDrop08_particles_end);
   fChain->SetBranchAddress("calosubjetsSoftDrop08#0", &calosubjetsSoftDrop08#0_, &b_calosubjetsSoftDrop08#0_);
   fChain->SetBranchAddress("calosubjetsSoftDrop08#0.index", &calosubjetsSoftDrop08#0_index, &b_calosubjetsSoftDrop08#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDrop08#0.collectionID", &calosubjetsSoftDrop08#0_collectionID, &b_calosubjetsSoftDrop08#0_collectionID);
   fChain->SetBranchAddress("calojets15", &calojets15_, &b_calojets15_);
   fChain->SetBranchAddress("calojets15.core.area", calojets15_core_area, &b_calojets15_core_area);
   fChain->SetBranchAddress("calojets15.core.bits", calojets15_core_bits, &b_calojets15_core_bits);
   fChain->SetBranchAddress("calojets15.core.p4.mass", calojets15_core_p4_mass, &b_calojets15_core_p4_mass);
   fChain->SetBranchAddress("calojets15.core.p4.px", calojets15_core_p4_px, &b_calojets15_core_p4_px);
   fChain->SetBranchAddress("calojets15.core.p4.py", calojets15_core_p4_py, &b_calojets15_core_p4_py);
   fChain->SetBranchAddress("calojets15.core.p4.pz", calojets15_core_p4_pz, &b_calojets15_core_p4_pz);
   fChain->SetBranchAddress("calojets15.particles_begin", calojets15_particles_begin, &b_calojets15_particles_begin);
   fChain->SetBranchAddress("calojets15.particles_end", calojets15_particles_end, &b_calojets15_particles_end);
   fChain->SetBranchAddress("calojets15#0", &calojets15#0_, &b_calojets15#0_);
   fChain->SetBranchAddress("calojets15#0.index", calojets15#0_index, &b_calojets15#0_index);
   fChain->SetBranchAddress("calojets15#0.collectionID", calojets15#0_collectionID, &b_calojets15#0_collectionID);
   fChain->SetBranchAddress("calojetsFlavor15", &calojetsFlavor15_, &b_calojetsFlavor15_);
   fChain->SetBranchAddress("calojetsFlavor15.tag", calojetsFlavor15_tag, &b_calojetsFlavor15_tag);
   fChain->SetBranchAddress("calojetsFlavor15#0", &calojetsFlavor15#0_, &b_calojetsFlavor15#0_);
   fChain->SetBranchAddress("calojetsFlavor15#0.index", calojetsFlavor15#0_index, &b_calojetsFlavor15#0_index);
   fChain->SetBranchAddress("calojetsFlavor15#0.collectionID", calojetsFlavor15#0_collectionID, &b_calojetsFlavor15#0_collectionID);
   fChain->SetBranchAddress("calobTags15", &calobTags15_, &b_calobTags15_);
   fChain->SetBranchAddress("calobTags15.tag", calobTags15_tag, &b_calobTags15_tag);
   fChain->SetBranchAddress("calobTags15#0", &calobTags15#0_, &b_calobTags15#0_);
   fChain->SetBranchAddress("calobTags15#0.index", calobTags15#0_index, &b_calobTags15#0_index);
   fChain->SetBranchAddress("calobTags15#0.collectionID", calobTags15#0_collectionID, &b_calobTags15#0_collectionID);
   fChain->SetBranchAddress("calocTags15", &calocTags15_, &b_calocTags15_);
   fChain->SetBranchAddress("calocTags15.tag", calocTags15_tag, &b_calocTags15_tag);
   fChain->SetBranchAddress("calocTags15#0", &calocTags15#0_, &b_calocTags15#0_);
   fChain->SetBranchAddress("calocTags15#0.index", calocTags15#0_index, &b_calocTags15#0_index);
   fChain->SetBranchAddress("calocTags15#0.collectionID", calocTags15#0_collectionID, &b_calocTags15#0_collectionID);
   fChain->SetBranchAddress("calotauTags15", &calotauTags15_, &b_calotauTags15_);
   fChain->SetBranchAddress("calotauTags15.tag", calotauTags15_tag, &b_calotauTags15_tag);
   fChain->SetBranchAddress("calotauTags15#0", &calotauTags15#0_, &b_calotauTags15#0_);
   fChain->SetBranchAddress("calotauTags15#0.index", calotauTags15#0_index, &b_calotauTags15#0_index);
   fChain->SetBranchAddress("calotauTags15#0.collectionID", calotauTags15#0_collectionID, &b_calotauTags15#0_collectionID);
   fChain->SetBranchAddress("calojetParts15", &calojetParts15_, &b_calojetParts15_);
   fChain->SetBranchAddress("calojetParts15.core.bits", calojetParts15_core_bits, &b_calojetParts15_core_bits);
   fChain->SetBranchAddress("calojetParts15.core.charge", calojetParts15_core_charge, &b_calojetParts15_core_charge);
   fChain->SetBranchAddress("calojetParts15.core.p4.mass", calojetParts15_core_p4_mass, &b_calojetParts15_core_p4_mass);
   fChain->SetBranchAddress("calojetParts15.core.p4.px", calojetParts15_core_p4_px, &b_calojetParts15_core_p4_px);
   fChain->SetBranchAddress("calojetParts15.core.p4.py", calojetParts15_core_p4_py, &b_calojetParts15_core_p4_py);
   fChain->SetBranchAddress("calojetParts15.core.p4.pz", calojetParts15_core_p4_pz, &b_calojetParts15_core_p4_pz);
   fChain->SetBranchAddress("calojetParts15.core.pdgId", calojetParts15_core_pdgId, &b_calojetParts15_core_pdgId);
   fChain->SetBranchAddress("calojetParts15.core.status", calojetParts15_core_status, &b_calojetParts15_core_status);
   fChain->SetBranchAddress("calojetParts15.core.vertex.x", calojetParts15_core_vertex_x, &b_calojetParts15_core_vertex_x);
   fChain->SetBranchAddress("calojetParts15.core.vertex.y", calojetParts15_core_vertex_y, &b_calojetParts15_core_vertex_y);
   fChain->SetBranchAddress("calojetParts15.core.vertex.z", calojetParts15_core_vertex_z, &b_calojetParts15_core_vertex_z);
   fChain->SetBranchAddress("calojetParts15.tracks_begin", calojetParts15_tracks_begin, &b_calojetParts15_tracks_begin);
   fChain->SetBranchAddress("calojetParts15.tracks_end", calojetParts15_tracks_end, &b_calojetParts15_tracks_end);
   fChain->SetBranchAddress("calojetParts15.clusters_begin", calojetParts15_clusters_begin, &b_calojetParts15_clusters_begin);
   fChain->SetBranchAddress("calojetParts15.clusters_end", calojetParts15_clusters_end, &b_calojetParts15_clusters_end);
   fChain->SetBranchAddress("calojetParts15#0", &calojetParts15#0_, &b_calojetParts15#0_);
   fChain->SetBranchAddress("calojetParts15#0.index", &calojetParts15#0_index, &b_calojetParts15#0_index);
   fChain->SetBranchAddress("calojetParts15#0.collectionID", &calojetParts15#0_collectionID, &b_calojetParts15#0_collectionID);
   fChain->SetBranchAddress("calojetParts15#1", &calojetParts15#1_, &b_calojetParts15#1_);
   fChain->SetBranchAddress("calojetParts15#1.index", &calojetParts15#1_index, &b_calojetParts15#1_index);
   fChain->SetBranchAddress("calojetParts15#1.collectionID", &calojetParts15#1_collectionID, &b_calojetParts15#1_collectionID);
   fChain->SetBranchAddress("calojetsOneSubJettiness15", &calojetsOneSubJettiness15_, &b_calojetsOneSubJettiness15_);
   fChain->SetBranchAddress("calojetsOneSubJettiness15.tag", calojetsOneSubJettiness15_tag, &b_calojetsOneSubJettiness15_tag);
   fChain->SetBranchAddress("calojetsOneSubJettiness15#0", &calojetsOneSubJettiness15#0_, &b_calojetsOneSubJettiness15#0_);
   fChain->SetBranchAddress("calojetsOneSubJettiness15#0.index", calojetsOneSubJettiness15#0_index, &b_calojetsOneSubJettiness15#0_index);
   fChain->SetBranchAddress("calojetsOneSubJettiness15#0.collectionID", calojetsOneSubJettiness15#0_collectionID, &b_calojetsOneSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("calojetsTwoSubJettiness15", &calojetsTwoSubJettiness15_, &b_calojetsTwoSubJettiness15_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness15.tag", calojetsTwoSubJettiness15_tag, &b_calojetsTwoSubJettiness15_tag);
   fChain->SetBranchAddress("calojetsTwoSubJettiness15#0", &calojetsTwoSubJettiness15#0_, &b_calojetsTwoSubJettiness15#0_);
   fChain->SetBranchAddress("calojetsTwoSubJettiness15#0.index", calojetsTwoSubJettiness15#0_index, &b_calojetsTwoSubJettiness15#0_index);
   fChain->SetBranchAddress("calojetsTwoSubJettiness15#0.collectionID", calojetsTwoSubJettiness15#0_collectionID, &b_calojetsTwoSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("calojetsThreeSubJettiness15", &calojetsThreeSubJettiness15_, &b_calojetsThreeSubJettiness15_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness15.tag", calojetsThreeSubJettiness15_tag, &b_calojetsThreeSubJettiness15_tag);
   fChain->SetBranchAddress("calojetsThreeSubJettiness15#0", &calojetsThreeSubJettiness15#0_, &b_calojetsThreeSubJettiness15#0_);
   fChain->SetBranchAddress("calojetsThreeSubJettiness15#0.index", calojetsThreeSubJettiness15#0_index, &b_calojetsThreeSubJettiness15#0_index);
   fChain->SetBranchAddress("calojetsThreeSubJettiness15#0.collectionID", calojetsThreeSubJettiness15#0_collectionID, &b_calojetsThreeSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15", &calosubjetsTrimmingTagged15_, &b_calosubjetsTrimmingTagged15_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15.subjets_begin", calosubjetsTrimmingTagged15_subjets_begin, &b_calosubjetsTrimmingTagged15_subjets_begin);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15.subjets_end", calosubjetsTrimmingTagged15_subjets_end, &b_calosubjetsTrimmingTagged15_subjets_end);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15#0", &calosubjetsTrimmingTagged15#0_, &b_calosubjetsTrimmingTagged15#0_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15#0.index", &calosubjetsTrimmingTagged15#0_index, &b_calosubjetsTrimmingTagged15#0_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15#0.collectionID", &calosubjetsTrimmingTagged15#0_collectionID, &b_calosubjetsTrimmingTagged15#0_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15#1", &calosubjetsTrimmingTagged15#1_, &b_calosubjetsTrimmingTagged15#1_);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15#1.index", calosubjetsTrimmingTagged15#1_index, &b_calosubjetsTrimmingTagged15#1_index);
   fChain->SetBranchAddress("calosubjetsTrimmingTagged15#1.collectionID", calosubjetsTrimmingTagged15#1_collectionID, &b_calosubjetsTrimmingTagged15#1_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged15", &calosubjetsPruningTagged15_, &b_calosubjetsPruningTagged15_);
   fChain->SetBranchAddress("calosubjetsPruningTagged15.subjets_begin", calosubjetsPruningTagged15_subjets_begin, &b_calosubjetsPruningTagged15_subjets_begin);
   fChain->SetBranchAddress("calosubjetsPruningTagged15.subjets_end", calosubjetsPruningTagged15_subjets_end, &b_calosubjetsPruningTagged15_subjets_end);
   fChain->SetBranchAddress("calosubjetsPruningTagged15#0", &calosubjetsPruningTagged15#0_, &b_calosubjetsPruningTagged15#0_);
   fChain->SetBranchAddress("calosubjetsPruningTagged15#0.index", &calosubjetsPruningTagged15#0_index, &b_calosubjetsPruningTagged15#0_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged15#0.collectionID", &calosubjetsPruningTagged15#0_collectionID, &b_calosubjetsPruningTagged15#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruningTagged15#1", &calosubjetsPruningTagged15#1_, &b_calosubjetsPruningTagged15#1_);
   fChain->SetBranchAddress("calosubjetsPruningTagged15#1.index", calosubjetsPruningTagged15#1_index, &b_calosubjetsPruningTagged15#1_index);
   fChain->SetBranchAddress("calosubjetsPruningTagged15#1.collectionID", calosubjetsPruningTagged15#1_collectionID, &b_calosubjetsPruningTagged15#1_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15", &calosubjetsSoftDropTagged15_, &b_calosubjetsSoftDropTagged15_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15.subjets_begin", calosubjetsSoftDropTagged15_subjets_begin, &b_calosubjetsSoftDropTagged15_subjets_begin);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15.subjets_end", calosubjetsSoftDropTagged15_subjets_end, &b_calosubjetsSoftDropTagged15_subjets_end);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15#0", &calosubjetsSoftDropTagged15#0_, &b_calosubjetsSoftDropTagged15#0_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15#0.index", calosubjetsSoftDropTagged15#0_index, &b_calosubjetsSoftDropTagged15#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15#0.collectionID", calosubjetsSoftDropTagged15#0_collectionID, &b_calosubjetsSoftDropTagged15#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15#1", &calosubjetsSoftDropTagged15#1_, &b_calosubjetsSoftDropTagged15#1_);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15#1.index", calosubjetsSoftDropTagged15#1_index, &b_calosubjetsSoftDropTagged15#1_index);
   fChain->SetBranchAddress("calosubjetsSoftDropTagged15#1.collectionID", calosubjetsSoftDropTagged15#1_collectionID, &b_calosubjetsSoftDropTagged15#1_collectionID);
   fChain->SetBranchAddress("calosubjetsTrimming15", &calosubjetsTrimming15_, &b_calosubjetsTrimming15_);
   fChain->SetBranchAddress("calosubjetsTrimming15.core.area", &calosubjetsTrimming15_core_area, &b_calosubjetsTrimming15_core_area);
   fChain->SetBranchAddress("calosubjetsTrimming15.core.bits", &calosubjetsTrimming15_core_bits, &b_calosubjetsTrimming15_core_bits);
   fChain->SetBranchAddress("calosubjetsTrimming15.core.p4.mass", &calosubjetsTrimming15_core_p4_mass, &b_calosubjetsTrimming15_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsTrimming15.core.p4.px", &calosubjetsTrimming15_core_p4_px, &b_calosubjetsTrimming15_core_p4_px);
   fChain->SetBranchAddress("calosubjetsTrimming15.core.p4.py", &calosubjetsTrimming15_core_p4_py, &b_calosubjetsTrimming15_core_p4_py);
   fChain->SetBranchAddress("calosubjetsTrimming15.core.p4.pz", &calosubjetsTrimming15_core_p4_pz, &b_calosubjetsTrimming15_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsTrimming15.particles_begin", &calosubjetsTrimming15_particles_begin, &b_calosubjetsTrimming15_particles_begin);
   fChain->SetBranchAddress("calosubjetsTrimming15.particles_end", &calosubjetsTrimming15_particles_end, &b_calosubjetsTrimming15_particles_end);
   fChain->SetBranchAddress("calosubjetsTrimming15#0", &calosubjetsTrimming15#0_, &b_calosubjetsTrimming15#0_);
   fChain->SetBranchAddress("calosubjetsTrimming15#0.index", &calosubjetsTrimming15#0_index, &b_calosubjetsTrimming15#0_index);
   fChain->SetBranchAddress("calosubjetsTrimming15#0.collectionID", &calosubjetsTrimming15#0_collectionID, &b_calosubjetsTrimming15#0_collectionID);
   fChain->SetBranchAddress("calosubjetsPruning15", &calosubjetsPruning15_, &b_calosubjetsPruning15_);
   fChain->SetBranchAddress("calosubjetsPruning15.core.area", &calosubjetsPruning15_core_area, &b_calosubjetsPruning15_core_area);
   fChain->SetBranchAddress("calosubjetsPruning15.core.bits", &calosubjetsPruning15_core_bits, &b_calosubjetsPruning15_core_bits);
   fChain->SetBranchAddress("calosubjetsPruning15.core.p4.mass", &calosubjetsPruning15_core_p4_mass, &b_calosubjetsPruning15_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsPruning15.core.p4.px", &calosubjetsPruning15_core_p4_px, &b_calosubjetsPruning15_core_p4_px);
   fChain->SetBranchAddress("calosubjetsPruning15.core.p4.py", &calosubjetsPruning15_core_p4_py, &b_calosubjetsPruning15_core_p4_py);
   fChain->SetBranchAddress("calosubjetsPruning15.core.p4.pz", &calosubjetsPruning15_core_p4_pz, &b_calosubjetsPruning15_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsPruning15.particles_begin", &calosubjetsPruning15_particles_begin, &b_calosubjetsPruning15_particles_begin);
   fChain->SetBranchAddress("calosubjetsPruning15.particles_end", &calosubjetsPruning15_particles_end, &b_calosubjetsPruning15_particles_end);
   fChain->SetBranchAddress("calosubjetsPruning15#0", &calosubjetsPruning15#0_, &b_calosubjetsPruning15#0_);
   fChain->SetBranchAddress("calosubjetsPruning15#0.index", &calosubjetsPruning15#0_index, &b_calosubjetsPruning15#0_index);
   fChain->SetBranchAddress("calosubjetsPruning15#0.collectionID", &calosubjetsPruning15#0_collectionID, &b_calosubjetsPruning15#0_collectionID);
   fChain->SetBranchAddress("calosubjetsSoftDrop15", &calosubjetsSoftDrop15_, &b_calosubjetsSoftDrop15_);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.core.area", calosubjetsSoftDrop15_core_area, &b_calosubjetsSoftDrop15_core_area);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.core.bits", calosubjetsSoftDrop15_core_bits, &b_calosubjetsSoftDrop15_core_bits);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.core.p4.mass", calosubjetsSoftDrop15_core_p4_mass, &b_calosubjetsSoftDrop15_core_p4_mass);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.core.p4.px", calosubjetsSoftDrop15_core_p4_px, &b_calosubjetsSoftDrop15_core_p4_px);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.core.p4.py", calosubjetsSoftDrop15_core_p4_py, &b_calosubjetsSoftDrop15_core_p4_py);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.core.p4.pz", calosubjetsSoftDrop15_core_p4_pz, &b_calosubjetsSoftDrop15_core_p4_pz);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.particles_begin", calosubjetsSoftDrop15_particles_begin, &b_calosubjetsSoftDrop15_particles_begin);
   fChain->SetBranchAddress("calosubjetsSoftDrop15.particles_end", calosubjetsSoftDrop15_particles_end, &b_calosubjetsSoftDrop15_particles_end);
   fChain->SetBranchAddress("calosubjetsSoftDrop15#0", &calosubjetsSoftDrop15#0_, &b_calosubjetsSoftDrop15#0_);
   fChain->SetBranchAddress("calosubjetsSoftDrop15#0.index", &calosubjetsSoftDrop15#0_index, &b_calosubjetsSoftDrop15#0_index);
   fChain->SetBranchAddress("calosubjetsSoftDrop15#0.collectionID", &calosubjetsSoftDrop15#0_collectionID, &b_calosubjetsSoftDrop15#0_collectionID);
   fChain->SetBranchAddress("pfjets02", &pfjets02_, &b_pfjets02_);
   fChain->SetBranchAddress("pfjets02.core.area", pfjets02_core_area, &b_pfjets02_core_area);
   fChain->SetBranchAddress("pfjets02.core.bits", pfjets02_core_bits, &b_pfjets02_core_bits);
   fChain->SetBranchAddress("pfjets02.core.p4.mass", pfjets02_core_p4_mass, &b_pfjets02_core_p4_mass);
   fChain->SetBranchAddress("pfjets02.core.p4.px", pfjets02_core_p4_px, &b_pfjets02_core_p4_px);
   fChain->SetBranchAddress("pfjets02.core.p4.py", pfjets02_core_p4_py, &b_pfjets02_core_p4_py);
   fChain->SetBranchAddress("pfjets02.core.p4.pz", pfjets02_core_p4_pz, &b_pfjets02_core_p4_pz);
   fChain->SetBranchAddress("pfjets02.particles_begin", pfjets02_particles_begin, &b_pfjets02_particles_begin);
   fChain->SetBranchAddress("pfjets02.particles_end", pfjets02_particles_end, &b_pfjets02_particles_end);
   fChain->SetBranchAddress("pfjets02#0", &pfjets02#0_, &b_pfjets02#0_);
   fChain->SetBranchAddress("pfjets02#0.index", pfjets02#0_index, &b_pfjets02#0_index);
   fChain->SetBranchAddress("pfjets02#0.collectionID", pfjets02#0_collectionID, &b_pfjets02#0_collectionID);
   fChain->SetBranchAddress("pfjetsFlavor02", &pfjetsFlavor02_, &b_pfjetsFlavor02_);
   fChain->SetBranchAddress("pfjetsFlavor02.tag", pfjetsFlavor02_tag, &b_pfjetsFlavor02_tag);
   fChain->SetBranchAddress("pfjetsFlavor02#0", &pfjetsFlavor02#0_, &b_pfjetsFlavor02#0_);
   fChain->SetBranchAddress("pfjetsFlavor02#0.index", pfjetsFlavor02#0_index, &b_pfjetsFlavor02#0_index);
   fChain->SetBranchAddress("pfjetsFlavor02#0.collectionID", pfjetsFlavor02#0_collectionID, &b_pfjetsFlavor02#0_collectionID);
   fChain->SetBranchAddress("pfbTags02", &pfbTags02_, &b_pfbTags02_);
   fChain->SetBranchAddress("pfbTags02.tag", pfbTags02_tag, &b_pfbTags02_tag);
   fChain->SetBranchAddress("pfbTags02#0", &pfbTags02#0_, &b_pfbTags02#0_);
   fChain->SetBranchAddress("pfbTags02#0.index", pfbTags02#0_index, &b_pfbTags02#0_index);
   fChain->SetBranchAddress("pfbTags02#0.collectionID", pfbTags02#0_collectionID, &b_pfbTags02#0_collectionID);
   fChain->SetBranchAddress("pfcTags02", &pfcTags02_, &b_pfcTags02_);
   fChain->SetBranchAddress("pfcTags02.tag", pfcTags02_tag, &b_pfcTags02_tag);
   fChain->SetBranchAddress("pfcTags02#0", &pfcTags02#0_, &b_pfcTags02#0_);
   fChain->SetBranchAddress("pfcTags02#0.index", pfcTags02#0_index, &b_pfcTags02#0_index);
   fChain->SetBranchAddress("pfcTags02#0.collectionID", pfcTags02#0_collectionID, &b_pfcTags02#0_collectionID);
   fChain->SetBranchAddress("pftauTags02", &pftauTags02_, &b_pftauTags02_);
   fChain->SetBranchAddress("pftauTags02.tag", pftauTags02_tag, &b_pftauTags02_tag);
   fChain->SetBranchAddress("pftauTags02#0", &pftauTags02#0_, &b_pftauTags02#0_);
   fChain->SetBranchAddress("pftauTags02#0.index", pftauTags02#0_index, &b_pftauTags02#0_index);
   fChain->SetBranchAddress("pftauTags02#0.collectionID", pftauTags02#0_collectionID, &b_pftauTags02#0_collectionID);
   fChain->SetBranchAddress("pfjetParts02", &pfjetParts02_, &b_pfjetParts02_);
   fChain->SetBranchAddress("pfjetParts02.core.bits", pfjetParts02_core_bits, &b_pfjetParts02_core_bits);
   fChain->SetBranchAddress("pfjetParts02.core.charge", pfjetParts02_core_charge, &b_pfjetParts02_core_charge);
   fChain->SetBranchAddress("pfjetParts02.core.p4.mass", pfjetParts02_core_p4_mass, &b_pfjetParts02_core_p4_mass);
   fChain->SetBranchAddress("pfjetParts02.core.p4.px", pfjetParts02_core_p4_px, &b_pfjetParts02_core_p4_px);
   fChain->SetBranchAddress("pfjetParts02.core.p4.py", pfjetParts02_core_p4_py, &b_pfjetParts02_core_p4_py);
   fChain->SetBranchAddress("pfjetParts02.core.p4.pz", pfjetParts02_core_p4_pz, &b_pfjetParts02_core_p4_pz);
   fChain->SetBranchAddress("pfjetParts02.core.pdgId", pfjetParts02_core_pdgId, &b_pfjetParts02_core_pdgId);
   fChain->SetBranchAddress("pfjetParts02.core.status", pfjetParts02_core_status, &b_pfjetParts02_core_status);
   fChain->SetBranchAddress("pfjetParts02.core.vertex.x", pfjetParts02_core_vertex_x, &b_pfjetParts02_core_vertex_x);
   fChain->SetBranchAddress("pfjetParts02.core.vertex.y", pfjetParts02_core_vertex_y, &b_pfjetParts02_core_vertex_y);
   fChain->SetBranchAddress("pfjetParts02.core.vertex.z", pfjetParts02_core_vertex_z, &b_pfjetParts02_core_vertex_z);
   fChain->SetBranchAddress("pfjetParts02.tracks_begin", pfjetParts02_tracks_begin, &b_pfjetParts02_tracks_begin);
   fChain->SetBranchAddress("pfjetParts02.tracks_end", pfjetParts02_tracks_end, &b_pfjetParts02_tracks_end);
   fChain->SetBranchAddress("pfjetParts02.clusters_begin", pfjetParts02_clusters_begin, &b_pfjetParts02_clusters_begin);
   fChain->SetBranchAddress("pfjetParts02.clusters_end", pfjetParts02_clusters_end, &b_pfjetParts02_clusters_end);
   fChain->SetBranchAddress("pfjetParts02#0", &pfjetParts02#0_, &b_pfjetParts02#0_);
   fChain->SetBranchAddress("pfjetParts02#0.index", &pfjetParts02#0_index, &b_pfjetParts02#0_index);
   fChain->SetBranchAddress("pfjetParts02#0.collectionID", &pfjetParts02#0_collectionID, &b_pfjetParts02#0_collectionID);
   fChain->SetBranchAddress("pfjetParts02#1", &pfjetParts02#1_, &b_pfjetParts02#1_);
   fChain->SetBranchAddress("pfjetParts02#1.index", &pfjetParts02#1_index, &b_pfjetParts02#1_index);
   fChain->SetBranchAddress("pfjetParts02#1.collectionID", &pfjetParts02#1_collectionID, &b_pfjetParts02#1_collectionID);
   fChain->SetBranchAddress("pfjetsOneSubJettiness02", &pfjetsOneSubJettiness02_, &b_pfjetsOneSubJettiness02_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness02.tag", pfjetsOneSubJettiness02_tag, &b_pfjetsOneSubJettiness02_tag);
   fChain->SetBranchAddress("pfjetsOneSubJettiness02#0", &pfjetsOneSubJettiness02#0_, &b_pfjetsOneSubJettiness02#0_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness02#0.index", pfjetsOneSubJettiness02#0_index, &b_pfjetsOneSubJettiness02#0_index);
   fChain->SetBranchAddress("pfjetsOneSubJettiness02#0.collectionID", pfjetsOneSubJettiness02#0_collectionID, &b_pfjetsOneSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness02", &pfjetsTwoSubJettiness02_, &b_pfjetsTwoSubJettiness02_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness02.tag", pfjetsTwoSubJettiness02_tag, &b_pfjetsTwoSubJettiness02_tag);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness02#0", &pfjetsTwoSubJettiness02#0_, &b_pfjetsTwoSubJettiness02#0_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness02#0.index", pfjetsTwoSubJettiness02#0_index, &b_pfjetsTwoSubJettiness02#0_index);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness02#0.collectionID", pfjetsTwoSubJettiness02#0_collectionID, &b_pfjetsTwoSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness02", &pfjetsThreeSubJettiness02_, &b_pfjetsThreeSubJettiness02_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness02.tag", pfjetsThreeSubJettiness02_tag, &b_pfjetsThreeSubJettiness02_tag);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness02#0", &pfjetsThreeSubJettiness02#0_, &b_pfjetsThreeSubJettiness02#0_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness02#0.index", pfjetsThreeSubJettiness02#0_index, &b_pfjetsThreeSubJettiness02#0_index);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness02#0.collectionID", pfjetsThreeSubJettiness02#0_collectionID, &b_pfjetsThreeSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02", &pfsubjetsTrimmingTagged02_, &b_pfsubjetsTrimmingTagged02_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02.subjets_begin", pfsubjetsTrimmingTagged02_subjets_begin, &b_pfsubjetsTrimmingTagged02_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02.subjets_end", pfsubjetsTrimmingTagged02_subjets_end, &b_pfsubjetsTrimmingTagged02_subjets_end);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02#0", &pfsubjetsTrimmingTagged02#0_, &b_pfsubjetsTrimmingTagged02#0_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02#0.index", &pfsubjetsTrimmingTagged02#0_index, &b_pfsubjetsTrimmingTagged02#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02#0.collectionID", &pfsubjetsTrimmingTagged02#0_collectionID, &b_pfsubjetsTrimmingTagged02#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02#1", &pfsubjetsTrimmingTagged02#1_, &b_pfsubjetsTrimmingTagged02#1_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02#1.index", pfsubjetsTrimmingTagged02#1_index, &b_pfsubjetsTrimmingTagged02#1_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged02#1.collectionID", pfsubjetsTrimmingTagged02#1_collectionID, &b_pfsubjetsTrimmingTagged02#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02", &pfsubjetsPruningTagged02_, &b_pfsubjetsPruningTagged02_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02.subjets_begin", pfsubjetsPruningTagged02_subjets_begin, &b_pfsubjetsPruningTagged02_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02.subjets_end", pfsubjetsPruningTagged02_subjets_end, &b_pfsubjetsPruningTagged02_subjets_end);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02#0", &pfsubjetsPruningTagged02#0_, &b_pfsubjetsPruningTagged02#0_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02#0.index", &pfsubjetsPruningTagged02#0_index, &b_pfsubjetsPruningTagged02#0_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02#0.collectionID", &pfsubjetsPruningTagged02#0_collectionID, &b_pfsubjetsPruningTagged02#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02#1", &pfsubjetsPruningTagged02#1_, &b_pfsubjetsPruningTagged02#1_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02#1.index", pfsubjetsPruningTagged02#1_index, &b_pfsubjetsPruningTagged02#1_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged02#1.collectionID", pfsubjetsPruningTagged02#1_collectionID, &b_pfsubjetsPruningTagged02#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02", &pfsubjetsSoftDropTagged02_, &b_pfsubjetsSoftDropTagged02_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02.subjets_begin", pfsubjetsSoftDropTagged02_subjets_begin, &b_pfsubjetsSoftDropTagged02_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02.subjets_end", pfsubjetsSoftDropTagged02_subjets_end, &b_pfsubjetsSoftDropTagged02_subjets_end);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02#0", &pfsubjetsSoftDropTagged02#0_, &b_pfsubjetsSoftDropTagged02#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02#0.index", pfsubjetsSoftDropTagged02#0_index, &b_pfsubjetsSoftDropTagged02#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02#0.collectionID", pfsubjetsSoftDropTagged02#0_collectionID, &b_pfsubjetsSoftDropTagged02#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02#1", &pfsubjetsSoftDropTagged02#1_, &b_pfsubjetsSoftDropTagged02#1_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02#1.index", pfsubjetsSoftDropTagged02#1_index, &b_pfsubjetsSoftDropTagged02#1_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged02#1.collectionID", pfsubjetsSoftDropTagged02#1_collectionID, &b_pfsubjetsSoftDropTagged02#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimming02", &pfsubjetsTrimming02_, &b_pfsubjetsTrimming02_);
   fChain->SetBranchAddress("pfsubjetsTrimming02.core.area", &pfsubjetsTrimming02_core_area, &b_pfsubjetsTrimming02_core_area);
   fChain->SetBranchAddress("pfsubjetsTrimming02.core.bits", &pfsubjetsTrimming02_core_bits, &b_pfsubjetsTrimming02_core_bits);
   fChain->SetBranchAddress("pfsubjetsTrimming02.core.p4.mass", &pfsubjetsTrimming02_core_p4_mass, &b_pfsubjetsTrimming02_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsTrimming02.core.p4.px", &pfsubjetsTrimming02_core_p4_px, &b_pfsubjetsTrimming02_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsTrimming02.core.p4.py", &pfsubjetsTrimming02_core_p4_py, &b_pfsubjetsTrimming02_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsTrimming02.core.p4.pz", &pfsubjetsTrimming02_core_p4_pz, &b_pfsubjetsTrimming02_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsTrimming02.particles_begin", &pfsubjetsTrimming02_particles_begin, &b_pfsubjetsTrimming02_particles_begin);
   fChain->SetBranchAddress("pfsubjetsTrimming02.particles_end", &pfsubjetsTrimming02_particles_end, &b_pfsubjetsTrimming02_particles_end);
   fChain->SetBranchAddress("pfsubjetsTrimming02#0", &pfsubjetsTrimming02#0_, &b_pfsubjetsTrimming02#0_);
   fChain->SetBranchAddress("pfsubjetsTrimming02#0.index", &pfsubjetsTrimming02#0_index, &b_pfsubjetsTrimming02#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimming02#0.collectionID", &pfsubjetsTrimming02#0_collectionID, &b_pfsubjetsTrimming02#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruning02", &pfsubjetsPruning02_, &b_pfsubjetsPruning02_);
   fChain->SetBranchAddress("pfsubjetsPruning02.core.area", &pfsubjetsPruning02_core_area, &b_pfsubjetsPruning02_core_area);
   fChain->SetBranchAddress("pfsubjetsPruning02.core.bits", &pfsubjetsPruning02_core_bits, &b_pfsubjetsPruning02_core_bits);
   fChain->SetBranchAddress("pfsubjetsPruning02.core.p4.mass", &pfsubjetsPruning02_core_p4_mass, &b_pfsubjetsPruning02_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsPruning02.core.p4.px", &pfsubjetsPruning02_core_p4_px, &b_pfsubjetsPruning02_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsPruning02.core.p4.py", &pfsubjetsPruning02_core_p4_py, &b_pfsubjetsPruning02_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsPruning02.core.p4.pz", &pfsubjetsPruning02_core_p4_pz, &b_pfsubjetsPruning02_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsPruning02.particles_begin", &pfsubjetsPruning02_particles_begin, &b_pfsubjetsPruning02_particles_begin);
   fChain->SetBranchAddress("pfsubjetsPruning02.particles_end", &pfsubjetsPruning02_particles_end, &b_pfsubjetsPruning02_particles_end);
   fChain->SetBranchAddress("pfsubjetsPruning02#0", &pfsubjetsPruning02#0_, &b_pfsubjetsPruning02#0_);
   fChain->SetBranchAddress("pfsubjetsPruning02#0.index", &pfsubjetsPruning02#0_index, &b_pfsubjetsPruning02#0_index);
   fChain->SetBranchAddress("pfsubjetsPruning02#0.collectionID", &pfsubjetsPruning02#0_collectionID, &b_pfsubjetsPruning02#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02", &pfsubjetsSoftDrop02_, &b_pfsubjetsSoftDrop02_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.core.area", pfsubjetsSoftDrop02_core_area, &b_pfsubjetsSoftDrop02_core_area);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.core.bits", pfsubjetsSoftDrop02_core_bits, &b_pfsubjetsSoftDrop02_core_bits);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.core.p4.mass", pfsubjetsSoftDrop02_core_p4_mass, &b_pfsubjetsSoftDrop02_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.core.p4.px", pfsubjetsSoftDrop02_core_p4_px, &b_pfsubjetsSoftDrop02_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.core.p4.py", pfsubjetsSoftDrop02_core_p4_py, &b_pfsubjetsSoftDrop02_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.core.p4.pz", pfsubjetsSoftDrop02_core_p4_pz, &b_pfsubjetsSoftDrop02_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.particles_begin", pfsubjetsSoftDrop02_particles_begin, &b_pfsubjetsSoftDrop02_particles_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02.particles_end", pfsubjetsSoftDrop02_particles_end, &b_pfsubjetsSoftDrop02_particles_end);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02#0", &pfsubjetsSoftDrop02#0_, &b_pfsubjetsSoftDrop02#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02#0.index", &pfsubjetsSoftDrop02#0_index, &b_pfsubjetsSoftDrop02#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDrop02#0.collectionID", &pfsubjetsSoftDrop02#0_collectionID, &b_pfsubjetsSoftDrop02#0_collectionID);
   fChain->SetBranchAddress("pfjets04", &pfjets04_, &b_pfjets04_);
   fChain->SetBranchAddress("pfjets04.core.area", pfjets04_core_area, &b_pfjets04_core_area);
   fChain->SetBranchAddress("pfjets04.core.bits", pfjets04_core_bits, &b_pfjets04_core_bits);
   fChain->SetBranchAddress("pfjets04.core.p4.mass", pfjets04_core_p4_mass, &b_pfjets04_core_p4_mass);
   fChain->SetBranchAddress("pfjets04.core.p4.px", pfjets04_core_p4_px, &b_pfjets04_core_p4_px);
   fChain->SetBranchAddress("pfjets04.core.p4.py", pfjets04_core_p4_py, &b_pfjets04_core_p4_py);
   fChain->SetBranchAddress("pfjets04.core.p4.pz", pfjets04_core_p4_pz, &b_pfjets04_core_p4_pz);
   fChain->SetBranchAddress("pfjets04.particles_begin", pfjets04_particles_begin, &b_pfjets04_particles_begin);
   fChain->SetBranchAddress("pfjets04.particles_end", pfjets04_particles_end, &b_pfjets04_particles_end);
   fChain->SetBranchAddress("pfjets04#0", &pfjets04#0_, &b_pfjets04#0_);
   fChain->SetBranchAddress("pfjets04#0.index", pfjets04#0_index, &b_pfjets04#0_index);
   fChain->SetBranchAddress("pfjets04#0.collectionID", pfjets04#0_collectionID, &b_pfjets04#0_collectionID);
   fChain->SetBranchAddress("pfjetsFlavor04", &pfjetsFlavor04_, &b_pfjetsFlavor04_);
   fChain->SetBranchAddress("pfjetsFlavor04.tag", pfjetsFlavor04_tag, &b_pfjetsFlavor04_tag);
   fChain->SetBranchAddress("pfjetsFlavor04#0", &pfjetsFlavor04#0_, &b_pfjetsFlavor04#0_);
   fChain->SetBranchAddress("pfjetsFlavor04#0.index", pfjetsFlavor04#0_index, &b_pfjetsFlavor04#0_index);
   fChain->SetBranchAddress("pfjetsFlavor04#0.collectionID", pfjetsFlavor04#0_collectionID, &b_pfjetsFlavor04#0_collectionID);
   fChain->SetBranchAddress("pfbTags04", &pfbTags04_, &b_pfbTags04_);
   fChain->SetBranchAddress("pfbTags04.tag", pfbTags04_tag, &b_pfbTags04_tag);
   fChain->SetBranchAddress("pfbTags04#0", &pfbTags04#0_, &b_pfbTags04#0_);
   fChain->SetBranchAddress("pfbTags04#0.index", pfbTags04#0_index, &b_pfbTags04#0_index);
   fChain->SetBranchAddress("pfbTags04#0.collectionID", pfbTags04#0_collectionID, &b_pfbTags04#0_collectionID);
   fChain->SetBranchAddress("pfcTags04", &pfcTags04_, &b_pfcTags04_);
   fChain->SetBranchAddress("pfcTags04.tag", pfcTags04_tag, &b_pfcTags04_tag);
   fChain->SetBranchAddress("pfcTags04#0", &pfcTags04#0_, &b_pfcTags04#0_);
   fChain->SetBranchAddress("pfcTags04#0.index", pfcTags04#0_index, &b_pfcTags04#0_index);
   fChain->SetBranchAddress("pfcTags04#0.collectionID", pfcTags04#0_collectionID, &b_pfcTags04#0_collectionID);
   fChain->SetBranchAddress("pftauTags04", &pftauTags04_, &b_pftauTags04_);
   fChain->SetBranchAddress("pftauTags04.tag", pftauTags04_tag, &b_pftauTags04_tag);
   fChain->SetBranchAddress("pftauTags04#0", &pftauTags04#0_, &b_pftauTags04#0_);
   fChain->SetBranchAddress("pftauTags04#0.index", pftauTags04#0_index, &b_pftauTags04#0_index);
   fChain->SetBranchAddress("pftauTags04#0.collectionID", pftauTags04#0_collectionID, &b_pftauTags04#0_collectionID);
   fChain->SetBranchAddress("pfjetParts04", &pfjetParts04_, &b_pfjetParts04_);
   fChain->SetBranchAddress("pfjetParts04.core.bits", pfjetParts04_core_bits, &b_pfjetParts04_core_bits);
   fChain->SetBranchAddress("pfjetParts04.core.charge", pfjetParts04_core_charge, &b_pfjetParts04_core_charge);
   fChain->SetBranchAddress("pfjetParts04.core.p4.mass", pfjetParts04_core_p4_mass, &b_pfjetParts04_core_p4_mass);
   fChain->SetBranchAddress("pfjetParts04.core.p4.px", pfjetParts04_core_p4_px, &b_pfjetParts04_core_p4_px);
   fChain->SetBranchAddress("pfjetParts04.core.p4.py", pfjetParts04_core_p4_py, &b_pfjetParts04_core_p4_py);
   fChain->SetBranchAddress("pfjetParts04.core.p4.pz", pfjetParts04_core_p4_pz, &b_pfjetParts04_core_p4_pz);
   fChain->SetBranchAddress("pfjetParts04.core.pdgId", pfjetParts04_core_pdgId, &b_pfjetParts04_core_pdgId);
   fChain->SetBranchAddress("pfjetParts04.core.status", pfjetParts04_core_status, &b_pfjetParts04_core_status);
   fChain->SetBranchAddress("pfjetParts04.core.vertex.x", pfjetParts04_core_vertex_x, &b_pfjetParts04_core_vertex_x);
   fChain->SetBranchAddress("pfjetParts04.core.vertex.y", pfjetParts04_core_vertex_y, &b_pfjetParts04_core_vertex_y);
   fChain->SetBranchAddress("pfjetParts04.core.vertex.z", pfjetParts04_core_vertex_z, &b_pfjetParts04_core_vertex_z);
   fChain->SetBranchAddress("pfjetParts04.tracks_begin", pfjetParts04_tracks_begin, &b_pfjetParts04_tracks_begin);
   fChain->SetBranchAddress("pfjetParts04.tracks_end", pfjetParts04_tracks_end, &b_pfjetParts04_tracks_end);
   fChain->SetBranchAddress("pfjetParts04.clusters_begin", pfjetParts04_clusters_begin, &b_pfjetParts04_clusters_begin);
   fChain->SetBranchAddress("pfjetParts04.clusters_end", pfjetParts04_clusters_end, &b_pfjetParts04_clusters_end);
   fChain->SetBranchAddress("pfjetParts04#0", &pfjetParts04#0_, &b_pfjetParts04#0_);
   fChain->SetBranchAddress("pfjetParts04#0.index", &pfjetParts04#0_index, &b_pfjetParts04#0_index);
   fChain->SetBranchAddress("pfjetParts04#0.collectionID", &pfjetParts04#0_collectionID, &b_pfjetParts04#0_collectionID);
   fChain->SetBranchAddress("pfjetParts04#1", &pfjetParts04#1_, &b_pfjetParts04#1_);
   fChain->SetBranchAddress("pfjetParts04#1.index", &pfjetParts04#1_index, &b_pfjetParts04#1_index);
   fChain->SetBranchAddress("pfjetParts04#1.collectionID", &pfjetParts04#1_collectionID, &b_pfjetParts04#1_collectionID);
   fChain->SetBranchAddress("pfjetsOneSubJettiness04", &pfjetsOneSubJettiness04_, &b_pfjetsOneSubJettiness04_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness04.tag", pfjetsOneSubJettiness04_tag, &b_pfjetsOneSubJettiness04_tag);
   fChain->SetBranchAddress("pfjetsOneSubJettiness04#0", &pfjetsOneSubJettiness04#0_, &b_pfjetsOneSubJettiness04#0_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness04#0.index", pfjetsOneSubJettiness04#0_index, &b_pfjetsOneSubJettiness04#0_index);
   fChain->SetBranchAddress("pfjetsOneSubJettiness04#0.collectionID", pfjetsOneSubJettiness04#0_collectionID, &b_pfjetsOneSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness04", &pfjetsTwoSubJettiness04_, &b_pfjetsTwoSubJettiness04_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness04.tag", pfjetsTwoSubJettiness04_tag, &b_pfjetsTwoSubJettiness04_tag);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness04#0", &pfjetsTwoSubJettiness04#0_, &b_pfjetsTwoSubJettiness04#0_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness04#0.index", pfjetsTwoSubJettiness04#0_index, &b_pfjetsTwoSubJettiness04#0_index);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness04#0.collectionID", pfjetsTwoSubJettiness04#0_collectionID, &b_pfjetsTwoSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness04", &pfjetsThreeSubJettiness04_, &b_pfjetsThreeSubJettiness04_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness04.tag", pfjetsThreeSubJettiness04_tag, &b_pfjetsThreeSubJettiness04_tag);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness04#0", &pfjetsThreeSubJettiness04#0_, &b_pfjetsThreeSubJettiness04#0_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness04#0.index", pfjetsThreeSubJettiness04#0_index, &b_pfjetsThreeSubJettiness04#0_index);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness04#0.collectionID", pfjetsThreeSubJettiness04#0_collectionID, &b_pfjetsThreeSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04", &pfsubjetsTrimmingTagged04_, &b_pfsubjetsTrimmingTagged04_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04.subjets_begin", pfsubjetsTrimmingTagged04_subjets_begin, &b_pfsubjetsTrimmingTagged04_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04.subjets_end", pfsubjetsTrimmingTagged04_subjets_end, &b_pfsubjetsTrimmingTagged04_subjets_end);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04#0", &pfsubjetsTrimmingTagged04#0_, &b_pfsubjetsTrimmingTagged04#0_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04#0.index", &pfsubjetsTrimmingTagged04#0_index, &b_pfsubjetsTrimmingTagged04#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04#0.collectionID", &pfsubjetsTrimmingTagged04#0_collectionID, &b_pfsubjetsTrimmingTagged04#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04#1", &pfsubjetsTrimmingTagged04#1_, &b_pfsubjetsTrimmingTagged04#1_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04#1.index", pfsubjetsTrimmingTagged04#1_index, &b_pfsubjetsTrimmingTagged04#1_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged04#1.collectionID", pfsubjetsTrimmingTagged04#1_collectionID, &b_pfsubjetsTrimmingTagged04#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04", &pfsubjetsPruningTagged04_, &b_pfsubjetsPruningTagged04_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04.subjets_begin", pfsubjetsPruningTagged04_subjets_begin, &b_pfsubjetsPruningTagged04_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04.subjets_end", pfsubjetsPruningTagged04_subjets_end, &b_pfsubjetsPruningTagged04_subjets_end);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04#0", &pfsubjetsPruningTagged04#0_, &b_pfsubjetsPruningTagged04#0_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04#0.index", &pfsubjetsPruningTagged04#0_index, &b_pfsubjetsPruningTagged04#0_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04#0.collectionID", &pfsubjetsPruningTagged04#0_collectionID, &b_pfsubjetsPruningTagged04#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04#1", &pfsubjetsPruningTagged04#1_, &b_pfsubjetsPruningTagged04#1_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04#1.index", pfsubjetsPruningTagged04#1_index, &b_pfsubjetsPruningTagged04#1_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged04#1.collectionID", pfsubjetsPruningTagged04#1_collectionID, &b_pfsubjetsPruningTagged04#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04", &pfsubjetsSoftDropTagged04_, &b_pfsubjetsSoftDropTagged04_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04.subjets_begin", pfsubjetsSoftDropTagged04_subjets_begin, &b_pfsubjetsSoftDropTagged04_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04.subjets_end", pfsubjetsSoftDropTagged04_subjets_end, &b_pfsubjetsSoftDropTagged04_subjets_end);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04#0", &pfsubjetsSoftDropTagged04#0_, &b_pfsubjetsSoftDropTagged04#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04#0.index", pfsubjetsSoftDropTagged04#0_index, &b_pfsubjetsSoftDropTagged04#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04#0.collectionID", pfsubjetsSoftDropTagged04#0_collectionID, &b_pfsubjetsSoftDropTagged04#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04#1", &pfsubjetsSoftDropTagged04#1_, &b_pfsubjetsSoftDropTagged04#1_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04#1.index", pfsubjetsSoftDropTagged04#1_index, &b_pfsubjetsSoftDropTagged04#1_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged04#1.collectionID", pfsubjetsSoftDropTagged04#1_collectionID, &b_pfsubjetsSoftDropTagged04#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimming04", &pfsubjetsTrimming04_, &b_pfsubjetsTrimming04_);
   fChain->SetBranchAddress("pfsubjetsTrimming04.core.area", &pfsubjetsTrimming04_core_area, &b_pfsubjetsTrimming04_core_area);
   fChain->SetBranchAddress("pfsubjetsTrimming04.core.bits", &pfsubjetsTrimming04_core_bits, &b_pfsubjetsTrimming04_core_bits);
   fChain->SetBranchAddress("pfsubjetsTrimming04.core.p4.mass", &pfsubjetsTrimming04_core_p4_mass, &b_pfsubjetsTrimming04_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsTrimming04.core.p4.px", &pfsubjetsTrimming04_core_p4_px, &b_pfsubjetsTrimming04_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsTrimming04.core.p4.py", &pfsubjetsTrimming04_core_p4_py, &b_pfsubjetsTrimming04_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsTrimming04.core.p4.pz", &pfsubjetsTrimming04_core_p4_pz, &b_pfsubjetsTrimming04_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsTrimming04.particles_begin", &pfsubjetsTrimming04_particles_begin, &b_pfsubjetsTrimming04_particles_begin);
   fChain->SetBranchAddress("pfsubjetsTrimming04.particles_end", &pfsubjetsTrimming04_particles_end, &b_pfsubjetsTrimming04_particles_end);
   fChain->SetBranchAddress("pfsubjetsTrimming04#0", &pfsubjetsTrimming04#0_, &b_pfsubjetsTrimming04#0_);
   fChain->SetBranchAddress("pfsubjetsTrimming04#0.index", &pfsubjetsTrimming04#0_index, &b_pfsubjetsTrimming04#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimming04#0.collectionID", &pfsubjetsTrimming04#0_collectionID, &b_pfsubjetsTrimming04#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruning04", &pfsubjetsPruning04_, &b_pfsubjetsPruning04_);
   fChain->SetBranchAddress("pfsubjetsPruning04.core.area", &pfsubjetsPruning04_core_area, &b_pfsubjetsPruning04_core_area);
   fChain->SetBranchAddress("pfsubjetsPruning04.core.bits", &pfsubjetsPruning04_core_bits, &b_pfsubjetsPruning04_core_bits);
   fChain->SetBranchAddress("pfsubjetsPruning04.core.p4.mass", &pfsubjetsPruning04_core_p4_mass, &b_pfsubjetsPruning04_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsPruning04.core.p4.px", &pfsubjetsPruning04_core_p4_px, &b_pfsubjetsPruning04_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsPruning04.core.p4.py", &pfsubjetsPruning04_core_p4_py, &b_pfsubjetsPruning04_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsPruning04.core.p4.pz", &pfsubjetsPruning04_core_p4_pz, &b_pfsubjetsPruning04_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsPruning04.particles_begin", &pfsubjetsPruning04_particles_begin, &b_pfsubjetsPruning04_particles_begin);
   fChain->SetBranchAddress("pfsubjetsPruning04.particles_end", &pfsubjetsPruning04_particles_end, &b_pfsubjetsPruning04_particles_end);
   fChain->SetBranchAddress("pfsubjetsPruning04#0", &pfsubjetsPruning04#0_, &b_pfsubjetsPruning04#0_);
   fChain->SetBranchAddress("pfsubjetsPruning04#0.index", &pfsubjetsPruning04#0_index, &b_pfsubjetsPruning04#0_index);
   fChain->SetBranchAddress("pfsubjetsPruning04#0.collectionID", &pfsubjetsPruning04#0_collectionID, &b_pfsubjetsPruning04#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04", &pfsubjetsSoftDrop04_, &b_pfsubjetsSoftDrop04_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.core.area", pfsubjetsSoftDrop04_core_area, &b_pfsubjetsSoftDrop04_core_area);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.core.bits", pfsubjetsSoftDrop04_core_bits, &b_pfsubjetsSoftDrop04_core_bits);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.core.p4.mass", pfsubjetsSoftDrop04_core_p4_mass, &b_pfsubjetsSoftDrop04_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.core.p4.px", pfsubjetsSoftDrop04_core_p4_px, &b_pfsubjetsSoftDrop04_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.core.p4.py", pfsubjetsSoftDrop04_core_p4_py, &b_pfsubjetsSoftDrop04_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.core.p4.pz", pfsubjetsSoftDrop04_core_p4_pz, &b_pfsubjetsSoftDrop04_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.particles_begin", pfsubjetsSoftDrop04_particles_begin, &b_pfsubjetsSoftDrop04_particles_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04.particles_end", pfsubjetsSoftDrop04_particles_end, &b_pfsubjetsSoftDrop04_particles_end);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04#0", &pfsubjetsSoftDrop04#0_, &b_pfsubjetsSoftDrop04#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04#0.index", &pfsubjetsSoftDrop04#0_index, &b_pfsubjetsSoftDrop04#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDrop04#0.collectionID", &pfsubjetsSoftDrop04#0_collectionID, &b_pfsubjetsSoftDrop04#0_collectionID);
   fChain->SetBranchAddress("pfjets08", &pfjets08_, &b_pfjets08_);
   fChain->SetBranchAddress("pfjets08.core.area", pfjets08_core_area, &b_pfjets08_core_area);
   fChain->SetBranchAddress("pfjets08.core.bits", pfjets08_core_bits, &b_pfjets08_core_bits);
   fChain->SetBranchAddress("pfjets08.core.p4.mass", pfjets08_core_p4_mass, &b_pfjets08_core_p4_mass);
   fChain->SetBranchAddress("pfjets08.core.p4.px", pfjets08_core_p4_px, &b_pfjets08_core_p4_px);
   fChain->SetBranchAddress("pfjets08.core.p4.py", pfjets08_core_p4_py, &b_pfjets08_core_p4_py);
   fChain->SetBranchAddress("pfjets08.core.p4.pz", pfjets08_core_p4_pz, &b_pfjets08_core_p4_pz);
   fChain->SetBranchAddress("pfjets08.particles_begin", pfjets08_particles_begin, &b_pfjets08_particles_begin);
   fChain->SetBranchAddress("pfjets08.particles_end", pfjets08_particles_end, &b_pfjets08_particles_end);
   fChain->SetBranchAddress("pfjets08#0", &pfjets08#0_, &b_pfjets08#0_);
   fChain->SetBranchAddress("pfjets08#0.index", pfjets08#0_index, &b_pfjets08#0_index);
   fChain->SetBranchAddress("pfjets08#0.collectionID", pfjets08#0_collectionID, &b_pfjets08#0_collectionID);
   fChain->SetBranchAddress("pfjetsFlavor08", &pfjetsFlavor08_, &b_pfjetsFlavor08_);
   fChain->SetBranchAddress("pfjetsFlavor08.tag", pfjetsFlavor08_tag, &b_pfjetsFlavor08_tag);
   fChain->SetBranchAddress("pfjetsFlavor08#0", &pfjetsFlavor08#0_, &b_pfjetsFlavor08#0_);
   fChain->SetBranchAddress("pfjetsFlavor08#0.index", pfjetsFlavor08#0_index, &b_pfjetsFlavor08#0_index);
   fChain->SetBranchAddress("pfjetsFlavor08#0.collectionID", pfjetsFlavor08#0_collectionID, &b_pfjetsFlavor08#0_collectionID);
   fChain->SetBranchAddress("pfbTags08", &pfbTags08_, &b_pfbTags08_);
   fChain->SetBranchAddress("pfbTags08.tag", pfbTags08_tag, &b_pfbTags08_tag);
   fChain->SetBranchAddress("pfbTags08#0", &pfbTags08#0_, &b_pfbTags08#0_);
   fChain->SetBranchAddress("pfbTags08#0.index", pfbTags08#0_index, &b_pfbTags08#0_index);
   fChain->SetBranchAddress("pfbTags08#0.collectionID", pfbTags08#0_collectionID, &b_pfbTags08#0_collectionID);
   fChain->SetBranchAddress("pfcTags08", &pfcTags08_, &b_pfcTags08_);
   fChain->SetBranchAddress("pfcTags08.tag", pfcTags08_tag, &b_pfcTags08_tag);
   fChain->SetBranchAddress("pfcTags08#0", &pfcTags08#0_, &b_pfcTags08#0_);
   fChain->SetBranchAddress("pfcTags08#0.index", pfcTags08#0_index, &b_pfcTags08#0_index);
   fChain->SetBranchAddress("pfcTags08#0.collectionID", pfcTags08#0_collectionID, &b_pfcTags08#0_collectionID);
   fChain->SetBranchAddress("pftauTags08", &pftauTags08_, &b_pftauTags08_);
   fChain->SetBranchAddress("pftauTags08.tag", pftauTags08_tag, &b_pftauTags08_tag);
   fChain->SetBranchAddress("pftauTags08#0", &pftauTags08#0_, &b_pftauTags08#0_);
   fChain->SetBranchAddress("pftauTags08#0.index", pftauTags08#0_index, &b_pftauTags08#0_index);
   fChain->SetBranchAddress("pftauTags08#0.collectionID", pftauTags08#0_collectionID, &b_pftauTags08#0_collectionID);
   fChain->SetBranchAddress("pfjetParts08", &pfjetParts08_, &b_pfjetParts08_);
   fChain->SetBranchAddress("pfjetParts08.core.bits", pfjetParts08_core_bits, &b_pfjetParts08_core_bits);
   fChain->SetBranchAddress("pfjetParts08.core.charge", pfjetParts08_core_charge, &b_pfjetParts08_core_charge);
   fChain->SetBranchAddress("pfjetParts08.core.p4.mass", pfjetParts08_core_p4_mass, &b_pfjetParts08_core_p4_mass);
   fChain->SetBranchAddress("pfjetParts08.core.p4.px", pfjetParts08_core_p4_px, &b_pfjetParts08_core_p4_px);
   fChain->SetBranchAddress("pfjetParts08.core.p4.py", pfjetParts08_core_p4_py, &b_pfjetParts08_core_p4_py);
   fChain->SetBranchAddress("pfjetParts08.core.p4.pz", pfjetParts08_core_p4_pz, &b_pfjetParts08_core_p4_pz);
   fChain->SetBranchAddress("pfjetParts08.core.pdgId", pfjetParts08_core_pdgId, &b_pfjetParts08_core_pdgId);
   fChain->SetBranchAddress("pfjetParts08.core.status", pfjetParts08_core_status, &b_pfjetParts08_core_status);
   fChain->SetBranchAddress("pfjetParts08.core.vertex.x", pfjetParts08_core_vertex_x, &b_pfjetParts08_core_vertex_x);
   fChain->SetBranchAddress("pfjetParts08.core.vertex.y", pfjetParts08_core_vertex_y, &b_pfjetParts08_core_vertex_y);
   fChain->SetBranchAddress("pfjetParts08.core.vertex.z", pfjetParts08_core_vertex_z, &b_pfjetParts08_core_vertex_z);
   fChain->SetBranchAddress("pfjetParts08.tracks_begin", pfjetParts08_tracks_begin, &b_pfjetParts08_tracks_begin);
   fChain->SetBranchAddress("pfjetParts08.tracks_end", pfjetParts08_tracks_end, &b_pfjetParts08_tracks_end);
   fChain->SetBranchAddress("pfjetParts08.clusters_begin", pfjetParts08_clusters_begin, &b_pfjetParts08_clusters_begin);
   fChain->SetBranchAddress("pfjetParts08.clusters_end", pfjetParts08_clusters_end, &b_pfjetParts08_clusters_end);
   fChain->SetBranchAddress("pfjetParts08#0", &pfjetParts08#0_, &b_pfjetParts08#0_);
   fChain->SetBranchAddress("pfjetParts08#0.index", &pfjetParts08#0_index, &b_pfjetParts08#0_index);
   fChain->SetBranchAddress("pfjetParts08#0.collectionID", &pfjetParts08#0_collectionID, &b_pfjetParts08#0_collectionID);
   fChain->SetBranchAddress("pfjetParts08#1", &pfjetParts08#1_, &b_pfjetParts08#1_);
   fChain->SetBranchAddress("pfjetParts08#1.index", &pfjetParts08#1_index, &b_pfjetParts08#1_index);
   fChain->SetBranchAddress("pfjetParts08#1.collectionID", &pfjetParts08#1_collectionID, &b_pfjetParts08#1_collectionID);
   fChain->SetBranchAddress("pfjetsOneSubJettiness08", &pfjetsOneSubJettiness08_, &b_pfjetsOneSubJettiness08_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness08.tag", pfjetsOneSubJettiness08_tag, &b_pfjetsOneSubJettiness08_tag);
   fChain->SetBranchAddress("pfjetsOneSubJettiness08#0", &pfjetsOneSubJettiness08#0_, &b_pfjetsOneSubJettiness08#0_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness08#0.index", pfjetsOneSubJettiness08#0_index, &b_pfjetsOneSubJettiness08#0_index);
   fChain->SetBranchAddress("pfjetsOneSubJettiness08#0.collectionID", pfjetsOneSubJettiness08#0_collectionID, &b_pfjetsOneSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness08", &pfjetsTwoSubJettiness08_, &b_pfjetsTwoSubJettiness08_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness08.tag", pfjetsTwoSubJettiness08_tag, &b_pfjetsTwoSubJettiness08_tag);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness08#0", &pfjetsTwoSubJettiness08#0_, &b_pfjetsTwoSubJettiness08#0_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness08#0.index", pfjetsTwoSubJettiness08#0_index, &b_pfjetsTwoSubJettiness08#0_index);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness08#0.collectionID", pfjetsTwoSubJettiness08#0_collectionID, &b_pfjetsTwoSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness08", &pfjetsThreeSubJettiness08_, &b_pfjetsThreeSubJettiness08_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness08.tag", pfjetsThreeSubJettiness08_tag, &b_pfjetsThreeSubJettiness08_tag);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness08#0", &pfjetsThreeSubJettiness08#0_, &b_pfjetsThreeSubJettiness08#0_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness08#0.index", pfjetsThreeSubJettiness08#0_index, &b_pfjetsThreeSubJettiness08#0_index);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness08#0.collectionID", pfjetsThreeSubJettiness08#0_collectionID, &b_pfjetsThreeSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08", &pfsubjetsTrimmingTagged08_, &b_pfsubjetsTrimmingTagged08_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08.subjets_begin", pfsubjetsTrimmingTagged08_subjets_begin, &b_pfsubjetsTrimmingTagged08_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08.subjets_end", pfsubjetsTrimmingTagged08_subjets_end, &b_pfsubjetsTrimmingTagged08_subjets_end);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08#0", &pfsubjetsTrimmingTagged08#0_, &b_pfsubjetsTrimmingTagged08#0_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08#0.index", &pfsubjetsTrimmingTagged08#0_index, &b_pfsubjetsTrimmingTagged08#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08#0.collectionID", &pfsubjetsTrimmingTagged08#0_collectionID, &b_pfsubjetsTrimmingTagged08#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08#1", &pfsubjetsTrimmingTagged08#1_, &b_pfsubjetsTrimmingTagged08#1_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08#1.index", pfsubjetsTrimmingTagged08#1_index, &b_pfsubjetsTrimmingTagged08#1_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged08#1.collectionID", pfsubjetsTrimmingTagged08#1_collectionID, &b_pfsubjetsTrimmingTagged08#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08", &pfsubjetsPruningTagged08_, &b_pfsubjetsPruningTagged08_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08.subjets_begin", pfsubjetsPruningTagged08_subjets_begin, &b_pfsubjetsPruningTagged08_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08.subjets_end", pfsubjetsPruningTagged08_subjets_end, &b_pfsubjetsPruningTagged08_subjets_end);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08#0", &pfsubjetsPruningTagged08#0_, &b_pfsubjetsPruningTagged08#0_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08#0.index", &pfsubjetsPruningTagged08#0_index, &b_pfsubjetsPruningTagged08#0_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08#0.collectionID", &pfsubjetsPruningTagged08#0_collectionID, &b_pfsubjetsPruningTagged08#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08#1", &pfsubjetsPruningTagged08#1_, &b_pfsubjetsPruningTagged08#1_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08#1.index", pfsubjetsPruningTagged08#1_index, &b_pfsubjetsPruningTagged08#1_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged08#1.collectionID", pfsubjetsPruningTagged08#1_collectionID, &b_pfsubjetsPruningTagged08#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08", &pfsubjetsSoftDropTagged08_, &b_pfsubjetsSoftDropTagged08_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08.subjets_begin", pfsubjetsSoftDropTagged08_subjets_begin, &b_pfsubjetsSoftDropTagged08_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08.subjets_end", pfsubjetsSoftDropTagged08_subjets_end, &b_pfsubjetsSoftDropTagged08_subjets_end);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08#0", &pfsubjetsSoftDropTagged08#0_, &b_pfsubjetsSoftDropTagged08#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08#0.index", pfsubjetsSoftDropTagged08#0_index, &b_pfsubjetsSoftDropTagged08#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08#0.collectionID", pfsubjetsSoftDropTagged08#0_collectionID, &b_pfsubjetsSoftDropTagged08#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08#1", &pfsubjetsSoftDropTagged08#1_, &b_pfsubjetsSoftDropTagged08#1_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08#1.index", pfsubjetsSoftDropTagged08#1_index, &b_pfsubjetsSoftDropTagged08#1_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged08#1.collectionID", pfsubjetsSoftDropTagged08#1_collectionID, &b_pfsubjetsSoftDropTagged08#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimming08", &pfsubjetsTrimming08_, &b_pfsubjetsTrimming08_);
   fChain->SetBranchAddress("pfsubjetsTrimming08.core.area", &pfsubjetsTrimming08_core_area, &b_pfsubjetsTrimming08_core_area);
   fChain->SetBranchAddress("pfsubjetsTrimming08.core.bits", &pfsubjetsTrimming08_core_bits, &b_pfsubjetsTrimming08_core_bits);
   fChain->SetBranchAddress("pfsubjetsTrimming08.core.p4.mass", &pfsubjetsTrimming08_core_p4_mass, &b_pfsubjetsTrimming08_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsTrimming08.core.p4.px", &pfsubjetsTrimming08_core_p4_px, &b_pfsubjetsTrimming08_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsTrimming08.core.p4.py", &pfsubjetsTrimming08_core_p4_py, &b_pfsubjetsTrimming08_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsTrimming08.core.p4.pz", &pfsubjetsTrimming08_core_p4_pz, &b_pfsubjetsTrimming08_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsTrimming08.particles_begin", &pfsubjetsTrimming08_particles_begin, &b_pfsubjetsTrimming08_particles_begin);
   fChain->SetBranchAddress("pfsubjetsTrimming08.particles_end", &pfsubjetsTrimming08_particles_end, &b_pfsubjetsTrimming08_particles_end);
   fChain->SetBranchAddress("pfsubjetsTrimming08#0", &pfsubjetsTrimming08#0_, &b_pfsubjetsTrimming08#0_);
   fChain->SetBranchAddress("pfsubjetsTrimming08#0.index", &pfsubjetsTrimming08#0_index, &b_pfsubjetsTrimming08#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimming08#0.collectionID", &pfsubjetsTrimming08#0_collectionID, &b_pfsubjetsTrimming08#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruning08", &pfsubjetsPruning08_, &b_pfsubjetsPruning08_);
   fChain->SetBranchAddress("pfsubjetsPruning08.core.area", &pfsubjetsPruning08_core_area, &b_pfsubjetsPruning08_core_area);
   fChain->SetBranchAddress("pfsubjetsPruning08.core.bits", &pfsubjetsPruning08_core_bits, &b_pfsubjetsPruning08_core_bits);
   fChain->SetBranchAddress("pfsubjetsPruning08.core.p4.mass", &pfsubjetsPruning08_core_p4_mass, &b_pfsubjetsPruning08_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsPruning08.core.p4.px", &pfsubjetsPruning08_core_p4_px, &b_pfsubjetsPruning08_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsPruning08.core.p4.py", &pfsubjetsPruning08_core_p4_py, &b_pfsubjetsPruning08_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsPruning08.core.p4.pz", &pfsubjetsPruning08_core_p4_pz, &b_pfsubjetsPruning08_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsPruning08.particles_begin", &pfsubjetsPruning08_particles_begin, &b_pfsubjetsPruning08_particles_begin);
   fChain->SetBranchAddress("pfsubjetsPruning08.particles_end", &pfsubjetsPruning08_particles_end, &b_pfsubjetsPruning08_particles_end);
   fChain->SetBranchAddress("pfsubjetsPruning08#0", &pfsubjetsPruning08#0_, &b_pfsubjetsPruning08#0_);
   fChain->SetBranchAddress("pfsubjetsPruning08#0.index", &pfsubjetsPruning08#0_index, &b_pfsubjetsPruning08#0_index);
   fChain->SetBranchAddress("pfsubjetsPruning08#0.collectionID", &pfsubjetsPruning08#0_collectionID, &b_pfsubjetsPruning08#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08", &pfsubjetsSoftDrop08_, &b_pfsubjetsSoftDrop08_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.core.area", pfsubjetsSoftDrop08_core_area, &b_pfsubjetsSoftDrop08_core_area);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.core.bits", pfsubjetsSoftDrop08_core_bits, &b_pfsubjetsSoftDrop08_core_bits);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.core.p4.mass", pfsubjetsSoftDrop08_core_p4_mass, &b_pfsubjetsSoftDrop08_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.core.p4.px", pfsubjetsSoftDrop08_core_p4_px, &b_pfsubjetsSoftDrop08_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.core.p4.py", pfsubjetsSoftDrop08_core_p4_py, &b_pfsubjetsSoftDrop08_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.core.p4.pz", pfsubjetsSoftDrop08_core_p4_pz, &b_pfsubjetsSoftDrop08_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.particles_begin", pfsubjetsSoftDrop08_particles_begin, &b_pfsubjetsSoftDrop08_particles_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08.particles_end", pfsubjetsSoftDrop08_particles_end, &b_pfsubjetsSoftDrop08_particles_end);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08#0", &pfsubjetsSoftDrop08#0_, &b_pfsubjetsSoftDrop08#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08#0.index", &pfsubjetsSoftDrop08#0_index, &b_pfsubjetsSoftDrop08#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDrop08#0.collectionID", &pfsubjetsSoftDrop08#0_collectionID, &b_pfsubjetsSoftDrop08#0_collectionID);
   fChain->SetBranchAddress("pfjets15", &pfjets15_, &b_pfjets15_);
   fChain->SetBranchAddress("pfjets15.core.area", pfjets15_core_area, &b_pfjets15_core_area);
   fChain->SetBranchAddress("pfjets15.core.bits", pfjets15_core_bits, &b_pfjets15_core_bits);
   fChain->SetBranchAddress("pfjets15.core.p4.mass", pfjets15_core_p4_mass, &b_pfjets15_core_p4_mass);
   fChain->SetBranchAddress("pfjets15.core.p4.px", pfjets15_core_p4_px, &b_pfjets15_core_p4_px);
   fChain->SetBranchAddress("pfjets15.core.p4.py", pfjets15_core_p4_py, &b_pfjets15_core_p4_py);
   fChain->SetBranchAddress("pfjets15.core.p4.pz", pfjets15_core_p4_pz, &b_pfjets15_core_p4_pz);
   fChain->SetBranchAddress("pfjets15.particles_begin", pfjets15_particles_begin, &b_pfjets15_particles_begin);
   fChain->SetBranchAddress("pfjets15.particles_end", pfjets15_particles_end, &b_pfjets15_particles_end);
   fChain->SetBranchAddress("pfjets15#0", &pfjets15#0_, &b_pfjets15#0_);
   fChain->SetBranchAddress("pfjets15#0.index", pfjets15#0_index, &b_pfjets15#0_index);
   fChain->SetBranchAddress("pfjets15#0.collectionID", pfjets15#0_collectionID, &b_pfjets15#0_collectionID);
   fChain->SetBranchAddress("pfjetsFlavor15", &pfjetsFlavor15_, &b_pfjetsFlavor15_);
   fChain->SetBranchAddress("pfjetsFlavor15.tag", pfjetsFlavor15_tag, &b_pfjetsFlavor15_tag);
   fChain->SetBranchAddress("pfjetsFlavor15#0", &pfjetsFlavor15#0_, &b_pfjetsFlavor15#0_);
   fChain->SetBranchAddress("pfjetsFlavor15#0.index", pfjetsFlavor15#0_index, &b_pfjetsFlavor15#0_index);
   fChain->SetBranchAddress("pfjetsFlavor15#0.collectionID", pfjetsFlavor15#0_collectionID, &b_pfjetsFlavor15#0_collectionID);
   fChain->SetBranchAddress("pfbTags15", &pfbTags15_, &b_pfbTags15_);
   fChain->SetBranchAddress("pfbTags15.tag", pfbTags15_tag, &b_pfbTags15_tag);
   fChain->SetBranchAddress("pfbTags15#0", &pfbTags15#0_, &b_pfbTags15#0_);
   fChain->SetBranchAddress("pfbTags15#0.index", pfbTags15#0_index, &b_pfbTags15#0_index);
   fChain->SetBranchAddress("pfbTags15#0.collectionID", pfbTags15#0_collectionID, &b_pfbTags15#0_collectionID);
   fChain->SetBranchAddress("pfcTags15", &pfcTags15_, &b_pfcTags15_);
   fChain->SetBranchAddress("pfcTags15.tag", pfcTags15_tag, &b_pfcTags15_tag);
   fChain->SetBranchAddress("pfcTags15#0", &pfcTags15#0_, &b_pfcTags15#0_);
   fChain->SetBranchAddress("pfcTags15#0.index", pfcTags15#0_index, &b_pfcTags15#0_index);
   fChain->SetBranchAddress("pfcTags15#0.collectionID", pfcTags15#0_collectionID, &b_pfcTags15#0_collectionID);
   fChain->SetBranchAddress("pftauTags15", &pftauTags15_, &b_pftauTags15_);
   fChain->SetBranchAddress("pftauTags15.tag", pftauTags15_tag, &b_pftauTags15_tag);
   fChain->SetBranchAddress("pftauTags15#0", &pftauTags15#0_, &b_pftauTags15#0_);
   fChain->SetBranchAddress("pftauTags15#0.index", pftauTags15#0_index, &b_pftauTags15#0_index);
   fChain->SetBranchAddress("pftauTags15#0.collectionID", pftauTags15#0_collectionID, &b_pftauTags15#0_collectionID);
   fChain->SetBranchAddress("pfjetParts15", &pfjetParts15_, &b_pfjetParts15_);
   fChain->SetBranchAddress("pfjetParts15.core.bits", pfjetParts15_core_bits, &b_pfjetParts15_core_bits);
   fChain->SetBranchAddress("pfjetParts15.core.charge", pfjetParts15_core_charge, &b_pfjetParts15_core_charge);
   fChain->SetBranchAddress("pfjetParts15.core.p4.mass", pfjetParts15_core_p4_mass, &b_pfjetParts15_core_p4_mass);
   fChain->SetBranchAddress("pfjetParts15.core.p4.px", pfjetParts15_core_p4_px, &b_pfjetParts15_core_p4_px);
   fChain->SetBranchAddress("pfjetParts15.core.p4.py", pfjetParts15_core_p4_py, &b_pfjetParts15_core_p4_py);
   fChain->SetBranchAddress("pfjetParts15.core.p4.pz", pfjetParts15_core_p4_pz, &b_pfjetParts15_core_p4_pz);
   fChain->SetBranchAddress("pfjetParts15.core.pdgId", pfjetParts15_core_pdgId, &b_pfjetParts15_core_pdgId);
   fChain->SetBranchAddress("pfjetParts15.core.status", pfjetParts15_core_status, &b_pfjetParts15_core_status);
   fChain->SetBranchAddress("pfjetParts15.core.vertex.x", pfjetParts15_core_vertex_x, &b_pfjetParts15_core_vertex_x);
   fChain->SetBranchAddress("pfjetParts15.core.vertex.y", pfjetParts15_core_vertex_y, &b_pfjetParts15_core_vertex_y);
   fChain->SetBranchAddress("pfjetParts15.core.vertex.z", pfjetParts15_core_vertex_z, &b_pfjetParts15_core_vertex_z);
   fChain->SetBranchAddress("pfjetParts15.tracks_begin", pfjetParts15_tracks_begin, &b_pfjetParts15_tracks_begin);
   fChain->SetBranchAddress("pfjetParts15.tracks_end", pfjetParts15_tracks_end, &b_pfjetParts15_tracks_end);
   fChain->SetBranchAddress("pfjetParts15.clusters_begin", pfjetParts15_clusters_begin, &b_pfjetParts15_clusters_begin);
   fChain->SetBranchAddress("pfjetParts15.clusters_end", pfjetParts15_clusters_end, &b_pfjetParts15_clusters_end);
   fChain->SetBranchAddress("pfjetParts15#0", &pfjetParts15#0_, &b_pfjetParts15#0_);
   fChain->SetBranchAddress("pfjetParts15#0.index", &pfjetParts15#0_index, &b_pfjetParts15#0_index);
   fChain->SetBranchAddress("pfjetParts15#0.collectionID", &pfjetParts15#0_collectionID, &b_pfjetParts15#0_collectionID);
   fChain->SetBranchAddress("pfjetParts15#1", &pfjetParts15#1_, &b_pfjetParts15#1_);
   fChain->SetBranchAddress("pfjetParts15#1.index", &pfjetParts15#1_index, &b_pfjetParts15#1_index);
   fChain->SetBranchAddress("pfjetParts15#1.collectionID", &pfjetParts15#1_collectionID, &b_pfjetParts15#1_collectionID);
   fChain->SetBranchAddress("pfjetsOneSubJettiness15", &pfjetsOneSubJettiness15_, &b_pfjetsOneSubJettiness15_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness15.tag", pfjetsOneSubJettiness15_tag, &b_pfjetsOneSubJettiness15_tag);
   fChain->SetBranchAddress("pfjetsOneSubJettiness15#0", &pfjetsOneSubJettiness15#0_, &b_pfjetsOneSubJettiness15#0_);
   fChain->SetBranchAddress("pfjetsOneSubJettiness15#0.index", pfjetsOneSubJettiness15#0_index, &b_pfjetsOneSubJettiness15#0_index);
   fChain->SetBranchAddress("pfjetsOneSubJettiness15#0.collectionID", pfjetsOneSubJettiness15#0_collectionID, &b_pfjetsOneSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness15", &pfjetsTwoSubJettiness15_, &b_pfjetsTwoSubJettiness15_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness15.tag", pfjetsTwoSubJettiness15_tag, &b_pfjetsTwoSubJettiness15_tag);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness15#0", &pfjetsTwoSubJettiness15#0_, &b_pfjetsTwoSubJettiness15#0_);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness15#0.index", pfjetsTwoSubJettiness15#0_index, &b_pfjetsTwoSubJettiness15#0_index);
   fChain->SetBranchAddress("pfjetsTwoSubJettiness15#0.collectionID", pfjetsTwoSubJettiness15#0_collectionID, &b_pfjetsTwoSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness15", &pfjetsThreeSubJettiness15_, &b_pfjetsThreeSubJettiness15_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness15.tag", pfjetsThreeSubJettiness15_tag, &b_pfjetsThreeSubJettiness15_tag);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness15#0", &pfjetsThreeSubJettiness15#0_, &b_pfjetsThreeSubJettiness15#0_);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness15#0.index", pfjetsThreeSubJettiness15#0_index, &b_pfjetsThreeSubJettiness15#0_index);
   fChain->SetBranchAddress("pfjetsThreeSubJettiness15#0.collectionID", pfjetsThreeSubJettiness15#0_collectionID, &b_pfjetsThreeSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15", &pfsubjetsTrimmingTagged15_, &b_pfsubjetsTrimmingTagged15_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15.subjets_begin", pfsubjetsTrimmingTagged15_subjets_begin, &b_pfsubjetsTrimmingTagged15_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15.subjets_end", pfsubjetsTrimmingTagged15_subjets_end, &b_pfsubjetsTrimmingTagged15_subjets_end);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15#0", &pfsubjetsTrimmingTagged15#0_, &b_pfsubjetsTrimmingTagged15#0_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15#0.index", &pfsubjetsTrimmingTagged15#0_index, &b_pfsubjetsTrimmingTagged15#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15#0.collectionID", &pfsubjetsTrimmingTagged15#0_collectionID, &b_pfsubjetsTrimmingTagged15#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15#1", &pfsubjetsTrimmingTagged15#1_, &b_pfsubjetsTrimmingTagged15#1_);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15#1.index", pfsubjetsTrimmingTagged15#1_index, &b_pfsubjetsTrimmingTagged15#1_index);
   fChain->SetBranchAddress("pfsubjetsTrimmingTagged15#1.collectionID", pfsubjetsTrimmingTagged15#1_collectionID, &b_pfsubjetsTrimmingTagged15#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15", &pfsubjetsPruningTagged15_, &b_pfsubjetsPruningTagged15_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15.subjets_begin", pfsubjetsPruningTagged15_subjets_begin, &b_pfsubjetsPruningTagged15_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15.subjets_end", pfsubjetsPruningTagged15_subjets_end, &b_pfsubjetsPruningTagged15_subjets_end);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15#0", &pfsubjetsPruningTagged15#0_, &b_pfsubjetsPruningTagged15#0_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15#0.index", &pfsubjetsPruningTagged15#0_index, &b_pfsubjetsPruningTagged15#0_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15#0.collectionID", &pfsubjetsPruningTagged15#0_collectionID, &b_pfsubjetsPruningTagged15#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15#1", &pfsubjetsPruningTagged15#1_, &b_pfsubjetsPruningTagged15#1_);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15#1.index", pfsubjetsPruningTagged15#1_index, &b_pfsubjetsPruningTagged15#1_index);
   fChain->SetBranchAddress("pfsubjetsPruningTagged15#1.collectionID", pfsubjetsPruningTagged15#1_collectionID, &b_pfsubjetsPruningTagged15#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15", &pfsubjetsSoftDropTagged15_, &b_pfsubjetsSoftDropTagged15_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15.subjets_begin", pfsubjetsSoftDropTagged15_subjets_begin, &b_pfsubjetsSoftDropTagged15_subjets_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15.subjets_end", pfsubjetsSoftDropTagged15_subjets_end, &b_pfsubjetsSoftDropTagged15_subjets_end);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15#0", &pfsubjetsSoftDropTagged15#0_, &b_pfsubjetsSoftDropTagged15#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15#0.index", pfsubjetsSoftDropTagged15#0_index, &b_pfsubjetsSoftDropTagged15#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15#0.collectionID", pfsubjetsSoftDropTagged15#0_collectionID, &b_pfsubjetsSoftDropTagged15#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15#1", &pfsubjetsSoftDropTagged15#1_, &b_pfsubjetsSoftDropTagged15#1_);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15#1.index", pfsubjetsSoftDropTagged15#1_index, &b_pfsubjetsSoftDropTagged15#1_index);
   fChain->SetBranchAddress("pfsubjetsSoftDropTagged15#1.collectionID", pfsubjetsSoftDropTagged15#1_collectionID, &b_pfsubjetsSoftDropTagged15#1_collectionID);
   fChain->SetBranchAddress("pfsubjetsTrimming15", &pfsubjetsTrimming15_, &b_pfsubjetsTrimming15_);
   fChain->SetBranchAddress("pfsubjetsTrimming15.core.area", &pfsubjetsTrimming15_core_area, &b_pfsubjetsTrimming15_core_area);
   fChain->SetBranchAddress("pfsubjetsTrimming15.core.bits", &pfsubjetsTrimming15_core_bits, &b_pfsubjetsTrimming15_core_bits);
   fChain->SetBranchAddress("pfsubjetsTrimming15.core.p4.mass", &pfsubjetsTrimming15_core_p4_mass, &b_pfsubjetsTrimming15_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsTrimming15.core.p4.px", &pfsubjetsTrimming15_core_p4_px, &b_pfsubjetsTrimming15_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsTrimming15.core.p4.py", &pfsubjetsTrimming15_core_p4_py, &b_pfsubjetsTrimming15_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsTrimming15.core.p4.pz", &pfsubjetsTrimming15_core_p4_pz, &b_pfsubjetsTrimming15_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsTrimming15.particles_begin", &pfsubjetsTrimming15_particles_begin, &b_pfsubjetsTrimming15_particles_begin);
   fChain->SetBranchAddress("pfsubjetsTrimming15.particles_end", &pfsubjetsTrimming15_particles_end, &b_pfsubjetsTrimming15_particles_end);
   fChain->SetBranchAddress("pfsubjetsTrimming15#0", &pfsubjetsTrimming15#0_, &b_pfsubjetsTrimming15#0_);
   fChain->SetBranchAddress("pfsubjetsTrimming15#0.index", &pfsubjetsTrimming15#0_index, &b_pfsubjetsTrimming15#0_index);
   fChain->SetBranchAddress("pfsubjetsTrimming15#0.collectionID", &pfsubjetsTrimming15#0_collectionID, &b_pfsubjetsTrimming15#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsPruning15", &pfsubjetsPruning15_, &b_pfsubjetsPruning15_);
   fChain->SetBranchAddress("pfsubjetsPruning15.core.area", &pfsubjetsPruning15_core_area, &b_pfsubjetsPruning15_core_area);
   fChain->SetBranchAddress("pfsubjetsPruning15.core.bits", &pfsubjetsPruning15_core_bits, &b_pfsubjetsPruning15_core_bits);
   fChain->SetBranchAddress("pfsubjetsPruning15.core.p4.mass", &pfsubjetsPruning15_core_p4_mass, &b_pfsubjetsPruning15_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsPruning15.core.p4.px", &pfsubjetsPruning15_core_p4_px, &b_pfsubjetsPruning15_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsPruning15.core.p4.py", &pfsubjetsPruning15_core_p4_py, &b_pfsubjetsPruning15_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsPruning15.core.p4.pz", &pfsubjetsPruning15_core_p4_pz, &b_pfsubjetsPruning15_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsPruning15.particles_begin", &pfsubjetsPruning15_particles_begin, &b_pfsubjetsPruning15_particles_begin);
   fChain->SetBranchAddress("pfsubjetsPruning15.particles_end", &pfsubjetsPruning15_particles_end, &b_pfsubjetsPruning15_particles_end);
   fChain->SetBranchAddress("pfsubjetsPruning15#0", &pfsubjetsPruning15#0_, &b_pfsubjetsPruning15#0_);
   fChain->SetBranchAddress("pfsubjetsPruning15#0.index", &pfsubjetsPruning15#0_index, &b_pfsubjetsPruning15#0_index);
   fChain->SetBranchAddress("pfsubjetsPruning15#0.collectionID", &pfsubjetsPruning15#0_collectionID, &b_pfsubjetsPruning15#0_collectionID);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15", &pfsubjetsSoftDrop15_, &b_pfsubjetsSoftDrop15_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.core.area", pfsubjetsSoftDrop15_core_area, &b_pfsubjetsSoftDrop15_core_area);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.core.bits", pfsubjetsSoftDrop15_core_bits, &b_pfsubjetsSoftDrop15_core_bits);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.core.p4.mass", pfsubjetsSoftDrop15_core_p4_mass, &b_pfsubjetsSoftDrop15_core_p4_mass);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.core.p4.px", pfsubjetsSoftDrop15_core_p4_px, &b_pfsubjetsSoftDrop15_core_p4_px);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.core.p4.py", pfsubjetsSoftDrop15_core_p4_py, &b_pfsubjetsSoftDrop15_core_p4_py);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.core.p4.pz", pfsubjetsSoftDrop15_core_p4_pz, &b_pfsubjetsSoftDrop15_core_p4_pz);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.particles_begin", pfsubjetsSoftDrop15_particles_begin, &b_pfsubjetsSoftDrop15_particles_begin);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15.particles_end", pfsubjetsSoftDrop15_particles_end, &b_pfsubjetsSoftDrop15_particles_end);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15#0", &pfsubjetsSoftDrop15#0_, &b_pfsubjetsSoftDrop15#0_);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15#0.index", &pfsubjetsSoftDrop15#0_index, &b_pfsubjetsSoftDrop15#0_index);
   fChain->SetBranchAddress("pfsubjetsSoftDrop15#0.collectionID", &pfsubjetsSoftDrop15#0_collectionID, &b_pfsubjetsSoftDrop15#0_collectionID);
   fChain->SetBranchAddress("trkjets02", &trkjets02_, &b_trkjets02_);
   fChain->SetBranchAddress("trkjets02.core.area", trkjets02_core_area, &b_trkjets02_core_area);
   fChain->SetBranchAddress("trkjets02.core.bits", trkjets02_core_bits, &b_trkjets02_core_bits);
   fChain->SetBranchAddress("trkjets02.core.p4.mass", trkjets02_core_p4_mass, &b_trkjets02_core_p4_mass);
   fChain->SetBranchAddress("trkjets02.core.p4.px", trkjets02_core_p4_px, &b_trkjets02_core_p4_px);
   fChain->SetBranchAddress("trkjets02.core.p4.py", trkjets02_core_p4_py, &b_trkjets02_core_p4_py);
   fChain->SetBranchAddress("trkjets02.core.p4.pz", trkjets02_core_p4_pz, &b_trkjets02_core_p4_pz);
   fChain->SetBranchAddress("trkjets02.particles_begin", trkjets02_particles_begin, &b_trkjets02_particles_begin);
   fChain->SetBranchAddress("trkjets02.particles_end", trkjets02_particles_end, &b_trkjets02_particles_end);
   fChain->SetBranchAddress("trkjets02#0", &trkjets02#0_, &b_trkjets02#0_);
   fChain->SetBranchAddress("trkjets02#0.index", trkjets02#0_index, &b_trkjets02#0_index);
   fChain->SetBranchAddress("trkjets02#0.collectionID", trkjets02#0_collectionID, &b_trkjets02#0_collectionID);
   fChain->SetBranchAddress("trkjetsFlavor02", &trkjetsFlavor02_, &b_trkjetsFlavor02_);
   fChain->SetBranchAddress("trkjetsFlavor02.tag", trkjetsFlavor02_tag, &b_trkjetsFlavor02_tag);
   fChain->SetBranchAddress("trkjetsFlavor02#0", &trkjetsFlavor02#0_, &b_trkjetsFlavor02#0_);
   fChain->SetBranchAddress("trkjetsFlavor02#0.index", trkjetsFlavor02#0_index, &b_trkjetsFlavor02#0_index);
   fChain->SetBranchAddress("trkjetsFlavor02#0.collectionID", trkjetsFlavor02#0_collectionID, &b_trkjetsFlavor02#0_collectionID);
   fChain->SetBranchAddress("trkbTags02", &trkbTags02_, &b_trkbTags02_);
   fChain->SetBranchAddress("trkbTags02.tag", trkbTags02_tag, &b_trkbTags02_tag);
   fChain->SetBranchAddress("trkbTags02#0", &trkbTags02#0_, &b_trkbTags02#0_);
   fChain->SetBranchAddress("trkbTags02#0.index", trkbTags02#0_index, &b_trkbTags02#0_index);
   fChain->SetBranchAddress("trkbTags02#0.collectionID", trkbTags02#0_collectionID, &b_trkbTags02#0_collectionID);
   fChain->SetBranchAddress("trkcTags02", &trkcTags02_, &b_trkcTags02_);
   fChain->SetBranchAddress("trkcTags02.tag", trkcTags02_tag, &b_trkcTags02_tag);
   fChain->SetBranchAddress("trkcTags02#0", &trkcTags02#0_, &b_trkcTags02#0_);
   fChain->SetBranchAddress("trkcTags02#0.index", trkcTags02#0_index, &b_trkcTags02#0_index);
   fChain->SetBranchAddress("trkcTags02#0.collectionID", trkcTags02#0_collectionID, &b_trkcTags02#0_collectionID);
   fChain->SetBranchAddress("trktauTags02", &trktauTags02_, &b_trktauTags02_);
   fChain->SetBranchAddress("trktauTags02.tag", trktauTags02_tag, &b_trktauTags02_tag);
   fChain->SetBranchAddress("trktauTags02#0", &trktauTags02#0_, &b_trktauTags02#0_);
   fChain->SetBranchAddress("trktauTags02#0.index", trktauTags02#0_index, &b_trktauTags02#0_index);
   fChain->SetBranchAddress("trktauTags02#0.collectionID", trktauTags02#0_collectionID, &b_trktauTags02#0_collectionID);
   fChain->SetBranchAddress("trkjetParts02", &trkjetParts02_, &b_trkjetParts02_);
   fChain->SetBranchAddress("trkjetParts02.core.bits", trkjetParts02_core_bits, &b_trkjetParts02_core_bits);
   fChain->SetBranchAddress("trkjetParts02.core.charge", trkjetParts02_core_charge, &b_trkjetParts02_core_charge);
   fChain->SetBranchAddress("trkjetParts02.core.p4.mass", trkjetParts02_core_p4_mass, &b_trkjetParts02_core_p4_mass);
   fChain->SetBranchAddress("trkjetParts02.core.p4.px", trkjetParts02_core_p4_px, &b_trkjetParts02_core_p4_px);
   fChain->SetBranchAddress("trkjetParts02.core.p4.py", trkjetParts02_core_p4_py, &b_trkjetParts02_core_p4_py);
   fChain->SetBranchAddress("trkjetParts02.core.p4.pz", trkjetParts02_core_p4_pz, &b_trkjetParts02_core_p4_pz);
   fChain->SetBranchAddress("trkjetParts02.core.pdgId", trkjetParts02_core_pdgId, &b_trkjetParts02_core_pdgId);
   fChain->SetBranchAddress("trkjetParts02.core.status", trkjetParts02_core_status, &b_trkjetParts02_core_status);
   fChain->SetBranchAddress("trkjetParts02.core.vertex.x", trkjetParts02_core_vertex_x, &b_trkjetParts02_core_vertex_x);
   fChain->SetBranchAddress("trkjetParts02.core.vertex.y", trkjetParts02_core_vertex_y, &b_trkjetParts02_core_vertex_y);
   fChain->SetBranchAddress("trkjetParts02.core.vertex.z", trkjetParts02_core_vertex_z, &b_trkjetParts02_core_vertex_z);
   fChain->SetBranchAddress("trkjetParts02.tracks_begin", trkjetParts02_tracks_begin, &b_trkjetParts02_tracks_begin);
   fChain->SetBranchAddress("trkjetParts02.tracks_end", trkjetParts02_tracks_end, &b_trkjetParts02_tracks_end);
   fChain->SetBranchAddress("trkjetParts02.clusters_begin", trkjetParts02_clusters_begin, &b_trkjetParts02_clusters_begin);
   fChain->SetBranchAddress("trkjetParts02.clusters_end", trkjetParts02_clusters_end, &b_trkjetParts02_clusters_end);
   fChain->SetBranchAddress("trkjetParts02#0", &trkjetParts02#0_, &b_trkjetParts02#0_);
   fChain->SetBranchAddress("trkjetParts02#0.index", &trkjetParts02#0_index, &b_trkjetParts02#0_index);
   fChain->SetBranchAddress("trkjetParts02#0.collectionID", &trkjetParts02#0_collectionID, &b_trkjetParts02#0_collectionID);
   fChain->SetBranchAddress("trkjetParts02#1", &trkjetParts02#1_, &b_trkjetParts02#1_);
   fChain->SetBranchAddress("trkjetParts02#1.index", &trkjetParts02#1_index, &b_trkjetParts02#1_index);
   fChain->SetBranchAddress("trkjetParts02#1.collectionID", &trkjetParts02#1_collectionID, &b_trkjetParts02#1_collectionID);
   fChain->SetBranchAddress("trkjetsOneSubJettiness02", &trkjetsOneSubJettiness02_, &b_trkjetsOneSubJettiness02_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness02.tag", trkjetsOneSubJettiness02_tag, &b_trkjetsOneSubJettiness02_tag);
   fChain->SetBranchAddress("trkjetsOneSubJettiness02#0", &trkjetsOneSubJettiness02#0_, &b_trkjetsOneSubJettiness02#0_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness02#0.index", trkjetsOneSubJettiness02#0_index, &b_trkjetsOneSubJettiness02#0_index);
   fChain->SetBranchAddress("trkjetsOneSubJettiness02#0.collectionID", trkjetsOneSubJettiness02#0_collectionID, &b_trkjetsOneSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness02", &trkjetsTwoSubJettiness02_, &b_trkjetsTwoSubJettiness02_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness02.tag", trkjetsTwoSubJettiness02_tag, &b_trkjetsTwoSubJettiness02_tag);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness02#0", &trkjetsTwoSubJettiness02#0_, &b_trkjetsTwoSubJettiness02#0_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness02#0.index", trkjetsTwoSubJettiness02#0_index, &b_trkjetsTwoSubJettiness02#0_index);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness02#0.collectionID", trkjetsTwoSubJettiness02#0_collectionID, &b_trkjetsTwoSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness02", &trkjetsThreeSubJettiness02_, &b_trkjetsThreeSubJettiness02_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness02.tag", trkjetsThreeSubJettiness02_tag, &b_trkjetsThreeSubJettiness02_tag);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness02#0", &trkjetsThreeSubJettiness02#0_, &b_trkjetsThreeSubJettiness02#0_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness02#0.index", trkjetsThreeSubJettiness02#0_index, &b_trkjetsThreeSubJettiness02#0_index);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness02#0.collectionID", trkjetsThreeSubJettiness02#0_collectionID, &b_trkjetsThreeSubJettiness02#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02", &trksubjetsTrimmingTagged02_, &b_trksubjetsTrimmingTagged02_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02.subjets_begin", trksubjetsTrimmingTagged02_subjets_begin, &b_trksubjetsTrimmingTagged02_subjets_begin);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02.subjets_end", trksubjetsTrimmingTagged02_subjets_end, &b_trksubjetsTrimmingTagged02_subjets_end);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02#0", &trksubjetsTrimmingTagged02#0_, &b_trksubjetsTrimmingTagged02#0_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02#0.index", &trksubjetsTrimmingTagged02#0_index, &b_trksubjetsTrimmingTagged02#0_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02#0.collectionID", &trksubjetsTrimmingTagged02#0_collectionID, &b_trksubjetsTrimmingTagged02#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02#1", &trksubjetsTrimmingTagged02#1_, &b_trksubjetsTrimmingTagged02#1_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02#1.index", trksubjetsTrimmingTagged02#1_index, &b_trksubjetsTrimmingTagged02#1_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged02#1.collectionID", trksubjetsTrimmingTagged02#1_collectionID, &b_trksubjetsTrimmingTagged02#1_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged02", &trksubjetsPruningTagged02_, &b_trksubjetsPruningTagged02_);
   fChain->SetBranchAddress("trksubjetsPruningTagged02.subjets_begin", trksubjetsPruningTagged02_subjets_begin, &b_trksubjetsPruningTagged02_subjets_begin);
   fChain->SetBranchAddress("trksubjetsPruningTagged02.subjets_end", trksubjetsPruningTagged02_subjets_end, &b_trksubjetsPruningTagged02_subjets_end);
   fChain->SetBranchAddress("trksubjetsPruningTagged02#0", &trksubjetsPruningTagged02#0_, &b_trksubjetsPruningTagged02#0_);
   fChain->SetBranchAddress("trksubjetsPruningTagged02#0.index", &trksubjetsPruningTagged02#0_index, &b_trksubjetsPruningTagged02#0_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged02#0.collectionID", &trksubjetsPruningTagged02#0_collectionID, &b_trksubjetsPruningTagged02#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged02#1", &trksubjetsPruningTagged02#1_, &b_trksubjetsPruningTagged02#1_);
   fChain->SetBranchAddress("trksubjetsPruningTagged02#1.index", trksubjetsPruningTagged02#1_index, &b_trksubjetsPruningTagged02#1_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged02#1.collectionID", trksubjetsPruningTagged02#1_collectionID, &b_trksubjetsPruningTagged02#1_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02", &trksubjetsSoftDropTagged02_, &b_trksubjetsSoftDropTagged02_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02.subjets_begin", trksubjetsSoftDropTagged02_subjets_begin, &b_trksubjetsSoftDropTagged02_subjets_begin);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02.subjets_end", trksubjetsSoftDropTagged02_subjets_end, &b_trksubjetsSoftDropTagged02_subjets_end);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02#0", &trksubjetsSoftDropTagged02#0_, &b_trksubjetsSoftDropTagged02#0_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02#0.index", trksubjetsSoftDropTagged02#0_index, &b_trksubjetsSoftDropTagged02#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02#0.collectionID", trksubjetsSoftDropTagged02#0_collectionID, &b_trksubjetsSoftDropTagged02#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02#1", &trksubjetsSoftDropTagged02#1_, &b_trksubjetsSoftDropTagged02#1_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02#1.index", trksubjetsSoftDropTagged02#1_index, &b_trksubjetsSoftDropTagged02#1_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged02#1.collectionID", trksubjetsSoftDropTagged02#1_collectionID, &b_trksubjetsSoftDropTagged02#1_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimming02", &trksubjetsTrimming02_, &b_trksubjetsTrimming02_);
   fChain->SetBranchAddress("trksubjetsTrimming02.core.area", &trksubjetsTrimming02_core_area, &b_trksubjetsTrimming02_core_area);
   fChain->SetBranchAddress("trksubjetsTrimming02.core.bits", &trksubjetsTrimming02_core_bits, &b_trksubjetsTrimming02_core_bits);
   fChain->SetBranchAddress("trksubjetsTrimming02.core.p4.mass", &trksubjetsTrimming02_core_p4_mass, &b_trksubjetsTrimming02_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsTrimming02.core.p4.px", &trksubjetsTrimming02_core_p4_px, &b_trksubjetsTrimming02_core_p4_px);
   fChain->SetBranchAddress("trksubjetsTrimming02.core.p4.py", &trksubjetsTrimming02_core_p4_py, &b_trksubjetsTrimming02_core_p4_py);
   fChain->SetBranchAddress("trksubjetsTrimming02.core.p4.pz", &trksubjetsTrimming02_core_p4_pz, &b_trksubjetsTrimming02_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsTrimming02.particles_begin", &trksubjetsTrimming02_particles_begin, &b_trksubjetsTrimming02_particles_begin);
   fChain->SetBranchAddress("trksubjetsTrimming02.particles_end", &trksubjetsTrimming02_particles_end, &b_trksubjetsTrimming02_particles_end);
   fChain->SetBranchAddress("trksubjetsTrimming02#0", &trksubjetsTrimming02#0_, &b_trksubjetsTrimming02#0_);
   fChain->SetBranchAddress("trksubjetsTrimming02#0.index", &trksubjetsTrimming02#0_index, &b_trksubjetsTrimming02#0_index);
   fChain->SetBranchAddress("trksubjetsTrimming02#0.collectionID", &trksubjetsTrimming02#0_collectionID, &b_trksubjetsTrimming02#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruning02", &trksubjetsPruning02_, &b_trksubjetsPruning02_);
   fChain->SetBranchAddress("trksubjetsPruning02.core.area", &trksubjetsPruning02_core_area, &b_trksubjetsPruning02_core_area);
   fChain->SetBranchAddress("trksubjetsPruning02.core.bits", &trksubjetsPruning02_core_bits, &b_trksubjetsPruning02_core_bits);
   fChain->SetBranchAddress("trksubjetsPruning02.core.p4.mass", &trksubjetsPruning02_core_p4_mass, &b_trksubjetsPruning02_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsPruning02.core.p4.px", &trksubjetsPruning02_core_p4_px, &b_trksubjetsPruning02_core_p4_px);
   fChain->SetBranchAddress("trksubjetsPruning02.core.p4.py", &trksubjetsPruning02_core_p4_py, &b_trksubjetsPruning02_core_p4_py);
   fChain->SetBranchAddress("trksubjetsPruning02.core.p4.pz", &trksubjetsPruning02_core_p4_pz, &b_trksubjetsPruning02_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsPruning02.particles_begin", &trksubjetsPruning02_particles_begin, &b_trksubjetsPruning02_particles_begin);
   fChain->SetBranchAddress("trksubjetsPruning02.particles_end", &trksubjetsPruning02_particles_end, &b_trksubjetsPruning02_particles_end);
   fChain->SetBranchAddress("trksubjetsPruning02#0", &trksubjetsPruning02#0_, &b_trksubjetsPruning02#0_);
   fChain->SetBranchAddress("trksubjetsPruning02#0.index", &trksubjetsPruning02#0_index, &b_trksubjetsPruning02#0_index);
   fChain->SetBranchAddress("trksubjetsPruning02#0.collectionID", &trksubjetsPruning02#0_collectionID, &b_trksubjetsPruning02#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDrop02", &trksubjetsSoftDrop02_, &b_trksubjetsSoftDrop02_);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.core.area", trksubjetsSoftDrop02_core_area, &b_trksubjetsSoftDrop02_core_area);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.core.bits", trksubjetsSoftDrop02_core_bits, &b_trksubjetsSoftDrop02_core_bits);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.core.p4.mass", trksubjetsSoftDrop02_core_p4_mass, &b_trksubjetsSoftDrop02_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.core.p4.px", trksubjetsSoftDrop02_core_p4_px, &b_trksubjetsSoftDrop02_core_p4_px);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.core.p4.py", trksubjetsSoftDrop02_core_p4_py, &b_trksubjetsSoftDrop02_core_p4_py);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.core.p4.pz", trksubjetsSoftDrop02_core_p4_pz, &b_trksubjetsSoftDrop02_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.particles_begin", trksubjetsSoftDrop02_particles_begin, &b_trksubjetsSoftDrop02_particles_begin);
   fChain->SetBranchAddress("trksubjetsSoftDrop02.particles_end", trksubjetsSoftDrop02_particles_end, &b_trksubjetsSoftDrop02_particles_end);
   fChain->SetBranchAddress("trksubjetsSoftDrop02#0", &trksubjetsSoftDrop02#0_, &b_trksubjetsSoftDrop02#0_);
   fChain->SetBranchAddress("trksubjetsSoftDrop02#0.index", &trksubjetsSoftDrop02#0_index, &b_trksubjetsSoftDrop02#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDrop02#0.collectionID", &trksubjetsSoftDrop02#0_collectionID, &b_trksubjetsSoftDrop02#0_collectionID);
   fChain->SetBranchAddress("trkjets04", &trkjets04_, &b_trkjets04_);
   fChain->SetBranchAddress("trkjets04.core.area", trkjets04_core_area, &b_trkjets04_core_area);
   fChain->SetBranchAddress("trkjets04.core.bits", trkjets04_core_bits, &b_trkjets04_core_bits);
   fChain->SetBranchAddress("trkjets04.core.p4.mass", trkjets04_core_p4_mass, &b_trkjets04_core_p4_mass);
   fChain->SetBranchAddress("trkjets04.core.p4.px", trkjets04_core_p4_px, &b_trkjets04_core_p4_px);
   fChain->SetBranchAddress("trkjets04.core.p4.py", trkjets04_core_p4_py, &b_trkjets04_core_p4_py);
   fChain->SetBranchAddress("trkjets04.core.p4.pz", trkjets04_core_p4_pz, &b_trkjets04_core_p4_pz);
   fChain->SetBranchAddress("trkjets04.particles_begin", trkjets04_particles_begin, &b_trkjets04_particles_begin);
   fChain->SetBranchAddress("trkjets04.particles_end", trkjets04_particles_end, &b_trkjets04_particles_end);
   fChain->SetBranchAddress("trkjets04#0", &trkjets04#0_, &b_trkjets04#0_);
   fChain->SetBranchAddress("trkjets04#0.index", trkjets04#0_index, &b_trkjets04#0_index);
   fChain->SetBranchAddress("trkjets04#0.collectionID", trkjets04#0_collectionID, &b_trkjets04#0_collectionID);
   fChain->SetBranchAddress("trkjetsFlavor04", &trkjetsFlavor04_, &b_trkjetsFlavor04_);
   fChain->SetBranchAddress("trkjetsFlavor04.tag", trkjetsFlavor04_tag, &b_trkjetsFlavor04_tag);
   fChain->SetBranchAddress("trkjetsFlavor04#0", &trkjetsFlavor04#0_, &b_trkjetsFlavor04#0_);
   fChain->SetBranchAddress("trkjetsFlavor04#0.index", trkjetsFlavor04#0_index, &b_trkjetsFlavor04#0_index);
   fChain->SetBranchAddress("trkjetsFlavor04#0.collectionID", trkjetsFlavor04#0_collectionID, &b_trkjetsFlavor04#0_collectionID);
   fChain->SetBranchAddress("trkbTags04", &trkbTags04_, &b_trkbTags04_);
   fChain->SetBranchAddress("trkbTags04.tag", trkbTags04_tag, &b_trkbTags04_tag);
   fChain->SetBranchAddress("trkbTags04#0", &trkbTags04#0_, &b_trkbTags04#0_);
   fChain->SetBranchAddress("trkbTags04#0.index", trkbTags04#0_index, &b_trkbTags04#0_index);
   fChain->SetBranchAddress("trkbTags04#0.collectionID", trkbTags04#0_collectionID, &b_trkbTags04#0_collectionID);
   fChain->SetBranchAddress("trkcTags04", &trkcTags04_, &b_trkcTags04_);
   fChain->SetBranchAddress("trkcTags04.tag", trkcTags04_tag, &b_trkcTags04_tag);
   fChain->SetBranchAddress("trkcTags04#0", &trkcTags04#0_, &b_trkcTags04#0_);
   fChain->SetBranchAddress("trkcTags04#0.index", trkcTags04#0_index, &b_trkcTags04#0_index);
   fChain->SetBranchAddress("trkcTags04#0.collectionID", trkcTags04#0_collectionID, &b_trkcTags04#0_collectionID);
   fChain->SetBranchAddress("trktauTags04", &trktauTags04_, &b_trktauTags04_);
   fChain->SetBranchAddress("trktauTags04.tag", trktauTags04_tag, &b_trktauTags04_tag);
   fChain->SetBranchAddress("trktauTags04#0", &trktauTags04#0_, &b_trktauTags04#0_);
   fChain->SetBranchAddress("trktauTags04#0.index", trktauTags04#0_index, &b_trktauTags04#0_index);
   fChain->SetBranchAddress("trktauTags04#0.collectionID", trktauTags04#0_collectionID, &b_trktauTags04#0_collectionID);
   fChain->SetBranchAddress("trkjetParts04", &trkjetParts04_, &b_trkjetParts04_);
   fChain->SetBranchAddress("trkjetParts04.core.bits", trkjetParts04_core_bits, &b_trkjetParts04_core_bits);
   fChain->SetBranchAddress("trkjetParts04.core.charge", trkjetParts04_core_charge, &b_trkjetParts04_core_charge);
   fChain->SetBranchAddress("trkjetParts04.core.p4.mass", trkjetParts04_core_p4_mass, &b_trkjetParts04_core_p4_mass);
   fChain->SetBranchAddress("trkjetParts04.core.p4.px", trkjetParts04_core_p4_px, &b_trkjetParts04_core_p4_px);
   fChain->SetBranchAddress("trkjetParts04.core.p4.py", trkjetParts04_core_p4_py, &b_trkjetParts04_core_p4_py);
   fChain->SetBranchAddress("trkjetParts04.core.p4.pz", trkjetParts04_core_p4_pz, &b_trkjetParts04_core_p4_pz);
   fChain->SetBranchAddress("trkjetParts04.core.pdgId", trkjetParts04_core_pdgId, &b_trkjetParts04_core_pdgId);
   fChain->SetBranchAddress("trkjetParts04.core.status", trkjetParts04_core_status, &b_trkjetParts04_core_status);
   fChain->SetBranchAddress("trkjetParts04.core.vertex.x", trkjetParts04_core_vertex_x, &b_trkjetParts04_core_vertex_x);
   fChain->SetBranchAddress("trkjetParts04.core.vertex.y", trkjetParts04_core_vertex_y, &b_trkjetParts04_core_vertex_y);
   fChain->SetBranchAddress("trkjetParts04.core.vertex.z", trkjetParts04_core_vertex_z, &b_trkjetParts04_core_vertex_z);
   fChain->SetBranchAddress("trkjetParts04.tracks_begin", trkjetParts04_tracks_begin, &b_trkjetParts04_tracks_begin);
   fChain->SetBranchAddress("trkjetParts04.tracks_end", trkjetParts04_tracks_end, &b_trkjetParts04_tracks_end);
   fChain->SetBranchAddress("trkjetParts04.clusters_begin", trkjetParts04_clusters_begin, &b_trkjetParts04_clusters_begin);
   fChain->SetBranchAddress("trkjetParts04.clusters_end", trkjetParts04_clusters_end, &b_trkjetParts04_clusters_end);
   fChain->SetBranchAddress("trkjetParts04#0", &trkjetParts04#0_, &b_trkjetParts04#0_);
   fChain->SetBranchAddress("trkjetParts04#0.index", &trkjetParts04#0_index, &b_trkjetParts04#0_index);
   fChain->SetBranchAddress("trkjetParts04#0.collectionID", &trkjetParts04#0_collectionID, &b_trkjetParts04#0_collectionID);
   fChain->SetBranchAddress("trkjetParts04#1", &trkjetParts04#1_, &b_trkjetParts04#1_);
   fChain->SetBranchAddress("trkjetParts04#1.index", &trkjetParts04#1_index, &b_trkjetParts04#1_index);
   fChain->SetBranchAddress("trkjetParts04#1.collectionID", &trkjetParts04#1_collectionID, &b_trkjetParts04#1_collectionID);
   fChain->SetBranchAddress("trkjetsOneSubJettiness04", &trkjetsOneSubJettiness04_, &b_trkjetsOneSubJettiness04_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness04.tag", trkjetsOneSubJettiness04_tag, &b_trkjetsOneSubJettiness04_tag);
   fChain->SetBranchAddress("trkjetsOneSubJettiness04#0", &trkjetsOneSubJettiness04#0_, &b_trkjetsOneSubJettiness04#0_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness04#0.index", trkjetsOneSubJettiness04#0_index, &b_trkjetsOneSubJettiness04#0_index);
   fChain->SetBranchAddress("trkjetsOneSubJettiness04#0.collectionID", trkjetsOneSubJettiness04#0_collectionID, &b_trkjetsOneSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness04", &trkjetsTwoSubJettiness04_, &b_trkjetsTwoSubJettiness04_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness04.tag", trkjetsTwoSubJettiness04_tag, &b_trkjetsTwoSubJettiness04_tag);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness04#0", &trkjetsTwoSubJettiness04#0_, &b_trkjetsTwoSubJettiness04#0_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness04#0.index", trkjetsTwoSubJettiness04#0_index, &b_trkjetsTwoSubJettiness04#0_index);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness04#0.collectionID", trkjetsTwoSubJettiness04#0_collectionID, &b_trkjetsTwoSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness04", &trkjetsThreeSubJettiness04_, &b_trkjetsThreeSubJettiness04_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness04.tag", trkjetsThreeSubJettiness04_tag, &b_trkjetsThreeSubJettiness04_tag);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness04#0", &trkjetsThreeSubJettiness04#0_, &b_trkjetsThreeSubJettiness04#0_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness04#0.index", trkjetsThreeSubJettiness04#0_index, &b_trkjetsThreeSubJettiness04#0_index);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness04#0.collectionID", trkjetsThreeSubJettiness04#0_collectionID, &b_trkjetsThreeSubJettiness04#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04", &trksubjetsTrimmingTagged04_, &b_trksubjetsTrimmingTagged04_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04.subjets_begin", trksubjetsTrimmingTagged04_subjets_begin, &b_trksubjetsTrimmingTagged04_subjets_begin);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04.subjets_end", trksubjetsTrimmingTagged04_subjets_end, &b_trksubjetsTrimmingTagged04_subjets_end);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04#0", &trksubjetsTrimmingTagged04#0_, &b_trksubjetsTrimmingTagged04#0_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04#0.index", &trksubjetsTrimmingTagged04#0_index, &b_trksubjetsTrimmingTagged04#0_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04#0.collectionID", &trksubjetsTrimmingTagged04#0_collectionID, &b_trksubjetsTrimmingTagged04#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04#1", &trksubjetsTrimmingTagged04#1_, &b_trksubjetsTrimmingTagged04#1_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04#1.index", trksubjetsTrimmingTagged04#1_index, &b_trksubjetsTrimmingTagged04#1_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged04#1.collectionID", trksubjetsTrimmingTagged04#1_collectionID, &b_trksubjetsTrimmingTagged04#1_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged04", &trksubjetsPruningTagged04_, &b_trksubjetsPruningTagged04_);
   fChain->SetBranchAddress("trksubjetsPruningTagged04.subjets_begin", trksubjetsPruningTagged04_subjets_begin, &b_trksubjetsPruningTagged04_subjets_begin);
   fChain->SetBranchAddress("trksubjetsPruningTagged04.subjets_end", trksubjetsPruningTagged04_subjets_end, &b_trksubjetsPruningTagged04_subjets_end);
   fChain->SetBranchAddress("trksubjetsPruningTagged04#0", &trksubjetsPruningTagged04#0_, &b_trksubjetsPruningTagged04#0_);
   fChain->SetBranchAddress("trksubjetsPruningTagged04#0.index", &trksubjetsPruningTagged04#0_index, &b_trksubjetsPruningTagged04#0_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged04#0.collectionID", &trksubjetsPruningTagged04#0_collectionID, &b_trksubjetsPruningTagged04#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged04#1", &trksubjetsPruningTagged04#1_, &b_trksubjetsPruningTagged04#1_);
   fChain->SetBranchAddress("trksubjetsPruningTagged04#1.index", trksubjetsPruningTagged04#1_index, &b_trksubjetsPruningTagged04#1_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged04#1.collectionID", trksubjetsPruningTagged04#1_collectionID, &b_trksubjetsPruningTagged04#1_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04", &trksubjetsSoftDropTagged04_, &b_trksubjetsSoftDropTagged04_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04.subjets_begin", trksubjetsSoftDropTagged04_subjets_begin, &b_trksubjetsSoftDropTagged04_subjets_begin);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04.subjets_end", trksubjetsSoftDropTagged04_subjets_end, &b_trksubjetsSoftDropTagged04_subjets_end);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04#0", &trksubjetsSoftDropTagged04#0_, &b_trksubjetsSoftDropTagged04#0_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04#0.index", trksubjetsSoftDropTagged04#0_index, &b_trksubjetsSoftDropTagged04#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04#0.collectionID", trksubjetsSoftDropTagged04#0_collectionID, &b_trksubjetsSoftDropTagged04#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04#1", &trksubjetsSoftDropTagged04#1_, &b_trksubjetsSoftDropTagged04#1_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04#1.index", trksubjetsSoftDropTagged04#1_index, &b_trksubjetsSoftDropTagged04#1_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged04#1.collectionID", trksubjetsSoftDropTagged04#1_collectionID, &b_trksubjetsSoftDropTagged04#1_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimming04", &trksubjetsTrimming04_, &b_trksubjetsTrimming04_);
   fChain->SetBranchAddress("trksubjetsTrimming04.core.area", &trksubjetsTrimming04_core_area, &b_trksubjetsTrimming04_core_area);
   fChain->SetBranchAddress("trksubjetsTrimming04.core.bits", &trksubjetsTrimming04_core_bits, &b_trksubjetsTrimming04_core_bits);
   fChain->SetBranchAddress("trksubjetsTrimming04.core.p4.mass", &trksubjetsTrimming04_core_p4_mass, &b_trksubjetsTrimming04_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsTrimming04.core.p4.px", &trksubjetsTrimming04_core_p4_px, &b_trksubjetsTrimming04_core_p4_px);
   fChain->SetBranchAddress("trksubjetsTrimming04.core.p4.py", &trksubjetsTrimming04_core_p4_py, &b_trksubjetsTrimming04_core_p4_py);
   fChain->SetBranchAddress("trksubjetsTrimming04.core.p4.pz", &trksubjetsTrimming04_core_p4_pz, &b_trksubjetsTrimming04_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsTrimming04.particles_begin", &trksubjetsTrimming04_particles_begin, &b_trksubjetsTrimming04_particles_begin);
   fChain->SetBranchAddress("trksubjetsTrimming04.particles_end", &trksubjetsTrimming04_particles_end, &b_trksubjetsTrimming04_particles_end);
   fChain->SetBranchAddress("trksubjetsTrimming04#0", &trksubjetsTrimming04#0_, &b_trksubjetsTrimming04#0_);
   fChain->SetBranchAddress("trksubjetsTrimming04#0.index", &trksubjetsTrimming04#0_index, &b_trksubjetsTrimming04#0_index);
   fChain->SetBranchAddress("trksubjetsTrimming04#0.collectionID", &trksubjetsTrimming04#0_collectionID, &b_trksubjetsTrimming04#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruning04", &trksubjetsPruning04_, &b_trksubjetsPruning04_);
   fChain->SetBranchAddress("trksubjetsPruning04.core.area", &trksubjetsPruning04_core_area, &b_trksubjetsPruning04_core_area);
   fChain->SetBranchAddress("trksubjetsPruning04.core.bits", &trksubjetsPruning04_core_bits, &b_trksubjetsPruning04_core_bits);
   fChain->SetBranchAddress("trksubjetsPruning04.core.p4.mass", &trksubjetsPruning04_core_p4_mass, &b_trksubjetsPruning04_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsPruning04.core.p4.px", &trksubjetsPruning04_core_p4_px, &b_trksubjetsPruning04_core_p4_px);
   fChain->SetBranchAddress("trksubjetsPruning04.core.p4.py", &trksubjetsPruning04_core_p4_py, &b_trksubjetsPruning04_core_p4_py);
   fChain->SetBranchAddress("trksubjetsPruning04.core.p4.pz", &trksubjetsPruning04_core_p4_pz, &b_trksubjetsPruning04_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsPruning04.particles_begin", &trksubjetsPruning04_particles_begin, &b_trksubjetsPruning04_particles_begin);
   fChain->SetBranchAddress("trksubjetsPruning04.particles_end", &trksubjetsPruning04_particles_end, &b_trksubjetsPruning04_particles_end);
   fChain->SetBranchAddress("trksubjetsPruning04#0", &trksubjetsPruning04#0_, &b_trksubjetsPruning04#0_);
   fChain->SetBranchAddress("trksubjetsPruning04#0.index", &trksubjetsPruning04#0_index, &b_trksubjetsPruning04#0_index);
   fChain->SetBranchAddress("trksubjetsPruning04#0.collectionID", &trksubjetsPruning04#0_collectionID, &b_trksubjetsPruning04#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDrop04", &trksubjetsSoftDrop04_, &b_trksubjetsSoftDrop04_);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.core.area", trksubjetsSoftDrop04_core_area, &b_trksubjetsSoftDrop04_core_area);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.core.bits", trksubjetsSoftDrop04_core_bits, &b_trksubjetsSoftDrop04_core_bits);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.core.p4.mass", trksubjetsSoftDrop04_core_p4_mass, &b_trksubjetsSoftDrop04_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.core.p4.px", trksubjetsSoftDrop04_core_p4_px, &b_trksubjetsSoftDrop04_core_p4_px);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.core.p4.py", trksubjetsSoftDrop04_core_p4_py, &b_trksubjetsSoftDrop04_core_p4_py);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.core.p4.pz", trksubjetsSoftDrop04_core_p4_pz, &b_trksubjetsSoftDrop04_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.particles_begin", trksubjetsSoftDrop04_particles_begin, &b_trksubjetsSoftDrop04_particles_begin);
   fChain->SetBranchAddress("trksubjetsSoftDrop04.particles_end", trksubjetsSoftDrop04_particles_end, &b_trksubjetsSoftDrop04_particles_end);
   fChain->SetBranchAddress("trksubjetsSoftDrop04#0", &trksubjetsSoftDrop04#0_, &b_trksubjetsSoftDrop04#0_);
   fChain->SetBranchAddress("trksubjetsSoftDrop04#0.index", &trksubjetsSoftDrop04#0_index, &b_trksubjetsSoftDrop04#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDrop04#0.collectionID", &trksubjetsSoftDrop04#0_collectionID, &b_trksubjetsSoftDrop04#0_collectionID);
   fChain->SetBranchAddress("trkjets08", &trkjets08_, &b_trkjets08_);
   fChain->SetBranchAddress("trkjets08.core.area", trkjets08_core_area, &b_trkjets08_core_area);
   fChain->SetBranchAddress("trkjets08.core.bits", trkjets08_core_bits, &b_trkjets08_core_bits);
   fChain->SetBranchAddress("trkjets08.core.p4.mass", trkjets08_core_p4_mass, &b_trkjets08_core_p4_mass);
   fChain->SetBranchAddress("trkjets08.core.p4.px", trkjets08_core_p4_px, &b_trkjets08_core_p4_px);
   fChain->SetBranchAddress("trkjets08.core.p4.py", trkjets08_core_p4_py, &b_trkjets08_core_p4_py);
   fChain->SetBranchAddress("trkjets08.core.p4.pz", trkjets08_core_p4_pz, &b_trkjets08_core_p4_pz);
   fChain->SetBranchAddress("trkjets08.particles_begin", trkjets08_particles_begin, &b_trkjets08_particles_begin);
   fChain->SetBranchAddress("trkjets08.particles_end", trkjets08_particles_end, &b_trkjets08_particles_end);
   fChain->SetBranchAddress("trkjets08#0", &trkjets08#0_, &b_trkjets08#0_);
   fChain->SetBranchAddress("trkjets08#0.index", trkjets08#0_index, &b_trkjets08#0_index);
   fChain->SetBranchAddress("trkjets08#0.collectionID", trkjets08#0_collectionID, &b_trkjets08#0_collectionID);
   fChain->SetBranchAddress("trkjetsFlavor08", &trkjetsFlavor08_, &b_trkjetsFlavor08_);
   fChain->SetBranchAddress("trkjetsFlavor08.tag", trkjetsFlavor08_tag, &b_trkjetsFlavor08_tag);
   fChain->SetBranchAddress("trkjetsFlavor08#0", &trkjetsFlavor08#0_, &b_trkjetsFlavor08#0_);
   fChain->SetBranchAddress("trkjetsFlavor08#0.index", trkjetsFlavor08#0_index, &b_trkjetsFlavor08#0_index);
   fChain->SetBranchAddress("trkjetsFlavor08#0.collectionID", trkjetsFlavor08#0_collectionID, &b_trkjetsFlavor08#0_collectionID);
   fChain->SetBranchAddress("trkbTags08", &trkbTags08_, &b_trkbTags08_);
   fChain->SetBranchAddress("trkbTags08.tag", trkbTags08_tag, &b_trkbTags08_tag);
   fChain->SetBranchAddress("trkbTags08#0", &trkbTags08#0_, &b_trkbTags08#0_);
   fChain->SetBranchAddress("trkbTags08#0.index", trkbTags08#0_index, &b_trkbTags08#0_index);
   fChain->SetBranchAddress("trkbTags08#0.collectionID", trkbTags08#0_collectionID, &b_trkbTags08#0_collectionID);
   fChain->SetBranchAddress("trkcTags08", &trkcTags08_, &b_trkcTags08_);
   fChain->SetBranchAddress("trkcTags08.tag", trkcTags08_tag, &b_trkcTags08_tag);
   fChain->SetBranchAddress("trkcTags08#0", &trkcTags08#0_, &b_trkcTags08#0_);
   fChain->SetBranchAddress("trkcTags08#0.index", trkcTags08#0_index, &b_trkcTags08#0_index);
   fChain->SetBranchAddress("trkcTags08#0.collectionID", trkcTags08#0_collectionID, &b_trkcTags08#0_collectionID);
   fChain->SetBranchAddress("trktauTags08", &trktauTags08_, &b_trktauTags08_);
   fChain->SetBranchAddress("trktauTags08.tag", trktauTags08_tag, &b_trktauTags08_tag);
   fChain->SetBranchAddress("trktauTags08#0", &trktauTags08#0_, &b_trktauTags08#0_);
   fChain->SetBranchAddress("trktauTags08#0.index", trktauTags08#0_index, &b_trktauTags08#0_index);
   fChain->SetBranchAddress("trktauTags08#0.collectionID", trktauTags08#0_collectionID, &b_trktauTags08#0_collectionID);
   fChain->SetBranchAddress("trkjetParts08", &trkjetParts08_, &b_trkjetParts08_);
   fChain->SetBranchAddress("trkjetParts08.core.bits", trkjetParts08_core_bits, &b_trkjetParts08_core_bits);
   fChain->SetBranchAddress("trkjetParts08.core.charge", trkjetParts08_core_charge, &b_trkjetParts08_core_charge);
   fChain->SetBranchAddress("trkjetParts08.core.p4.mass", trkjetParts08_core_p4_mass, &b_trkjetParts08_core_p4_mass);
   fChain->SetBranchAddress("trkjetParts08.core.p4.px", trkjetParts08_core_p4_px, &b_trkjetParts08_core_p4_px);
   fChain->SetBranchAddress("trkjetParts08.core.p4.py", trkjetParts08_core_p4_py, &b_trkjetParts08_core_p4_py);
   fChain->SetBranchAddress("trkjetParts08.core.p4.pz", trkjetParts08_core_p4_pz, &b_trkjetParts08_core_p4_pz);
   fChain->SetBranchAddress("trkjetParts08.core.pdgId", trkjetParts08_core_pdgId, &b_trkjetParts08_core_pdgId);
   fChain->SetBranchAddress("trkjetParts08.core.status", trkjetParts08_core_status, &b_trkjetParts08_core_status);
   fChain->SetBranchAddress("trkjetParts08.core.vertex.x", trkjetParts08_core_vertex_x, &b_trkjetParts08_core_vertex_x);
   fChain->SetBranchAddress("trkjetParts08.core.vertex.y", trkjetParts08_core_vertex_y, &b_trkjetParts08_core_vertex_y);
   fChain->SetBranchAddress("trkjetParts08.core.vertex.z", trkjetParts08_core_vertex_z, &b_trkjetParts08_core_vertex_z);
   fChain->SetBranchAddress("trkjetParts08.tracks_begin", trkjetParts08_tracks_begin, &b_trkjetParts08_tracks_begin);
   fChain->SetBranchAddress("trkjetParts08.tracks_end", trkjetParts08_tracks_end, &b_trkjetParts08_tracks_end);
   fChain->SetBranchAddress("trkjetParts08.clusters_begin", trkjetParts08_clusters_begin, &b_trkjetParts08_clusters_begin);
   fChain->SetBranchAddress("trkjetParts08.clusters_end", trkjetParts08_clusters_end, &b_trkjetParts08_clusters_end);
   fChain->SetBranchAddress("trkjetParts08#0", &trkjetParts08#0_, &b_trkjetParts08#0_);
   fChain->SetBranchAddress("trkjetParts08#0.index", &trkjetParts08#0_index, &b_trkjetParts08#0_index);
   fChain->SetBranchAddress("trkjetParts08#0.collectionID", &trkjetParts08#0_collectionID, &b_trkjetParts08#0_collectionID);
   fChain->SetBranchAddress("trkjetParts08#1", &trkjetParts08#1_, &b_trkjetParts08#1_);
   fChain->SetBranchAddress("trkjetParts08#1.index", &trkjetParts08#1_index, &b_trkjetParts08#1_index);
   fChain->SetBranchAddress("trkjetParts08#1.collectionID", &trkjetParts08#1_collectionID, &b_trkjetParts08#1_collectionID);
   fChain->SetBranchAddress("trkjetsOneSubJettiness08", &trkjetsOneSubJettiness08_, &b_trkjetsOneSubJettiness08_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness08.tag", trkjetsOneSubJettiness08_tag, &b_trkjetsOneSubJettiness08_tag);
   fChain->SetBranchAddress("trkjetsOneSubJettiness08#0", &trkjetsOneSubJettiness08#0_, &b_trkjetsOneSubJettiness08#0_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness08#0.index", trkjetsOneSubJettiness08#0_index, &b_trkjetsOneSubJettiness08#0_index);
   fChain->SetBranchAddress("trkjetsOneSubJettiness08#0.collectionID", trkjetsOneSubJettiness08#0_collectionID, &b_trkjetsOneSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness08", &trkjetsTwoSubJettiness08_, &b_trkjetsTwoSubJettiness08_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness08.tag", trkjetsTwoSubJettiness08_tag, &b_trkjetsTwoSubJettiness08_tag);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness08#0", &trkjetsTwoSubJettiness08#0_, &b_trkjetsTwoSubJettiness08#0_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness08#0.index", trkjetsTwoSubJettiness08#0_index, &b_trkjetsTwoSubJettiness08#0_index);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness08#0.collectionID", trkjetsTwoSubJettiness08#0_collectionID, &b_trkjetsTwoSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness08", &trkjetsThreeSubJettiness08_, &b_trkjetsThreeSubJettiness08_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness08.tag", trkjetsThreeSubJettiness08_tag, &b_trkjetsThreeSubJettiness08_tag);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness08#0", &trkjetsThreeSubJettiness08#0_, &b_trkjetsThreeSubJettiness08#0_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness08#0.index", trkjetsThreeSubJettiness08#0_index, &b_trkjetsThreeSubJettiness08#0_index);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness08#0.collectionID", trkjetsThreeSubJettiness08#0_collectionID, &b_trkjetsThreeSubJettiness08#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08", &trksubjetsTrimmingTagged08_, &b_trksubjetsTrimmingTagged08_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08.subjets_begin", trksubjetsTrimmingTagged08_subjets_begin, &b_trksubjetsTrimmingTagged08_subjets_begin);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08.subjets_end", trksubjetsTrimmingTagged08_subjets_end, &b_trksubjetsTrimmingTagged08_subjets_end);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08#0", &trksubjetsTrimmingTagged08#0_, &b_trksubjetsTrimmingTagged08#0_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08#0.index", &trksubjetsTrimmingTagged08#0_index, &b_trksubjetsTrimmingTagged08#0_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08#0.collectionID", &trksubjetsTrimmingTagged08#0_collectionID, &b_trksubjetsTrimmingTagged08#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08#1", &trksubjetsTrimmingTagged08#1_, &b_trksubjetsTrimmingTagged08#1_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08#1.index", trksubjetsTrimmingTagged08#1_index, &b_trksubjetsTrimmingTagged08#1_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged08#1.collectionID", trksubjetsTrimmingTagged08#1_collectionID, &b_trksubjetsTrimmingTagged08#1_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged08", &trksubjetsPruningTagged08_, &b_trksubjetsPruningTagged08_);
   fChain->SetBranchAddress("trksubjetsPruningTagged08.subjets_begin", trksubjetsPruningTagged08_subjets_begin, &b_trksubjetsPruningTagged08_subjets_begin);
   fChain->SetBranchAddress("trksubjetsPruningTagged08.subjets_end", trksubjetsPruningTagged08_subjets_end, &b_trksubjetsPruningTagged08_subjets_end);
   fChain->SetBranchAddress("trksubjetsPruningTagged08#0", &trksubjetsPruningTagged08#0_, &b_trksubjetsPruningTagged08#0_);
   fChain->SetBranchAddress("trksubjetsPruningTagged08#0.index", &trksubjetsPruningTagged08#0_index, &b_trksubjetsPruningTagged08#0_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged08#0.collectionID", &trksubjetsPruningTagged08#0_collectionID, &b_trksubjetsPruningTagged08#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged08#1", &trksubjetsPruningTagged08#1_, &b_trksubjetsPruningTagged08#1_);
   fChain->SetBranchAddress("trksubjetsPruningTagged08#1.index", trksubjetsPruningTagged08#1_index, &b_trksubjetsPruningTagged08#1_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged08#1.collectionID", trksubjetsPruningTagged08#1_collectionID, &b_trksubjetsPruningTagged08#1_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08", &trksubjetsSoftDropTagged08_, &b_trksubjetsSoftDropTagged08_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08.subjets_begin", trksubjetsSoftDropTagged08_subjets_begin, &b_trksubjetsSoftDropTagged08_subjets_begin);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08.subjets_end", trksubjetsSoftDropTagged08_subjets_end, &b_trksubjetsSoftDropTagged08_subjets_end);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08#0", &trksubjetsSoftDropTagged08#0_, &b_trksubjetsSoftDropTagged08#0_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08#0.index", trksubjetsSoftDropTagged08#0_index, &b_trksubjetsSoftDropTagged08#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08#0.collectionID", trksubjetsSoftDropTagged08#0_collectionID, &b_trksubjetsSoftDropTagged08#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08#1", &trksubjetsSoftDropTagged08#1_, &b_trksubjetsSoftDropTagged08#1_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08#1.index", trksubjetsSoftDropTagged08#1_index, &b_trksubjetsSoftDropTagged08#1_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged08#1.collectionID", trksubjetsSoftDropTagged08#1_collectionID, &b_trksubjetsSoftDropTagged08#1_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimming08", &trksubjetsTrimming08_, &b_trksubjetsTrimming08_);
   fChain->SetBranchAddress("trksubjetsTrimming08.core.area", &trksubjetsTrimming08_core_area, &b_trksubjetsTrimming08_core_area);
   fChain->SetBranchAddress("trksubjetsTrimming08.core.bits", &trksubjetsTrimming08_core_bits, &b_trksubjetsTrimming08_core_bits);
   fChain->SetBranchAddress("trksubjetsTrimming08.core.p4.mass", &trksubjetsTrimming08_core_p4_mass, &b_trksubjetsTrimming08_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsTrimming08.core.p4.px", &trksubjetsTrimming08_core_p4_px, &b_trksubjetsTrimming08_core_p4_px);
   fChain->SetBranchAddress("trksubjetsTrimming08.core.p4.py", &trksubjetsTrimming08_core_p4_py, &b_trksubjetsTrimming08_core_p4_py);
   fChain->SetBranchAddress("trksubjetsTrimming08.core.p4.pz", &trksubjetsTrimming08_core_p4_pz, &b_trksubjetsTrimming08_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsTrimming08.particles_begin", &trksubjetsTrimming08_particles_begin, &b_trksubjetsTrimming08_particles_begin);
   fChain->SetBranchAddress("trksubjetsTrimming08.particles_end", &trksubjetsTrimming08_particles_end, &b_trksubjetsTrimming08_particles_end);
   fChain->SetBranchAddress("trksubjetsTrimming08#0", &trksubjetsTrimming08#0_, &b_trksubjetsTrimming08#0_);
   fChain->SetBranchAddress("trksubjetsTrimming08#0.index", &trksubjetsTrimming08#0_index, &b_trksubjetsTrimming08#0_index);
   fChain->SetBranchAddress("trksubjetsTrimming08#0.collectionID", &trksubjetsTrimming08#0_collectionID, &b_trksubjetsTrimming08#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruning08", &trksubjetsPruning08_, &b_trksubjetsPruning08_);
   fChain->SetBranchAddress("trksubjetsPruning08.core.area", &trksubjetsPruning08_core_area, &b_trksubjetsPruning08_core_area);
   fChain->SetBranchAddress("trksubjetsPruning08.core.bits", &trksubjetsPruning08_core_bits, &b_trksubjetsPruning08_core_bits);
   fChain->SetBranchAddress("trksubjetsPruning08.core.p4.mass", &trksubjetsPruning08_core_p4_mass, &b_trksubjetsPruning08_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsPruning08.core.p4.px", &trksubjetsPruning08_core_p4_px, &b_trksubjetsPruning08_core_p4_px);
   fChain->SetBranchAddress("trksubjetsPruning08.core.p4.py", &trksubjetsPruning08_core_p4_py, &b_trksubjetsPruning08_core_p4_py);
   fChain->SetBranchAddress("trksubjetsPruning08.core.p4.pz", &trksubjetsPruning08_core_p4_pz, &b_trksubjetsPruning08_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsPruning08.particles_begin", &trksubjetsPruning08_particles_begin, &b_trksubjetsPruning08_particles_begin);
   fChain->SetBranchAddress("trksubjetsPruning08.particles_end", &trksubjetsPruning08_particles_end, &b_trksubjetsPruning08_particles_end);
   fChain->SetBranchAddress("trksubjetsPruning08#0", &trksubjetsPruning08#0_, &b_trksubjetsPruning08#0_);
   fChain->SetBranchAddress("trksubjetsPruning08#0.index", &trksubjetsPruning08#0_index, &b_trksubjetsPruning08#0_index);
   fChain->SetBranchAddress("trksubjetsPruning08#0.collectionID", &trksubjetsPruning08#0_collectionID, &b_trksubjetsPruning08#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDrop08", &trksubjetsSoftDrop08_, &b_trksubjetsSoftDrop08_);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.core.area", trksubjetsSoftDrop08_core_area, &b_trksubjetsSoftDrop08_core_area);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.core.bits", trksubjetsSoftDrop08_core_bits, &b_trksubjetsSoftDrop08_core_bits);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.core.p4.mass", trksubjetsSoftDrop08_core_p4_mass, &b_trksubjetsSoftDrop08_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.core.p4.px", trksubjetsSoftDrop08_core_p4_px, &b_trksubjetsSoftDrop08_core_p4_px);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.core.p4.py", trksubjetsSoftDrop08_core_p4_py, &b_trksubjetsSoftDrop08_core_p4_py);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.core.p4.pz", trksubjetsSoftDrop08_core_p4_pz, &b_trksubjetsSoftDrop08_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.particles_begin", trksubjetsSoftDrop08_particles_begin, &b_trksubjetsSoftDrop08_particles_begin);
   fChain->SetBranchAddress("trksubjetsSoftDrop08.particles_end", trksubjetsSoftDrop08_particles_end, &b_trksubjetsSoftDrop08_particles_end);
   fChain->SetBranchAddress("trksubjetsSoftDrop08#0", &trksubjetsSoftDrop08#0_, &b_trksubjetsSoftDrop08#0_);
   fChain->SetBranchAddress("trksubjetsSoftDrop08#0.index", &trksubjetsSoftDrop08#0_index, &b_trksubjetsSoftDrop08#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDrop08#0.collectionID", &trksubjetsSoftDrop08#0_collectionID, &b_trksubjetsSoftDrop08#0_collectionID);
   fChain->SetBranchAddress("trkjets15", &trkjets15_, &b_trkjets15_);
   fChain->SetBranchAddress("trkjets15.core.area", trkjets15_core_area, &b_trkjets15_core_area);
   fChain->SetBranchAddress("trkjets15.core.bits", trkjets15_core_bits, &b_trkjets15_core_bits);
   fChain->SetBranchAddress("trkjets15.core.p4.mass", trkjets15_core_p4_mass, &b_trkjets15_core_p4_mass);
   fChain->SetBranchAddress("trkjets15.core.p4.px", trkjets15_core_p4_px, &b_trkjets15_core_p4_px);
   fChain->SetBranchAddress("trkjets15.core.p4.py", trkjets15_core_p4_py, &b_trkjets15_core_p4_py);
   fChain->SetBranchAddress("trkjets15.core.p4.pz", trkjets15_core_p4_pz, &b_trkjets15_core_p4_pz);
   fChain->SetBranchAddress("trkjets15.particles_begin", trkjets15_particles_begin, &b_trkjets15_particles_begin);
   fChain->SetBranchAddress("trkjets15.particles_end", trkjets15_particles_end, &b_trkjets15_particles_end);
   fChain->SetBranchAddress("trkjets15#0", &trkjets15#0_, &b_trkjets15#0_);
   fChain->SetBranchAddress("trkjets15#0.index", trkjets15#0_index, &b_trkjets15#0_index);
   fChain->SetBranchAddress("trkjets15#0.collectionID", trkjets15#0_collectionID, &b_trkjets15#0_collectionID);
   fChain->SetBranchAddress("trkjetsFlavor15", &trkjetsFlavor15_, &b_trkjetsFlavor15_);
   fChain->SetBranchAddress("trkjetsFlavor15.tag", trkjetsFlavor15_tag, &b_trkjetsFlavor15_tag);
   fChain->SetBranchAddress("trkjetsFlavor15#0", &trkjetsFlavor15#0_, &b_trkjetsFlavor15#0_);
   fChain->SetBranchAddress("trkjetsFlavor15#0.index", trkjetsFlavor15#0_index, &b_trkjetsFlavor15#0_index);
   fChain->SetBranchAddress("trkjetsFlavor15#0.collectionID", trkjetsFlavor15#0_collectionID, &b_trkjetsFlavor15#0_collectionID);
   fChain->SetBranchAddress("trkbTags15", &trkbTags15_, &b_trkbTags15_);
   fChain->SetBranchAddress("trkbTags15.tag", trkbTags15_tag, &b_trkbTags15_tag);
   fChain->SetBranchAddress("trkbTags15#0", &trkbTags15#0_, &b_trkbTags15#0_);
   fChain->SetBranchAddress("trkbTags15#0.index", trkbTags15#0_index, &b_trkbTags15#0_index);
   fChain->SetBranchAddress("trkbTags15#0.collectionID", trkbTags15#0_collectionID, &b_trkbTags15#0_collectionID);
   fChain->SetBranchAddress("trkcTags15", &trkcTags15_, &b_trkcTags15_);
   fChain->SetBranchAddress("trkcTags15.tag", trkcTags15_tag, &b_trkcTags15_tag);
   fChain->SetBranchAddress("trkcTags15#0", &trkcTags15#0_, &b_trkcTags15#0_);
   fChain->SetBranchAddress("trkcTags15#0.index", trkcTags15#0_index, &b_trkcTags15#0_index);
   fChain->SetBranchAddress("trkcTags15#0.collectionID", trkcTags15#0_collectionID, &b_trkcTags15#0_collectionID);
   fChain->SetBranchAddress("trktauTags15", &trktauTags15_, &b_trktauTags15_);
   fChain->SetBranchAddress("trktauTags15.tag", trktauTags15_tag, &b_trktauTags15_tag);
   fChain->SetBranchAddress("trktauTags15#0", &trktauTags15#0_, &b_trktauTags15#0_);
   fChain->SetBranchAddress("trktauTags15#0.index", trktauTags15#0_index, &b_trktauTags15#0_index);
   fChain->SetBranchAddress("trktauTags15#0.collectionID", trktauTags15#0_collectionID, &b_trktauTags15#0_collectionID);
   fChain->SetBranchAddress("trkjetParts15", &trkjetParts15_, &b_trkjetParts15_);
   fChain->SetBranchAddress("trkjetParts15.core.bits", trkjetParts15_core_bits, &b_trkjetParts15_core_bits);
   fChain->SetBranchAddress("trkjetParts15.core.charge", trkjetParts15_core_charge, &b_trkjetParts15_core_charge);
   fChain->SetBranchAddress("trkjetParts15.core.p4.mass", trkjetParts15_core_p4_mass, &b_trkjetParts15_core_p4_mass);
   fChain->SetBranchAddress("trkjetParts15.core.p4.px", trkjetParts15_core_p4_px, &b_trkjetParts15_core_p4_px);
   fChain->SetBranchAddress("trkjetParts15.core.p4.py", trkjetParts15_core_p4_py, &b_trkjetParts15_core_p4_py);
   fChain->SetBranchAddress("trkjetParts15.core.p4.pz", trkjetParts15_core_p4_pz, &b_trkjetParts15_core_p4_pz);
   fChain->SetBranchAddress("trkjetParts15.core.pdgId", trkjetParts15_core_pdgId, &b_trkjetParts15_core_pdgId);
   fChain->SetBranchAddress("trkjetParts15.core.status", trkjetParts15_core_status, &b_trkjetParts15_core_status);
   fChain->SetBranchAddress("trkjetParts15.core.vertex.x", trkjetParts15_core_vertex_x, &b_trkjetParts15_core_vertex_x);
   fChain->SetBranchAddress("trkjetParts15.core.vertex.y", trkjetParts15_core_vertex_y, &b_trkjetParts15_core_vertex_y);
   fChain->SetBranchAddress("trkjetParts15.core.vertex.z", trkjetParts15_core_vertex_z, &b_trkjetParts15_core_vertex_z);
   fChain->SetBranchAddress("trkjetParts15.tracks_begin", trkjetParts15_tracks_begin, &b_trkjetParts15_tracks_begin);
   fChain->SetBranchAddress("trkjetParts15.tracks_end", trkjetParts15_tracks_end, &b_trkjetParts15_tracks_end);
   fChain->SetBranchAddress("trkjetParts15.clusters_begin", trkjetParts15_clusters_begin, &b_trkjetParts15_clusters_begin);
   fChain->SetBranchAddress("trkjetParts15.clusters_end", trkjetParts15_clusters_end, &b_trkjetParts15_clusters_end);
   fChain->SetBranchAddress("trkjetParts15#0", &trkjetParts15#0_, &b_trkjetParts15#0_);
   fChain->SetBranchAddress("trkjetParts15#0.index", &trkjetParts15#0_index, &b_trkjetParts15#0_index);
   fChain->SetBranchAddress("trkjetParts15#0.collectionID", &trkjetParts15#0_collectionID, &b_trkjetParts15#0_collectionID);
   fChain->SetBranchAddress("trkjetParts15#1", &trkjetParts15#1_, &b_trkjetParts15#1_);
   fChain->SetBranchAddress("trkjetParts15#1.index", &trkjetParts15#1_index, &b_trkjetParts15#1_index);
   fChain->SetBranchAddress("trkjetParts15#1.collectionID", &trkjetParts15#1_collectionID, &b_trkjetParts15#1_collectionID);
   fChain->SetBranchAddress("trkjetsOneSubJettiness15", &trkjetsOneSubJettiness15_, &b_trkjetsOneSubJettiness15_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness15.tag", trkjetsOneSubJettiness15_tag, &b_trkjetsOneSubJettiness15_tag);
   fChain->SetBranchAddress("trkjetsOneSubJettiness15#0", &trkjetsOneSubJettiness15#0_, &b_trkjetsOneSubJettiness15#0_);
   fChain->SetBranchAddress("trkjetsOneSubJettiness15#0.index", trkjetsOneSubJettiness15#0_index, &b_trkjetsOneSubJettiness15#0_index);
   fChain->SetBranchAddress("trkjetsOneSubJettiness15#0.collectionID", trkjetsOneSubJettiness15#0_collectionID, &b_trkjetsOneSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness15", &trkjetsTwoSubJettiness15_, &b_trkjetsTwoSubJettiness15_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness15.tag", trkjetsTwoSubJettiness15_tag, &b_trkjetsTwoSubJettiness15_tag);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness15#0", &trkjetsTwoSubJettiness15#0_, &b_trkjetsTwoSubJettiness15#0_);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness15#0.index", trkjetsTwoSubJettiness15#0_index, &b_trkjetsTwoSubJettiness15#0_index);
   fChain->SetBranchAddress("trkjetsTwoSubJettiness15#0.collectionID", trkjetsTwoSubJettiness15#0_collectionID, &b_trkjetsTwoSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness15", &trkjetsThreeSubJettiness15_, &b_trkjetsThreeSubJettiness15_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness15.tag", trkjetsThreeSubJettiness15_tag, &b_trkjetsThreeSubJettiness15_tag);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness15#0", &trkjetsThreeSubJettiness15#0_, &b_trkjetsThreeSubJettiness15#0_);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness15#0.index", trkjetsThreeSubJettiness15#0_index, &b_trkjetsThreeSubJettiness15#0_index);
   fChain->SetBranchAddress("trkjetsThreeSubJettiness15#0.collectionID", trkjetsThreeSubJettiness15#0_collectionID, &b_trkjetsThreeSubJettiness15#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15", &trksubjetsTrimmingTagged15_, &b_trksubjetsTrimmingTagged15_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15.subjets_begin", trksubjetsTrimmingTagged15_subjets_begin, &b_trksubjetsTrimmingTagged15_subjets_begin);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15.subjets_end", trksubjetsTrimmingTagged15_subjets_end, &b_trksubjetsTrimmingTagged15_subjets_end);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15#0", &trksubjetsTrimmingTagged15#0_, &b_trksubjetsTrimmingTagged15#0_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15#0.index", &trksubjetsTrimmingTagged15#0_index, &b_trksubjetsTrimmingTagged15#0_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15#0.collectionID", &trksubjetsTrimmingTagged15#0_collectionID, &b_trksubjetsTrimmingTagged15#0_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15#1", &trksubjetsTrimmingTagged15#1_, &b_trksubjetsTrimmingTagged15#1_);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15#1.index", trksubjetsTrimmingTagged15#1_index, &b_trksubjetsTrimmingTagged15#1_index);
   fChain->SetBranchAddress("trksubjetsTrimmingTagged15#1.collectionID", trksubjetsTrimmingTagged15#1_collectionID, &b_trksubjetsTrimmingTagged15#1_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged15", &trksubjetsPruningTagged15_, &b_trksubjetsPruningTagged15_);
   fChain->SetBranchAddress("trksubjetsPruningTagged15.subjets_begin", trksubjetsPruningTagged15_subjets_begin, &b_trksubjetsPruningTagged15_subjets_begin);
   fChain->SetBranchAddress("trksubjetsPruningTagged15.subjets_end", trksubjetsPruningTagged15_subjets_end, &b_trksubjetsPruningTagged15_subjets_end);
   fChain->SetBranchAddress("trksubjetsPruningTagged15#0", &trksubjetsPruningTagged15#0_, &b_trksubjetsPruningTagged15#0_);
   fChain->SetBranchAddress("trksubjetsPruningTagged15#0.index", &trksubjetsPruningTagged15#0_index, &b_trksubjetsPruningTagged15#0_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged15#0.collectionID", &trksubjetsPruningTagged15#0_collectionID, &b_trksubjetsPruningTagged15#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruningTagged15#1", &trksubjetsPruningTagged15#1_, &b_trksubjetsPruningTagged15#1_);
   fChain->SetBranchAddress("trksubjetsPruningTagged15#1.index", trksubjetsPruningTagged15#1_index, &b_trksubjetsPruningTagged15#1_index);
   fChain->SetBranchAddress("trksubjetsPruningTagged15#1.collectionID", trksubjetsPruningTagged15#1_collectionID, &b_trksubjetsPruningTagged15#1_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15", &trksubjetsSoftDropTagged15_, &b_trksubjetsSoftDropTagged15_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15.subjets_begin", trksubjetsSoftDropTagged15_subjets_begin, &b_trksubjetsSoftDropTagged15_subjets_begin);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15.subjets_end", trksubjetsSoftDropTagged15_subjets_end, &b_trksubjetsSoftDropTagged15_subjets_end);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15#0", &trksubjetsSoftDropTagged15#0_, &b_trksubjetsSoftDropTagged15#0_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15#0.index", trksubjetsSoftDropTagged15#0_index, &b_trksubjetsSoftDropTagged15#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15#0.collectionID", trksubjetsSoftDropTagged15#0_collectionID, &b_trksubjetsSoftDropTagged15#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15#1", &trksubjetsSoftDropTagged15#1_, &b_trksubjetsSoftDropTagged15#1_);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15#1.index", trksubjetsSoftDropTagged15#1_index, &b_trksubjetsSoftDropTagged15#1_index);
   fChain->SetBranchAddress("trksubjetsSoftDropTagged15#1.collectionID", trksubjetsSoftDropTagged15#1_collectionID, &b_trksubjetsSoftDropTagged15#1_collectionID);
   fChain->SetBranchAddress("trksubjetsTrimming15", &trksubjetsTrimming15_, &b_trksubjetsTrimming15_);
   fChain->SetBranchAddress("trksubjetsTrimming15.core.area", &trksubjetsTrimming15_core_area, &b_trksubjetsTrimming15_core_area);
   fChain->SetBranchAddress("trksubjetsTrimming15.core.bits", &trksubjetsTrimming15_core_bits, &b_trksubjetsTrimming15_core_bits);
   fChain->SetBranchAddress("trksubjetsTrimming15.core.p4.mass", &trksubjetsTrimming15_core_p4_mass, &b_trksubjetsTrimming15_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsTrimming15.core.p4.px", &trksubjetsTrimming15_core_p4_px, &b_trksubjetsTrimming15_core_p4_px);
   fChain->SetBranchAddress("trksubjetsTrimming15.core.p4.py", &trksubjetsTrimming15_core_p4_py, &b_trksubjetsTrimming15_core_p4_py);
   fChain->SetBranchAddress("trksubjetsTrimming15.core.p4.pz", &trksubjetsTrimming15_core_p4_pz, &b_trksubjetsTrimming15_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsTrimming15.particles_begin", &trksubjetsTrimming15_particles_begin, &b_trksubjetsTrimming15_particles_begin);
   fChain->SetBranchAddress("trksubjetsTrimming15.particles_end", &trksubjetsTrimming15_particles_end, &b_trksubjetsTrimming15_particles_end);
   fChain->SetBranchAddress("trksubjetsTrimming15#0", &trksubjetsTrimming15#0_, &b_trksubjetsTrimming15#0_);
   fChain->SetBranchAddress("trksubjetsTrimming15#0.index", &trksubjetsTrimming15#0_index, &b_trksubjetsTrimming15#0_index);
   fChain->SetBranchAddress("trksubjetsTrimming15#0.collectionID", &trksubjetsTrimming15#0_collectionID, &b_trksubjetsTrimming15#0_collectionID);
   fChain->SetBranchAddress("trksubjetsPruning15", &trksubjetsPruning15_, &b_trksubjetsPruning15_);
   fChain->SetBranchAddress("trksubjetsPruning15.core.area", &trksubjetsPruning15_core_area, &b_trksubjetsPruning15_core_area);
   fChain->SetBranchAddress("trksubjetsPruning15.core.bits", &trksubjetsPruning15_core_bits, &b_trksubjetsPruning15_core_bits);
   fChain->SetBranchAddress("trksubjetsPruning15.core.p4.mass", &trksubjetsPruning15_core_p4_mass, &b_trksubjetsPruning15_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsPruning15.core.p4.px", &trksubjetsPruning15_core_p4_px, &b_trksubjetsPruning15_core_p4_px);
   fChain->SetBranchAddress("trksubjetsPruning15.core.p4.py", &trksubjetsPruning15_core_p4_py, &b_trksubjetsPruning15_core_p4_py);
   fChain->SetBranchAddress("trksubjetsPruning15.core.p4.pz", &trksubjetsPruning15_core_p4_pz, &b_trksubjetsPruning15_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsPruning15.particles_begin", &trksubjetsPruning15_particles_begin, &b_trksubjetsPruning15_particles_begin);
   fChain->SetBranchAddress("trksubjetsPruning15.particles_end", &trksubjetsPruning15_particles_end, &b_trksubjetsPruning15_particles_end);
   fChain->SetBranchAddress("trksubjetsPruning15#0", &trksubjetsPruning15#0_, &b_trksubjetsPruning15#0_);
   fChain->SetBranchAddress("trksubjetsPruning15#0.index", &trksubjetsPruning15#0_index, &b_trksubjetsPruning15#0_index);
   fChain->SetBranchAddress("trksubjetsPruning15#0.collectionID", &trksubjetsPruning15#0_collectionID, &b_trksubjetsPruning15#0_collectionID);
   fChain->SetBranchAddress("trksubjetsSoftDrop15", &trksubjetsSoftDrop15_, &b_trksubjetsSoftDrop15_);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.core.area", trksubjetsSoftDrop15_core_area, &b_trksubjetsSoftDrop15_core_area);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.core.bits", trksubjetsSoftDrop15_core_bits, &b_trksubjetsSoftDrop15_core_bits);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.core.p4.mass", trksubjetsSoftDrop15_core_p4_mass, &b_trksubjetsSoftDrop15_core_p4_mass);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.core.p4.px", trksubjetsSoftDrop15_core_p4_px, &b_trksubjetsSoftDrop15_core_p4_px);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.core.p4.py", trksubjetsSoftDrop15_core_p4_py, &b_trksubjetsSoftDrop15_core_p4_py);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.core.p4.pz", trksubjetsSoftDrop15_core_p4_pz, &b_trksubjetsSoftDrop15_core_p4_pz);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.particles_begin", trksubjetsSoftDrop15_particles_begin, &b_trksubjetsSoftDrop15_particles_begin);
   fChain->SetBranchAddress("trksubjetsSoftDrop15.particles_end", trksubjetsSoftDrop15_particles_end, &b_trksubjetsSoftDrop15_particles_end);
   fChain->SetBranchAddress("trksubjetsSoftDrop15#0", &trksubjetsSoftDrop15#0_, &b_trksubjetsSoftDrop15#0_);
   fChain->SetBranchAddress("trksubjetsSoftDrop15#0.index", &trksubjetsSoftDrop15#0_index, &b_trksubjetsSoftDrop15#0_index);
   fChain->SetBranchAddress("trksubjetsSoftDrop15#0.collectionID", &trksubjetsSoftDrop15#0_collectionID, &b_trksubjetsSoftDrop15#0_collectionID);
   fChain->SetBranchAddress("met", &met_, &b_met_);
   fChain->SetBranchAddress("met.magnitude", met_magnitude, &b_met_magnitude);
   fChain->SetBranchAddress("met.phi", met_phi, &b_met_phi);
   fChain->SetBranchAddress("met.scalarSum", met_scalarSum, &b_met_scalarSum);
   Notify();
}

Bool_t events::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void events::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t events::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef events_cxx
