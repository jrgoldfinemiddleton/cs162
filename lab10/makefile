#########################################################
# File: makefile
# Description: Builds Lab 10 for CS 162.
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

# -O2 allows for tail recursion optimization
CXXFLAGS += -O2

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files. 
# Edit as needed.
SRC1 = main.cpp
SRCS = ${SRC1}

# HEADERS is a standard name for the header files. 
# Edit these as needed.
HEADERS = 

# These will be your executable names. 
# Edit as needed.
PROG1 = main
PROGS = ${PROG1}

# This is the name of your document(s). 
# Edit as needed.
DOC = 

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
ZIP = cs162_lab10_goldfinj.zip

# This is the name of your extra files.
# Edit as needed.
FILES = reflection.pdf

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

