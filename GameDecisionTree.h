#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    /*
     *  already finished because when a game Decision Tree is created
     *  its default root is pointing to a nullptr
     */
    std::string description;
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter)
    {
        //opens the file with given fileName
        std::ifstream file(filename);

        //var that holds a full line from the file
        std::string line;

        //goes through the file, reading line by line
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            int num, leftNum, rightNum;

            //breaks "description" down using the delimiter
            std::getline(ss, description, delimiter);
            ss >> num >> leftNum >> rightNum;
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame()
    {
        //if root is empty
        if (!root)
        {
            std::cout << "story is empty";
            return;
        }

        Node<T>* current = root;

        while (current != nullptr)
        {
            std::cout << current->data.description << "\n";

            //if both of the children are null (child node), end game
            if (current->left == nullptr && current->right == nullptr)
            {
                std::cout << current->data.description << "\n";
                break;
            }

            std::cout << "choose path:\n";
            if (current->left)
            {
                std::cout << "1. left\n";
                std::cout << "2. right\n";
            }

            int choice;
            std::cout << "enter # '1 | 2'";
            std::cin >> choice;

            if (std::cin.fail() || (choice != 1 && choice != 2))
            {
                std::cout << "invalid choice\n";
                continue;
            }

            if (choice == 1 && current->left)
            {
                current = current->left;
            }
            else if (choice == 2 && current->right)
            {
                current = current->right;
            }
            else
            {
                std::cout << "path doesn't exist. try again.\n";
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H