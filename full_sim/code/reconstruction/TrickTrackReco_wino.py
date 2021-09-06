import os
import argparse
from GaudiKernel import SystemOfUnits as units
from GaudiKernel import PhysicalConstants as constants
from Gaudi.Configuration import *
import math

from argparse import Namespace
args = Namespace(
  inputfile='',
  pileupfiles='',
  outputfile='',
  nevents=1000,
  npileup=0,
  noSignal=False, #False
  cleanHits=True, #True
  trajectories=False, #False
  truthseeding=False, #False
  recoHelix=False, #False
)

inputfile = args.inputfile

algList = []

from Configurables import AuditorSvc, ChronoAuditor
chra = ChronoAuditor()
audsvc = AuditorSvc()
audsvc.Auditors = [chra]

# switch between branch nameing conventions
collectionNames = {}
collectionNames["GenParticles"] = "GenParticles"
collectionNames["GenVertices"] = "GenVertices"
collectionNames["SimParticles"] = "SimParticles"
collectionNames["SimVertices"] = "SimVertices"
collectionNames["TrackerHitsPosition"] = "SmearedTrackerHits"
# collectionNames["TrackerHitsPosition"] = "TrackerHitsPosition"
collectionNames["TrackerHits"] = "TrackerHits"

if args.trajectories:
  collectionNames["trajectory"] = "trajectory"
  collectionNames["trajectoryPoints"] = "trajectoryPoints"

if not args.noSignal:
  from Configurables import PodioInput
  podioinput = PodioInput("PodioReader",
                          collections=list(collectionNames.values()),
                            OutputLevel=DEBUG,
                            )
  podioinput.AuditExecute = True
  algList += [podioinput]
if args.npileup > 0:
  pileupFilenames = args.pileupfiles

  from Configurables import PileupParticlesMergeTool
  particlemergetool = PileupParticlesMergeTool("PileupGenParticlesMergeTool")
  # branchnames for the pileup
  particlemergetool.genParticlesBranch = "GenParticles"
  particlemergetool.genVerticesBranch = "GenVertices"
  # branchnames for the signal
  particlemergetool.signalGenVertices.Path = "GenVertices"
  particlemergetool.signalGenParticles.Path = "GenParticles"
  # branchnames for the output
  particlemergetool.mergedGenParticles.Path = "mergedGenParticles"
  particlemergetool.mergedGenVertices.Path = "mergedGenVertices"

  simparticlemergetool = PileupParticlesMergeTool("PileupSimParticlesMergeTool")
  # branchnames for the pileup
  simparticlemergetool.genParticlesBranch = "SimParticles"
  simparticlemergetool.genVerticesBranch = "SimVertices"
  # branchnames for the signal
  simparticlemergetool.signalGenVertices.Path = "SimVertices"
  simparticlemergetool.signalGenParticles.Path = "SimParticles"
  # branchnames for the output
  simparticlemergetool.mergedGenParticles.Path = "mergedSimParticles"
  simparticlemergetool.mergedGenVertices.Path = "mergedSimVertices"

  from Configurables import PileupTrackHitMergeTool
  trackhitsmergetool = PileupTrackHitMergeTool("PileupTrackHitMergeTool")
  # branchnames for the pileup
  trackhitsmergetool.pileupHitsBranch = "TrackerHits"
  trackhitsmergetool.pileupPositionedHitsBranch = "TrackerHitsPosition"
  # branchnames for the signal
  trackhitsmergetool.signalHits = "TrackerHits"
  trackhitsmergetool.signalPositionedHits = "TrackerHitsPosition"
  # branchnames for the output
  trackhitsmergetool.mergedHits = "mergedTrackerHits"
  trackhitsmergetool.mergedPositionedHits = "mergedTrackerPositionedHits"

  # use the pileuptool to specify the number of pileup
  from Configurables import ConstPileUp
  pileuptool = ConstPileUp("ConstPileUp", numPileUpEvents=args.npileup)

  # algorithm for the overlay
  from Configurables import PileupOverlayAlg
  overlay = PileupOverlayAlg()
  overlay.pileupFilenames = pileupFilenames
  overlay.randomizePileup = False
  overlay.noSignal = args.noSignal
  overlay.mergeTools = [particlemergetool, simparticlemergetool, trackhitsmergetool]
  overlay.PileUpTool = pileuptool
  overlay.AuditExecute = True
  algList += [overlay]

from Configurables import FCCDataSvc
podioevent   = FCCDataSvc("EventDataSvc", input=args.inputfile)




# TrickTrack Seeding Configuration
from Configurables import FCChhSeedHitFilterTool
hitfiltertool = FCChhSeedHitFilterTool("FCChhSeedHitFilterTool")

from Configurables import FCChhSeedingGraphTool
layergraphtool = FCChhSeedingGraphTool("TheSeedingGraphTool")


from Configurables import TrickTrackSeedingTool
tricktrack_seed_tool = TrickTrackSeedingTool()
tricktrack_seed_tool.LayerGraphTool = layergraphtool
tricktrack_seed_tool.deltaZ=860
tricktrack_seed_tool.deltaT=3000000.0
tricktrack_seed_tool.deltaPhi=2
tricktrack_seed_tool.seedingLayerIndices = [[0, 0], [0,1], [0,2], [0,3],  [2,0], [2,2], [2,4], [2,6], [2,8], [2,1],[2,3],[2,5],[2,7],[2,9]]

#tricktrack_seed_tool.ptMin = 100.00
tricktrack_seed_tool.phiCut = 2
#tricktrack_seed_tool.thetaCut = 2.
tricktrack_seed_tool.hardPtCut= 11.0
#tricktrack_seed_tool.regionOriginRadius= 120.5

tricktrack_seed_tool.cleanHits = args.cleanHits



from Configurables import RiemannFitTool
riemann_fit = RiemannFitTool("TheRiemannFitTool")
riemann_fit.hitRes = 5 * units.micrometer / math.sqrt(12)
riemann_fit.saveOnlyValidFit = True

from Configurables import RecTrackAlg
RecTrackAlg = RecTrackAlg()
RecTrackAlg.TrackSeedingTool = tricktrack_seed_tool
# Alternative: uncomment to use the MCTruth for seeding
#RecTrackAlg.TrackSeedingTool = truth_seeds
RecTrackAlg.TrackFittingTool = riemann_fit
RecTrackAlg.TrackerPositionedHits.Path = collectionNames["TrackerHitsPosition"]





from Configurables import PodioOutput
out = PodioOutput("out",
                   filename=args.outputfile,
                   OutputLevel=DEBUG)
out.outputCommands = ["keep *"]


RecTrackAlg.AuditExecute = True
out.AuditExecute = True
algList += [RecTrackAlg]

if args.recoHelix:
  from Configurables import RecHelixTrajectory
  rht = RecHelixTrajectory()
  rht.AuditExecute = True
  algList += [rht]
algList += [out]

from Configurables import ApplicationMgr
ApplicationMgr( TopAlg =  algList,
                EvtSel = 'NONE',
                EvtMax   = args.nevents,
                ExtSvc = [podioevent],
                OutputLevel=VERBOSE,
 )
