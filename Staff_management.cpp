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
  new_emplyee.role = role;
  new_emplyee.salary = salary;
  
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
  }
  
  return 0;
}
  
