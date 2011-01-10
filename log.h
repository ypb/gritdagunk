
#ifndef GDG_LOG_H
#define GDG_LOG_H

#include <stdio.h>

#define log(x) { log_indent() ; printf(x) ; printf("\n") ; }

void log_indent();
void log_straight(const char*, const char*);
void log_push(const char*);
void log_pop(const char*);

#endif

