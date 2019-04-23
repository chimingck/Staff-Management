#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Record
{
  string id;
  string name;
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

void display_employee(const vector<Record> &employees, int index)
{
  cout << left << setw(5) << to_string(index)+"." << " "
       << left << setw(12) << employees[index].id << " "
       << left << setw(20) << employees[index].name << " "
       << left << setw(3) << employees[index].age << " "
       << left << setw(20) << employees[index].role << " "
       << left << fixed << setprecision(2) << employees[index].salary << endl;
}

void display_all_employees(const vector<Record> &employees)
{
  // Header, optional
  cout << left << setw(6) << "INDEX" << left << setw(13) << "ID"
       << left << setw(21) << "NAME" << left << setw(4) << "AGE"
       << left << setw(21) << "ROLE" << "SALARY" << endl;
  // loop through vector<Record> employees
  for (vector<Record>::size_type i = 0; i != employees.size(); ++i)
    display_employee(employees, i);
}

// field
// 1.Id
// 2.Name
// 3.Age
// 4.Role
// key must be converted string
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
int create_employee(vector<Record> &employees, string id,string name, int age, string role, double salary)
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
int modify_employee(vector<Record> &employees, const vector<string> &self_defined_field, int index, int field, string new_value)
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
  else if (field <= 5+self_defined_field.size()) // between 5 and self_defined_field.size()
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

void add_self_defined()
{
  
}

void delete_self_defined()
{
  
}

int main()
{ 
  // Sample Test Case
  vector<Record> employees;
  vector<string> self_defined_field;

  create_employee(employees, "3035574141", "Alvin", 18, "student", 100);
  create_employee(employees, "3035574142", "Wilson", 19, "student", 200);
  create_employee(employees, "3035574143", "Hello", 18, "sales", 7053.43);
  create_employee(employees, "3035574144", "Ken", 18, "sales", 8530.5);
  create_employee(employees, "3035574145", "William", 20, "accountant", 14000.85);
  create_employee(employees, "0000000000", "Ken", 26, "ceo", 50000);
  create_employee(employees, "9999999999", "Lucy", 43, "accountant", 23000.64);

  display_all_employees(employees);

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
  display_all_employees(employees);

  cout << endl << "Now modify the role of Alvin from ''student'' to ''ceo''." << endl;
  modify_employee(employees, self_defined_field, 0, 4, "ceo");
  display_all_employees(employees);

  cout << "Role = ceo: ";
  vector<int> roles2 = search_employee(employees, 4, "ceo");
  for (auto i : roles2)
    cout << i << " ";
  cout << endl;

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
  
