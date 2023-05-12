#include "status_events.h"

struct events readLineEvents(FILE* file, int idx) {
    int position = idx * sizeof(struct events);

    fseek(file, position, SEEK_SET);

    struct events line;
    fread(&line, sizeof(struct events), 1, file);

    rewind(file);

    return line;
}

void eventOutput(struct events event) {
    printf("%d ", event.event_id);
    printf("%d ", event.module_id);
    printf("%d ", event.status);
    printf("%s ", event.date);
    printf("%s", event.time);
}

int countLinesEvents(FILE* file) {
    int size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    return size / sizeof(struct events);
}

void printEventsTable(FILE* events) {
    int count = countLinesEvents(events);
    struct events line;
    int i = 0;
    for (; i < count - 1; i++) {
        line = readLineEvents(events, i);
        eventOutput(line);
        printf("\n");
    }
    line = readLineEvents(events, i);
    eventOutput(line);
}
