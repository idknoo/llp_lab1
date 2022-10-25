#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define TEXT_LENGTH_MAX   255
#define FORMAT_TEXT_LENGTH 255

#define COLUMN_TYPE_TEXT   0
#define COLUMN_TYPE_INT    1
#define COLUMN_TYPE_DOUBLE 2
#define COLUMN_TYPE_BOOL   3

typedef struct MetaDB {
    char format_text[FORMAT_TEXT_LENGTH];
    time_t created;
    time_t updated;
    size_t tables_count;
    size_t first_table_offset;
} MetaDB;

typedef struct MetaColumn {
    char name[TEXT_LENGTH_MAX];
    size_t type;
    bool is_key;
    bool is_required;
    size_t next_column_offset;
} MetaColumn;

typedef struct MetaTable {
    char name[TEXT_LENGTH_MAX];
    size_t amount_columns;
    size_t amount_rows;
    size_t first_column_offset;
    size_t first_row_offset;
    size_t next_table_offset;
} MetaTable;

typedef struct MetaRow {
    int row_size;
    size_t first_data_offset;
    size_t next_row_offset;
} MetaRow;