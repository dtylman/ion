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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Arping.o \
	${OBJECTDIR}/AutoConfiguration.o \
	${OBJECTDIR}/DHCPOSDataObject.o \
	${OBJECTDIR}/DataObject.o \
	${OBJECTDIR}/DataObserver.o \
	${OBJECTDIR}/DataSubsystem.o \
	${OBJECTDIR}/DissectSubsystem.o \
	${OBJECTDIR}/EditThingPage.o \
	${OBJECTDIR}/EventData.o \
	${OBJECTDIR}/EventDataObject.o \
	${OBJECTDIR}/EventNotification.o \
	${OBJECTDIR}/EventsPage.o \
	${OBJECTDIR}/EventsSubsystem.o \
	${OBJECTDIR}/FileRequestHandler.o \
	${OBJECTDIR}/Frame.o \
	${OBJECTDIR}/IPCache.o \
	${OBJECTDIR}/IPData.o \
	${OBJECTDIR}/IPDataObject.o \
	${OBJECTDIR}/IPDataObserver.o \
	${OBJECTDIR}/Injector.o \
	${OBJECTDIR}/MAC.o \
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
	${OBJECTDIR}/ProtocolNBDatagram.o \
	${OBJECTDIR}/ProtocolUDP.o \
	${OBJECTDIR}/Rouing.o \
	${OBJECTDIR}/Routing_LINUX.o \
	${OBJECTDIR}/SaveThingPage.o \
	${OBJECTDIR}/ScopedTransaciton.o \
	${OBJECTDIR}/Selfy.o \
	${OBJECTDIR}/SendMail.o \
	${OBJECTDIR}/Solicitator.o \
	${OBJECTDIR}/ThingDataObject.o \
	${OBJECTDIR}/ThingObserver.o \
	${OBJECTDIR}/ThingsPage.o \
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
LDLIBSOPTIONS=-L../lib/poco-1.6.0-all/lib/Linux/x86_64 -lPocoFoundation.a -lPocoUtil.a -lPocoXML.a -lPocoJSON.a -lpcap

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ion

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ion: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ion ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Arping.o: Arping.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arping.o Arping.cpp

${OBJECTDIR}/AutoConfiguration.o: AutoConfiguration.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AutoConfiguration.o AutoConfiguration.cpp

${OBJECTDIR}/DHCPOSDataObject.o: DHCPOSDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DHCPOSDataObject.o DHCPOSDataObject.cpp

${OBJECTDIR}/DataObject.o: DataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObject.o DataObject.cpp

${OBJECTDIR}/DataObserver.o: DataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObserver.o DataObserver.cpp

${OBJECTDIR}/DataSubsystem.o: DataSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataSubsystem.o DataSubsystem.cpp

${OBJECTDIR}/DissectSubsystem.o: DissectSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DissectSubsystem.o DissectSubsystem.cpp

${OBJECTDIR}/EditThingPage.o: EditThingPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EditThingPage.o EditThingPage.cpp

${OBJECTDIR}/EventData.o: EventData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventData.o EventData.cpp

${OBJECTDIR}/EventDataObject.o: EventDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventDataObject.o EventDataObject.cpp

${OBJECTDIR}/EventNotification.o: EventNotification.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventNotification.o EventNotification.cpp

${OBJECTDIR}/EventsPage.o: EventsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventsPage.o EventsPage.cpp

${OBJECTDIR}/EventsSubsystem.o: EventsSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventsSubsystem.o EventsSubsystem.cpp

${OBJECTDIR}/FileRequestHandler.o: FileRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FileRequestHandler.o FileRequestHandler.cpp

${OBJECTDIR}/Frame.o: Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Frame.o Frame.cpp

${OBJECTDIR}/IPCache.o: IPCache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPCache.o IPCache.cpp

${OBJECTDIR}/IPData.o: IPData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPData.o IPData.cpp

${OBJECTDIR}/IPDataObject.o: IPDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPDataObject.o IPDataObject.cpp

${OBJECTDIR}/IPDataObserver.o: IPDataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPDataObserver.o IPDataObserver.cpp

${OBJECTDIR}/Injector.o: Injector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Injector.o Injector.cpp

${OBJECTDIR}/MAC.o: MAC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MAC.o MAC.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/PageRequestHandler.o: PageRequestHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PageRequestHandler.o PageRequestHandler.cpp

${OBJECTDIR}/PcapActivity.o: PcapActivity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapActivity.o PcapActivity.cpp

${OBJECTDIR}/PcapDevice.o: PcapDevice.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapDevice.o PcapDevice.cpp

${OBJECTDIR}/PcapIfaceAddress.o: PcapIfaceAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapIfaceAddress.o PcapIfaceAddress.cpp

${OBJECTDIR}/PcapSubsystem.o: PcapSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapSubsystem.o PcapSubsystem.cpp

${OBJECTDIR}/Protocol.o: Protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Protocol.o Protocol.cpp

${OBJECTDIR}/ProtocolARP.o: ProtocolARP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolARP.o ProtocolARP.cpp

${OBJECTDIR}/ProtocolDHCP.o: ProtocolDHCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolDHCP.o ProtocolDHCP.cpp

${OBJECTDIR}/ProtocolEthernet.o: ProtocolEthernet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolEthernet.o ProtocolEthernet.cpp

${OBJECTDIR}/ProtocolIP.o: ProtocolIP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolIP.o ProtocolIP.cpp

${OBJECTDIR}/ProtocolNBDatagram.o: ProtocolNBDatagram.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolNBDatagram.o ProtocolNBDatagram.cpp

${OBJECTDIR}/ProtocolUDP.o: ProtocolUDP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolUDP.o ProtocolUDP.cpp

${OBJECTDIR}/Rouing.o: Rouing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rouing.o Rouing.cpp

${OBJECTDIR}/Routing_LINUX.o: Routing_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Routing_LINUX.o Routing_LINUX.cpp

${OBJECTDIR}/SaveThingPage.o: SaveThingPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SaveThingPage.o SaveThingPage.cpp

${OBJECTDIR}/ScopedTransaciton.o: ScopedTransaciton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScopedTransaciton.o ScopedTransaciton.cpp

${OBJECTDIR}/Selfy.o: Selfy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Selfy.o Selfy.cpp

${OBJECTDIR}/SendMail.o: SendMail.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SendMail.o SendMail.cpp

${OBJECTDIR}/Solicitator.o: Solicitator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solicitator.o Solicitator.cpp

${OBJECTDIR}/ThingDataObject.o: ThingDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingDataObject.o ThingDataObject.cpp

${OBJECTDIR}/ThingObserver.o: ThingObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingObserver.o ThingObserver.cpp

${OBJECTDIR}/ThingsPage.o: ThingsPage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThingsPage.o ThingsPage.cpp

${OBJECTDIR}/WebMenu.o: WebMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebMenu.o WebMenu.cpp

${OBJECTDIR}/WebRequestHandlerFactory.o: WebRequestHandlerFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebRequestHandlerFactory.o WebRequestHandlerFactory.cpp

${OBJECTDIR}/WebSubsystem.o: WebSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebSubsystem.o WebSubsystem.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ion

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
