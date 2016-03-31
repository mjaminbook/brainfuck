#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_ARRAY_SIZE 30000
#define BF_FILE_INDEX 1
#define BF_ARGS_INDEX 2

unsigned char* dataArray;
int dataPointer;
FILE* fp;
unsigned char* bfInput;
int inputPointer;
int inputSize;
//TODO: Make sure that once dataPointer exceeds max that it returns to zero, or that once it reaches below zero that it returns to the max

void processCommand(char command){
	if(command == '<'){
		dataPointer--;
	}
	else if(command == '>'){
		dataPointer++;
	}
	else if(command == '+'){
		dataArray[dataPointer]++;
	}
	else if(command == '-'){
		dataArray[dataPointer]--;
	}
	else if(command == '.'){
		printf("%c", dataArray[dataPointer]);
	}
	else if(command == ','){
		if(inputPointer >= inputSize){
			exit(1);
		}

		dataArray[dataPointer] = bfInput[inputPointer];
		inputPointer++;
	}
	else if(command == '['){
		if(dataArray[dataPointer] == 0){
			int loopCounter = 0;
			while(1){ //TODO: Fix the loop!
				if(command == '['){
					loopCounter++;
				}
				else if(command == ']'){
					loopCounter--;
				}

				if(loopCounter == 0){
					return;
				}

				command = fgetc(fp);
			}
		}
	}
	else if(command == ']'){
		if(dataArray[dataPointer] != 0){
			int loopCounter = 0;
			fseek(fp, -(sizeof(char)), SEEK_CUR); //Because the pointer is one ahead right now from fgetc
			while(1){
				if(command == ']'){
					loopCounter++;
				}
				else if(command == '['){
					loopCounter--;
				}
				if(loopCounter == 0){
					return;
				}
				fseek(fp, -(sizeof(char)), SEEK_CUR);
				command = fgetc(fp);
				fseek(fp, -(sizeof(char)), SEEK_CUR);
			}
		}	
	}
}

//Note: For input, you must have any input with spaces contained within quotation marks
int main(int argc, char** argv){
	fp = fopen(argv[BF_FILE_INDEX], "r");
	if (fp == NULL){
		printf("%s does not exist", argv[BF_FILE_INDEX]);
		return(1);
	}
	if(argc > BF_ARGS_INDEX){
		bfInput = argv[BF_ARGS_INDEX];
		inputPointer = 0;
		inputSize = strlen(bfInput);
	}

	dataArray = malloc(DATA_ARRAY_SIZE * sizeof(char));
	dataPointer = 0;
	memset(dataArray, 0, DATA_ARRAY_SIZE);
	char command;
	//TODO: Add error handling for invalid file pointers
	while((command = fgetc(fp)) != EOF){
		processCommand(command);
	}
	printf("\n");
}
