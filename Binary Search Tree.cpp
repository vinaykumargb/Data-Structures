#include <iostream> // std::cout
#include <vector> // std::vector
#include <algorithm> // std::generate()
#include <cstdlib> // srand(), rand()
#include <ctime> // time()
int randnum(){
    return ((rand()%100)+1);
}
struct Node {
    int data;
    Node *left = nullptr, 
    *right = nullptr;
    Node(int data){
        this->data = data;
    }
};
Node *root{nullptr};
class BST {
public:
    bool IsNull(Node *root){
        return (root==nullptr);
    }
    Node* push(Node *root, int data){
        if(IsNull(root)){
            root = new Node(data);
        }else if(data < (*root).data){
            (*root).left =
            push((*root).left, data);
        }else if(data == (*root).data){
            return root;
        }else {
            (*root).right =
            push((*root).right, data);
        }
        ::root = root;
        return root;
    }
    void Inorder(Node *root){
        if(!IsNull(root)){
            Inorder((*root).left);
            std::cout<<
            (*root).data<<" ";
            Inorder((*root).right);
        }
    }
    bool Search(Node *root, int val){
        if(IsNull(root)){
            return false;
        } 
        if(root->data == val){
            return true;
        }
        if((*root).data > val){
            return
            Search((*root).left, val);
        }else{
            return 
            Search((*root).right, val);
        }
    }
};
int main() {
    srand(time(nullptr));
    BST B;
    std::vector<int>values(100);
    std::generate(
        values.begin(), values.end(),
        ::randnum
    );
    for(int value : values){
        B.push(root, value);
    }
    std::cout<<(B.IsNull(root)?
        "Root is Empty.\n":
        "Root is not empty.\n");
    std::cout<<"Printing values stored in Binary Tree:\n";
    B.Inorder(root);
    std::cout<<(B.Search(root, 42)?
        "\nValue 42 is Found":
        "\nValue 42 isn't Found"
        );
    root = nullptr;
    std::cout<<(B.IsNull(root)?
        "\nRoot is Empty.":
        "\nRoot is not empty."
        );
    return 0;
}
