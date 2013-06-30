CXX = g++
CFLAGS = -g -Wall -Wextra -O2 -std=c++0x
SRCDIR = src/
INCLUDES = -I./include/
OBJDIR = obj/
OUTDIR = build/
SOURCES = $(wildcard $(SRCDIR)*.cc)
OBJS = $(SOURCES:$(SRCDIR)%.cc=$(OBJDIR)%.o)

all: pe1 pe2 pe3 pe4 pe5 pe6 pe7 pe8 pe9 pe10 \
  pe11 pe12 pe13 pe14 pe15

pe1: $(OBJDIR)pe1.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe2: $(OBJDIR)pe2.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe3: $(OBJDIR)pe3.o $(OBJDIR)divs.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o $(OBJDIR)divs.o

pe4: $(OBJDIR)pe4.o $(OBJDIR)palindrome.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o $(OBJDIR)palindrome.o

pe5: $(OBJDIR)pe5.o $(OBJDIR)gcd.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o $(OBJDIR)gcd.o

pe6: $(OBJDIR)pe6.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe7: $(OBJDIR)pe7.o $(OBJDIR)prime.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o $(OBJDIR)prime.o

pe8: $(OBJDIR)pe8.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe9: $(OBJDIR)pe9.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe10: $(OBJDIR)pe10.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe11: $(OBJDIR)pe11.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe12: $(OBJDIR)pe12.o $(OBJDIR)divs.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o $(OBJDIR)divs.o

pe13: $(OBJDIR)pe13.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe14: $(OBJDIR)pe14.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o

pe15: $(OBJDIR)pe15.o $(OBJDIR)divs.o
	$(CXX) -o $(OUTDIR)$@ $(OBJDIR)$@.o $(OBJDIR)divs.o

clean:
	-$(RM) $(OUTDIR)*.exe $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.cc
	$(CXX) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)