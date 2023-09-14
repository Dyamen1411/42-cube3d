#!/bin/sh
./preprocess.sh $1.c                                                           \
	| sed "s#0x..\(..\)\(..\)\(..\), #echo -ne '\\\xff\\\x\3\\\x\2\\\x\1'\n#g" \
	> $1.sh                                                                    \
	&& chmod +x $1.sh
