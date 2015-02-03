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
	${OBJECTDIR}/DBTool.o \
	${OBJECTDIR}/TableIP.o \
	${OBJECTDIR}/TableOSDHCP.o \
	${OBJECTDIR}/TableOUI.o \
	${OBJECTDIR}/TableThing.o


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
LDLIBSOPTIONS=-L../lib/poco-1.6.0-all/lib/Linux/x86_64 -lPocoUtil -lPocoData -lPocoDataSQLite -lPocoFoundation -lPocoJSON -lPocoXML

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbtool

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbtool: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbtool ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DBTool.o: DBTool.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DBTool.o DBTool.cpp

${OBJECTDIR}/TableIP.o: TableIP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TableIP.o TableIP.cpp

${OBJECTDIR}/TableOSDHCP.o: TableOSDHCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TableOSDHCP.o TableOSDHCP.cpp

${OBJECTDIR}/TableOUI.o: TableOUI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TableOUI.o TableOUI.cpp

${OBJECTDIR}/TableThing.o: TableThing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TableThing.o TableThing.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbtool

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
