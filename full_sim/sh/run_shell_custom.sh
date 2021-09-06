#!/bin/sh

for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14
do
  for j in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
  do
    counter=$((counter+1))
    if (( $counter>=910))
    then
      # 1
      echo "Counter: $counter"
      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
      --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
      rm pileup.txt
      echo "File pileup_200_5x5_$counter.root created"
      ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_${counter}.root
      rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root
      echo "File selected_5x5_$counter.root created"
      echo "********** Finished **********"
      # 2
      counter=$((counter+1))
      echo "Counter: $counter"
      rm pileup.txt
      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
      --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
      rm pileup.txt
      echo "File pileup_200_5x5_$counter.root created"
      ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_${counter}.root
      rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root
      echo "File selected_5x5_$counter.root created"
      echo "********** Finished **********"
      # 3
      counter=$((counter+1))
      echo "Counter: $counter"
      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
      --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
      rm pileup.txt
      echo "File pileup_200_5x5_$counter.root created"
      ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_${counter}.root
      rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root
      echo "File selected_5x5_$counter.root created"
      echo "********** Finished **********"
      # 4
      counter=$((counter+1))
      echo "Counter: $counter"
      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
      --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
      rm pileup.txt
      echo "File pileup_200_5x5_$counter.root created"
      ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_${counter}.root
      rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root
      echo "File selected_5x5_$counter.root created"
      echo "********** Finished **********"
      # 5
      counter=$((counter+1))
      echo "Counter: $counter"
      fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
      --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
      rm pileup.txt
      echo "File pileup_200_5x5_$counter.root created"
      ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_${counter}.root
      rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_5x5_${counter}.root
      echo "File selected_5x5_$counter.root created"
      echo "********** Finished **********"
    else
      counter=$((counter+1))
      counter=$((counter+1))
      counter=$((counter+1))
      counter=$((counter+1))
    fi
  done
done
