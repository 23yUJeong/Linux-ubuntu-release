#ifndef __LINUX_PROJECT_H__
#define __LINUX_PROJECT_H__

#include <sys/types.h>

#define MAX_STR 100
#define BLOCK_COUNT 10

#define LOGDIR "./log"
#define LOGFILE "restart.txt"

typedef char* String;

typedef struct _swInfo
{
	String name;
	String restart_count;
	String start_time;
	String reason;
	int int_restart;
} swInfo;
typedef struct _swParam
{
	String SwBlock;
	String App_para1;
	String App_para2;
	String App_para3;
} swParam;
typedef struct _swInfoManager
{
	pid_t pids[BLOCK_COUNT];
	pid_t dpid;
	int p_no;
	swInfo sw_info[BLOCK_COUNT];
	swParam sw_param[BLOCK_COUNT];
} swManager;

void InitSwManager(swManager* info);
void readFileList(swManager* info);
void InitSWBlock(swManager* info);
void restartProcess(swManager* info, int index);
void LogInterface(swManager* info);
int FindIndex(swManager* info);

char* rtrim(const char* s);
char* ltrim(const char* s);
char* trim(const char* s);
char *gettime(void);
void LogWrite(swInfo* list);

#endif

