#!/bin/bash

set -xe

EXEC_FILENAME="$1"
IN_GLOB="$2"
OUT_GLOB="$3"

for INPUT in "$IN_GLOB"*.inp.*; do
  EXPECTED_OUTPUT=${INPUT//".inp."/".out."}
  OUTPUT_FILE=${INPUT//$IN_GLOB/$OUT_GLOB}
  valgrind \
    --log-file="$OUTPUT_FILE.valgrind.logs" \
    ./"$EXEC_FILENAME" < "$INPUT" > "$OUTPUT_FILE"
  diff "$OUTPUT_FILE" "$EXPECTED_OUTPUT"
done
