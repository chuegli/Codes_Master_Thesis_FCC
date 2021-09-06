ssh -XY chugli@lxplus.cern.ch


######### Locations:
#### Pileups with different pixel sizes:
/eos/atlas/unpledged/group-tokyo/users/masaito/datafiles/FCC/MinBias/
#### Default pileups with defautl pixel size:
/eos/experiment/fcc/hh/simulation/samples/v03/physics/MinBias/bFieldOn/etaFull/simu/tracker/mergedHits/final/energyCut360eV/correctHistory/


######## SCP:
## Take:
scp chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Reconstruction/RecTracker/options/TrickTrackReco.py ./
scp -r chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/ ./
scp -r chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/ ./

## Give:
scp TrickTrackReco.py chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Reconstruction/RecTracker/options/
scp Makefile fake_tracks.cc reco_effi.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
scp tests.sh chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/


####### Reconstruction:
### 1 event with x pileups:
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_1.root' >> ./Mio/txt_files/pileup_1.txt
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_2.root' >> ./Mio/txt_files/pileup_2.txt
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_4.root' >> ./Mio/txt_files/pileup_4.txt
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_8.root' >> ./Mio/txt_files/pileup_8.txt
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_16.root' >> ./Mio/txt_files/pileup_16.txt
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_32.root' >> ./Mio/txt_files/pileup_32.txt
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_64.root' >> ./Mio/txt_files/pileup_64.txt

### Generate signal:
# scp chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Detector/DetFCChhTrackerTkLayout/compact/Tracker.xml ./
scp Tracker.xml chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_3/Detector/DetFCChhTrackerTkLayout/compact/
scp geantSim_TrackerPerformance_wino.py TrickTrackReco_wino.py chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Reconstruction/RecTracker/options/

fccrun Reconstruction/RecTracker/options/geantSim_TrackerPerformance_wino.py -n 10000 --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root --EtaMin -2.0 --EtaMax 2.0 --PtMin 3000000 --PtMax 3000000
fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000.root' -n 10000

######## Comparison pileups vs signal:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000.root' -n 10000 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> signal.txt
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_tracks.root' -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
scp Makefile make_comparison_histos.cc make_comparison_plots.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/

cd Mio/code
make
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_tracks.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_comparison.root'
./make_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_comparison.root' '../plots/plots_comparison'

#### apply a pileups selection reduction:
make
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_tracks.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_comparison.root'
./make_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_comparison.root' '../plots/plots_comparison_selection'


########## Pileups size comparison:
### pileup_numberOfPileups_numberOfEvents_pixelSize_timeResolution.root
## 10 ps:
make
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_1.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_1_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_5_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50_10_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_1_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50_10_comparison.root' '../plots/pileups_size_comparison'

## 50 ps:
make
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_1.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_1_50_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_5_50_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50_50_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_1_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_5_50_comparison.root' '../plots/pileups_time_comparison'


./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50_test.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50_50_comparison_test.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_1_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_50_50_comparison_test.root' '../plots/pileups_time_comparison'

#################################################################################
############################### Generate pileups with different sizes:
scp Tracker.xml chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Detector/DetFCChhTrackerTkLayout/compact/
scp geantSim_TrackerPerformance_wino.py TrickTrackReco_wino.py TrickTrackReco.py chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Reconstruction/RecTracker/options/
scp TrickTrackReco.py chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Reconstruction/RecTracker/options/


# fccrun Reconstruction/RecTracker/options/geantSim_TrackerPerformance_wino.py -n 10000 --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000_1.root --EtaMin -2.0 --EtaMax 2.0 --PtMin 3000000 --PtMax 3000000
# fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000_1.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_1.root' -n 10000 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> signal.txt
# rm signal.txt

# fccrun Reconstruction/RecTracker/options/geantSim_TrackerPerformance_wino.py -n 10000 --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000_5.root --EtaMin -2.0 --EtaMax 2.0 --PtMin 3000000 --PtMax 3000000
# fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000_5.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' -n 10000 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> signal.txt
# rm signal.txt

# fccrun Reconstruction/RecTracker/options/geantSim_TrackerPerformance_wino.py -n 10000 --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000_50.root --EtaMin -2.0 --EtaMax 2.0 --PtMin 3000000 --PtMax 3000000
# fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000_50.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_50.root' -n 10000 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> signal.txt
# rm signal.txt

