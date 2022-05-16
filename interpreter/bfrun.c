#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MEM_SIZE 30000

bool valid(char c) {
	char* valid_characters = "<>,.[]+-";
	char* current;
	for(current = valid_characters; *current != '\0'; current++) {
		if(c == *current) {return true;}
	}
	return false;
}

int main(int argc, char** argv) {

	bool integer_option = false;

	if(argc < 2 || argc > 3) {
		printf("Usage: bfrun [output_option] <file>\n");
		return -1;
	}

	int i;
	for(i = 1; i < argc; i++) {
		if(!strcmp(argv[i], "-n")) {integer_option = true;}
	}

	char* filename = argv[argc - 1];

	FILE* fp;
	if((fp = fopen(filename, "r")) == NULL) {
		printf("Unable to open file '%s'\n", filename);
		return -1;
	}

	int size;
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	rewind(fp);

	char* code = calloc(1, size + 1);

	char c;
	int index = 0;
	do {
		c = fgetc(fp);
		if(valid(c)) {	
			code[index] = c;
			index++;
		}

	}while(c != EOF);

	code = realloc(code, index + 2);
	code[index + 1] = '\0';
	fclose(fp);

	unsigned char arr[MEM_SIZE] = {0};

	char* instruction;
	unsigned char* memory_pointer = arr;
	int open_loop = 0;
	int close_loop = 0;
	for(instruction = code; *instruction != '\0'; instruction++) {
		switch(*instruction) {
			case '>':
				memory_pointer++;
				break;
			case '<':
				memory_pointer--;
				break;
			case '+':
				(*memory_pointer)++;
				break;
			case '-':
				(*memory_pointer)--;
				break;
			case '.':
				if(integer_option) {printf("%d", *memory_pointer);}
				else {printf("%c", *memory_pointer);}
				break;
			case ',':
				scanf("%hhd", memory_pointer);
				break;
			case '[':
				if(!*memory_pointer) {open_loop = 1;}
				while(open_loop) {
					instruction++;
					if(*instruction == '[') {open_loop++;}
					else if(*instruction == ']') {open_loop--;}
				}
				break;
			case ']':
				if(*memory_pointer) {close_loop = 1;}
				while(close_loop) {
					instruction--;
					if(*instruction == '[') {close_loop--;}
					else if(*instruction == ']') {close_loop++;}
				}
				break;
			default:
				break;
		}
	}

	free(code);
	
	return 0;
}