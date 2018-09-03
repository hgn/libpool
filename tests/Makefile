SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET := tests

CC     ?= gcc
LIBS   := ../libtrifles.a
CFLAGS := -Wall -Wextra -Wunused -pipe -Wwrite-strings -Wsign-compare \
				 -Wshadow -Wformat=2 -Wundef -Wstrict-prototypes   \
				 -fno-strict-aliasing -fno-common -Wformat-security \
				 -Wformat-y2k -Winit-self -Wpacked -Wredundant-decls \
				 -Wstrict-aliasing=3 -Wswitch-default -Wswitch-enum \
				 -Wno-system-headers -Wundef -Wvolatile-register-var \
				 -Wcast-align -Wbad-function-cast -Wwrite-strings \
				 -Wold-style-definition  -Wdeclaration-after-statement \
				 -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
				 -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 \
				 -Wwrite-strings  -Waggregate-return -Wcast-qual \
				 -Wswitch-default -Wconversion -Wunreachable-code \
				 -Wno-format-extra-args -Wno-format-zero-length \
				 -Wformat-nonliteral -Werror=implicit-function-declaration
CFLAGS += -fsanitize=address  -fsanitize=undefined
CFLAGS += -D_FORTIFY_SOURCE=2 -fasynchronous-unwind-tables
CFLAGS += -fstack-protector-strong -grecord-gcc-switches
CFLAGS += -Wl,-z,defs -Wl,-z,relro -fexceptions
CFLAGS += -ftrapv
CFLAGS += -std=gnu11
CFLAGS += -Wno-unused-function
CFLAGS += -I.. -I../..
CFLAGS += -L..

CFLAGS += -ggdb3 -Werror

EXTRA_CFLAGS := -DLIBTRIFLES_DEBUG

.PHONY: all clean cscope

all: $(TARGET)

#%.o : %.c
#	$(CC) -c $(CFLAGS) $(EXTRA_CFLAGS) $(CPPFLAGS) $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS) 

cscope:
	find ${CURDIR} -name "*.[chsS]" > cscope.files
	cscope -b -q

clean:
	rm -f $(OBJ) $(TARGET)

distclean: clean
	rm -f ${CURDIR}/cscope.*

