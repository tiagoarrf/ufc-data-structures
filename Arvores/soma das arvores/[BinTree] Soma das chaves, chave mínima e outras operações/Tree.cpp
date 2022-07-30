// Tiago A. Fontenele
// Date: 13/03/2021
#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include "Tree.h"

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr)
    {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

Tree::Tree(std::string serial)
{
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

void Tree::_serializeTree(std::stringstream &ss, Node **node)
{
    std::string value;
    ss >> value;
    if (value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

Tree::~Tree()
{
    _clear(_root);
}

Node *Tree::_clear(Node *node)
{
    if (node != nullptr)
    { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder()
{
    _inorder(_root);
}

void Tree::_inorder(Node *node)
{
    if (node != nullptr)
    { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);
    }
}

void Tree::bshow()
{
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca)
{
    if (node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right, heranca + "r");
    for (int i = 0; i < (int)heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if (heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if (node == nullptr)
    {
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if (node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}

int Tree::sum_keys()
{ // TODO 1
    return _sum_keys(_root);
}

int Tree::_sum_keys(Node *node)
{ // TODO 1
    int sum = 0;
    if (node == nullptr)
    {
        return sum;
    }
    sum = node->key;
    sum += _sum_keys(node->left);
    sum += _sum_keys(node->right);
    return sum;
}

// Para fazer essa funcao, suponha que as arvores dos testes nunca serao vazias,
// assim, sempre havera um menor valor de chave a ser retornado
int Tree::min_key()
{ // TODO 1
    return _min_key(_root);
}

// Supoe que o ponteiro recebido sempre eh diferente de nullptr
int Tree::_min_key(Node *node)
{ // TODO 1
    if (node != nullptr)
    {
        int min_r = _min_key(node->right);
        int min_l = _min_key(node->left);
        if (min_l < node->key && min_l < min_r)
        {
            return min_l;
        }
        else if (min_r < node->key && min_r < min_l)
        {
            return min_r;
        }
        else if (node->key < min_r && node->key < min_l)
        {
            return node->key;
        }
        else
        {
            return node->key;
        }
    }
    return INT_MAX;
}

int Tree::total_internal_nodes()
{ // TODO 1
    return _total_internal_nodes(_root);
}

int Tree::_total_internal_nodes(Node *node)
{                // TODO 1
    int tni = 0; // total de nós internos
    if (node != nullptr)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            return tni;
        }
        else
        {
            tni = 1;
        }
        tni += _total_internal_nodes(node->left) + _total_internal_nodes(node->right);
        return tni;
    }
    return tni;
}

int Tree::um_filho()
{ // TODO 1
    return _um_filho(_root);
}

int Tree::_um_filho(Node *node)
{ // TODO 1
    if (node == nullptr)
    {
        return 0;
    }
    else{
        int cnt;
        if((node->left == nullptr) && (node->right == nullptr)){
            cnt = 0;
        }
        else if((node->left != nullptr) && (node->right == nullptr) || (node->left == nullptr) && (node->right != nullptr)){
            cnt = 1;
        }
        else{
            cnt = 0;
        }
        cnt += _um_filho(node->left);
        cnt += _um_filho(node->right);
        return cnt;
    }
}
