// DAY 2: ADVANCED POINTERS & LINKED LISTS
// Building on Day 1 foundation - Taking it to the next level!
// Focus: Double pointers, function pointers, linked lists

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// ============================================================================
// PART 1: POINTER TO POINTER (Double Pointers)
// ============================================================================

void part1_double_pointers() {
    printf("=== PART 1: DOUBLE POINTERS (POINTER TO POINTER) ===\n\n");
    
    int value = 42;
    int *ptr = &value;        // Pointer to int
    int **ptr_to_ptr = &ptr;  // Pointer to pointer to int
    
    printf("Understanding Multiple Levels:\n");
    printf("Value:                  %d\n", value);
    printf("Address of value:       %p\n", (void*)&value);
    printf("\n");
    printf("ptr points to:          %p\n", (void*)ptr);
    printf("ptr dereference:        %d\n", *ptr);
    printf("Address of ptr:         %p\n", (void*)&ptr);
    printf("\n");
    printf("ptr_to_ptr points to:   %p\n", (void*)ptr_to_ptr);
    printf("ptr_to_ptr dereference: %p (*ptr_to_ptr = ptr)\n", (void*)*ptr_to_ptr);
    printf("Double dereference:     %d (**ptr_to_ptr = value)\n", **ptr_to_ptr);
    printf("\n");
    
    // Modify value through double pointer
    **ptr_to_ptr = 99;
    printf("After **ptr_to_ptr = 99:\n");
    printf("value is now: %d\n\n", value);
    
    printf("WHY DOUBLE POINTERS MATTER IN EMBEDDED:\n");
    printf("- Modifying pointers in functions (passing pointer by reference)\n");
    printf("- Dynamic arrays of pointers\n");
    printf("- Linked list operations\n");
    printf("- Device driver data structures\n\n");
}

// Practical example: Function that modifies a pointer
void allocate_memory(int **ptr, int size) {
    *ptr = malloc(size * sizeof(int));
    printf("Memory allocated inside function: %p\n", (void*)*ptr);
}

void demonstrate_pointer_modification() {
    printf("=== PRACTICAL: Modifying Pointer in Function ===\n\n");
    
    int *my_array = NULL;
    printf("Before: my_array = %p\n", (void*)my_array);
    
    // Pass pointer's address so function can modify it
    allocate_memory(&my_array, 5);
    
    printf("After:  my_array = %p\n", (void*)my_array);
    
    if (my_array != NULL) {
        // Use the allocated memory
        for(int i = 0; i < 5; i++) {
            my_array[i] = i * 10;
        }
        
        printf("Array contents: ");
        for(int i = 0; i < 5; i++) {
            printf("%d ", my_array[i]);
        }
        printf("\n\n");
        
        free(my_array);
    }
}

// ============================================================================
// PART 2: ARRAY OF POINTERS
// ============================================================================

void part2_array_of_pointers() {
    printf("=== PART 2: ARRAY OF POINTERS ===\n\n");
    
    // Array of string pointers (common in embedded)
    char *error_messages[] = {
        "No Error",
        "Invalid Parameter",
        "Hardware Timeout",
        "Memory Allocation Failed",
        "Sensor Not Responding"
    };
    
    int num_messages = sizeof(error_messages) / sizeof(error_messages[0]);
    
    printf("Error Message Table (embedded pattern):\n");
    for(int i = 0; i < num_messages; i++) {
        printf("Error %d: %s\n", i, error_messages[i]);
    }
    printf("\n");
    
    // Array of integer pointers
    int a = 10, b = 20, c = 30;
    int *ptr_array[] = {&a, &b, &c};
    
    printf("Array of Pointers to Integers:\n");
    for(int i = 0; i < 3; i++) {
        printf("ptr_array[%d] points to: %p, value: %d\n", 
               i, (void*)ptr_array[i], *ptr_array[i]);
    }
    printf("\n");
    
    printf("USE CASES IN EMBEDDED:\n");
    printf("- Jump tables for state machines\n");
    printf("- Command handlers\n");
    printf("- Error message lookup\n");
    printf("- Hardware register arrays\n\n");
}

// ============================================================================
// PART 3: FUNCTION POINTERS
// ============================================================================

// Example functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

