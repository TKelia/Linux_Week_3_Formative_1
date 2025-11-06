#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LEN 1024
#define MAX_PATH_LEN 512

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_elf_file>\n", argv[0]);
        return 1;
    }

    char *elf_path = argv[1];
    char output_file[MAX_PATH_LEN];

    // Generate output file name
    snprintf(output_file, sizeof(output_file), "%s.txt", elf_path);

    // Prepare the objdump command
    char command[MAX_COMMAND_LEN];
    snprintf(command, sizeof(command),
             "objdump -d --section=.text %s > %s",
             elf_path, output_file);

    // Run the command
    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error: Failed to execute objdump command.\n");
        return 1;
    }

    printf("Disassembled code saved to: %s\n", output_file);
    return 0;
}
