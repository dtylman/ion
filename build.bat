call "%VS120COMNTOOLS%..\..\VC\vcvarsall.bat" x86
set WORKSPACE=%CD%

cd %WORKSPACE%\lib\openssl-1.0.2
call perl Configure VC-WIN32 --prefix=%OPENSSL_DIR%
call ms\do_nasm
call nmake -f ms\nt.mak
cd ..

cd %WORKSPACE%\lib\poco-1.6.0-all
call buildwin 120 build static_mt both Win32 nosamples notests msbuild

cd %WORKSPACE%\lib\libnet-1.2-rc3
call msvcbuild.bat

cd %WORKSPACE%
call msbuild ion.sln /p:Configuration=Release

cd %WORKSPACE%\Release
call dbtool.exe /overwrite /oui=%WORKSPACE%\dbtool\oui.txt /db=%WORKSPACE%\Release\ion.db

cd %WORKSPACE%\inst\win
call "c:\Program Files (x86)\Inno Setup 5\Compil32.exe" /cc ion.iss





