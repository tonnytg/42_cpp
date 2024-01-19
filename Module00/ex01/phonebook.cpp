#include "phonebook.hpp"
#include <iostream>

Phonebook::Phonebook() {}

bool Phonebook::AddContact(const std::string& name, const std::string& phone) {
    // Encontre uma posição vazia no array para adicionar o contato
    for (int i = 0; i < 8; i++) {
        if (_contacts[i].GetName() == "") {
            _contacts[i].SetName(name);
            _contacts[i].SetPhone(phone);
            return true; // Contato adicionado com sucesso
        }
    }
    return false; // Não há espaço para adicionar mais contatos
}

bool Phonebook::RemoveContact(const std::string& name) {
    // Encontre e remova um contato pelo nome
    for (int i = 0; i < 8; i++) {
        if (_contacts[i].GetName() == name) {
            _contacts[i] = Contact(); // Limpar o contato
            return true; // Contato removido com sucesso
        }
    }
    return false; // Contato não encontrado
}

void Phonebook::DisplayContacts() const {
    std::cout << "Contatos na agenda:" << std::endl;
    for (int i = 0; i < 8; i++) {
        if (_contacts[i].GetName() != "") {
            std::cout << "Nome: " << _contacts[i].GetName() << ", Telefone: " << _contacts[i].GetPhone() << std::endl;
        }
    }
}
