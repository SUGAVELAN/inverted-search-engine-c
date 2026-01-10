#include "common.h"

// Verify a single file and add it to file list if valid
int check_file(struct file_node**file_head_x,int f,char*file_name[])
{
    struct file_node*file_head= *file_head_x;


         // Check whether file exists
        FILE*fp=NULL;
        fp=fopen(file_name[f],"r");
        if(fp==NULL)
        {
            printf("%s IS NOT VALID FILE\n",file_name[f]);
            return 0;
        }

         // Check whether file is empty
        char ch=fgetc(fp);
        if(ch==EOF)
        {
            printf("%s FILE IS EMPTY\n",file_name[f]);
            fclose(fp);
            return 1;
        }
        fclose(fp);


        // If file list is empty, add first file node
        if(file_head==NULL)
        {
           struct file_node*new_file_node=malloc(sizeof(struct file_node));
           strcpy(new_file_node->file_name,file_name[f]);
           new_file_node->file_link=NULL;
           *file_head_x = new_file_node;
            return 1;
         
        }


        else
        {
            // Check for duplicate file names
            struct file_node*temp_h = file_head;
            struct file_node*prev=NULL;
            int flag =0;
            while(temp_h)
            {
               if(strcmp(temp_h->file_name,file_name[f])==0)
               {
                flag=1;
                break;
               }
               else
               {
                    prev=temp_h;
                    temp_h= temp_h->file_link;
               }  
            }

             // Add new file if not duplicated
            if(flag==0)
            {
                struct file_node*new_file_node=malloc(sizeof(struct file_node));
                strcpy(new_file_node->file_name,file_name[f]);
                new_file_node->file_link=NULL;
                prev->file_link = new_file_node;
                
            }
            else if(flag==1)
            {
                printf("%s FILE IS DUPLICATED - SKIPPED\n", file_name[f]);
            }

        }
        return 1;
}




// Verify input files for CREATE or UPDATE operation
int file_verify(int total_files, char*file_name[],struct file_node**file_head_x,int flag){

    int x=1;

     // Flag 0 : verify files passed during CREATE
    if(flag==0){ 
    for(int f=1;f<total_files;f++)
    {
        if(x)
        x=check_file(file_head_x,f,file_name);
    }
   
    }

     // Flag 1 : verify single file during UPDATE
    else if(flag==1)
    {
         x =  check_file(file_head_x,0,file_name);
    }
    return x;

}