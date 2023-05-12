#ifndef MODULES_H
#define MODULES_H

#include <stdio.h>

#include "structs.h"

struct modules readLineModules(FILE* file, int idx);
void moduleOutput(struct modules module);
int countLinesModule(FILE* file);
void printModulesTable(FILE* modules);
void selectModules(FILE* modules);
void writeLineModules(FILE* file, int idx, struct modules line);
void insertModules(FILE* modules);
void updateModules(FILE* modules);
void writeFileModules(FILE* file, FILE* buf);
void deleteModules();
void deleteModulesById();

#endif