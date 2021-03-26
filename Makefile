BINDIR = bin
BINARY = $(shell basename $(shell pwd))

$(BINDIR)/$(BINARY): clean $(BINDIR)
	$(CC) -o $@ *.c -O3 -finstrument-functions

$(BINDIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(BINDIR)
