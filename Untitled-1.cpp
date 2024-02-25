#include <iostream>
#include <list>
#include <vector>
#include <string>

#define TABLE_SIZE 10  // Você pode ajustar o tamanho conforme necessário

class HashTable {
private:
    std::vector<std::list<std::pair<std::string, std::string>>> table;

    int hash(std::string key) {
        // Implementação simples de função hash
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(std::string key, std::string value) {
        int index = hash(key);
        auto& list = table[index];
        for (auto& pair : list) {
            // Se a chave já existe, atualize o valor
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // Caso contrário, insira um novo par chave-valor
        list.emplace_back(key, value);
    }

    std::string search(std::string key) {
        int index = hash(key);
        auto& list = table[index];
        for (auto& pair : list) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "";  // Retorne uma string vazia se a chave não for encontrada
    }

    bool remove(std::string key) {
        int index = hash(key);
        auto& list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                list.erase(it);
                return true;  // Retorne verdadeiro se a chave for removida
            }
        }
        return false;  // Retorne falso se a chave não for encontrada
    }
};

int main() {
    HashTable ht;

    // Exemplo de inserção
    ht.insert("BIC100", "Caneta Azul");
    ht.insert("BIC200", "Caneta Vermelha");

    // Exemplo de busca
    std::string value = ht.search("BIC100");
    if (!value.empty()) {
        std::cout << "Valor encontrado: " << value << std::endl;
    } else {
        std::cout << "Valor não encontrado." << std::endl;
    }

    // Exemplo de remoção
    bool removed = ht.remove("BIC100");
    if (removed) {
        std::cout << "Chave removida com sucesso." << std::endl;
    } else {
        std::cout << "Chave não encontrada para remoção." << std::endl;
    }

    return 0;
}
