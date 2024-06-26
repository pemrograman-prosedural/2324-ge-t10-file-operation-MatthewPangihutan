#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"
#include "student.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
short findStudentIdx ( char *_id,struct student_t *list, int length );
void print_students(struct student_t *_student, int jumlah);
void print_students_detail(struct student_t *_student, int jumlah);
void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name);
void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name);
void unassign_student(struct student_t *_student, struct dorm_t *_dorm);
#include "dorm.h"

void emptyDorm (struct dorm_t* residence, struct student_t** potentialResidents, unsigned short totalPR) {
            // Your code here
}
#endif
