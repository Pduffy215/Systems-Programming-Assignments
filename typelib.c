#include "typelib.h"
#include <stdio.h>
#include <string.h>

/*
This is the implementation of the functions in typelib.h. 
Please read the comments in typelib.h before you start working on this file.
*/

letter_grade_t percentage_to_letter(float percentage) {
    if (percentage < 0.0f || percentage > 100.0f) {
	    return GRADE_INVALID;         //If percentage is greater isnt between 0 and 100 return GRADE_INVALID
    }
    if (percentage >= 97.0f) {
	    return GRADE_A_PLUS;
    } else if (percentage >= 93.0f) {
	    return GRADE_A;
    } else if (percentage >= 90.0f) {
	    return GRADE_A_MINUS;
    } else if (percentage >= 87.0f) {
	    return GRADE_B_PLUS;          //Use if and else if statements for all the rest of the percentages
    } else if (percentage >= 83.0f) {
            return GRADE_B;
    } else if (percentage >= 80.0f) {
            return GRADE_B_MINUS;
    } else if (percentage >= 77.0f) {
            return GRADE_C_PLUS;
    } else if (percentage >= 73.0f) {
            return GRADE_C;
    } else if (percentage >= 70.0f) {
            return GRADE_C_MINUS;
    } else if (percentage >= 67.0f) {
            return GRADE_D_PLUS;
    } else if (percentage >= 63.0f) {
            return GRADE_D;
    } else if (percentage >= 60.0f) {
            return GRADE_D_MINUS;
    } else {
	    return GRADE_F;
    }
}

float letter_to_percentage(letter_grade_t letter) {
    switch (letter) {
        case GRADE_A_PLUS:
            return 98.5f;  
        case GRADE_A:
            return 95.0f;  
        case GRADE_A_MINUS:    //Use switch for each case of letter grade and return the appropriate value
            return 91.5f;  
        case GRADE_B_PLUS:
            return 88.5f;  
        case GRADE_B:
            return 85.0f;  
        case GRADE_B_MINUS:
            return 81.5f;  
        case GRADE_C_PLUS:
            return 78.5f;  
        case GRADE_C:
            return 75.0f;  
        case GRADE_C_MINUS:
            return 71.5f;  
        case GRADE_D_PLUS:
            return 68.5f;  
        case GRADE_D:
            return 65.0f;  
        case GRADE_D_MINUS:
            return 61.5f;  
        case GRADE_F:
            return 30.0f; 
        case GRADE_INVALID:
        default:
            return -1.0f;
    }
}

float letter_to_gpa(letter_grade_t letter) {
    switch (letter) {
        case GRADE_A_PLUS:
        case GRADE_A:
            return 4.0f;
        case GRADE_A_MINUS:  //A and A plus are both 4.0 so return same value
            return 3.7f;
        case GRADE_B_PLUS:
            return 3.3f;   //Use switch again for all the cases 
        case GRADE_B:
            return 3.0f;
        case GRADE_B_MINUS:
            return 2.7f;
        case GRADE_C_PLUS:
            return 2.3f;
        case GRADE_C:
            return 2.0f;
        case GRADE_C_MINUS:
            return 1.7f;
        case GRADE_D_PLUS:
            return 1.3f;
        case GRADE_D:
            return 1.0f;
        case GRADE_D_MINUS:
            return 0.7f;
        case GRADE_F:
            return 0.0f;
        case GRADE_INVALID:
        default:
            return -1.0f;
    }
}

student_t create_student(int student_id, const char first_name[], const char last_name[], int year_level, bool is_suspended) {
    student_t student = {0};
    student.student_id = student_id;    //Set all parameters of the student
    student.year_level = year_level;
    student.is_suspended = is_suspended;

    strncpy(student.first_name, first_name, MAX_FIRST_NAME_LENGTH - 1);
    student.first_name[MAX_FIRST_NAME_LENGTH - 1] = '\0';               //Copy the students first name but make sure the                                                                        //Null terminator has space

    strncpy(student.last_name, last_name, MAX_LAST_NAME_LENGTH - 1);  //Copy Last Name using same method
    student.last_name[MAX_LAST_NAME_LENGTH - 1] = '\0';

    return student;
}

course_t create_course(const char course_code[], const char course_name[], int credits, int max_students) {
    course_t course = {0}; 
    course.credits = credits;
    course.max_students = max_students;   //Set all parameters of the Course

    strncpy(course.course_code, course_code, MAX_COURSE_CODE_LENGTH - 1); //Copy the Strings with Null terminator
    course.course_code[MAX_COURSE_CODE_LENGTH - 1] = '\0';

    strncpy(course.course_name, course_name, MAX_COURSE_NAME_LENGTH - 1);
    course.course_name[MAX_COURSE_NAME_LENGTH - 1] = '\0';

    return course;
}

bool is_course_at_capacity(course_t course) {
    // TODO: Check if course enrollment equals max capacity
    return false;
}

course_t add_student_to_course(course_t course, student_t student) {
    // TODO: Add student to course's student array
    return course;
}

float calculate_student_average(grade_t grades[], int num_grades, int student_id) {
    // TODO: Calculate average percentage grade for a specific student
    return -1.0;
}

int find_top_student(grade_t grades[], int num_grades, student_t students[], int num_students) {
    // TODO: Find student with highest average grade
    return -1;
}

float calculate_class_average(grade_t grades[], int num_grades, student_t students[], int num_students) {
    // TODO: Calculate average grade for entire class
    return -1.0;
}

int count_students_by_year(student_t students[], int num_students, int year_level) {
    // TODO: Count enrolled students in specific year level
    return 0;
}

int calculate_total_credit_hours(course_t course) {
    // TODO: Calculate total credit hours for enrolled students
    return 0;
}

int find_most_popular_course(course_t courses[], int num_courses) {
    // TODO: Find course with highest enrollment
    return -1;
}

int find_student_in_course(course_t course, int student_id) {
    // TODO: Find student in course by student ID
    return -1;
}
