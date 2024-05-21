#include "selforg.h"

Node *head = NULL;

void process_file(char *input_file, char *output_file);

int main(int argc , char *argv[]){

    if(argc != 3){
        printf("Incorrent amount of arguments passed");
        printf("\nUsage : run.exe <input_file> <outputfile>");
        exit(INCORRECT_USAGE);
    }
    
    process_file(argv[1],argv[2]);

}

void process_file(char *input_file, char *output_file){

    FILE *input , *output;

    input = fopen(input_file, "r");
    if(input == NULL){
        printf("Error reading file");
        exit(FILE_OPEN_FAILURE);
    }  
    
    output = fopen(output_file, "w");
    if(output == NULL){
        printf("Error writing to file ");
        exit(FILE_OPEN_FAILURE);
    }

    int num;
    while(fscanf(input , "%d" , &num) != EOF){
        Node *node = find(&head , num);
    if(node == NULL){
        insertatbegin(&head , num);
    }else{
        move_to_front(&head , node);
    }
    }

    write_to_file(head, output);
    


}
