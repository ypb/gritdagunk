
#include "ent.h"

int main(int argc, char *argv[]) {
  gunk Reality = ent();
  ent_extend(Reality, Reality);
  ent_print(Reality);
  ent_behave(Reality, ent_print);
  ent_extend(Reality, Reality);
  ent_run(Reality);
  ent_run(Reality);
  return 0;
}

