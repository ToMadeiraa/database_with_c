#ifndef LEVELS_H
#define LEVELS_H

#include <stdio.h>

#include "structs.h"

struct levels readLineLevels(FILE* file, int idx);
void levelOutput(struct levels level);
int countLinesLevel(FILE* levels);
void printLevelsTable(FILE* levels);
void selectLevels(FILE* levels);
void writeLineLevels(FILE* file, int idx, struct levels line);
void insertLevels(FILE* levels);
void updateLevels(FILE* levels);
void writeFileLevels(FILE* file, FILE* buf);
void deleteLevels();
#endif