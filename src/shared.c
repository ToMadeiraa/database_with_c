#include <stdio.h>

#include "levels.h"
#include "modules.h"
#include "status_events.h"
#include "structs.h"

void printMenu1() {
    printf(
        "----------------------------------\n"
        " 0 SHOW MODULES\n 1 SELECT MODULES\n 2 INSERT MODULE\n"
        " 3 UPDATE MODULE\n 4 DELETE MODULE\n-1 BACK\n"
        "----------------------------------\n");
}

int modulesControll() {
    int mode;
    printMenu1();
    scanf("%d", &mode);
    if (mode == 1) {
        FILE* file = fopen(modules_path, "rb+");
        selectModules(file);
        fclose(file);
        printf("\n----------------------------------\n");
    } else if (mode == 2) {
        FILE* file = fopen(modules_path, "rb+");
        insertModules(file);
        fclose(file);
        printf("\n----------------------------------\n");
    } else if (mode == 3) {
        FILE* file = fopen(modules_path, "rb+");
        updateModules(file);
        fclose(file);
        printf("\n----------------------------------\n");
    } else if (mode == 4) {
        deleteModules();
        printf("\n----------------------------------\n");
    } else if (mode == 0) {
        FILE* file = fopen(modules_path, "rb+");
        printf("\n-----------------------------------------\n");
        printModulesTable(file);
        fclose(file);
    }

    return 0;
}

void printMenu2() {
    printf(
        "----------------------------------\n"
        " 0 SHOW LEVELS\n 1 SELECT LEVELS\n 2 INSERT LEVELS\n"
        " 3 UPDATE LEVELS\n 4 DELETE LEVELS\n-1 BACK\n"
        "----------------------------------\n");
}

int levelsControll() {
    int mode;
    printMenu2();
    scanf("%d", &mode);
    if (mode == 1) {
        FILE* file = fopen(levels_path, "rb+");
        selectLevels(file);
        fclose(file);
        printf("\n----------------------------------\n");
    } else if (mode == 2) {
        FILE* file = fopen(levels_path, "rb+");
        insertLevels(file);
        fclose(file);
        printf("\n----------------------------------\n");
    } else if (mode == 3) {
        FILE* file = fopen(levels_path, "rb+");
        updateLevels(file);
        fclose(file);
        printf("\n----------------------------------\n");
    } else if (mode == 4) {
        deleteLevels();
        printf("\n----------------------------------\n");
    } else if (mode == 0) {
        FILE* file = fopen(levels_path, "rb+");
        printf("\n-----------------------------------------\n");
        printLevelsTable(file);
        fclose(file);
    }

    return 0;
}