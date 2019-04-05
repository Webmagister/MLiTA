#!/usr/bin/env bash

PROGRAM="./square"
OUT=$(mktemp)
INPUT_DATA_FOLDER="tests"
CORRECT_OUT_FOLDER="correctOutput"

function error() {
    rm ${OUT}
    echo -en \\nProgram test failed\\n

    exit 1
}

echo input1.txt
${PROGRAM} ${INPUT_DATA_FOLDER}/input1.txt ${OUT}
diff ${OUT} ${CORRECT_OUT_FOLDER}/output1.txt > /dev/null || error
echo -en Passed\\n\\n

echo input12.txt
${PROGRAM} ${INPUT_DATA_FOLDER}/input12.txt ${OUT}
diff ${OUT} ${CORRECT_OUT_FOLDER}/output12.txt > /dev/null || error
echo -en Passed\\n\\n

rm ${OUT}
echo All tests passed

exit 0