
/* #include <stdio.h> */
#include <stdlib.h>

#include "obj.h"
#include "ent.h"

#include "log.h"

/* getters */

#define bail_on_null(ob) { \
  if (ob == NULL) {	\
  log_push(fun); \
  log_indent(); printf("error fatal: getting from NULL grit detected,\n"); \
  log_pop(fun); \
  return NULL; } }

gunk ent_print(gunk o) {
  char* fun = "print";
  bail_on_null(o);
  log_push(fun);
  log_indent(); printf("ent(%p) {t(%p) g(%p) G(%p) p(%p)},\n",
					   (void*) o,
					   (void*) o->type,
					   (void*) o->grit,
					   (void*) o->gunk,
					   (void*) o->prop);
  log_pop(fun);
  return o;
}

gunk ent_run(gunk object) {
  gunk result;
  char* fun = "run";
  bail_on_null(object);
  log_push(fun);
  ent_print(object);
  log_indent(); printf("...ning:\n");
  if (object->prop == NULL) {
	result = object;
	log_indent(); printf("error major: entity has NULL property,\n");
  } else {
	result = (*object->prop)(object);
  }
  log_pop(fun);
  return result;
}

gunk ent_content(gunk o) {
  char* fun = "content";
  bail_on_null(o);
  return o->gunk;
}

gunk ent_extent(gunk o) {
  char* fun = "extent";
  bail_on_null(o);
  return o->grit;
}

/* ent_t?!?ype */

gunk ent() {
  return (gunk)malloc(sizeof(struct grit));
}

/* setters */

/*
  that's so god-damn-C-awful...
  temp = (gunk*)((char*)operand+(offset*sizeof(gunk)));
  perhaps using array in stead of ... ah, but then...
*/

#define on_null_grit(ob) { if (ob == NULL) { \
  log_push(fun); \
  log_indent(); printf("error fatal: setting to NULL grit detected,\n"); \
  ent_print(ob); \
  log_pop(fun); \
  return -1; } }

#define on_non_null_gunk(ob) { log_push(fun); \
  log_indent(); printf("error fatal: refusing to fill non-NULL grit,\n"); \
  ent_print(ob); \
  log_pop(fun); \
  return -1; }

int ent_extend(gunk o, gunk with) {
  char* fun = "extend";
  on_null_grit(o);
  if (o->grit == NULL) {
	o->grit = with ;
	return 0;
  } else {
	on_non_null_gunk(o);
  }
}

int ent_contain(gunk o, gunk ent) {
  char* fun = "contain";
  on_null_grit(o);
  if (o->gunk == NULL) {
	o->gunk = ent ;
	return 0;
  } else {
	on_non_null_gunk(o);
  }
}

int ent_behave(gunk o, gunk (*like)(gunk)) {
  char* fun = "behave";
  on_null_grit(o);
  if (o->prop == NULL) {
	o->prop = like ;
	return 0;
  } else {
	on_non_null_gunk(o);
  }
}
