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
	${OBJECTDIR}/DissectSubsystem.o \
	${OBJECTDIR}/Frame.o \
	${OBJECTDIR}/MAC.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/ModelSubsystem.o \
	${OBJECTDIR}/PcapActivity.o \
	${OBJECTDIR}/PcapIfaceAddress.o \
	${OBJECTDIR}/PcapSubsystem.o \
	${OBJECTDIR}/Protocol.o \
	${OBJECTDIR}/ProtocolARP.o \
	${OBJECTDIR}/ProtocolEthernet.o \
	${OBJECTDIR}/ProtocolIP.o \
	${OBJECTDIR}/ProtocolNBDatagram.o \
	${OBJECTDIR}/ProtocolUDP.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snuffapp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DissectSubsystem.o: DissectSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DissectSubsystem.o DissectSubsystem.cpp

${OBJECTDIR}/Frame.o: Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Frame.o Frame.cpp

${OBJECTDIR}/MAC.o: MAC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MAC.o MAC.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/ModelSubsystem.o: ModelSubsystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModelSubsystem.o ModelSubsystem.cpp

${OBJECTDIR}/PcapActivity.o: PcapActivity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PcapActivity.o PcapActivity.cpp

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
