#!/usr/bin/env bash

PROGRAM="./cutLog"
OUT=$(mktemp)
INPUT_DATA_FOLDER="tests"
CORRECT_OUT_FOLDER="correctOutput"

function error() {
    rm ${OUT}
    echo -en \\nProgram test failed\\n

    exit 1
}

echo L = 100, N = 3
${PROGRAM} ${INPUT_DATA_FOLDER}/input1.txt > ${OUT}
diff ${OUT} ${CORRECT_OUT_FOLDER}/output1.txt > /dev/null || error
echo -en Passed\\n\\n

echo L = 10, N = 4
${PROGRAM} ${INPUT_DATA_FOLDER}/input2.txt > ${OUT}
diff ${OUT} ${CORRECT_OUT_FOLDER}/output2.txt > /dev/null || error
echo -en Passed\\n\\n

rm ${OUT}
echo All tests passed

exit 0