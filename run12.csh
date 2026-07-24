#!/bin/tcsh

if ($#argv < 1) then
    echo "Usage: $0 <parameter>"
    exit 1
endif

set parameter = "$1"

cd ./StROOT_ProductionCode_wTrk

chmod u+x ./runMacro.csh

singularity exec -e -B /direct -B /star -B /afs -B /gpfs -B /sdcc/lustre02 /cvmfs/star.sdcc.bnl.gov/containers/rhic_sl7.sif ./runMacro.csh ${parameter} 

mv ./H* /gpfs01/star/pwg/fliu/production/pp2012/PicoDstLambda_P12id/
