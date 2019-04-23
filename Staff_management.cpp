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


void function_display(input_choice)
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
    else{
      cout << "Error, please enter number from the Function List." << endl;
      function_display(input_choice);
    }
  }
  
  return 0;
}
  
