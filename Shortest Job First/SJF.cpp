#include<iostream>
#include <fstream>

using namespace std;

int main()
{
	int p1[20], p2[20], p3[20], p4[20], p5[20], p6[20], p7[20], p8[20], p9[20];
	int	i, j, n, total = 0, pos, temp;
	double avg_wt, avg_tat;
	
	ifstream in;
	in.open("CPU.txt");

	if (in.fail())
	{
		cout << "Input file opening failed.\n";
	}

	for (int i = 0; i < 143; i++)
	{

	}
	/*cout << "nEnter Burst Time and Priorityn";
	for (i = 0; i<n; i++)
	{
		cout << "nP[" << i + 1 << "]n";
		cout << "Burst Time:";
		cin >> bt[i];
		cout << "Priority:";
		cin >> pr[i];
		p[i] = i + 1;           //contains process number
	}

	//sorting burst time, priority and process number in ascending order using selection sort
	for (i = 0; i<n; i++)
	{
		pos = i;
		for (j = i + 1; j<n; j++)
		{
			if (pr[j]<pr[pos])
				pos = j;
		}

		temp = pr[i];
		pr[i] = pr[pos];
		pr[pos] = temp;

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}

	wt[0] = 0;            //waiting time for first process is zero

	//calculate waiting time
	for (i = 1; i<n; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += bt[j];

		total += wt[i];
	}

	avg_wt = total / n;      //average waiting time
	total = 0;

	cout << "nProcesst    Burst Time    tWaiting TimetTurnaround Time";
	for (i = 0; i<n; i++)
	{
		tat[i] = bt[i] + wt[i];     //calculate turnaround time
		total += tat[i];
		cout << "nP[" << p[i] << "]tt  " << bt[i] << "tt    " << wt[i] << "ttt" << tat[i];
	}

	avg_tat = total / n;     //average turnaround time
	cout << "nnAverage Waiting Time=" << avg_wt;
	cout << "nAverage Turnaround Time=" << avg_tat;*/

	return 0;
}