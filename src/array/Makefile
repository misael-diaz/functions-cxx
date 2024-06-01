#!/usr/bin/make
#
# Functions					June 01, 2024
#
# source: src/array/Makefile
# author: @misael-diaz
#
# Synopsis:
# Defines the Makefile for building the program with GNU make.
#
# Copyright (c) 2024 Misael Díaz-Maldonado
# This file is released under the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#

include make-inc

all: $(ARRAY_BIN)

$(ARRAY_BIN): $(ARRAY_OBJ)
	$(CXX) $(CXXOPT) $(ARRAY_OBJ) -o $(ARRAY_BIN)

$(ARRAY_OBJ): $(HEADERS) $(ARRAY_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(ARRAY_CXX) -o $(ARRAY_OBJ)

clean:
	/bin/rm -f *.obj *.bin
