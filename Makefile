# Top level makefile, the real stuff  is at src/Makefile

default: all

.DEFAULT:
	cd src && $(MAKE) $@

install:
	cd src && $(MAKE) $@

.PHONY: install

run:
	src/smlispy

clean:
	cd src && rm -f smlispy
