#include <iostream> // std::cout
#include <vector> // std::vector
#include <algorithm> // std::for_each()
#include <random> // std::random_device, std::mt19937, std::uniform_int_distribution
struct Node{
    int data;
    Node* next = nullptr;
};
int main(){
    Node* headNode{nullptr};
    std::vector<int>nums(10);
    
    // for random numbers
    std::random_device rdnum;
    std::mt19937 gen(rdnum());
    std::uniform_int_distribution<>rd(42, 442);
    
    // store random numbers in vector
    std::generate(nums.begin(), nums.end(), [&](){return rd(gen);});
    
    // Print values stored in vector
    std::cout<<"Values stored in vector:"<<std::endl;
    for(int num : nums) std::cout<<num<<" ";
    std::cout<<"\nPrinting linked list:"<<std::endl;
    
    std::for_each(nums.begin(), nums.end(),
    /**
     * Lambda expression to store the values as linked list
     */ 
        // Get a value in vector
        [&](int val){
            // Create new node
            Node* newNode = new Node;

            // add current value to newly created node
            /**
             * val--||
             *      \/
             * ||-----------||
             * ||   data    ||-next-->nullptr
             * ||-----------||
             */
            newNode->data = val;

            // store address of head node in new Node next pointer
            /**
             * ||-----------||
             * ||   data    ||-next-->headNode
             * ||-----------||
             */
            newNode->next = headNode;

            // store new node to the head node
            headNode = newNode;
        }
    );

    // Print Linked list
    while(headNode!=NULL){
        std::cout<<headNode->data<<((headNode->next!=NULL)?"->":"->nullptr");
        headNode = headNode->next;
    }
    return 0;
}
