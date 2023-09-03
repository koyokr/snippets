CC = gcc
CFLAGS = -I../include/ -O2
TARGETS = hello waitpid1 waitpid2 shellex kill sigint signal1 signal2 \
	  procmask1 procmask2 waitforsignal waitforsignal2 waitforsignal3 \
	  sigsuspend setjmp restart fork
LIBCSAPP = libcsapp.so
LIBS = ./$(LIBCSAPP) -pthread

all: $(TARGETS)

hello: hello.s
	$(CC) $(CFLAGS) -o $@ $<

waitpid1: waitpid1.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

waitpid2: waitpid2.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

shellex: shellex.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

kill: kill.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

sigint: sigint.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

signal1: signal1.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

signal2: signal2.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

procmask1: procmask1.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

procmask2: procmask2.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

waitforsignal: waitforsignal.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

waitforsignal2: waitforsignal2.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

waitforsignal3: waitforsignal3.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

sigsuspend: sigsuspend.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

setjmp: setjmp.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

restart: restart.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

fork: fork.c $(LIBCSAPP)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

libcsapp.so: ../src/csapp.c
	$(CC) $(CFLAGS) -shared -fpic -o $@ $<

clean:
	rm -f $(TARGETS) *.o *.so
