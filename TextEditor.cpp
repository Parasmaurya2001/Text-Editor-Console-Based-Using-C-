#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;

class Node
{
public:
    string name;
    string content;
    Node *next = NULL;

    Node(string name, string content)
    {
        this->name = name;
        this->content = content;
    }
};

class FileManager
{
public:
    Node *head = NULL;

    // addition - sub
    void insert(string name, string content)
    {
        Node *newNode = new Node(name, content);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    // display - sub
    void display(string name)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << "---------------------------------------------" << endl;
                cout << "The Content is : " << temp->content;
                cout << "---------------------------------------------" << endl;
                return;
            }
            temp = temp->next;
        }
    }

    // search - sub
    int search(string name)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }

    // delete - sub
    void remove(string name)
    {

        if (head->next = NULL)
        {
            head = NULL;
            return;
        }

        if (head->name == name)
        {
            head = head->next;
            return;
        }

        Node *temp1 = head;
        Node *prev = NULL;

        while (temp1 != NULL)
        {
            if (temp1->name == name)
            {
                prev->next = temp1->next;
            }
            prev = temp1;
        }
    }

    // Content Getter
    string getContent(string name)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                return temp->content;
            }
            temp = temp->next;
        }
        return "NOT FOUND";
    }

    // Modify function
    void modify(string name, string content)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                temp->content = content;
                return;
            }
            temp = temp->next;
        }
    }

    //  edit function
    void edit(string name)
    {
        stack<string> undo;
        stack<string> redo;
        // undo.push(getContent(name));
        while (true)
        {
            string choice;
            cout << "---------------------------------------------" << endl;
            cout << "Welcome to Editing Menu" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "1. Insertion in File" << endl;
            cout << "2. Deletion in File" << endl;
            cout << "3. Undo Opertion" << endl;
            cout << "4. Redo Operation" << endl;
            cout << "5. Return to Main Menu" << endl;
            cout << "Enter Your Choice : ";
            getline(cin, choice);

            switch (stoi(choice))
            {
            case 1:
                insertion(name, undo, redo);
                break;

            case 2:
                deletion(name, undo, redo);
                break;

            case 3:
                undooperation(name, undo, redo);
                break;

            case 4:
                redooperation(name, undo, redo);
                break;

            case 5:
                return;
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Wrong Choice - Please Try Again" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            }
        }
    }

    // Insertion Menu
    void insertion(string name, stack<string> &undo, stack<string> &redo)
    {
        while (true)
        {
            string choice;
            cout << "---------------------------------------------" << endl;
            cout << "Insertion Menu : " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "1. Insertion in Begining" << endl;
            cout << "2. Insertion in the Middle" << endl;
            cout << "3. Insertion in the End" << endl;
            cout << "4. Return to Edit Menu" << endl;
            getline(cin, choice);

            switch (stoi(choice))
            {
            case 1:
                insertbegin(name, undo, redo);
                break;

            case 2:
                insertmid(name, undo, redo);
                break;

            case 3:
                insertend(name, undo, redo);
                break;

            case 4:
                return;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Wrong Choice" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            }
        }
    }

    // Insert Begin
    void insertbegin(string name, stack<string> &undo, stack<string> &redo)
    {
        undo.push(getContent(name));
        cout << "---------------------------------------------" << endl;
        cout << "The original content in the File is : " << getContent(name) << endl;
        string temp;
        cout << "Enter the content that you want to insert in the begining of the content : ";
        getline(cin, temp);
        string original = temp + getContent(name);
        // undo.push(original);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

    // Insert Mid
    void insertmid(string name, stack<string> &undo, stack<string> &redo)
    {
        undo.push(getContent(name));
        cout << "---------------------------------------------" << endl;
        cout << "The original content in the File is : " << getContent(name) << endl;
        string temp;
        cout << "Enter the content that you want to insert in the Middle of the content : ";
        getline(cin, temp);
        string index;
        cout << "Enter the index of modification";
        getline(cin, index);
        string original = getContent(name).substr(0, stoi(index)) + temp + getContent(name).substr(stoi(index));
        // undo.push(original);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

    // Insert Begin
    void insertend(string name, stack<string> &undo, stack<string> &redo)
    {
        undo.push(getContent(name));
        cout << "---------------------------------------------" << endl;
        cout << "The original content in the File is : " << getContent(name) << endl;
        string temp;
        cout << "Enter the content that you want to insert in the end of the content : ";
        getline(cin, temp);
        string original = getContent(name) + temp;
        // undo.push(original);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

    // Deletion Menu - edit
    void deletion(string name, stack<string> &undo, stack<string> &redo)
    {
        while (true)
        {
            string choice;
            cout << "---------------------------------------------" << endl;
            cout << "Deletion Menu : " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "1. Deletion in Begining" << endl;
            cout << "2. Deletion in the Middle" << endl;
            cout << "3. Deletion in the End" << endl;
            cout << "4. Return to Edit Menu" << endl;
            getline(cin, choice);

            switch (stoi(choice))
            {
            case 1:
                deletebegin(name, undo, redo);
                break;

            case 2:
                deletemid(name, undo, redo);
                break;

            case 3:
                deleteend(name, undo, redo);
                break;

            case 4:
                return;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Wrong Choice" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            }
        }
    }

    // delete-begin
    void deletebegin(string name, stack<string> &undo, stack<string> &redo)
    {
        undo.push(getContent(name));
        cout << "---------------------------------------------" << endl;
        cout << "The original content in the File is : " << getContent(name) << endl;
        string index;
        cout << "Enter the index upto which you want to delete from the begining : ";
        getline(cin, index);
        string original = getContent(name).substr(stoi(index) + 1);
        //   undo.push(original);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

    // delete-mid
    void deletemid(string name, stack<string> &undo, stack<string> &redo)
    {
        undo.push(getContent(name));
        cout << "---------------------------------------------" << endl;
        cout << "The original content in the File is : " << getContent(name) << endl;
        string sindex, eindex;
        cout << "Enter the starting index which you want to delete : ";
        getline(cin, sindex);
        cout << "Enter the ending index which you want to delete : ";
        getline(cin, eindex);
        string original = getContent(name).substr(0, stoi(sindex)) + getContent(name).substr(stoi(eindex));
        // undo.push(original);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

    // delete - end
    void deleteend(string name, stack<string> &undo, stack<string> &redo)
    {
        undo.push(getContent(name));
        cout << "---------------------------------------------" << endl;
        cout << "The original content in the File is : " << getContent(name) << endl;
        string index;
        cout << "Enter the index through which you want to delete from the end : ";
        getline(cin, index);
        string original = getContent(name).substr(0, getContent(name).size() - stoi(index));
        // undo.push(original);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

    // undo - operation
    void undooperation(string name, stack<string> &undo, stack<string> &redo)
    {
        // string temp = undo.top();
        // undo.pop();

        cout << "---------------------------------------------" << endl;

        if (undo.empty())
        {
            cout << "---------------------------------------------" << endl;
            cout << "No opertions to undo" << endl;
            cout << "-----------------------------------" << endl;
            return;
        }

        redo.push(getContent(name));
        cout << "The original content of the file is : " << getContent(name) << endl;
        modify(name, undo.top());
        redo.push(undo.top());
        undo.pop();
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : " << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

    // redo - operation
    void redooperation(string name, stack<string> &undo, stack<string> &redo)
    {
        cout << "---------------------------------------------" << endl;
        if (redo.empty())
        {
            cout << "---------------------------------------------" << endl;
            cout << "No opertions to redo" << endl;
            cout << "---------------------------------------------" << endl;
            return;
        }
        cout << "The original content of the file is : " << getContent(name) << endl;
        string temp = redo.top();
        redo.pop();
        undo.push(temp);
        modify(name, temp);
        cout << "---------------------------------------------" << endl;
        cout << "After Modification the content becomes : " << getContent(name) << endl;
        cout << "---------------------------------------------" << endl;
    }

public:
    // MAIN 4 FUNCTIONS

    //  Create a new File
    void newFile()
    {
        string name;
        string content;
        cout << "---------------------------------------------" << endl;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {
            cout << "---------------------------------------------" << endl;
            cout << "File Name Already Exists" << endl;
            cout << "---------------------------------------------" << endl;
            return;
        }
        else
        {
            cout << "Enter the content of the File : " << endl;
            getline(cin, content);
            insert(name, content);
            cout << "---------------------------------------------" << endl;
            cout << "File Created Successfully" << endl;
            cout << "---------------------------------------------" << endl;
        }
    }

    // Open a File
    void openFile()
    {
        string name;
        cout << "---------------------------------------------" << endl;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {
            display(name);
            cout << endl;
            return;
        }
        else
        {
            cout << "---------------------------------------------" << endl;
            cout << "File Does Not Exist" << endl;
            cout << "---------------------------------------------" << endl;
            return;
        }
    }

    // Edit a File
    void editFile()
    {
        string name;
        cout << "---------------------------------------------" << endl;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {

            edit(name);
            return;
        }
        else
        {
            cout << "---------------------------------------------" << endl;
            cout << "File does not Exist" << endl;
            cout << "---------------------------------------------" << endl;
        }
    }

    // Remove a File
    void removeFile()
    {
        string name;
        cout << "---------------------------------------------" << endl;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {
            remove(name);
            cout << "---------------------------------------------" << endl;
            cout << "File Deleted Successfully" << endl;
            cout << "---------------------------------------------" << endl;
            return;
        }
        else
        {
            cout << "---------------------------------------------" << endl;
            cout << "File Does not Exist" << endl;
            cout << "---------------------------------------------" << endl;
        }
    }
};

int main()
{
    string choice;
    FileManager f;
    cout << "---------------------------------------------" << endl;
    cout << "WELCOME TO TEXT EDITOR" << endl;
    cout << "---------------------------------------------" << endl;
    while (true)
    {
        cout << "---------------------------------------------" << endl;
        cout << "MAIN MENU" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Press the following digits to perform an operation : " << endl;
        cout << "1. New File" << endl;
        cout << "2. Open File" << endl;
        cout << "3. Edit File" << endl;
        cout << "4. Delete File" << endl;
        getline(cin, choice);

        switch (stoi(choice))
        {

        // New File
        case 1:
            f.newFile();
            break;

        case 2:
            f.openFile();
            break;

        case 3:
            f.editFile();
            break;

        case 4:
            f.removeFile();
            break;

        default:
            cout << "---------------------------------------------" << endl;
            cout << "Wrong Choice selected" << endl;
            cout << "---------------------------------------------" << endl;
            break;
        }
    }
    return 0;
}