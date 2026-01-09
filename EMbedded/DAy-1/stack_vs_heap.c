// DEEP DIVE: Stack vs Heap - Technical Details
// Answering your fundamental questions about memory management

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// ============================================================================
// QUESTION 1: What is the difference between Stack and Heap?
// ============================================================================

void explain_stack_vs_heap_difference() {
    printf("=== STACK vs HEAP: FUNDAMENTAL DIFFERENCES ===\n\n");
    
    printf("🔹 STACK:\n");
    printf("- LIFO (Last In, First Out) data structure\n");
    printf("- Managed automatically by CPU hardware\n");
    printf("- Variables created in function scope\n");
    printf("- Very fast allocation/deallocation\n");
    printf("- Limited size (typically 1MB-8MB on desktop, 2KB-8KB embedded)\n");
    printf("- No fragmentation\n");
    printf("- Automatic cleanup when scope ends\n\n");
    
    printf("🔹 HEAP:\n");
    printf("- Unstructured memory pool\n");
    printf("- Managed by operating system/runtime\n");
    printf("- Variables created with malloc/new\n");
    printf("- Slower allocation (requires OS calls)\n");
    printf("- Large size (can use most available RAM)\n");
    printf("- Can get fragmented over time\n");
    printf("- Manual cleanup required\n\n");
    
    // Visual representation
    printf("MEMORY LAYOUT:\n");
    printf("┌─────────────────┐ ← High Memory (0xFFFFFFFF)\n");
    printf("│  STACK REGION   │ ← Fixed size region in RAM\n");
    printf("│  (grows down)   │ ← Each function call adds frame\n");
    printf("├─────────────────┤\n");
    printf("│   UNUSED RAM    │ ← Available for heap expansion\n");
    printf("├─────────────────┤\n");
    printf("│  HEAP REGION    │ ← Dynamic allocation area\n");
    printf("│  (grows up)     │ ← malloc/free manages this\n");
    printf("├─────────────────┤\n");
    printf("│ GLOBAL/STATIC   │ ← Global variables\n");
    printf("├─────────────────┤\n");
    printf("│ PROGRAM CODE    │ ← Your compiled program\n");
    printf("└─────────────────┘ ← Low Memory (0x00000000)\n\n");
}

// ============================================================================
// QUESTION 2: Why is Stack fast? What is the limited space?
// ============================================================================

void explain_stack_speed_and_limits() {
    printf("=== WHY STACK IS FAST & LIMITED ===\n\n");
    
    printf("🚀 WHY STACK IS FAST:\n");
    printf("1. CPU has dedicated STACK POINTER register (SP)\n");
    printf("2. Allocation = just move SP by a few bytes\n");
    printf("3. Deallocation = just move SP back\n");
    printf("4. No searching for free memory blocks\n");
    printf("5. No OS system calls needed\n");
    printf("6. Hardware-optimized operations\n\n");
    
    // Demonstrate stack pointer concept
    printf("📊 STACK POINTER DEMONSTRATION:\n");
    int a = 10;  // SP moves down by 4 bytes
    int b = 20;  // SP moves down by 4 more bytes
    int c = 30;  // SP moves down by 4 more bytes
    
    printf("Variable addresses (showing stack growth):\n");
    printf("a (first):  %p\n", (void*)&a);
    printf("b (second): %p\n", (void*)&b);
    printf("c (third):  %p\n", (void*)&c);
    
    // Calculate stack growth direction
    if (&c < &b) {
        printf("→ Stack grows DOWNWARD (toward lower addresses)\n");
        printf("→ Each variable allocation moves stack pointer down\n");
    }
    
    printf("\n💾 STACK SIZE LIMITS:\n");
    printf("SYSTEM          TYPICAL STACK SIZE\n");
    printf("────────────────────────────────────\n");
    printf("Desktop Linux   8 MB (8,388,608 bytes)\n");
    printf("Desktop Windows 1 MB (1,048,576 bytes)\n");
    printf("Arduino Uno     2 KB (2,048 bytes) ⚠️\n");
    printf("STM32F4         4 KB (4,096 bytes) ⚠️\n");
    printf("FPB-RA4E2       8 KB (8,192 bytes) ⚠️\n\n");
    
    printf("⚠️  EMBEDDED REALITY:\n");
    printf("- Your entire RAM might be only 32KB!\n");
    printf("- Stack is pre-allocated region in RAM\n");
    printf("- NOT related to datatype size\n");
    printf("- Stack overflow = program crash!\n\n");
}

// ============================================================================
// QUESTION 3: How does compiler handle stack? How is data destroyed?
// ============================================================================

void explain_compiler_stack_management() {
    printf("=== HOW COMPILER MANAGES STACK ===\n\n");
    
    printf("🔧 COMPILER'S STACK MANAGEMENT:\n");
    printf("1. Function entry: Compiler generates code to:\n");
    printf("   - Save current stack pointer\n");
    printf("   - Move stack pointer to allocate space\n");
    printf("   - Store local variables in allocated space\n\n");
    
    printf("2. Function exit: Compiler generates code to:\n");
    printf("   - Restore previous stack pointer\n");
    printf("   - Return control to caller\n");
    printf("   - Local variables become 'garbage'\n\n");
    
    // Demonstrate with function calls
    printf("📋 STACK FRAME DEMONSTRATION:\n");
    
    void inner_function() {
        int inner_var = 999;
        printf("  Inside inner_function:\n");
        printf("  inner_var address: %p\n", (void*)&inner_var);
        printf("  Stack pointer moved further down\n");
    }
    
    int outer_var = 555;
    printf("In main function:\n");
    printf("outer_var address: %p\n", (void*)&outer_var);
    printf("Calling inner_function...\n");
    
    inner_function();
    
    printf("Back in main function\n");
    printf("inner_var is now DESTROYED (memory reusable)\n\n");
    
    printf("🗑️ HOW DATA GETS 'DESTROYED':\n");
    printf("- NO actual deletion happens!\n");
    printf("- Stack pointer just moves back\n");
    printf("- Memory becomes available for reuse\n");
    printf("- Old data might still be there temporarily\n");
    printf("- But it's considered 'garbage' and will be overwritten\n\n");
}

