rem call "%VS120COMNTOOLS%..\..\VC\vcvarsall.bat" x86

cd lib\poco-1.6.0-all
call buildwin 120 build static_mt both Win32 nosamples notests msbuild
cd ..

