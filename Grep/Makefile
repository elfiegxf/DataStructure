############################################################################
##                             Makefile for GERP.                          ##
############################################################################
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra 
LDFLAGS  = -std=c++11



gerp:  FSTree.o DirNode.o gerp.o hashTable.o indexfunction.o searchfuncion.o stringProcessing.o 
	${CXX} ${LDFLAGS} ${CXXFLAGS} -o gerp FSTree.o DirNode.o gerp.o hashTable.o indexfunction.o searchfuncion.o stringProcessing.o  

gerp.o:  gerp.cpp hashTable.h indexfunction.h searchfunction.h stringProcessing.h FSTree.h DirNode.h 
hashTable.o: hashTable.cpp hashTable.h 
indexfunction.o: indexfunction.cpp stringProcessing.h hashTable. h
searchfunction.o: searchfunction.cpp searchfunction.h hashTable.h 
stringProcessing.o: stringProcessing.cpp stringProcessing.h




#
# The following rules show how you can use make to automate things
# besides program building.
#
# Makefiles traditionally have a "clean" target.  The purpose is to
# clean up everything that is automatically built by make.  It's
# useful for when you want to save disk space and also when you've
# messed things up and just want to rebuild everything from scratch.
# The clean target doesn't have an prerequisites, because you don't
# need anything to be there in order to clean up!
#
# .dSYM directories are something that gets make in the Mac
# environment for debugging data, and so I delete them when cleaning
# up. 
#
clean:
	rm -rf sorter *.o *.dSYM

#
# You can even have a rule that turns your work in for you!
# You can make rules for running tests, too.
#
provide:
	provide comp15 proj2part3 README Makefile FSTree.o DirNode.o gerp.cpp hashTable.h hashTable.cpp indexfunction.h indexfunction.cpp searchfunction.h searchfunction.cpp stringProcessing.h stringProcessing.cpp FSTree.h DirNode.h
