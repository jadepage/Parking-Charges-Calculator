#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

float charges(float custTime);

int main()
{

	// Ask 3 customers for their parking hours
	float custOne, custTwo, custThree, custTime;
	for (int num = 1; num <= 3; num++)
	{
		cout << "Please enter customer " << num << " parking hours: ";
		cin >> custTime;
		cout << endl;

		// Store the customers parking hours
		if (num == 1)
		{
			custOne = custTime;
		}
		else if (num == 2)
		{
			custTwo = custTime;
		}
		else
		{
			custThree = custTime;
		}
	}

	// Display the table header
	cout << setw(10) << left << "Cars " << left << setw(10) << "Hours" << left << setw(10) << "Charges" << endl;

	// Display the parking hours and charge of the first customer
	cout << setw(10) << left << " 1" << left << setw(10) << custOne << left << setw(10) << charges(custOne) << endl;

	// Display the parking hours and charge of the second customer
	cout << setw(10) << left << " 2" << left << setw(10) << custTwo << left << setw(10) << charges(custTwo) << endl;

	// Display the parking hours and charge of the third customer
	cout << setw(10) << left << " 3" << left << setw(10) << custThree << left << setw(10) << charges(custThree) << endl;

	// Add the total hours and parking charges and display the result
	cout << setw(10) << left << "Total" << left << setw(10) << custOne + custTwo + custThree << left << setw(10) << charges(custOne) + charges(custTwo) + charges(custThree) << endl;
}

// Calculates the customer charges
float charges(float custTime)
{	
	float minFee = 12.00, addFee = 0.90, maxFee = 20.00;
	float minHours = 3, maxHours = 24;
	float custCharge;

	/* If customer's parking hours are less than 3 hours,
		customer pays 12.00
	*/
	if (custTime <= minHours)
	{
		custCharge = minFee;
	}

	/* If customer's parking hours are more than 3 hours
		and less than 24 hours, customer is charged 
		an additonal fee of 0.90 per hour
	*/
	else if (custTime > minHours && custTime <= maxHours)
	{
		custCharge = minFee + ((custTime - minHours) * addFee);

		/* Check to see if customer charge is more than
			the maximum fee and if true then only
			charge customer 20.00
		*/
		if (custCharge > maxFee)
		{
			custCharge = maxFee;
		}
	}

	/* If customer's hours are more than 24 hours
		then only charge the customer 20.00
	*/
	else
	{
		custCharge = maxFee;
	}
	
	return custCharge;	
}