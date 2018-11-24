//
// Created by arch0n on 18-11-20.
//

#include "arObserver.h"


#define VMRSS_LINE 17
#define VMSIZE_LINE 13

arObserver::arObserver() {
    pid = getpid();
    assert(pid != -1);
}

int arObserver::get_proc_mem(){

    char file_name[64]={0};
    FILE *fd;
    char line_buff[512]={0};
    sprintf(file_name,"/proc/%d/status", pid);

    fd =fopen(file_name,"r");
    if(nullptr == fd){
        return 0;
    }

    char name[64];
    int vmrss;
    for (int i=0; i<VMRSS_LINE-1;i++){
        fgets(line_buff,sizeof(line_buff),fd);
    }

    fgets(line_buff,sizeof(line_buff),fd);
    sscanf(line_buff,"%s %d",name,&vmrss);
    fclose(fd);

    return vmrss;
}

int arObserver::get_proc_virtualmem(){
    char file_name[64];
    FILE *fd;
    char line_buff[512];
    sprintf(file_name,"/proc/%d/status",pid);

    fd =fopen(file_name,"r");
    if(nullptr == fd){
        return 0;
    }

    char name[64];
    int vmsize;
    for (int i=0; i<VMSIZE_LINE-1;i++){
        fgets(line_buff,sizeof(line_buff),fd);
    }

    fgets(line_buff,sizeof(line_buff),fd);
    sscanf(line_buff,"%s %d",name,&vmsize);
    fclose(fd);

    return vmsize;
}
