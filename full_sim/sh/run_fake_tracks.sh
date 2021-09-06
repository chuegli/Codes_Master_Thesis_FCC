#!/bin/sh

for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
do
  for j in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
  do
    counter=$((counter+1))
    if (( $counter>=385))
    then
      if (( $counter==1))
      then
        root -q ./Mio/code/start_file.cc
      fi
      # 1
      echo "Counter: $counter"

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      root -q -l ./Mio/code/newline_write.cc

      echo "********** Finished **********"

      ################################## 2
      echo "Counter: $counter"

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      root -q -l ./Mio/code/newline_write.cc

      echo "********** Finished **********"

      ################################## 3
      echo "Counter: $counter"

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      root -q -l ./Mio/code/newline_write.cc

      echo "********** Finished **********"

      ################################## 4
      echo "Counter: $counter"

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      root -q -l ./Mio/code/newline_write.cc

      echo "********** Finished **********"

      ################################## 5
      echo "Counter: $counter"

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 0.1 --deltaPhi 0.01 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 10.0 --phiCut 1 --thetaCut 1 --hardPtCut 50.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root -n 1 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1 --thetaCut 1 --hardPtCut 12.0 --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileups_2.txt
      rm pileups_2.txt
      ./Mio/code/fake_tracks /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_test.root

      root -q -l ./Mio/code/newline_write.cc

      echo "********** Finished **********"
    fi
  done
done
