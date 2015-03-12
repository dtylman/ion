#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AddressesPage.o \
	${OBJECTDIR}/Arping.o \
	${OBJECTDIR}/AuthDataObject.o \
	${OBJECTDIR}/DHCPOSDataObject.o \
	${OBJECTDIR}/DataObject.o \
	${OBJECTDIR}/DataObserver.o \
	${OBJECTDIR}/DataSubsystem.o \
	${OBJECTDIR}/DissectSubsystem.o \
	${OBJECTDIR}/EditThingPage.o \
	${OBJECTDIR}/EventConfigPage.o \
	${OBJECTDIR}/EventData.o \
	${OBJECTDIR}/EventDataObject.o \
	${OBJECTDIR}/EventNotification.o \
	${OBJECTDIR}/EventsPage.o \
	${OBJECTDIR}/EventsSubsystem.o \
	${OBJECTDIR}/FileRequestHandler.o \
	${OBJECTDIR}/Frame.o \
	${OBJECTDIR}/IONDataObject.o \
	${OBJECTDIR}/IPCache.o \
	${OBJECTDIR}/IPData.o \
	${OBJECTDIR}/IPDataObserver.o \
	${OBJECTDIR}/Injector.o \
	${OBJECTDIR}/LibnetException.o \
	${OBJECTDIR}/MAC.o \
	${OBJECTDIR}/MailConfigPage.o \
	${OBJECTDIR}/MailSendPage.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/NetStat_LINUX.o \
	${OBJECTDIR}/PageRequestHandler.o \
	${OBJECTDIR}/PcapActivity.o \
	${OBJECTDIR}/PcapDevice.o \
	${OBJECTDIR}/PcapIfaceAddress.o \
	${OBJECTDIR}/PcapSubsystem.o \
	${OBJECTDIR}/Protocol.o \
	${OBJECTDIR}/ProtocolARP.o \
	${OBJECTDIR}/ProtocolDHCP.o \
	${OBJECTDIR}/ProtocolEthernet.o \
	${OBJECTDIR}/ProtocolIP.o \
	${OBJECTDIR}/ProtocolIPV6.o \
	${OBJECTDIR}/ProtocolNBDatagram.o \
	${OBJECTDIR}/ProtocolTCP.o \
	${OBJECTDIR}/ProtocolUDP.o \
	${OBJECTDIR}/Rouing.o \
	${OBJECTDIR}/Routing_LINUX.o \
	${OBJECTDIR}/ScopedTransaciton.o \
	${OBJECTDIR}/Selfy.o \
	${OBJECTDIR}/SendMail.o \
	${OBJECTDIR}/ServerSettingsPage.o \
	${OBJECTDIR}/Solicitator.o \
	${OBJECTDIR}/Syslog_LINUX.o \
	${OBJECTDIR}/ThingData.o \
	${OBJECTDIR}/ThingObserver.o \
	${OBJECTDIR}/ThingsPage.o \
	${OBJECTDIR}/TrafficBulk.o \
	${OBJECTDIR}/TrafficData.o \
	${OBJECTDIR}/TrafficDataObject.o \
	${OBJECTDIR}/TrafficObserver.o \
	${OBJECTDIR}/WebForm.o \
	${OBJECTDIR}/WebMenu.o \
	${OBJECTDIR}/WebRequestHandlerFactory.o \
	${OBJECTDIR}/WebSubsystem.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../lib/poco-1.6.0-all/lib/Linux/x86_64 ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoUtild.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoJSONd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoXMLd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoFoundationd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDataSQLited.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDatad.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetSSLd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoCryptod.a -lpcap -lpthread -ldl -lnet `pkg-config --libs libssl`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../${CND_CONF}/ion

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetd.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoUtild.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoJSONd.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoXMLd.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoFoundationd.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDataSQLited.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDatad.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetSSLd.a

../${CND_CONF}/ion: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoCryptod.a

../${CND_CONF}/ion: ${OBJECTFILES}
	${MKDIR} -p ../${CND_CONF}
	${LINK.cc} -o ../${CND_CONF}/ion ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AddressesPage.o: AddressesPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AddressesPage.o AddressesPage.cpp

