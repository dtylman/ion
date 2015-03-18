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
	${OBJECTDIR}/TableOSDHCP.o \
	${OBJECTDIR}/TableOUI.o \
	${OBJECTDIR}/TableServices.o \
	${OBJECTDIR}/Tables.o


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
LDLIBSOPTIONS=-L../lib/poco-1.6.0-all/lib/Linux/x86_64 ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoUtild.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoXMLd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoJSONd.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDataSQLited.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDatad.a ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoFoundationd.a -lpthread -ldl

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../${CND_CONF}/dbtool

../${CND_CONF}/dbtool: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoNetd.a

../${CND_CONF}/dbtool: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoUtild.a

../${CND_CONF}/dbtool: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoXMLd.a

../${CND_CONF}/dbtool: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoJSONd.a

../${CND_CONF}/dbtool: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDataSQLited.a

../${CND_CONF}/dbtool: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoDatad.a

../${CND_CONF}/dbtool: ../lib/poco-1.6.0-all/lib/Linux/x86_64/libPocoFoundationd.a

../${CND_CONF}/dbtool: ${OBJECTFILES}
	${MKDIR} -p ../${CND_CONF}
	${LINK.cc} -o ../${CND_CONF}/dbtool ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DBTool.o: DBTool.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DBTool.o DBTool.cpp

${OBJECTDIR}/TableOSDHCP.o: TableOSDHCP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TableOSDHCP.o TableOSDHCP.cpp

${OBJECTDIR}/TableOUI.o: TableOUI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TableOUI.o TableOUI.cpp

${OBJECTDIR}/TableServices.o: TableServices.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TableServices.o TableServices.cpp

${OBJECTDIR}/Tables.o: Tables.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lib/poco-1.6.0-all/Foundation/include -I../lib/poco-1.6.0-all/Util/include -I../lib/poco-1.6.0-all/XML/include -I../lib/poco-1.6.0-all/Net/include -I../lib/poco-1.6.0-all/JSON/include -I../lib/poco-1.6.0-all/Data/include -I../lib/poco-1.6.0-all/Data/SQLite/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tables.o Tables.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../${CND_CONF}/dbtool

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
