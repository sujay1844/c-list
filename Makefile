BINARY=list
CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=

SRCDIR=src
BUILDDIR=build
BINDIR=bin

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
EXEC=$(BINDIR)/$(BINARY)

.PHONY: all clean build run

all: build

build: $(EXEC)

$(EXEC): $(OBJS) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: build
	./$(EXEC)

$(BUILDDIR) $(BINDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

