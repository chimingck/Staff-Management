#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "staff_management.h"

using namespace std;

void function_display(int input_choice)
{
  if(input_choice == 0){
    cout << "WELCOME TO THE STAFF MANAGEMENT SYSTEM" << endl;
    cout << "You may use the following functions:  " << endl << endl;
    // Header, optional
    cout << left << setw(4) << "No."
         << left << setw(30) << "Name"
         << left << setw(100) << "Discription"
         << endl;
    
    // Function 1
    cout << left << setw(4) << "1."
         << left << setw(30) << "Display All Employees"
         << left << setw(100) << "To Display All Details (e.g. Name, Role...) of All Employees."
         << endl;

    // Function 2
    cout << left << setw(4) << "2."
         << left << setw(30) << "Search Employee(s)"
         << left << setw(100) << "To Get a List of Employee(s) by a Field (e.g. ID, Name, Age, Role...)."
         << endl;

    //Function 3
    cout << left << setw(4) << "3."
         << left << setw(30) << "Search Employee(s) by Salary"
         << left << setw(100) << "To Get a List of Employee(s) by Salary (More than, Below, Between)."
         << endl;

    // Function 4
    cout << left << setw(4) << "4."
         << left << setw(30) << "Fire Employee"
         << left << setw(100) << "To Fire an Employee by the Staff ID."
         << endl;
    
    //Function 5
    cout << left << setw(4) << "5."
         << left << setw(30) << "Modify Employee Info."
         << left << setw(100) << "To Modify an Employee's Information by the Staff ID."
         << endl;
    
    //Function 6
    cout << left << setw(4) << "6."
         << left << setw(30) << "Add Self-defined Field"
         << left << setw(100) << "To Add a Self-defined Field to the Staff Records."
         << endl;
    
    //Function 7
    cout << left << setw(4) << "7."
         << left << setw(30) << "Delete Self-defined Field"
         << left << setw(100) << "To Delete a Self-defined Field from the Staff Records."
         << endl;

  }
  else if(input_choice == 1){

  }
  else if(input_choice == 2){

  }
  else if(input_choice == 3){

  }
  else if(input_choice == 4){

  }
  else if(input_choice == 5){

  }
  else if(input_choice == 6){

  }
  else if(input_choice == -1){
    cout << "***___SYSTEM TERMINATED___***" << endl;
    cout << "    ***___THANK YOU___***    " << endl;
    cout << "    ***___GOOD  BYE___***    " << endl;
  }
  else{
    cout << "Error, please enter number from the Function List." << endl;
  }
}

void clear_screen()
{
  cout << string( 100, '\n' );
}

