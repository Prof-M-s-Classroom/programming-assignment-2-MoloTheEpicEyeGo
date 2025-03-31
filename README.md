[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Your Name]`  
### **Student ID:** `[Your ID]`  

---

## **1. Project Overview**


> My project is a text-based RPG game using **binary decision trees**. Every game event is represented by a node and the player chooses their own path. The story can be created in the story.txt file. The end of the story is determined when the player has reached a node with both -1 as the left and right child.
---

## **2. Folder & File Structure**

- **`main.cpp`** → `calls the core functions all in one organized place. This is where we create the objects of classes (where you're stories are created)`  
- **`GameDecisionTree.h`** → `stores the core functions that the program will mainly use`  
- **`Node.h`** → `stores a basic node structure which will be used by other classes`  
- **`Story.h`** → `stores the parameter of a "story node" which would be used in other classes `  
- **`story.txt`** → `this is where you write and create your story`  

---

## **3. Decision Tree Construction**

- The story objects are created by first parsing the story.txt file line by line and we do this by using a loop that will parse a line into an event number, the description of event and the left and right number
- We loop through all the existing nodes and connect each one to its left and right child, we base this on the left and right event number 
- If a node has -1 as their right and left child, this indicates that this is the end of the story, also meaning that the node is a leaf node. 

---

## **4. Game Traversal**

- The game moves through the decision tree using user input to follow different story paths. The tree is made up of nodes, each containing a Story object
- When the player reaches a leaf node, it will end the game because a leaf node indiciates that its the end of the story. 
- If there is multiple parent nodes leading to the same event, the easy solution to this is to make the parent nodes point to the 

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- The file is read by first declaring four temp vars (eventStr, desc, leftStr and rightStr), then we use "std::getline(ss, varName, delimiter)" to section out the line of string into its respective vars. we use the delimiter to specifically section out the line of text.
- We ensure that the nodes are properly linked by storing the nodes in a nodeMap based on their event #.
- One challenge that I experienced was something related to how CLion's settings was. The settings were incorrectly pointing to the files therefore making every test not possible to open the text file.

---

## **6. Debugging Process (Errors & Fixes)**

> Initially, my program was not successfully opening the story.txt file. But after doing some research, I found that the error was becuase of the "Working Directory" settings. The project had no "wWorking Directory" therefore making it impossible to open the story.txt file.

---

## **7. Sample Output & Walkthrough**

root set to event #1

You wake up in a forest clearing. Two paths lie ahead: one leads into dense trees, the other toward an old building. Which way do you go?
Choose your path:
1.
2.
Enter # '1 | 2': 1

You take the forest path and arrive at a rushing river. Do you swim across or follow it downstream?
Choose your path:
1.
2.
Enter # '1 | 2': 2

You follow the river and find a broken bridge. Do you attempt to cross or head back into the woods?
Choose your path:
1.
2.
Enter # '1 | 2': 1

The story ends here. Thanks for playing!

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`   
- **Searching for an event in the tree** → `O(n)`  
- **Game traversal efficiency** → `O(n)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game. When both the left and right child pointers were nullptr, the program printed the final description once and then displayed “The story ends here. Thanks for playing!” before exiting.

---
