#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "levels.h"
#include "modules.h"
#include "shared.h"
#include "status_events.h"
#include "structs.h"

int getInput();
void menu();

int main() {
    menu();

    return 0;
}

void menu() {
    int input = 0;
    while (input != -1) {
        printf("\n-----------------------------------------\n MENU:\n");
        printf(" 0 SELECT TABLE\n 1 SHOW TABLES\n-1 EXIT\n");
        printf("-----------------------------------------\n");

        input = getInput();
        switch (input) {
            case 0:
                printf(" 0 MODULES\n 1 LEVELS\n");
                input = getInput();
                if (input == 0) modulesControll();
                if (input == 1) levelsControll();
                break;
            case 1:;
                FILE *file = fopen(modules_path, "rb+");
                printf("\n-----------------------------------------\n");
                printModulesTable(file);
                fclose(file);

                file = fopen(levels_path, "rb+");
                printf("\n-----------------------------------------\n");
                printLevelsTable(file);
                fclose(file);

                file = fopen(events_path, "rb+");
                printf("\n-----------------------------------------\n");
                printEventsTable(file);
                fclose(file);

                break;
            case -1:
                input = -1;
                break;
        }
    }
}

int getInput() {
    char *inp = malloc(256 * sizeof(char));
    fgets(inp, 256, stdin);
    int input = atoi(inp);
    free(inp);
    return input;
}
