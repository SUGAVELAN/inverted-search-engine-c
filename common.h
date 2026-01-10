#ifndef STR
#define STR

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Sub node: stores file-wise word count
struct sub_node{
    int count_word;
    char file_name[20];
    struct sub_node*sub_link;
};

// Main node: stores each unique word
struct main_node{
    char word[50];
    int count_file;
    struct sub_node*sub_link;
    struct main_node*main_link;
};

// File node: maintains list of input files
struct file_node{
    char file_name[20];
    struct file_node* file_link;
};

// Search result status
enum xx{
    WORD_FOUND =1,
    WORD_NOT_FOUND = -1
};


// Function declarations
void create_database(struct main_node*head[],struct file_node*file_head);
void insert_word(struct main_node*head[],int index,char* file_name,char word[]);
int file_verify(int total_files, char*file_name[],struct file_node**file_head_x,int flag);
int check_file(struct file_node**file_head_x,int f,char*file_name[]);
void display_database (struct main_node*head[]);
int search_word(struct main_node*head[],int index,char word[]);
void save(struct main_node*head[]);
#endif