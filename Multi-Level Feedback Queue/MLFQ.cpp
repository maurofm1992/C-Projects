//Name: Mauricio Da Graca
//Class: COP4610
//Date: 3/20/2016
//CPU scheduling algorithm assignment.


/*This program simulates the process of the MLFQ scheduling algorithm*/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void main()
{
	int bt[20], IOt[20], p[20], wt[20], tat[20];
	int i, j, n, q, total = 0, pos, temp;
	float avg_wt, avg_tat;
	cout << "Enter number of process:";
	cin >> n;

	cout << "\nEnter CPU burst:\n";
	for (i = 0; i<n; i++)
	{
		cout << "p" << i + 1 << ":";
		cin >> bt[i];
		p[i] = i + 1;           //contains process number
	}


	cout << "\nEnter I/O Time:\n";
	for (i = 0; i<n; i++)
	{
		cout << "p" << i + 1 << ":";
		cin >> IOt[i];
		p[i] = i + 1;           //contains process number
	}

	//sorting burst time in ascending order using selection sort
	for (i = 0; i<n; i++)
	{
		pos = i;

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}

	wt[0] = 0; //waiting time for first process will be zero

	//calculate waiting time
	for (i = 1; i<n; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += bt[j];

		total += wt[i];
	}

	avg_wt = (float)total / n;      //average waiting time
	total = 0;

	cout << ("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time \n");
	for (i = 0; i<n; i++)
	{
		tat[i] = bt[i] + wt[i];     //calculate turnaround time
		total += tat[i];
		cout << p[i] << "\t\t";
		cout << bt[i] << "\t\t";
		cout << wt[i] << "\t\t";
		cout << tat[i] << "\n";
	}

	avg_tat = (float)total / n;     //average turnaround time
	printf("\n\nAverage Waiting Time=%f", avg_wt);
	printf("\nAverage Turnaround Time=%f\n", avg_tat);
}