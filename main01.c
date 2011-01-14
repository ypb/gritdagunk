
#include "gdg.h"

#include <stdlib.h>

#define DEFPULNUM 2

int main(int argc, char *argv[]) {
  int pulsnum, start;
  gdg_pulse(3);
  start = gdg_start();
  if (argc > 1) {
	pulsnum = atoi(argv[1]);
  } else {
	pulsnum = DEFPULNUM;
  }
  gdg_pulse(pulsnum);
  return 0;
}

