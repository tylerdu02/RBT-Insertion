/*
* Tyler Du
* 4/30/23
* Red Black Tree Insertion
* https://www.programiz.com/dsa/red-black-tree
* https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
* Links used for reference to help
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstring>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    bool isRed;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
        isRed = true;
    }
};

void insert(Node* &root, Node* current);
void RBTInsert(Node* current, Node* &root);
void print(Node* root, int numTabs);
void rotateLeft(Node* current, Node* &root);
void rotateRight(Node* current, Node* &root);
void search(Node* root, int value);
Node* getParent(Node* current);
Node* getGrandparent(Node* current);
Node* getSibling(Node* current);
Node* getUncle(Node* current);
bool color(Node* current);

int main() {
    char input[10];
    bool running = true;
    Node* root = NULL;

    while (running == true) {
        cout << "Add, print, file, or search?" << endl;

        cin.get(input, 10);
        cin.ignore(1, '\n');

        if (input[0] == 'A' || input[0] == 'a') { // input
            int num;
            cout << "Input a number 1-999" << endl;
            cin >> num;
            cin.ignore(1, '\n');
            if (num >= 1 && num <= 999) { // checks if input is valid
                Node* current = new Node(num);
                insert(root, current);
                RBTInsert(current, root);
            }
            else { 
                cout << "Invalid input" << endl;
            }
        }
        else if (input[0] == 'P' || input[0] == 'p') { // prints 
            print(root, 0);
            cout << endl;
        }
        else if (input[0] == 'S' || input[0] == 's') { // searches
            int searchNum;
            cout << "What number would you like to search?" << endl;
            cin >> searchNum;
            cin.ignore(1, '\n');
            search(root, searchNum);
        }
        else if (input[0] == 'F' || input[0] == 'f') { // generates numbers from numbers.txt
            cout << "Numbers from tree have been generated into tree" << endl;
            ifstream numbers;
            numbers.open("numbers.txt");
            int numnums;
            while (numbers >> numnums) { 
                Node* current = new Node(numnums);
                insert(root, current);
                RBTInsert(current, root);
            }
            numbers.close();
        }
         else {
            cout << "Number not found" << endl;
        }
    }
}