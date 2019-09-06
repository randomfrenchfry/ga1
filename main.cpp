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
    int size;
    Node*head;
    Node*tail;
public:
    list();
    void createNode(string value);
    void display();
    void bsortlist();
    int indexof(string name);
};

int main() {
    //Commented so I can do local testing
    //ADD TO MAIN PARAMETERS: int argc, char *argv[]
    //ArgumentManager am(argc,argv);
    //const string in = am.get("input");
    //const string out = am.get("output");
    string fileName;

    // THIS IS TO TEST LOCALLY/////////////////////////////////
    cin >> fileName;
    ifstream file;
    file.open(fileName);
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    list list1;
    string value; //data for Node

    //THIS GRABS THE FIRST NAME OF VERY PERSON - IDK IF WE NEED THE LAST NAME TOO FOR THOSE THAT HAVE IT
    //IF SO, ADAPT SO THAT IT INCLUDES LAST NAME
    while(getline(file,value)){
        int stringshort = value.find(",");
        value = value.substr(0,stringshort);
        list1.createNode(value);
    }
    list1.bsortlist();
    list1.display();
    file.close();
    return 0;
}
list::list(){
    size = 0;
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
    size += 1;
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
    string temp;
//BUBBLE SORT
    for(int i=0;i<size;i++) {
        Node*ptr = head; //Reset the pointer to head every time so it can run through it again
        while (ptr->next != NULL) {
            if (ptr->name.compare(ptr->next->name) > 0) {
                //if(ptr->name > ptr->next->name){
                temp = ptr->next->name;
                ptr->next->name = ptr->name;
                ptr->name = temp;
            }
            ptr = ptr->next; // move ptr
        }
    }
}
int list::indexof(string name){
    Node* cur = head; //start at head and look down
    string curname = cur->name;
    int place = 0;
    while(place < size && curname != name){
        place++;
        cur = cur->next;
        curname = cur->name;
    }
    if (place == size){
        return -1;
    }else{
        return place;
    }
}
