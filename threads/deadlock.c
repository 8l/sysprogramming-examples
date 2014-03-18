/* (C) IT Sky Consulting GmbH 2014
 * http://www.it-sky-consulting.com/
 * Author: Karl Brodowsky
 * Date: 2014-02-27
 * License: GPL v2 (See https://de.wikipedia.org/wiki/GNU_General_Public_License )
 */


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#include <itskylib.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void *thread_run(void *ptr) {
  
  printf("in child thread: getting mutex2\n");
  pthread_mutex_lock(&mutex2);
  printf("in child thread: got mutex2\n");
  sleep(5);
  printf("in child thread: getting mutex1\n");
  pthread_mutex_lock(&mutex1);
  printf("in child thread: got mutex1\n");
  sleep(5);
  printf("in child thread: releasing\n");
  pthread_mutex_unlock(&mutex1);
  pthread_mutex_unlock(&mutex2);
  printf("in child thread: done\n");

  return (void *) NULL;
}

int main(int argc, char *argv[]) {
  pthread_t thread1;
  int retcode;
  retcode = pthread_mutex_init(&mutex1, NULL);
  handle_thread_error(retcode, "pthread_mutex_init (1)", PROCESS_EXIT);
  retcode = pthread_mutex_init(&mutex2, NULL);
  handle_thread_error(retcode, "pthread_mutex_init (2)", PROCESS_EXIT);

  retcode = pthread_create(&thread1, NULL, thread_run, NULL);
  handle_thread_error(retcode, "pthread_create", PROCESS_EXIT);
  
  printf("in parent thread: getting mutex1\n");
  pthread_mutex_lock(&mutex1);
  printf("in parent thread: got mutex1\n");
  sleep(5);
  printf("in parent thread: getting mutex2\n");
  pthread_mutex_lock(&mutex2);
  printf("in parent thread: got mutex2\n");
  sleep(5);
  printf("in parent thread: releasing\n");
  pthread_mutex_unlock(&mutex2);
  pthread_mutex_unlock(&mutex1);
  printf("in parent thread: done\n");

  retcode = pthread_join( thread1, NULL);
  handle_thread_error(retcode, "pthread_join", PROCESS_EXIT);

  retcode = pthread_mutex_destroy(&mutex1);
  handle_thread_error(retcode, "pthread_mutex_destroy", PROCESS_EXIT);
  retcode = pthread_mutex_destroy(&mutex2);
  handle_thread_error(retcode, "pthread_mutex_destroy", PROCESS_EXIT);
  printf("done\n");
  exit(0);
}
