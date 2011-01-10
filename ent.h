
#ifndef GDG_ENT_H
#define GDG_ENT_H

typedef struct grit* gunk;

gunk ent_print(gunk);
gunk ent_run(gunk);

gunk ent();
void ent_extend(gunk, gunk);
void ent_behave(gunk, gunk (*)(gunk));

#endif
