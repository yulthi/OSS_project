#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOKEN_COUNT 1024

typedef enum {
    UNDEFINED = 0,
    OBJECT = 1,
    ARRAY = 2,
    STRING = 3,
    PRIMITIVE = 4

} type_t;

typedef struct {
    type_t type;
    int start;
    int end;
    int size;
    char *string;
} tok_t;

typedef struct _JSON {
    tok_t tokens[TOKEN_COUNT];
} JSON;

typedef struct _FOOD {

} FOOD;

char *readfile(char*, int*);
int fileCheck(char*, char*);
void array_parse(char*, JSON*, int*, int*);
void object_parse(char*, JSON*, int*, int*);
void json_parse(char*, int, JSON*, int*);
void freeJson(JSON*, int);
void printResult(JSON*, int);
void makeFoodToken();