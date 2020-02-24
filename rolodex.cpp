
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

const size_t max_fname = 20;
const size_t max_lname = 20;
const size_t max_street = 40;
const size_t max_city = 30;
const size_t max_state = 2;
const size_t max_email = 40;
const size_t max_zip = 5;
const size_t max_phone = 10;
const size_t max_numCol = 4;			//for entry number print out
string print_divider = "|";			//for print out divider
char setfill_data = ' ';			//for print entries setfill
char setfill_head = '=';			//for print header format
string print_addDivdr = ", ";			//for joining address in one field


class Rolodex
{
public:
	Rolodex(): r_fname(), r_lname(), r_street(), r_city(), r_state(), r_zip(0), r_email(), r_phone_num(0) {}
	
	void read_entry();
	void add_list(Rolodex & object, vector<Rolodex> & list);			
	void remove_entry(vector<Rolodex> & list, size_t delt_index);
	void edit_entry(vector<Rolodex> & list, size_t edit_index);
		
	unsigned int num_size(unsigned int number) const;
	
	char initial_menu() const;
	char submenu() const;
	void print_header() const;
	void print_entries(size_t index) const;
	long find_byName(string searchfor) const;
	long find_byAddress(string searchfor) const;
	long find_byEmail(string searchfor) const;
	long find_byNumber(unsigned int searchfor) const;

private:
	string r_fname;
	string r_lname;
	string r_street;
	string r_city;
	string r_state;
	unsigned int r_zip;
	string r_email;
	unsigned int r_phone_num;
};

