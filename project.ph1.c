#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <dirent.h>
struct undo
{
  char *prev;
  char file[250];
};
struct undo add[200];
char *infi(char *asl, char *last, long long index)
{
  for (long long i = index; i < strlen(asl); i++)
  {
    *(last + (i - index)) = *(asl + i);
  }
  return last;
}
long long removee(char *address, long long ent, long long charr, long long si, long long fb)
{
  // printf("%lld",fb);
  long long n = 0;
  FILE *file;
  file = fopen(address, "r");
  if (file == NULL)
  {
    fclose(file);
    return 0;
  }
  fseek(file, 0, SEEK_END);
  long long len = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *stringg = (char *)calloc(sizeof(char), (len + 1));
  char *first = (char *)calloc(sizeof(char), (len + 1));
  char *last = (char *)calloc(sizeof(char), (len + 1));
  char c;
  long long i = 0, bb = 0, cc = 0;
  while ((c = fgetc(file)) != EOF)
  {
    *(stringg + i) = c;
    i++;
  }
  *(stringg + i) = '\0';
  long long index = 0;
  // printf("%d",strlen(stringg));

  for (long long i = 0; i < strlen(stringg); i++)
  {
    if (ent == n)
    {
      bb = index;
      break;
    }

    if (*(stringg + i) == '\n')
    {
      n++;
    }
    //*(first+i)=*(stringg+i);
    index++;
  }
  if (ent > n)
  {
    printf("\nout of index!!\n");
    return 1;
  }

  index = 0;

  for (long long i = bb; i < strlen(stringg) + 10; i++)
  {

    // printf("\n\t%lld  %d",index+bb,strlen(stringg));

    if (*(stringg + (i)) == '\0' || *(stringg + (i)) == '\n')
    {
      printf("\nout of index!!!\n");
      return 1;
    }

    if (index == charr)
    {
      cc = index;
      break;
    }
    index++;
  }
  if ((cc + bb) + si >= strlen(stringg))
  {
    printf("\nout of index!!!\n");
    return 1;
  }

  if (fb == (-1))
  {
    for (long long i = 0; i < (cc + bb) - si; i++)
    {
      *(first + i) = *(stringg + i);
    }
    last = infi(stringg, last, (cc + bb));
  }
  else
  {
    for (long long i = 0; i < (cc + bb); i++)
    {
      *(first + i) = *(stringg + i);
    }
    last = infi(stringg, last, (cc + bb) + si);
  }
  strcat(first, last);
  file = fopen(address, "w");
  fprintf(file, "%s", first);
  fclose(file);
  return 2;
}
long long posedit1(char *poss, long long a)
{
  a = atoll((poss));

  return a;
}
long long posedit2(char *poss, long long b)
{
  long long i = 0;
  for (i = 0; i < strlen(poss); i++)
  {
    if (*(poss + i) == ':')
    {
      break;
    }
  }
  i++;
  b = atoll(poss + i);
  return b;
}

char *parda13(char *thisone)
{
  // printf("%s\n", thisone);
  char *newtr;
  newtr = (char *)calloc(strlen(thisone), sizeof(char));
  if (*(thisone + 0) == '"' && *(thisone + (strlen(thisone) - 1)) == '"')
  {
    for (long long i = 0; i < strlen(thisone) - 2; i++)
    {
      *(newtr + i) = *(thisone + (i + 1));
    }
  }
  else
  {
    long long o = 0;
    for (long long i = 0; i < strlen(thisone); i++)
    {
      if (*(thisone + i) != ' ')
      {
        *(newtr + o) = *(thisone + i);
        o++;
      }
    }
  }
  return newtr;
}
char *pishins(char *entr)
{

  char *newtr = (char *)calloc(sizeof(char), strlen(entr));
  if (*(entr + 0) == '"' && *(entr + (strlen(entr) - 1)) == '"')
  {
    for (long long i = 0; i < strlen(entr) - 2; i++)
    {
      *(newtr + i) = *(entr + (i + 1));
    }
  }
  else
  {
    long long o = 0;
    for (long long i = 0; i < strlen(entr); i++)
    {
      if (*(entr + i) != ' ')
      {
        *(newtr + o) = *(entr + i);
        o++;
      }
    }
  }
  char *last = (char *)calloc(strlen(newtr), sizeof(char));
  long long h = 0;
  for (long long i = 0; i < strlen(newtr); i++)
  {
    if (*(newtr + (i - 1)) != '\\' && *(newtr + i) == '\\' && *(newtr + (i + 1)) == 'n')
    {
      *(last + h) = '\n';
      h++;
      i++;
      continue;
    }
    else if (*(newtr + (i)) == '\\' && *(newtr + (i + 1)) == '\\' && *(newtr + (i + 2)) == 'n')
    {
      *(last + h) = '\\';
      h++;
      i++;
      continue;
    }
    else
    {
      *(last + h) = *(newtr + i);
      h++;
      continue;
    }
  }
  return last;
}

