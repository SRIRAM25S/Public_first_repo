// DAY 1: EMBEDDED SYSTEMS FOUNDATION
// Let's start your 60-day journey RIGHT NOW!
// Focus: Memory, Pointers, and Basic Embedded Concepts

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// ============================================================================
// PART 1: MEMORY BASICS - Understanding Stack and Heap
// ============================================================================

void part1_memory_basics() {
    printf("=== PART 1: MEMORY BASICS ===\n\n");
    
    // Stack variables - automatic, fast, limited
    int stack_var = 100;
    char stack_array[10] = "Hellosrira";
    
    // Heap variables - manual, slower, larger
    int *heap_var = (int *)malloc(sizeof(int));
    *heap_var = 200;
    
    printf("📊 Memory Addresses:\n");
    printf("Stack variable: %p (value: %d)\n", (void*)&stack_var, stack_var); // Address of stack_var = stack, value = 100
    printf("Stack array:    %p (value: %s)\n", (void*)stack_array, stack_array); // Address of stack_array = stack, value = "Hellosrira"
    printf("Heap variable:  %p (value: %d)\n", (void*)heap_var, *heap_var); // Address of heap_var = heap, value = 200
    
    // Clean up heap
    free(heap_var); //freeing the allocated memory to avoid memory leaks
    
    printf("\n✅ Key Concept: Stack is fast, Heap needs malloc/free\n\n");
}

// ============================================================================
// PART 2: POINTER FUNDAMENTALS - The Heart of Embedded Programming
// ============================================================================

void part2_pointer_basics() {
    printf("=== PART 2: POINTER FUNDAMENTALS ===\n\n");
    
    int value = 42;
    int *ptr = &value;  // ptr stores the ADDRESS of value
    
    printf("🔍 Understanding Pointers:\n");
    printf("Value:           %d\n", value); // value = 42
    printf("Address of value: %p\n", (void*)&value); // address of value
    printf("Pointer stores:   %p\n", (void*)ptr); // address
    printf("Pointer points to: %d\n", *ptr); // 42
    
    // Modify through pointer
    printf("Before changing the Value: %d\n", value); 
    *ptr = 99;
    printf("\nAfter *ptr = 99:\n");
    printf("Value is now:     %d\n", value); //99
    
    printf("\n✅ Key Concept: Pointers store memory addresses\n\n");
}

// ============================================================================
// PART 3: BIT OPERATIONS - Essential for Hardware Control
// ============================================================================

void part3_bit_operations() {
    printf("=== PART 3: BIT OPERATIONS ===\n\n");
    
    uint8_t register_value = 0x00;  // Start with all bits 0
    
    printf("🔧 Manipulating Hardware Registers:\n");
    printf("Initial value:        0x%04X (binary: ", register_value);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (register_value >> i) & 1);
    }
    printf(")\n");
    
    // Set bit 3 (turn ON)
    register_value |= (1 << 0);
    printf("After setting bit 3:  0x%02X\n", register_value);
    
    // Set bit 5
    register_value |= (1 << 5);
    printf("After setting bit 5:  0x%02X\n", register_value);
    
    // Clear bit 3 (turn OFF)
    register_value &= ~(1 << 3);
    printf("After clearing bit 3: 0x%02X\n", register_value);
    
    // Check if bit 5 is set
    if (register_value & (1 << 5)) {
        printf("Bit 5 is SET ✓\n");
    }
    
    printf("\n✅ Key Concept: Bit operations control hardware pins\n\n");
}

// ============================================================================
// PART 4: MEMORY-MAPPED I/O - How Embedded Systems Talk to Hardware
// ============================================================================

