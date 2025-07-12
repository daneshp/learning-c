#include <stdio.h>
#include <stdint.h>

// Function to check system endianness
void check_endianness() {
    uint32_t test = 0x12345678;
    uint8_t *byte_ptr = (uint8_t *)&test;
    
    printf("=== System Endianness Check ===\n");
    printf("32-bit value: 0x%08X\n", test);
    printf("Byte layout in memory:\n");
    printf("Address  | Byte Value\n");
    printf("---------|----------\n");
    
    for (int i = 0; i < 4; i++) {
        printf("byte[%d]  | 0x%02X\n", i, byte_ptr[i]);
    }
    
    if (byte_ptr[0] == 0x78) {
        printf("\nThis system is LITTLE-ENDIAN\n");
        printf("(Least significant byte stored first)\n");
    } else if (byte_ptr[0] == 0x12) {
        printf("\nThis system is BIG-ENDIAN\n");
        printf("(Most significant byte stored first)\n");
    }
    printf("\n");
}

int main() {
    printf("ENDIANNESS DEMONSTRATION PROGRAM\n");
    printf("This is auto generated code i have not written\n");
    printf("==================================\n\n");
    
    check_endianness();
    
    printf("Key Takeaways:\n");
    printf("- Endianness affects how multi-byte values are stored in memory\n");
    printf("- it refers to the order in which bytes are stored in memory when representing multi byte data types");
    printf("- Most x86/x64 systems are little-endian\n");
    printf("- Network protocols typically use big-endian ('network byte order')\n");
    printf("- Always be aware of endianness when working with binary data\n");
    
    return 0;
}