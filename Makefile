# automatically generated makefile by ./scripts/create-make

CFLAGS=-Wall -g -std=gnu99 -I./include -L./lib

LIBS=-lpthread -litsky


all: lib/libitsky.a processes/fork-write-twice processes/daemonize processes/fork-wait processes/daemonize-with-pipe processes/extract processes/transmit-via-pipe io/tty-read io/stdio-stat io/lowlevel-read-write io/stdin-read io/read-string-array io/reading-deleted-file io/shared-locking io/highlevel-io io/advisory-locking-blocking io/file-stat io/lowlevel-io io/lockf-file-part1 io/reading-dir-short io/lockf-file-part2 io/abc-lowlevel io/not-reading-dir io/advisory-locking io/failing-io io/reading-dir io/password-test io/abc-highlevel threads/thread_return threads/thread-param-trap threads/thread-id threads/condition threads/timedlock threads/threadf threads/thread threads/thread_write_once threads/exit-pthread-exit threads/nonblocking threads/mutex-reentrance threads/mutex-order threads/deadlock threads/barriere ipc/shared-memory ipc/signal ipc/msgqueue-positive-typed ipc/daemonize-group-signal-sigaction ipc/semaphore ipc/msgqueue-simple ipc/shared-memory-count-simple ipc/mutex-ipc-separate ipc/mutex-ipc ipc/posix-sem-ipc ipc/semaphore-simple ipc/daemonize-group-signal ipc/shared-memory-count-simple-posix ipc/daemonize-signal-and-pipe ipc/msgqueue ipc/msgqueue-hello ipc/sysv-sem-ipc ipc/shared-memory-count-output-semaphore ipc/msgqueue-negative-typed ipc/shared-memory-count

clean:
	rm -f lib/libitsky.a processes/fork-write-twice processes/daemonize processes/fork-wait processes/daemonize-with-pipe processes/extract processes/transmit-via-pipe io/tty-read io/stdio-stat io/lowlevel-read-write io/stdin-read io/read-string-array io/reading-deleted-file io/shared-locking io/highlevel-io io/advisory-locking-blocking io/file-stat io/lowlevel-io io/lockf-file-part1 io/reading-dir-short io/lockf-file-part2 io/abc-lowlevel io/not-reading-dir io/advisory-locking io/failing-io io/reading-dir io/password-test io/abc-highlevel threads/thread_return threads/thread-param-trap threads/thread-id threads/condition threads/timedlock threads/threadf threads/thread threads/thread_write_once threads/exit-pthread-exit threads/nonblocking threads/mutex-reentrance threads/mutex-order threads/deadlock threads/barriere ipc/shared-memory ipc/signal ipc/msgqueue-positive-typed ipc/daemonize-group-signal-sigaction ipc/semaphore ipc/msgqueue-simple ipc/shared-memory-count-simple ipc/mutex-ipc-separate ipc/mutex-ipc ipc/posix-sem-ipc ipc/semaphore-simple ipc/daemonize-group-signal ipc/shared-memory-count-simple-posix ipc/daemonize-signal-and-pipe ipc/msgqueue ipc/msgqueue-hello ipc/sysv-sem-ipc ipc/shared-memory-count-output-semaphore ipc/msgqueue-negative-typed ipc/shared-memory-count

lib/libitsky.a: lib/lib.c
	gcc -c $(CFLAGS) lib/lib.c -o lib/lib.o
	ar crs lib/libitsky.a lib/lib.o

processes/fork-write-twice: processes/fork-write-twice.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) processes/fork-write-twice.c $(LIBS) -o processes/fork-write-twice

processes/daemonize: processes/daemonize.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) processes/daemonize.c $(LIBS) -o processes/daemonize

processes/fork-wait: processes/fork-wait.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) processes/fork-wait.c $(LIBS) -o processes/fork-wait

processes/daemonize-with-pipe: processes/daemonize-with-pipe.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) processes/daemonize-with-pipe.c $(LIBS) -o processes/daemonize-with-pipe

processes/extract: processes/extract.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) processes/extract.c $(LIBS) -o processes/extract

processes/transmit-via-pipe: processes/transmit-via-pipe.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) processes/transmit-via-pipe.c $(LIBS) -o processes/transmit-via-pipe

io/tty-read: io/tty-read.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/tty-read.c $(LIBS) -o io/tty-read

io/stdio-stat: io/stdio-stat.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/stdio-stat.c $(LIBS) -o io/stdio-stat

io/lowlevel-read-write: io/lowlevel-read-write.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/lowlevel-read-write.c $(LIBS) -o io/lowlevel-read-write

io/stdin-read: io/stdin-read.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/stdin-read.c $(LIBS) -o io/stdin-read

io/read-string-array: io/read-string-array.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/read-string-array.c $(LIBS) -o io/read-string-array

io/reading-deleted-file: io/reading-deleted-file.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/reading-deleted-file.c $(LIBS) -o io/reading-deleted-file

io/shared-locking: io/shared-locking.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/shared-locking.c $(LIBS) -o io/shared-locking

io/highlevel-io: io/highlevel-io.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/highlevel-io.c $(LIBS) -o io/highlevel-io

io/advisory-locking-blocking: io/advisory-locking-blocking.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/advisory-locking-blocking.c $(LIBS) -o io/advisory-locking-blocking

io/file-stat: io/file-stat.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/file-stat.c $(LIBS) -o io/file-stat

io/lowlevel-io: io/lowlevel-io.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/lowlevel-io.c $(LIBS) -o io/lowlevel-io

io/lockf-file-part1: io/lockf-file-part1.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/lockf-file-part1.c $(LIBS) -o io/lockf-file-part1

io/reading-dir-short: io/reading-dir-short.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/reading-dir-short.c $(LIBS) -o io/reading-dir-short

