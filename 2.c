#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool even(int n){
    if(n%2 == 0 && n!=1){
        return true;
    }else{
        return false;
    }
}
int main(){
    char *input = (char *)malloc(sizeof(char)*+1);
    int *process = (int *)malloc(sizeof(int)*+1);
    printf("\033[1mChallenge\033[m: Write a function that takes in a list of integers and returns the sum of all even numbers in the list.\n");
    printf("Use ',' to separate numbers.\n");
    printf(">>> ");
    scanf("%99[^\n]s", input);
    for(int i=0; i<(char)strlen(input); i++){
        if((int)input[i] == 32){
    /*         ^
      Gets char type input and turns into int,
      therefore turning the char input into 
      its ASCII value.      
    */
            printf("[x] Do not use spaces.");
            return 0;
        }
    }
    int alc = 0;
    char *getitems = strtok(input, ",");
    /*                  ^
        Function strtok splits string using delimiter. In this case ','.
    */
    while(getitems != NULL){
        if(even(atoi(getitems))){
            process[alc++] = atoi(getitems);
        }
    /*               ^          ^-----------
    by using external integer variable      |
    'alc', it adds +1 bytes to the          |
    dynamic malloc process pointer          |
       -------------------------------------
    function atoi is used to turn char
    data types into integer. 
    char *getitems -> int *getitems  
    */
        getitems = strtok(NULL, ",");
    }
    free(input);
    int holdsum=0;
    for(int j=0;j<alc;j++){
            if(holdsum != 0){
                holdsum = holdsum+process[j];
            }else{
                holdsum=process[j];
        }
        
    }
    printf("\nSumming Result: %d\n",holdsum);
    /*
    free function. used to free allocated memory
    after use.
    */
    /*
    Cannot use 'free(process)' because it will output 'munmap_chunk(): invalid pointer'
    or 'double free or corruption(out)' on big numbers.
    */
    return 0;
}