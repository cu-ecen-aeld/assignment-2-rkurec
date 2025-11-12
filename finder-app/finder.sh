#!/bin/bash
if [ $# -ne 2 ]
then
    echo "Invalid arguments; $0 {path} {pattern}"
    exit 1
else
    filesdir=$1     # search path
    searchstr=$2    # search criteria
    if [ -d $filesdir ]
    then
        # find count of files with $searchstr in $filesdir
        filecount=`grep -rl "$searchstr" $filesdir | wc -l`
        # find count of lines with $searchstr in $filesdir
        lines=`grep -c "$searchstr" $filesdir/* | wc -l`
        echo "The number of files are $filecount and the number of matching lines are $lines"
    else
        echo "invalid path!: $filesdir"
        exit 1
    fi
fi
#echo "DONE!"