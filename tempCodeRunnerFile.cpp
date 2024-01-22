#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    string name;
    string content;
    Node *next;

    Node(string name, string content)
    {
        this->name = name;
        this->content = content;
        this->next = NULL;
    }
};

class FileManager
{
public:
    Node *head;

    FileManager()
    {
        head = NULL;
    }

    // addition - sub
    void insert(string name, string content)
    {
        Node *newNode = new Node(name, content);
        if (head == NULL)
        {
            head = newNode;
        }

        newNode->next = head;
        head = newNode;
    }

    // display - sub
    void
    display(string name)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << "The Content is : " << temp->content;
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
        while (true)
        {
            string choice;
            cout << "Welcome to Editing Menu" << endl;
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
                insertion(name);
                break;

            case 2:
                deletion(name);
                break;

            case 5:
                return;
                break;

            default:
                cout
                    << "Wrong Choice - Please Try Again"
                    << endl;
                break;
            }
        }
    }

    // Insertion Menu
    void insertion(string name)
    {
        while (true)
        {
            string choice;
            cout << "Insertion Menu : " << endl;
            cout << "1. Insertion in Begining" << endl;
            cout << "2. Insertion in the Middle" << endl;
            cout << "3. Insertion in the End" << endl;
            cout << "4. Return to Edit Menu" << endl;
            getline(cin, choice);

            switch (stoi(choice))
            {
            case 1:
                insertbegin(name);
                break;

            case 2:
                insertmid(name);
                break;

            case 3:
                insertend(name);
                break;

            case 4:
                return;

            default:
                break;
            }
        }
    }

    // Insert Begin
    void insertbegin(string name)
    {
        cout << "The original content in the File is : " << getContent(name) << endl;
        string temp;
        cout << "Enter the content that you want to insert in the begining of the content : ";
        getline(cin, temp);
        string original = temp + getContent(name);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
    }

    // Insert Mid
    void insertmid(string name)
    {
        cout << "The original content in the File is : " << getContent(name) << endl;
        string temp;
        cout << "Enter the content that you want to insert in the Middle of the content : ";
        getline(cin, temp);
        string index;
        cout << "Enter the index of modification";
        getline(cin, index);
        string original = getContent(name).substr(0, stoi(index)) + temp + getContent(name.substr(stoi(index) + 1));
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
    }

    // Insert Begin
    void insertend(string name)
    {
        cout << "The original content in the File is : " << getContent(name) << endl;
        string temp;
        cout << "Enter the content that you want to insert in the end of the content : ";
        getline(cin, temp);
        string original = getContent(name) + temp;
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
    }

    // Deletion Menu - edit
    void deletion(string name)
    {
        while (true)
        {
            string choice;
            cout << "Deletion Menu : " << endl;
            cout << "1. Deletion in Begining" << endl;
            cout << "2. Deletion in the Middle" << endl;
            cout << "3. Deletion in the End" << endl;
            cout << "4. Return to Edit Menu" << endl;
            getline(cin, choice);

            switch (stoi(choice))
            {
            case 1:
                deletebegin(name);
                break;

            case 2:
                deletemid(name);
                break;

            case 3:
                deleteend(name);
                break;

            case 4:
                return;

            default:
                break;
            }
        }
    }

    // delete-begin
    void deletebegin(string name)
    {
        cout << "The original content in the File is : " << getContent(name) << endl;
        string index;
        cout << "Enter the index upto which you want to delete from the begining : ";
        getline(cin, index);
        string original = getContent(name).substr(stoi(index) + 1);
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
    }

    // delete-mid
    void deletemid(string name)
    {
        cout << "The original content in the File is : " << getContent(name) << endl;
        string sindex, eindex;
        cout << "Enter the starting index which you want to delete : ";
        getline(cin, sindex);
        cout << "Enter the ending index which you want to delete : ";
        getline(cin, eindex);
        string original = getContent(name).substr(0, stoi(sindex)) + getContent(name).substr(stoi(eindex));
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
    }

    // delete - end
    void deleteend(string name)
    {
        cout << "The original content in the File is : " << getContent(name) << endl;
        string index;
        cout << "Enter the index through which you want to delete from the end : ";
        getline(cin, index);
        string original = getContent(name).substr(0, getContent(name).size() - stoi(index));
        modify(name, original);
        cout << "\nModification done Successfully" << endl;
        cout << "After Modification the content becomes : ";
        cout << getContent(name) << endl;
    }

public:
    // MAIN 4 FUNCTIONS

    //  Create a new File
    void newFile()
    {
        string name;
        string content;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {
            cout << "File Name Already Exists" << endl;
            return;
        }
        else
        {
            cout << "Enter the content of the File : " << endl;
            getline(cin, content);
            insert(name, content);2
            
            cout << "File Created Successfully" << endl;
        }
    }

    // Open a File
    void openFile()
    {
        string name;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {
            display(name);
            return;
        }
        else
        {
            cout << "File Does Not Exist" << endl;
        }
    }

    // Edit a File
    void editFile()
    {
        string name;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {
            edit(name);
            return;
        }
        else
        {
            cout << "File does not Exist" << endl;
        }
    }

    // Remove a File
    void removeFile()
    {
        string name;
        cout << "Enter the Name of the File : " << endl;
        getline(cin, name);
        if (search(name))
        {
            remove(name);
            cout << "File Deleted Successfully" << endl;
        }
        else
        {
            cout << "File Does not Exist" << endl;
        }
    }
};

int main()
{
    string choice;
    FileManager f;
    while (true)
    {
        cout << endl
             << "WELCOME TO TEXT EDITOR" << endl;
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
            cout << "Wrong Choice selected" << endl;
            break;
        }
    }
    return 0;
}