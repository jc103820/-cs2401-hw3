#include "planner.h"
using namespace std;

//Constructor
Planner::Planner(node* h, node * t, int n){
    head = h;
    tail = t;
    numnodes = n;
}

//Deconstructor
//TODO

//Copy Constructor
//TODO

//Overloaded Assignment Operator
//TODO

//1. Add a new Assignment to the list. (It will be inserted in order.)
void Planner::add(Assignment a){
    if(head == NULL){ //if head is null them it is empty so one spot to add
        head = tail = new node(a);
        numnodes++;
    } else if(a.get_due() < (head -> data()).get_due()){ //if the first is greater than the new one, add to begining
        head = new node(a, head);
        numnodes++;
    }else {
        node* cursor = head;
        node* prev;
        while(cursor != NULL && (cursor -> data()).get_due() < a.get_due()){
            prev = cursor;
            cursor = cursor -> link();
        }
        if(cursor == NULL){ // add to end
            tail -> set_link(new node(a));
            tail = tail -> link();
            numnodes++;
        } else { // add here at ordered spot
            prev -> set_link(new node(a, cursor));
            numnodes++;
        }
    }
}

//2. View the entire list of Assignment, in the order they are stored.
void Planner::display(ostream& outs){
    node* cur = head;
    while(cur != NULL){
        outs << cur -> data() << endl;
        cur = cur -> link();
    }
}

//3. Remove an assignment that has been completed. This will use the find and remove 
//functions, both of which will take a string which is the name of the assignment.
void Planner::remove(string target){
    if(head == NULL){ //return if empty string
        return;
    }
    node* cursor = head;
    node* prev;
    if((head -> data()).get_name() == target){ //if the target is at the start
        head = head -> link();
        delete cursor;
    } else { // if not at the start
        while(cursor != NULL && (cursor -> data()).get_name() != target){
            prev = cursor;
            cursor = cursor -> link();
        }
        if(cursor != NULL){
            prev -> set_link(cursor -> link());
            delete cursor;
        }
    }
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
    string tmpStr;
    while(!ins.eof()){
        Assignment tmp;
        ins >> tmp;
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        add(tmp);
    }
}

//Save Assignments to file
void Planner::save(ostream& outs){
    node* cur = head;
    while(cur != NULL){
        outs << cur -> data() << endl;
        cur = cur -> link();
    }
}

//Find Homework Assignment
Assignment Planner::find(string target){
    //TODO
    if(head == NULL){
        return Assignment();
    }
    node* cursor = head;
    while(cursor != NULL && (cursor -> data()).get_name() != target){
        cursor = cursor -> link();
    }
    if(cursor != NULL){
        return cursor -> data();
    } else {
        return Assignment();
    }
}

/*
void Playlist::load(std::istream& ins){
    while(!ins.eof()){
        if(used == capacity){
            resize();
        }
        ins >> data[used];
        used++;
    }
}
*/