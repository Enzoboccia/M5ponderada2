#include <iostream>
#include <list>
#include <vector>
#include <string>

#define TABLE_SIZE 10  // Ajuste conforme necessário para seus testes

class HashTable {
private:
    std::vector<std::list<std::pair<std::string, std::string>>> table;

    int hash(std::string key) {
        // Implementação simples da função hash
        int hashValue = 0;
        for (char c : key) {
            hashValue += c;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(std::string key, std::string value) {
        int index = hash(key);
        auto& pairs = table[index];
        for (auto& pair : pairs) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        pairs.emplace_back(key, value);
    }

    std::string search(std::string key) {
        int index = hash(key);
        auto& pairs = table[index];
        for (auto& pair : pairs) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "";  // Retorna uma string vazia se a chave não for encontrada
    }

    bool remove(std::string key) {
        int index = hash(key);
        auto& pairs = table[index];
        for (auto it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->first == key) {
                pairs.erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    HashTable ht;

    // Caso de Teste 1: Inserção de Item
    ht.insert("BIC100", "Caneta Azul");
    std::string value = ht.search("BIC100");
    std::cout << (value == "Caneta Azul" ? "Caso de Teste 1 passou" : "Caso de Teste 1 falhou") << std::endl;

    // Caso de Teste 2: Busca de Item Existente
    value = ht.search("BIC100");
    std::cout << (value == "Caneta Azul" ? "Caso de Teste 2 passou" : "Caso de Teste 2 falhou") << std::endl;

    // Caso de Teste 3: Remoção de Item
    ht.remove("BIC100");
    value = ht.search("BIC100");
    std::cout << (value.empty() ? "Caso de Teste 3 passou" : "Caso de Teste 3 falhou") << std::endl;

    // Caso de Teste 4: Atualização de Item Existente
    ht.insert("BIC200", "Caneta Vermelha");
    ht.insert("BIC200", "Caneta Preta");
    value = ht.search("BIC200");
    std::cout << (value == "Caneta Preta" ? "Caso de Teste 4 passou" : "Caso de Teste 4 falhou") << std::endl;

    // Caso de Teste 5: Tratamento de Colisões
    ht.insert("ABC123", "Item 1"); // Suponha que "ABC123" e "XYZ789" resultem no mesmo valor de hash
    ht.insert("XYZ789", "Item 2");
    bool colisaoPassou = true;
    value = ht.search("ABC123");
    if (value != "Item 1") {
        colisaoPassou = false;
        std::cout << "Caso de Teste 5 falhou: Primeiro item da colisão não foi encontrado corretamente." << std::endl;
    }
    value = ht.search("XYZ789");
    if (value != "Item 2") {
        colisaoPassou = false;
        std::cout << "Caso de Teste 5 falhou: Segundo item da colisão não foi encontrado corretamente." << std::endl;
    }
    if (colisaoPassou) {
        std::cout << "Caso de Teste 5 passou: Tratamento de colisões funcionando corretamente." << std::endl;
    }

    return 0;
}
