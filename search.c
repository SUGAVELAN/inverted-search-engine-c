#include"common.h"

// Search a word in the database using hash index
int search_word(struct main_node*head[],int index,char word[])
{
    struct main_node*temp_main= head[index];
    struct sub_node*temp_sub=NULL;

     // Traverse main nodes at given index
    while(temp_main){
        if(strcmp(temp_main->word,word)==0)
        {
            printf("[ %d ]  [ %s ]  %d FILE(S)\n",index,word,temp_main->count_file);

            // Display file-wise occurrence
            temp_sub=temp_main->sub_link;
            while(temp_sub){
                printf("FILE    :   %s  :   %d TIME(S)\n",temp_sub->file_name,temp_sub->count_word);
                temp_sub=temp_sub->sub_link;
            }
            return WORD_FOUND;
        }
        else{
            temp_main=temp_main->main_link;
        }
    }

    return WORD_NOT_FOUND;
}


