#include <iostream>
#include "node.h"
using namespace std;

class Planner{
    public:
        //Constructor
		Planner(node* h = NULL, node * t = NULL, int n = 0);

        //Deconstructor
        //TODO

        //Copy Constructor
        //TODO

        //Overloaded Assignment Operator
        //TODO

        //1. Add a new Assignment to the list. (It will be inserted in order.)
        void add(Assignment a);

        //2. View the entire list of Assignment, in the order they are stored.
        void display(ostream& outs);

        //3. Remove an assignment that has been completed. This will use the find and remove 
        //functions, both of which will take a string which is the name of the assignment.
        void remove(string target);

        //4. Learn the number of assignments that are waiting to be completed.
        int waiting();

        //5. See the amount of time you have to complete the assignment that is due soonest. (This 
        //assignment should be at the front of the list.)
        unsigned int due_next();

        //6. See the average amount of time that assignments have been sitting in the list since they 
        //were entered.
        unsigned int average_wait();

        //7. Identify the assignment that has been in the list the longest.
        unsigned int oldest();

        //8. Identify the assignment that was added to the list most recently.
        unsigned int newest();

        //9. See all assignments that must be completed by a date entered by the user
        void find_all(DateTime due_date);

        //Load Assignments into Planner Object
        void load(istream& ins);

        //Save Assignments to file
        void save(ostream& outs);
        
        //Find Homework Assignment
        Assignment find(string target);
        
        
    private:
		node* head;
        node* tail;
        int numnodes;
};
//TODO What needs to be const??
//OFSTREAM??