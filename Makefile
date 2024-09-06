CC := clang

# compiler flags
DEBUG     := -ggdb -gdwarf-4
OPTIMISE  := -O0
WARNING   := -Wall -Wextra -Wno-variadic-macros \
             -Wno-overlength-strings -pedantic
EXTRA     := -std=c11 -fPIC
CFLAGS    := $(DEBUG) $(OPTIMISE) $(WARNING) $(EXTRA)
DFLAGS    ?= # -DDEBUG

# linker flags

# commands

COMPILE:=$(CC) $(CFLAGS) $(DFLAGS)

# targets

lib: build build/libstack.a

tests: test_stack

# target files

build/src/%.o: src/%.c src/%.h | build
	$(COMPILE) -c -o $@ $<

build/%.o: %.c | build
	$(COMPILE) -c -o $@ $<

build/libstack.a: build/src/stack.o | build
	ar rcs $@ $^

test_stack: build/src/stack.o build/tests/test_stack.o | build
	$(COMPILE) -o $@ $^ $(LDFLAGS)

# target directories

build:
	mkdir -p build
	mkdir -p build/src
	mkdir -p build/tests

install: build/libstack.a src/stack.h
	cp build/libstack.a /usr/local/lib
	cp src/stack.h /usr/local/include

clean:
	rm -rf build
	rm -f test_stack

.PHONY: clean tests install uninstall