
#include "ent.h"
#include "log.h"

/* HEY, I founddda Stack... and it's a singular hip of funny bones, doc! */

static gunk gdg_top = NULL;
static gunk gdg_edge = NULL;
static int gdg_pulses = 0;

gunk gdg_create(const char* id) {
  gunk temp;
  log_push("gdg_create");
  temp = ent();
  if (temp == NULL) {
	/* LOL, hopefully these are program data and need not further alllocum */
	log_indent(); printf("error fatal: allocation failure: (");
	printf(id); printf("),\n");
	log_pop(id);
  }
  log_indent(); printf("allocum: %s@(%p),\n", id, (void*)temp);
  log_pop("gdg_create");
  return temp;
}

gunk gdg_content_run(gunk ent) {
  gunk con;
  log_push("gdg_content_run");
  con = ent_content(ent);
  if (con == NULL) {
	log_indent(); printf("error minor: NULL content,\n");
  } else {
	/* so WHOOT?!?, we discard result ANYWAY, blech, TOPONDER!!1!1!! */
	ent_run(con);
  }
  log_pop("gdg_content_run");
  return ent_extent(ent);
}

void gdg_pulse(int num) {
  gunk next;
  gdg_pulses = num;
  next = ent_run(gdg_top);
  while (next) {
	next = ent_run(next);
  }
}

gunk gdg_pulse_end(gunk ent) {
  gunk result;
  char* fun = "gdg_pulse_end";
  gdg_pulses--;
  log_push(fun);
  log_indent(); printf("remaining pulses: ");
  printf("%d,\n", gdg_pulses);
  if (gdg_pulses <= 0) {
	/* shoulda be NULL, but... erm... */
	result = ent_extent(ent);
  } else {
	result = ent_content(ent);
  }
  log_pop(fun);
  return result;
} 

int gdg_start() {
  log_push("gdg_start");
  /* perhaps test for -1 if we already failed once around... */
  if (gdg_top == NULL) {
	gdg_top = gdg_create("gdg_top");
	if (gdg_top == NULL) {
	  log_pop("gdg_start");
	  return -1;
	}
	gdg_edge = gdg_create("gdg_edge");
	if (gdg_edge == NULL) {
	  log_pop("gdg_start");
	  return -1;
	}
	/* TODO: check status */
	ent_extend(gdg_top, gdg_edge);
	ent_behave(gdg_top, gdg_content_run);
	ent_contain(gdg_edge, gdg_top);
	ent_behave(gdg_edge, gdg_pulse_end);
	/* and what about behave? yeah, whoof! */
  }
  log_indent(); printf("success,\n");
  log_pop("gdg_start");
  return 0;
}

