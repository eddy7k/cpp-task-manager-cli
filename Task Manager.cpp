#include <iostream>
#include <vector> 
#include <fstream>
#include <string>

using namespace std;  


void saveTasks(const vector<string>& tasks, const string& filename)
{
    ofstream file(filename);
    for(const auto& task : tasks)
    {
        file << task << "\n";
    }

}


void loadTasks(vector<string>& tasks, const string& filename)
{
    ifstream file(filename);
    string task;

    while(getline(file,task))
    {
        if(!task.empty())
        {
            tasks.push_back(task);
        }
    }
}


int main()
{
    
    vector<string> tasks;
    const string filename = "tasks.txt";

    loadTasks(tasks,filename);


    while(true)
    {
        cout<<"\nTo-Do List:\n";

        //Display tasks of the list
        for(int i = 0;i<tasks.size();i++)
        {
            cout<< i + 1 << ". "<< tasks[i] << "\n";
        }

        //Menu options

        cout<<"\nOptions:\n";
        cout<<"1. Add Task\n";
        cout<<"2. Remove Task\n";
        cout<<"3. Exit\n";
        cout<<"Choose an option: ";
        int choice;
        cin>>choice;
        cin.ignore();

        if(choice == 1)
        {
            cout<< "Enter task: ";
            string task;
            getline(cin,task);
            tasks.push_back(task);
            saveTasks(tasks,filename);
        }
        else if(choice == 2)
        {
            cout<< "Enter task number to remove: ";
            int taskNum;
            cin>>taskNum;

            if(taskNum >=1 && taskNum <= tasks.size())
            {
                tasks.erase(tasks.begin() + taskNum - 1);
                saveTasks(tasks,filename);
            }
            else
            {
                cout<<"Invalid task number\n";
            }
        }
        else if(choice == 3)
        {
        break;
       }
       else
       {
        cout<<"Invalid choice \n";
       }
    }
    
    return 0;
}