#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

// Compile using the following command: 
// gcc employeeMain.c employeeTable.c employeeOne.c employeeTwo.c -o employeeProgram

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
    long searchID = 1001;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, searchID);
    if (matchPtr != NULL)
        printf("Employee ID %ld is in record %td\n", matchPtr->IDnumber, matchPtr - EmployeeTable);
    else
        printf("Employee ID %ld is NOT found in the record\n", searchID);

    searchID = 9999;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, searchID);
    if (matchPtr != NULL)
        printf("Employee ID %ld is in record %td\n", matchPtr->IDnumber, matchPtr - EmployeeTable);
    else
        printf("Employee ID %ld is NOT found in the record\n", searchID);

    // Search by employee name
    const char *searchName = "Tony Bobcat";
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, searchName);
    if (matchPtr != NULL)
        printf("Employee %s is in record %td\n", matchPtr->name, matchPtr - EmployeeTable);
    else
        printf("Employee %s is NOT found in the record\n", searchName);

    searchName = "Hung Anh Ho";
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, searchName);
    if (matchPtr != NULL)
        printf("Employee %s is in record %td\n", matchPtr->name, matchPtr - EmployeeTable);
    else
        printf("Employee %s is NOT found in the record\n", searchName);

    // Search by phone number
    const char *searchPhone = "909-555-2134";
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, searchPhone);
    if (matchPtr != NULL)
        printf("Employee with phone number %s is in record %td\n", searchPhone, matchPtr - EmployeeTable);
    else
        printf("Employee with phone number %s is NOT found in the record\n", searchPhone);

    searchPhone = "123-456-7890";
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, searchPhone);
    if (matchPtr != NULL)
        printf("Employee with phone number %s is in record %td\n", searchPhone, matchPtr - EmployeeTable);
    else
        printf("Employee with phone number %s is NOT found in the record\n", searchPhone);

    // Search by salary
    double searchSalary = 8.78;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, searchSalary);
    if (matchPtr != NULL)
        printf("Employee with salary %.2f is in record %td\n", searchSalary, matchPtr - EmployeeTable);
    else
        printf("Employee with salary %.2f is NOT found in the record\n", searchSalary);

    searchSalary = 10.00;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, searchSalary);
    if (matchPtr != NULL)
        printf("Employee with salary %.2f is in record %td\n", searchSalary, matchPtr - EmployeeTable);
    else
        printf("Employee with salary %.2f is NOT found in the record\n", searchSalary);

    return EXIT_SUCCESS;
}

