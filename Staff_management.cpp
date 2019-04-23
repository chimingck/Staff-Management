#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Record
{
  string id;
  int age;
  string role;
  double salary;
  vector<string> self_defined;
};


void function_display(int input_choice)
{
  
}

void clear_screen()
{
  cout << string( 100, '\n' );
}

void create_employee(vector<Record> employees, string id, int age, string role, double salary)
{
  if (int < 0)
    age = -1;
  if (salary < 0)
    salary = -1;
  
  Record new_employee;
  new_employee.id = id;
  new_employee.age = age;
  new_employee.role = role;
  new_employee.salary = salary;
  
  employees.push_back(new_employee);
}

void search_employee()
{
  
}

void fire_employee()
{
  
}

void modify_employee()
{
  
}

void search_by_salary()
{
  
}

void add_self_defined()
{
  
}

void delete_self_defined()
{
  
}

int main()
{ 
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
    else if(input_choice == 6){
      cout << "SYSTEM TERMINATED" << endl;
      break;
    }
    else{
      cout << "Error, please enter number from the Function List." << endl;
      input_choice = 0;
      function_display(input_choice);
    }
  }
  
  return 0;
}
  
