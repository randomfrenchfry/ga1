#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <string>

using namespace std;

struct Node{
    string name;
    int index;
    Node* next;
};

int main(int argc, char *argv[]) {
    ArgumentManager am(argc,argv);
    const string in = am.get("input");
    const string out = am.get("output");

    return 0;
}