void part3_function_pointers() {
    printf("=== PART 3: FUNCTION POINTERS ===\n\n");
    
    // Declare function pointer
    int (*operation)(int, int);

    // int (*operation)(int, int);
    
    printf("Function Pointer Basics:\n");
    
    // Point to add function
    operation = add;
    printf("add(5, 3) = %d\n", operation(5, 3));
    
    // Point to subtract function
    operation = subtract;
    printf("subtract(5, 3) = %d\n", operation(5, 3));
    
    // Point to multiply function
    operation = multiply;
    printf("multiply(5, 3) = %d\n", operation(5, 3));
    printf("\n");
    
    // Array of function pointers (common embedded pattern)
    int (*operations[])(int, int) = {add, subtract, multiply};
    char *op_names[] = {"Add", "Subtract", "Multiply"};
    
    printf("Function Pointer Array:\n");
    for(int i = 0; i < 3; i++) {
        printf("%s(10, 5) = %d\n", op_names[i], operations[i](10, 5));
    }
    printf("\n");
    
    printf("EMBEDDED USE CASES:\n");
    printf("- Interrupt handler tables\n");
    printf("- State machine action dispatch\n");
    printf("- Command processing\n");
    printf("- Callback functions\n\n");
}

// ============================================================================
// PART 4: LINKED LISTS - The Foundation
// ============================================================================

// Define a node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node* create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert at beginning
void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    if (new_node == NULL) return;
    
    new_node->next = *head;  // New node points to current head
    *head = new_node;        // Update head to new node
}

// Insert at end
void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (new_node == NULL) return;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    // Traverse to end
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Print list
void print_list(Node *head) {
    Node *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Delete a node
void delete_node(Node **head, int data) {
    if (*head == NULL) return;
    
    // If head needs to be deleted
    if ((*head)->data == data) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Deleted %d from beginning\n", data);
        return;
    }
    
    // Search for node to delete
    Node *current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
        printf("Deleted %d\n", data);
    } else {
        printf("Node with data %d not found\n", data);
    }
}

// Free entire list
void free_list(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("List freed\n");
}

void part4_linked_lists() {
    printf("=== PART 4: LINKED LISTS ===\n\n");
    
    Node *head = NULL;
    
    printf("Building a Linked List:\n\n");
    
    // Insert elements
    printf("Inserting at beginning: 30, 20, 10\n");
    insert_at_beginning(&head, 30);
    print_list(head);
    insert_at_beginning(&head, 20);
    print_list(head);
    insert_at_beginning(&head, 10);
    print_list(head);
    printf("\n");
    
    printf("Inserting at end: 40, 50\n");
    insert_at_end(&head, 40);
    print_list(head);
    insert_at_end(&head, 50);
    print_list(head);
    printf("\n");
    
    // Delete elements
    printf("Deleting nodes:\n");
    delete_node(&head, 30);
    print_list(head);
    delete_node(&head, 10);
    print_list(head);
    printf("\n");
    
    // Free memory
    free_list(&head);
    print_list(head);
    
    printf("\nWHY LINKED LISTS IN EMBEDDED:\n");
    printf("- Dynamic task queues in RTOS\n");
    printf("- Buffer management\n");
    printf("- Event handling\n");
    printf("- Device driver queues\n\n");
}

// ============================================================================
// PART 5: PRACTICAL EMBEDDED EXAMPLE - Circular Buffer using Pointers
// ============================================================================

#define BUFFER_SIZE 8

typedef struct {
    int buffer[BUFFER_SIZE];
    int *head;
    int *tail;
    int count;
} CircularBuffer;

void init_circular_buffer(CircularBuffer *cb) {
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
    cb->count = 0;
}

int buffer_write(CircularBuffer *cb, int data) {
    if (cb->count >= BUFFER_SIZE) {
        printf("Buffer FULL! Cannot write %d\n", data);
        return 0;  // Buffer full
    }
    
    *cb->head = data;
    cb->head++;
    
    // Wrap around if needed
    if (cb->head >= cb->buffer + BUFFER_SIZE) {
        cb->head = cb->buffer;
    }
    
    cb->count++;
    return 1;  // Success
}

int buffer_read(CircularBuffer *cb, int *data) {
    if (cb->count == 0) {
        printf("Buffer EMPTY! Cannot read\n");
        return 0;  // Buffer empty
    }
    
    *data = *cb->tail;
    cb->tail++;
    
    // Wrap around if needed
    if (cb->tail >= cb->buffer + BUFFER_SIZE) {
        cb->tail = cb->buffer;
    }
    
    cb->count--;
    return 1;  // Success
}

void part5_circular_buffer() {
    printf("=== PART 5: CIRCULAR BUFFER (EMBEDDED PATTERN) ===\n\n");
    
    CircularBuffer uart_buffer;
    init_circular_buffer(&uart_buffer);
    
    printf("Simulating UART Data Reception:\n\n");
    
    // Write data
    printf("Writing data to buffer:\n");
    for(int i = 0; i < 6; i++) {
        buffer_write(&uart_buffer, i * 10);
        printf("Wrote %d, buffer count: %d\n", i * 10, uart_buffer.count);
    }
    printf("\n");
    
    // Read some data
    printf("Reading data from buffer:\n");
    int data;
    for(int i = 0; i < 3; i++) {
        if (buffer_read(&uart_buffer, &data)) {
            printf("Read %d, buffer count: %d\n", data, uart_buffer.count);
        }
    }
    printf("\n");
    
    // Write more (demonstrating wrap-around)
    printf("Writing more data (wrap-around test):\n");
    for(int i = 60; i < 90; i += 10) {
        buffer_write(&uart_buffer, i);
        printf("Wrote %d, buffer count: %d\n", i, uart_buffer.count);
    }
    printf("\n");
    
    printf("CIRCULAR BUFFERS ARE CRITICAL IN:\n");
    printf("- UART/Serial communication\n");
    printf("- Audio streaming (your speaker project!)\n");
    printf("- Sensor data buffering\n");
    printf("- Inter-task communication\n\n");
}

// ============================================================================
// DAY 2 EXERCISES
// ============================================================================

void day2_exercises() {
    printf("=== DAY 2 PRACTICAL EXERCISES ===\n\n");
    
    printf("YOUR TASKS:\n\n");
    
    printf("EXERCISE 1: Double Pointer Challenge\n");
    printf("-------------------------------------\n");
    printf("Task: Write a function that takes int** and allocates a 2D array\n");
    printf("Prototype: void create_2d_array(int ***arr, int rows, int cols)\n");
    printf("Hint: Allocate array of pointers, then allocate each row\n\n");
    
    printf("EXERCISE 2: Function Pointer State Machine\n");
    printf("-------------------------------------------\n");
    printf("Task: Create a state machine using function pointers\n");
    printf("Hint: Array of function pointers for each state\n\n");
    
    printf("EXERCISE 3: Linked List Operations\n");
    printf("-----------------------------------\n");
    printf("Task: Add these functions to the linked list:\n");
    printf("  - Find middle element\n");
    printf("  - Reverse the list\n");
    printf("  - Detect if list has a cycle\n\n");
    
    printf("EXERCISE 4: Circular Buffer Enhancement\n");
    printf("----------------------------------------\n");
    printf("Task: Add peek function (read without removing)\n");
    printf("Task: Add is_full() and is_empty() functions\n");
    printf("Bonus: Make it work with any data type using void*\n\n");
}

// ============================================================================
// MAIN
// ============================================================================

int main() {
    printf("\n");
    printf("========================================================\n");
    printf("    DAY 2: ADVANCED POINTERS & DATA STRUCTURES        \n");
    printf("        Leveling Up Your Embedded Skills              \n");
    printf("========================================================\n");
    printf("\n");
    
    part1_double_pointers();
    demonstrate_pointer_modification();
    part2_array_of_pointers();
    part3_function_pointers();
    part4_linked_lists();
    part5_circular_buffer();
    day2_exercises();
    
    printf("========================================================\n");
    printf("              DAY 2 SUMMARY                            \n");
    printf("========================================================\n");
    printf("  [OK] Double pointers: Pointer to pointer             \n");
    printf("  [OK] Array of pointers: Multiple pointer management  \n");
    printf("  [OK] Function pointers: Dynamic function calls       \n");
    printf("  [OK] Linked lists: Dynamic data structures           \n");
    printf("  [OK] Circular buffers: Real embedded pattern         \n");
    printf("========================================================\n");
    printf("\n");
    
    printf("NEXT STEPS:\n");
    printf("1. Compile and run this code\n");
    printf("2. Complete the 4 exercises\n");
    printf("3. Read: Data structures for embedded systems\n");
    printf("4. Practice: Draw memory diagrams for each concept\n");
    printf("5. Tomorrow: Communication protocols & interrupts!\n");
    printf("\n");
    printf("Time needed: 3-4 hours\n");
    printf("You crushed Day 1! Let's dominate Day 2!\n\n");
    
    return 0;
}