#ifndef Events_H
#define Events_H

#include <stdio.h>

#include "structs.h"

struct events readLineEvents(FILE* file, int idx);
void eventOutput(struct events event);
int countLinesEvents(FILE* event);
void printEventsTable(FILE* event);

#endif