int main()
{
	vector<Rolodex> rolodex_entries;							// Starting a vector to hold rolodex entries

	Rolodex card;										// Constructing new Rolodex object using Default Constructor
	
	bool more;										// For condition to run while loop
	while (more)
	{
		cin.clear();
		char choice = card.initial_menu();						// Calling class member funciton to cout and cin initial menu and choice
	
		if (choice == 'a' || choice == 'A' || choice == '1')				// Choice to add entry
		{
			card.add_list(card, rolodex_entries);
			
			cin.ignore(INT_MAX, '\n');						
			cout << "\nWould you like to return to main menu? (Y/y): ";
			char ans;
			cin >> ans;
	
			if(ans != 'Y' && ans != 'y')
			{
				cout << "\nThank your for using DigiRolodex!! See you next time...\n\n";	// Terminate the loop and return 0 to main
				return 0;
			} else  more = true;
		} else	
		if (choice == 'e' || choice == 'E' || choice == '2')						// Edit option
		{
			card.print_header();									// To display existing entries for edit choice
				
			for (size_t index = 0; index < rolodex_entries.size(); index++)
			{
				rolodex_entries[index].print_entries(index);					
				cout << '\n';
			}

			cin.ignore(INT_MAX, '\n');
			cout << "\n\nWhich entry would you like to Edit? Enter \"0\" to return to main menu: ";		// Zero is used as terminating key
			size_t edit_index;										// User can key in zero to jump out of edit
			cin >> edit_index;
			
				while(cin.fail() || edit_index > rolodex_entries.size())				// To avoid picking up invalid or out of range
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Not a valid choice... choose from listed entry no.: ";
					cin >> edit_index;
				}

			if(edit_index != 0)										
			{
				card.edit_entry(rolodex_entries, edit_index);					// Calling edit member function, passing vec and index

				cout << "\nEntry is Edited...\n";	
				
				card.print_header();								// Print Rolodex entries post edit
				
				for (size_t index = 0; index < rolodex_entries.size(); index++)
				{
					rolodex_entries[index].print_entries(index);
					cout << '\n';
				}

				cout << "\nWould you like to return to main menu? (Y/y): ";
				char ans;
				cin >> ans;
	
				if(ans != 'Y' && ans != 'y')
				{
					cout << "\nThank your for using DigiRolodex!! See you next time...\n\n";
					return 0;
				} else  more = true;
			}
		} else
		if (choice == 'd' || choice == 'D' || choice == '3')						// Delete option
		{
			card.print_header();									// To print existing entries for delete choice
				
			for (size_t index = 0; index < rolodex_entries.size(); index++)
			{
				rolodex_entries[index].print_entries(index);
				cout << '\n';
			}

			cin.ignore(INT_MAX, '\n');
			cout << "\n\nWhich entry would you like to delete? Enter \"0\" to return to main menu: ";	// Zero to terminate edit function by user
			size_t delt_index;
			cin >> delt_index;
			
				while(cin.fail() || delt_index > rolodex_entries.size())				// To avoid invalid or out of range options
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Not a valid choice... choose from listed entry no.: ";
					cin >> delt_index;
				}

			if(delt_index != 0)
			{
				card.remove_entry(rolodex_entries, delt_index);					// Calling delete member function, passing vec & index
		
				cout << "\nEntry is deleted...\n";	
				
				card.print_header();
				
				for (size_t index = 0; index < rolodex_entries.size(); index++)
				{
					rolodex_entries[index].print_entries(index);
					cout << '\n';
				}

				cin.ignore(INT_MAX, '\n');	
				cout << "\nWould you like to return to main menu? (Y/y): ";
				char ans;
				cin >> ans;
	
				if(ans != 'Y' && ans != 'y')
				{
					cout << "\nThank your for using DigiRolodex!! See you next time...\n\n";
					return 0;
				} else  more = true;
			}
		} else
		if (choice == 'f' || choice == 'F' || choice == '4')						// Find option
		{
			cin.clear();
			char sub_choice = card.submenu();
			
			if (sub_choice == 'N' || sub_choice == 'n' || sub_choice == '1')			// Find by Name option
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Plesae enter Name to search: ";					// To get search item
				string search_value;
				getline(cin, search_value);

				card.print_header();
				
				for (size_t index = 0; index < rolodex_entries.size(); index++)			
				{
					long found = rolodex_entries[index].find_byName(search_value);		// Find by Name func, if value found, returns 1 else -1
					if (found == 1)								// If found, prints object stored in that vec index
					{
						rolodex_entries[index].print_entries(index);
						cout << '\n';
					}
				}
				
				more = false;
			} else
			if (sub_choice == 'A' || sub_choice == 'a' || sub_choice == '2')			// find by Address, works same as Name function
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Plesae enter Address to search: ";
				string search_value;
				getline(cin, search_value);

				card.print_header();
				
				for (size_t index = 0; index < rolodex_entries.size(); index++)
				{
					long found = rolodex_entries[index].find_byAddress(search_value);
					if (found == 1)
					{
						rolodex_entries[index].print_entries(index);
						cout << '\n';
					}
				}
				
				more = false;
			} else
			if (sub_choice == 'P' || sub_choice == 'p' || sub_choice == '3')			// find by Phone Number, works same
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Plesae enter Phone Number to search: ";
				unsigned int search_value;
				cin >> search_value;
				
				card.print_header();
				
				for (size_t index = 0; index < rolodex_entries.size(); index++)
				{
					long found = rolodex_entries[index].find_byNumber(search_value);
					if (found == 1)
					{
						rolodex_entries[index].print_entries(index);
						cout << '\n';
					}
				}
		
				more = false;
			} else
			if (sub_choice == 'E' || sub_choice == 'e' || sub_choice == '4')			// find by Email option, works same as other find
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Plesae enter Email address to search: ";
				string search_value;
				getline(cin, search_value);

				card.print_header();
				
				for (size_t index = 0; index < rolodex_entries.size(); index++)
				{
					long found = rolodex_entries[index].find_byEmail(search_value);
					if (found == 1)
					{
						rolodex_entries[index].print_entries(index);
						cout << '\n';
					}
				}

				more = false;
			} else
			if (sub_choice == 'R' || sub_choice == 'r' || sub_choice == '5')				// Gives user an option to return to main menu
			{
				more = true;										// Return True to continue original while loop
			} else 												// Else accounts for all other invalid options
			     {
				cout << "\nInvalid choice...\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\nWould you like to return to main menu? (Y/y): ";
				char ans;
				cin >> ans;
		
				if(ans != 'Y' && ans != 'y')
				{
					cout << "\nThank your for using DigiRolodex!! See you next time...\n\n";
					return 0;
				} else  more = true;
			     }
		} else

		if (choice == 'p' || choice == 'P' || choice == '5')					// To print all existing entries
		{	
			if (rolodex_entries.size() == 0)
			{
				cout << "\nNo entries to display yet...\n\n";
				more = false;
			} else
			     {
				card.print_header();
			
				for (size_t index = 0; index < rolodex_entries.size(); index++)
				{	
					rolodex_entries[index].print_entries(index);
					cout << '\n';
				}
				cout << '\n';
				more = false;
			     }
		} else
	
		if (choice == 'q' || choice == 'Q' || choice == '6')					// To quit program as requested by user
		{
			cout << "\nThank your for using DigiRolodex!! See you next time...\n\n";
			return 0;	
		} else 	{										// Else for invalid options entered by user
				cout << "\nNot a valid option... Please try again...\n";
				more = true;
			}
	}
	return 0;
}

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
	cout << setw(max_numCol) << left << "No." << print_divider << setw(max_fname) << left << "FIRST NAME" << print_divider << setw(max_lname) 
	     << left << "LAST NAME" << print_divider << setw(max_phone + 5) << left << "PHONE NUMBER" << print_divider << setw(max_email) 
	     << left << "EMAIL" << print_divider << left << "ADDRESS \n";
	cout << setfill (setfill_head) << setw(max_numCol) << "" << print_divider << setw(max_fname) << "" << print_divider << setw(max_lname) << "" 
	     << print_divider << setw(max_phone + 5) << "" << print_divider << setw(max_email) << "" << print_divider << setw(60) << "";
	cout << '\n';
}

void Rolodex::print_entries(size_t index) const					// Prints out object elements, position is shown by index + 1 to avoid 0 pos
{
	cout << setfill(setfill_data);
	cout << setw(max_numCol) << left << index + 1 << print_divider << setw(max_fname) << left << r_fname << print_divider << setw(max_lname) << left 
	     << r_lname << print_divider << setw(max_phone + 5) << left << r_phone_num << print_divider << setw(max_email) << left << r_email << print_divider 
	     << left << r_street << print_addDivdr << r_city << print_addDivdr << r_state << print_addDivdr << r_zip;
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





