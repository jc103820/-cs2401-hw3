#include "planner.h"
using namespace std;

//Constructor
Planner::Planner(node* h, node * t, const int n){
    head = h;
    tail = t;
    numnodes = n;
}

//Deconstructor
Planner::~Planner(){
    node* ptr;
    while(head != NULL){
        ptr = head;
        head = head -> link();
        delete ptr;
    }
    tail = NULL;
}

//Copy Constructor
Planner::Planner(const Planner& other){
    if(other.head == NULL){
        head = tail = NULL;
        numnodes = 0;
    } else {
        node* src;
        numnodes = other.get_numnodes();
        head = new node(other.head -> data());
        tail = head;
        src = other.head -> link();
        while(src != NULL){
            tail -> set_link(new node(src -> data()));
            src = src -> link();
            tail = tail -> link();
        }
    }
}

//Overloaded Assignment Operator
Planner& Planner::operator =(const Planner& other){
    if(this == &other){
        return *this;
    }
    //deconstructor
    node* remptr;
    while(head != NULL){
        remptr = head;
        head = head -> link();
        delete remptr;
    }
    head = tail = NULL;

    //Copy
    if(other.head == NULL){
        head = tail = NULL;
        numnodes = 0;
    } else {
        node* src;
        numnodes = other.get_numnodes();
        head = new node(other.head -> data());
        tail = head;
        src = other.head -> link();
        while(src != NULL){
            tail -> set_link(new node(src -> data()));
            src = src -> link();
            tail = tail -> link();
        }
    }
    
    return *this;
}

//1. Add a new Assignment to the list. (It will be inserted in order.)
void Planner::add(const Assignment a){
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
void Planner::display(ostream& outs)const{
    node* cur = head;
    while(cur != NULL){
        outs << cur -> data() << endl;
        cur = cur -> link();
    }
}

//3. Remove an assignment that has been completed. This will use the find and remove 
//functions, both of which will take a string which is the name of the assignment.
void Planner::remove(const string target){
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
}

//4. Learn the number of assignments that are waiting to be completed.
int Planner::waiting()const{
    int numwait = 0;

    DateTime curTime;
    curTime.make_now();

    node* cur = head;
    while(cur != NULL){ //update numwait
        if(curTime < (cur -> data()).get_due()){
            numwait++;
        }
        cur = cur -> link();
    }
    return numwait;
}

//5. See the amount of time you have to complete the assignment that is due soonest. (This 
//assignment should be at the front of the list.)
unsigned int Planner::due_next()const{
    node* cur = head;
    unsigned int soonest = UINT_MAX;
    while(cur != NULL){ //update numwait
        if(cur -> data().minutes_til_due() < soonest){
            soonest = (cur -> data()).minutes_til_due();
        }
        cur = cur -> link();
    }
    return soonest;
}

//6. See the average amount of time that assignments have been sitting in the list since they 
//were entered.
unsigned int Planner::average_wait()const{
    node* cur = head;
    unsigned int total = 0;
    while(cur != NULL){ //update numwait
        total += (cur -> data()).minutes_waiting();
        cur = cur -> link();
    }
    return (total / numnodes);
}

//7. Identify the assignment that has been in the list the longest.
unsigned int Planner::oldest()const{
    node* cur = head;
    unsigned int oldest = 0;
    while(cur != NULL){ //update numwait
        if(cur -> data().minutes_waiting() > oldest){
            oldest = (cur -> data()).minutes_waiting();
        }
        cur = cur -> link();
    }
    return oldest;
}

//8. Identify the assignment that was added to the list most recently.
unsigned int Planner::newest()const{
    node* cur = head;
    unsigned int newest = UINT_MAX;
    while(cur != NULL){ //update numwait
        if(cur -> data().minutes_waiting() < newest){
            newest = (cur -> data()).minutes_waiting();
        }
        cur = cur -> link();
    }
    return newest;
}

//9. See all assignments that must be completed by a date entered by the user
void Planner::find_all(DateTime due_date)const{

    node* cur = head;
    while(cur != NULL){ //update numwait
        if((cur -> data()).get_due() < due_date){
            cout << cur -> data();
        }
        cur = cur -> link();
    }
    return;
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
Assignment Planner::find(string target)const{
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