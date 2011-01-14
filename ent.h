
#ifndef GDG_ENT_H
#define GDG_ENT_H

typedef struct grit* gunk;

gunk ent_print(gunk);
gunk ent_run(gunk);
gunk ent_content(gunk);
gunk ent_extent(gunk);

gunk ent();

/* not yet needed but it's a matter of c&p (bah) */
/* int ent_type(gunk, gunk); */

/* exo-tend? connect? hmmm... */
int ent_extend(gunk, gunk);

/* supplement? since extend is "atomic"... endo-tend */
int ent_contain(gunk, gunk);

int ent_behave(gunk, gunk (*)(gunk));

#endif
