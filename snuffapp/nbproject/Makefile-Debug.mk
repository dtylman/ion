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
	${OBJECTDIR}/Arping.o \
	${OBJECTDIR}/AutoJSONConfiguration.o \
	${OBJECTDIR}/DataObject.o \
	${OBJECTDIR}/DataObserver.o \
	${OBJECTDIR}/DataSubsystem.o \
	${OBJECTDIR}/DissectSubsystem.o \
	${OBJECTDIR}/Frame.o \
	${OBJECTDIR}/HostDataObject.o \
	${OBJECTDIR}/HostObserver.o \
	${OBJECTDIR}/IPCache.o \
	${OBJECTDIR}/IPDataObject.o \
	${OBJECTDIR}/IPDataObserver.o \
	${OBJECTDIR}/Injector.o \
	${OBJECTDIR}/MAC.o \
	${OBJECTDIR}/Main.o \
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
	${OBJECTDIR}/Routing_LINUX.o


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
LDLIBSOPTIONS=-L../lib/poco-1.6.0-all/lib/Linux/x86_64 ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoUtild.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoJSONd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoXMLd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoFoundationd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDataSQLited.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDatad.a -lpcap -lpthread -ldl -lnet

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoUtild.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoJSONd.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoXMLd.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoFoundationd.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetd.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDataSQLited.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDatad.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Arping.o: Arping.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arping.o Arping.cpp

${OBJECTDIR}/AutoJSONConfiguration.o: AutoJSONConfiguration.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AutoJSONConfiguration.o AutoJSONConfiguration.cpp

${OBJECTDIR}/DataObject.o: DataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObject.o DataObject.cpp

${OBJECTDIR}/DataObserver.o: DataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataObserver.o DataObserver.cpp

${OBJECTDIR}/DataSubsystem.o: DataSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataSubsystem.o DataSubsystem.cpp

${OBJECTDIR}/DissectSubsystem.o: DissectSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DissectSubsystem.o DissectSubsystem.cpp

${OBJECTDIR}/Frame.o: Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Frame.o Frame.cpp

${OBJECTDIR}/HostDataObject.o: HostDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HostDataObject.o HostDataObject.cpp

${OBJECTDIR}/HostObserver.o: HostObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HostObserver.o HostObserver.cpp

${OBJECTDIR}/IPCache.o: IPCache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPCache.o IPCache.cpp

${OBJECTDIR}/IPDataObject.o: IPDataObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPDataObject.o IPDataObject.cpp

${OBJECTDIR}/IPDataObserver.o: IPDataObserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPDataObserver.o IPDataObserver.cpp

${OBJECTDIR}/Injector.o: Injector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Injector.o Injector.cpp

${OBJECTDIR}/MAC.o: MAC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MAC.o MAC.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/PcapActivity.o: PcapActivity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapActivity.o PcapActivity.cpp

${OBJECTDIR}/PcapDevice.o: PcapDevice.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapDevice.o PcapDevice.cpp

${OBJECTDIR}/PcapIfaceAddress.o: PcapIfaceAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapIfaceAddress.o PcapIfaceAddress.cpp

${OBJECTDIR}/PcapSubsystem.o: PcapSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapSubsystem.o PcapSubsystem.cpp

${OBJECTDIR}/Protocol.o: Protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Protocol.o Protocol.cpp

${OBJECTDIR}/ProtocolARP.o: ProtocolARP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolARP.o ProtocolARP.cpp

${OBJECTDIR}/ProtocolDHCP.o: ProtocolDHCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolDHCP.o ProtocolDHCP.cpp

${OBJECTDIR}/ProtocolEthernet.o: ProtocolEthernet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolEthernet.o ProtocolEthernet.cpp

${OBJECTDIR}/ProtocolIP.o: ProtocolIP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolIP.o ProtocolIP.cpp

${OBJECTDIR}/ProtocolNBDatagram.o: ProtocolNBDatagram.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolNBDatagram.o ProtocolNBDatagram.cpp

${OBJECTDIR}/ProtocolUDP.o: ProtocolUDP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProtocolUDP.o ProtocolUDP.cpp

${OBJECTDIR}/Rouing.o: Rouing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rouing.o Rouing.cpp

${OBJECTDIR}/Routing_LINUX.o: Routing_LINUX.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Routing_LINUX.o Routing_LINUX.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
