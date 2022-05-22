#************************************************************************
# Makefile(Version is Linux).
# Copyright (C) 2021-2022 NULL_703. All rights reserved.
# Created on 2021.10.7  17:40
# Created by NULL_703
# Last change time on 2022.5.21  19:31
#*************************************************************************
cpp = g++
gc = gcc
cflag = -O2 -std=c99 -Wall -s -c
flag = -O2 -std=c++11 -Wall -s -c
AsmFlag = -S -O2 -std=c++11 -Wall
AsmCflag = -S -O2 -std=c99 -Wall
cppasms = main.asm calculate.asm fileopt.asm
casms = formulas.asm functions.asm network.asm phyformula.asm hextrs.asm cpcolfunc.asm \
shvector.asm
bin = shcalc
obj = main.o calculate.o fileopt.o
Lobj = formulas.o functions.o network.o phyformula.o hextrs.o cpcolfunc.o shvector.o
lib = libformula.so

all: $(bin) $(lib)

$(bin): $(obj) $(lib)
	@echo "Build shcalc..."
	$(cpp) $(obj) -L. -lformula -s -o $(bin)
	@echo "Finish!"

%.o: %.cpp
	$(cpp) $(flag) $<

$(lib): $(Lobj)
	@echo "Build libformula..."
	$(gc) $(Lobj) -shared -s -o $(lib)
	@echo "Finish!"

%.o: %.c
	$(gc) $(cflag) -fPIC $<

.PHONY: asm
asm: $(casms) $(cppasms)
	@echo "Createing assembly file..."
	mkdir assembly
	mv "*.s" "assembly"
	@echo "Finish!"
	@echo "Tips: All assembly code into folder assembly."

$(cppasms):
%.asm: %.cpp
	$(cpp) $(AsmFlag) $<

$(casms):
%.asm: %.c
	$(gc) $(AsmCflag) $<

.PHONY: help
help:
	@echo "********************Makefile usage********************"
	@echo "Copyright (C) 2021-2022 NULL_703. All rights reserved."
	@echo "Welcome use Makefile(Linux version)! The usage in below:"
	@echo "make: build source code.(for default)"
	@echo "make clean: remove all binary file."
	@echo "make help: show help."
	@echo "make move: move all executable file."
	@echo "make asm: make assembly code."
	@echo "make install: install this program.(must use command 'sudo')"
	@echo "make uninstall: uninstall the program from your system."
	@echo "**********************End of help**********************"

.PHONY: move
move:
	@echo "Moving..."
	mkdir binary
	mv $(bin) binary
	@echo "finish!"

.PHONY: clean
clean:
	@echo "Deleting all non source code file..."
	-rm -f *.o *.asm *.s $(bin) $(lib)
	-rm -fr ./binary ./assembly
	@echo "Finish!"

.PHONY: install
install:
	@echo "installing shcalc..."
	mkdir /lib/shcalc
	cp $(lib) /lib
	cp $(bin) /lib/shcalc
	ln -s /lib/shcalc/$(bin) /bin/$(bin)
	@echo "Finish!"

.PHONY: uninstall
uninstall:
	@echo "uninstalling shcalc..."
	rm /lib/shcalc/$(bin)
	rm /lib/$(lib)
	rm /bin/$(bin)
	rm -d lib/shcalc
	@echo "Finish!"