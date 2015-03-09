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
	${OBJECTDIR}/WebForm.o \
	${OBJECTDIR}/WebMenu.o \
	${OBJECTDIR}/WebRequestHandlerFactory.o \
	${OBJECTDIR}/WebSubsystem.o


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

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../${CND_CONF}/ion

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
