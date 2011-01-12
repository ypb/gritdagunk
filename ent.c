
/* #include <stdio.h> */
#include <stdlib.h>

#include "obj.h"
#include "ent.h"

#include "log.h"

gunk ent_print(gunk o) {
  log_push("print");
  log_indent(); printf("ent(%p) {t(%p) g(%p) G(%p) p(%p)}\n",
					   (void*) o,
					   (void*) o->type,
					   (void*) o->grit,
					   (void*) o->gunk,
					   (void*) o->prop);
  log_pop("print");
  return o;
}

gunk ent_run(gunk o) {
  gunk r ;
  log_push("run");
  ent_print(o);
  log_indent(); printf("...ning:\n");
  r = (*o->prop)(o);
  log_pop("run");
  return r;
}

gunk ent() {
  return (gunk)malloc(sizeof(struct grit));
}

int ent_extend(gunk o, gunk with) {
  if (o->grit == NULL) {
	o->grit = with ;
	return 0;
  } else {
	log_push("extend");
	log_indent(); printf("error fatal: refusing to fill non-empty grit\n");
	ent_print(o);
	log_pop("extend");
	return -1;
  }
}

int ent_contain(gunk o, gunk ent) {
  if (o->gunk == NULL) {
	o->gunk = ent ;
	return 0;
  } else {
	log_push("contain");
	log_indent(); printf("error fatal: refusing to fill non-empty grit\n");
	ent_print(o);
	log_pop("contain");
	return -1;
  }
}

int ent_behave(gunk o, gunk (*like)(gunk)) {
  if (o->prop == NULL) {
	o->prop = like ;
	return 0;
  } else {
	log_push("behave");
	log_indent(); printf("error fatal: refusing to fill non-empty grit\n");
	ent_print(o);
	log_pop("behave");
	return -1;
  }
}
