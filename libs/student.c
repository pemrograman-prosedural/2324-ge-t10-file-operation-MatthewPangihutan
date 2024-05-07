#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t std;
    strcpy(std.id, _id); 
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    std.gender = _gender;
    std.dorm = NULL;

    return std;
}

void print_students(struct student_t *_student, int jumlah)
{
  for(int x= 0; x<jumlah; x++){
    if(_student[x].gender == GENDER_FEMALE){
        printf("%s|%s|%s|female\n", _student[x].id, _student[x].name, _student[x].year);
        }
        else{
        printf("%s|%s|%s|male\n", _student[x].id, _student[x].name, _student[x].year);
    }
  }
}

void print_students_detail(struct student_t *_student, int jumlah){
    for(int x= 0; x<jumlah; x++){
        if(_student[x].dorm == NULL){
            if(_student[x].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|unassigned\n", _student[x].id, _student[x].name, _student[x].year);
            }
            else{
                printf("%s|%s|%s|male|unassigned\n", _student[x].id, _student[x].name, _student[x].year);
            }
        }
        else{
            if(_student[x].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|%s\n", _student[x].id, _student[x].name, _student[x].year, _student[x].dorm->name);
            }
            else{
                printf("%s|%s|%s|male|%s\n", _student[x].id, _student[x].name, _student[x].year, _student[x].dorm->name);
            }
        }
    }
}

