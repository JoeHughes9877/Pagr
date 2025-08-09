OBJDIR = obj
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
LDFLAGS = -lncursesw

SRC = $(wildcard src/*.c) $(wildcard file_formats/*.c)
OBJ = $(patsubst src/%.c,$(OBJDIR)/src/%.o,$(filter src/%.c,$(SRC))) \
      $(patsubst file_formats/%.c,$(OBJDIR)/file_formats/%.o,$(filter file_formats/%.c,$(SRC)))
TARGET = pagr

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/src/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/file_formats/%.o: file_formats/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)
