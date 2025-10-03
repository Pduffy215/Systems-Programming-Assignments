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
    // TODO: Convert letter grade to middle percentage value
    return -1.0;
}

float letter_to_gpa(letter_grade_t letter) {
    // TODO: Convert letter grade to GPA value (4.0 scale)
    return -1.0;
}

student_t create_student(int student_id, const char first_name[], const char last_name[], int year_level, bool is_suspended) {
    // TODO: Create a new student with the given parameters
    student_t student = {0}; // TODO :: Initialize / change this to your liking
    return student;
}

course_t create_course(const char course_code[], const char course_name[], int credits, int max_students) {
    // TODO: Create a new course with the given parameters
    course_t course = {0}; // TODO :: Initialize / change this to your liking
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
