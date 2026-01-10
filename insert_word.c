#include "common.h"

// Insert a word into the inverted index
void insert_word(struct main_node*head[],int index,char* file_name,char word[])
{


    // If no word exists at this index, create first main node
    if(head[index]==NULL)
    {
        struct main_node*new_main=malloc(sizeof(struct main_node));
        struct sub_node*new_sub=malloc(sizeof(struct sub_node));
        strcpy( new_main->word,word);
        new_main->count_file=1;
        new_main->sub_link=new_sub;
        new_main->main_link=NULL; 
        new_sub->sub_link=NULL;
        strcpy(new_sub->file_name,file_name);
        new_sub->count_word=1;
        head[index]=new_main;
        return;
    }

    else if(head[index]!=NULL)
    {
        // Traverse main node list at this index
        struct main_node*temp=head[index];
        struct main_node*prev=NULL;
        int flag=0;


        while(temp)
        {
            // Check if word already exists
            if(strcmp(word,temp->word)==0)
            {
                flag=1;
                break;
            }
            prev=temp;
            temp=temp->main_link;
        }
        
        // Word not found: create new main node
        if(flag==0)
        {
            struct main_node*new_main=malloc(sizeof(struct main_node));
            struct sub_node*new_sub=malloc(sizeof(struct sub_node));
           
            strcpy(new_main->word,word);
            
            prev->main_link=new_main;
            new_main->count_file=1;
            new_main->sub_link=new_sub;
            new_main->main_link=NULL; 
            new_sub->sub_link=NULL;
            strcpy(new_sub->file_name,file_name);
            new_sub->count_word=1;

        }

        // Word found: update sub node list
        else if(flag==1)
        {
            struct sub_node*temp_sub=temp->sub_link;
            struct sub_node*temp_sub_prev=NULL;
            int flag_sub=0;

            // Check if file already exists for this word
            while(temp_sub)
            {
                if (strcmp(temp_sub->file_name,file_name)==0)
                {
                    flag_sub=1;
                    break;
                }
            temp_sub_prev=temp_sub;
            temp_sub=temp_sub->sub_link;
            }

            // File exists: increment word count
            if(flag_sub==1)
            {
            temp_sub->count_word= temp_sub->count_word+1;
            }

            // New file: add new sub node
            else
            {
            struct sub_node*new_sub=malloc(sizeof(struct sub_node));
            temp_sub_prev->sub_link=new_sub;
            temp->count_file=temp->count_file+1;
            new_sub->sub_link=NULL;
            strcpy(new_sub->file_name,file_name);
            new_sub->count_word=1;
            }
        }
    }
}