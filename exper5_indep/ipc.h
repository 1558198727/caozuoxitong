#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define BUFSZ   256
#define MAXVAL   100
#define STRSIZ   8
#define WRITERQUEST  1 //д�����ʶ
#define READERQUEST  2 //�������ʶ
#define FINISHED  3 //��д��ɱ�ʶ

/*�źŵƿ����õĹ�ͬ��*/
typedef union semuns {
    int val;
    } Sem_uns;

/* ��Ϣ�ṹ��*/
typedef struct msgbuf {
    long mtype;
    int  mid;
    } Msg_buf;


//�ź���
key_t costomer_key;
int costomer_sem;
key_t account_key;
int account_sem;

int sem_val;
int sem_flg;

//��Ϣ����
int wait_quest_flg;
key_t wait_quest_key;
int wait_quest_id;
int wait_respond_flg;
key_t wait_respond_key;
int wait_respond_id;

int sofa_quest_flg;
key_t sofa_quest_key;
int sofa_quest_id;
int sofa_respond_flg;
key_t sofa_respond_key;
int sofa_respond_id;

int get_ipc_id(char *proc_file,key_t key);
char *set_shm(key_t shm_key,int shm_num,int shm_flag);
int set_msq(key_t msq_key,int msq_flag);
int set_sem(key_t sem_key,int sem_val,int sem_flag);
int down(int sem_id);
int up(int sem_id);