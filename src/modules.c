#include "modules.h"

struct modules readLineModules(FILE* file, int idx) {
    int position = idx * sizeof(struct modules);

    fseek(file, position, SEEK_SET);

    struct modules line;
    fread(&line, sizeof(struct modules), 1, file);

    rewind(file);

    return line;
}

void moduleOutput(struct modules module) {
    printf("%d ", module.id);
    printf("%s ", module.name);
    printf("%d ", module.level);
    printf("%d ", module.cell);
    printf("%d", module.flag);
}

int countLinesModule(FILE* file) {
    int size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    return size /= sizeof(struct modules);
}

void printModulesTable(FILE* modules) {
    int count = countLinesModule(modules);
    struct modules line;
    int i = 0;
    for (; i < count - 1; i++) {
        line = readLineModules(modules, i);
        moduleOutput(line);
        printf("\n");
    }
    line = readLineModules(modules, i);
    moduleOutput(line);
}

void selectModules(FILE* modules) {
    printf("Insert the number of records or -1 to output all of them: ");
    int count;
    scanf("%d", &count);
    int size = countLinesModule(modules);
    if (count > size || count == -1) count = size;

    struct modules line;
    int i = 0;
    for (; i < count - 1; i++) {
        line = readLineModules(modules, i);
        moduleOutput(line);
        printf("\n");
    }
    line = readLineModules(modules, i);
    moduleOutput(line);
}

void writeLineModules(FILE* file, int idx, struct modules line) {
    int position = idx * sizeof(struct modules);

    fseek(file, position, SEEK_SET);

    fwrite(&line, sizeof(struct modules), 1, file);
    fflush(file);
    rewind(file);
}

void insertModules(FILE* modules) {
    printf("Insert level, cell and flag of module: ");
    struct modules new_module;
    char name[30] = "Custom module\0";
    int i = 0;
    while (name[i]) {
        new_module.name[i] = name[i];
        i++;
    }
    new_module.name[i] = '\0';

    scanf("%d%d%d", &(new_module.level), &(new_module.cell), &(new_module.flag));
    int size = countLinesModule(modules);
    new_module.id = size;

    writeLineModules(modules, size, new_module);
}

void updateModules(FILE* modules) {
    printf("Insert the number of module you want to change: ");
    int count;
    scanf("%d", &count);
    printf("Insert level, cell and flag of module: ");
    struct modules new_module;
    char name[30] = "Custom module\0";
    int i = 0;
    while (name[i]) {
        new_module.name[i] = name[i];
        i++;
    }
    new_module.name[i] = '\0';
    scanf("%d%d%d", &(new_module.level), &(new_module.cell), &(new_module.flag));
    new_module.id = count;
    writeLineModules(modules, count, new_module);
}

void writeFileModules(FILE* file, FILE* buf) {
    int size = countLinesModule(buf);
    struct modules line;
    for (int i = 0; i < size; i++) {
        line = readLineModules(buf, i);
        writeLineModules(file, i, line);
    }
}

void deleteModules() {
    printf("Insert id of module you want to delete: ");
    int count;
    scanf("%d", &count);

    FILE* file = fopen(modules_path, "ab+");
    FILE* buf = tmpfile();
    struct modules line;
    int size = countLinesModule(file);
    for (int i = 0, k = 0; i < size; i++) {
        line = readLineModules(file, i);
        if (line.id != count) {
            writeLineModules(buf, k, line);
            k++;
        }
    }
    fclose(file);

    file = fopen(modules_path, "wb+");
    writeFileModules(file, buf);
    fclose(buf);
}
