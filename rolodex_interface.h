#ifndef MY_ROLODEX_LIBRARY_H_INC
#define MY_ROLODEX_LIBRARY_H_INC

#include <string>
#include <vector>


const size_t max_fname = 20;
const size_t max_lname = 20;
const size_t max_street = 40;
const size_t max_city = 30;
const size_t max_state = 2;
const size_t max_email = 40;
const size_t max_zip = 5;
const size_t max_phone = 10;
const size_t max_numCol = 4;				//for entry number print out


class Rolodex
{
public:
	Rolodex(): r_fname(), r_lname(), r_street(), r_city(), r_state(), r_zip(0), r_email(), r_phone_num(0) {}
	
	void read_entry();
	void add_list(Rolodex & object, std::vector<Rolodex> & list);			
	void remove_entry(std::vector<Rolodex> & list, size_t delt_index);
	void edit_entry(std::vector<Rolodex> & list, size_t edit_index);
		
	unsigned int num_size(unsigned int number) const;
	
	char initial_menu() const;
	char submenu() const;
	void print_header() const;
	void print_entries(size_t index) const;
	long find_byName(std::string searchfor) const;
	long find_byAddress(std::string searchfor) const;
	long find_byEmail(std::string searchfor) const;
	long find_byNumber(unsigned int searchfor) const;

private:
	std::string r_fname;
	std::string r_lname;
	std::string r_street;
	std::string r_city;
	std::string r_state;
	unsigned int r_zip;
	std::string r_email;
	unsigned int r_phone_num;
};


#endif

