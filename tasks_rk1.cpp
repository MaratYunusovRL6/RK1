#include "tasks_rk1.h"
//1
void WorkWithFile:: readFromFile (const char* filename) {
    FILE *res = fopen(filename, "r");
    if(res) {
        while (fgets(dataOfFile, 2000, res) != NULL){
        }
    }
    fclose(res);
}
void WorkWithFile::prepareTestFile(const char* filename) {
    FILE *res = fopen(filename, "w");
    fprintf(res, "%s","asaadsaddsfsdfdfdffdfdfdfdf" );
    fclose(res);
}
WorkWithFile::WorkWithFile(const char* filename){
    prepareTestFile(filename);
    readFromFile (filename);
}
WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}
void WorkWithFile::writeStatInfoToFile(const char* outFile){
    FILE *res = fopen(outFile, "w");
    int count[100];
    for (int i = 0; i<91; i++){
        count[i] = 0;
    }
    for(int i = 0; i < strlen(dataOfFile); i++) {
        count[int(dataOfFile[i])-33]++;
    }
    for(int i = 0; i < 91;i++){
        if (count[i]!=0)
            fprintf(res, "%c\t%i\n", char(i+33), count[i]);
    }
    fclose(res);
}
//2
char* convertDecToBin(int number) {
    char* binary = new char[33];
    int i = 0;
    while (number > 0) {
        binary[i++] = number % 2 + '0';
        number /= 2;
    }
    binary[i] = '\0';
    int len = strlen(binary);
    for (int j = 0; j < len / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[len - j - 1];
        binary[len - j - 1] = temp;
    }
    return binary;
}
void writeToFile(const char* fileName, const char* strNum) {
    std::ofstream file;
    file.open(fileName);
    file << strNum << std::endl;
    file.close();
}
//3
char* convertBinToHex(const char* binNum){
    int number = 0;
    if((int)(strlen(binNum))%4 != 0)
        number = 4 - (int)(strlen(binNum))%4;
    char* numP = new char[number + strlen(binNum) + 1];
    std::map<std::string , char> m {{"0000", '0'}, {"0001", '1'},
                                    {"0010", '2'},{"0011", '3'},
                                    {"0100", '4'}, {"0101", '5'},
                                    {"0110", '6'}, {"0111", '7'},
                                    {"1000", '8'},{"1001", '9'},
                                    {"1010", 'A'}, {"1011", 'B'},
                                    {"1100", 'C'}, {"1101", 'D'},
                                    {"1110", 'E'},{"1111", 'F'}};
    for (int i = 0; i < number; ++i) {
        numP[i] = '0';
    }
    for (int i = number; i < number + strlen(binNum) + 1; ++i) {
        numP[i] = binNum[i - number];
        numP[i + 1] = '\0';
    }
    char* hexNum = new char[8];
    int Index = 0;
    int i = 0;
    while(i< strlen(numP)){
        char *tmp = new char[5];
        for (int j = 0; j < 4; ++j) {
            tmp[j] = numP[i++];
            tmp[j + 1] = '\0';
        }
        hexNum[Index++] = m.find(tmp)->second;
        delete[] tmp;
    }
    hexNum[Index] = '\0';
    delete[] numP;
    return hexNum;
}

//4
void buildTree(int a){
    std::cout<<std::endl;
    int e=-1;
    for (a+1;a>0;a--)
        std::cout<<std::string(a-1,' ')<<std::string(e=e+2,'*')<<std::string(a-1,' ')<<std::endl;
}
//5
std::vector<std::pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount) {
    std::vector<std::pair<int, float>> result;
    for (int i = 0; i < rowCount; i++) {
        float sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += ar[i * colCount + j];
        }
        float aver = sum / colCount;
        result.push_back(std::make_pair(i, aver));
    }
    return result;
}
void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        ar[i] = rand() % 100;
    }
}
//6
LinkedList::LinkedList() {
    Head = nullptr;
    Tail = nullptr;
}
LinkedList::~LinkedList() {
    while(Head != nullptr) {
        Node *k = Head;
        Head = Head->next;
        delete k;
    }
}

void LinkedList::push_back(int nameNode) {
    Node* New = new Node;
    if (Head == nullptr){
        New->nameNode = nameNode +1;
        New->next = nullptr;
        New->prev = nullptr;
        Head = Tail = New;
    }
    else{
        New->nameNode = nameNode +1;
        Tail->next = New;
        New->prev = Tail;
        New->next = nullptr;
        Tail = New;
    }
    Node::countNodes++;
}

void LinkedList::writeToFileFromTail() {
    FILE* res = fopen("task6_Tail.txt", "w");
    Node* Cursor = Tail;
    //fprintf(res, "%i\n", Cursor);//если что удалить
    while (Cursor != nullptr) {
        fprintf(res, "%i\n", Cursor->nameNode);
        Cursor = Cursor->prev;
    }
    fclose(res);
}
void LinkedList::writeToFileFromHead() {
    FILE* res = fopen("task6_Head.txt", "w");
    Node* Cursor = Head;
    //fprintf(res, "%i\n", Cursor);
    while (Cursor != nullptr) {
        fprintf(res, "%i\n", Cursor->nameNode);
        Cursor = Cursor->next;
    }
    fclose(res);
}
void LinkedList::insert(int nameNode, int position) {
    Node* New = new Node;
    New->nameNode = nameNode;
    if(position == 0){
        Head->prev = New;
        New->next = Head;
        New->prev = nullptr;
        Head = New;
    }
    if(position > 0 && position <= Node::countNodes){
        Node* c = Head;
        for (int i = 0; i < position-1; i++){
            c = c->next;
        }
        New->next = c->next;
        New->prev = c;
        c->next = New;
        if(position == Node::countNodes){
            Tail=New;
        }
        else{
            New->next->prev = New;
        }
    }
    Node::countNodes++;
}
