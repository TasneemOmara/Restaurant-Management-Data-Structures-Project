#pragma once
#include <iostream>
#include <fstream>
#include "ArrivalEvent.h"
#include "Event.h"
#include "Queue.h"
#include "CancellationEvent.h"
using namespace std;
///class Restaurant;

void Read_File1(int Arr[12])//, char** Events, int** Event_Data )//,Queue<Event*> Q)
{
	ifstream myfile;
	// replace "dir" with the directory of the file you want to read and make sure the address has no spaces in it and to put the address inside quotation marks
	myfile.open("D:/Zewail/mext.txt");
	//initiating and array that includes speeds, number, breaks for different cooks types and timesteps for promotion and number of events
	// Arr[12] = {SN, SG, SV, N, G, V, BM, BN, BG, BV, AutoS, M};
	/*
	SN = speed of all normal cooks
	SG = speed for vegan cooks
	SV = speed for VIP cooks
	N = number of normal cooks
	G = number of vegan cooks
	V = number of VIP cooks
	BM = is the number of meals the cook must do before taking a break
	BN = the break duration in timesteps for normal cooks
	BG = the break duration in timesteps for vegan ones
	BV = the break duration in timesteps for VIP cooks.
	AutoS = represent the number of timesteps after which an order is automatically promoted to VIP
	M = represents the number of events following this line
	*/
	//int Arr[12];
	for (int i = 0; i < 12; i++)
	{
		myfile >> Arr[i];
	}
	int M = Arr[11];
	//Queue<Event*> EventsQueue;
	/*
	Event** Events_Array;
	Events_Array = new Event*[M];
	char R;
	int SIZE;
	char TYP;
	int TS;
	int ID;
	Int MONEY;
	for (int i = 0; i < M; i++)
	{
		myfile >> R;
		switch (R)
		{
		case 'R':
			myfile >> SIZE;
			myfile >> TYP;
			myfile >> TS;
			myfile >> ID;
			myfile >> MONEY;
			Events_Array[i] = ArrivalEvent*(TS, ID, TYP);


			break;
		case 'X':

			break;

		}
	}
	*/
	//old starts here
	//char** Events;
	//int** Event_Data;
	//Events = new char* [M];
	//Event_Data = new int* [M]
	myfile.close();
}

void Read_File2(char** Events, int** Event_Data, int M)
{
	ifstream myfile;
	// replace "dir" with the directory of the file you want to read and make sure the address has no spaces in it and to put the address inside quotation marks
	myfile.open("D:/Zewail/mext.txt");
	int x;
	for (int i = 0; i < 12; i++)
	{
		myfile >> x;
	}

	for (int i = 0; i < M; i++)
	{
		char Event_Type;
		myfile >> Event_Type;
		switch (Event_Type)
		{
		case 'R':
			Events[i] = new char[2];
			Event_Data[i] = new int[4];
			Events[i][0] = Event_Type;
			myfile >> Event_Data[i][0];
			myfile >> Events[i][1];
			for (int j = 1; j <= 3; j++)
			{
				myfile >> Event_Data[i][j];
			}
			break;
		case 'X':
			Events[i] = new char[1];
			Events[i][0] = Event_Type;
			Event_Data[i] = new int[2];
			myfile >> Event_Data[i][0];
			myfile >> Event_Data[i][1];
			break;
		case 'P':
			Events[i] = new char[1];
			Events[i][0] = Event_Type;
			Event_Data[i] = new int[3];
			for (int j = 0; j <= 2; j++)
			{
				myfile >> Event_Data[i][j];
			}
			break;
		}
	}

	myfile.close();
	/*
	char R;
	char T;
	ORD_TYPE TY;
	for (int i = 0; i < M; i++)
	{
		R = Events[i][0];
		if (R == 'R')
		{
			T = Events[i][1];
			switch (T)
			{
			case 'N':
				TY = ORD_TYPE::TYPE_NRM;
				break;
			case 'F':
				TY = ORD_TYPE::TYPE_VEG;
				break;
			case 'V':
				TY = ORD_TYPE::TYPE_VIP;
				break;

			}
			//TY = ORD_TYPE(Events[i][1]);
			ArrivalEvent* A = new ArrivalEvent(Event_Data[i][0], Event_Data[i][1], TY);
			A->setDishes(Event_Data[i][2]);
			A->setMoney(Event_Data[i][3]);
			Q.enqueue(A);
			break;
		}
		else if (R == 'X')
		{
			CancellationEvent* E = new CancellationEvent(Event_Data[i][0], Event_Data[i][1]);
			Q.enqueue(E);
			break;
		}
	}
	*/
}

void Enqueuer(Event** Array, char** Events, int** Event_Data, int M)
{

	char R;
	char T;
	ORD_TYPE TY;
	for (int i = 0; i < M; i++)
	{
		R = Events[i][0];
		if (R == 'R')
		{
			T = Events[i][1];
			switch (T)
			{
			case 'N':
				TY = TYPE_NRM;
				break;
			case 'F':
				TY = TYPE_VEG;
				break;
			case 'V':
				TY = TYPE_VIP;
				break;

			}
			//TY = ORD_TYPE(Events[i][1]);
			ArrivalEvent* A = new ArrivalEvent(Event_Data[i][0], Event_Data[i][1], TY);
			Array[i] = A;
			A->setDishes(Event_Data[i][2]);
			A->setMoney(Event_Data[i][3]);
			//EventsQueue.enqueue(A);
			break;
		}
		else if (R == 'X')
		{

			CancellationEvent* E = new CancellationEvent(Event_Data[i][0], Event_Data[i][1]);
			Array[i] = E;
			//EventsQueue.enqueue(E);
			break;
		}
	}
}
