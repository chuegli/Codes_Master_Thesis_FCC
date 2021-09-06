#!/bin/sh
for i in 1 2 3 4 5 6 7 8 9
do
  for j in 0 1 2 3 4 5 6 7 8 9
  do
    if ((( $i==1 && $j==0 ) || ( $i==3 && $j==0 )))
    then
      echo "Not nice"
    else
      ### 1:
      counter=$((counter+1))
      if (( $counter>=410 ))
      then
        echo "${i}${j}[0-1]*"
        fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --pileupFilenames /eos/experiment/fcc/hh/simulation/samples/v03/physics/MinBias/bFieldOn/etaFull/simu/tracker/mergedHits/final/energyCut360eV/correctHistory/output_${i}${j}[0-1]*.root --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
        --hitEtaCut 1.2 --hitEnergyCut 5e-6 >> pileup.txt
        echo "File pileup_200_default_$counter.root created"
        rm pileup.txt
        ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_${counter}.root
        rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root
        echo "File selected_$counter.root created"
        echo "********** Finished ************"
        ### 2:
        counter=$((counter+1))
        echo "${i}${j}[2-3]*"
        fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --pileupFilenames /eos/experiment/fcc/hh/simulation/samples/v03/physics/MinBias/bFieldOn/etaFull/simu/tracker/mergedHits/final/energyCut360eV/correctHistory/output_${i}${j}[2-3]*.root --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
        --hitEtaCut 1.2 --hitEnergyCut 5e-6 >>  pileup.txt
        echo "File pileup_200_default_$counter.root created"
        rm pileup.txt
        ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_${counter}.root
        rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root
        echo "File selected_$counter.root created"
        echo "********** Finished ************"
        ### 3:
        counter=$((counter+1))
        echo "${i}${j}[4-5]*"
        fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --pileupFilenames /eos/experiment/fcc/hh/simulation/samples/v03/physics/MinBias/bFieldOn/etaFull/simu/tracker/mergedHits/final/energyCut360eV/correctHistory/output_${i}${j}[4-5]*.root --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
        --hitEtaCut 1.2 --hitEnergyCut 5e-6 >>  pileup.txt
        echo "File pileup_200_default_$counter.root created"
        rm pileup.txt
        ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_${counter}.root
        rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root
        echo "File selected_$counter.root created"
        echo "********** Finished ************"
        ### 4:
        counter=$((counter+1))
        echo "${i}${j}[6-7]*"
        fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --pileupFilenames /eos/experiment/fcc/hh/simulation/samples/v03/physics/MinBias/bFieldOn/etaFull/simu/tracker/mergedHits/final/energyCut360eV/correctHistory/output_${i}${j}[6-7]*.root --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
        --hitEtaCut 1.2 --hitEnergyCut 5e-6 >>  pileup.txt
        echo "File pileup_200_default_$counter.root created"
        rm pileup.txt
        ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_${counter}.root
        rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root
        echo "File selected_$counter.root created"
        echo "********** Finished ************"
        ### 5:
        counter=$((counter+1))
        echo "${i}${j}[8-9]*"
        fccrun Reconstruction/RecTracker/options/TrickTrackReco.py --pileupFilenames /eos/experiment/fcc/hh/simulation/samples/v03/physics/MinBias/bFieldOn/etaFull/simu/tracker/mergedHits/final/energyCut360eV/correctHistory/output_${i}${j}[8-9]*.root --filename /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root -n 10 --deltaZ 1e4 --deltaT 3e6 --deltaPhi 0.1 --deltaRho 1e5 --ptMin 7.0 --phiCut 1.0 --thetaCut 1.0 --hardPtCut 12.0 \
        --hitEtaCut 1.2 --hitEnergyCut 5e-6 >>  pileup.txt
        echo "File pileup_200_default_$counter.root created"
        rm pileup.txt
        ./Mio/code/select_save /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_${counter}.root
        rm /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_default_${counter}.root
        echo "File selected_$counter.root created"
        echo "********** Finished ************"
      else
        counter=$((counter+1))
        counter=$((counter+1))
        counter=$((counter+1))
        counter=$((counter+1))
      fi
    fi
  done

done
