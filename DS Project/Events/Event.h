#pragma once

#include "../Defs.h"
#include "../Generic_DS/Queue.h"
#include "../Generic_DS/PriorityQueue.h"
#include "../Generic_DS/Node.h"
#include "../Generic_DS/LinkedList.h"
#include "../Rest/Cook.h"
#include "../Rest/Order.h"

class Restaurant;

//The base class for all possible events in the system (abstract class)
class Event
{
protected:
	int EventTime;	//Timestep when this event takes place
	int OrderID;	//each event is related to certain order
public:
	Event();
	Event(int eTime, int ordID);
	static int get_arrival_count();
	static int arrival_count;
	int getEventTime();
	int getOrderID();
	virtual ~Event();
	virtual void setDishes(int size) {};
	virtual void setMoney(double money) {};
	virtual void Execute(Restaurant* pRest)=0;	////a pointer to "Restaurant" and events need it to execute
};