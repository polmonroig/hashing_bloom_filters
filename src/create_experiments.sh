#!/bin/sh
# This shell script generates a sequnce of experiments
# with the same parameters but with different seeds

N=$1
LOAD=$2
N_HASH_F=$3
SEED=$4
KEY_P=$5
INPUT=$6
OUTPUT=$7
N_ROUNDS=$8



make # create executable
echo "Number of rounds: $N_ROUNDS"

RANDOM=$SEED
for (( i = 0; i < $N_ROUNDS ; i++));
do
    SEED=($RANDOM % 10000000)
    echo "Current seed: $SEED"
    ./program $N $LOAD $N_HASH_F $SEED $KEY_P $INPUT $OUTPUT

done
