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

## Casos de Teste

Descreva seus casos de teste aqui, incluindo pré-condições, etapas do teste e pós-condições para inserção, busca e remoção.