${OBJECTDIR}/Arping.o: Arping.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arping.o Arping.cpp

${OBJECTDIR}/AuthDataObject.o: AuthDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AuthDataObject.o AuthDataObject.cpp

${OBJECTDIR}/DHCPOSDataObject.o: DHCPOSDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DHCPOSDataObject.o DHCPOSDataObject.cpp

${OBJECTDIR}/DataObject.o: DataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObject.o DataObject.cpp

${OBJECTDIR}/DataObserver.o: DataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObserver.o DataObserver.cpp

${OBJECTDIR}/DataSubsystem.o: DataSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataSubsystem.o DataSubsystem.cpp

${OBJECTDIR}/DissectSubsystem.o: DissectSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DissectSubsystem.o DissectSubsystem.cpp

${OBJECTDIR}/EditThingPage.o: EditThingPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EditThingPage.o EditThingPage.cpp

${OBJECTDIR}/EventConfigPage.o: EventConfigPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventConfigPage.o EventConfigPage.cpp

${OBJECTDIR}/EventData.o: EventData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventData.o EventData.cpp

${OBJECTDIR}/EventDataObject.o: EventDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventDataObject.o EventDataObject.cpp

${OBJECTDIR}/EventNotification.o: EventNotification.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventNotification.o EventNotification.cpp

${OBJECTDIR}/EventsPage.o: EventsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventsPage.o EventsPage.cpp

${OBJECTDIR}/EventsSubsystem.o: EventsSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventsSubsystem.o EventsSubsystem.cpp

${OBJECTDIR}/FileRequestHandler.o: FileRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FileRequestHandler.o FileRequestHandler.cpp

${OBJECTDIR}/Frame.o: Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Frame.o Frame.cpp

${OBJECTDIR}/IONDataObject.o: IONDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IONDataObject.o IONDataObject.cpp

${OBJECTDIR}/IPCache.o: IPCache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPCache.o IPCache.cpp

${OBJECTDIR}/IPData.o: IPData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPData.o IPData.cpp

${OBJECTDIR}/IPDataObserver.o: IPDataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPDataObserver.o IPDataObserver.cpp

${OBJECTDIR}/Injector.o: Injector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Injector.o Injector.cpp

${OBJECTDIR}/LibnetException.o: LibnetException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LibnetException.o LibnetException.cpp

${OBJECTDIR}/MAC.o: MAC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MAC.o MAC.cpp

${OBJECTDIR}/MailConfigPage.o: MailConfigPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MailConfigPage.o MailConfigPage.cpp

${OBJECTDIR}/MailSendPage.o: MailSendPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MailSendPage.o MailSendPage.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/NetStat_LINUX.o: NetStat_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NetStat_LINUX.o NetStat_LINUX.cpp

${OBJECTDIR}/PageRequestHandler.o: PageRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PageRequestHandler.o PageRequestHandler.cpp

${OBJECTDIR}/PcapActivity.o: PcapActivity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapActivity.o PcapActivity.cpp

${OBJECTDIR}/PcapDevice.o: PcapDevice.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapDevice.o PcapDevice.cpp

${OBJECTDIR}/PcapIfaceAddress.o: PcapIfaceAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapIfaceAddress.o PcapIfaceAddress.cpp

${OBJECTDIR}/PcapSubsystem.o: PcapSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapSubsystem.o PcapSubsystem.cpp

${OBJECTDIR}/Protocol.o: Protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Protocol.o Protocol.cpp

${OBJECTDIR}/ProtocolARP.o: ProtocolARP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolARP.o ProtocolARP.cpp

${OBJECTDIR}/ProtocolDHCP.o: ProtocolDHCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolDHCP.o ProtocolDHCP.cpp

${OBJECTDIR}/ProtocolEthernet.o: ProtocolEthernet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolEthernet.o ProtocolEthernet.cpp

${OBJECTDIR}/ProtocolIP.o: ProtocolIP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolIP.o ProtocolIP.cpp

${OBJECTDIR}/ProtocolIPV6.o: ProtocolIPV6.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolIPV6.o ProtocolIPV6.cpp

