#!/bin/sh

cd lib/poco-1.6.0-all
./configure --static --no-tests --no-samples --omit=Data/MySQL,Data/ODBC,Zip,MongoDB --sqlite-thread-safe=2
make -j4

