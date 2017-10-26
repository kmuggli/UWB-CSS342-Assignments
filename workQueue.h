//
// Created by tatsu on 10/22/2017.
//



#ifndef PROJECT2_WORKQUEUE_H
#define PROJECT2_WORKQUEUE_H
#include <string>
#include <iostream>
#include "workItem.h"

using namespace std;


class Node
{
public:
    // Constructors
    Node();
    Node(WorkItem); // Need to fix this.

    // Getters and Setters
    int getPriority() const;
    string getKey() const;
    Node * getNext() const;
    WorkItem getThis() const;

    void setNext(Node* &);
    void setWorkItem(WorkItem &);

    // Actions


private:
    WorkItem item;
    Node* pnext;
};


class WorkQueue {
    friend class WorkItem;

public:
    // Constructors
    WorkQueue(); // Main Constructor
    WorkQueue(const WorkQueue &); // Copy constructor **NEEDS TO DEEP COPY**
    WorkQueue & operator=(const WorkQueue &); // operator= **NEEDS TO DEEP COPY**
    virtual ~WorkQueue(); // Destructor

    // Getters and setters
    int getNumWorkItems() const;// Get total number of items in the queue
    int getNumWorkItems(int priority);// get total number of items of the provided priority

    // Actions
    void addWorkItem(const class WorkItem &); // How to add a "node" to the list
    const WorkItem & nextWorkItem(int priority) const; // Returns the next work item for the priority level
    bool hasWorkItem(int priority) const; // Returns true if there is a work item to be returned for a given priority
    bool containsKey( const string & key) const;// Returns true if there is a work item with the key in the queue
    void bumpWorkItem( const string & key);// “Bumps” the work item to the head of it’s priority queue
    void deleteWorkItem(string key);// Delete the work item with this key
    void deleteAllWorkItems();// delete all ( and clean up any memory, etc)

    /////////////////////////
    // TEST METHOD
    /////////////////////////
    void print() const;

private:
    Node *phead, *ptail;

};



#endif //PROJECT2_WORKQUEUE_H
