#!/bin/bash
# scp BG_kin.cc signal_kin.cc plots_kin.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/code/kinematic_selection/
# scp ../../sh/myscript_kin.sh chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/code/kinematic_selection/
root -q "BG_kin.cc+(\"W+jets\")"
root -q "BG_kin.cc+(\"Z+jets\")"
root -q "BG_kin.cc+(\"ttbar\")"
root -q "BG_kin.cc+(\"topsingle\")"
root -q signal_kin.cc
root -q "BG_kin.cc+(\"multijets\")"
root -q -b plots_kin.cc

# scp chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/txt/array_* ./
