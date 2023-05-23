#include "tasks_rk1.h"

void task_1() {
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_sourceFile_task1.txt");
}

void task_2(){
    int number=-89;//входные данные для десятичного числа
    char* binary = convertDecToBin(number);
    writeToFile("result_task2.txt", binary);
    delete[] binary;
}

void task_3(){
    const char* binNum="11001";
    writeToFile("result_task3.txt", 0, convertBinToHex( binNum), binNum);
}
void task_4(){
    buildTree(8);//входные данные для размера дерева
}

void task_5(){
    int colCount = 5;//входные данные для количества колонок
    int rowCount = 14;//входные данные для количества строк
    float* ar = new float[colCount * rowCount];
    randFill(ar, colCount*rowCount);
    std::vector <std::pair<int, float>> result = averStr2DArray(ar, colCount, rowCount);
    std::fstream file("result_task5.txt", std::ios::out);
    if (file.is_open()) {
        for (auto pair : result) {
            file <<  pair.first << " : " << std::fixed << std::setprecision(2) << pair.second << std::endl;
        }
        file.close();
    } else {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
}

LinkedList a;
void task_6(){
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    a.writeToFileFromHead();
    a.writeToFileFromTail();
}
void task_7(){
    a.insert(1,5);
};



int main() {
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6();
    task_7();
    return 0;
}
