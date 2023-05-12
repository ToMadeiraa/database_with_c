#include "levels.h"

struct levels readLineLevels(FILE* file, int idx) {
    int position = idx * sizeof(struct levels);

    fseek(file, position, SEEK_SET);

    struct levels line;
    fread(&line, sizeof(struct levels), 1, file);

    rewind(file);

    return line;
}

void levelOutput(struct levels level) {
    printf("%d ", level.level);
    printf("%d ", level.cells_num);
    printf("%d", level.pr_flag);
}

int countLinesLevel(FILE* file) {
    int size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    return size / sizeof(struct levels);
}

void printLevelsTable(FILE* levels) {
    int count = countLinesLevel(levels);
    struct levels line;
    int i = 0;
    for (; i < count - 1; i++) {
        line = readLineLevels(levels, i);
        levelOutput(line);
        printf("\n");
    }
    line = readLineLevels(levels, i);
    levelOutput(line);
}

void selectLevels(FILE* levels) {
    printf("Insert the number of records or -1 to output all of them: ");
    int count;
    scanf("%d", &count);
    int size = countLinesLevel(levels);
    if (count > size || count == -1) count = size;

    struct levels line;
    int i = 0;
    for (; i < count - 1; i++) {
        line = readLineLevels(levels, i);
        levelOutput(line);
        printf("\n");
    }
    line = readLineLevels(levels, i);
    levelOutput(line);
}

void writeLineLevels(FILE* file, int idx, struct levels line) {
    int position = idx * sizeof(struct levels);

    fseek(file, position, SEEK_SET);

    fwrite(&line, sizeof(struct levels), 1, file);
    fflush(file);
    rewind(file);
}

void insertLevels(FILE* levels) {
    printf("Insert level, number of cell and flag: ");
    struct levels new_level;
    scanf("%d%d%d", &(new_level.level), &(new_level.cells_num), &(new_level.pr_flag));
    int size = countLinesLevel(levels);
    new_level.level = size + 1;
    writeLineLevels(levels, size, new_level);
}

void updateLevels(FILE* levels) {
    printf("Insert the level you want to change: ");
    int count;
    scanf("%d", &count);
    printf("Insert level, number of cell and flag: ");
    struct levels new_level;
    scanf("%d%d%d", &(new_level.level), &(new_level.cells_num), &(new_level.pr_flag));
    new_level.level = count;
    writeLineLevels(levels, count - 1, new_level);
}

void writeFileLevels(FILE* file, FILE* buf) {
    int size = countLinesLevel(buf);
    struct levels line;
    for (int i = 0; i < size; i++) {
        line = readLineLevels(buf, i);
        writeLineLevels(file, i, line);
    }
}

void deleteLevels() {
    printf("Insert level you want to delete: ");
    int count;
    scanf("%d", &count);

    FILE* file = fopen(levels_path, "ab+");
    FILE* buf = tmpfile();
    struct levels line;
    int size = countLinesLevel(file);
    for (int i = 0, k = 0; i < size; i++) {
        line = readLineLevels(file, i);
        if (line.level != count) {
            writeLineLevels(buf, k, line);
            k++;
        }
    }
    fclose(file);

    file = fopen(levels_path, "wb+");
    writeFileLevels(file, buf);
    fclose(buf);
}
