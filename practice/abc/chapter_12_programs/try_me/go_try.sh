#!/bin/bash

## Experiment with the status
## (status is accessed using $? in a bash script)

echo ---	#echo call sets status to 0
echo At the top: status = $?
./try_me
echo ---	#echo call sets status to 0
echo After try_me: status = $?
./try_me
val=$?		#capture status value from try_me
echo ---	#echo call sets status to 0
echo After try_me again: val = $val
echo ""
echo ---
echo To exit from the while loop, input 0.
while [ $val ]
do
./try_me
val=$?
echo In the loop: val = $val
done
exit 0
