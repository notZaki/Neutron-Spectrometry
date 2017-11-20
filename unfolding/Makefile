#***************************************************************************************************
# Makefile for neutron unfolding program. Primary targets:
#	1)
#	2) 
#***************************************************************************************************

#===================================================================================================
# ROOT libraries & flags
#===================================================================================================
ROOTCFLAGS   = $(shell root-config --cflags)
ROOTLIBS     = $(shell root-config --libs)
ROOTGLIBS    = $(shell root-config --glibs)

LIBS            = $(ROOTLIBS)
GLIBS           = $(ROOTGLIBS)

ALLLIBS = $(LIBS) $(GLIBS) 

OAWGDEFFLAGS = -D_OAWG -D_OAWG_DIR="\"`pwd`\"" -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS

#===================================================================================================
# General libraries & flags
#===================================================================================================
CPP = g++
INC_DIR = include
SRC_DIR = source
OBJ_DIR = objects

GIT_COMMIT := $(shell git describe --abbrev=7 --dirty --always --tags)
GIT_CFLAG = -DGIT_COMMIT=\"$(GIT_COMMIT)\"

# Note the -I option specifies the include directory for header files, so don't need to put them
# explicitly in the make commands listed below
CFLAGS = -o $@ -Wall -O -g -std=c++11 $(GIT_CFLAG) -I$(INC_DIR) -I$(SRC_DIR)

LFLAGS = -Wall -O -g $(ROOTCFLAGS) 

OBJS = $(OBJ_DIR)/unfold_spectrum.o $(OBJ_DIR)/fileio.o $(OBJ_DIR)/handle_args.o $(OBJ_DIR)/root_helpers.o $(OBJ_DIR)/physics_calculations.o

#===================================================================================================
# Targets
#===================================================================================================
#-----------------------------------------------------------------------------
# Standard make targets
#-----------------------------------------------------------------------------
# make all targets
all: unfold_spectrum.exe

# tidy up
clean: 
	rm -rf $(OBJ_DIR)/*.o unfold_spectrum.exe

#-----------------------------------------------------------------------------
# Primary (executable) targets
#-----------------------------------------------------------------------------
unfold_spectrum.exe: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) $(ALLLIBS) -o unfold_spectrum.exe

#-----------------------------------------------------------------------------
# Intermediate (object) targets
#-----------------------------------------------------------------------------
# Note, the $< variable specifies the name of the first prerequisite for each make command (e.g.
# unfold_spectrum.cpp)
$(OBJ_DIR)/unfold_spectrum.o: $(SRC_DIR)/unfold_spectrum.cpp 
	$(CPP) -c $(CFLAGS) $<

$(OBJ_DIR)/fileio.o: $(SRC_DIR)/fileio.cpp
	$(CPP) -c $(CFLAGS) $<

$(OBJ_DIR)/handle_args.o: $(SRC_DIR)/handle_args.cpp
	$(CPP) -c $(CFLAGS) $<

$(OBJ_DIR)/root_helpers.o: $(SRC_DIR)/root_helpers.cpp
	$(CPP) -c $(CFLAGS) $(ROOTCFLAGS) $<

$(OBJ_DIR)/physics_calculations.o: $(SRC_DIR)/physics_calculations.cpp
	$(CPP) -c $(CFLAGS) $<

# The following can be used instead of the above explicit commands for each object file (except for
# those that vary in format. Both unfold_spectrum.o and root_helper.o are different).
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	$(CPP) -c $(CFLAGS) $<


	