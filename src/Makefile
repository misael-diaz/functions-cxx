#!/usr/bin/make
#
# Functions				June 01, 2024
#
# source: src/Makefile
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

all: arrays carts wages

arrays:
	@$(MAKE) -C array
carts:
	@$(MAKE) -C cart
wages:
	@$(MAKE) -C wage
clean:
	@$(MAKE) -C array clean
	@$(MAKE) -C cart clean
	@$(MAKE) -C wage clean
