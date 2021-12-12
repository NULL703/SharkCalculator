#************************************************************************
# Makefile(Version is Linux).
# Copyright (C) 2021 NULL_703. All rights reserved.
# Created on 2021.10.7  17:40
# Created by NULL_703
# Last change time on 2021.12.6  20:43
#*************************************************************************
cpp = g++
gc = gcc
cflag = -O2 -std=c99 -Wall -s -c
flag = -O2 -std=c++11 -Wall -s -c
AsmFlag = -S -O2 -std=c++11 -Wall
AsmCflag = -S -O2 -std=c99 -Wall
asms = main.asm calculate.asm formulas.asm functions.asm network.asm
bin = shcalc
obj = main.o calculate.o
Lobj = formulas.o functions.o network.o
lib = libformula.so

all: $(bin) $(lib)

$(bin): $(obj) $(lib)
	@echo "Build shcalc..."
	$(cpp) $(obj) -L. -lformula -s -o $(bin)
	@echo "Finish!"

main.o: main.cpp
	$(cpp) $(flag) main.cpp -o main.o

calculate.o: calculate.cpp
	$(cpp) $(flag) calculate.cpp -o calculate.o

$(lib): $(Lobj)
	@echo "Build libformula..."
	$(gc) $(Lobj) -shared -s -o $(lib)
	@echo "Finish!"

formulas.o: formulas.c
	$(gc) $(cflag) -fPIC formulas.c -o formulas.o

network.o: network.c
	$(gc) $(cflag) -fPIC network.c -o network.o

functions.o: functions.c
	$(gc) $(cflag) -fPIC functions.c -o functions.o

.PHONY: asm
asm: $(asms)
	@echo "Createing assembly file..."
	mkdir assembly
	mv $(asms) assembly
	@echo "Finish!"
	@echo "Tips: All assembly code into folodr assembly."
main.asm: main.cpp
	$(cpp) $(AsmFlag) main.cpp -o main.asm

calculate.asm: calculate.cpp
	$(cpp) $(Asmflag) -S calculate.cpp -o calculate.asm

formulas.asm: formulas.c
	$(gc) $(AsmCflag) formulas.c -o formulas.asm

functions.asm: functions.c
	$(gc) $(AsmCflag) functions.c -o functions.asm

network.asm: network.c
	$(gc) $(AsmCflag) network.c -o network.asm

.PHONY: help
help:
	@echo "********************Makefile usage********************"
	@echo "Copyright (C) 2021 NULL_703, All rights reserved."
	@echo "Welcome use Makefile(Linux version)! The usage in bolow:"
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
	-rm -f *.o *.asm $(bin)
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