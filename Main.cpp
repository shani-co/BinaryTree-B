#include "sources/BinaryTree.hpp"               // link us to the source hpp file.
#include <algorithm>
#include <vector>  
#include <cstring> 

using namespace std;
using namespace ariel;

int main(){

BinaryTree<char> CharsTree;
CharsTree.add_root('-');
CharsTree.add_left('-', '>');
CharsTree.add_right('-', '<');


std::cout << "preorder:" <<std::endl;
for (auto it=CharsTree.begin_preorder(); it!=CharsTree.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }
  cout << endl;
    std::cout << "inorder:" <<std::endl;
  for (auto it=CharsTree.begin_inorder(); it!=CharsTree.end_inorder(); ++it) {
    cout << (*it) << " " ; 
  }
  cout << endl;
    std::cout << "postorder:" <<std::endl;
  for (auto it=CharsTree.begin_postorder(); it!=CharsTree.end_postorder(); ++it) {
    cout << (*it) << " " ;  // prints: a b +
  }
  cout << endl; 

BinaryTree<string> StringTree;
StringTree.add_root("shani");
StringTree.add_left("shani","want");
StringTree.add_right("shani","to");
StringTree.add_right("to","graduate");

std::cout << "preorder:" <<std::endl;
for (auto it=StringTree.begin_preorder(); it!=StringTree.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }
  cout << endl;
    std::cout << "inorder:" <<std::endl;
  for (auto it=StringTree.begin_inorder(); it!=StringTree.end_inorder(); ++it) {
    cout << (*it) << " " ;
  }
  cout << endl;
    std::cout << "postorder:" <<std::endl;
  for (auto it=StringTree.begin_postorder(); it!=StringTree.end_postorder(); ++it) {
    cout << (*it) << " " ;  // prints: a b +
  }
  cout << endl;

BinaryTree<int> Tree;
Tree.add_root(49);
Tree.add_left(49,7);
Tree.add_right(49,2);
Tree.add_left(7,1);
Tree.add_right(7,6);
Tree.add_left(2,5);
Tree.add_right(2,9);

std::cout << "preorder:" <<std::endl;
for (auto it=Tree.begin_preorder(); it!=Tree.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }
  cout << endl;
  std::cout << "inorder:" <<std::endl;
  for (auto it=Tree.begin_inorder(); it!=Tree.end_inorder(); ++it) {
    cout << (*it) << " " ;
  }
  cout << endl;
  std::cout << "postorder:" <<std::endl;
  for (auto it=Tree.begin_postorder(); it!=Tree.end_postorder(); ++it) {
    cout << (*it) << " " ;
  }
  cout <<"\n"<< endl;

}