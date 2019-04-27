# Staff-Management
HKU ENGG1340 Course Project

## Introduction
It's an employee management system which facilitates the administrative work of a **samll** company/business.

## Aims & objective (optional)
This staff management aims to help a **small** company/business to collect and manage the information of its employees.
## Features

1. Create new employee with employee's data(e.g. ID, Name, Age, Role/Job Position, Salary)
2. Search for & delete employees' data by ID, Name, Age or Role
3. Display all employees' data
4. Fire an employee
5. Modify current employees' info.
6. Search/list employees by salary (heigher than/ lower than/ between a specified price point)
7. Add self-define field/attributes
8. Delete self-define field/attributes

## Assumption/Preset statement
There are 5 initial field of each employee - (ID, Name, Age, Role, Salary)
For creating new employee, the below is the input specification:
- ID: 10 digits string, Unique
- Name: Maximum 20 digits string
- Age: Maximum 3 digits Positive Integer
- Role(Post of the Employee): Maximum 20 digits string
- Salary: Maximum 10 digits double
Errors may occur when users create a new employee **not** according to the above specoification




## Implementation
Maybe using vector of struct to store the info of each employee (but how to add self-define attribute?)