long long insert(char *address, long long ent, long long charr, char *thisstring)
{
  // printf("add %s        enter %lld          char %lld       thisstring %s",address,ent,charr,thisstring);
  long long n = 0;
  FILE *file;
  file = fopen(address, "r");
  if (file == NULL)
  {
    fclose(file);
    return 0;
  }
  fseek(file, 0, SEEK_END);
  long long len = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *stringg = (char *)calloc(sizeof(char), (len + 1));
  char *first = (char *)calloc(sizeof(char), (len + 1));
  char *last = (char *)calloc(sizeof(char), (len + 1));
  char c;
  long long i = 0, bb = 0, cc = 0;
  while ((c = fgetc(file)) != EOF)
  {
    *(stringg + i) = c;
    i++;
  }
  *(stringg + i) = '\0';
  long long index = 0;
  // printf("%d",strlen(stringg));

  for (long long i = 0; i < strlen(stringg); i++)
  {
    if (ent == n)
    {
      bb = index;
      break;
    }

    if (*(stringg + i) == '\n')
    {
      n++;
    }
    *(first + i) = *(stringg + i);
    index++;
  }
  if (ent > n)
  {
    printf("\nout of index!!\n");
    return 1;
  }

  index = 0;

  for (long long i = bb; i < strlen(stringg) + 10; i++)
  {

    // printf("\n\t%lld  %d",index+bb,strlen(stringg));
    if (index + bb == strlen(stringg))
    {
      file = fopen(address, "a");
      fprintf(file, "%s", thisstring);
      fclose(file);
      return 2;
    }
    if ((*(stringg + (i)) == '\0' || *(stringg + (i)) == '\n') && *(stringg + (i + 2)) == '\0' || *(stringg + (i + 2)) == '\n')
    {

      printf("\nout of index!!!\n");
      fclose(file);
      return 1;
    }

    if (index == charr)
    {
      cc = index;
      break;
    }
    index++;
    *(first + i) = *(stringg + i);
  }

  last = infi(stringg, last, cc + bb);

  strcat(first, thisstring);
  strcat(first, last);
  // printf("\n\t%s",first);
  //
  file = fopen(address, "w");
  fprintf(file, "%s", first);
  fclose(file);
  return 2;
}
long long insertrepl(char *address, long long ent, long long charr, char *thisstring)
{
  // printf("add %s        enter %lld          char %lld       thisstring %s",address,ent,charr,thisstring);
  long long n = 0;
  FILE *file;
  file = fopen(address, "r");
  if (file == NULL)
  {
    fclose(file);
    return 0;
  }
  fseek(file, 0, SEEK_END);
  long long len = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *stringg = (char *)calloc(sizeof(char), (len + 1));
  char *first = (char *)calloc(sizeof(char), (len + 1));
  char *last = (char *)calloc(sizeof(char), (len + 1));
  char c;
  long long i = 0, bb = 0, cc = 0;
  while ((c = fgetc(file)) != EOF)
  {
    *(stringg + i) = c;
    i++;
  }
  *(stringg + i) = '\0';
  long long index = 0;
  // printf("%d",strlen(stringg));

  for (long long i = 0; i < strlen(stringg); i++)
  {
    if (ent == n)
    {
      bb = index;
      break;
    }

    if (*(stringg + i) == '\n')
    {
      n++;
    }
    *(first + i) = *(stringg + i);
    index++;
  }
  if (ent > n)
  {
    printf("\nout of index!!\n");
    return 1;
  }

  index = 0;

  for (long long i = bb; i < strlen(stringg) + 10; i++)
  {

    // printf("\n\t%lld  %d",index+bb,strlen(stringg));
    if (index + bb == strlen(stringg))
    {
      file = fopen(address, "a");
      fprintf(file, "%s", thisstring);
      fclose(file);
      return 2;
    }

    if (index == charr)
    {
      cc = index;
      break;
    }
    index++;
    *(first + i) = *(stringg + i);
  }

  last = infi(stringg, last, cc + bb);

  strcat(first, thisstring);
  strcat(first, last);
  // printf("\n\t%s",first);
  //
  file = fopen(address, "w");
  fprintf(file, "%s", first);
  fclose(file);
  return 2;
}
char *cat(char *filename)
{
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL)
  {
    fclose(file);
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  long long len = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *stringg = (char *)malloc(sizeof(char) * (len + 1));
  char c;
  long long i = 0;
  while ((c = fgetc(file)) != EOF)
  {
    *(stringg + i) = c;
    i++;
  }
  *(stringg + i) = '\0';
  fclose(file);
  return stringg;
}
long long compare(char *inyki, char *oonyki)
{
  FILE *fp;
  char *str = (char *)calloc(1000000, sizeof(char));
  FILE *fp1;
  char *str1 = (char *)calloc(10000000, sizeof(char));

  fp = fopen(inyki, "r");
  fp1 = fopen(oonyki, "r");
  if (fp == NULL)
  {
    printf("Error opening file");
    fclose(fp);
    fclose(fp1);
    return 1;
  }
  if (fp1 == NULL)
  {
    printf("Error opening file");
    fclose(fp);
    fclose(fp1);
    return 1;
  }
  fseek(fp, 0, SEEK_END);
  long long len = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  fseek(fp1, 0, SEEK_END);
  long long len1 = ftell(fp1);
  fseek(fp1, 0, SEEK_SET);
  long long yk = 0;
  long long doo = 0;
  while (fgets(str, len, fp) != NULL)
  {
    yk++;
  }
  while (fgets(str1, len1, fp1) != NULL)
  {
    doo++;
  }
  fclose(fp);
  fclose(fp1);
  fp = fopen(inyki, "r");
  fp1 = fopen(oonyki, "r");
  while (fgets(str1, len1, fp1) != NULL && fgets(str, len, fp) != NULL)
  {
    if (strcmp(str, str1) != 0)
    {
      printf("first file: %s\nsecond file: %s\n", str, str1);
    }
  }
  if (yk >= doo)
  {
    while (fgets(str, len, fp) != NULL)
    {
      printf("first file: %s\n", str);
    }
  }
  else
  {
    while ((str1, len1, fp1) != NULL)
    {
      printf("second file: %s\n", str1);
    }
  }
  fclose(fp);
  fclose(fp1);

  return 2;
}
long long creatfile(char *input)
{
  char *input1 = NULL;
  input1 = (char *)calloc(102, sizeof(char));
  printf("%s\n", input);
  FILE *creat;
  creat = fopen(input, "r");
  if (creat != NULL)
  {
    printf("\nalready exists\n");
    fclose(creat);
    return;
  }

  for (long long i = 0; input != '\0' && i < 103; i++)
  {
    if (*(input + i) == '/')
    {
      mkdir(input1);
    }
    *(input1 + i) = *(input + i);
  }
  creat = fopen(input1, "w");
  printf("\nDone!\n");
  fclose(creat);
}
long long copy(char *address, long long ent, long long charr, long long si, long long fb, char *saving)
{

  long long n = 0;
  FILE *file;
  file = fopen(address, "r");
  if (file == NULL)
  {
    fclose(file);
    return 0;
  }
  fseek(file, 0, SEEK_END);
  long long len = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *stringg = (char *)calloc(sizeof(char), (len + 1));
  char *first = (char *)calloc(sizeof(char), (len + 1));
  char *last = (char *)calloc(sizeof(char), (len + 1));
  char c;
  long long i = 0, bb = 0, cc = 0;
  while ((c = fgetc(file)) != EOF)
  {
    *(stringg + i) = c;
    i++;
  }
  *(stringg + i) = '\0';
  long long index = 0;
  // printf("%d",strlen(stringg));

  for (long long i = 0; i < strlen(stringg); i++)
  {
    if (ent == n)
    {
      bb = index;
      break;
    }

    if (*(stringg + i) == '\n')
    {
      n++;
    }
    //*(first+i)=*(stringg+i);
    index++;
  }
  if (ent > n)
  {
    printf("\nout of index!!\n");
    return 1;
  }

  index = 0;

  for (long long i = bb; i < strlen(stringg) + 10; i++)
  {

    // printf("\n\t%lld  %d",index+bb,strlen(stringg));

    if (*(stringg + (i)) == '\0' || *(stringg + (i)) == '\n')
    {
      printf("\nout of index!!!\n");
      return 1;
    }

    if (index == charr)
    {
      cc = index;
      break;
    }
    index++;
  }
  if ((cc + bb) + si >= strlen(stringg))
  {
    printf("\nout of index!!!\n");
    return 1;
  }

  if (fb == (-1))
  {
    for (long long i = 0; i < (cc + bb) - si; i++)
    {
      *(first + i) = *(stringg + i);
    }

    for (long long i = (cc + bb) - si; i < (cc + bb); i++)
    {
      *(saving + (i - (cc + bb) + si)) = *(stringg + i);
    }
  }
  else
  {
    for (long long i = 0; i < (cc + bb); i++)
    {
      *(first + i) = *(stringg + i);
    }
    for (long long i = (cc + bb); i < (cc + bb) + si; i++)
    {
      *(saving + (i - (cc + bb))) = *(stringg + i);
    }
  }
  return 2;
}
long long byword(char *stri, long long index)
{
  long long word = 0;
  for (long long i = 0; i <= index; i++)
  {
    if (*(stri + i) == ' ' || *(stri + i) == '\n')
    {
      if (*(stri + (i + 1)) != ' ' || *(stri + (i + 1)) != '\n')
      {
        word++;
      }
    }
  }
  return word;
}
long long fsade(char *add, char *text, char *qb, char *qb1, long long at, int boooll)
{ // printf("%s,%s",qb,qb1);
  char *komaki = (char *)calloc(sizeof(char), 2);

  // printf("%s",komaki);
  *(komaki + 0) = '#';

  if (qb == NULL)
  {
    qb = komaki;
  }
  if (qb1 == NULL)
  {
    qb1 = komaki;
  }

  long long *res;
  long long resss = 0;
  // printf("*%s*\t*%s*\t*%s*\t*%s*\t*%lld*",add,text,qb,qb1,at);
  long long b = 0;
  long long count = 0;
  char *mohtv = cat(add);
  if (mohtv == NULL)
  {
    printf("Error opening file");
    return 1;
  }

  for (long long i = 0; i < strlen(mohtv); i++)
  {
    char *tike = (char *)calloc((strlen(text) + 1), sizeof(char));
    for (long long ii = 0; ii < strlen(text); ii++)
    {
      *(tike + ii) = *(mohtv + (ii + i));

      if (strcmp(text, tike) == 0)
      {
        count++;
        if (qb == komaki && qb1 == komaki)
        {
          printf("%lld\n", i);
          b++;
          return 1;
        }
        if ((strcmp(qb, "byword") == 0) && qb1 == komaki)
        {
          printf("%lld\n", byword(mohtv, i));
          b++;
          return 1;
        }
        if ((strcmp(qb, "all") == 0) && qb1 == komaki)
        {
          if (boooll == 0)
          {
            printf("%lld\n", i);
            b++;
            continue;
          }
        }
        if ((strcmp(qb, "all") == 0) && (strcmp(qb1, "byword") == 0))
        {
          printf("%lld\n", byword(mohtv, i));
          b++;
          continue;
        }

        // printf("%s\n",qb);
        if ((strcmp(qb, "at") == 0) && qb1 == komaki)
        {

          if (count == at)
          {
            if (boooll == 0)
            {
              printf("%lld\n", i);
              b++;
            }
            else
            {
              b++;
              return i;
            }
          }

          else
          {
            continue;
          }
        }
        if ((strcmp(qb, "at") == 0) && (strcmp(qb1, "byword") == 0))
        {
          if (count == at)
          {
            printf("%lld\n", byword(mohtv, i));
            b++;
            return 1;
          }
        }
      }
    }
  }
  // printf("%lld,%lld",count,at);

  if ((strcmp(qb, "at") == 0) && at > count)
  {
    if ((boooll == 0))
    {
      printf("-1");
      return -1;
    }
    else
    {
      b++;
      return -2;
    }
  }
  if ((strcmp(qb, "count") == 0) && qb1 == komaki)
  {
    printf("%lld\n", count);
    b++;
    return 1;
  }
  else if ((strcmp(qb, "count") == 0) || (strcmp(qb, "at") == 0 && strcmp(qb1, "all") == 0) || (strcmp(qb1, "at") == 0 && strcmp(qb, "all") == 0))
  {
    printf("Wrong entries\n");
    return -1;
  }
  if (b == 0)
  {
    printf("Not found\n");
    return -1;
  }

  return b;
}
long long fstrebd(char *add, char *text, char *qb, char *qb1, long long at, int boooll)
{
  // printf("*%s*",qb);
  char *komaki = (char *)calloc(sizeof(char), 2);
  *(komaki + 0) = '^';
  if (qb == NULL)
  {
    qb = komaki;
  }
  if (qb1 == NULL)
  {
    qb1 = komaki;
  }
  long long *res;
  long long resss = 0;

  long long b = 0;
  char *mohtv = cat(add);
  if (mohtv == NULL)
  {
    printf("Error opening file");
    return 1;
  }

  long long count = 0;
  for (long long i = 0; i < strlen(mohtv); i++)
  {
    char *tike = (char *)calloc((strlen(text) + 1), sizeof(char));
    for (long long ii = 0; ii < strlen(text); ii++)
    {
      *(tike + ii) = *(mohtv + (ii + i));

      if (strcmp(text, tike) == 0 && (i == 0 || *(mohtv + (i - 1)) == '\0' || *(mohtv + (i - 1)) == '\n' || *(mohtv + (i - 1)) == ' ' || *(mohtv + (i - 1)) == EOF))
      {

        count++;
        if (qb == komaki && qb1 == komaki)
        {
          printf("%lld\n", i);
          b++;
          return 1;
        }
        if ((strcmp(qb, "byword") == 0) && qb1 == komaki)
        {
          printf("%lld\n", byword(mohtv, i));
          b++;
          return 1;
        }
        if ((strcmp(qb, "all") == 0) && qb1 == komaki)
        {
          if (boooll == 0)
          {
            printf("%lld\n", i);
            b++;
            continue;
          }
        }
        if ((strcmp(qb, "all") == 0) && (strcmp(qb1, "byword") == 0))
        {

          printf("%lld\n", byword(mohtv, i));
          b++;
          continue;
        }

        if ((strcmp(qb, "at") == 0) && qb1 == komaki)
        {
          if (count == at)
          {
            if (boooll == 0)
            {
              printf("%lld\n", i);
              b++;
            }
            else
            {
              b++;
              return i;
            }
          }

          else
          {
            continue;
          }
        }
        if ((strcmp(qb, "at") == 0) && (strcmp(qb1, "byword") == 0))
        {
          if (count == at)
          {
            printf("%lld\n", byword(mohtv, i));
            b++;
          }
        }
      }
    }
  }

  if ((strcmp(qb, "at") == 0) && at > count)
  {
    if ((boooll == 0))
    {
      printf("-1");
      return -1;
    }
    else
    {
      b++;
      return -2;
    }
  }
  if ((strcmp(qb, "count") == 0) && qb1 == komaki)
  {
    printf("%lld\n", count);
    b++;
    return 1;
  }
  // if(((strcmp(qb,"count")==0)&&(qb1!=NULL))||((strcmp(qb,"at")==0)&&(strcmp(qb1,"all")==0))||((strcmp(qb1,"at")==0)&&(strcmp(qb,"all")==0))){

  // printf("Wrong entries\n");
  // return -1;
  //}
  if (((strcmp(qb, "count") == 0) && (qb1 != komaki)))
  {
    printf("Wrong entries\n");
    return -1;
  }
  if (((strcmp(qb, "at") == 0) && (strcmp(qb1, "all") == 0)))
  {
    printf("Wrong entries\n");
    return -1;
  }

  if ((strcmp(qb, "all") == 0))
  {
    if ((strcmp(qb1, "at") == 0))
    {
      printf("Wrong entries\n");
      return -1;
    }
    else
    {
    }
  }

  if (b == 0)
  {
    printf("Not found\n");
    return -1;
  }
}
long long fstreqbl(char *add, char *text, char *qb, char *qb1, long long at, int boooll)
{
  char *komaki = (char *)calloc(sizeof(char), 2);
  *(komaki + 0) = '^';
  if (qb == NULL)
  {
    qb = komaki;
  }
  if (qb1 == NULL)
  {
    qb1 = komaki;
  }
  long long *res;
  long long resss = 0;
  long long b = 0;
  long long count = 0;
  char *mohtv = cat(add);
  if (mohtv == NULL)
  {
    printf("Error opening file");
    return 1;
  }

  for (long long i = 0; i < strlen(mohtv); i++)
  {
    char *tike = (char *)calloc((strlen(text) + 1), sizeof(char));
    long long ii = 0;
    for (ii = 0; ii < strlen(text); ii++)
    {
      *(tike + ii) = *(mohtv + (ii + i));

      if (strcmp(text, tike) == 0 && (*(mohtv + (ii + i)) == '\0' || *(mohtv + (ii + i)) == '\n' || *(mohtv + (ii + i)) == ' ' || *(mohtv + (ii + i)) == EOF))
      {
        count++;
        if (qb == komaki && qb1 == komaki)
        {
          printf("%lld\n", i);
          b++;
          return 1;
        }
        if ((strcmp(qb, "byword") == 0) && qb1 == komaki)
        {
          printf("%lld\n", byword(mohtv, i));
          b++;
          return 1;
        }
        if ((strcmp(qb, "all") == 0) && qb1 == komaki)
        {
          if (boooll == 0)
          {
            printf("%lld\n", i);
            b++;
            continue;
          }
        }
        if ((strcmp(qb, "all") == 0) && (strcmp(qb1, "byword") == 0))
        {
          printf("%lld\n", byword(mohtv, i));

          b++;
          continue;
        }

        if ((strcmp(qb, "at") == 0) && qb1 == komaki)
        {
          if (count == at)
          {
            if (boooll == 0)
            {
              printf("%lld\n", i);
              b++;
            }
            else
            {
              b++;
              return i;
            }
          }

          else
          {
            continue;
          }
        }
        if ((strcmp(qb, "at") == 0) && (strcmp(qb1, "byword") == 0))
        {
          if (count == at)
          {
            printf("%lld\n", byword(mohtv, i));
            b++;
          }
        }
      }
    }
  }

  if ((strcmp(qb, "at") == 0) && at > count)
  {
    if ((boooll == 0))
    {
      printf("-1");
      return -1;
    }
    else
    {
      b++;
      return -2;
    }
  }

  if ((strcmp(qb, "count") == 0) && qb1 == komaki)
  {
    printf("%lld\n", count);
    b++;
    return 1;
  }
  else if ((strcmp(qb, "count") == 0) || (strcmp(qb, "at") == 0 && strcmp(qb1, "all") == 0) || (strcmp(qb1, "at") == 0 && strcmp(qb, "all") == 0))
  {
    printf("Wrong entries\n");
    return -1;
  }
  if (b == 0)
  {
    printf("Not found\n");
    return -1;
  }

  return b;
}
char *backfind(char *stri)
{
  char *new = (char *)calloc(sizeof(char), strlen(stri));
  long long h = 0;
  for (long long i = 0; i < strlen(stri); i++)
  {
    if ((*(stri + i)) == '\\' && *(stri + (i + 1)) == '*')
    {
      i++;
    }
    *(new + h) = *(stri + i);
    h++;
  }
  return new;
}
long long editstre(char *stri, char *addr, char *qb, char *qb1, long long at, int boooll)
{
  char *neww = (char *)calloc(sizeof(char), (strlen(stri) + 1));

  if (*(stri + 0) == '*')
  {
    for (long long i = 0; i < strlen(stri) - 1; i++)
    {

      *(neww + i) = *(stri + (i + 1));
    }

    fstreqbl(addr, backfind(neww), qb, qb1, at, boooll);
  }

  else if (*(stri + (strlen(stri) - 1)) == '*' && *(stri + (strlen(stri) - 2)) != '\\')
  {
    for (long long i = 0; i < strlen(stri) - 1; i++)
    {
      *(neww + i) = *(stri + i);
    }
    // printf("%s", neww);

    fstrebd(addr, backfind(neww), qb, qb1, at, boooll);
  }
  else
  {
    for (long long i = 0; i < strlen(stri); i++)
    {
      *(neww + i) = *(stri + i);
    }
    // printf("%s", neww);

    return fsade(addr, backfind(neww), qb, qb1, at, boooll);
  }
  // printf("%s", neww);
  return 0;
}
long long komkrep1(long long i, char *addr)
{
  char *read = cat(addr);
  long long ent = 0;
  long long k = 0;
  while (k <= i)
  {
    if (*(read + k) == '\n')
    {
      ent++;
    }
    k++;
  }
  return ent;
}
long long komkrep2(long long i, char *addr)
{
  char *read = cat(addr);
  long long tedadent = komkrep1(i, addr);
  long long komkent = 0;
  long long kk = 0;
  while (komkent < tedadent)
  {
    if (*(read + kk) == '\n')
    {
      komkent++;
    }

    //  printf("(%lld),*(%c)",komkent,*(read+kk));
    kk++;
  }
  return (i - kk);
}
long long replace(char *add, char *fi, char *se, char *qbb, long long at)
{
  char *qbbb1 = {0};
  char *baqali = fi;
  long long lenfi = strlen(fi);
  for (long long i = 0; i < strlen(fi); i++)
  {
    if (*(baqali + 0) == '*')
    {
      lenfi--;
    }
    else if (*(baqali + i) == '\\' && *(baqali + (i + 1)) == '*')
    {
      lenfi--;
    }
  }

  int a = 1;
  // printf("&&%s**",qbbb1);
  if (strcmp(qbb, "all") == 0)
  {
    a = 2;
    at = 1;
    *(qbb + 1) = 't';
    *(qbb + 2) = '\0';
  }

  long long index = editstre(fi, add, qbb, qbbb1, at, 1);

  if (index >= 0)
  {

    if (a == 1)
    {
      // printf("<%lld.%lld>",komkrep1((index),add),komkrep2((index),add));
      removee(add, komkrep1((index), add), komkrep2((index), add), lenfi, (1));
      // printf("%lld   %lld^*^*",komkrep1((index),add),komkrep2((index),add));
      // insert
      insertrepl(add, komkrep1((index), add), komkrep2((index), add), se);
      // printf("%lld   %lld",komkrep1((index),add),komkrep2((index),add));
    }
    // printf("HJKL");
    else if (a == 2)
    {

      while (1)
      {
        if (index == (-2))
        {
          break;
        }

        removee(add, komkrep1((index), add), komkrep2((index), add), lenfi, (1));
        insertrepl(add, komkrep1((index), add), komkrep2((index), add), se);
        at++;
        long long index = editstre(fi, add, qbb, qbbb1, at, 1);
      }
    }
  }
  else
  {
    printf("Error finding");
  }
}
long long grep(char *addre, char *text, long long opt)
{

  FILE *fp;

  fp = fopen(addre, "r");
  fseek(fp, 0, SEEK_END);
  long long len = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  long long barac = 0;
  fclose(fp);
  fp = fopen(addre, "r");
  char *mohtv = (char *)calloc(len, sizeof(char));
  while (fgets(mohtv, len, fp) != NULL)
  {
    for (long long i = 0; i < len; i++)
    {
      char *tike = (char *)calloc((strlen(text) + 1), sizeof(char));
      for (long long ii = 0; ii < strlen(text); ii++)
      {
        *(tike + ii) = *(mohtv + (ii + i));
        if (strcmp(tike, text) == 0)
        {
          if (opt == 0)
          {
            printf("%s: %s\n", addre, mohtv);
          }
          else if (opt == 1)
          {
            barac++;
          }
          else if (opt == 2)
          {
            printf("%s\n", addre);
            fclose(fp);
            return 0;
          }
        }
      }
    }
  }
  if (opt == 1)
  {
    fclose(fp);
    return barac;
  }
  fclose(fp);
  return 0;
}
void tree(const int root, char *paaath, long long depth)
{
  if (root >= depth * 2)
  {
    return;
  }
  int i;
  char path[1000];
  struct dirent *dp;
  DIR *dir = opendir(paaath);

  if (!dir)
    return;

  while ((dp = readdir(dir)) != NULL)
  {
    if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
    {
      for (i = 0; i < root; i++)
      {
        if (i % 2 == 0 || i == 0)
          printf("%c", 179);
        else
          printf(" ");
      }

      printf("%c%c%s\n", 195, 196, dp->d_name);

      strcpy(path, paaath);
      strcat(path, "/");
      strcat(path, dp->d_name);
      tree(path, root + 2, depth);
    }
  }

  closedir(dir);
  return;
}
long long pairs(char *addr)
{

  FILE *fp;
  fp = fopen(addr, "r");
  if (fp == NULL)
  {
    printf("Error opening");
    fclose(fp);
    return 0;
  }

  fseek(fp, 0, SEEK_END);
  long long len = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  long long barac = 0;
  fclose(fp);
  fp = fopen(addr, "r");
  char *mohtv = (char *)calloc(len + 1, sizeof(char));
  fgets(mohtv, len, fp) != NULL;
  fclose(fp);
  char *here = (char *)calloc(sizeof(char), (len * 10));
  // printf("%s",mohtv);
  long long ekh = 0;
  long long tool = 0;
  for (long long i = 0; i < strlen(mohtv); i++)
  {
    if (*(mohtv + i) == '{')
    {
      ekh++;
      *(here + tool) = '\n';
      *(here + (tool + 1)) = '\0';
      tool++;
      for (int p = 0; p < ekh - 1; p++)
      {
        *(here + tool) = '\t';
        *(here + (tool + 1)) = '\0';
        tool++;
      }
      *(here + tool) = '{';
      *(here + (tool + 1)) = '\n';
      tool += 2;
      for (int p = 0; p < ekh; p++)
      {
        *(here + tool) = '\t';
        *(here + (tool + 1)) = '\0';
        ekh++;
      }
      continue;
    }
    if (*(mohtv + i) == '}')
    {
      ekh--;
      if (ekh < 0)
      {
        printf("Wrong aqualad\n");
        return 0;
      }
      *(here + tool) = '\n';
      *(here + (tool + 1)) = '\0';
      tool++;
      for (int p = 0; p < ekh; p++)
      {
        *(here + tool) = '\t';
        *(here + (tool + 1)) = '\0';
        tool++;
      }
      *(here + tool) = '}';
      tool++;
      continue;
    }
    *(here + tool) = *(mohtv + i);
    *(here + (tool + 1)) = '\0';
    tool++;
  }
  if (ekh != 0)
  {
    printf("There are some wrong aqualad\n");
    return 0;
  }
  fp = fopen(addr, "w");
  fprintf(fp, "%s", here);
  fclose(fp);
}
long long undo(char *add) {}
int main(char *add, char *text)
{
  char *clipboard = {0};
  char *cl;
  char *save;
  // char* input1=NULL;
  // input1=(char*)calloc(102,sizeof(char));
  char *input = NULL;
  input = (char *)calloc(102, sizeof(char));

  while (1)
  {
    gets(input);
    char *id = NULL;
    id = (char *)calloc(102, sizeof(char));
    char *asli = NULL;
    asli = (char *)calloc(102, sizeof(char));
    long long i = 0;
    while (*(input + i) != '_')
    {
      *(id + i) = *(input + i);
      i++;
    }
    i += 2;
    long long p = 0;
    while (*(input + i) != '\0')
    {
      *(asli + p) = *(input + i);
      i++;
      p++;
    }
    // printf("%s",asli);
    if (strcmp(id, "createfile ") == 0)
    {
      creatfile(parda13(asli + 5));
    }

    else if (strcmp(id, "cat ") == 0)
    {
      char *read = cat(parda13(asli + 5));
      if (read == NULL)
      {
        printf("\nError reading file!\n");
      }
      else
      {
        printf("%s", read);
      }
    }
    else if (strcmp(id, "insert ") == 0)
    {
      char *add = strtok(asli + 5, "_");
      // printf("%s\n",add);
      char *what = strtok(NULL, "_");
      // printf("%s\n",what);
      char *pos = strtok(NULL, "_");
      // printf("%s\n",pos);
      long long f = posedit1(pos + 4, f);
      long long l = posedit2(pos + 4, l);
      // printf("#%lld %lld#",f,l);
      clipboard = cat(parda13(add));
      long long read = insert(parda13(add), f, l, pishins(what + 4));
      if (read == 2)
      {

        printf("\ndone\n");
      }
      else if (read == 1)
      {
      }
      else
      {

        printf("\nError reading file!\n");
      }
    }
    else if (strcmp(id, "remove ") == 0)
    {
      char *add = strtok(asli + 5, "_");
      // printf("%s\n",add);

      char *pos = strtok(NULL, "_");
      long long f = posedit1(pos + 4, f);
      long long l = posedit2(pos + 4, l);
      char *size = strtok(NULL, "_");
      long long siz = posedit1(size + 5, siz);
      // printf("\t%lld",siz);
      char *forb = strtok(NULL, "_");
      // printf("%s %d", forb, strlen(forb));
      long long k;
      if (strcmp(forb, "f") == 0)
      {
        k = 1;
      }
      if (strcmp(forb, "b") == 0)
      {
        k = (-1);
      }
      clipboard = cat(parda13(add));
      long long read = removee(parda13(add), f, l, siz, k);
      if (read == 2)
      {

        printf("\ndone\n");
      }
      else if (read == 1)
      {
      }
      else
      {

        printf("\nError reading file!\n");
      }
    }
    else if (strcmp(id, "copy ") == 0)
    {

      char *add = strtok(asli + 5, "_");
      // printf("%s\n",add);

      char *pos = strtok(NULL, "_");
      long long f = posedit1(pos + 4, f);
      long long l = posedit2(pos + 4, l);
      char *size = strtok(NULL, "_");
      long long siz = posedit1(size + 5, siz);
      // printf("\t%lld",siz);
      char *forb = strtok(NULL, "_");
      // printf("%s %d",forb,strlen(forb));
      save = (char *)calloc(sizeof(char), (siz + 1));
      long long k;
      if (strcmp(forb, "f") == 0)
      {
        k = 1;
      }
      if (strcmp(forb, "b") == 0)
      {
        k = (-1);
      }

      long long read = copy(parda13(add), f, l, siz, k, save);
      if (read == 2)
      {
        printf("\ndone\n");
      }
      else if (read == 1)
      {
      }
      else
      {

        printf("\nError reading file!\n");
      }
    }
    else if (strcmp(id, "cut ") == 0)
    {

      char *add = strtok(asli + 5, "_");
      // printf("%s\n",add);

      char *pos = strtok(NULL, "_");
      long long f = posedit1(pos + 4, f);
      long long l = posedit2(pos + 4, l);
      char *size = strtok(NULL, "_");
      long long siz = posedit1(size + 5, siz);
      // printf("\t%lld",siz);
      char *forb = strtok(NULL, "_");
      // printf("%s %d",forb,strlen(forb));
      save = (char *)calloc(sizeof(char), (siz + 1));
      long long k;
      if (strcmp(forb, "f") == 0)
      {
        k = 1;
      }
      if (strcmp(forb, "b") == 0)
      {
        k = (-1);
      }
      clipboard = cat(parda13(add));
      long long read = copy(parda13(add), f, l, siz, k, save);
      if (read == 2)
      {
        removee(parda13(add), f, l, siz, k);
        printf("\ndone\n");
      }
      else if (read == 1)
      {
      }
      else
      {

        printf("\nError reading file!\n");
      }
    }
    else if (strcmp(id, "paste ") == 0)
    {
      char *add = strtok(asli + 5, "_");
      // printf("%s\n",add);
      char *pos = strtok(NULL, "_");
      // printf("%s\n",pos);
      long long f = posedit1(pos + 4, f);
      long long l = posedit2(pos + 4, l);
      // printf("#%lld %lld#",f,l);
      clipboard = cat(parda13(add));
      long long read = insert(parda13(add), f, l, save);
      if (read == 2)
      {
        printf("\ndone\n");
      }
      else if (read == 1)
      {
      }
      else
      {

        printf("\nError reading file!\n");
      }
    }
    else if (strcmp(id, "undo ") == 0)
    {
      char *add = strtok(asli + 5, "_");

      clipboard = cat(parda13(add));
      if (cat == NULL)
      {
        printf("\nError reading file!\n");
      }

      if (clipboard == NULL)
      {
        printf("No recent changes");
      }
      else
      {
        FILE *filee;
        char *add = strtok(asli + 5, "_");
        filee = fopen(parda13(add), "w");
        fprintf(filee, "%s", clipboard);
        fclose(filee);
      }
    }
    else if (strcmp(id, "compare ") == 0)
    {
      char *add1 = strtok(asli, "_");
      char *add2 = strtok(NULL, "_");
      long long read = compare(parda13(add1), parda13(add2));
      if (read == 1)
      {
      }
      else
      {
      }
    }
    else if (strcmp(id, "find ") == 0)
    {

      char *str = strtok(asli, "_");
      char *fil = strtok(NULL, "_");
      char *qb = strtok(NULL, "_");
      char *qb1 = strtok(NULL, "_");
      long long addd = atoll(qb + 3);
      if ((*(qb + 0)) == 'a' && (*(qb + 1)) == 't')
      {
        long long addd = atoll(qb + 3);
        *(qb + 2) = '\0';
        *(qb + 3) = '\0';
      }

      str = str + 4;
      fil = fil + 5;
      //  printf("%s\t%s\t%s\t%s\t%lld*",str,fil,qb,qb1,addd);
      editstre(str, parda13(fil), qb, qb1, addd, 0);
    }
    else if (strcmp(id, "replace ") == 0)
    {
      char *str1 = strtok(asli, "_");
      char *str2 = strtok(NULL, "_");
      char *adr = strtok(NULL, "_");
      char *qbb = strtok(NULL, "_");
      char *qbb1 = strtok(NULL, "_");
      char *komki = "at 1";
      if (qbb == NULL || strcmp(qbb, "at") == 0)
      {
        qbb = komki;
      }
      long long addd = atoll(qbb + 3);
      if ((*(qbb + 0)) == 'a' && (*(qbb + 1)) == 't')
      {

        *(qbb + 2) = '\0';
        *(qbb + 3) = '\0';
      }

      str1 = str1 + 5;
      str2 = str2 + 5;
      adr = adr + 5;
      if (qbb1 == NULL)
      {
        replace(parda13(adr), str1, str2, qbb, addd);
      }
      else
      {
        printf("Wrong entries\n");
      }

      // printf("%s\t%s\t%s\t%s^^\t%lld^^",str1,str2,adr,qbb,addd);
    }
    else if (strcmp(id, "grep ") == 0)
    {
      long long op = 0;

      char *fi = strtok(asli, "__");
      // printf("%s\n",fi);
      char *se = strtok(NULL, "__");
      // printf("%s\n",se);
      grep(parda13(se), fi, op);
      // printf("sfgdfg");
      while (1)
      {
        char *th = strtok(NULL, "__");

        if (th == NULL)
        {
          break;
        }
        grep(parda13(th), fi, op);
      }
    }
    else if (strcmp(id, "grep -C ") == 0)
    {
      long long res = 0;
      long long op = 1;
      char *fi = strtok(asli, "__");
      //  printf("%s\n",fi);
      char *se = strtok(NULL, "__");
      // printf("%s\n",se);
      res = grep(parda13(se), fi, op);
      while (1)
      {
        char *th = strtok(NULL, "__");

        if (th == NULL)
        {
          break;
        }
        res += grep(parda13(th), fi, op);
      }
      printf("%lld", res);
    }
    else if (strcmp(id, "grep -I ") == 0)
    {
      long long op = 2;
      char *fi = strtok(asli, "__");
      // printf("%s\n",fi);
      char *se = strtok(NULL, "__");
      // printf("%s\n",se);
      grep(parda13(se), fi, op);
      while (1)
      {
        char *th = strtok(NULL, "__");

        if (th == NULL)
        {
          break;
        }
        grep(parda13(th), fi, op);
      }
    }
    else if (strcmp(id, "tree ") == 0)
    {
      long long omq = atoll(asli);
      // printf("%lld",omq);
      char path[100] = "root";

      if (omq > 0)
        tree(0, path, omq);
      else if (omq == -1)
      {
        tree(0, path, 200);
      }
      else if (omq < -1)
      {
        printf("Wrong entries\n");
        continue;
      }
    }
    else if (strcmp(id, "auto ") == 0)
    {
      char *addre = strtok(asli, "__");
      pairs(parda13(addre));
    }

    else if (strcmp(id, "undo") == 0)
    {
      char *addre = strtok(asli, "__");
      undo(parda13(addre));
    }
    else if (strcmp(id, "exit") == 0)
    {
      break;
    }
    else
    {
      printf("Wrong command");
    }
  }
}
