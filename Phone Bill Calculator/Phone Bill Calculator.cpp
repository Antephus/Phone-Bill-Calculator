/* Carrie Morris,  MSc Applied Computing
08000 5769
Handed in 28/10/2016
Version...3? 4?? */


#include <iostream>
#include <iomanip>
using namespace std;


class Bill
{
private:
	int minutes;
	double discount;
	double total_bill;
	double bill_payable;
	const double LANDLINE_RATE = 0.05;
	const double MOBILE_RATE = 0.15;

public:
	Bill();
	
	void set_minutes();
	void set_minutes(int mins);
	void set_discount(int minutes);
	void set_total_bill(int minutes, double rate);
	void set_bill_payable(double total_bill, double discount);
	
	int get_minutes();
	double get_discount();
	double get_total_bill();
	double get_bill_payable();
	const double get_landline_rate();
	const double get_mobile_rate();
};



// Display a menu of options for users to choose until the user indicates they are finished using the program
int main()
{
	int choice;
	
	cout << "Welcome! This program will calculate your phone bills for you." << endl;

	do
	{
		cout << "------------------------------- MAIN MENU -------------------------------" << endl;
		cout << "1. Calculate landline bill" << endl;
		cout << "2. Calculate mobile phone bill" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "Please enter the number of your choice (1-2 or 0 to exit):" << endl;
		cin >> choice;


		// Get a new choice if input was invalid
		while (choice != 1 && choice != 2 && choice != 0)
		{
			cout << "That's not a valid choice, please enter 1-2, or 0 to exit: " << endl;
			cin >> choice;
		}

		cout << endl << endl;

				
		switch (choice)
		{
		// Calculate and display landline bill details
		case 1:
		{
			Bill landline = Bill();


			// Get minutes from the user and calculate and set all other variables based on this
			landline.set_minutes();
			landline.set_total_bill(landline.get_minutes(), landline.get_landline_rate());	
			landline.set_discount(landline.get_minutes());
			landline.set_bill_payable(landline.get_total_bill(), landline.get_discount());
			

			// Display all billing details for the user
			cout << "-------------------- Your Landline Bill --------------------" << endl;
			cout << "Minutes Spent: " << landline.get_minutes() << endl;
			cout << "Current Rate: " << char(156) << landline.get_landline_rate() << " per minute" << endl;
			cout << "Total Bill: " << char(156) << landline.get_total_bill() << endl;
			cout.unsetf(ios_base::fixed);
			cout << "Discount Applicable: " << landline.get_discount() * 100 << "%" << endl;
			cout << "--------------------" << endl;
			cout << "AMOUNT PAYABLE: " << char(156) << setprecision(2) << fixed << landline.get_bill_payable() << endl;
			cout << "--------------------" << endl << endl << endl;
			cout << "Would you like to calculate another bill?" << endl << endl;

			break;
		}


		// Calculate and display mobile phone bill details
		case 2:
		{
			Bill mobile = Bill();

			// Get minutes from the user and calculate and set all other variables based on this
			mobile.set_minutes();
			mobile.set_total_bill(mobile.get_minutes(), mobile.get_mobile_rate());
			mobile.set_discount(mobile.get_minutes());
			mobile.set_bill_payable(mobile.get_total_bill(), mobile.get_discount());


			// Display all billing details for the user
			cout << "-------------------- Your Mobile Phone Bill --------------------" << endl;
			cout << "Minutes Spent: " << mobile.get_minutes() << endl;
			cout << "Current Rate: " << char(156) << mobile.get_mobile_rate() << " per minute" << endl;
			cout << "Total Bill: " << char(156) << mobile.get_total_bill() << endl;
			cout.unsetf(ios_base::fixed);
			cout << "Discount Applicable: " << mobile.get_discount() * 100 << "%" << endl;
			cout << "--------------------" << endl;
			cout << "AMOUNT PAYABLE: " << char(156) << setprecision(2) << fixed << mobile.get_bill_payable() << endl;
			cout << "--------------------" << endl << endl << endl;
			cout << "Would you like to calculate another bill?" << endl << endl;
			break;
		}


		case 0:
			// If the user just wants to exit, don't print default error message and just break
			break;


		default:
			// If not an expected entry, get a new choice number
			cout << "That's not a valid choice, please enter 1-2, or 0 to exit: " << endl;
			cin >> choice;
			break;
		}

	//end of main menu
	} while (choice != 0);

	cout << "Thank you, good bye :)" << endl;

	return 0;
}



Bill::Bill()
{
	minutes = 0;
	discount = 0.0;
	total_bill = 0.0;
	bill_payable = 0.0;
}



void Bill::set_minutes()
{
	// Get a number and keep displaying an error message and getting new numbers until the entered number is valid
	cout << "How many minutes have you spent using your phone?" << endl;
	cout << "Please enter a whole number: " << endl;
	cin >> minutes;

	while (minutes < 0)
	{
		cout << "Sorry, you must enter a positive, whole number. Enter 0 if you didn't use your landline at all: ";
		cin >> minutes;
	}

	cout << endl << endl;
}



// Was used for quicker/easier testing
void Bill::set_minutes(int mins)
{
	minutes = mins;
}



void Bill::set_discount(int minutes)
{
	// Figure out how much discount the user should get based on how many minutes they've used
	if (minutes <= 100)
		discount = 0.0;

	else if (minutes > 100 && minutes <= 200)
		discount = 0.05;

	else if (minutes > 200 && minutes <= 400)
		discount = 0.1;

	else
		discount = 0.15;
}



void Bill::set_total_bill(int minutes, double rate)
{
	// Calculate the total bill amount
	total_bill = minutes * rate;
}



void Bill::set_bill_payable(double total_bill, double discount)
{
	// If the user gets a discount, calculate their bill after discount
	if (discount == 0.0)
		bill_payable = total_bill;
	else
		bill_payable = total_bill - (total_bill * discount);
}


// Series of getters


int Bill::get_minutes()
{
	return minutes;
}



double Bill::get_discount()
{
	return discount;
}



double Bill::get_total_bill()
{
	return total_bill;
}



double Bill::get_bill_payable()
{
	return bill_payable;
}



const double Bill::get_landline_rate()
{
	return LANDLINE_RATE;
}



const double Bill::get_mobile_rate()
{
	return MOBILE_RATE;
}