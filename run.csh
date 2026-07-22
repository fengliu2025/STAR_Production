#!/bin/tcsh

if ($#argv < 1) then
    echo "Usage: $0 <parameter>"
    exit 1
endif

set parameter = "$1"

cd ./StROOT_ProductionCode

chmod u+x ./runMacro.csh

singularity exec -e -B /direct -B /star -B /afs -B /gpfs -B /sdcc/lustre02 /cvmfs/star.sdcc.bnl.gov/containers/rhic_sl7.sif ./runMacro.csh ${parameter} 

