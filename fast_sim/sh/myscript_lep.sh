#!/bin/bash

# root "./code/lepton_study/BG_lep.cc(\"W+jets\")"<<-EOF
# .q
# EOF
root -q "./code/lepton_study/BG_lep.cc(\"W+jets\")"
root -q "./code/lepton_study/BG_lep.cc+(\"Z+jets\")"
root -q "./code/lepton_study/BG_lep.cc+(\"ttbar\")"
root -q "./code/lepton_study/BG_lep.cc+(\"topsingle\")"
root -q ./code/lepton_study/signal_lep.cc+
root -q ./code/lepton_study/plots_lep.cc+