################ Reconstruct again pileups with different sizes:
### is it necessary to recompile for each size? (let's do it just to be sure)
# fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_1.root' -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
# rm pileup.txt
# ./Mio/code/./fake_tracks '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_1.root'

# fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5.root' -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
# rm pileup.txt
# ./Mio/code/./fake_tracks '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5.root'

# fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_50.root' -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
# rm pileup.txt
# ./Mio/code/./fake_tracks '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_50.root'

scp Makefile make_comparison_histos.cc make_comparison_plots.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
cd Mio/code
make

#### Wino size comparison:
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_1.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_1_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_50.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_50_10_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_1_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_50_10_comparison.root' '../plots/wino_size_comparison'

### Pileup size comparison:
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_1.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_1_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_50.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_50_10_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_1_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_50_10_comparison.root' '../plots/pileups_size_comparison'

#### Wino time comparison:
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_50_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_1_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_50_comparison.root' '../plots/wino_time_comparison'

### Pileup time comparison:
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_50_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_1_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_50_comparison.root' '../plots/pileups_time_comparison'

### Pileup vs signal comparison (time):
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root'

./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_50_comparison.root'

./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_50_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root' '../plots/pileups_winos_comparison'

### Pileup vs signal comparison (size):
make
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_50.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_50_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_50_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root' '../plots/pileups_winos_comparison_size'

### Pileup default vs pileups masahiko:
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default.root' -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
./Mio/code/./fake_tracks '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_10_default.root'

make
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_1.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_1_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_50.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_50_10_comparison.root'
./make_comparison_histos '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_default_10_comparison.root'
./make_size_comparison_plots '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_5_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_50_10_comparison.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_default_10_comparison.root' '../plots/pileups_default_vs_masahikos'

##############################
#######################
##############
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --pileupFilenames /eos/experiment/fcc/hh/simulation/samples/v03/physics/MinBias/bFieldOn/etaFull/simu/tracker/mergedHits/final/energyCut360eV/correctHistory/output_11[0-1]*.root --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_1.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >>  pileup.txt
make
./select_save '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_1.root' "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_1.root"

##################################################################################
################## Comparison selected pileups vs selected signal ################
##################################################################################
fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000.root' -n 10000 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >>  signal.txt
rm signal.txt
scp Makefile look_selected.cc signal_histo_selected.cc comparison_plots_selected.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
make
./look_selected
./signal_histo_selected '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_default_selected.root'
./comparison_plots_selected '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_default_selected.root' "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_histo.root" '../plots/selected_pileup_vs_signal'
scp -r chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/selected_pileup_vs_signal.pdf ./plots/





fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_64.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6

fccrun Reconstruction/RecTracker/options/TrickTrackReco_50.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_2/root_files/pileup_200_50x50_1.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
./code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_2/root_files/pileup_200_50x50_1.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_2/root_files/selected_50x50_1.root
rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_2/root_files/pileup_200_50x50_1.root



#%%%%%%%%%%%%%%%%%%%%%%%%%% Pileups seeds: trackStates check:
scp Makefile fake_tracks.cc reco_effi.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/








cd Mio/code/
make
cd ../..
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 1e2 --deltaT 3e6 --deltaPhi 1e-3 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 100.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root


fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_1.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
--hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
rm pileup.txt
./select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_1.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_1.root

fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000_5.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' -n 10000 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> signal.txt
rm signal.txt
./signal_histo_selected '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected.root'

./select_save '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected.root


#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#&&&&&&&&&&&&&&&&&&&&&&&&& Selected and anylsis:
#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
1) Find the good files using test.py
2) Run the run_shell_custom.sh file
3) Put files together using: read_selected.cc
4) Put entries in histos: look_selected.cc
5) DO the same for the signal: select_save.cc + look_selected
5) Compare the 2 root files for pileup and winos: comparison_plots_selected

scp Makefile read_selected.cc look_selected.cc comparison_plots_selected.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
root -b -q read_selected.cc # change stuff when changing pixel size
./look_selected  "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_5x5.root" "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_histo_5x5.root"
./select_save '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected.root
./look_selected /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root
./comparison_plots_selected '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root' "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_histo_5x5.root" '../plots/selected_pileup_vs_signal_5x5'
scp -r chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/selected_pileup_vs_signal.pdf ./plots/


