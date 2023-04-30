#include "tasks_rk1.h"

void task_1() {
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_task1.txt");
}

void task_2(){
    int number=-89;//входные данные для десятичного числа
    char* binary = convertDecToBin(number);
    writeToFile("result_task2.txt", binary);
    delete[] binary;
}

void task_3(){
    writeToFile("result_task3.txt", convertBinToHex("100011010111"));//входные данные для ввода двоичного числа
}

void task_4(){
    buildTree(8);//входные данные для размера дерева
}

void task_5(){
    const int colCount = 5;//входные данные для количества колонок
    const int rowCount = 14;//входные данные для количества строк
    float ar[colCount * rowCount];
    randFill(ar, colCount * rowCount);
    std::vector <std::pair<int, float>> result = averStr2DArray(ar, colCount, rowCount);
    std::fstream file("result_task5.txt", std::ios::out);
    if (file.is_open()) {
        for (auto pair : result) {
            file << "строка " << pair.first << " : " << std::fixed << std::setprecision(2) << pair.second << std::endl;
        }
        file.close();
    } else {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
}

int Node::countNodes = 0;
void task_6_7(){
    LinkedList out;
    for(int i = 0; i < 15; i++){
        out.push_back(i);
    }
    out.writeToFileFromHead();
    out.insert(6, 3);
    out.writeToFileFromTail();
}

int main() {
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6_7();
    //task_7();
    return 0;
}
