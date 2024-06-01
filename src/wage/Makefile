#!/usr/bin/make
#
# Functions					June 01, 2024
#
# source: src/wage/Makefile
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

all: $(WAGE_BIN)

$(WAGE_BIN): $(WAGE_OBJ)
	$(CXX) $(CXXOPT) $(WAGE_OBJ) -o $(WAGE_BIN)

$(WAGE_OBJ): $(HEADERS) $(WAGE_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(WAGE_CXX) -o $(WAGE_OBJ)

clean:
	/bin/rm -f *.obj *.bin
