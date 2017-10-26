//
// Created by tatsu on 10/22/2017.
//

#include "workQueue.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// NODE STUFF BELOW ////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////
// Node CONSTRUCTORS
/////////////////////////////////

Node::Node(){
    item = WorkItem();
    pnext = NULL;
}

Node::Node(WorkItem rhs){
    item = rhs;
    pnext = NULL;
}

//////////////////////////////////
// GETTERS
/////////////////////////////////

int Node::getPriority() const {
    return item.getPriority();
}

string Node::getKey() const {
    return item.getKey();
}

Node * Node::getNext() const {
    return pnext;
}

WorkItem Node::getThis() const {
    return item;
}

///////////////////////////////////////
// SETTERS
///////////////////////////////////////
void Node::setWorkItem(WorkItem & rhs) {
    item = rhs;
}

void Node::setNext(Node* & rhs) {
    pnext = rhs;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// WORKQUEUE STUFF BELOW ////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////
// WorkQueue Constructors
///////////////////////////////////
WorkQueue::WorkQueue()
{
    phead = NULL;
    ptail = NULL;
}


WorkQueue::WorkQueue(const WorkQueue & rhs) { // Copy Constructo
    Node *temp = rhs.phead;
    WorkQueue *newQueue = new WorkQueue;

    if (temp == NULL)
    {
        newQueue->phead = NULL;
    }
    else
    {
        newQueue->addWorkItem(rhs.phead->getThis());
    }

    //cout << "before while loo" << endl;
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
        newQueue->addWorkItem(temp->getThis());
       // cout << "in while loop: " << endl;
    }
    //cout << "got here" << endl;
    newQueue->addWorkItem(temp->getThis());
    //cout << "exiting" << endl;
}

WorkQueue & WorkQueue::operator=(const WorkQueue & rhs) {

    WorkQueue temp(rhs);
    swap(temp.phead, phead);
    return *this;
}
////////////////////////////////////////////////
// Destructor
////////////////////////////////////////////////
WorkQueue::~WorkQueue()
{
    //this->clear();
}



void WorkQueue::addWorkItem(const WorkItem & rhs){

    Node *newNode = new Node(rhs);
    if (phead == NULL)
    {
        phead = newNode;
    }
    else
    {
        Node *temp = phead;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}


int WorkQueue::getNumWorkItems() const {
    Node* p = phead;
    if (phead == NULL){
        return 0;
    }
    else {
        int size = 0;
        for (; p != NULL; size++, p = p->getNext());
        return size;
    }
}

int WorkQueue::getNumWorkItems(int priority) {
    int number = 0;
    Node *temp = phead;
    if (priority == NULL){
        return 0;
    }
    while (temp  != NULL)
    {

        if (temp->getPriority() == priority)
        {
            number++;
        }
        temp = temp->getNext();
    }
    return number;
}

bool WorkQueue::hasWorkItem(int priority) const { // NEED EXCEPTIONS
    Node *temp = phead;
    if (temp == NULL)
    {
        return false;
    }
    while (temp->getPriority() != priority && temp->getNext() != NULL)
    {
        temp = temp->getNext();


        if (temp->getPriority() == priority)
        {
            return true;
        }
    }
            return false;
}

bool WorkQueue::containsKey(const string &key) const { // One of three methods with basically the same problem.
    Node *temp = phead;
    cout << "this is the key passed in: " << key << endl;
    if (temp == NULL)
    {
        cout << "NULL queue. So return FALSE" << endl;
        return false;
    }
    else if (temp->getKey().compare(key) == true) {
        cout << "Returning TRUE" << endl;
        return true;
    }
    else {
        cout << "this is the key in temp: " << temp->getKey() << endl;
        while (temp->getKey().compare(key) == false || temp->getNext() != NULL) {

                temp = temp->getNext();
                if (temp == NULL){
                    return false;
                }
                cout << "Iterating the while loop printing what's in temp: " << temp->getKey() << endl;
                if (temp->getKey().compare(key) == true) {
                    cout << "Returning TRUE" << endl;
                    return true;
                }
        }
    }

    cout << "Iterated the whole list, Key not found. Returning FALSE" << endl;
    return false;
}

void WorkQueue::bumpWorkItem(const string &key) { // Will have problems to be resolved with containsKey() as well
    Node *temp = phead;
    cout << "this is the key passed in: " << key << endl;
    if (temp == NULL)
    {
        cout << "NULL queue. So do nothing? pass exception?" << endl;
    }
    cout << "this is the key in temp: " << temp->getKey() << endl;
    while (!temp->getKey().compare(key)  && temp->getNext() != NULL){
        temp = temp->getNext();
        cout << "Iterating the while loop printing what's in temp: " << temp->getKey() << endl;

        if (temp->getKey().compare(key))
        {
            cout << "Moving to front of the list" << endl;
            Node *oldHead = phead;                                      // May have problems here too?
            temp->setNext(oldHead);
            phead = temp;
        }
    }
    cout << "Iterated the whole list, Key not found. Throw exception" << endl;
   // throw exeption here
}

void WorkQueue::deleteWorkItem(string key) { // SAME THING AS ABOVE
    Node *temp = phead;
    cout << "this is the key passed in: " << key << endl;
    if (temp == NULL)
    {
        cout << "NULL queue. So do nothing? pass exception?" << endl;
    }
    if (temp->getKey().compare(key) == true)
    {
        // Delete it
    }
    /*else if {
        cout << "this is the key in temp: " << temp->getKey() << endl;
        while (!temp->getNext()->getKey().compare(key) && temp->getNext() != NULL) {
            temp = temp->getNext();
            cout << "Iterating the while loop printing what's in temp: " << temp->getKey() << endl;

            if (temp->getKey().compare(key)) {

            }
        }
        cout << "Iterated the whole list, Key not found. Throw exception" << endl;
        // throw exeption here
    }*/
}



const WorkItem &WorkQueue::nextWorkItem(int priority) const {
    Node *temp = phead;
    while (temp->getPriority() != priority)
    {
        temp = temp->getNext();
    }
    return temp->getThis();
}

void WorkQueue::deleteAllWorkItems() { // May be too agressive? weird problems
    Node *temp1 = phead;
    Node *temp2 = phead;

    while(temp1 != NULL)
    {
        temp2 = phead->getNext();
        delete(temp1);
        temp1 = temp2;
    }

    phead = NULL;
}




//////////////////////////////
// TEST
//////////////////////////////
void WorkQueue::print() const {
    Node *temp = phead;
    while (temp != NULL)
    {
        cout << "priority: " << temp->getPriority() << endl;
        cout << "key: " << temp->getKey() << endl;
        cout << "temp->getNext is: " << temp->getNext() << endl;
        temp = temp->getNext();

    }
}







