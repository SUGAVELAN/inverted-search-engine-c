
#include "common.h"


int main(int total_files,char*file_name[]){

    //CHECK FILES ARE PASSED THROUGH CLA
    if(total_files==1){
        printf("ERROR : NO ARGUMENTS PASSED THROUGH COMMAND LINE\n");
        return 0;
    }

    struct file_node*file_head_x=NULL;
    
    //FILE VERIFICATION
    int x = file_verify(total_files,file_name,&file_head_x,0);
    if(!x) return 0;

    //HEAD[26] IS THE HASH TABLE IT STORES ADDRESS OF MAIN_NODE
    struct main_node*head[26]={NULL};
    int choice;
    int db_created = 0;

    while(1)
    {
    printf("1. CREATE  DATA BASE\n");
    printf("2. DISPLAY DATA BASE\n");
    printf("3. SEARCH  DATA BASE\n");
    printf("4. UPDATE  DATA BASE\n");
    printf("5. SAVE\n");
    printf("6. EXIT\n");

    printf("--------------------------------------------------------------\n");
    printf("\n");
    printf("ENTER YOUR OPTION: ");
    scanf("%d",&choice);


    switch(choice)
    {

        // ---------------- CREATE DATABASE ----------------
        case 1:
                if(db_created)
                    printf("DATABASE ALREADY CREATED\n");
                else 
                {
                    create_database(head, file_head_x);        //CALL CREATE_DATABASE() fun.

                    db_created = 1;
                    printf("--------------------------------------------------------------\n");
                    printf("\n");
                }
            break;


        // ---------------- DISPLAY DATABASE ----------------
        case 2:
                
                if (!db_created)
                {
                    printf("DATABASE NOT CREATED YET\n");
                    break;
                }

                display_database(head);                            //CALL DISPALY_DATABASE() fun.

                printf("--------------------------------------------------------------\n");
                printf("\n");
            break;

         // ---------------- SEARCH WORD ----------------
        case 3:
        {
                if (!db_created)
                {
                    printf("DATABASE NOT CREATED YET\n");
                    break;
                }

                char word[20];
                printf("ENTER THE WORD YOU WANT TO  SEARCH : ");
                scanf("%19s",word);

                int index;
                if(word[0]>='a' && word[0]<='z')
                index = word[0]-'a';
                else
                index= word[0]-'A';

                if(search_word(head,index,word)==WORD_NOT_FOUND)       //CALL SEARCH_WORD() fun.
                printf("\nWORD_NOT_FOUND\n");

                printf("--------------------------------------------------------------\n");
                printf("\n");
                break;
        }

        // ---------------- UPDATE DATABASE ----------------
        case 4:
        {

                if (!db_created)
                {
                    printf("CREATE DATABASE FIRST\n");
                    break;
                }

                char *update_list[1];            //CREATING A TEMPORARY FILE_NAME LIST
                char update_file_name[20];       //CHAR ARRAY USED TO READ FILE_NAME
                printf("ENTER THE FILE NAME ");
                scanf("%19s",update_file_name);   

                update_list[0]=update_file_name;      //CONNECT FILE_NAME TO ARRAY

                //VERIFY AND ADD NEW FILE
                file_verify(1,update_list,&file_head_x,1);

                //TRAVERSE TO LAST FILE NODE AND UPDATE
                struct file_node*temp = file_head_x;
                while(temp->file_link)
                {
                    temp=temp->file_link;
                }


                create_database(head, temp);

                printf("--------------------------------------------------------------\n");
                printf("\n");
                break;
        }

        // ---------------- SAVE DATABASE ----------------
        case 5:
              if (!db_created)
                {
                    printf("DATABASE NOT CREATED YET\n");
                    break;
                }

                save(head);         //CALL SAVE() fun.
                printf("--------------------------------------------------------------\n");
                printf("\n");
               break;

         // ---------------- EXIT ----------------
        case 6:
               return 0;
        default:
            printf("INVALID OPTION\n");

    }
}
}