int main()
{ 
  // Sample Test Case
  vector<Record> employees;
  vector<string> self_defined_fields;

  create_employee(employees, "3035574141", "Alvin", 18, "student", 100);
  create_employee(employees, "3035574142", "Wilson", 19, "student", 200);
  create_employee(employees, "3035574143", "Hello", 18, "sales", 7053.43);
  create_employee(employees, "3035574144", "Ken", 18, "sales", 8530.5);
  create_employee(employees, "3035574145", "William", 20, "accountant", 14000.85);
  create_employee(employees, "0000000000", "Ken", 26, "ceo", 50000);
  create_employee(employees, "9999999999", "Lucy", 43, "accountant", 23000.64);

  display_all_employees(employees, self_defined_fields);

  cout << endl;
  // search by ID
  cout << "ID = 9999999999: ";
  vector<int> ids = search_employee(employees, 1, "9999999999");
  for (auto i : ids)
    cout << i << " ";
  cout << endl;

  // search by Name
  cout << "Name = Ken: ";
  vector<int> names = search_employee(employees, 2, "Ken");
  for (auto i : names)
    cout << i << " ";
  cout << endl;

  // search by age
  cout << "Age = 18: ";
  vector<int> ages = search_employee(employees, 3, "18");
  for (auto i : ages)
    cout << i << " ";
  cout << endl;

  // search by age 2
  cout << "Age = 30: ";
  vector<int> ages2 = search_employee(employees, 3, "30");
  for (auto i : ages2)
    cout << i << " ";
  cout << endl;

  // search by Role
  cout << "Role = accountant: ";
  vector<int> roles = search_employee(employees, 4, "accountant");
  for (auto i : roles)
    cout << i << " ";
  cout << endl;

  // search by salary
  cout << "salary between 10000 and 30000: ";
  vector<int> salaries = search_by_salary(employees, 10000, 30000);
  for (auto i : salaries)
    cout << i << " ";
  cout << endl;

  // search by salary
  cout << "salary below 20000: ";
  vector<int> salaries2 = search_by_salary(employees, 0, 20000);
  for (auto i : salaries2)
    cout << i << " ";
  cout << endl;

  // search by salary
  cout << "salary more than 10000: ";
  vector<int> salaries3 = search_by_salary(employees, 10000, numeric_limits<double>::max()); // or just input 999999999..
  for (auto i : salaries3)
    cout << i << " ";
  cout << endl;

  cout << endl << "Now fire the employee with index 2 & 4." << endl;
  fire_employee(employees, 2);
  // Be aware of the result.
  // The employee with index 2 is deleted. The employees after him/her is than moved one index forward.
  // So when deleting the employee with index 4, is actually deleting the employee with index 5 originally
  // which is Ken, the CEO xd
  fire_employee(employees, 4);
  display_all_employees(employees, self_defined_fields);

  cout << endl << "Now modify the role of Alvin from \"student\" to \"ceo\"." << endl;
  modify_employee(employees, self_defined_fields, 0, 4, "ceo");
  display_all_employees(employees, self_defined_fields);

  cout << "Role = ceo: ";
  vector<int> roles2 = search_employee(employees, 4, "ceo");
  for (auto i : roles2)
    cout << i << " ";
  cout << endl;

  cout << endl << "Now try to modify field 6 which is not exist for now (the 1st self-defined field)." << endl;
  cout << "The runction modify_employee will return -3 inidicating non-exist field." << endl;
  int s = modify_employee(employees, self_defined_fields, 4, 6, "Haaa");
  cout << s << endl;

  cout << endl << "Now add a self-defined field called \"sex\" and initialize it to \"M\"." << endl;
  // be aware that the self-defined field is case sensitive.
  add_self_defined(employees, self_defined_fields, "sex", "M");
  display_all_employees(employees, self_defined_fields);

  cout << endl << "Now add another self-defined field called \"sport\" and default initialize it to empty." << endl;
  add_self_defined(employees, self_defined_fields, "sport");
  display_all_employees(employees, self_defined_fields);

  cout << endl << "Now modify Lucy's \"sport\" field to badminton and \"sex\" to \"F\"." << endl;
  modify_employee(employees, self_defined_fields, 4, 6, "F");
  modify_employee(employees, self_defined_fields, 4, 7, "badminton");
  display_all_employees(employees, self_defined_fields);

  cout << endl << "Now delete the self-defined field \"sex\"." << endl;
  delete_self_defined_by_name(employees, self_defined_fields, "sex");
  // delete_self_defined_by_index(employees, self_defined_fields, 0);
  display_all_employees(employees, self_defined_fields);


  cout << endl;
  function_display(0);
  /*
  int input_choice = 0;
  while(input_choice != -1){
    function_display(input_choice);
    cin >> input_choice;
    clear_screen();
    if(input_choice == 1){

    }
    else if(input_choice == 2){

    }
    else if(input_choice == 3){

    }
    else if(input_choice == 4){

    }
    else if(input_choice == 5){

    }
    else if(input_choice == 6){

    }
    else if(input_choice == -1){
      cout << "***___SYSTEM TERMINATED___***" << endl;
      cout << "    ***___THANK YOU___***    " << endl;
      cout << "    ***___GOOD  BYE___***    " << endl;
      break;
    }
    else{
      cout << "Error, please enter number from the Function List." << endl;
      input_choice = 0;
      function_display(input_choice);
    }
  }
  */
  return 0;
}