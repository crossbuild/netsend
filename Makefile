# $Id$

ifeq ($(shell test \! -f Make.Rules || echo yes),yes)
		include Make.Rules
endif

DESTDIR=

TARGET = netsend
OBJECTS =    error.o    \
						 file.o     \
						 getopt.o   \
						 main.o     \
						 net.o      \
						 receive.o  \
						 transmit.o \
						 xfuncs.o

# Inline workaround:
# max-inline-insns-single specified the maximum size
# of a function (counted in internal gcc instructions).
# Default: 300
CFLAGS += --param max-inline-insns-single=400

all: config.h $(TARGET)

config.h: Make.Rules

Make.Rules: configure
	@if [ ! -f Make.Rules ] ; then                   \
	echo "No Make.Rules file present" ;              \
	echo "Hint: call ./configure script" ;           \
	echo "./configure --help for more information" ; \
  exit 1 ; fi

config.h: 
	@bash configure

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

install: all
	install $(TARGET) $(DESTDIR)$(BINDIR)

uninstall:
	rm $(DESTDIR)$(BINDIR)/$(TARGET)

clean :
	@rm -rf $(TARGET) $(OBJECTS) core *~

distclean: clean
	@rm -f config.h Make.Rules