void part4_memory_mapped_io() {
    printf("=== PART 4: MEMORY-MAPPED I/O SIMULATION ===\n\n");
    
    // Simulate hardware registers
    uint32_t hardware_memory[5] = {0};
    
    // Create pointers to simulate hardware registers
    volatile uint32_t *GPIO_DATA = &hardware_memory[0];
    volatile uint32_t *GPIO_DIR = &hardware_memory[1];
    volatile uint32_t *GPIO_ENABLE = &hardware_memory[2];
    
    printf("🎛️ Controlling Hardware Through Memory:\n");
    
    // Configure GPIO as output
    *GPIO_DIR = 0xFF;  // All pins as output
    printf("GPIO Direction set: 0x%08X\n", *GPIO_DIR);
    
    // Enable GPIO
    *GPIO_ENABLE = 0x01;
    printf("GPIO Enabled:       0x%08X\n", *GPIO_ENABLE);
    
    // Write data to GPIO
    *GPIO_DATA = 0xAA;  // Alternating pattern
    printf("GPIO Data written:  0x%08X\n", *GPIO_DATA);
    
    printf("\n💡 In Real Hardware:\n");
    printf("GPIO_DATA would be at address like 0x40020000\n");
    printf("Writing to this address controls actual pins!\n");
    
    printf("\n✅ Key Concept: Pointers to specific addresses control hardware\n\n");
}

// ============================================================================
// PART 5: STATE MACHINES - Core Pattern in Embedded Systems
// ============================================================================

void part5_state_machine() {
    printf("=== PART 5: STATE MACHINE BASICS ===\n\n");
    
    typedef enum {
        STATE_INIT,
        STATE_IDLE,
        STATE_ACTIVE,
        STATE_MAINTAINANCE,
        STATE_ERROR
    } SystemState;
    
    SystemState current_state = STATE_INIT;
    int counter = 0;
    
    printf("🔄 State Machine Simulation:\n\n");
    
    for (int step = 0; step < 12; step++) {
        printf("Step %2d | State: ", step);
        
        switch (current_state) {
            case STATE_INIT:
                printf("INIT    -> ");
                current_state = STATE_IDLE;
                printf("Moving to IDLE\n");
                break;
                
            case STATE_IDLE:
                printf("IDLE    -> ");
                if (counter >= 3) {
                    current_state = STATE_ACTIVE;
                    printf("Counter reached 3, going ACTIVE\n");
                } else {
                    printf("Waiting (counter: %d)\n", counter);
                }
                counter++;
                break;
                
            case STATE_ACTIVE:
                printf("ACTIVE  -> ");
                if (counter >= 8) {
                    current_state = STATE_ERROR;
                    printf("Counter too high! ERROR\n");
                } else {
                    printf("Processing (counter: %d)\n", counter);
                }
                counter++;
                break;
                
            case STATE_MAINTAINANCE:
                printf("MAINTAINANCE -> ");
                printf("Performing maintenance tasks\n");
                current_state = STATE_IDLE;
                break;

            case STATE_ERROR:
                printf("ERROR   -> ");
                printf("Resetting system\n");
                current_state = STATE_MAINTAINANCE;
                counter = 0;
                break;
        }
    }
    
    printf("\n✅ Key Concept: State machines manage system behavior\n\n");
}

// ============================================================================
// DAY 1 PRACTICAL EXERCISES
// ============================================================================

