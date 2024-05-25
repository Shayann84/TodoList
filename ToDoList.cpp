#include <iostream>
#include <vector>
using namespace std;

class TodoList{

    private:
    vector<string> todo;
    vector<int> markIndexes;
    
    int sizeOfVector = 1;
    string task;
    int markIndex, unMarkIndex, priorityIndex, editIndex, removeIndex;

    public:
    void addNewTask() {
        cout<<"Enter your task:";
        cin.ignore();
        getline(cin,task);
        todo.push_back(task);
        todo.shrink_to_fit();
        sizeOfVector++;
    }

    void markAsCompleted() {
        cout<<"Enter the index of your task:";
        cin>> markIndex;
        markIndexes.resize(sizeOfVector);
        markIndexes[markIndex-1] = 1;
        sizeOfVector++;
    }

    void removeMark(){
        cout<<"Enter the index of your task:";
        cin>> unMarkIndex;
        markIndexes[unMarkIndex-1] = 0;
    }

    void prioritiseTask() {
        cout<<"Enter the index of your task:";
        cin>> priorityIndex;
        todo.insert(todo.begin(), todo[priorityIndex-1]);
        todo.erase(todo.begin()+(priorityIndex));
    }

    void editTask() {
        cout<<"Enter the index of your task:";
        while (true) {
            cin>> editIndex;
            auto it = todo.begin() + (editIndex-1);
            if (editIndex >= todo.size()) {
                cout<< "This task index is empty, try an assigned index: ";
            } else {
                cout<<"Enter your task:";
                cin.ignore();
                getline(cin,task);
                *it = task;
                break;
            }
        }
    }

    void deleteTask() {
        cout<<"Enter the index of your task (enter 0 to remove all tasks):";
        cin>> removeIndex;
        if (removeIndex == 0) {
            todo.clear();
        } else {
        todo.erase(todo.begin()+(removeIndex-1));
        }
    }

    void displayAllTasks() {
        int i = 0;
        int index = 1;
        system("cls");
        cout<< "==============================================\n";
        cout<< "=================DISPLAY MENU=================\n\n";

        for (auto it = todo.begin(); it != todo.end(); it++) { 
            if (markIndexes.empty()) {
                cout<<index<<". "<< *it <<"[ ]"<<endl;
            } else {
                if (markIndexes.at(i) == 1) {
                    cout<<index<<". "<< *it <<"[X]"<<endl;
                } else {
                    cout<<index<<". "<< *it <<"[ ]"<<endl;
                }
            }
            i++;
            index++;
        }
        cin.ignore();
        cout << endl << "Press enter to return to main menu: ";
        cin.get();
    }
};

int main() {
    char choices;
    TodoList todo;

    while (true) {
        system("cls");
        cout << "===============================================\n";
        cout << "===================TODO LIST===================\n";
        cout << "===================MAIN MENU===================\n\n";
        cout << "1.Add new task\n2.Display all task\n3.Mark as completed\n";
        cout << "4.Remove Mark\n5.Prioritise task\n6.Edit task\n";
        cout << "7.Delete task\n0.Quit\n\nEnter your choice: ";
        cin  >> choices;

        switch (choices) {
            case '1':
            todo.addNewTask();
            break;

            case '2':
            todo.displayAllTasks();
            break;

            case '3':
            todo.markAsCompleted();
            break;

            case '4':
            todo.removeMark();
            break;

            case '5':
            todo.prioritiseTask();
            break;

            case '6':
            todo.editTask();
            break;

            case '7':
            todo.deleteTask();
            break;
            
            case '0':
            return 0;
            
            default:
            break;
        }
    }
}