${OBJECTDIR}/ProtocolNBDatagram.o: ProtocolNBDatagram.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolNBDatagram.o ProtocolNBDatagram.cpp

${OBJECTDIR}/ProtocolTCP.o: ProtocolTCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolTCP.o ProtocolTCP.cpp

${OBJECTDIR}/ProtocolUDP.o: ProtocolUDP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolUDP.o ProtocolUDP.cpp

${OBJECTDIR}/Rouing.o: Rouing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rouing.o Rouing.cpp

${OBJECTDIR}/Routing_LINUX.o: Routing_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Routing_LINUX.o Routing_LINUX.cpp

${OBJECTDIR}/ScopedTransaciton.o: ScopedTransaciton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScopedTransaciton.o ScopedTransaciton.cpp

${OBJECTDIR}/Selfy.o: Selfy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Selfy.o Selfy.cpp

${OBJECTDIR}/SendMail.o: SendMail.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SendMail.o SendMail.cpp

${OBJECTDIR}/ServerSettingsPage.o: ServerSettingsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServerSettingsPage.o ServerSettingsPage.cpp

${OBJECTDIR}/Solicitator.o: Solicitator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solicitator.o Solicitator.cpp

${OBJECTDIR}/Syslog_LINUX.o: Syslog_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Syslog_LINUX.o Syslog_LINUX.cpp

${OBJECTDIR}/ThingData.o: ThingData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingData.o ThingData.cpp

${OBJECTDIR}/ThingObserver.o: ThingObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingObserver.o ThingObserver.cpp

${OBJECTDIR}/ThingsPage.o: ThingsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingsPage.o ThingsPage.cpp

${OBJECTDIR}/TrafficBulk.o: TrafficBulk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficBulk.o TrafficBulk.cpp

${OBJECTDIR}/TrafficData.o: TrafficData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficData.o TrafficData.cpp

${OBJECTDIR}/TrafficDataObject.o: TrafficDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficDataObject.o TrafficDataObject.cpp

${OBJECTDIR}/TrafficObserver.o: TrafficObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficObserver.o TrafficObserver.cpp

${OBJECTDIR}/WebForm.o: WebForm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebForm.o WebForm.cpp

${OBJECTDIR}/WebMenu.o: WebMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebMenu.o WebMenu.cpp

${OBJECTDIR}/WebRequestHandlerFactory.o: WebRequestHandlerFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebRequestHandlerFactory.o WebRequestHandlerFactory.cpp

${OBJECTDIR}/WebSubsystem.o: WebSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebSubsystem.o WebSubsystem.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include -I. `pkg-config --cflags libssl` -std=c++11  -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/AddressesPage_nomain.o: ${OBJECTDIR}/AddressesPage.o AddressesPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/AddressesPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AddressesPage_nomain.o AddressesPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/AddressesPage.o ${OBJECTDIR}/AddressesPage_nomain.o;\
	fi

${OBJECTDIR}/Arping_nomain.o: ${OBJECTDIR}/Arping.o Arping.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arping.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arping_nomain.o Arping.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Arping.o ${OBJECTDIR}/Arping_nomain.o;\
	fi

${OBJECTDIR}/AuthDataObject_nomain.o: ${OBJECTDIR}/AuthDataObject.o AuthDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/AuthDataObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AuthDataObject_nomain.o AuthDataObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/AuthDataObject.o ${OBJECTDIR}/AuthDataObject_nomain.o;\
	fi

${OBJECTDIR}/DHCPOSDataObject_nomain.o: ${OBJECTDIR}/DHCPOSDataObject.o DHCPOSDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DHCPOSDataObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DHCPOSDataObject_nomain.o DHCPOSDataObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DHCPOSDataObject.o ${OBJECTDIR}/DHCPOSDataObject_nomain.o;\
	fi

${OBJECTDIR}/DataObject_nomain.o: ${OBJECTDIR}/DataObject.o DataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObject_nomain.o DataObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataObject.o ${OBJECTDIR}/DataObject_nomain.o;\
	fi

