#########################################################
# File: makefile
# Description: Builds Lab 6 for CS 162.
#########################################################

# #'s are line-comments 

# CXX is a standard variable name used for the compiler. 
CXX = g++

# CXXFLAGS is a standard variable name for compile flags.
# -std=c++0x specifies to use a certain language version.
CXXFLAGS = -std=c++0x

# -Wall turns on all warnings
CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files. 
# Edit as needed.
SRC1 = Stack.cpp
SRC2 = Queue.cpp
SRC3 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

# HEADERS is a standard name for the header files. 
# Edit these as needed.
HEADER1 = Stack.hpp
HEADER2 = Queue.hpp
HEADERS = ${HEADER1} ${HEADER2}

# These will be your executable names. 
# Edit as needed.
PROG1 = main
PROGS = ${PROG1}

# This is the name of your document(s). 
# Edit as needed.
DOC = reflection.pdf

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
ZIP = cs162_lab6_goldfinj.zip

# This is the name of your extra files.
# Edit as needed.
FILES = 

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build availible.
# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

# Typing 'make zip' in terminal calls this build.
# This creates a compressed file for submission.
zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOC} ${FILES}  makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

