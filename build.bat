call "%VS100COMNTOOLS%..\..\VC\vcvarsall.bat" x86

cd lib\poco-1.6.0-all
call buildwin 100 build shared both Win32 nosamples notests msbuild
cd ..

