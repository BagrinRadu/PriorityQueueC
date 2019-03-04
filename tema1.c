#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Node 
typedef struct node { 
    int data; 
  
    // Lower values indicate higher priority 
    int priority; 
  
    struct node* next; 
  
} Node; 

// Function to Create A New Node 
Node* newNode(int d, int p) 
{ 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->data = d; 
    temp->priority = p; 
    temp->next = NULL; 
  
    return temp; 
} 


// Function to insert nodes according to priority 
void insert(Node** head, int d, int p) 
{ 
    Node* start = (*head); 
  
    // Create new Node 
    Node* temp = newNode(d, p); 
  
    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
    if ((*head)->priority > p) { 
        // Insert New Node before head 
        temp->next = *head; 
        (*head) = temp; 
    } else { 
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && 
               start->next->priority < p) { 
            start = start->next; 
        } 
  
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
  


// Return the value at head 
int top(Node** head) 
{ 
    return (*head)->data; 
} 
  
// Removes the element with the 
// highest priority form the list 
void pop(Node** head) 
{ 
    Node* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 

// Function to check is list is empty 
int isEmpty(Node** head) 
{ 
    return (*head) == NULL; 
} 


// Driver code 
int main(int argc, char **argv) 
{ 
	int i;
	FILE *file;
	char cmd[2000];
	char val[2000];
	long priority;
    // Create a Priority Queue 
    Node* pq = newNode(4, 1); 
    // insert(&pq, 5, 2); 
    // insert(&pq, 6, 3); 
    // insert(&pq, 7, 0); 
  
    // while (!isEmpty(&pq)) { 
    //     printf("%d ", top(&pq)); 
    //     pop(&pq); 
    // } 


    // Open file if exists
    if (argc > 1) {
    	for (i = 1; i < argc; i++) {
		    if ((file = fopen(argv[i], "r"))) {
		    	while (1) {
		    		fscanf(file, "%s", cmd);
			    	if (strcmp(cmd, "insert") == 0) {
			    		// insert
			    		printf("%s ", cmd);
			    		fscanf(file, "%s %ld", val, &priority);
			    		printf("%s %ld\n", val, priority);
			    	} else if (strcmp(cmd, "top") == 0) {
			    		// top
			    		printf("%s \n", cmd);
			    	} else if (strcmp(cmd, "pop") == 0) {
			    		// pop
			    		printf("%s \n", cmd);
			    	}

			    	if (feof(file)) {
		    			printf("GATAAA\n");
     					break;
		    		}
			    }
			    fclose(file);
		    }
    	}
	} else {
		// Read from standard input
		scanf("%s", cmd);
		if (strcmp(cmd, "insert") == 0) {
    		// insert
    		printf("%s ", cmd);
    		scanf("%s %ld", val, &priority);
    		printf("%s %ld\n", val, priority);
    	} else if (strcmp(cmd, "top") == 0) {
    		// top
    		printf("%s \n", cmd);
    	} else if (strcmp(cmd, "pop") == 0) {
    		// pop
    		printf("%s \n", cmd);
    	}

	}
  
    return 0; 
} 