#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "jrb.h"
#include "jval.h"

int main(int argc, char **argv)
{
  Jval jv;
  JRB t,tmp;
  IS is, is2,is3;
  int i;
  int parametre;
  if(strcmp(argv[1],"-d") == 0)
  {
    parametre = 1;
  }
  else if(strcmp(argv[1],"-e") == 0)
  {
    parametre = 2;
  }
  char *kilit[1000];
  
  for(i=0;i<1000;i++)
  {
    kilit[i] = NULL;
  }
  
  if (argc != 4) { fprintf(stderr, "Arguman kullanimi yanlis!\n"); exit(1); }
 

  is = new_inputstruct(".kilit");
  if (is == NULL) {
    perror("HATA:");
    exit(1);
  }
  
  t = make_jrb();

  int len = 0;
  char *acp;char *kapap;
  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
        acp = strchr(is->fields[i],'{');kapap = strchr(is->fields[i],'}');
        if(acp == NULL && kapap == NULL){
        kilit[len] = strdup(is->fields[i]);
        len++;
        }
    }
  }

//parsing kilit
  int x=0; int y=0;
  while(kilit[x] != NULL)
  {
    while(kilit[x][y] != '\0')
    {
      kilit[x][y] = kilit[x][y+1];
      y++;
    }
    x++;
    y=0;
  }
  x=0;y=0;
    while(kilit[x] != NULL)
  {
    while(kilit[x][y] != '\0')
    {
      if(kilit[x][y]=='"' || kilit[x][y]==':')
      {
        kilit[x][y]='\0';
      }
      if(kilit[x][y]==',' && kilit[x][y+1] == '\n')
      {
        kilit[x][y]='\0';
      }
      y++;
    }
    x++;
    y=0;
  }
//çift elemanlar kelime, tek elemanlar şifrelenmiş hal
int k=0;
switch (parametre)
{
case 1:

  k=0;
  while(k < len)
  {
  jrb_insert_str(t,kilit[k+1],new_jval_s((char *)kilit[k]));
  k+=2;
  }

  is2 = new_inputstruct(argv[2]);
  if (is2 == NULL) {
    perror("HATA:");
    exit(1);
  }
  
  FILE *fp;
  fp = fopen(argv[3],"w");
  
  while(get_line(is2) >= 0) {
    for (i = 0; i < is2->NF; i++) {
      tmp = jrb_find_str(t,is2->fields[i]);
      fprintf(fp,"%s ",tmp->val.s); 
    }
  }
  fclose(fp);
  jettison_inputstruct(is2);
  break;
case 2:
  
  k=0;
 while(k < len)
  {
  jrb_insert_str(t,kilit[k],new_jval_s((char *)kilit[k+1]));
  k+=2;
  }

  is3 = new_inputstruct(argv[2]);
  if (is3 == NULL) {
    perror("HATA:");
    exit(1);
  }
  
  FILE *fp2;
  fp2 = fopen(argv[3],"w");
  
  while(get_line(is3) >= 0) {
    for (i = 0; i < is3->NF; i++) {
      tmp = jrb_find_str(t,is3->fields[i]);
      fprintf(fp2,"%s ",tmp->val.s); 
    }
  }
  fclose(fp2);
  jettison_inputstruct(is3);
  break;

default:
  printf("%s\n", "Kabul edilen parametreler: -d -e");
  break;
}

  jettison_inputstruct(is);
  return 0;
}