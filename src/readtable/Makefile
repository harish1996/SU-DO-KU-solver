.PHONY=all

PROJ_DIR=../..
INC_DIR=$(PROJ_DIR)/inc
SRC_DIR=$(PROJ_DIR)/src
PRETTYPRINT=$(SRC_DIR)/prettyprint
INCLUDE_DIRS = -I$(INC_DIR)

DEPENDENCIES = readtable.o \
	       $(PRETTYPRINT)/prettyprint.o

all: $(DEPENDENCIES)
	g++ $(INCLUDE_DIRS) $(DEPENDENCIES) -o readtable.out

%.o : %.cpp
	g++ $(INCLUDE_DIRS) -c $< -o $@
