#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
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

typedef enum {
    LARGE =1,
    MEDIUM =2,
    SMALL =3,
    STARTUP =4
    
} c_size; //company size

// typedef enum {
//     Server Manager=1,
//     MEDIUM =2,
//     SMALL =3,
//     STARTUP =5
    
// } job_positions; //job positions obviously

typedef struct _Company {
    char *name;
    c_size size;
    int salary;
    int recruitNum;
    char *coding;
    char location[60];
    char city[15];
    int positionCount;
    char positions[10][30];
} Company;

typedef struct _User {
    char name[30];
    int salary;
    char city[15];
    int workAbroad;
} User;

char *readfile(char*, int*);
int fileCheck(char*, char*);
void array_parse(char*, JSON*, int*, int*);
void object_parse(char*, JSON*, int*, int*);
void json_parse(char*, int, JSON*, int*);
void freeJson(JSON*, int);
void printResult(JSON*, int);
void makeCompanyTokens(JSON*, Company*, int, int*);
void printCompanies(Company*, int);
void searchByName(Company*, int);
void searchBySize(Company*, int);
void searchBySalary(Company*, int);
void searchByJob(Company*, int, char[][40], int);
void enterInfo(User*);
// void recommendations(User*);