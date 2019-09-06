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

int main(int argc, char *argv[]) {
    
    ArgumentManager am(argc,argv);
    const string in = am.get("input");
    const string out = am.get("output");
    const string cmd = am.get("command");

    // THIS IS TO TEST LOCALLY/////////////////////////////////
    //cout << "Input Filename: ";
    //cin >> fileName;
    //ifstream file;
    //file.open(fileName);
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    ifstream infile;
    infile.open(in);
    list list1;
    string value; //data for Node

    //THIS GRABS THE FIRST NAME OF VERY PERSON - IDK IF WE NEED THE LAST NAME TOO FOR THOSE THAT HAVE IT
    //IF SO, ADAPT SO THAT IT INCLUDES LAST NAME
    while(getline(infile,value)){
        int stringshort = value.find(",");
        value = value.substr(0,stringshort);
        list1.createNode(value);
    }
    list1.bsortlist();
    //list1.display();
    infile.close();
    
    //string comdname = "";
    //cout << "Comand file name:";
    //cin >> comdname;
    ifstream cfile;
    ofstream outfile;
    cfile.open(cmd);
    outfile.open(out);

    string player = "";
    while(getline(cfile,player)){
        if(player.substr(player.length()-1,player.length()) == "\r"){ // getline keeps the heckin carrige return so we gotta trim that
            player = player.substr(0,player.length()-1);
        }
        outfile << "index of " << player << ": " << list1.indexof(player) << endl;
    }
    cfile.close();
    outfile.close();

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
    while(place < size-1 && curname != name){
        //cout << place << "not " << "~" << curname << "~" << endl;
        place++;
        cur = cur->next;
        curname = cur->name;
    }
    if (curname == name){ 
        return place;
    }else{ // this catches if name is not in list
        return -1;
    }
}
