#########################################################
# File: makefile
# Description: Builds Assignment 5 for CS 162.
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
SRCS =  AidEvent.cpp DrunkEvent.cpp EmptySystem.cpp EnemySystem.cpp
SRCS += Fighter.cpp FightEvent.cpp Finale.cpp FriendlySystem.cpp
SRCS += Game.cpp HiScore.cpp Info.cpp KeyItemEvent.cpp main.cpp Map.cpp
SRCS += Menu.cpp MonetaryEvent.cpp NeutralSystem.cpp Pilot.cpp
SRCS += System.cpp TaxEvent.cpp utilities.cpp Weapon.cpp

# HEADERS is a standard name for the header files. 
# Edit these as needed.
HEADERS =  AidEvent.hpp Bolq.hpp Direction.hpp DrunkEvent.hpp EmptySystem.hpp
HEADERS += EnemySystem.hpp Event.hpp Fighter.hpp FightEvent.hpp Finale.hpp
HEADERS += FriendlySystem.hpp Game.hpp HiScore.hpp Info.hpp Item.hpp
HEADERS += KeyItemEvent.hpp Lamborqini.hpp Map.hpp Menu.hpp MonetaryEvent.hpp
HEADERS += NeutralSystem.hpp Pilot.hpp Raw.hpp SleazeLiner.hpp Suxel.hpp
HEADERS += System.hpp TaxEvent.hpp TrollE.hpp utilities.hpp Voltsweeper.hpp
HEADERS += Weapon.hpp Windweeper.hpp

# These will be your executable names. 
# Edit as needed.
PROG1 = main

# This is the name of your document(s). 
# Edit as needed.
DOC = reflection.pdf

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
ZIP = cs162_assn5_goldfinj.zip

# This is name of the directory containing needed text files.
TXT_DIR = text

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build availible.
# In this case, default.
#default:
#	${CXX} ${SRCS} -o ${PROG1}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

# Typing 'make zip' in terminal calls this build.
# This creates a compressed file for submission.
zip:
	zip -r ${ZIP} ${SRCS} ${HEADERS} ${DOC} makefile ${TXT_DIR}

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

