#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

// Compile using the following command: 
// gcc employeeMain.c employeeTable.c employeeOne.c

int main(void) {
    // Function declarations defined in employeeOne.c
    PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number);
    PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, const char *name);
    PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int size, const char *phoneNumber);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary);

    // External variables defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration

    // Search by employee number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1001);
    if (matchPtr != NULL)
        printf("Employee ID 1001 is in record %td\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1001 is NOT found in the record\n");

    // Search by employee name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %td\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Search by phone number
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employee with phone number 909-555-2134 is in record %td\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone number 909-555-2134 is NOT found in the record\n");

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    if (matchPtr != NULL)
        printf("Employee with phone number 123-456-7890 is in record %td\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone number 123-456-7890 is NOT found in the record\n");

    return EXIT_SUCCESS;
}