${OBJECTDIR}/DataObserver_nomain.o: ${OBJECTDIR}/DataObserver.o DataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataObserver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObserver_nomain.o DataObserver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataObserver.o ${OBJECTDIR}/DataObserver_nomain.o;\
	fi

${OBJECTDIR}/DataSubsystem_nomain.o: ${OBJECTDIR}/DataSubsystem.o DataSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataSubsystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataSubsystem_nomain.o DataSubsystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataSubsystem.o ${OBJECTDIR}/DataSubsystem_nomain.o;\
	fi

${OBJECTDIR}/DissectSubsystem_nomain.o: ${OBJECTDIR}/DissectSubsystem.o DissectSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DissectSubsystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DissectSubsystem_nomain.o DissectSubsystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DissectSubsystem.o ${OBJECTDIR}/DissectSubsystem_nomain.o;\
	fi

${OBJECTDIR}/EditThingPage_nomain.o: ${OBJECTDIR}/EditThingPage.o EditThingPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EditThingPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EditThingPage_nomain.o EditThingPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EditThingPage.o ${OBJECTDIR}/EditThingPage_nomain.o;\
	fi

${OBJECTDIR}/EventConfigPage_nomain.o: ${OBJECTDIR}/EventConfigPage.o EventConfigPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EventConfigPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventConfigPage_nomain.o EventConfigPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EventConfigPage.o ${OBJECTDIR}/EventConfigPage_nomain.o;\
	fi

${OBJECTDIR}/EventData_nomain.o: ${OBJECTDIR}/EventData.o EventData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EventData.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventData_nomain.o EventData.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EventData.o ${OBJECTDIR}/EventData_nomain.o;\
	fi

${OBJECTDIR}/EventDataObject_nomain.o: ${OBJECTDIR}/EventDataObject.o EventDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EventDataObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventDataObject_nomain.o EventDataObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EventDataObject.o ${OBJECTDIR}/EventDataObject_nomain.o;\
	fi

${OBJECTDIR}/EventNotification_nomain.o: ${OBJECTDIR}/EventNotification.o EventNotification.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EventNotification.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventNotification_nomain.o EventNotification.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EventNotification.o ${OBJECTDIR}/EventNotification_nomain.o;\
	fi

${OBJECTDIR}/EventsPage_nomain.o: ${OBJECTDIR}/EventsPage.o EventsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EventsPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventsPage_nomain.o EventsPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EventsPage.o ${OBJECTDIR}/EventsPage_nomain.o;\
	fi

${OBJECTDIR}/EventsSubsystem_nomain.o: ${OBJECTDIR}/EventsSubsystem.o EventsSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EventsSubsystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventsSubsystem_nomain.o EventsSubsystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EventsSubsystem.o ${OBJECTDIR}/EventsSubsystem_nomain.o;\
	fi

${OBJECTDIR}/FileRequestHandler_nomain.o: ${OBJECTDIR}/FileRequestHandler.o FileRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FileRequestHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FileRequestHandler_nomain.o FileRequestHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FileRequestHandler.o ${OBJECTDIR}/FileRequestHandler_nomain.o;\
	fi

${OBJECTDIR}/Frame_nomain.o: ${OBJECTDIR}/Frame.o Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Frame.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Frame_nomain.o Frame.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Frame.o ${OBJECTDIR}/Frame_nomain.o;\
	fi

${OBJECTDIR}/IONDataObject_nomain.o: ${OBJECTDIR}/IONDataObject.o IONDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IONDataObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IONDataObject_nomain.o IONDataObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IONDataObject.o ${OBJECTDIR}/IONDataObject_nomain.o;\
	fi

${OBJECTDIR}/IPCache_nomain.o: ${OBJECTDIR}/IPCache.o IPCache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IPCache.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPCache_nomain.o IPCache.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IPCache.o ${OBJECTDIR}/IPCache_nomain.o;\
	fi

${OBJECTDIR}/IPData_nomain.o: ${OBJECTDIR}/IPData.o IPData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IPData.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPData_nomain.o IPData.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IPData.o ${OBJECTDIR}/IPData_nomain.o;\
	fi

