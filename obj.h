
#ifndef GDG_OBJ_H
#define GDG_OBJ_H

/* This is It... Da basic block, an atom of Gunk... */

struct grit {
  /*
	type: for now, is redundant, externally motivated artifact, though
	it tries not to break uniformity of design, might be used to orient
	"grits" walker about the type of current "prop" or perhaps even to
	pack some direct C typed data into the pointer...
   */
  struct grit* type;
  /*
	grit: even a point needs a reference of a background to "differentiate"
	itself into form, and we need at least a linked list to dem "points";
	arragment into vector/arrays is purely an option and only a matter of
	external heap optimization; "imagined" types of geometry are far more
	non-trivial than rigidly contiguous, even multidimentional, sets of grits
   */
  struct grit* grit;
  /*
	gunk: to wit "real" stuff has content, and a linked list of grits is
	"our" way of managing/marshaling their timeslices and the like, so in
	this way grit pointer above is "direction out" to the next "individual",
	and gunk then is its internal representation: of stacks of actions,
	perhaps registers... the usual FSM aka closure local state (starting
	with list of outside grits from whence information/energy fluctuations
	can be injested... etc.
   */
  struct grit* gunk;
  /*
	each "brick" manifests itself as more than a mere grit reference by
	virtue of sustaining some form of activit, whether combinatorial or
	"wave"-like, it still remains to be experienced by trying to implement
	something usuful in this manner; all in all full power of C lies
	at our disposal... though as argument and return types stand it may be
	a wee bit too constraining
   */
  struct grit* (*prop) (struct grit*);
};

/*
  One may protest that grit is not atomic having four parts at least,
  gosh/darn it!, but in a way... grits are "only" struct grit* (see typedef
  in ent.h) everything else is gunk, though unit of gunkiness is one grit...
  i think single C type uniformity is desired anyway, and there is
  possibility (necessity really) of wholly or partially NULL struct grit
 */

#endif