void day1_exercises() {
    printf("=== DAY 1 PRACTICAL EXERCISES ===\n\n");
    
    printf("📝 YOUR TASKS:\n\n");
    
    printf("EXERCISE 1: Bit Operations\n");
    printf("---------------------------------------------------------------\n");
    printf("Task: Set bits 0, 2, and 4 simultaneously in one operation\n");
    printf("Hint: Use OR operation with a mask\n");
    printf("Answer format: register |= 0x??;\n\n");

    uint32_t register_value = 0x00;
    register_value |= (1<<0) | (1<<2) | (1<<4);

    printf("Register Value after setting bits %2X \n\n", register_value);
    
    printf("EXERCISE 2: Pointer Arithmetic\n");
    printf("---------------------------------------------------------------\n");
    printf("Task: Create an array and access elements using pointer arithmetic\n");
    printf("Hint: ptr + 1 moves to next element\n\n");

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("Values of arr are :");
    int i=0;
   while(i < 10){
        
         *arr = *(arr + i);
          printf("%d ",*arr);
         i++;
      
   }
    
    printf("\nEXERCISE 3: State Machine Extension\n");
    printf("---------------------------------------------------------------\n");
    printf("Task: Add a MAINTENANCE state that runs between ERROR and IDLE\n");
    printf("Hint: ERROR -> MAINTENANCE -> IDLE\n\n");

    
    typedef enum {
        STATE_INIT,
        STATE_IDLE,
        STATE_ACTIVE,
        STATE_MAINTAINANCE,
        STATE_ERROR
    } SystemState;
    
    SystemState current_state = STATE_INIT;
    int counter = 0;
    
    printf("🔄 State Machine Simulation:\n\n");
    
    for (int step = 0; step < 12; step++) {
        printf("Step %2d | State: ", step);
        
        switch (current_state) {
            case STATE_INIT:
                printf("INIT    -> ");
                current_state = STATE_IDLE;
                printf("Moving to IDLE\n");
                break;
                
            case STATE_IDLE:
                printf("IDLE    -> ");
                if (counter >= 3) {
                    current_state = STATE_ACTIVE;
                    printf("Counter reached 3, going ACTIVE\n");
                } else {
                    printf("Waiting (counter: %d)\n", counter);
                }
                counter++;
                break;
                
            case STATE_ACTIVE:
                printf("ACTIVE  -> ");
                if (counter >= 8) {
                    current_state = STATE_ERROR;
                    printf("Counter too high! ERROR\n");
                } else {
                    printf("Processing (counter: %d)\n", counter);
                }
                counter++;
                break;
                
            case STATE_MAINTAINANCE:
                printf("MAINTAINANCE -> ");
                printf("Performing maintenance tasks\n");
                current_state = STATE_IDLE;
                break;

            case STATE_ERROR:
                printf("ERROR   -> ");
                printf("Resetting system\n");
                current_state = STATE_MAINTAINANCE;
                counter = 0;
                break;
        }
    }

    
    printf("EXERCISE 4: Memory Allocation\n");
    printf("---------------------------------------------------------------\n");
    printf("Task: Allocate array on heap, fill with values, print, then free\n");
    printf("Hint: Use malloc, for loop, printf, free\n\n");

    typedef struct{
    short day;
    char month; 
    short year;
    }Date;

    Date *T1 = malloc(sizeof(Date));
    Date *T2 = calloc(20, sizeof(Date));

    T1 -> day = 19;
    T1 -> month = 12;   
    T1 -> year = 2021;
    printf("T1 ==> %02i - %02i - %04i \n", T1->day, T1->month, T1 -> year);
    free(T1);
}
// ============================================================================
// MAIN - Your Day 1 Journey Starts Here!
// ============================================================================

int main() {
    printf("\n");
    printf("============================================\n");
    printf("||     🚀 DAY 1: EMBEDDED SYSTEMS FOUNDATION 🚀          ||\n");
    printf("||     Your 60-Day Journey to Embedded Excellence        ||\n");
    printf("===================================================\n");
    printf("\n");
    
    // Run all parts
    // part1_memory_basics();
    // part2_pointer_basics();
    // part3_bit_operations();
    // part4_memory_mapped_io();
    // part5_state_machine();
    day1_exercises();
    
    printf("============================================\n");
    printf("||              📚 DAY 1 SUMMARY                         ||\n");
    printf("============================================\n");
    printf("||  ✅ Memory: Stack vs Heap                             ||\n");
    printf("||  ✅ Pointers: Address manipulation                    ||\n");
    printf("||  ✅ Bit Ops: Hardware control                         ||\n");
    printf("||  ✅ Memory-mapped I/O: Controlling hardware           ||\n");
    printf("||  ✅ State Machines: System behavior                   ||\n");
    printf("============================================\n");
    printf("\n");
    
    printf("🎯 NEXT STEPS:\n");
    printf("1. Save this as 'day1_foundation.c'\n");
    printf("2. Compile: gcc -o day1 day1_foundation.c\n");
    printf("3. Run: ./day1\n");
    printf("4. Complete the 4 exercises\n");
    printf("5. Read your OS book: Memory Management chapter\n");
    printf("6. Tomorrow: Advanced pointers and linked lists!\n");
    printf("\n");
    printf("⏰ Total time needed today: 3-4 hours\n");
    printf("💪 You've got this! Let's make it happen!\n\n");
    
    return 0;
}