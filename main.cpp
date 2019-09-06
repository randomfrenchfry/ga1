#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <string>

using namespace std;

struct Node{
    string name;
    Node* next;
};
class list{
private:
    Node*head;
    Node*tail;
public:
    list();
    void createNode(string value);
    void display();
    void bsortlist();
};

int main() {
    //Commented so I can do local testing
    //ADD TO MAIN PARAMETERS: int argc, char *argv[]
    //ArgumentManager am(argc,argv);
    //const string in = am.get("input");
    //const string out = am.get("output");
    string fileName;
    cin >> fileName;
    ifstream file;
    file.open(fileName);

    list list1;
    string value; //data for Node

    //THIS GRABS THE FIRST NAME OF VERY PERSON - IDK IF WE NEED THE LAST NAME TOO FOR THOSE THAT HAVE IT
    //IF SO, ADAPT SO THAT IT INCLUDES LAST NAME
    int count = 0;
    while(getline(file,value)){
        int stringshort = value.find(",");
        value = value.substr(0,stringshort);
        count +=1;
        list1.createNode(value);
    }
    list1.bsortlist();
    list1.display();
    file.close();
    return 0;
}
list::list(){
    head = NULL;
    tail = NULL;
}
void list::createNode(string value) {
    Node*p = new Node;
    p->name = value;
    p->next = NULL;
    if(head == NULL){
        head = p;
        tail = p;
        p = NULL;
    } else{
        tail->next = p;
        tail = p;
    }
}
void list::display() {
    Node*cu = new Node;
    cu = head;
    while(cu!=NULL){
        cout << "NODE DATA " << cu->name << endl;
        cu = cu->next;
    }
}
void list::bsortlist() {
    //FIX BSORT SO THAT IT SWAPS THE VALUES CORRECTLY
    Node*ptr = head;
    string temp;

    while(ptr->next != 0){
        if(ptr->name > ptr->next->name){
            temp = ptr->next->name;
            ptr->next->name = ptr->name;
            ptr->name = temp;
        }
        ptr = ptr->next;
    }
}