#!/bin/sh

executable=c-csv-test
dir=build


run_command() {
    cd $dir && cmake .. && cmake --build . && ./$executable
}

if [[ ! -e $dir ]]
then
    mkdir $dir && run_command
else
    run_command
fi

if [[ $? != 0 ]]
then
    echo "Failure."
else
    echo "Success."
fi