${OBJECTDIR}/IPDataObserver_nomain.o: ${OBJECTDIR}/IPDataObserver.o IPDataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IPDataObserver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPDataObserver_nomain.o IPDataObserver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IPDataObserver.o ${OBJECTDIR}/IPDataObserver_nomain.o;\
	fi

${OBJECTDIR}/Injector_nomain.o: ${OBJECTDIR}/Injector.o Injector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Injector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Injector_nomain.o Injector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Injector.o ${OBJECTDIR}/Injector_nomain.o;\
	fi

${OBJECTDIR}/LibnetException_nomain.o: ${OBJECTDIR}/LibnetException.o LibnetException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LibnetException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LibnetException_nomain.o LibnetException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LibnetException.o ${OBJECTDIR}/LibnetException_nomain.o;\
	fi

${OBJECTDIR}/MAC_nomain.o: ${OBJECTDIR}/MAC.o MAC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MAC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MAC_nomain.o MAC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MAC.o ${OBJECTDIR}/MAC_nomain.o;\
	fi

${OBJECTDIR}/MailConfigPage_nomain.o: ${OBJECTDIR}/MailConfigPage.o MailConfigPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MailConfigPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MailConfigPage_nomain.o MailConfigPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MailConfigPage.o ${OBJECTDIR}/MailConfigPage_nomain.o;\
	fi

${OBJECTDIR}/MailSendPage_nomain.o: ${OBJECTDIR}/MailSendPage.o MailSendPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MailSendPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MailSendPage_nomain.o MailSendPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MailSendPage.o ${OBJECTDIR}/MailSendPage_nomain.o;\
	fi

${OBJECTDIR}/Main_nomain.o: ${OBJECTDIR}/Main.o Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main_nomain.o Main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Main.o ${OBJECTDIR}/Main_nomain.o;\
	fi

${OBJECTDIR}/NetStat_LINUX_nomain.o: ${OBJECTDIR}/NetStat_LINUX.o NetStat_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/NetStat_LINUX.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NetStat_LINUX_nomain.o NetStat_LINUX.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/NetStat_LINUX.o ${OBJECTDIR}/NetStat_LINUX_nomain.o;\
	fi

${OBJECTDIR}/PageRequestHandler_nomain.o: ${OBJECTDIR}/PageRequestHandler.o PageRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PageRequestHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PageRequestHandler_nomain.o PageRequestHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PageRequestHandler.o ${OBJECTDIR}/PageRequestHandler_nomain.o;\
	fi

${OBJECTDIR}/PcapActivity_nomain.o: ${OBJECTDIR}/PcapActivity.o PcapActivity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PcapActivity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapActivity_nomain.o PcapActivity.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PcapActivity.o ${OBJECTDIR}/PcapActivity_nomain.o;\
	fi

${OBJECTDIR}/PcapDevice_nomain.o: ${OBJECTDIR}/PcapDevice.o PcapDevice.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PcapDevice.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapDevice_nomain.o PcapDevice.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PcapDevice.o ${OBJECTDIR}/PcapDevice_nomain.o;\
	fi

${OBJECTDIR}/PcapIfaceAddress_nomain.o: ${OBJECTDIR}/PcapIfaceAddress.o PcapIfaceAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PcapIfaceAddress.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapIfaceAddress_nomain.o PcapIfaceAddress.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PcapIfaceAddress.o ${OBJECTDIR}/PcapIfaceAddress_nomain.o;\
	fi

${OBJECTDIR}/PcapSubsystem_nomain.o: ${OBJECTDIR}/PcapSubsystem.o PcapSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PcapSubsystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapSubsystem_nomain.o PcapSubsystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PcapSubsystem.o ${OBJECTDIR}/PcapSubsystem_nomain.o;\
	fi

${OBJECTDIR}/Protocol_nomain.o: ${OBJECTDIR}/Protocol.o Protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Protocol.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Protocol_nomain.o Protocol.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Protocol.o ${OBJECTDIR}/Protocol_nomain.o;\
	fi

