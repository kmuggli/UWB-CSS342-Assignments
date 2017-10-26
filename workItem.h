//
// Created by tatsu on 10/22/2017.
//

#ifndef PROJECT2_WORKITEM_H
#define PROJECT2_WORKITEM_H
#include <string>
#include <iostream>
using namespace std;

class WorkItem {
    friend class WorkQueue;
public:

    // Constructors
    WorkItem();
    WorkItem(int priority, const string & key); // Standard constructor
    WorkItem(const WorkItem &); // Copy constructor
    WorkItem &operator=(const WorkItem &rhs); // operator =? not entirely sure what to call it
    virtual ~WorkItem();  // Destructor

    // Getters & Setters
    int getPriority() const;
    string getKey() const;

private:
    int priority; // Priority of the WorkItem
    string key;
};

#endif //PROJECT2_WORKITEM_H
