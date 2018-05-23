## Dynamic structures

Implementation of RBT, BST and HashTable. Writting this algorithms i used Cormen's "Introduction to Algorithms", so in need of full descritption of this structures you can read about it there. All the methods are very simillar to those in this book.


### USAGE

There is avaliable simple parser just to test this structures in run. **To compile the programme just type** `make` in TTY in programme directory. Makefile contains commands which will remove last main file and compile whole programme. Compilation is made with -g flag, so there shouldn't be any problems with testing programme with debuggers.

 <br>
    
  **1.) Running programme and chosing structure**
  
   To chose structures to test you have to use --type flag running main and after the flag type one of structures. Examples of 
   avaliable main calls:
      
   * `./main --type bst `- Binary Search Tree
   * `./main --type rbt `- Red-Black Tree
   * `./main --type hmap `- Hash Table
   
 <br>
   
 **2.) Handling command line and avaliable operations**

  For all type of structures there are the same possible commands, if there is no such operation in given structure the output         would be an empty line, for example `inorder` in Hash Table.**First command that you have to type to stdin is number of commands you want to execute**. Avaliable commands in TTY, during programme run:
  
  * `insert k` - insertion of k string into chosen structure. From borders of a string non alnum chars will be removed before insertion.
  * `delete k` - deletion of k string from chosen structure. If there is more than one occurence,
  * `load file` - loads file and carries insertion for all strings in it splitted by '/n'. This command allows some big data tests as there is printed total operations time to cerr at the end of programme run.
  * `max` - prints to stdout maximum element from the structure.
  * `min` - prints to stdout minimum element from the structure.
  * `inorder` - inorder print of all the elements from the structure.
  * `successor k` - finds and prints succesor of the k element.
  * `find k` - if k is in the structure output will be 1, otherwise 0.
  
