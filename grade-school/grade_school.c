#include "grade_school.h"
#include <string.h>

// typedef struct {
//    uint8_t grade;
//    char name[MAX_NAME_LENGTH];
// } student_t;

// typedef struct {
//    size_t count;
//    student_t students[MAX_STUDENTS];
// } roster_t;

void init_roster(roster_t *roster) {
    roster->count = 0;
    for (size_t i = 0; i < MAX_STUDENTS; i++) {
        roster->students[i].grade = 0;
        strcpy(roster->students[i].name, "");
    }
}

int add_student(roster_t *roster, char *name, int grade)
{
    // Check if student is on the list already
    for (size_t i = 0; i < roster->count; i++)
    {
        if(strcmp(roster->students[i].name, name) == 0)
            return 0; // Exit as student is present
    }
    // Add directly to the roster
    if (roster->count < MAX_STUDENTS) {
        strncpy(roster->students[roster->count].name, name, MAX_NAME_LENGTH - 1);
        roster->students[roster->count].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        roster->students[roster->count].grade = grade;
        roster->count++;
    }
    return 1;
}

roster_t get_grade(roster_t *roster, int grade) {
    // Create an array to store names
    char names[MAX_STUDENTS][MAX_NAME_LENGTH];
    size_t name_count = 0;

    // Iterate through the roster to collect names with the specified grade
    for (size_t i = 0; i < roster->count; i++) {
        if (roster->students[i].grade == grade) {
            strcpy(names[name_count], roster->students[i].name);
            name_count++;
        }
    }

    // Sort the names
    for (size_t i = 0; i < name_count - 1; i++) {
        for (size_t j = i + 1; j < name_count; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[MAX_NAME_LENGTH];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // Create a new roster to hold the sorted names
    roster_t result;
    result.count = name_count;

    // Populate the new roster with the sorted names
    for (size_t i = 0; i < name_count; i++) {
        result.students[i].grade = grade;
        strcpy(result.students[i].name, names[i]);
    }

    return result;
}
