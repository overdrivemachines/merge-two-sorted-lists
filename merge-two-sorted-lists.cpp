#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> values);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
void printLinkedList(ListNode* head);

int main(int argc, char const* argv[]) {
  vector<int> v = {5, 3, 7, 6};
  ListNode* list1 = createLinkedList(v);
  printLinkedList(list1);
  return 0;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* head;

  return head;
}

// Create Linked list given a vector of int values
// returns pointer to head of lined list
ListNode* createLinkedList(vector<int> values) {
  ListNode* head;
  ListNode* node = new ListNode();
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;
  }
  head = head->next;
  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head) {
  ListNode* node = head;

  while (node != nullptr) {
    cout << node->val << "->";
    node = node->next;
  }
  cout << "NULL\n";
}
