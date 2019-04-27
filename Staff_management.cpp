#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "staff_management.h"

using namespace std;

struct Record;

void display_employee(const vector<Record> &employees, const vector<string> &self_defined_fields, int index)
{
  cout << left << setw(5) << to_string(index)+"." << " "
       << left << setw(12) << employees[index].id << " "
       << left << setw(20) << employees[index].name << " "
       << left << setw(3) << employees[index].age << " "
       << left << setw(20) << employees[index].role << " "
       << left << setw(10) << fixed << setprecision(2) << employees[index].salary << " ";
  // output self-defined field(s)
  for (vector<string>::size_type i = 0; i != self_defined_fields.size(); ++i)
    cout << left << setw(self_defined_fields[i].size()+5) << employees[index].self_defined[i] << " ";
  cout << endl;
}

void display_all_employees(const vector<Record> &employees, const vector<string> &self_defined_fields)
{
  // Header, optional
  cout << left << setw(6) << "INDEX" << left << setw(13) << "ID"
       << left << setw(21) << "NAME" << left << setw(4) << "AGE"
       << left << setw(21) << "ROLE" << left << setw(11) << "SALARY";
  for (auto s : self_defined_fields)
    cout << left << setw(s.size()+6) << s;
  cout << endl;

  // loop through vector<Record> employees
  for (vector<Record>::size_type i = 0; i != employees.size(); ++i)
    display_employee(employees, self_defined_fields, i);
}

// field
// 1.Id
// 2.Name
// 3.Age
// 4.Role
// key must be converted string
// To make it simple, do not support search by self-defined-attribute(s) for now.
// return a vector<int> which store the index(es) of all employees who matches the key.
vector<int> search_employee(const vector<Record> &employees, int field, string key)
{
  vector<int> results;

  if (field == 1) // Id
  {
    for (vector<Record>::size_type i = 0; i != employees.size(); ++i)
      if (employees[i].id == key)
      {
        results.push_back(i);
        break;
      }
  }
  else if (field == 2) // Name
  {
    for (vector<Record>::size_type i = 0; i != employees.size(); ++i)
      if (employees[i].name == key)
        results.push_back(i);
  }
  else if (field == 3) // Age
  {
    for (vector<Record>::size_type i = 0; i != employees.size(); ++i)
      if (to_string(employees[i].age) == key)
        results.push_back(i);
  }
  else if (field == 4) // Role
  {
    for (vector<Record>::size_type i = 0; i != employees.size(); ++i)
      if (employees[i].role == key)
        results.push_back(i);
  }
  // NO need to search by salary in this function

  return results;
}

// return 0 if employee is created successfully.
// return -1 if there is an existing employee with same id.
// return -2 if the age/salary is less than 0, or id/name/role is empty. Employee not created.
int create_employee(vector<Record> &employees, const vector<string> &self_defined_fields, string id,string name, int age, string role, double salary)
{
  if (age < 0 || salary < 0 || id.empty() || name.empty() || role.empty())
    return -2; // invalid parameter(s)
  if (search_employee(employees, 1, id).size() != 0)
    return -1; // id conflict
  
  Record new_employee;
  new_employee.id = id;
  new_employee.name = name;
  new_employee.age = age;
  new_employee.role = role;
  new_employee.salary = salary;
  
  employees.push_back(new_employee);
  return 0;
}

// return 0 if employee's is removed successfully.
// return -1 if the index is out of range
int fire_employee(vector<Record> &employees, int index)
{
  if (index >= 0 && index < employees.size())
  {
    employees.erase(employees.begin()+index);
    return 0;
  }
  return -1; // Index out of range
}

//  field
// 1:Id
// 2:Name
// 3:Age
// 4:Role
// 5:Salary
// 6+:Self_defined_field
// key must be converted string
// return 0 if employee's data is modified successfully.
// return -1 if there is no existing employee with specified id.
// return -2 if the new_value is empty or cannot be converted to int/double properly. i.e. invalid input.
// return -3 if the field is invalid.
int modify_employee(vector<Record> &employees, const vector<string> &self_defined_fields, int index, int field, string new_value)
{
  if (index < 0 || index >= employees.size())
    return -1; // Index out of range
  if (new_value.empty())
    return -2; // empty new_value

  if (field == 1)
    employees[index].id = new_value;
  else if (field == 2)
    employees[index].name = new_value;
  else if (field == 3)
  {
    int age = atoi(new_value.c_str());
    if (age > 0)
      employees[index].age = age;
    else
      return -2; // Invalid input for age
  }
  else if (field == 4)
    employees[index].role = new_value;
  else if (field == 5)
  {
    double salary = atof(new_value.c_str());
    if (salary > 0)
      employees[index].salary = salary;
    else
      return -2; // Invalid input for salary
  }
  else if (field <= 5+self_defined_fields.size()) // between 5 and self_defined_field.size()
  {
    (employees[index]).self_defined[field-6] = new_value;
  }
  else
    return -3; // Incorrect field number
  
  return 0;
}

// use low = 0, high = X to find employees with salary lower than $X
// use low = X, high = std::numeric_limits<double>::max() to find employees with salary higher than $X
// use low = X, high = Y to find employees with salary between $X and $Y
// return a vector<int> which store the index(es) of target employee(s)
vector<int> search_by_salary(vector<Record> &employees, double low, double high)
{
  if (low > high) // swap low and high
  {
    double temp = low;
    low = high;
    high = temp;
  }
  vector<int> results;
  for (vector<Record>::size_type i = 0; i != employees.size(); ++i)
    if (employees[i].salary >= low && employees[i].salary <= high)
      results.push_back(i);

  return results;
}

// return 0 if the attriute/field is added and initialized successfully.
// return -1 if there is an existing self-defined field/attribute with same name. 
int add_self_defined(vector<Record> &employees, vector<string> &self_defined_fields, string field_name, string default_value /*= ""*/)
{
  for (vector<string>::size_type i = 0; i != self_defined_fields.size(); ++i)
    if (self_defined_fields[i] == field_name)
      return -1; // Same field/attribute already exist
  
  self_defined_fields.push_back(field_name);
  for (auto &record : employees)
    record.self_defined.push_back(default_value);
  return 0;
}

// ***Provided 2 similar functions here. Choose the one that you find it convinient and you can delete the another one.***

// return 0 if the attriute/field is deleted successfully.
// return -1 if there is no existing self-defined field/attribute with specified name. 
int delete_self_defined_by_name(vector<Record> &employees, vector<string> &self_defined_fields, string field_name)
{
  vector<string>::size_type i = 0;
  bool found = false;
  // Not to delete elements of a vector inside the loop of that vector
  for (i = 0; i != self_defined_fields.size(); ++i)
    if (self_defined_fields[i] == field_name)
    {
      found = true;
      break;
    }
  if (found)
  {
    for (auto &record : employees)
      record.self_defined.erase(record.self_defined.begin()+i);
    self_defined_fields.erase(self_defined_fields.begin()+i);
    return 0;
  }
  else
    return -1; // field not found.
}

// return 0 if the attriute/field is deleted successfully.
// return -1 if there is no existing self-defined field/attribute with specified index. i.e. index out of range .
int delete_self_defined_by_index(vector<Record> &employees, vector<string> &self_defined_fields, int index)
{
  if (index >= 0 && index < self_defined_fields.size())
    {
      for (auto &record : employees)
        record.self_defined.erase(record.self_defined.begin()+index);

      self_defined_fields.erase(self_defined_fields.begin()+index);
      return 0;
    }
  else
    return -1; // index out of range.
}