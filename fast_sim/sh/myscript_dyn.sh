#!/bin/bash
root -q -l "./code/dyn/BG_dyn_paper.cc(\"W+jets\")"
root -q -l "./code/dyn/BG_dyn_paper.cc(\"Z+jets\")"
root -q -l "./code/dyn/BG_dyn_paper.cc(\"ttbar\")"
root -q -l "./code/dyn/BG_dyn_paper.cc(\"topsingle\")"
root -q -l "./code/dyn/BG_dyn_paper.cc(\"multijets\")"
root -q -l ./code/dyn/signal_dyn_paper.cc
root -q -l -b ./code/dyn/plots_dyn_paper_add.cc
