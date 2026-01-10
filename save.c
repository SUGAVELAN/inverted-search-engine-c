#include"common.h"

// Save the inverted index database into a text file
void save(struct main_node*head[]){
    FILE*fptr=NULL;
    fptr=fopen("DATABASE.txt","w");
    if(fptr == NULL)
    {
    printf("ERROR: UNABLE TO CREATE FILE\n");
    return;
    }


    // Traverse all hash indices
    for(int index=0; index<26; index++){
        if(head[index]!=NULL){
    
            struct main_node*temp_main= head[index];
            struct sub_node*temp_sub=NULL;
            // Write main and sub node data to file
            while(temp_main)
            {
                fprintf(fptr,"[ %d ]  [ %s ]  %d FILE(S)\n",index,temp_main->word,temp_main->count_file);

                  temp_sub=temp_main->sub_link;
            while(temp_sub)
            {
                fprintf(fptr,"FILE    :   %s  :   %d TIME(S)\n",temp_sub->file_name,temp_sub->count_word);
                temp_sub=temp_sub->sub_link;
            }
            fprintf(fptr,"\n");
            temp_main=temp_main->main_link;
            }
            fprintf(fptr,"-------------------------------------------------------------------------------------");
            fprintf(fptr,"\n");
        }
    }
    fclose(fptr);

    printf("DATA SAVED SUCCESSFULLY\n");

}