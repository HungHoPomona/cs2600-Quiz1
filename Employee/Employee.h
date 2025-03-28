#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
    int IDnumber;
    char *name;
    char *phoneNumber;
    double salary;
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;

// Updated function prototypes
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number);
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, const char *name);
PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int size, const char *phoneNumber);
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary);
#endif // EMPLOYEE_H
