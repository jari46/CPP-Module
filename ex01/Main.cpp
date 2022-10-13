#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
  PhoneBook phonebook0;
  std::string input;

  while (true) {
	  phonebook0.read_input(input);
    switch (phonebook0.get_type(input)) {
      case CMD_ADD:
        phonebook0.add_contact();
        break;
      case CMD_SEARCH:
        phonebook0.search_contact();
        break;
      case CMD_EXIT:
        std::cout << "Bye~!" << std::endl;
        return 0;
      default:
        std::cout << "Wrong command..." << std::endl;
        continue;
    }
  }
  return 0; 
}
