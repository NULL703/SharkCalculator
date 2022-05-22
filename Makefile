all: build

build:
	make -f src/Makefile

.PHONY: clean
clean:
	make -f src/Makefile clean

.PHONY: install
install:
	make -f src/Makefile install