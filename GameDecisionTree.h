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
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter)
    {
        //opens the file based on the filename
        std::ifstream file(filename);

        //if it cannot open the file, error message will show
        if (!file.is_open()) {
            std::cout << "failed to open" << filename << std::endl;
            return;
        }

        //var that will hold a line of string/text from the story.txt file
        std::string line;

        //unordered tree that will be used to store nodes with story event #'s
        std::unordered_map<int, Node<T>*> nodeMap;

        //loops through the story.txt file and reads each line of text/string
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string eventStr, desc, leftStr, rightStr;

            //the story.txt file is written in this format, therefore the code is in this order.
            std::getline(ss, eventStr, delimiter);
            std::getline(ss, desc, delimiter);
            std::getline(ss, leftStr, delimiter);
            std::getline(ss, rightStr, delimiter);

            //checks for invalid text
            if (eventStr.empty() || leftStr.empty() || rightStr.empty()) {
                std::cout << "Skipping malformed line: " << line << "\n";
                continue;
            }

            //changes the string #'s to actual integer's
            int eventNumber = std::stoi(eventStr);
            int leftNumber = std::stoi(leftStr);
            int rightNumber = std::stoi(rightStr);

            //makes a story object that we will use for the story node
            T story(desc, eventNumber, leftNumber, rightNumber);

            //Node that stores a certain story event
            Node<T>* node = new Node<T>(story);

            //create a nodeMap so we can build the tree
            nodeMap[eventNumber] = node;
            // std::cout << "Parsed Event #" << eventNumber << " — \"" << desc
            //   << "\" | Left: " << leftNumber << " | Right: " << rightNumber << "\n";
        }

        //loop goes through the nodeMap and connects each node to its corresponding children.
        for (auto& pair : nodeMap)
        {
            Node<T>* node = pair.second;

            int left = node->data.leftEventNumber;
            int right = node->data.rightEventNumber;

            if (left != -1 && nodeMap.count(left)) {
                node->left = nodeMap[left];
            }

            if (right != -1 && nodeMap.count(right)) {
                node->right = nodeMap[right];
            }
        }

        //since we set the root node to "null" we set the root node to 1, 1 being the first event of the game
        if (nodeMap.count(1))
        {
            root = nodeMap[1];
            std::cout << "root set to event #1\n";
        }
        else
        {
            std::cout << "tree is not rooted!!!\n";
        }
    }


    // TODO: Function to start the game and traverse the tree based on user input
    void playGame()
    {
        //checks if the story even has a story
        if (!root)
        {
            std::cout << "story is empty";
            return;
        }

        Node<T>* current = root;

        //goes through the nodes until its nullptr
        while (current != nullptr)
        {
            //outputs the description of the specific node
            std::cout << current->data.description << "\n";

            //if both of the children are null (child node), end game
            if (current->left == nullptr && current->right == nullptr)
            {
                break;
            }

            std::cout << "choose path:\n";
            if (current->left)
            {
                std::cout << "1. \n";
                std::cout << "2. \n";
            }

            int choice;
            std::cout << "enter # '1 | 2'";
            std::cin >> choice;

            if (std::cin.fail() || (choice != 1 && choice != 2))
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "invalid input. Please enter 1 or 2.\n";
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