//
// Created by tatsu on 10/22/2017.
//

#include "workItem.h"


////////////////////////////////////////
// Constructor
////////////////////////////////////////
WorkItem::WorkItem(int priority, const string & key) {

    this->priority = priority;
    this->key = key;

}
WorkItem::WorkItem(){ // How to get around this?
    priority = 0;
    key = "here's your problem";
}
////////////////////////////////////////
// copy constructor
////////////////////////////////////////
WorkItem::WorkItem(const WorkItem & rhs) {
    this->priority = rhs.getPriority();
    this->key = rhs.getKey();
    // Something to get the LL going
}

///////////////////////////////////////
// operator = constructor
///////////////////////////////////////
WorkItem & WorkItem::operator = (const WorkItem & rhs) {
    this->priority = rhs.getPriority();
    this->key = rhs.getKey();
    // Something to get the :: going
    return *this;
}
///////////////////////////////
// Deconstructor
//////////////////////////////
WorkItem::~WorkItem() {
    // something goes here...

}

string WorkItem::getKey() const {
    return key;
}

int WorkItem::getPriority() const {
    return priority;
}
