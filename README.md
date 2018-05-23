## Dynamic structures

Implementation of RBT, BST and HashTable. Writting this algorithms i used Cormen's "Introduction to Algorithms", so in need of full descritption of this structures and methods you can read about it there.


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

  For all type of structures there are the same possible commands, if there is no such operation in given structure the output         would be an empty line, for example `inorder` in Hash Table. Avaliable commands in TTY, during programme run:
  
  * `insert k` - insertion of k string into chosen structure. From borders of a string non alnum chars will be removed before insertion.
  * `delete k` - deletion of k string from chosen structure. If there is more than one occurence,
  *
