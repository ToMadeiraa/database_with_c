#ifndef STRUCTS_H
#define STRUCTS_H

#define modules_path "../materials/master_modules.db"
#define levels_path "../materials/master_levels.db"
#define events_path "../materials/master_status_events.db"

struct modules {
    int id;
    char name[30];
    int level;
    int cell;
    int flag;
};

struct levels {
    int level;
    int cells_num;
    int pr_flag;
};

struct events {
    int event_id;
    int module_id;
    int status;
    char date[11];
    char time[9];
};

#endif