${OBJECTDIR}/ProtocolARP_nomain.o: ${OBJECTDIR}/ProtocolARP.o ProtocolARP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolARP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolARP_nomain.o ProtocolARP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolARP.o ${OBJECTDIR}/ProtocolARP_nomain.o;\
	fi

${OBJECTDIR}/ProtocolDHCP_nomain.o: ${OBJECTDIR}/ProtocolDHCP.o ProtocolDHCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolDHCP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolDHCP_nomain.o ProtocolDHCP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolDHCP.o ${OBJECTDIR}/ProtocolDHCP_nomain.o;\
	fi

${OBJECTDIR}/ProtocolEthernet_nomain.o: ${OBJECTDIR}/ProtocolEthernet.o ProtocolEthernet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolEthernet.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolEthernet_nomain.o ProtocolEthernet.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolEthernet.o ${OBJECTDIR}/ProtocolEthernet_nomain.o;\
	fi

${OBJECTDIR}/ProtocolIP_nomain.o: ${OBJECTDIR}/ProtocolIP.o ProtocolIP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolIP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolIP_nomain.o ProtocolIP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolIP.o ${OBJECTDIR}/ProtocolIP_nomain.o;\
	fi

${OBJECTDIR}/ProtocolIPV6_nomain.o: ${OBJECTDIR}/ProtocolIPV6.o ProtocolIPV6.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolIPV6.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolIPV6_nomain.o ProtocolIPV6.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolIPV6.o ${OBJECTDIR}/ProtocolIPV6_nomain.o;\
	fi

${OBJECTDIR}/ProtocolNBDatagram_nomain.o: ${OBJECTDIR}/ProtocolNBDatagram.o ProtocolNBDatagram.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolNBDatagram.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolNBDatagram_nomain.o ProtocolNBDatagram.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolNBDatagram.o ${OBJECTDIR}/ProtocolNBDatagram_nomain.o;\
	fi

${OBJECTDIR}/ProtocolTCP_nomain.o: ${OBJECTDIR}/ProtocolTCP.o ProtocolTCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolTCP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolTCP_nomain.o ProtocolTCP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolTCP.o ${OBJECTDIR}/ProtocolTCP_nomain.o;\
	fi

${OBJECTDIR}/ProtocolUDP_nomain.o: ${OBJECTDIR}/ProtocolUDP.o ProtocolUDP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProtocolUDP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolUDP_nomain.o ProtocolUDP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProtocolUDP.o ${OBJECTDIR}/ProtocolUDP_nomain.o;\
	fi

${OBJECTDIR}/Rouing_nomain.o: ${OBJECTDIR}/Rouing.o Rouing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Rouing.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rouing_nomain.o Rouing.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Rouing.o ${OBJECTDIR}/Rouing_nomain.o;\
	fi

${OBJECTDIR}/Routing_LINUX_nomain.o: ${OBJECTDIR}/Routing_LINUX.o Routing_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Routing_LINUX.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Routing_LINUX_nomain.o Routing_LINUX.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Routing_LINUX.o ${OBJECTDIR}/Routing_LINUX_nomain.o;\
	fi

${OBJECTDIR}/ScopedTransaciton_nomain.o: ${OBJECTDIR}/ScopedTransaciton.o ScopedTransaciton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ScopedTransaciton.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScopedTransaciton_nomain.o ScopedTransaciton.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ScopedTransaciton.o ${OBJECTDIR}/ScopedTransaciton_nomain.o;\
	fi

${OBJECTDIR}/Selfy_nomain.o: ${OBJECTDIR}/Selfy.o Selfy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Selfy.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Selfy_nomain.o Selfy.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Selfy.o ${OBJECTDIR}/Selfy_nomain.o;\
	fi

${OBJECTDIR}/SendMail_nomain.o: ${OBJECTDIR}/SendMail.o SendMail.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SendMail.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SendMail_nomain.o SendMail.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SendMail.o ${OBJECTDIR}/SendMail_nomain.o;\
	fi

${OBJECTDIR}/ServerSettingsPage_nomain.o: ${OBJECTDIR}/ServerSettingsPage.o ServerSettingsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ServerSettingsPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServerSettingsPage_nomain.o ServerSettingsPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ServerSettingsPage.o ${OBJECTDIR}/ServerSettingsPage_nomain.o;\
	fi

