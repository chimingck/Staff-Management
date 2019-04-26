#ifndef STAFF_MANAGEMENT_H
#define STAFF_MANAGEMENT_H

#include <string>
#include <vector>

struct Record
{
  std::string id;
  std::string name;
  int age;
  std::string role;
  double salary;
  std::vector<std::string> self_defined;
};

void function_display(int input_choice);

void clear_screen();

void display_employee(const std::vector<Record> &employees, const std::vector<std::string> &self_defined_fields, int index);

void display_all_employees(const std::vector<Record> &employees, const std::vector<std::string> &self_defined_fields);

std::vector<int> search_employee(const std::vector<Record> &employees, int field, std::string key);

int create_employee(std::vector<Record> &employees, std::string id,std::string name, int age, std::string role, double salary);

int fire_employee(std::vector<Record> &employees, int index);

int modify_employee(std::vector<Record> &employees, const std::vector<std::string> &self_defined_fields, int index, int field, std::string new_value);

std::vector<int> search_by_salary(std::vector<Record> &employees, double low, double high);

int add_self_defined(std::vector<Record> &employees, std::vector<std::string> &self_defined_fields, std::string field_name, std::string default_value /*= ""*/);

int delete_self_defined_by_name(std::vector<Record> &employees, std::vector<std::string> &self_defined_fields, std::string field_name);

int delete_self_defined_by_index(std::vector<Record> &employees, std::vector<std::string> &self_defined_fields, int index);

#endif