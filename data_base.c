
#include"common.h"


// Create inverted index database from verified file list
void create_database(struct main_node*head[],struct file_node*file_head)
{
    // Traverse through each verified file
   struct file_node*temp_file=file_head;
   while(temp_file)
   {
    FILE*fp;
    fp= fopen(temp_file->file_name,"r");
    if(fp == NULL) 
    {
    // Skip file if it cannot be opened
    temp_file = temp_file->file_link;
    continue;
    }

    char ch;
    char word[50];
    int i=0;

        // Read file character by character
        while((ch=fgetc(fp))!=EOF)
        {
            if(ch!=' ' && ch!= '\n' )
            {
                word[i++]=ch;
            }
            else
            {
                if(i==0) continue;
                word[i]='\0';
                i=0;

                // Calculate index (case-insensitive)
                int index;
                if(word[0]>='a' && word[0]<='z')
                index = word[0]-'a';
                else
                index= word[0]-'A';

                insert_word(head,index,temp_file->file_name,word);
            }
        }

        // Handle last word if file doesn't end with space/newline
        if(i>0)
        {
            word[i]='\0';
            int index;
                if(word[0]>='a' && word[0]<='z')
                index = word[0]-'a';
                else
                index= word[0]-'A';
            insert_word(head,index,temp_file->file_name,word);
        }
        
        fclose(fp);
        temp_file=temp_file->file_link;
    }
    printf("\nDATA BASE CREATED SUCCESSFULLY\n");
}