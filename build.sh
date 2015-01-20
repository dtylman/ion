#!/bin/sh

cd lib/poco-1.6.0-all
./configure --static --no-tests --no-samples --omit=Data/MySQL,Data/ODBC,Zip,MongoDB,NetSSL,NetSSL_OpenSSL,PageCompiler
make -j4

