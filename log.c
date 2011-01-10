
#include "log.h"

static int count = 0;
/* static int current = 0; */

void log_indent() {
  int i;
  for (i = 0; i < count ; i++) {
	printf("  ");
  }
}

void log_straight(const char* msg, const char* mrk) {
  log_indent();
  printf(msg);
  printf(mrk);
  printf("\n");
}

void log_push(const char* msg) {
  log_straight(msg, ":");
  /* current = strlen(msg); */
  /* count += current; */
  count++;
}

void log_pop(const char* msg) {
  log_straight(msg, ".");
  /* count -= current; */
  count--;
}

