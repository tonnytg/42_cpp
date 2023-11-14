#include <iostream>
#include <string>
#include <vector>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	// Método para configurar os detalhes do contato
	void setDetails(const std::string& fname, const std::string& lname, const std::string& nname,
					const std::string& phone, const std::string& secret) {
		first_name = fname;
		last_name = lname;
		nickname = nname;
		phone_number = phone;
		darkest_secret = secret;
	}

	// Método para imprimir os detalhes do contato
	void printDetails() const {
		std::cout << "First Name: " << first_name << '\n';
		std::cout << "Last Name: " << last_name << '\n';
		std::cout << "Nickname: " << nickname << '\n';
		std::cout << "Phone Number: " << phone_number << '\n';
		std::cout << "Darkest Secret: " << darkest_secret << '\n';
	}
};

int main() {
	// Criação de um vetor para armazenar os contatos
	std::vector<Contact> phonebook;
	phonebook.reserve(8); // Supondo que você pode ter até 8 contatos

	// Adicionando um novo contato
	Contact newContact;
	newContact.setDetails("John", "Doe", "Johnny", "123-456-7890", "Afraid of clowns");
	phonebook.push_back(newContact);

	// Exibindo os detalhes de todos os contatos
	for (const auto& contact : phonebook) {
		contact.printDetails();
		std::cout << "------------------\n";
	}

	// Implementação de um loop para interagir com o usuário e adicionar/buscar/sair seria o próximo passo.

	return 0;
}
