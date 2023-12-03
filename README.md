# INTECH-ADDITV 
# **Question 1
 a) String compression
Implement a method to perform string compression. E.g. ‘aabcccccaaa’ should be a2b1c5a3. The
code to implement this is given in the link - https://www.educative.io/answers/string-
compression-using-run-length-encoding

# ___ Ans ___ with bonus 1 and bonus 2

![WhatsApp Image 2023-12-03 at 15 32 15_0d4b1aa7](https://github.com/VishwajitNaik/INTECH-ADDITV/assets/44186372/d134e06d-bb58-447d-bba3-0857a341d49d)

    #include <iostream>
    #include <string>
    using namespace std;
    
    string compress(const string& s) {
        int num = s.length(); // calculating length of the string
        string compressed;

    int i = 0;
    while (i < num) {
        // Counting the repetitions of each character
        int repetition = 1;
        while (s[i] == s[i + 1] && i < num - 1) {
            repetition++;
            i++;
        }

        // Append character and its count to the compressed string (skip if count is 1)
        if (repetition > 1) {
            compressed += s[i] + to_string(repetition);
        } else {
            compressed += s[i];
        }

        i++;
    }

    return compressed;
    }

    int main() {
        string str = "aabbcddddd";
        string compressedStr = compress(str);
        cout << compressedStr << endl;

    // Bonus 1: Compress further
    string compressedStr2 = compress(compressedStr);
    cout << compressedStr2 << endl;

    // Bonus 2: Decompress
    // Decompress the second compressed string
    string decompressedStr = "";
    int index = 0;
    while (index < compressedStr2.length()) {
        char c = compressedStr2[index++];
        string countStr = "";
        while (index < compressedStr2.length() && isdigit(compressedStr2[index])) {
            countStr += compressedStr2[index++];
        }
        int count = (countStr.empty()) ? 1 : stoi(countStr);
        decompressedStr += string(count, c);
    }

    cout << decompressedStr << endl;

    return 0;
}

# /*
Output : -

a2b2cd5
a2b2cd5
aabbcddddd

# **Question 2
Linked List - The link shows a program to find the nth element of a linked list.
https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

Find a way to find the kth to the last element of linked list ( assume length of linked list is not
known)

# ___ Ans ___ with bonus 1

# Psudo code  (logic) : 
![WhatsApp Image 2023-12-03 at 15 32 15_efe03599](https://github.com/VishwajitNaik/INTECH-ADDITV/assets/44186372/7d2dbeea-c166-4a47-98f2-346e5510efec)



# Main Code :


     #include <stdio.h>
     #include <stdlib.h>
     
     struct Node {
         int data;
         struct Node* next;
     };
     
     // Function to find the kth to the last element of a linked list
     struct Node* kthToLast(struct Node* head, int k) {
         if (head == NULL || k <= 0) {
             return NULL;
         }

    struct Node *s = head, *s1 = head;
    int i = 1;

    // Move s1 k nodes ahead
    while (s1->next != NULL && i < k) {
        i++;
        s1 = s1->next;
    }

    // If k is greater than the length of the linked list
    if (i < k) {
        return NULL;
    }

    // Move s and s1 until s1 reaches the end
    while (s1->next != NULL) {
        s1 = s1->next;
        s = s->next;
    }

    return s;
}

    // Function to insert a new node at the end of the linked list
    void insertAtEnd(struct Node** headRef, int newData) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        struct Node* last = *headRef;

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    return;
    }

    // Function to print the linked list
    void printList(struct Node* node) {
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
    
    // Driver program to test the functions
    int main() {
        struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    int k = 3;
    struct Node* kthNode = kthToLast(head, k);

    if (kthNode != NULL) {
        printf("The %dth to the last element is: %d\n", k, kthNode->data);
    } else {
        printf("Invalid value of k\n");
    }

    return 0;
    }


# **Question 3
c) Stack minimum- Details of stack data structure is available in
https://www.geeksforgeeks.org/stack-data-structure/
Stack has functions of push and pop. Can you also add a function ‘min’ to the stack and it
should also execute in O(1).
If you are not aware of O(1), refer to some videos online. E.g.
https://en.wikipedia.org/wiki/Big_O_notation
Bonus 1 –
Explain one real world use case where stack is better used data structure than arrays.

# ___ Ans ___

# psudo code : -

![WhatsApp Image 2023-12-03 at 15 32 15_804c27b8](https://github.com/VishwajitNaik/INTECH-ADDITV/assets/44186372/4506f71f-16a8-418d-80ce-19e84d6fa218)


# main code


    #include <stdio.h>
    #include <stdlib.h>
    
    #define N 100 // Size of the stack
    
    // Structure to represent a stack
    struct Stack {
        int arr[N];
        int top;
        int minStack[N];
        int minTop;
    };
    
    // Function to initialize a stack
    void initialize(struct Stack *stack) {
        stack->top = -1;
        stack->minTop = -1;
    }
    
    // Function to push an element onto the stack
    void push(struct Stack *stack, int x) {
        if (stack->top + 1 == N) {
            printf("Stack overflow\n");
            exit(1);
        } else {
            stack->top++;
            stack->arr[stack->top] = x;
    
            // Update the minimum stack
            if (stack->minTop == -1 || x <= stack->minStack[stack->minTop]) {
                stack->minTop++;
                stack->minStack[stack->minTop] = x;
            }
        }
    }
    
    // Function to pop an element from the stack
    int pop(struct Stack *stack) {
        if (stack->top == -1) {
            printf("Stack underflow\n");
            exit(1);
        } else {
            int y = stack->arr[stack->top];
    
            // Update the minimum stack
            if (y == stack->minStack[stack->minTop]) {
                stack->minTop--;
            }
    
            stack->top--;
            return y;
        }
     }

    // Function to get the minimum element from the stack
    int getMinimum(struct Stack *stack) {
        if (stack->minTop == -1) {
            printf("Stack is empty\n");
            exit(1);
        } else {
            return stack->minStack[stack->minTop];
        }
    }

    int main() {
        struct Stack stack;
        initialize(&stack);
    
        // Push elements onto the stack
        push(&stack, 3);
        push(&stack, 5);
        push(&stack, 2);
        push(&stack, 1);
        push(&stack, 4);
    
        // Get the minimum element
        printf("Minimum element in the stack: %d\n", getMinimum(&stack));
    
        // Pop elements from the stack
        printf("Popped element: %d\n", pop(&stack));
        printf("Popped element: %d\n", pop(&stack));
    
        // Get the minimum element after popping
        printf("Minimum element in the stack: %d\n", getMinimum(&stack));
    
        return 0;
    }


# Bonus 1 :-
  # 1] Browser(Back button ) : -
          Web browsers use a stack to implement the "Back" button functionality. 
          Each time a user visits a web page, the browser adds the page to a stack.
          When the user clicks the "Back" button, the browser pops the top page from the stack and navigates to the previous page.
# 2] Undo Mechanism in Software:
          Many software applications, including text editors, graphic design tools,  use a stack to implement the "Undo" mechanism. 
          Each action performed by the user is pushed onto a stack, and pressing "Undo" pops the last action from the stack.

# **Question 4

You will be given a list coin denominations that you can use to tender change to
your customers, find the most optimum way to tender the exact change to your
customers , the optimum is when you use the least number of coins.
Example:
# input =&gt; [ 1, 2, 5, 8, 10] (available coins)
# Input =&gt; 7 (Change to be given)
# Ans : [ 2, 5 ]

# ___ Ans ___

# Ans : - Code
     #include <stdio.h>
     #include <stdlib.h>
     #include <limits.h>
     
     int min(int a, int b) {
         return (a < b) ? a : b;
     }
     
     void findOptimalChange(int coins[], int numCoins, int amount) {
         int dp[amount + 1];
         int parent[amount + 1];
     
         dp[0] = 0;
     
         for (int i = 1; i <= amount; i++) {
             dp[i] = INT_MAX;
             parent[i] = -1;
         }
     
         for (int i = 0; i < numCoins; i++) {
             for (int j = coins[i]; j <= amount; j++) {
                 if (dp[j - coins[i]] != INT_MAX && dp[j - coins[i]] + 1 < dp[j]) {
                     dp[j] = dp[j - coins[i]] + 1;
                     parent[j] = i;
                 }
             }
         }
     
         if (dp[amount] == INT_MAX) {
             printf("No solution exists for the given amount using the provided coins.\n");
         } else {
             printf("Optimal change: ");
             while (amount > 0) {
                 int coin = coins[parent[amount]];
                 printf("%d ", coin);
                 amount -= coin;
             }
             printf("\n");
         }
     }
     
     int main() {
         int coins[] = {1, 2, 5, 8, 10};
         int numCoins = sizeof(coins) / sizeof(coins[0]);
         int amount = 7;
     
         printf("Available coins: ");
         for (int i = 0; i < numCoins; i++) {
             printf("%d ", coins[i]);
         }
         printf("\n");
     
         printf("Change to be given: %d\n", amount);
     
         findOptimalChange(coins, numCoins, amount);
     
         return 0;
     }


Explain what is a greedy algorithm and how dynamic programming helps in this case.

  # Bonus question:
          given a number N, remove one digit and print the largest possible number.
# __ANS__
      
    #include <stdio.h>
    #include <string.h>
    
    void removeOneDigit(char number[]) {
        int n = strlen(number);
    
        for (int i = 0; i < n - 1; i++) {
            // If the current digit is smaller than the next digit, remove it
            if (number[i] < number[i + 1]) {
                // Move all digits after the removed digit one position left
                for (int j = i; j < n - 1; j++) {
                    number[j] = number[j + 1];
                }
                // Set the last digit to null character to shorten the string
                number[n - 1] = '\0';
                return;  // Stop after removing one digit
            }
        }
    
        // If no removal occurred, remove the last digit
        number[n - 1] = '\0';
    }
    
    int main() {
        char number[] = "9273";
        
        printf("Original number: %s\n", number);
        
        removeOneDigit(number);
        
        printf("Largest number after removing one digit: %s\n", number);
    
        return 0;
    }


# **Question 5
What is dot product and cross product? Explain use cases of where dot product is used and
cross product is used in graphics environment. Add links to places where you studied this
information and get back with the understanding.

# ___ Ans ___

# **Question 6
Explain a piece of code that you wrote which you are proud of? If you have not written any
code, please write your favorite subject in engineering studies. We can go deep into that
subject.

# ___ Ans ___

# **Question 7
Random crashes – you are given a source code to test and it randomly crashes and it never
crashes in the same place ( you have attached a debugger and you find this). Explain what
all you would suspect and how would you go about with isolating the cause.
# ___ Ans ___
