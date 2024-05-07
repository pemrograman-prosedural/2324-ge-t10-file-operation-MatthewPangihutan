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
    if(strcmp(_gender, "female") == 0){
        std.gender = GENDER_FEMALE;
    } else if(strcmp(_gender, "male") == 0){
        std.gender = GENDER_MALE;
    }
    std.dorm = malloc(sizeof(struct dorm_t));
    std.dorm = NULL;

    return std;
}

void print_student(struct student_t *_student, int jumlah){
    for (int i = 0; i < jumlah; i++)
    {
        if(_student[i].gender == GENDER_FEMALE){
            printf("%s|%s|%s|female\n", _student[i].id, _student[i].name, _student[i].year);
        } else if(_student[i].gender == GENDER_MALE){
            printf("%s|%s|%s|male\n", _student[i].id, _student[i].name, _student[i].year);
        }
    }
}

void print_student_detail(struct student_t *_student, int jumlah){
    for(int i = 0; i < jumlah; i++){
        if(_student[i].dorm == NULL){
            if(_student[i].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|unassigned\n", _student[i].id, _student[i].name, _student[i].year);
            } else if(_student[i].gender == GENDER_MALE){
                printf("%s|%s|%s|male|unassigned\n", _student[i].id, _student[i].name, _student[i].year);
            }
        } else {
            if(_student[i].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm->name);
            } else if(_student[i].gender == GENDER_MALE){
                printf("%s|%s|%s|male|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm->name);
            }
        }
    }
}

void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char*dorm_name){
    if(_dorm->residents_num < _dorm->capacity){
        if(_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char*dorm_name){
    if(_dorm->residents_num < _dorm->capacity){
        if(_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
            old_dorm->residents_num--;
        }
    }
}