#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

#define PHONEBOOK_SIZE	8
#define PADDING_SIZE	10

#define CMD_WRONG 0
#define CMD_EXIT 1
#define CMD_ADD 2
#define CMD_SEARCH 3

// typedef enum Command {
//   CMD_WRONG, 
//   CMD_ADD, 
//   CMD_SEARCH, 
//   CMD_EXIT, 
// } Command;

class PhoneBook {
	private:
		const std::string cmd_add;
		const std::string cmd_search;
		const std::string cmd_exit;

		Contact contacts[PHONEBOOK_SIZE];
		size_t first_empty_contact;
		int filled_contact;

		void display_contact_list(void);
    void display_contact(int index);

	public:
    PhoneBook();
  
		int get_type(std::string &input) const;
		void read_input(std::string &input);

		void add_contact(void);
		void search_contact(void);
};

#endif // PHONE_BOOK_HPP
