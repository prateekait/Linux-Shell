//Program to implement myshell

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<dirent.h>

#define PROMPT "krishna@myshell:$"

int main(int arg,char *argv[]){
  char *mycmd = NULL;
  
  char cmd[10], *arg1, *arg2, *path, *tmppath, *curpath;
  
  int read, i=0, pid, count, count1, in1, in2, j;
  unsigned int len;
  
  path = (char *)calloc(PATH_MAX, sizeof(char));
  curpath = (char *)calloc(PATH_MAX, sizeof(char));
  getcwd(path,500);
  
  while(1){
    printf(PROMPT);
    len = 0;
    mycmd = NULL;
    i = 0;
    in1 = 0;
    in2 = 0;
    count1 = 0;
    count = 0;
    arg1 = NULL;
    arg2 = NULL;

    //Read a new command in mycmd
    read = getline(&mycmd, &len, stdin);
    
    //Extract the arguments provided with the command
    while(mycmd[i] != ' ' && mycmd[i] != '\n')
      cmd[i]=mycmd[i++];
    cmd[i] = '\0';
    count++;
    in1 = i+1;
    while(i++ < len-1){
      if(mycmd[i] == ' ' || mycmd[i] == '\n')	  
	count++;	
      else
	count1++;
      if(arg1 == NULL && count == 2){
	arg1 = (char*)calloc(count1+1,sizeof(char));
	strncpy(arg1, mycmd+in1, count1);
	arg1[count1] = '\0';
	in2 = i+1;
	count1 = 0;
      }
      if(arg2 == NULL && count == 3){
	arg2 = (char*)calloc(count1+1, sizeof(char));
	strncpy(arg2, mycmd+in2, count1);
	arg2[count1] = '\0';
	count1 = 0;
      }
    }
    
    //myexit command
    if(strcmp(cmd, "myexit") == 0){
      printf("\n");
      return 0;
    }
    //mycd command
    else {
      if(strcmp(cmd, "mycd") == 0){
	if(arg1 == NULL || strlen(arg1) == 0)
	  //Change to home directory
	  chdir((char*)getenv("HOME"));
	else if(strcmp(arg1,"..") == 0){
	  for(j=strlen((char*)getcwd(curpath,PATH_MAX))-2;j>0;j--){
	    if(curpath[j] == '/')
	      break;
	  }
	  curpath[j]='\0';
	  chdir(curpath);
	}
	else			
	  chdir(arg1);			
      }
      else if((pid = fork()) == 0){
	//myls command
	if(strcmp(cmd, "myls") == 0){
	  tmppath = NULL;
	  tmppath = path;
	  strcat(tmppath, "/./myls.out");
	  execlp (tmppath, tmppath, arg1, (char *)NULL);
	  exit(0);
	}
	//mypwd command
	else if(strcmp(cmd, "mypwd") == 0){
	  tmppath = NULL;
	  tmppath = path;
	  strcat(tmppath, "/./mypwd.out");
	  execlp (tmppath, tmppath, (char *)NULL);
	  exit(0);
	}
	//mymkdir command
	else if(strcmp(cmd, "mymkdir") == 0){
	  tmppath = NULL;
	  tmppath = path;
	  
	  strcat(tmppath, "/./mymkdir.out");
	  if(arg1 == NULL)
	    printf("Invalid argument list\n");
	  else
	    execlp (tmppath, tmppath, arg1, (char *)NULL);
	  exit(0);
	}
	//myrm command
	else if(strcmp(cmd, "myrm") == 0){
	  tmppath = NULL;
	  tmppath = path;
	  strcat(tmppath, "/./myrm.out");
	  if(arg1 == NULL)
	    printf("Invalid argument list\n");
	  else
	    execlp (tmppath, tmppath, arg1, (char *)NULL);
	  exit(0);
	}
	//mymv command
	else if(strcmp(cmd, "mymv") == 0){
	  tmppath = NULL;
	  tmppath = path;
	  strcat(tmppath, "/./mymv.out");
	  if(arg1 == NULL || arg2 == NULL)
	    printf("Invalid argument list\n");
	  else
	    execlp (tmppath, tmppath, arg1, arg2, (char *)NULL);
	  exit(0);
	}
	//myps command
	else if(strcmp(cmd, "myps") == 0){
	  tmppath = NULL;
	  tmppath = path;
	  strcat(tmppath,"/./myps.out");
	  execlp (tmppath, tmppath, arg1, (char *)NULL);
	  exit(0);
	}
	//mytail command
	else if(strcmp(cmd, "mytail") == 0){
	  tmppath = NULL;
	  tmppath = path;
	  strcat(tmppath, "/./mytail.out");
	  if(arg1 == NULL || arg2 == NULL)
	    printf("Invalid argument list\n");
	  else
	    execlp (tmppath, tmppath, arg1, arg2, (char *)NULL);
	  exit(0);
	}
	
      }
      if(pid > 0)
	wait(pid,NULL);
      if(arg1 != NULL){
	free(arg1);
      }
      if(arg2 != NULL){	
	free(arg2);
      }
      free(mycmd);
    } 
  } 
  return 0;
}
