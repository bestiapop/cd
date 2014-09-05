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
	${OBJECTDIR}/algorithm/Huffman.o \
	${OBJECTDIR}/algorithm/lz77.o \
	${OBJECTDIR}/controllers/BitInStream.o \
	${OBJECTDIR}/controllers/BitOutStream.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/method/Method.o \
	${OBJECTDIR}/method/byteMethod.o \
	${OBJECTDIR}/method/huffmanMethod.o \
	${OBJECTDIR}/structures/FiniteBuffer.o \
	${OBJECTDIR}/structures/Nodo.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmancode

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmancode: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmancode ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/algorithm/Huffman.o: algorithm/Huffman.cpp 
	${MKDIR} -p ${OBJECTDIR}/algorithm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/algorithm/Huffman.o algorithm/Huffman.cpp

${OBJECTDIR}/algorithm/lz77.o: algorithm/lz77.cpp 
	${MKDIR} -p ${OBJECTDIR}/algorithm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/algorithm/lz77.o algorithm/lz77.cpp

${OBJECTDIR}/controllers/BitInStream.o: controllers/BitInStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/controllers
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controllers/BitInStream.o controllers/BitInStream.cpp

${OBJECTDIR}/controllers/BitOutStream.o: controllers/BitOutStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/controllers
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controllers/BitOutStream.o controllers/BitOutStream.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/method/Method.o: method/Method.cpp 
	${MKDIR} -p ${OBJECTDIR}/method
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/method/Method.o method/Method.cpp

${OBJECTDIR}/method/byteMethod.o: method/byteMethod.cpp 
	${MKDIR} -p ${OBJECTDIR}/method
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/method/byteMethod.o method/byteMethod.cpp

${OBJECTDIR}/method/huffmanMethod.o: method/huffmanMethod.cpp 
	${MKDIR} -p ${OBJECTDIR}/method
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/method/huffmanMethod.o method/huffmanMethod.cpp

${OBJECTDIR}/structures/FiniteBuffer.o: structures/FiniteBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/structures
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/structures/FiniteBuffer.o structures/FiniteBuffer.cpp

${OBJECTDIR}/structures/Nodo.o: structures/Nodo.cpp 
	${MKDIR} -p ${OBJECTDIR}/structures
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/structures/Nodo.o structures/Nodo.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmancode

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc