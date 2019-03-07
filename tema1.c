#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"

// Node 
typedef struct node { 
    char data[200]; 
  
    int priority; 
  
    struct node* next; 
  
} Node; 

// Function to Create A New Node 
Node* newNode(char d[200], int p) { 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    strcpy(temp->data, d); 
    temp->priority = p; 
    temp->next = NULL; 
  
    return temp; 
} 


// Function to insert nodes according to priority 
void insert(Node** head, char d[200], int p) { 
    Node* start = (*head); 
  
    // Create new Node 
    Node* temp = newNode(d, p); 
  
    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
    //if ((*head)->priority < p) { 
    if (compare((*head)->priority, p) < 0) { 
        // Insert New Node before head 
        temp->next = *head; 
        (*head) = temp; 
    } else { 
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && 
               compare(start->next->priority, p) > 0) { 
            start = start->next; 
        } 
  
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
  

// Function to check is list is empty 
int isEmpty(Node** head) 
{ 
    return (*head) == NULL; 
} 


// Return the value at head 
char * top(Node** head) 
{ 
    return (*head)->data; 
} 
  


// Removes the element with the 
// highest priority form the list 
void pop(Node** head) 
{ 
    if(!isEmpty(head)) {
    	Node* temp = *head; 
    	(*head) = (*head)->next; 
    	free(temp); 
	}
} 




// Driver code 
int main(int argc, char **argv) 
{ 
	int i, j, nr_spaces;
	FILE *file;
	char line[2000];
	char * p;
	int read;
	long unsigned int len = 0;
	char cmd[200];
	char val[200];
	long priority;
    // Create a Priority Queue 
    Node* pq = NULL; 


    // Open file if exists
    if (argc > 1) {
    	for (i = 1; i < argc; i++) {
		    if ((file = fopen(argv[i], "r"))) {
		    	while (fgets(line, sizeof(line), file) != NULL) {
		    		sscanf(line, "%s", cmd);
		    		// Verify if this line is a valid command. If YES then execute it.
			    	if (strncmp(line, "insert", 6) == 0 && strlen(line) > 8) {
			    		nr_spaces = 0;
			    		for(j = 0; j < strlen(line); j++) {
			    			if(line[j] == ' ') {
			    				nr_spaces = nr_spaces + 1;
			    			}
			    		}
			    		if (nr_spaces != 2) {
			    			continue;
			    		}
			    		// Valid insert
			    		sscanf(line, "%s %s %ld", cmd, val, &priority);
			    		if(isEmpty(&pq)) {
			    			pq = newNode(val, priority);
			    		} else {
			    			insert(&pq, val, priority);
			    		}
			    	} else if (strncmp(line, "top", 3) == 0 && strlen(line) <= 5) {
			    		if(!isEmpty(&pq)) {
			    			printf("%s\n", top(&pq));
			    		} 
			    	} else if (strncmp(line, "pop", 3) == 0 && strlen(line) <= 5) {
			    		pop(&pq);
			    	}

			    	if (feof(file)) {
     					break;
		    		}
			    }
			    fclose(file);
		    }
    	}
	} else {

		while(fgets(line, sizeof(line), stdin)) {
			sscanf(line, "%s", cmd);
		    		// Verify if this line is a valid command. If YES then execute it.
			    	if (strncmp(line, "insert", 6) == 0 && strlen(line) > 8) {
			    		nr_spaces = 0;
			    		for(j = 0; j < strlen(line); j++) {
			    			if(line[j] == ' ') {
			    				nr_spaces = nr_spaces + 1;
			    			}
			    		}
			    		if (nr_spaces != 2) {
			    			continue;
			    		}
			    		// Valid insert
			    		sscanf(line, "%s %s %ld", cmd, val, &priority);
			    		if(isEmpty(&pq)) {
			    			pq = newNode(val, priority);
			    		} else {
			    			insert(&pq, val, priority);
			    		}
			    	} else if (strncmp(line, "top", 3) == 0 && strlen(line) <= 5) {
			    		if(!isEmpty(&pq)) {
			    			printf("%s\n", top(&pq));
			    		} 
			    	} else if (strncmp(line, "pop", 3) == 0 && strlen(line) <= 5) {
			    		pop(&pq);
			    	}
		}
	}



	while(!isEmpty(&pq)) {
		pop(&pq);
	}

    return 0; 
} 