io/lockf-file-part2: io/lockf-file-part2.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/lockf-file-part2.c $(LIBS) -o io/lockf-file-part2

io/abc-lowlevel: io/abc-lowlevel.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/abc-lowlevel.c $(LIBS) -o io/abc-lowlevel

io/not-reading-dir: io/not-reading-dir.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/not-reading-dir.c $(LIBS) -o io/not-reading-dir

io/advisory-locking: io/advisory-locking.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/advisory-locking.c $(LIBS) -o io/advisory-locking

io/failing-io: io/failing-io.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/failing-io.c $(LIBS) -o io/failing-io

io/reading-dir: io/reading-dir.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/reading-dir.c $(LIBS) -o io/reading-dir

io/password-test: io/password-test.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/password-test.c $(LIBS) -o io/password-test

io/abc-highlevel: io/abc-highlevel.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) io/abc-highlevel.c $(LIBS) -o io/abc-highlevel

threads/thread_return: threads/thread_return.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/thread_return.c $(LIBS) -o threads/thread_return

threads/thread-param-trap: threads/thread-param-trap.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/thread-param-trap.c $(LIBS) -o threads/thread-param-trap

threads/thread-id: threads/thread-id.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/thread-id.c $(LIBS) -o threads/thread-id

threads/condition: threads/condition.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/condition.c $(LIBS) -o threads/condition

threads/timedlock: threads/timedlock.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/timedlock.c $(LIBS) -o threads/timedlock

threads/threadf: threads/threadf.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/threadf.c $(LIBS) -o threads/threadf

threads/thread: threads/thread.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/thread.c $(LIBS) -o threads/thread

threads/thread_write_once: threads/thread_write_once.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/thread_write_once.c $(LIBS) -o threads/thread_write_once

threads/exit-pthread-exit: threads/exit-pthread-exit.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/exit-pthread-exit.c $(LIBS) -o threads/exit-pthread-exit

threads/nonblocking: threads/nonblocking.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/nonblocking.c $(LIBS) -o threads/nonblocking

threads/mutex-reentrance: threads/mutex-reentrance.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/mutex-reentrance.c $(LIBS) -o threads/mutex-reentrance

threads/mutex-order: threads/mutex-order.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/mutex-order.c $(LIBS) -o threads/mutex-order

threads/deadlock: threads/deadlock.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/deadlock.c $(LIBS) -o threads/deadlock

threads/barriere: threads/barriere.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) threads/barriere.c $(LIBS) -o threads/barriere

ipc/shared-memory: ipc/shared-memory.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/shared-memory.c $(LIBS) -o ipc/shared-memory

ipc/signal: ipc/signal.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/signal.c $(LIBS) -o ipc/signal

ipc/msgqueue-positive-typed: ipc/msgqueue-positive-typed.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/msgqueue-positive-typed.c $(LIBS) -o ipc/msgqueue-positive-typed

ipc/daemonize-group-signal-sigaction: ipc/daemonize-group-signal-sigaction.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/daemonize-group-signal-sigaction.c $(LIBS) -o ipc/daemonize-group-signal-sigaction

ipc/semaphore: ipc/semaphore.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/semaphore.c $(LIBS) -o ipc/semaphore

ipc/msgqueue-simple: ipc/msgqueue-simple.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/msgqueue-simple.c $(LIBS) -o ipc/msgqueue-simple

ipc/shared-memory-count-simple: ipc/shared-memory-count-simple.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/shared-memory-count-simple.c $(LIBS) -o ipc/shared-memory-count-simple

ipc/mutex-ipc-separate: ipc/mutex-ipc-separate.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/mutex-ipc-separate.c $(LIBS) -o ipc/mutex-ipc-separate

ipc/mutex-ipc: ipc/mutex-ipc.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/mutex-ipc.c $(LIBS) -o ipc/mutex-ipc

ipc/posix-sem-ipc: ipc/posix-sem-ipc.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/posix-sem-ipc.c $(LIBS) -o ipc/posix-sem-ipc

ipc/semaphore-simple: ipc/semaphore-simple.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/semaphore-simple.c $(LIBS) -o ipc/semaphore-simple

ipc/daemonize-group-signal: ipc/daemonize-group-signal.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/daemonize-group-signal.c $(LIBS) -o ipc/daemonize-group-signal

ipc/shared-memory-count-simple-posix: ipc/shared-memory-count-simple-posix.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/shared-memory-count-simple-posix.c $(LIBS) -o ipc/shared-memory-count-simple-posix

ipc/daemonize-signal-and-pipe: ipc/daemonize-signal-and-pipe.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/daemonize-signal-and-pipe.c $(LIBS) -o ipc/daemonize-signal-and-pipe

ipc/msgqueue: ipc/msgqueue.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/msgqueue.c $(LIBS) -o ipc/msgqueue

ipc/msgqueue-hello: ipc/msgqueue-hello.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/msgqueue-hello.c $(LIBS) -o ipc/msgqueue-hello

ipc/sysv-sem-ipc: ipc/sysv-sem-ipc.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/sysv-sem-ipc.c $(LIBS) -o ipc/sysv-sem-ipc

ipc/shared-memory-count-output-semaphore: ipc/shared-memory-count-output-semaphore.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/shared-memory-count-output-semaphore.c $(LIBS) -o ipc/shared-memory-count-output-semaphore

ipc/msgqueue-negative-typed: ipc/msgqueue-negative-typed.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/msgqueue-negative-typed.c $(LIBS) -o ipc/msgqueue-negative-typed

ipc/shared-memory-count: ipc/shared-memory-count.c lib/libitsky.a include/itskylib.h
	gcc $(CFLAGS) ipc/shared-memory-count.c $(LIBS) -o ipc/shared-memory-count


