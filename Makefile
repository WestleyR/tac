# Created by: WestleyR
# email: westleyr@nym.hush.com
# Date: Nov 5, 2019
# https://github.com/WestleyR/list-files
# Version-1.0.6
#
# The Clear BSD License
#
# Copyright (c) 2019 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

CC = gcc
CFLAGS = -Wall
TARGET = tac

PREFIX = /usr/local

MAIN = src/main-tac.c

.PHONY:
all: $(TARGET)

.PHONY:
$(TARGET): $(MAIN)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN)

.PHONY:
static: $(MAIN)
	$(CC) $(CFLAGS) -static -o $(TARGET) $(MAIN)

.PHONY:
test: $(TARGET)
	@bash ./run-tests

.PHONY:
install: $(TARGET)
	mkdir -p $(PREFIX)/bin
	cp -f $(TARGET) $(PREFIX)/bin

.PHONY:
clean:
	 rm -f $(TARGET)

.PHONY:
uninstall: $(PREFIX)/$(TARGET)
	rm -f $(PREFIX)/$(TARGET)

#
# End Makefile
#

