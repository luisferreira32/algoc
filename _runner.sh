#!/bin/bash

set -xe

IN_GLOB="$1"
OUT_GLOB="$2"

IFS="/" read -r -a tmp_arr <<< "$IN_GLOB"

EXEC_FILENAME="bin/${tmp_arr[1]}"

for INPUT in "$IN_GLOB"*.inp.*; do
  EXPECTED_OUTPUT=${INPUT//".inp."/".out."}
  valgrind --log-file="${INPUT//$IN_GLOB/$OUT_GLOB}.valgrind.logs" $EXEC_FILENAME < "$INPUT" > "${INPUT//$IN_GLOB/$OUT_GLOB}"
  diff "${INPUT//$IN_GLOB/$OUT_GLOB}" "$EXPECTED_OUTPUT"
done
