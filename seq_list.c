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



int main(void)
{
    seq_list_t seq_list;
    return 0;
}