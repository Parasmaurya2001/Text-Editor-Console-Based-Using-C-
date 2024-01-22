# Text Editor

This is a simple text editor implemented in C++ that allows users to create, open, edit, and delete text files. The editor supports basic file manipulation operations such as insertion, deletion, undo, and redo.

## Features

- **New File:** Create a new text file with a specified name and content.
- **Open File:** Display the content of an existing text file.
- **Edit File:** Modify the content of a text file using various editing options, including insertion, deletion, undo, and redo.
- **Delete File:** Remove an existing text file.

## Code Structure

The code is organized into two classes: `Node` and `FileManager`. The `Node` class represents a node in a linked list, where each node contains the name and content of a text file. The `FileManager` class provides methods for file manipulation, including insertion, display, search, deletion, content retrieval, modification, and editing.

### FileManager Class Methods

1. **insert(string name, string content):** Add a new file to the linked list.
2. **display(string name):** Display the content of a specific file.
3. **search(string name):** Check if a file with a given name exists.
4. **remove(string name):** Delete a file with a specified name.
5. **getContent(string name):** Retrieve the content of a file.
6. **modify(string name, string content):** Modify the content of a file.
7. **edit(string name):** Enter the editing menu for a specific file, allowing insertion, deletion, undo, redo, and returning to the main menu.
8. **insertion(string name, stack<string> &undo, stack<string> &redo):** Enter the insertion menu for a specific file, providing options for insertion at the beginning, middle, or end.
9. **insertbegin(string name, stack<string> &undo, stack<string> &redo):** Insert content at the beginning of a file.
10. **insertmid(string name, stack<string> &undo, stack<string> &redo):** Insert content in the middle of a file.
11. **insertend(string name, stack<string> &undo, stack<string> &redo):** Insert content at the end of a file.
12. **deletion(string name, stack<string> &undo, stack<string> &redo):** Enter the deletion menu for a specific file, providing options for deletion at the beginning, middle, or end.
13. **deletebegin(string name, stack<string> &undo, stack<string> &redo):** Delete content from the beginning of a file.
14. **deletemid(string name, stack<string> &undo, stack<string> &redo):** Delete content from the middle of a file.
15. **deleteend(string name, stack<string> &undo, stack<string> &redo):** Delete content from the end of a file.
16. **undooperation(string name, stack<string> &undo, stack<string> &redo):** Undo the last operation on a file.
17. **redooperation(string name, stack<string> &undo, stack<string> &redo):** Redo the last undone operation on a file.
18. **newFile():** Create a new text file.
19. **openFile():** Open and display the content of an existing text file.
20. **editFile():** Edit the content of an existing text file.
21. **removeFile():** Delete an existing text file.

### Main Function

The `main()` function serves as the entry point of the program, presenting a menu for users to choose operations like creating a new file, opening an existing file, editing a file, or deleting a file. The program runs in an infinite loop until the user chooses to exit.

## Usage

1. Compile the code using a C++ compiler.
2. Run the compiled executable.
3. Follow the on-screen prompts to perform file operations.

Feel free to explore and customize the code based on your requirements!
