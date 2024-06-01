#!/usr/bin/make
#
# Functions					June 01, 2024
#
# source: src/cart/Makefile
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

all: $(CART_BIN)

$(CART_BIN): $(CART_OBJ)
	$(CXX) $(CXXOPT) $(CART_OBJ) -o $(CART_BIN)

$(CART_OBJ): $(HEADERS) $(CART_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(CART_CXX) -o $(CART_OBJ)

clean:
	/bin/rm -f *.obj *.bin
