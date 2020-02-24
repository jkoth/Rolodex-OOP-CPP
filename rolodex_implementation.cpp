#include "rolodex_interface.h"

#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;


void Rolodex::add_list(Rolodex & object, vector<Rolodex> & list)			// Add entry function
{
		bool more;
		while (more)
		{
			cin.clear();
			object.read_entry();						// Reads new rolodex entry
			list.push_back(object);						// Adds to vector list
		
			cout << "\nWould you like to add another entry? (Y/y): ";
			char ans;
			cin >> ans;
		
			if(ans != 'Y' && ans != 'y')
			{
				more = false;
			} else  more = true;
		}
}

void Rolodex:: read_entry()								// cout and cin object elements to be stored in Rolodex entries
{
	cin.ignore(INT_MAX, '\n');
	cout << "Please enter First Name: ";
	getline(cin, r_fname);
	
		while(r_fname.size() > max_fname)
		{
			cin.clear();

			cout << "\nFirst Name should be less than " << max_fname << " characters.\n";
			cout << "\nPlease enter First Name: ";
			getline(cin, r_fname);
		}

	
	cout << "Please enter Last Name: ";
	getline(cin, r_lname);

		while(r_lname.size() > max_lname)
		{
			cin.clear();

			cout << "\nLast Name should be less than " << max_lname << " characters.\n";
			cout << "\nPlease enter Last Name: ";
			getline(cin, r_lname);
		}
	

	cout << "Please enter Street name: ";
	getline(cin, r_street);

		while(r_street.size() > max_street)
		{
			cin.clear();

			cout << "\nStreet name should be less than " << max_street << " characters.\n";
			cout << "\nPlease enter Street name: ";
			getline(cin, r_street);
		}

	
	cout << "Please enter City: ";
	getline(cin, r_city);

		while(r_city.size() > max_city)
		{
			cin.clear();

			cout << "\nCity should be less than " << max_city << " characters.\n";
			cout << "\nPlease enter City: ";
			getline(cin, r_city);
		}

	
	cout << "Please enter State: ";
	getline(cin, r_state);

		while(r_state.size() > max_state)
		{
			cin.clear();

			cout << "\nState should be less than " << max_state << " characters.\n";
			cout << "\nPlease enter State: ";
			getline(cin, r_state);
		}

	
	cout << "Please enter Zip Code (" << max_zip << " degit): ";
	cin >> r_zip;
		
		while(cin.fail() || num_size(r_zip) > max_zip)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\nInvalid input!\n";
	
			cout << "\nPlease enter Zip Code (" << max_zip << " degit): ";
			cin >> r_zip;
		}
	
	cin.ignore(INT_MAX, '\n');
	cout << "Please enter Email address: ";
	getline(cin, r_email);

		while(r_email.size() > max_email)
		{
			cin.clear();

			cout << "\nEmail should be less than " << max_email << " characters.\n";
			cout << "\nPlease enter Email address: ";
			getline(cin, r_email);
		}

	
	cout << "Please enter Phone Number: ";
	cin >> r_phone_num;
	
		while(cin.fail() || num_size(r_phone_num) > max_phone)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\nInvalid input!\n";

			cout << "\nPlease enter Phone Number: ";
			cin >> r_phone_num;
		}
	string remainder;
	getline(cin, remainder);						// Not used anywhere. Just collecting anything left in cin buffer
}

void Rolodex::print_header() const						// Prints header with setw equal to field's max size
{
	cout << '\n';
	cout << setw(max_numCol) << left << "No." << "|" << setw(max_fname) << left << "FIRST NAME" << "|" << setw(max_lname) 
	     << left << "LAST NAME" << "|" << setw(max_phone + 5) << left << "PHONE NUMBER" << "|" << setw(max_email) 
	     << left << "EMAIL" << "|" << left << "ADDRESS \n";
	cout << setfill ('=') << setw(max_numCol) << "" << "|" << setw(max_fname) << "" << "|" << setw(max_lname) << "" 
	     << "|" << setw(max_phone + 5) << "" << "|" << setw(max_email) << "" << "|" << setw(60) << "";
	cout << '\n';
}

void Rolodex::print_entries(size_t index) const					// Prints out object elements, position is shown by index + 1 to avoid 0 pos
{
	cout << setfill(' ');
	cout << setw(max_numCol) << left << index + 1 << "|" << setw(max_fname) << left << r_fname << "|" << setw(max_lname) << left 
	     << r_lname << "|" << setw(max_phone + 5) << left << r_phone_num << "|" << setw(max_email) << left << r_email << "|" 
	     << left << r_street << ", " << r_city << ", " << r_state << ", " << r_zip;
}

char Rolodex::initial_menu() const						// cout initial menu & cin initial user choice
{
	cout << "\nWelcome to DegiRolodex!!\n\n";
	cout << "Please choose from below options\n\n";
	cout << "1) Add entry (A/a)\n";
	cout << "2) Edit entry (E/e)\n";
	cout << "3) Delete entry (D/d)\n";
	cout << "4) Find entry (F/f)\n";
	cout << "5) Print all entries (P/p)\n";
	cout << "6) Quit (Q/q)\n";
	
	cout << "Select by option number or letter: ";
	char initial_choice;
	cin >> initial_choice;
	
	return initial_choice;
}

char Rolodex::submenu() const							// cout submenu for find choice from initial menu & cin find by choice
{
	cin.clear();
	cout << "\n\n1) find by Name (N/n)\n";
	cout << "2) find by Address (A/a)\n";
	cout << "3) find by Phone number (P/p)\n";
	cout << "4) find by Email address (E/e)\n";
	cout << "5) Return to Main Menu (M/m)\n";
	
	cout << "Select by option number or letter: ";
	char sub_choice;
	cin >> sub_choice;
	
	return sub_choice;
}

long Rolodex::find_byName(string searchfor) const			// find by Name function compares first name and last name agains search value for given
{
	if (r_fname == searchfor || r_lname == searchfor)
	{
		return 1;
	}
	
	return -1;
}

long Rolodex::find_byAddress(string searchfor) const			// find by address fields except zip
{
	if (r_street == searchfor || 
	    r_city == searchfor || 
	    r_state == searchfor)
	{
		return 1;
	}
	
	return -1;
}

long Rolodex::find_byEmail(string searchfor) const			// find by email
{
	if (r_email == searchfor)
	{
		return 1;
	}
	
	return -1;
}

long Rolodex::find_byNumber(unsigned int searchfor) const
{
	if (r_phone_num == searchfor)					// find by Phone number
	{
		return 1;
	}
	
	return -1;
}

void Rolodex::remove_entry(vector<Rolodex> & list, size_t delt_index)		// Deletes entry based on supplied index to be removed, (index - 1) to get proper index
{
	for (size_t pos = delt_index - 1; pos < list.size() -1; pos++)
	{
		list[pos] = list[pos + 1];
	}
	list.pop_back();
}

void Rolodex::edit_entry(vector<Rolodex> & list, size_t edit_index)	// Allows User to overwrite entry for index picked to edit, (index - 1) to get proper index
{
	list[edit_index - 1].read_entry();
}

unsigned int Rolodex::num_size(unsigned int number) const		// To count the size of phone number and zip code
{
	unsigned int size = 0;
		do
		{
			number /= 10;
			size += 1;
		} while (number != 0);
	return size;
}

