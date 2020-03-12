#!/bin/sh
# This shell script generates a sequnce of experiments
# with the same parameters but with different seeds

N_ROUNDS=$1
SEED=`date '+%s'`
make # create executable
echo "Number of rounds: $N_ROUNDS"
echo "Current seed: $SEED"
