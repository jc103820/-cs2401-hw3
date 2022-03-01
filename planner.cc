#include "planner.h"
using namespace std;

//Constructor
Planner::Planner(node* h){
    head = h;
}

//Deconstructor
//TODO

//Copy Constructor
//TODO

//Overloaded Assignment Operator
//TODO

//1. Add a new Assignment to the list. (It will be inserted in order.)
void Planner::add(Assignment a){
    //TODO
}

//2. View the entire list of Assignment, in the order they are stored.
void Planner::display(ostream& outs){
    //TODO
}

//3. Remove an assignment that has been completed. This will use the find and remove 
//functions, both of which will take a string which is the name of the assignment.
void Planner::remove(string target){
    //TODO
}

//4. Learn the number of assignments that are waiting to be completed.
int Planner::waiting(){
    return 0;
}

//5. See the amount of time you have to complete the assignment that is due soonest. (This 
//assignment should be at the front of the list.)
unsigned int Planner::due_next(){
    //TODO
    return 0;
}

//6. See the average amount of time that assignments have been sitting in the list since they 
//were entered.
unsigned int Planner::average_wait(){
    //TODO
    return 0;
}

//7. Identify the assignment that has been in the list the longest.
unsigned int Planner::oldest(){
    //TODO
    return 0;
}

//8. Identify the assignment that was added to the list most recently.
unsigned int Planner::newest(){
    //TODO
    return 0;
}

//9. See all assignments that must be completed by a date entered by the user
void Planner::find_all(DateTime due_date){
    //TODO
}

//Load Assignments into Planner Object
void Planner::load(istream& ins){
    //TODO
}

//Save Assignments to file
void Planner::save(ostream& outs){
    //TODO
}

//Find Homework Assignment
Assignment Planner::find(string target){
    //TODO
    return Assignment();
}

