// Day 1: Understanding Memory and Pointers - The Foundation of Embedded Systems
// This is where embedded programming differs from regular programming

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Simulating embedded concepts on your regular computer
void demonstrate_memory_layout() {
    printf("=== Memory Layout Demonstration ===\n");
    
    // Stack variables (automatic storage)
    int stack_var = 100;
    char stack_array[10] = "Hello";
    
    // Heap allocation (dynamic storage)
    int *heap_var = malloc(sizeof(int));
    *heap_var = 200;
    
    // Print addresses to understand memory layout
    printf("Stack variable address: %p, value: %d\n", (void*)&stack_var, stack_var);
    printf("Stack array address: %p\n", (void*)stack_array);
    printf("Heap variable address: %p, value: %d\n", (void*)heap_var, *heap_var);
    
    // In embedded systems, you often work with specific memory addresses
    printf("\nIn embedded systems, you might access hardware registers like:\n");
    printf("GPIO_PORT_A = 0x40020000 (this would be a real hardware address)\n");
    
    free(heap_var);
}

void demonstrate_bit_operations() {
    printf("\n=== Bit Operations - Essential for Embedded ===\n");
    
    uint8_t control_register = 0x00; // Simulating a hardware register
    
    printf("Initial register value: 0x%02X\n", control_register);
    
    // Setting bits (turning ON)
    control_register |= (1 << 3); // Set bit 3
    printf("After setting bit 3: 0x%02X\n", control_register);
    
    // Clearing bits (turning OFF)
    control_register &= ~(1 << 1); // Clear bit 1
    printf("After clearing bit 1: 0x%02X\n", control_register);
    
    // Toggling bits
    control_register ^= (1 << 5); // Toggle bit 5
    printf("After toggling bit 5: 0x%02X\n", control_register);
    
    // Checking if a bit is set
    if (control_register & (1 << 3)) {
        printf("Bit 3 is SET\n");
    }
}

void demonstrate_pointers_and_hardware() {
    printf("\n=== Pointers and Hardware Access Simulation ===\n");
    
    // Simulating memory-mapped I/O (how embedded systems talk to hardware)
    uint32_t simulated_memory[10] = {0}; // Pretend this is hardware memory
    
    // Create pointers to simulate hardware registers
    volatile uint32_t *gpio_data_reg = &simulated_memory[0];
    volatile uint32_t *gpio_direction_reg = &simulated_memory[1];
    
    // Configure "GPIO" direction (1 = output, 0 = input)
    *gpio_direction_reg = 0xFF; // All pins as output
    
    // Write data to "GPIO" port
    *gpio_data_reg = 0xAA; // Alternating pattern
    
    printf("GPIO Direction Register: 0x%08X\n", *gpio_direction_reg);
    printf("GPIO Data Register: 0x%08X\n", *gpio_data_reg);
    
    printf("\nNote: In real embedded systems, these pointers would point to\n");
    printf("actual hardware register addresses like 0x40020000\n");
}

void basic_state_machine() {
    printf("\n=== Simple State Machine - Core of Many Embedded Systems ===\n");
    
    typedef enum {
        STATE_IDLE,
        STATE_WORKING,
        STATE_ERROR
    } system_state_t;
    
    system_state_t current_state = STATE_IDLE;
    int counter = 0;
    
    // Simulate a simple state machine
    for (int i = 0; i < 10; i++) {
        printf("Step %d: ", i);
        
        switch (current_state) {
            case STATE_IDLE:
                printf("IDLE -> ");
                if (counter > 2) {
                    current_state = STATE_WORKING;
                    printf("Switching to WORKING\n");
                } else {
                    printf("Staying in IDLE\n");
                }
                counter++;
                break;
                
            case STATE_WORKING:
                printf("WORKING -> ");
                if (counter > 7) {
                    current_state = STATE_ERROR;
                    printf("Error occurred!\n");
                } else {
                    printf("Processing...\n");
                }
                counter++;
                break;
                
            case STATE_ERROR:
                printf("ERROR -> Resetting system\n");
                current_state = STATE_IDLE;
                counter = 0;
                break;
        }
    }
}

int main() {
    printf("Welcome to Embedded Systems Learning - Day 1!\n");
    printf("===============================================\n");
    
    demonstrate_memory_layout();
    demonstrate_bit_operations();
    demonstrate_pointers_and_hardware();
    basic_state_machine();
    
    printf("\n=== Your Assignment for Today ===\n");
    printf("1. Compile and run this program\n");
    printf("2. Modify the bit operations to set multiple bits at once\n");
    printf("3. Add a new state to the state machine\n");
    printf("4. Read Chapter 1-2 of your OS book about process and memory management\n");
    
    return 0;
}

// Tomorrow we'll cover:
// - How operating systems manage processes
// - Introduction to interrupts and system calls
// - Setting up a real embedded development environment