#ifndef _Q7_H
#include "Pile.h"
int mime_type(char *type);
char *type_only(const char *typemime);
void find_by_mime(char *dir,char *param,Pile *P);
#endif