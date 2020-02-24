#include "rolodex_interface.h"

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;


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

