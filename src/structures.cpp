#include <iostream>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

#include "BSTree.h"
#include "List.h"
#include "RBTree.h"
#include "HashTable.h"
#include "DynamicStructure.h"

using namespace std;

void printUsage(){
  cout << endl;
  cout << "usage: ./main --type struct_name" << endl;
  cout << endl;
  cout << "-----------------------------------------------"<< endl;
  cout << endl;
  cout << " available structures : " << endl;
  cout << "     - Binary Search Tree, struct_name: bst" << endl;
  cout << "     - Red Black Tree, struct_name: rbt" << endl;
  cout << "     - Hash Map, struct_name: hmap" << endl;
  cout << endl;
}

/**
*function responsible for removing spaces and not alnum chars from string borders before inserting it into a struct
*/

string remove_char(string str){
  str.erase(remove_if(str.begin(),str.end(),::ispunct),str.end());
  str.erase(remove_if(str.begin(),str.end(),::isspace),str.end());
  return str;
}

/**
*function responsible for inserting strings from a file
*/
void fileToStructure(string fileName,DynamicStructure* structure){
  string line;
  string key;
  ifstream fin;
  istringstream iss;

  fin.open(fileName,ifstream::in);
  while(fin>>key){
    key = remove_char(key);
    structure->insert(key);
  }
  fin.close();
}

int main(int argc, char*argv[]){

  DynamicStructure* structure;
  int opCount=0;

  /**
  * parsing programme arugments and initializing appropriate data structure
  */

  if(argc == 3){
    if(strcmp(argv[1],"--type")==0){
			if(strcmp(argv[2],"bst") == 0){
        structure =  new BSTree();
      }
      else if(strcmp(argv[2],"rbt") == 0){
        structure = new RBTree();
      }
      else if(strcmp(argv[2],"hmap")==0){
        structure = new HashTable();
      }
      else{
        printUsage();
        return 1;
      }
		}
    else{
      cout << "printUsage" << endl;
      return 1;
    }
  }
  else{
    printUsage();
    return 1;
  }

  double time = 0;
  clock_t start;
  clock_t end;

  cin >> opCount;
  int maxEl=0;
  string line;
  string firstToken;
  string secondToken;
  string toInsert;
  cin.ignore();

  /**
  * parsing command line with getline(), executing the operations on given structures and counting stats.
  */

  while(opCount > 0){
    getline(cin, line);
    string firstToken = line.substr(0,line.find(' '));
    string secondToken = line.substr(line.find(' ')+1, line.size());

    toInsert = remove_char(secondToken);

    if(firstToken.compare("insert")==0){
      start = clock();
      structure->insert(toInsert);
      end = clock();
      time+=(end - start) / (double) CLOCKS_PER_SEC;
    }
    else if(firstToken.compare("load")==0){
      start = clock();
      fileToStructure(secondToken, structure);
      end = clock();
      time+=(end - start) / (double) CLOCKS_PER_SEC;
    }
    else if(firstToken.compare("delete")==0){
      start = clock();
      structure->deleteNode(toInsert);
      end = clock();
      time+=(end - start) / (double) CLOCKS_PER_SEC;
    }
    else if(firstToken.compare("find")==0){
      start = clock();
      cout << structure->find(toInsert) << endl;
      end = clock();
      time+=(end - start) / (double) CLOCKS_PER_SEC;
    }
    else if(firstToken.compare("min")==0){
      start = clock();
      cout << structure->min() << endl;
      end = clock();
      time+=(end - start) / (double) CLOCKS_PER_SEC;
    }
    else if(firstToken.compare("max")==0){
      start = clock();
      cout << structure->max() << endl;
      end = clock();
      time+=(end - start) / (double) CLOCKS_PER_SEC;
    }
    else if(firstToken.compare("successor")==0){
      start = clock();
      cout << structure->successor(toInsert) << endl;
      end = clock();
      time+=(end - start) / (double) CLOCKS_PER_SEC;
    }
    else if(firstToken.compare("inorder")==0){
      structure->inorderWalk();
    }
    opCount--;
    if(maxEl < structure->getElements()){
      maxEl = structure->getElements();
    }
  }

  cerr << endl;
  cerr << "---------------"<< endl;
  cerr<< endl;
  cerr << "REMOVALS : "<< structure->getRemovals()<<endl;
  cerr << "INSERTS : "<< structure->getInserts()<<endl;
  cerr << "TOTAL TIME : "<< time<<endl;
  cerr << "MAX ELEMENTS : "<< maxEl << endl;

  delete structure;
}
