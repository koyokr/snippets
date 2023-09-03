#!/bin/bash

if [ -x ./intr ] && [ -f ./mymalloc.so ]; then
	LD_PRELOAD=./mymalloc.so ./intr
fi
