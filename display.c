#include "common.h"

// Display the entire inverted index database
void display_database (struct main_node*head[]){
    int  x = 0;

    // Traverse all hash indices
    for(int index=0; index<26; index++)
    {
        if(head[index]!=NULL){
            x=1;
            struct main_node*temp_main= head[index];
            struct sub_node*temp_sub=NULL;

            // Traverse main nodes at this index
            while(temp_main)
            {
                printf("[ %d ]  [ %s ]  %d FILE(S)\n",index,temp_main->word,temp_main->count_file);

                // Display file-wise word count
                temp_sub=temp_main->sub_link;
            while(temp_sub)
            {
                printf("FILE    :   %s  :   %d TIME(S)\n",temp_sub->file_name,temp_sub->count_word);
                temp_sub=temp_sub->sub_link;
            }
            printf("\n");
            temp_main=temp_main->main_link;
            }
            printf("--------------------------------------------------------------\n");
            printf("\n");
        }
    }
    // If database is empty
    if(!x) printf("DATA BASE IS EMPTY");
}
