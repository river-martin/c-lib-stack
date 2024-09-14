CC := clang

# compiler flags
DEBUG     := -gdwarf-4
OPTIMISE  := -O0
WARNING   := -Wall -Wextra -Wno-variadic-macros \
             -Wno-overlength-strings -pedantic
EXTRA     := -std=c11 -fPIC
CFLAGS    := $(DEBUG) $(OPTIMISE) $(WARNING) $(EXTRA)
DFLAGS    ?= # -DDEBUG

# linker flags

LDFLAGS := -L. -lstack

# commands

COMPILE:=$(CC) $(CFLAGS) $(DFLAGS)

# targets

libstack.a: build/src/stack.o
	ar rcs $@ $^

tests: test_stack

# target files

build/src/%.o: src/%.c src/%.h | build
	$(COMPILE) -c -o $@ $<

build/tests/%.o: tests/%.c libstack.a | build
	$(COMPILE) -c -o $@ $<

build/%.o: %.c | build
	$(COMPILE) -c -o $@ $<

test_stack: build/tests/test_stack.o libstack.a
	$(COMPILE) -o $@ $< $(LDFLAGS)

# target directories

build:
	mkdir -p build/src
	mkdir -p build/tests

install: libstack.a src/stack.h
	cp libstack.a /usr/local/lib
	cp src/stack.h /usr/local/include

uninstall:
	rm -f /usr/local/lib/libstack.a
	rm -f /usr/local/include/stack.h

clean:
	rm -rf build
	rm -f libstack.a
	rm -f test_stack

.PHONY: clean tests install uninstall

