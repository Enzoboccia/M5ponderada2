# M5ponderada2

# Hash Table Implementation in C++

Este repositório contém uma implementação simples de uma Hash Table em C++. A Hash Table suporta inserção, busca e remoção de elementos com base em chaves de string.

## Como funciona

A Hash Table utiliza uma função de hash para mapear chaves de strings a índices de um vetor. Cada índice do vetor aponta para uma lista ligada que armazena pares de chave-valor para lidar com colisões de hash.

### Métodos Implementados

- `insert(key, value)`: Insere um par chave-valor na Hash Table. Se a chave já existe, o valor é atualizado.
- `search(key)`: Busca e retorna o valor associado a uma chave. Se a chave não existe, retorna uma string vazia.
- `remove(key)`: Remove um par chave-valor baseado na chave fornecida. Retorna verdadeiro se a chave foi encontrada e removida, falso caso contrário.

## Como usar

O arquivo `main.cpp` demonstra o uso básico da Hash Table, incluindo inserção, busca e remoção de elementos. Compile o código com seu compilador C++ favorito e execute o programa para ver os resultados.

### Casos de Teste

#### Caso de Teste 1: Inserção de Item
- **Pré-condição**: Tabela hash inicialmente vazia.
- **Etapas do Teste**: Inserir um item com chave "BIC100" e valor "Caneta Azul".
- **Pós-condição**: A tabela hash deve conter o item.

#### Caso de Teste 2: Busca de Item Existente
- **Pré-condição**: Tabela hash contém o item com chave "BIC100" e valor "Caneta Azul".
- **Etapas do Teste**: Buscar o item com chave "BIC100".
- **Pós-condição**: O valor retornado deve ser "Caneta Azul".

#### Caso de Teste 3: Remoção de Item
- **Pré-condição**: Tabela hash contém o item com chave "BIC100" e valor "Caneta Azul".
- **Etapas do Teste**: Remover o item com chave "BIC100".
- **Pós-condição**: A tabela hash não deve conter o item.


