#!/bin/bash
# scp BG_kin_sel.cc signal_kin_sel.cc plots_kin_sel.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/code/dyn/
root -q "BG_kin_sel.cc+(\"W+jets\")"
root -q "BG_kin_sel.cc+(\"Z+jets\")"
root -q "BG_kin_sel.cc+(\"ttbar\")"
root -q "BG_kin_sel.cc+(\"topsingle\")"
root -q signal_kin_sel.cc+
root -q "BG_kin_sel.cc+(\"multijets\")"
root -q -b plots_kin_sel.cc+
