############################################################################
##                             Makefile for Nozama                ##
############################################################################
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra
LDFLAGS  = -g3

#
# Here are the rules!  Each rule has a "target" followed by a colon.
# After the colon, is a list of "dependencies" (also called
# "prerequisites") all on one line.  These are files that must already
# exist and be up-to-date before you can make the target.  So, the
# first rule below says that you'd like define how to make a thing
# called "hookbook," and that depends on 4 .o files.  You may follow
# that line with a recipe as a series of one line commands indented
# with a tab character (yes, it must be a tab character!).  In this
# first rule, if you have all the .o files up-to-date, you make a
# hookbook by running clang++ with the flags specified above giving it
# all the .o files and producing leaving the executable output in a
# file named "hookbook."
# 
#
Nozamas: main.o Nozama.o PackageQueue.o ProcessQueue.o Orderqueue.o Parser.o
	${CXX} ${LDFLAGS} -o Nozamas  main.o Nozama.o PackageQueue.o ProcessQueue.o Orderqueue.o Parser.o 

#
# The following rules don't have recipes.  The make program has a ton
# of built-in rules, and it knows that if you want a X.o file and you
# have an X.cpp, it can compile the .cpp file to make a .o file.
# Furthermore, if the conventionally known variables CXX and CXXFLAGS
# are defined, it will use them!  What it doesn't know is what files
# besides the .cpp file the program module might depend on.  So, we
# only specify the target and dependencies here. 
#
main.o:  main.cpp
Nozama.o :Nozama.cpp Nozama.h
Orderqueue.o : Orderqueue.h Orderqueue.cpp Order.h Order.cpp
ProcessQueue.o :ProcessQueue.h ProcessQueue.cpp
PackageQueue.o: PackageQueue.cpp PackageQueue.h
Parser.o: Parser.h Parser.cpp


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
	rm -rf Nozamas *.o *.dSYM

#
# You can even have a rule that turns your work in for you!
# You can make rules for running tests, too.
#
provide:
	provide comp15 proj1 Orderqueue.h Orderqueue.cpp main.cpp Nozama.cpp Nozama.h Orderqueue.h Orderqueue.cpp Order.h Order.cpp ProcessQueue.h ProcessQueue.cpp PackageQueue.cpp PackageQueue.h Parser.h Parser.cpp testOrderqueue.cpp README orderinfo
 