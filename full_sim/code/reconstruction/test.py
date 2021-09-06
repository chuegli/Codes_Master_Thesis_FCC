import ROOT
import sys
import glob

################################################################################
### What it does:
# takes a list of 100 root files
# for every file it checks if the tree named "events" exists
# it outputs a list of the files where it exsits
# these files are the ones which can be reconstructed unsing TrickTrackReco.py
### How to run:
# 1) Go to: /afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
# 2) Command: python test.py /eos/user/m/masaito/FCC/MinBias/5x5/simu/ntuple.0001[0-9][0-9].root
################################################################################

print("Input argument to python:\n")

pileupFilenamesCopy = \
[sys.argv[1],sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5],sys.argv[6],sys.argv[7],sys.argv[8],sys.argv[9],sys.argv[10], \
sys.argv[11],sys.argv[12],sys.argv[13],sys.argv[14],sys.argv[15],sys.argv[16],sys.argv[17],sys.argv[18],sys.argv[19],sys.argv[20], \
sys.argv[21],sys.argv[22],sys.argv[23],sys.argv[24],sys.argv[25],sys.argv[26],sys.argv[27],sys.argv[28],sys.argv[29],sys.argv[30], \
sys.argv[31],sys.argv[32],sys.argv[33],sys.argv[34],sys.argv[35],sys.argv[36],sys.argv[37],sys.argv[38],sys.argv[39],sys.argv[40], \
sys.argv[41],sys.argv[42],sys.argv[43],sys.argv[44],sys.argv[45],sys.argv[46],sys.argv[47],sys.argv[48],sys.argv[49],sys.argv[50], \
sys.argv[51],sys.argv[52],sys.argv[53],sys.argv[54],sys.argv[55],sys.argv[56],sys.argv[57],sys.argv[58],sys.argv[59],sys.argv[60], \
sys.argv[61],sys.argv[62],sys.argv[63],sys.argv[64],sys.argv[65],sys.argv[66],sys.argv[67],sys.argv[68],sys.argv[69],sys.argv[70], \
sys.argv[71],sys.argv[72],sys.argv[73],sys.argv[74],sys.argv[75],sys.argv[76],sys.argv[77],sys.argv[78],sys.argv[79],sys.argv[80], \
sys.argv[81],sys.argv[82],sys.argv[83],sys.argv[84],sys.argv[85],sys.argv[86],sys.argv[87],sys.argv[88],sys.argv[89],sys.argv[90], \
sys.argv[91],sys.argv[92],sys.argv[93],sys.argv[94],sys.argv[95],sys.argv[96],sys.argv[97],sys.argv[98],sys.argv[99],sys.argv[100]]
pileupFilenames = []
for filename in pileupFilenamesCopy:
    file = ROOT.TFile(filename, "READ")
    bool_events = False
    for key in file.GetListOfKeys():
        if(key.GetName()=="events"):
            bool_events = True
    if(bool_events):
        pileupFilenames.append(filename)
print(pileupFilenames)
