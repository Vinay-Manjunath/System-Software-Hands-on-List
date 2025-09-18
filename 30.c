/*
============================================================================
Name        : 30_daemon_script.c
Author      : M Vinay
Date        : 05-09-2025
Description :
    C program to create a Daemon process that runs a script at a
    specific time (HH:MM). The daemon keeps running in the background,
    checking the time every 10 seconds, and executes the script at the
    given time. The output of the script is redirected to the log file.
============================================================================
Sample Output (05-09-2025):
$ cc 30.c
$ ./a.out 13:28 /root/hands_on_list1/1.sh /root/hands_on_list1/log.txt &
[1] 1417

$ cat log.txt
test_file
test_file_hrdlink
test_file_sftlink
Daemon triggered script at 13:28
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc,char *argv[]){
	if(argc!=4){
		fprintf(stderr,"Usage: %s <HH:MM> <script_path> <log_file>\n",argv[0]);
		exit(1);
	}

	int thr,tmin;
	sscanf(argv[1],"%d:%d",&thr,&tmin);

	char *script=argv[2];
	char *logfile=argv[3];

	pid_t pid=fork();

	if(pid<0){
		fprintf(stderr,"Fork failed\n");
		exit(1);
	}
	if(pid>0){
		exit(0);
	}

	if(setsid()<0) exit(1);
	if(chdir("/")<0) exit(1);

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while(1){
		time_t now=time(NULL);
		struct tm *t=localtime(&now);

		if(t->tm_hour==thr && t->tm_min==tmin){
			char cmd[512];
			snprintf(cmd,sizeof(cmd),"%s>>%s 2>&1",script,logfile);
			system(cmd);

			FILE *f=fopen(logfile,"a");
			if(f){
				fprintf(f,"Daemon triggered script at %02d:%02d\n",thr,tmin);
				fclose(f);
			}
			sleep(60);
		}
		sleep(10);
	}
	return 0;
}