##############################
# C:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 100 --deltaT 0.5 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 1.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_1000.root' -n 1000 --deltaZ 100 --deltaT 0.5 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 1.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >>  signal.txt
rm signal.txt
./Mio/code/./reco_effi
# B:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 100 --deltaT 3e6 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 12.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_1000.root' -n 1000 --deltaZ 100 --deltaT 3e6 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 12.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >>  signal.txt
rm signal.txt
./Mio/code/./reco_effi
# D:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 100 --deltaT 3e6 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 1.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_1000.root' -n 1000 --deltaZ 100 --deltaT 3e6 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 1.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >>  signal.txt
rm signal.txt
./Mio/code/./reco_effi
# A:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 100 --deltaT 0.5 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 12.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco_wino.py --input '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_10000.root' --filename '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_1000.root' -n 1000 --deltaZ 100 --deltaT 0.5 --deltaPhi 0.01 --deltaRho 1 --ptMin 20.0 --phiCut 0.3 --thetaCut 0.3 --hardPtCut 12.0 --hitEtaCut 1.1 --hitEnergyCut 5e-6 >>  signal.txt
rm signal.txt
./Mio/code/./reco_effi



# C:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 5 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
# B:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 5 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
# D:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 5 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
# A:
fccrun Reconstruction/RecTracker/options/TrickTrackReco_test.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 5 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
rm pileups_2.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root




fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
--hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
rm pileup.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
--hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
rm pileup.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
--hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
rm pileup.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
--hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
rm pileup.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
--hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
rm pileup.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root
fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
--hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
rm pileup.txt
./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
scp Makefile fake_tracks.cc start_file.cc newline_write.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
scp run_fake_tracks.sh chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/

chmod 755 run_fake_tracks.sh
./run_fake_tracks.sh

scp chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/Fake_rate_estimation.txt ./txt_files/
rm /afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/Fake_rate_estimation.txt
scp ./txt_files/Fake_rate_estimation_final_5.txt chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/


chmod 755 run_shell_custom.sh
./run_shell_custom.sh

scp read_fake_rate.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
root -q -l -b read_fake_rate.cc



&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

              ALWAYS CHECK THAT TEHNEW BETA CALCULATION IS USED !!!!!

&&&&& Make the wino pt distribution for 10 ps:
& maybe used this file:
scp Makefile plot_beta.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
'/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root'
./plot_beta '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root' '/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/wino_beta_10ps'
scp chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/wino_beta_10ps.pdf ./
& and plot h_track_pt

./select_save '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_1.root' /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_1x1_selected.root
./look_selected /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_1x1_selected.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_1x1_selected_histo.root

scp Makefile select_save.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
./select_save '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected.root
# ./look_selected /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_2/root_files/wino_5x5_selected.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root


./select_save '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_50.root' /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_50x50_selected.root
./look_selected /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_50x50_selected.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_50x50_selected_histo.root

./plot_beta_2 '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_1x1_selected_histo.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_50x50_selected_histo.root' '/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/wino_beta_5x5'


&&&&& Redo beta distribution (wino) for different pixels sizes in same plot:
& 1) Trovare i file dove sono simulati

&&&&& Redo beta distributions (wino) for different time resolutions in same plot:
& 1) trovare il codice dove cambiare la time resolution

&&&&& Beta resolution versus time resolution (wino) plot redo:
& 1) find code doing it
& 2) Do in particular fits on the 10 ps and write the resolution down in the thesis

./my_make_beta_2 '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_beta_5x5_time' 0.005
./wino_fitting_beta_2

            DOES THIS WAY OF CALCULATING BETA WORK FOR PILEUPS ?!?!?!?!?!
maybe use these with old beta calculation just for fater results redo everything would take a very large amount of time....

&&&&& Beta resolution distributions (pileups) for different time resolutions in the same plot:

&&&&& Beta resolution distributions (pileups) for different pixel sizes in the same plot:

#








./my_make_beta_final '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_bea_5x5' 0.005
./plot_beta '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_bea_5x5.root' '/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/wino_beta_10ps'
