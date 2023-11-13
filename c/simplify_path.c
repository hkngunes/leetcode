#include "stdio.h"
#include "stdlib.h"

const char* simplifyPath(const char * path){
  int size_path=0,i_p=0,i_r=0;
  char* res;
  while(path[size_path] != '\0') size_path++;
  res = (char*)malloc(size_path+1);
  res[i_r++]='/';
  while(path[i_p] != '\0'){
    if(path[i_p] == '/'){
      while(path[i_p]=='/') i_p++;
      continue;
    }

    if(path[i_p] == '.' && path[i_p+1] == '/'){
      i_p += 2;
      continue;
    }

    if(path[i_p] == '.' && path[i_p+1] == '\0'){
      i_p += 1;
      continue;
    }
    
    if(path[i_p] == '.' && path[i_p+1] == '.' && path[i_p+2] == '/'){
      i_p+=3;
      if(i_r == 1){
	continue;
      }
      while(res[i_r-2] != '/') i_r--;
      i_r--;
      continue;
    }

    if(path[i_p] == '.' && path[i_p+1] == '.' && path[i_p+2] == '\0'){
      i_p += 2;
      if(i_r == 1){
	continue;
      }
      while(res[i_r-2] != '/') i_r--;
      i_r--;
      continue;
    }

    while(path[i_p] != '\0' && path[i_p] != '/'){
      res[i_r++] = path[i_p++];
    }
    if(path[i_p] == '/'){
      res[i_r++] = '/';
    }

  }
  if(i_r != 1 && res[i_r-1] == '/'){
    i_r--;
  }
  res[i_r]='\0';
  return res;
}

void testSP(){
  const char* path = "/";
  path = "/a//b////c/d//././/../";
  printf("%s : %s\n", path, simplifyPath(path));
  path = "/a/b/../c/";
  printf("%s : %s\n", path, simplifyPath(path));
}

int main(){
  testSP();
  return 0;
}
