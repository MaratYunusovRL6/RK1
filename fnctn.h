//
// Created by Admin on 27.03.2023.
//

#ifndef RK1_FNCTN_H
#define RK1_FNCTN_H
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <list>
#include <bits/stdc++.h>
#include <string>
#include <ctime>
char* NewChar(const char* s);

class WorkWithFile {
private :
    char* dataOfFile = new char[20000];

    void readFromFile(const char* fileName);

    void prepareTestFile(const char* fileName);

public :
    WorkWithFile(const char* fileName);

    ~WorkWithFile();

    void writeStatInfoToFile(const char* outFile);
};

char* convertDecToBin(int number);

void writeToFile(const char* fileName, const char* strNum);

void buildTree(int height);

char* convertBinToHex(const char* binNum);

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum);

std::vector<std::pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount);

void randFill(float* ar, int N);

struct Node  {
    Node* next;
    Node* prev;
    int nameNode;	//имя узла
    static int countNodes;
};
class LinkedList {
private :
    Node* Head;
    Node* Tail;
public :
    LinkedList();
    ~LinkedList();

    void push_back(int nameNode);
    void writeToFileFromTail();
    void writeToFileFromHead();
    void insert(int nameNode, int position);
};

#endif

