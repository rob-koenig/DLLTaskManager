/*
 * DNode.cpp
 *
 *  Created on: Apr 2, 2020
 *      Author: 13027
 */

#include <iostream>
#include "DNode.hpp"
using namespace std;

/* write your constructors here! */
DNode::DNode(){
    task = new Task();
    prev = nullptr;
    next = nullptr;
}

DNode::DNode(string taskname, int priority, int hours, int mins){
    //DNode *task = new DNode(taskname, priority, hours, mins);
    Task *newTask = new Task{taskname, priority, hours, mins};
    task = newTask;
    prev = nullptr;
    next = nullptr;
}

DNode::~DNode() {
	cout << "deleting node with task " << task->tasknum << endl;
}