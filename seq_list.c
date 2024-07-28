/*
数据结构：
        1.线性结构
            (1)顺序表
                    借助数据元素在存储器中的相对位置来表示数据元素的逻辑关系 
            (2)链表 单链表  双链表  单向循环链表 双向循环链表
            (3)如何在工程中和内核中使用链表
        2.树形结构
        3.网状结构
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEQ_LIST_INIT_LEN           8

#define INSERT_BACK                 1
#define INSERT_FRONT                2
#define DELETE_BACK                 3
#define DELETE_FRONT                4
#define INSERT_POS                  5
#define DELETE_POS                  6
#define MODIFY_POS                  7
#define SHOW_LIST                   8
#define FIND                        9
#define CUR_LENGTH                  10
#define CLEAR_LIST                  11
#define DESTORY_LIST                12
#define SORT                        13
#define REVERSE_LIST                14
#define EXIT_SYSTEM                 15


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct
{
    int user_id;
    char user_name[20];
    char user_email[20];
    int user_grade;
}element_t;

typedef struct
{
    element_t *base;
    int seq_list_tot_len;
    int seq_list_cur_len;
}seq_list_t;

void seq_list_init(seq_list_t *seq_list);
void insert_back(seq_list_t *seq_list, element_t *element);
void insert_front(seq_list_t *seq_list, element_t *element);
void show_list(seq_list_t *seq_list);
int main(void)
{
    seq_list_t seq_list;
    seq_list_init(&seq_list);
    u32 opera = 0;
    element_t element;
    while(1)
    {
        printf("-------------------------------------\n");
        printf("| Seq_List Operation:               |\n");
        printf("-------------------------------------\n");
        printf("| (1) insert_back   (2)insert_front |\n");
        printf("| (3) delete_back   (4)delete_front |\n");
        printf("| (5) insert_pos    (6)delete_pos   |\n");
        printf("| (7) modify_pos    (8)show_list    |\n");
        printf("| (9) find          (10)cur_length  |\n");
        printf("| (11) clear_list   (12)destroy_list|\n");
        printf("| (13) sort         (14)reverse_list|\n");
        printf("| (15) exit_system                  |\n");
        printf("-------------------------------------\n");
        printf("Please enter the operation you want:>");
        scanf("%d", &opera);
        switch(opera)
        {
            case INSERT_BACK:
                printf("(Insert back)Please enter user's name email and grade:");
                scanf("%s %s %d", element.user_name, element.user_email, &element.user_grade);
                insert_back(&seq_list, &element);
                break;
            case INSERT_FRONT:
                printf("(Insert front)Please enter user's name email and grade:");
                scanf("%s %s %d", element.user_name, element.user_email, &element.user_grade);
                insert_front(&seq_list, &element);
                break;
            case DELETE_BACK:
                break;
            case DELETE_FRONT:
                break;
            case INSERT_POS:
                break;
            case DELETE_POS:
                break;
            case MODIFY_POS:
                break;
            case SHOW_LIST:
                show_list(&seq_list);
                break;
            case FIND:
                break;
            case CUR_LENGTH:
                break;
            case CLEAR_LIST:
                break;
            case DESTORY_LIST:
                break;
            case SORT:
                break;
            case REVERSE_LIST:
                break;
            case EXIT_SYSTEM:
                break;
            default:
                printf("Please enter 0-14\n\n\n");
                break;
        }
    }
    return 0;
}


void seq_list_init(seq_list_t *seq_list)
{
    seq_list->base = (element_t *)malloc(sizeof(element_t) * SEQ_LIST_INIT_LEN);
    if(NULL == seq_list->base)
    {
        printf("malloc error\n");
        exit(0);
    }
    seq_list->seq_list_cur_len = 0;
    seq_list->seq_list_tot_len = 8;
}   /* seq_list_init() */


void insert_back(seq_list_t *seq_list, element_t *element)
{
    if(seq_list->seq_list_cur_len == seq_list->seq_list_tot_len)
    {
        printf("SQL is full\n");
        return;
    }
    memcpy((seq_list->base + seq_list->seq_list_cur_len)->user_name, element->user_name, 20);
    memcpy((seq_list->base + seq_list->seq_list_cur_len)->user_email, element->user_email, 20);
    (seq_list->base + seq_list->seq_list_cur_len)->user_grade = element->user_grade;
    (seq_list->base + seq_list->seq_list_cur_len)->user_id = seq_list->seq_list_cur_len+1;
    seq_list->seq_list_cur_len++;
    
}   /* insert_back() */


void insert_front(seq_list_t *seq_list, element_t *element)
{
    u32 i = 0;
    if(seq_list->seq_list_cur_len == seq_list->seq_list_tot_len)
    {
        printf("SQL is full\n");
        return;
    }


    for(i = seq_list->seq_list_cur_len; i > 0; i--)
    {
        memcpy((seq_list->base + i), (seq_list->base + i - 1), sizeof(element_t));
    }
    memcpy(seq_list->base->user_name, element->user_name, 20);
    memcpy(seq_list->base->user_email, element->user_email, 20);
    seq_list->base->user_grade = element->user_grade;
    seq_list->base->user_id = seq_list->seq_list_cur_len+1;
    seq_list->seq_list_cur_len++;
}   /* insert_front() */


void show_list(seq_list_t *seq_list)
{
    u32 i = 0;

    printf("------------------------------------------------------------------\n");
    printf("| User information table                                         |\n");
    printf("------------------------------------------------------------------\n");
    printf("| User ID|           User name|         User E-mail|  User grade||\n");
    for(i = 0; i < seq_list->seq_list_cur_len; i++)
    {
        printf("|%8d|%20s|%20s|%12d||\n", seq_list->base[i].user_id, seq_list->base[i].user_name, 
                                         seq_list->base[i].user_email, seq_list->base[i].user_grade);
    }
    printf("------------------------------------------------------------------\n");
}   /* show_list() */