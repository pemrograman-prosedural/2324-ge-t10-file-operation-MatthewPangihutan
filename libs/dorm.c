#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
   struct dorm_t dorm_;

    dorm_.residents_num = 0;
    strcpy( dorm_.name, _name );
    dorm_.capacity = _capacity;
    dorm_.gender   = _gender;
    dorm_.residents_num = 0;

    return dorm_;
}

void print_dorm (struct dorm_t *dorm, int size)
{
   for(int a = 0; a<size; a++){
    if(dorm[a].gender == GENDER_FEMALE){
        printf("%s|%d|female\n", dorm[a].name, dorm[a].capacity);
    }
    else{
        printf("%s|%d|male\n", dorm[a].name, dorm[a].capacity);
    }
   }
}

void print_dorm_detail(struct dorm_t *dorm, int size)
{
   for(int a = 0; a<size; a++){
    if(dorm[a].gender == GENDER_FEMALE){
        printf("%s|%d|female|%d\n", dorm[a].name, dorm[a].capacity, dorm[a].residents_num);
    }
    else{
        printf("%s|%d|male|%d\n", dorm[a].name, dorm[a].capacity, dorm[a].residents_num);
    }
   }
}
