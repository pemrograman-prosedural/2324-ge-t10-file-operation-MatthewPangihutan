// NIM - Name
// NIM - Name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"
#define _SIZE 255

int main(int _argc, char **_argv)
{
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    unsigned short totalDorm = 0;
    unsigned short totalStudent = 0;
    char line[_SIZE];
    char* token;

    FILE *reader = fopen("./storage/dorm-repository.txt","r");
    while ( fgets(line, _SIZE, reader) != NULL ) {
        line[strcspn(line, "\r\n")] = 0;
        token = strtok(line,"|"); char* name = token;
        token = strtok(NULL,"|"); unsigned short capacity = atoi(token);
        token = strtok(NULL,"|"); char* gender = token;

        if ( strcmp(gender, "male") == 0 )
            dorms[totalDorm] = create_dorm(name, capacity, GENDER_MALE);
        else if ( strcmp(gender, "female") == 0 )
            dorms[totalDorm] = create_dorm(name, capacity, GENDER_FEMALE);
        totalDorm++;
    }

    reader = fopen("./storage/student-repository.txt","r");
    while ( fgets(line, _SIZE, reader) != NULL )
    {
        line[strcspn(line, "\r\n")] = 0;
        token = strtok(line,"|"); char* id = token;
        token = strtok(NULL,"|"); char* name = token;
        token = strtok(NULL,"|"); char* year = token;
        token = strtok(NULL,"|"); char* gender = token;

        if ( strcmp(gender, "male") == 0 )
            students[totalStudent] = create_student(id, name, year, GENDER_MALE);
        else if ( strcmp(gender, "female") == 0 )
            students[totalStudent] = create_student(id, name, year, GENDER_FEMALE);
        totalStudent++;
    }

    fclose(reader);

/* -------------------------- INTERACTIVE -------------------------- */

    while ( 1 ) {
        line[0] = '\0';
        fgets(line, 255, stdin);
        fflush(stdin);
        
        /* declared in scope level --> temporary
           but the result remains */

        if ( strcmp(line, "---") == 0 ) break;

        else if ( strcmp(line, "student-print-all") == 0 ) {
                print_students(students, totalStudent);
        }

        else if ( strcmp(line, "dorm-print-all") == 0 ) {
                print_dorm(dorms, totalDorm);
        }

        else if ( strcmp(line, "student-print-all-detail") == 0 ) {
                print_students_detail(students, totalStudent);
        }

        else if ( strcmp(line, "dorm-print-all-detail") == 0 ) {
                print_dorm_detail(dorms, totalDorm);
        }
    
    free(dorms);
    free(students);
    }
    return 0;
}
