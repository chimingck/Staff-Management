#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct record
{
  string id;
  unsigned age;
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

void create_employee()
{

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
  
