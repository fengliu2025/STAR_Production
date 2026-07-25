#!/bin/tcsh


if ($#argv < 1) then
    echo "Usage: $0 <parameter>"
    exit 1
endif

set parameter = "$1"

starver SL24y

root4star -l -b -q runPicoLambdaAnaMaker3.C\(${parameter}\)