${OBJECTDIR}/Solicitator_nomain.o: ${OBJECTDIR}/Solicitator.o Solicitator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Solicitator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solicitator_nomain.o Solicitator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Solicitator.o ${OBJECTDIR}/Solicitator_nomain.o;\
	fi

${OBJECTDIR}/Syslog_LINUX_nomain.o: ${OBJECTDIR}/Syslog_LINUX.o Syslog_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Syslog_LINUX.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Syslog_LINUX_nomain.o Syslog_LINUX.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Syslog_LINUX.o ${OBJECTDIR}/Syslog_LINUX_nomain.o;\
	fi

${OBJECTDIR}/ThingData_nomain.o: ${OBJECTDIR}/ThingData.o ThingData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ThingData.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingData_nomain.o ThingData.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ThingData.o ${OBJECTDIR}/ThingData_nomain.o;\
	fi

${OBJECTDIR}/ThingObserver_nomain.o: ${OBJECTDIR}/ThingObserver.o ThingObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ThingObserver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingObserver_nomain.o ThingObserver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ThingObserver.o ${OBJECTDIR}/ThingObserver_nomain.o;\
	fi

${OBJECTDIR}/ThingsPage_nomain.o: ${OBJECTDIR}/ThingsPage.o ThingsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ThingsPage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingsPage_nomain.o ThingsPage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ThingsPage.o ${OBJECTDIR}/ThingsPage_nomain.o;\
	fi

${OBJECTDIR}/TrafficBulk_nomain.o: ${OBJECTDIR}/TrafficBulk.o TrafficBulk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TrafficBulk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficBulk_nomain.o TrafficBulk.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TrafficBulk.o ${OBJECTDIR}/TrafficBulk_nomain.o;\
	fi

${OBJECTDIR}/TrafficData_nomain.o: ${OBJECTDIR}/TrafficData.o TrafficData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TrafficData.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficData_nomain.o TrafficData.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TrafficData.o ${OBJECTDIR}/TrafficData_nomain.o;\
	fi

${OBJECTDIR}/TrafficDataObject_nomain.o: ${OBJECTDIR}/TrafficDataObject.o TrafficDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TrafficDataObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficDataObject_nomain.o TrafficDataObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TrafficDataObject.o ${OBJECTDIR}/TrafficDataObject_nomain.o;\
	fi

${OBJECTDIR}/TrafficObserver_nomain.o: ${OBJECTDIR}/TrafficObserver.o TrafficObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TrafficObserver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrafficObserver_nomain.o TrafficObserver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TrafficObserver.o ${OBJECTDIR}/TrafficObserver_nomain.o;\
	fi

${OBJECTDIR}/WebForm_nomain.o: ${OBJECTDIR}/WebForm.o WebForm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/WebForm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebForm_nomain.o WebForm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/WebForm.o ${OBJECTDIR}/WebForm_nomain.o;\
	fi

${OBJECTDIR}/WebMenu_nomain.o: ${OBJECTDIR}/WebMenu.o WebMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/WebMenu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebMenu_nomain.o WebMenu.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/WebMenu.o ${OBJECTDIR}/WebMenu_nomain.o;\
	fi

${OBJECTDIR}/WebRequestHandlerFactory_nomain.o: ${OBJECTDIR}/WebRequestHandlerFactory.o WebRequestHandlerFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/WebRequestHandlerFactory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebRequestHandlerFactory_nomain.o WebRequestHandlerFactory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/WebRequestHandlerFactory.o ${OBJECTDIR}/WebRequestHandlerFactory_nomain.o;\
	fi

${OBJECTDIR}/WebSubsystem_nomain.o: ${OBJECTDIR}/WebSubsystem.o WebSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/WebSubsystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/NetSSL_OpenSSL/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -I../lib/poco-1.6.0-all/Crypto/include `pkg-config --cflags libssl` -std=c++11  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebSubsystem_nomain.o WebSubsystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/WebSubsystem.o ${OBJECTDIR}/WebSubsystem_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../${CND_CONF}/ion

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
