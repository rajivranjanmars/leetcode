/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
   ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size(); // Get the number of linked lists
    if (k == 0)
        return NULL;

    vector<pair<int, ListNode*>> arr; // Create a vector pair to store values and nodes

    for (int i = 0; i < k; i++) {
        ListNode* curr_list = lists[i]; // Extract the current linked list

        while (curr_list != NULL) { // Traverse the linked list
            arr.push_back({curr_list -> val, curr_list}); // Store value and node in the vector pair
            curr_list = curr_list -> next; // Move to the next node
        }
    }

    if (arr.size() == 0)
        return NULL;

    sort(arr.begin(), arr.end()); // Sort the vector pair based on the values

    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i].second -> next = arr[i + 1].second; // Link the nodes together
    }

    arr[arr.size() - 1].second -> next = NULL; // Set the next pointer of the last node to NULL

    return arr[0].second; // Return the head of the merged linked list
}


};