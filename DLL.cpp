
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
using namespace std;


DLL::DLL(){
    first = nullptr;
    last = nullptr;
    numTasks = 0;
    tothrs = 0;
    totmin = 0;
}

DLL::DLL(string taskname, int priority, int hours, int mins){
    DNode *newNode = new DNode{taskname, priority, hours, mins};
    last = newNode;
    numTasks = numTasks + 1;
    tothrs = tothrs + hours;
    totmin = totmin + mins;
}

DLL::~DLL(){
    //cout << "deleting node with task " << endl;
    DNode *current = first;
    while(current){
        current = current->next;
        delete current;
    }
    delete current;
    first = NULL;
    last = NULL;
    numTasks = 0;
    tothrs = 0;
    totmin = 0;
}

void DLL::push(string taskname, int priority, int hours, int mins) {
    DNode *newTask = new DNode(taskname, priority, hours, mins);;
    DNode *current = first;
    if(!first){
        first = newTask;
        last = newTask;
        numTasks = numTasks + 1;
        tothrs = tothrs + hours;
        totmin = totmin + mins;
    }
    else if(!current->next){
        if(priority >= current->task->priority){
            current->next = newTask;
            last = newTask;
            numTasks = numTasks + 1;
            tothrs = tothrs + hours;
            totmin = totmin + mins;
            return;
        }
        else if (priority < current->task->priority){
            current->prev = newTask;
            first = newTask;
            numTasks = numTasks + 1;
            tothrs = tothrs + hours;
            totmin = totmin + mins;
            return;
        }
    }
    else if(priority == 3){
        DNode *temp = last;
        temp->next = newTask;
        last = newTask;
        numTasks = numTasks + 1;
        tothrs = tothrs + hours;
        totmin = totmin + mins;
    }
    else {
        DNode *temp2 = first;
        if (priority == 2){
            while (temp2->task->priority <= 2) {
                if (!temp2->next){
                    newTask->prev = temp2;
                    newTask->next = temp2->next;
                    temp2->next = newTask;
                    numTasks = numTasks + 1;
                    tothrs = tothrs + hours;
                    totmin = totmin + mins;
                    return;
                }
                if(temp2->next->task->priority > 2) {
                    newTask->prev = temp2;
                    newTask->next = temp2->next;
                    temp2->next = newTask;
                    numTasks = numTasks + 1;
                    tothrs = tothrs + hours;
                    totmin = totmin + mins;
                    return;
                }
                temp2 = temp2->next;
            }
        }
        else if(priority ==1){
            while (temp2->task->priority == 1) {
                if(temp2->next->task->priority > 1){
                    newTask->prev = temp2;
                    newTask->next = temp2->next;
                    temp2->next = newTask;
                    numTasks = numTasks + 1;
                    tothrs = tothrs + hours;
                    totmin = totmin + mins;
                    return;
                }
                temp2 = temp2->next;
            }
        }
        newTask->prev = temp2;
        newTask->next = temp2->next;
        temp2->next = newTask;
        numTasks = numTasks + 1;
        tothrs = tothrs + hours;
        totmin = totmin + mins;
    }
}

Task *DLL::pop() {
    //numTasks = numTasks - 1;
	DNode *temp = last;
    tothrs = tothrs - temp->task->hr;
    totmin = totmin - temp->task->min;
    last = temp->prev;
    return temp->task;
}

int DLL::remove(int tasknum) {
    DNode *temp1= first;
    for(int i=0; i<tasknum; i++){
        temp1 = temp1->next;
        if(temp1 == NULL){
            return -1;
        }
    }
    temp1->prev->next = temp1->next;
    temp1->next->prev = temp1->next;
    delete temp1;
    numTasks--;
    return tasknum;
}

void DLL::addTime(int hours, int mins) {
    tothrs = tothrs + hours;
    totmin = totmin + mins;
}

void DLL::removeTime(int hours, int mins) {
    tothrs = tothrs - hours;
    totmin = totmin - mins;
}

void DLL::moveUp(int tasknum) {
    DNode *current = first;
    for(int i=1; i<tasknum; i++){
        current = current->next;
    }
    if(current->prev == last){
        first = current->next;
        first->next = NULL;
        current->prev = last;
        last = current;
        current->next = NULL;
    }
    else{
        DNode *previous = current->prev;
        current->next = previous;
        current->prev = previous->prev;
        previous->next = previous->next->next;
        previous->prev = current;
        if(current->task->priority<previous->task->priority){
            current->task->priority=previous->task->priority;
        }
    }
}

void DLL::moveDown(int tasknum) {
    DNode *current = first;
    for(int i=1; i<tasknum; i++){
        current = current->next;
    }
    if(current->next == NULL){
        current->next = first;
        last = current->prev;
        current->prev->next = NULL;
        first = current;
        current->prev = NULL;
    }
    else{
        DNode *nextNode = current->next;
        current->next = nextNode->next;
        nextNode->prev = current->prev;
        nextNode->next = current;
        if(current->task->priority>nextNode->task->priority){
            current->task->priority=nextNode->task->priority;
        }
    }
}

void DLL::changePriority(int tasknum, int newPriority) {
    DNode *current = first;
    for(int i=1; i<tasknum; i++){
        current = current->next;
    }
    current->task->priority = newPriority;
}

void DLL::listDuration(int *pHours, int *pMins,int priority) {
    DNode *current = first;
    while(current->task->priority != priority && current!= NULL){
        current = current->next;
    }
    while(current->task->priority == priority){
        *pHours = *pHours + current->task->hr;
        *pMins = *pMins + current->task->min;
        if(*pMins >= 60){
            *pMins = *pMins - 60;
            *pHours++;
        }
    }
}

void DLL::printList() {
	if (!first){
        cout << "Empty List" << endl;
    }
	DNode *current = first;
	cout << "Total Time Required: "<<tothrs<< ":"<<totmin<<endl;
	while (current) {
		current->task->printTask();
		current = current->next;
	}
	cout << endl;
}

void DLL::printList(int priority) {
	if (!first){
        cout << "Empty List" << endl;
    }
    DNode *current = first;
    while(current->task->priority != priority && current!= NULL){
        current = current->next;
    }
    while(current->task->priority == priority) {
        cout << "Total Time Required: " << tothrs << ":" << totmin << endl;
        while (current != NULL) {
            current->task->printTask();
            current = current->next;
        }
    }
    cout << endl;
}

void DLL::printReverse() {
	if (!first){
        cout << "Empty List" << endl;
    }
    DNode *current = last;
    cout << "Total Time Required: "<<tothrs<< ":"<<totmin<<endl;
    while (current) {
        current->task->printTask();
        current = current->prev;
    }
    cout << endl;
}