// ============================================================================
// QUESTION 4: Why is Heap slower? How does free() work?
// ============================================================================

void explain_heap_performance() {
    printf("=== WHY HEAP IS SLOWER & HOW FREE() WORKS ===\n\n");
    
    printf("🐌 WHY HEAP IS SLOWER:\n");
    printf("1. malloc() must SEARCH for free memory block\n");
    printf("2. Must track allocated/free regions (metadata)\n");
    printf("3. Requires system calls to OS\n");
    printf("4. May need to defragment memory\n");
    printf("5. Thread synchronization overhead\n");
    printf("6. More complex algorithms vs simple pointer arithmetic\n\n");
    
    // Performance comparison
    printf("⏱️ PERFORMANCE COMPARISON:\n");
    clock_t start, end;
    
    // Stack allocation speed test
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        int stack_var = i;  // Stack allocation
        (void)stack_var;    // Prevent optimization
    }
    end = clock();
    double stack_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Heap allocation speed test
    start = clock();
    for (int i = 0; i < 1000; i++) {  // Note: fewer iterations!
        int *heap_var = malloc(sizeof(int));  // Heap allocation
        if (heap_var) {
            *heap_var = i;
            free(heap_var);
        }
    }
    end = clock();
    double heap_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Stack operations: %.6f seconds (1M operations)\n", stack_time);
    printf("Heap operations:  %.6f seconds (1K operations)\n", heap_time);
    printf("Heap is roughly %.0fx SLOWER!\n\n", (heap_time * 1000) / stack_time);
    
    printf("🧹 HOW free() WORKS:\n");
    printf("1. Takes pointer to previously malloc'd memory\n");
    printf("2. Finds metadata block (stored before your data)\n");
    printf("3. Marks memory block as 'free' in internal lists\n");
    printf("4. May coalesce (merge) with adjacent free blocks\n");
    printf("5. Does NOT zero out the memory!\n");
    printf("6. Memory becomes available for future malloc()\n\n");
    
    // Demonstrate heap metadata
    printf("💾 HEAP MEMORY STRUCTURE:\n");
    int *heap_demo = malloc(sizeof(int));
    *heap_demo = 12345;
    
    printf("Your pointer:     %p\n", (void*)heap_demo);
    printf("Your data:        %d\n", *heap_demo);
    printf("Metadata is stored BEFORE your pointer (invisible to you)\n");
    
    free(heap_demo);
    printf("After free(): memory marked as available, data might still be there!\n\n");
}

// ============================================================================
// QUESTION 5: Why %p and void*?
// ============================================================================

void explain_pointer_formatting() {
    printf("=== WHY %p AND void* FOR ADDRESSES ===\n\n");
    
    printf("🔍 WHY %p FORMAT SPECIFIER:\n");
    printf("- %p is specifically for POINTER addresses\n");
    printf("- Prints in hexadecimal format (0x...)\n");
    printf("- Platform-independent way to print addresses\n");
    printf("- Handles different pointer sizes (32-bit vs 64-bit)\n\n");
    
    printf("🔄 WHY void* CAST:\n");
    printf("- printf() expects void* for %p format\n");
    printf("- void* is 'generic pointer type'\n");
    printf("- Any pointer type can be cast to void*\n");
    printf("- Avoids compiler warnings\n\n");
    
    // Demonstrate different ways to print addresses
    int test_var = 42;
    int *ptr_to_test = &test_var;
    
    printf("📋 ADDRESS PRINTING EXAMPLES:\n");
    printf("Using %%p with void* cast: %p\n", (void*)&test_var);
    printf("Using %%p with pointer:    %p\n", (void*)ptr_to_test);
    
    // Show what happens without proper casting (may cause warnings)
    printf("Direct address (may warn): %p\n", (void*)(uintptr_t)&test_var);
    
    printf("\n💡 MEMORY ADDRESS FACTS:\n");
    printf("- 32-bit systems: addresses are 4 bytes (0x00000000 to 0xFFFFFFFF)\n");
    printf("- 64-bit systems: addresses are 8 bytes (0x0000000000000000 to 0xFFFFFFFFFFFFFFFF)\n");
    printf("- Hexadecimal is used because it maps nicely to binary\n");
    printf("- Each hex digit = 4 bits\n\n");
}

int main() {
    printf("🧠 MEMORY MANAGEMENT DEEP DIVE\n");
    printf("===============================\n\n");
    
    explain_stack_vs_heap_difference();
    explain_stack_speed_and_limits();
    explain_compiler_stack_management();
    explain_heap_performance();
    explain_pointer_formatting();
    
    printf("🎓 KEY INSIGHTS:\n");
    printf("1. Stack = Hardware-assisted, LIFO, automatic\n");
    printf("2. Heap = Software-managed, complex, manual\n");
    printf("3. Stack size is fixed RAM region, not datatype-related\n");
    printf("4. Compiler generates stack management code automatically\n");
    printf("5. free() doesn't erase data, just marks as available\n");
    printf("6. %%p and void* are the standard way to print addresses\n\n");
    
    printf("🔥 NOW YOU UNDERSTAND MEMORY AT THE DEEPEST LEVEL!\n");
    
    return 0;
}