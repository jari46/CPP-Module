#include <iostream> //string, cin, cout
#include <string> //find_last_not_of, getline, empty, length
#include <iomanip> //setw
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
  : cmd_add("ADD"), cmd_search("SEARCH"), cmd_exit("EXIT"), first_empty_contact(0), filled_contact(0) {}

int PhoneBook::get_type(std::string &input) const {
	if (input == cmd_add)
		return (CMD_ADD);
	else if (input == cmd_search)
		return (CMD_SEARCH);
	else if (input == cmd_exit) 
		return (CMD_EXIT);
	else
		return (CMD_WRONG);
}

void PhoneBook::read_input(std::string &input) {

	std::cout << "\nWhat do you want to do? (ADD or SEARCH or EXIT): ";
	std::getline(std::cin, input);
	if (std::cin.fail()) { std::exit(EXIT_FAILURE);}
}

/********  add_contact()  ********/

void PhoneBook::add_contact(void) {
	Contact &working_contact = contacts[first_empty_contact];
  
  std::string input;

  std::cout << "** First Name: ";
	std::getline(std::cin, input);
	if (std::cin.fail()) { std::exit(EXIT_FAILURE);}
  if (input.find_last_not_of(" ") == input.npos) {
    std::cout << "No empty field is allowed..." << std::endl;
    return ;
  }
  working_contact.set_first_name(input);

  std::cout << "** Last Name: ";
	std::getline(std::cin, input);
	if (std::cin.fail()) {std::exit(EXIT_FAILURE);}
  if (input.find_last_not_of(" ") == input.npos) {
    std::cout << "No empty field is allowed..." << std::endl;
    return ;
  }
  working_contact.set_last_name(input);

  std::cout << "** Nickname: ";
	std::getline(std::cin, input);
	if (std::cin.fail()) {std::exit(EXIT_FAILURE);}
  if (input.find_last_not_of(" ") == input.npos) {
    std::cout << "No empty field is allowed..." << std::endl;
    return ;
  }
  working_contact.set_nickname(input);

  std::cout << "** Phone Number: ";
	std::getline(std::cin, input);
	if (std::cin.fail()) {std::exit(EXIT_FAILURE);}
  if (input.find_last_not_of(" ") == input.npos) {
    std::cout << "No empty field is allowed..." << std::endl;
    return ;
  }
  working_contact.set_phone_number(input);

  std::cout << "** darkest secret: ";
	std::getline(std::cin, input);
	if (std::cin.fail()) {std::exit(EXIT_FAILURE);}
  if (input.find_last_not_of(" ") == input.npos) {
    std::cout << "No empty field is allowed..." << std::endl;
    return ;
  }
  working_contact.set_darkest_secret(input);

  std::cout << "done!" << std::endl;

	if (first_empty_contact == PHONEBOOK_SIZE - 1)
    first_empty_contact = 0;
  else
    first_empty_contact++;

  if (filled_contact < PHONEBOOK_SIZE)
    filled_contact++;
}

/********  search_contact()  ********/

// if the index is out of range : "Wrong index"
// or wrong: undefined behavior(display the first index)

void PhoneBook::search_contact(void) {
  std::string input_s;
	
  if (filled_contact <= 0)
    std::cout << "add first..." << std::endl;
  else {
    display_contact_list();
    
    std::cout << "Which index you want to search?: ";
    std::getline(std::cin, input_s);
    if (std::cin.fail()) { std::exit(EXIT_FAILURE);}
    std::cout << std::endl;
    
    int input_i = std::atoi(input_s.c_str());
    if (0 <= input_i && input_i <= 7)
      display_contact(input_i);
    else
      std::cout << "Wrong index..." << std::endl;
  }
}

static std::string get_content_truncated(std::string str) {
  std::string str_truncated = str;

  std::cout << std::setw(PADDING_SIZE);
  if (PADDING_SIZE < str_truncated.length()) {
    str_truncated.resize(10);
    str_truncated.replace(9, 1, ".");
  }
  return str_truncated;
}

void PhoneBook::display_contact_list(void) {
  std::cout << "n" << " | " \
  << get_content_truncated("First Name") << " | " \
  << get_content_truncated("Last Name") << " | " \
  << get_content_truncated("Nickname") << std::endl;

  for (int i = 0; i < filled_contact; i++) {
    Contact working_contact = contacts[i];
    std::cout << i << " | " \
    << get_content_truncated(working_contact.get_first_name()) << " | " \
    << get_content_truncated(working_contact.get_last_name()) << " | " \
    << get_content_truncated(working_contact.get_nickname()) << std::endl;
  }
}

void PhoneBook::display_contact(int index) {
  if (filled_contact <= index)
    std::cout << "No content yet..." << std::endl;
  else {
    for (int i = 0; i < filled_contact; i++) {
      if (i == index) {
        Contact working_contact = contacts[i];
        std::cout << "First Name: " << working_contact.get_first_name() << std::endl;
        std::cout << "Last Name: " << working_contact.get_last_name() << std::endl;
        std::cout << "Nickname: " << working_contact.get_nickname() << std::endl;
        std::cout << "Phone Number: " << working_contact.get_phone_number() << std::endl;
        std::cout << "Darkest Secret: " << working_contact.get_darkest_secret() << std::endl;
      }
    }
  }
}
