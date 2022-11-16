#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
class process {
private:
    string name;
    int processID;
    double memory;
public:
    string get_name(){return this->name; }
    int get_id(){return this->processID; }
    double get_memory(){return this->memory; }
    void set_name(string name){this->name = name; }
    void set_id(int id){this->processID = id; }
    void set_memory(double memory){this->memory = memory; }
    process(string name, int id, double memory) : name(name), processID(id), memory(memory){}
    process() = default;

};
class TaskManager{
private:
    vector<process>pl;
public:
    void Add(process pr){
        pl.push_back(pr);
    }
    void print(){
        cout <<"Image Name                     PID Session Name        Session#    Mem Usage\n"
               "========================= ======== ================ =========== ============" << endl;
        for(auto i : pl){
            cout << left << setw(30) << i.get_name();
            cout << right << setw(30) << i.get_id();
            cout << right << setw(30) << i.get_memory() << endl;
        }
    }
    void sort_name(){
        sort(pl.begin(), pl.end(),[](process p1, process p2){return p1.get_name() < p2.get_name();});

    }

    void sort_id(){
        sort(pl.begin(), pl.end(),[](process p1, process p2){return p1.get_id() < p2.get_id();});
    }

    void sort_mem(){
        sort(pl.begin(), pl.end(),[](process p1, process p2){return p1.get_memory() < p2.get_memory();});
    }



};
int main() {
    TaskManager task;
    string name, id, id2, mem, mem2, s;
    fstream file;
    file.open("file.txt", ios::in);
    file.ignore(256, '\n');
    file.ignore(256, '\n');
    while (!file.eof()) {
        getline(file, s);
        name = s.substr(0, 25);
        id = s.substr(26, 8);
        mem = s.substr(64, 12);
        for (int i = 0; i < id.size(); i++) {
            if (isdigit(id[i])) {
                id2 += id[i];
            }
        }
        for (int i = 0; i < mem.size(); i++) {
            if (isdigit(mem[i]) || mem[i] == ',') {
                mem2 += mem[i];
            }
        }
        replace(mem2.begin(), mem2.end(), ',', '.');
        process p;
        p.set_name(name);
        p.set_id(stoi(id2));
        p.set_memory(stof(mem2));
        task.Add(p);
        mem2.clear();
        id2.clear();
    }
    task.sort_mem();
    task.print();

}