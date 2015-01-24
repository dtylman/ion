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
	${OBJECTDIR}/Dissect/DissectSubsystem.o \
	${OBJECTDIR}/Dissect/Frame.o \
	${OBJECTDIR}/Dissect/MAC.o \
	${OBJECTDIR}/Dissect/Protocol.o \
	${OBJECTDIR}/Dissect/ProtocolARP.o \
	${OBJECTDIR}/Dissect/ProtocolEthernet.o \
	${OBJECTDIR}/Dissect/ProtocolIP.o \
	${OBJECTDIR}/Dissect/ProtocolNBDatagram.o \
	${OBJECTDIR}/Dissect/ProtocolUDP.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/Model/HostnameModel.o \
	${OBJECTDIR}/Model/IPModel.o \
	${OBJECTDIR}/Model/Model.o \
	${OBJECTDIR}/Model/ModelSubsystem.o \
	${OBJECTDIR}/Sniff/PcapActivity.o \
	${OBJECTDIR}/Sniff/PcapIfaceAddress.o \
	${OBJECTDIR}/Sniff/PcapSubsystem.o


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
LDLIBSOPTIONS=-L../lib/poco-1.6.0-all/lib/Linux/x86_64 ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoUtild.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoJSONd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoXMLd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoFoundationd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDataSQLited.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDatad.a -lpcap -lpthread -ldl

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

${OBJECTDIR}/Dissect/DissectSubsystem.o: Dissect/DissectSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/DissectSubsystem.o Dissect/DissectSubsystem.cpp

${OBJECTDIR}/Dissect/Frame.o: Dissect/Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/Frame.o Dissect/Frame.cpp

${OBJECTDIR}/Dissect/MAC.o: Dissect/MAC.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/MAC.o Dissect/MAC.cpp

${OBJECTDIR}/Dissect/Protocol.o: Dissect/Protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/Protocol.o Dissect/Protocol.cpp

${OBJECTDIR}/Dissect/ProtocolARP.o: Dissect/ProtocolARP.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/ProtocolARP.o Dissect/ProtocolARP.cpp

${OBJECTDIR}/Dissect/ProtocolEthernet.o: Dissect/ProtocolEthernet.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/ProtocolEthernet.o Dissect/ProtocolEthernet.cpp

${OBJECTDIR}/Dissect/ProtocolIP.o: Dissect/ProtocolIP.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/ProtocolIP.o Dissect/ProtocolIP.cpp

${OBJECTDIR}/Dissect/ProtocolNBDatagram.o: Dissect/ProtocolNBDatagram.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/ProtocolNBDatagram.o Dissect/ProtocolNBDatagram.cpp

${OBJECTDIR}/Dissect/ProtocolUDP.o: Dissect/ProtocolUDP.cpp 
	${MKDIR} -p ${OBJECTDIR}/Dissect
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dissect/ProtocolUDP.o Dissect/ProtocolUDP.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/Model/HostnameModel.o: Model/HostnameModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/Model
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model/HostnameModel.o Model/HostnameModel.cpp

${OBJECTDIR}/Model/IPModel.o: Model/IPModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/Model
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model/IPModel.o Model/IPModel.cpp

${OBJECTDIR}/Model/Model.o: Model/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/Model
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model/Model.o Model/Model.cpp

${OBJECTDIR}/Model/ModelSubsystem.o: Model/ModelSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/Model
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model/ModelSubsystem.o Model/ModelSubsystem.cpp

${OBJECTDIR}/Sniff/PcapActivity.o: Sniff/PcapActivity.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sniff
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sniff/PcapActivity.o Sniff/PcapActivity.cpp

${OBJECTDIR}/Sniff/PcapIfaceAddress.o: Sniff/PcapIfaceAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sniff
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sniff/PcapIfaceAddress.o Sniff/PcapIfaceAddress.cpp

${OBJECTDIR}/Sniff/PcapSubsystem.o: Sniff/PcapSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sniff
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sniff/PcapSubsystem.o Sniff/PcapSubsystem.cpp

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
