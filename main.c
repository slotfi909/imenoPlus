#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TOTALHASH1 11
#define TOTALHASH2 9
#define TOTALHASH3 3
#define TOTALHASH4 10
#define TOTALNORMACC 100
#define TOTALSUPACC 100
#define TOTALHOSPITAL 100
#define TOTALDEADACC 100
int vorood;
int flag1=1,flag2=1,flag3=1;
/////////////////////////////
int counter1=0;           ///
int counter2=0;           ///
int counter3=0;           ///
int counter4=0;           ///
/////////////////////////////
char chek[4][20];
char admin[4][50]={"useradmin","passadmin","1273629361","slotfi909@gmail.com"};
typedef struct normacc{
     char *name;
     char *lastname;
     char *codemelli;
     char *namekaarbari;
     char *ramz;
     char *email;
     char *khoon;
     int sen;
     int qad;
     int vazn;
     int healthcode;
    //  time_t times1[10];
    int times1[10];
     int healthcodes[10];
    int times2[10];
    char codemellies[10][20];
    int times3[10];
    char plcnames[10][20];
 }normacc;
typedef struct supacc{
     char *name;
     char *lastname;
     char *codemelli;
     char *namekaarbari;
     char *ramz;
     char *email;
     char *namemakan;
     char *shahr;
     int mantaqe;
     int plchealth;
 }supacc;
typedef struct hospital{
    char name[50];
    char shahr[50];
    int mantaqe;
}hospital;
typedef struct deadacc{
     char name[50];
     char lastname[50];
     char codemelli[50];
     char namekaarbari[50];
     char ramz[50];
     char email[50];
     char khoon[50];
     int sen;
     int qad;
     int vazn;
 }deadacc;
    normacc **all1;
    supacc **all2;
    hospital **all3;
    deadacc **all4;
void changeinfo1(int k);
void forget1(int *a,normacc ***all1);
void forget2(int *a,supacc ***all2);
void forget3(int *a);
void crtuser1 (normacc **all1);
void crtuser2 (supacc **all2);
void addhospital(hospital ** a3);
char* strnchr(char * str,char key,int num);
char* between(char * start,char* end);
void crtspace(normacc *** all1,supacc *** all2,hospital ***all3,deadacc ***all4);
void stctofile(void);
void filetostct(void);
void setcounters(void);
void showmenu1(int k,normacc **all1);
void showmenu2(int k,supacc **all2);
void showmenu3(hospital **all3);
void allmember(void);
void allplaces(void);
void allhospitals(void);
void login(void);
char* starpass(char password[51]);
//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//
int main(){
    flag1=1;
    setcounters();
    crtspace(&all1,&all2,&all3,&all4);
    filetostct();
system("cls");
 while(flag1){
     flag1=flag2=flag3=1;
    system("cls");
puts("salam!\nbe \"imeno +\" khosh amdid :) \nlotfan yek gozine ra entekhab nam\
a'Ed ! :)\n1-vorood be barname\n2-ijaad accounte jadid\
\n3-faraamooshie ramze oboor\n4-khorooj");
    scanf("%d",&vorood);
          if(vorood==1){
            while(flag2 && flag1){
          system("cls");
            puts("lotfan username khod ra vared nama'Ed:");
             scanf("%s",chek[0]);
             puts("\nlotfan password khod ra vared nama'Ed:");
             char *temp1=(char *)calloc(51,sizeof(char));
             temp1=starpass(temp1);
            /*scanf("%s",chek[1]);*/
            strcpy(chek[1],temp1);
            login();
             stctofile();
            }
          }
     if(vorood==2){
        system("cls");
        int acctype;
        puts("1-kaarbare aadi\n2-saahebine mashaaqel\n3-lock kardan(barghasht be menuye aavaal)");
        scanf("%d",&acctype);
        if(acctype==1){
         crtuser1(all1);
         stctofile();
        }
        if(acctype==2){
            crtuser2(all2);
            stctofile();
        }
        if(acctype==3);
        if(acctype!=1 && acctype!=2 && acctype!=3)
            puts("adade vaared shode sahih nist :( , lotfan dobare talash konid...");
getchar();




     }
  if(vorood==3){
        system("cls");
        int loginchek=0;
        puts("lotfan etela'Ate zir ra takmil nema'Ed");
         puts("naame karbari: ");
        scanf("%s",chek[1]);
         puts("code melli: ");
        scanf("%s",chek[0]);
        puts("Email: ");
        scanf("%s",chek[2]);
        // int acctype;
        // puts("no'e accounte shoma che bood?\n1-Aadi 2-saahebine mashaaqe");
        // scanf("%d",&acctype);
        // if(acctype==1)
        forget1(&loginchek,&all1); // v be c sup
        // if(acctype==2)
         forget2(&loginchek,&all2);
         stctofile();
         forget3(&loginchek);
        if(loginchek==0){
            puts("etela'Ate vared shode sahih nist :( , lotfan dobare talash konid");
          getchar();
          getchar();
            }
          }
if(vorood==4)
flag1=0;
if(vorood!=1 && vorood!=2 && vorood!=3 && vorood!=4){
     puts("adade vaared shode sahih nist :( , lotfan dobare talash konid...");
     getchar();
     getchar();
 }
stctofile();
 }
stctofile();
return 0;
 }
 //--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//
void changeinfo1(int k){
 char * test=(char *)malloc(50*sizeof(char));
   // char * temp=(char *)malloc(50*sizeof(char));
    // static int k=0;
    int tempint;
    puts("mikhaahid kodaam yek az mavaarede zir ra taqir dahid?");
  puts("1-nam: ");
    // scanf("%s",test);
    // strcpy((all1[k]->name),test);
    puts("2-naame khaanevadegi: ");
    // scanf("%s",test);
    // strcpy(all1[k]->lastname,test);
    puts("3-code melli: ");
    // scanf("%s",test);
    // strcpy(all1[k]->codemelli,test);
    puts("4-naame kaarbari: ");
    // scanf("%s",test);
    // strcpy(all1[k]->namekaarbari,test);
    puts("4-ramze oboor: ");
    // scanf("%s",test);
    // printf("tekraare ramze oboor: ");
    // scanf("%s",temp);
    // while(strcmp(test,temp)){
            // puts("lotfan ramze khod ra dobare vared namaEd");
            // printf("ramze oboor: ");
            // scanf("%s",test);
            // printf("tekrare ramze oboor: ");
            // scanf("%s",temp);
            //   }
    // strcpy(all1[k]->ramz,test);
    puts("5-email: ");
    // scanf("%s",test);
    // strcpy(all1[k]->email,test);
    // getchar();
puts("6-gorooh khooni(ekhtiari): ");
        // fgets(test,50,stdin);
        // test[strlen(test) - 1] = '\0';
        // strcpy(all1[k]->khoon,test);
        puts("7-sen(ekhtiari): ");
        // fgets(test,50,stdin);
        // test[strlen(test) - 1] = '\0';
        // strcpy(all1[k]->sen,test);
        // if(test!=0)
        // all1[k]->sen=atoi(test);
        puts("8-qad(ekhtiari): ");
        // fgets(test,50,stdin);
        // test[strlen(test) - 1] = '\0';
        // strcpy(all1[k]->qad,test);
        // if(test!=0)
        // all1[k]->qad=atoi(test);
        puts("9-vazn(ekhtiari): ");
        // fgets(test,50,stdin);
        int a;
        scanf("%d",&a);
        puts("etela'Ate jadid raa vared konid");
        scanf("%s",test);
        if(a==1)
        strcpy((all1[k]->name),test);
        if(a==2)
        strcpy((all1[k]->lastname),test);
        if(a==3)
        strcpy((all1[k]->codemelli),test);
        if(a==4)
        strcpy((all1[k]->namekaarbari),test);
        if(a==5)
        strcpy((all1[k]->ramz),test);
        if(a==6)
        strcpy((all1[k]->khoon),test);
        if(a==7){
            tempint=atoi(test);
            all1[k]->sen=tempint;
        }
        // strcpy((all1[k]->sen),test);
        if(a==8){
            tempint=atoi(test);
            all1[k]->qad=tempint;
        }
        // strcpy((all1[k]->qad),test);
        if(a==9){
            tempint=atoi(test);
            all1[k]->vazn=tempint;
        }
        // strcpy((all1[k]->vazn),test);

        // test[strlen(test) - 1] = '\0';
        puts("etela'At ba movafaqiat taqir kard :)\n");
        getchar();
        getchar();
        // strcpy(all1[k]->vazn,test);
        // if(test!=0)
        // all1[k]->vazn=atoi(test);
        // k++;
// return k ;
return ;
}
void forget1(int *a,normacc ***all1){
    for(int i=0;i<counter1;i++)
    if(!strcmp((*all1)[i]->codemelli,chek[0]))
     if(!strcmp((*all1)[i]->namekaarbari,chek[1]))
      if(!strcmp((*all1)[i]->email,chek[2])){
          puts("lotfan ramze jadide khod ra vared namaEd :)");
          char temp[50];
          scanf("%s",temp);
        strcpy((*all1)[i]->ramz,temp);
        *a=1;
        puts("ramz ba movafaqiat taqir kard !");
        break;
      }
    return ;
}
void forget2(int *a,supacc ***all2){
    for(int i=0;i<counter2;i++)
    if(!strcmp((*all2)[i]->codemelli,chek[0]))
     if(!strcmp((*all2)[i]->namekaarbari,chek[1]))
      if(!strcmp((*all2)[i]->email,chek[2])){
          puts("lotfan ramze jadide khod ra vared namaEd :)");
          char temp[50];
          scanf("%s",temp);
        strcpy((*all2)[i]->ramz,temp);
        *a=1;
        puts("ramz ba movafaqiat taqir kard !");
        break;
      }
    return ;
}
void forget3(int *a){
    if(!strcmp(admin[2],chek[0]))
     if(!strcmp(admin[0],chek[1]))
      if(!strcmp(admin[3],chek[2])){
    puts("ramz jadid ra vared konid!");
    char temp[50];
    scanf("%s",temp);
    strcpy(admin[1],temp);
    *a=1;
      }
    return;
}
void crtuser1 (normacc **all1){
    char * test=(char *)malloc(50*sizeof(char));
    char * temp=(char *)malloc(50*sizeof(char));
    // static int counter1=0;
  printf("nam: ");
    scanf("%s",test);
    strcpy((all1[counter1]->name),test);
    printf("naame khaanevadegi: ");
    scanf("%s",test);
    strcpy(all1[counter1]->lastname,test);
    printf("code melli: ");
    scanf("%s",test);
    strcpy(all1[counter1]->codemelli,test);
    printf("naame kaarbari: ");
    scanf("%s",test);
    strcpy(all1[counter1]->namekaarbari,test);
    printf("ramze oboor: ");
    /*scanf("%s",test);*/
    test=starpass(test);
    puts("\n");
    printf("tekraare ramze oboor: ");
    /*scanf("%s",temp);*/
    temp=starpass(temp);
        puts("\n");
    while(strcmp(test,temp)){
            puts("lotfan ramze khod ra dobare vared namaEd");
            printf("ramze oboor: ");
            /*scanf("%s",test);*/
                test=starpass(test);
                    puts("\n");
            printf("tekrare ramze oboor: ");
            /*scanf("%s",temp);*/
                temp=starpass(temp);
    puts("\n");
              }
    strcpy(all1[counter1]->ramz,test);
    printf("email: ");
    scanf("%s",test);
    strcpy(all1[counter1]->email,test);
    getchar();
printf("gorooh khooni(ekhtiari): ");
        fgets(test,50,stdin);
        test[strlen(test) - 1] = '\0';
        strcpy(all1[counter1]->khoon,test);
        printf("sen(ekhtiari): ");
        fgets(test,50,stdin);
        test[strlen(test) - 1] = '\0';
        // strcpy(all1[counter1]->sen,test);
        if(test!=0)
        all1[counter1]->sen=atoi(test);
        printf("qad(ekhtiari): ");
        fgets(test,50,stdin);
        test[strlen(test) - 1] = '\0';
        // strcpy(all1[counter1]->qad,test);
        if(test!=0)
        all1[counter1]->qad=atoi(test);
        printf("vazn(ekhtiari): ");
        fgets(test,50,stdin);
        test[strlen(test) - 1] = '\0';
        puts("sabte name shoma kamel shod :)\n");
        // strcpy(all1[counter1]->vazn,test);
        if(test!=0)
        all1[counter1]->vazn=atoi(test);
        counter1++;
// return counter1 ;
return ;
}
void crtuser2 (supacc **all2){
    char * test=(char *)malloc(50*sizeof(char));
    char * temp=(char *)malloc(50*sizeof(char));
    int tempint;
    // static int counter2=0;
  printf("nam: ");
    scanf("%s",test);
    strcpy(all2[counter2]->name,test);
    printf("naame khaanevadegi: ");
    scanf("%s",test);
    strcpy(all2[counter2]->lastname,test);
    printf("code melli: ");
    scanf("%s",test);
    strcpy(all2[counter2]->codemelli,test);
    printf("naame kaarbari: ");
    scanf("%s",test);
    strcpy(all2[counter2]->namekaarbari,test);
    printf("ramze oboor: ");
    /*scanf("%s",test);*/
        test=starpass(test);
        puts("\n");
    printf("tekraare ramze oboor: ");
    /*scanf("%s",temp);*/
        temp=starpass(temp);
                puts("\n");
    while(strcmp(test,temp)){
            puts("lotfan ramze khod ra dobare vared namaEd");
            printf("ramze oboor: ");
                    test=starpass(test);
//            scanf("%s",test);
        puts("\n");
            printf("tekrare ramze oboor: ");
//            scanf("%s",temp);
        temp=starpass(temp);
                puts("\n");

              }
    strcpy(all2[counter2]->ramz,test);
    printf("email: ");
    scanf("%s",test);
    strcpy(all2[counter2]->email,test);
    printf("naame makaan: ");
    scanf("%s",test);
    strcpy(all2[counter2]->namemakan,test);
    printf("shahr: ");
    scanf("%s",test);
    strcpy(all2[counter2]->shahr,test);
    printf("mantaqe: ");
    scanf("%d",&tempint);
    // strcpy(all2[counter2]->mantaqe,test);
    all2[counter2]->mantaqe=tempint;
    puts("sabte name shoma kamel shod :)\n");
counter2++;
getchar();
// return counter2;
return ;
}
void addhospital(hospital ** a3){
    char temp[50];
    int tempint;
    printf("esme bimarestaan: ");
    scanf("%s",temp);
    strcpy(a3[counter3]->name,temp);
    printf("shahr: ");
    scanf("%s",temp);
    strcpy(a3[counter3]->shahr,temp);
    printf("mantaqe: ");
    scanf("%d",&tempint);
    a3[counter3]->mantaqe=tempint;
    puts("anjaam shod!");
getchar();
getchar();
counter3++;
    return ;

}
char* strnchr(char * str,char key,int num){
    int count=0;
    while(count!=num){
    while(*str!=key){
        str++;
    }
    str++;
    count++;
    }
    return str-1;
}
char* between(char * start,char* end){
    char *res=calloc(500,sizeof(char));
    int i=0;
	start++;
	end--;
    while(start<=end){
       res[i]=*(start);
       start++;
       i++;
    }
    return res;
}
void crtspace(normacc *** all1,supacc *** all2,hospital ***all3,deadacc ***all4){
    *all1=(normacc **)malloc(TOTALNORMACC*sizeof(normacc *));
    *all2=(supacc **)malloc(TOTALSUPACC*sizeof(supacc *));
    *all3=(hospital **)malloc(TOTALHOSPITAL*sizeof(hospital *));
    *all4=(hospital **)malloc(TOTALDEADACC*sizeof(deadacc *));
    for(int i=0;i<TOTALNORMACC;i++){
     (*all1)[i]=(normacc *)malloc(sizeof(normacc));
     (*all1)[i]->name=(char *)malloc(50*sizeof(char));
     (*all1)[i]->lastname=(char *)malloc(50*sizeof(char));
     (*all1)[i]->codemelli=(char *)malloc(50*sizeof(char));
     (*all1)[i]->namekaarbari=(char *)malloc(50*sizeof(char));
     (*all1)[i]->ramz=(char *)malloc(50*sizeof(char));
     (*all1)[i]->email=(char *)malloc(50*sizeof(char));
     (*all1)[i]->khoon=(char *)malloc(50*sizeof(char));
    (*all1)[i]->healthcode=1;
    for(int k=0;k<10;k++){
        (*all1)[i]->healthcodes[k]=0;
        (*all1)[i]->times1[k]=0;
        (*all1)[i]->times2[k]=0;
        (*all1)[i]->times3[k]=0;
    }
    }
    for(int i=0;i<TOTALSUPACC;i++){
     //////////////////////////////////////////////////////////
     (*all2)[i]=(supacc *)malloc(sizeof(supacc));
     (*all2)[i]->name=(char *)malloc(50*sizeof(char));
     (*all2)[i]->lastname=(char *)malloc(50*sizeof(char));
     (*all2)[i]->codemelli=(char *)malloc(50*sizeof(char));
     (*all2)[i]->namekaarbari=(char *)malloc(50*sizeof(char));
     (*all2)[i]->ramz=(char *)malloc(50*sizeof(char));
     (*all2)[i]->email=(char *)malloc(50*sizeof(char));
     (*all2)[i]->namemakan=(char *)malloc(50*sizeof(char));
     (*all2)[i]->shahr=(char *)malloc(50*sizeof(char));
     (*all2)[i]->plchealth=0;
     }
     for(int i=0;i<TOTALHOSPITAL;i++)
     (*all3)[i]=(hospital *)malloc(sizeof(hospital));
     for(int i=0;i<TOTALDEADACC;i++)
     (*all4)[i]=(deadacc *)malloc(sizeof(deadacc));

    return ;
}
void stctofile(void){
    FILE *fptr1;
    FILE *fptr2;
    FILE *fptr3;
    FILE *fptr4;
    FILE *fptr5;
    FILE *fptr6;
    FILE *fptr7;
    fptr1=fopen("data1.txt","w+");
    fptr2=fopen("data2.txt","w+");
    fptr3=fopen("data3.txt","w+");
    fptr4=fopen("data4.txt","w+");
    fptr5=fopen("data5.txt","w+");
    fptr6=fopen("data6.txt","w+");
    fptr7=fopen("data7.txt","w+");
    for(int i=0;i<counter1;i++){
        fprintf(fptr1,"%d",i+1);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%s",all1[i]->name);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%s",all1[i]->lastname);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%s",all1[i]->codemelli);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%s",all1[i]->namekaarbari);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%s",all1[i]->ramz);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%s",all1[i]->email);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%s",all1[i]->khoon);
        fprintf(fptr1,"%c",'#');
        if(all1[i]->sen)
        fprintf(fptr1,"%d",all1[i]->sen);
        fprintf(fptr1,"%c",'#');
        if(all1[i]->qad)
        fprintf(fptr1,"%d",all1[i]->qad);
        fprintf(fptr1,"%c",'#');
        if(all1[i]->vazn)
        fprintf(fptr1,"%d",all1[i]->vazn);
        fprintf(fptr1,"%c",'#');
        fprintf(fptr1,"%d",all1[i]->healthcode);
        fprintf(fptr1,"%c",'\n');
    }
    for(int i=0;i<counter2;i++){
        fprintf(fptr2,"%d",i+1);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->name);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->lastname);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->codemelli);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->namekaarbari);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->ramz);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->email);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->namemakan);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%s",all2[i]->shahr);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%d",all2[i]->mantaqe);
        fprintf(fptr2,"%c",'#');
        fprintf(fptr2,"%d",all2[i]->plchealth);
        fprintf(fptr2,"%c",'\n');
    }
    for(int i=0;i<counter3;i++){
        fprintf(fptr3,"%d",i+1);
        fprintf(fptr3,"%c",'#');
        fprintf(fptr3,"%s",all3[i]->name);
        fprintf(fptr3,"%c",'#');
        fprintf(fptr3,"%s",all3[i]->shahr);
        fprintf(fptr3,"%c",'#');
        fprintf(fptr3,"%d",all3[i]->mantaqe);
        fprintf(fptr3,"%c",'\n');
    }
    for(int i=0;i<counter4;i++){
        fprintf(fptr4,"%d",i+1);
        fprintf(fptr4,"%c",'#');
        fprintf(fptr4,"%s",all4[i]->name);
        fprintf(fptr4,"%c",'#');
        fprintf(fptr4,"%s",all4[i]->lastname);
        fprintf(fptr4,"%c",'#');
        fprintf(fptr4,"%s",all4[i]->codemelli);
        fprintf(fptr4,"%c",'#');
        fprintf(fptr4,"%s",all4[i]->namekaarbari);
        fprintf(fptr4,"%c",'#');
        fprintf(fptr4,"%s",all4[i]->ramz);
        fprintf(fptr4,"%c",'#');
        fprintf(fptr4,"%s",all4[i]->email);
        fprintf(fptr4,"%c",'#');
        fprintf(fptr4,"%s",all4[i]->khoon);
        fprintf(fptr4,"%c",'#');
        if(all4[i]->sen)
        fprintf(fptr4,"%d",all4[i]->sen);
        fprintf(fptr4,"%c",'#');
        if(all4[i]->qad)
        fprintf(fptr4,"%d",all4[i]->qad);
        fprintf(fptr4,"%c",'#');
        if(all4[i]->vazn)
        fprintf(fptr4,"%d",all4[i]->vazn);
        fprintf(fptr4,"%c",'\n');
    }
    ////////////////////////////////
    for(int i=0;i<counter1;i++){
        fprintf(fptr5,"%d",i+1);
        fprintf(fptr5,"%c",'#');
        for(int j=0;j<10;j++){
            if(all1[i]->times1[j])
            fprintf(fptr5,"%d",all1[i]->times1[j]);
                 fprintf(fptr5,"%c",'-');
            if(all1[i]->times1[j])
            fprintf(fptr5,"%d",all1[i]->healthcodes[j]);
                 fprintf(fptr5,"%c",'-');

        }
fseek(fptr5,-1,SEEK_CUR);
                 fprintf(fptr5,"%c",'\n');



    }
    for(int i=0;i<counter1;i++){
        fprintf(fptr6,"%d",i+1);
        fprintf(fptr6,"%c",'#');
        for(int j=0;j<10;j++){
            if(all1[i]->times2[j])
            fprintf(fptr6,"%d",all1[i]->times2[j]);
                 fprintf(fptr6,"%c",'-');
            if(all1[i]->times2[j])
            fprintf(fptr6,"%s",all1[i]->codemellies[j]);
                 fprintf(fptr6,"%c",'-');
        }
fseek(fptr6,-1,SEEK_CUR);
                 fprintf(fptr6,"%c",'\n');
    }
    for(int i=0;i<counter1;i++){
        fprintf(fptr7,"%d",i+1);
        fprintf(fptr7,"%c",'#');
        for(int j=0;j<10;j++){
            if(all1[i]->times3[j])
            fprintf(fptr7,"%d",all1[i]->times3[j]);
                 fprintf(fptr7,"%c",'-');
            if(all1[i]->times3[j])
            fprintf(fptr7,"%s",all1[i]->plcnames[j]);
                 fprintf(fptr7,"%c",'-');
        }
fseek(fptr7,-1,SEEK_CUR);
                 fprintf(fptr7,"%c",'\n');
    }

    return ;
}
void filetostct(void){
    FILE *fptr1=0;
    FILE *fptr2=0;
    FILE *fptr3=0;
    FILE *fptr4=0;
    FILE *fptr5=0;
    FILE *fptr6=0;
    FILE *fptr7=0;
    fptr1=fopen("data1.txt","r+");
    fptr2=fopen("data2.txt","r+");
    fptr3=fopen("data3.txt","r+");
    fptr4=fopen("data4.txt","r+");
    fptr5=fopen("data5.txt","r+");
    fptr6=fopen("data6.txt","r+");
    fptr7=fopen("data7.txt","r+");
    char *temp1=(char *)malloc(500*sizeof(char));
    char *temp2=(char *)malloc(500*sizeof(char));
    for(int i=0;i<counter1;i++){
        if(fptr1)
        fgets(temp1,200,fptr1);
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        strcpy(all1[i]->name,temp2);
        temp2=between(strnchr(temp1,'#',2),strnchr(temp1,'#',3));
         strcpy(all1[i]->lastname,temp2);
        temp2=between(strnchr(temp1,'#',3),strnchr(temp1,'#',4));
         strcpy(all1[i]->codemelli,temp2);
         temp2=between(strnchr(temp1,'#',4),strnchr(temp1,'#',5));
         strcpy(all1[i]->namekaarbari,temp2);
         temp2=between(strnchr(temp1,'#',5),strnchr(temp1,'#',6));
         strcpy(all1[i]->ramz,temp2);
         temp2=between(strnchr(temp1,'#',6),strnchr(temp1,'#',7));
         strcpy(all1[i]->email,temp2);
         temp2=between(strnchr(temp1,'#',7),strnchr(temp1,'#',8));
         strcpy(all1[i]->khoon,temp2);
         temp2=between(strnchr(temp1,'#',8),strnchr(temp1,'#',9));
        all1[i]->sen=atoi(temp2);
         temp2=between(strnchr(temp1,'#',9),strnchr(temp1,'#',10));
        all1[i]->qad=atoi(temp2);
         temp2=between(strnchr(temp1,'#',10),strnchr(temp1,'#',11));
        all1[i]->vazn=atoi(temp2);
         temp2=between(strnchr(temp1,'#',11),temp1+strlen(temp1));
        all1[i]->healthcode=atoi(temp2);
    }
    for(int i=0;i<counter2;i++){
                if(fptr2)
            fgets(temp1,200,fptr2);
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        strcpy(all2[i]->name,temp2);
        temp2=between(strnchr(temp1,'#',2),strnchr(temp1,'#',3));
         strcpy(all2[i]->lastname,temp2);
        temp2=between(strnchr(temp1,'#',3),strnchr(temp1,'#',4));
         strcpy(all2[i]->codemelli,temp2);
         temp2=between(strnchr(temp1,'#',4),strnchr(temp1,'#',5));
         strcpy(all2[i]->namekaarbari,temp2);
         temp2=between(strnchr(temp1,'#',5),strnchr(temp1,'#',6));
         strcpy(all2[i]->ramz,temp2);
         temp2=between(strnchr(temp1,'#',6),strnchr(temp1,'#',7));
         strcpy(all2[i]->email,temp2);
         temp2=between(strnchr(temp1,'#',7),strnchr(temp1,'#',8));
         strcpy(all2[i]->namemakan,temp2);
         temp2=between(strnchr(temp1,'#',8),strnchr(temp1,'#',9));
         strcpy(all2[i]->shahr,temp2);
         temp2=between(strnchr(temp1,'#',9),strnchr(temp1,'#',10));
        all2[i]->mantaqe=atoi(temp2);
         temp2=between(strnchr(temp1,'#',10),temp1+strlen(temp1));
        all2[i]->plchealth=atoi(temp2);
    }
    for(int i=0;i<counter3;i++){
                if(fptr3)
        fgets(temp1,200,fptr3);
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        strcpy(all3[i]->name,temp2);
        temp2=between(strnchr(temp1,'#',2),strnchr(temp1,'#',3));
         strcpy(all3[i]->shahr,temp2);
         temp2=between(strnchr(temp1,'#',3),temp1+strlen(temp1));
        all3[i]->mantaqe=atoi(temp2);
    }
    for(int i=0;i<counter4;i++){
                if(fptr4)
        fgets(temp1,200,fptr4);
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        strcpy(all4[i]->name,temp2);
        temp2=between(strnchr(temp1,'#',2),strnchr(temp1,'#',3));
         strcpy(all4[i]->lastname,temp2);
        temp2=between(strnchr(temp1,'#',3),strnchr(temp1,'#',4));
         strcpy(all4[i]->codemelli,temp2);
         temp2=between(strnchr(temp1,'#',4),strnchr(temp1,'#',5));
         strcpy(all4[i]->namekaarbari,temp2);
         temp2=between(strnchr(temp1,'#',5),strnchr(temp1,'#',6));
         strcpy(all4[i]->ramz,temp2);
         temp2=between(strnchr(temp1,'#',6),strnchr(temp1,'#',7));
         strcpy(all4[i]->email,temp2);
         temp2=between(strnchr(temp1,'#',7),strnchr(temp1,'#',8));
         strcpy(all4[i]->khoon,temp2);
         temp2=between(strnchr(temp1,'#',8),strnchr(temp1,'#',9));
        //  strcpy(all4[i]->sen,temp2);
        all4[i]->sen=atoi(temp2);
         temp2=between(strnchr(temp1,'#',9),strnchr(temp1,'#',10));
        //  strcpy(all4[i]->qad,temp2);
        all4[i]->qad=atoi(temp2);
         temp2=between(strnchr(temp1,'#',10),temp1+strlen(temp1));
        //  strcpy(all4[i]->vazn,temp2);
        all4[i]->vazn=atoi(temp2);
        // temp2=between(strnchr(temp1,'#',11),strnchr(temp1,'#',12));
        //  temp2=between(strnchr(temp1,'#',11),temp1+strlen(temp1));
        //  strcpy(all4[i]->healthcode,temp2);
        // all4[i]->healthcode=atoi(temp2);
    }
    ///////////////////////////////////////
    for(int i=0;i<counter1;i++){
        int k1=0,k2=0;
        temp1[0]='\0';
        if(fptr5)
        fgets(temp1,500,fptr5);
        if(*temp1){
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'-',1));
        all1[i]->times1[k1]=atoi(temp2);
        k1++;
        for(int j=1;j<19;j++){
                 temp2=between(strnchr(temp1,'-',j),strnchr(temp1,'-',j+1));
   if(j%2==1){
               all1[i]->healthcodes[k2]=atoi(temp2);
               k2++;
   }
   if(j%2==0){
               all1[i]->times1[k1]=atoi(temp2);
               k1++;
   }
        }
temp2=between(strnchr(temp1,'-',19),temp1+strlen(temp1));
 all1[i]->healthcodes[k2]=atoi(temp2);
        k2++;
    }



}
    for(int i=0;i<counter1;i++){
        int k1=0,k2=0;
        temp1[0]='\0';
        if(fptr6)
        fgets(temp1,500,fptr6);
        if(*temp1){
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'-',1));
        all1[i]->times2[k1]=atoi(temp2);
        k1++;
        for(int j=1;j<19;j++){
                 temp2=between(strnchr(temp1,'-',j),strnchr(temp1,'-',j+1));
   if(j%2==1){
               strcpy(all1[i]->codemellies[k2],temp2);
               k2++;
   }
   if(j%2==0){
               all1[i]->times2[k1]=atoi(temp2);
               k1++;
   }
        }
temp2=between(strnchr(temp1,'-',19),temp1+strlen(temp1));
               strcpy(all1[i]->codemellies[k2],temp2);
        k2++;
    }


}
    for(int i=0;i<counter1;i++){
        int k1=0,k2=0;
        temp1[0]='\0';
        if(fptr7)
        // fgets(temp1,500,fptr6);
        fgets(temp1,500,fptr7);
        if(*temp1){
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'-',1));
        all1[i]->times3[k1]=atoi(temp2);
        k1++;
        for(int j=1;j<19;j++){
                 temp2=between(strnchr(temp1,'-',j),strnchr(temp1,'-',j+1));
   if(j%2==1){
               strcpy(all1[i]->plcnames[k2],temp2);
               k2++;
   }
   if(j%2==0){
               all1[i]->times3[k1]=atoi(temp2);
               k1++;
   }
        }
temp2=between(strnchr(temp1,'-',19),temp1+strlen(temp1));
               strcpy(all1[i]->plcnames[k2],temp2);
        k2++;
    }



}


return ;
}
void setcounters(void){
    int numofhash1=0;
    int numofhash2=0;
    int numofhash3=0;
    int numofhash4=0;
    int numofhash5=0;
    FILE *fptr1;
    FILE *fptr2;
    FILE *fptr3;
    FILE *fptr4;
    FILE *fptr5;
    fptr1=fopen("data1.txt","r");
    fptr2=fopen("data2.txt","r");
    fptr3=fopen("data3.txt","r");
    fptr4=fopen("data4.txt","r");
    fptr5=fopen("data5.txt","r");
    char temp='!';
    // if(!fptr1)
    // return;
    if(fptr1)
    while(!feof(fptr1)){
        temp=fgetc(fptr1);
        if(temp=='#')
        numofhash1++;
    }
    // if(!fptr2)
    // return;
    temp='!';
    if(fptr2)
    while(!feof(fptr2)){
        temp=fgetc(fptr2);
        if(temp=='#')
        numofhash2++;
    }
    temp='!';
    // if(!fptr3)
    // return;
    if(fptr3)
    while(!feof(fptr3)){
        temp=fgetc(fptr3);
        if(temp=='#')
        numofhash3++;
    }
    temp='!';
    if(fptr4)
    while(!feof(fptr4)){
        temp=fgetc(fptr4);
        if(temp=='#')
        numofhash4++;
    }
    // if(fptr5)
    // while(!feof(fptr5)){
    //     temp=fgetc(fptr5);
    //     if(temp=='#')
    //     numofhash5++;
    // }
   numofhash1/=TOTALHASH1;
   numofhash2/=TOTALHASH2;
   numofhash3/=TOTALHASH3;
   numofhash4/=TOTALHASH4;
    counter1=numofhash1;
    counter2=numofhash2;
    counter3=numofhash3;
    counter4=numofhash4;
    // counter5=numofhash5;
    // counter5=counter1;
    return ;
}
void showmenu1(int k,normacc **all1){
    system("cls");
    int menu;
    while(flag1  && flag2 &&flag3){
            system("cls");
        stctofile();
        int temptime=time(0);
        if(all1[k]->times1[0]){
        // int temptime=time(0);
      int v=0;
      while(all1[k]->times1[v]!=0)
       v++;
       v--;
       int res=temptime-(all1[k]->times1[v]);
       if(res>=604800){
        //   if(all1[k]->healthcode==4)
        //   all1[k]->healthcode=3;
           if(all1[k]->healthcode==3)
           all1[k]->healthcode=2;
           if(all1[k]->healthcode==2)
           all1[k]->healthcode=1;

       }
        }
    printf("salam %s , be \"imeno+\" khoosh omadi ! :)\n",all1[k]->name);
    printf("code salamatie shoma %d mibashad\nya'ani shoma ",all1[k]->healthcode);
                if(all1[k]->healthcode==1) printf("salem hastid");
                if(all1[k]->healthcode==2) printf("mashkook be dashtane bimari hastid");
                if(all1[k]->healthcode==3) printf("khatarnaak hastid(be ehtemaale ziad bimaar hastid)");
                if(all1[k]->healthcode==4) printf("bimaar hastid :(");
     printf("\nbaraye edame , code morede nazare khod ra vared nama'Ed :\n");
                puts("1-virayeshe etela'At");
                puts("2-sabte Akharin v'Aziate salamati");
                puts("3-moshahede tarikhche vorood vaziat salamat");
                puts("4-sabte molaaqaat ba sayer afraad");
                puts("5-taarikhcheye molaaqaat ha");
                puts("6-ezaafe kardan mahal haye rafte");
                puts("7-moshahede tarikhche mahal haye rafte");
                puts("8-moshahede Amaare corona");
                puts("9-moshahede bimarestaan va markaz haaye darmaani atraaf");
                puts("10-qofl kardan(khorooj az hesaabe kaarbari)");
                puts("11-khorooj az barname");
                scanf("%d",&menu);
                if(menu==1){
                system("cls");
                changeinfo1(k);
                }
                if(menu==2){
                    int healthcheker=0;
                    int healthcheker1;
                    system("cls");
                    puts("lotfan be so'Alaate zir ba deqat javab dahid.");
                    printf("dar soorate dashtane har yek az al'Aeme ");
                    puts("zir , '1' va dar soorate nadashtane Anha , '0' ra vared konid");
                    printf("sorfe khoshk ba te'daade ziad:");
                    scanf("%d",&healthcheker1);
                    puts("");
                    if(healthcheker1==1)
                    healthcheker+=30;
                    printf("tabe baalaaye 37 daraje:");
                    scanf("%d",&healthcheker1);
                     puts("");
                    if(healthcheker1==1)
                    healthcheker+=20;
                    printf("tangi nafas:");
                    scanf("%d",&healthcheker1);
                     puts("");
                    if(healthcheker1==1)
                    healthcheker+=20;
                    printf("dard va kooftegi badan:");
                    scanf("%d",&healthcheker1);
                     puts("");
                    if(healthcheker1==1)
                    healthcheker+=15;
                    printf("galoo dard:");
                    scanf("%d",&healthcheker1);
                     puts("");
                    if(healthcheker1==1)
                    healthcheker+=15;
                    if(all1[k]->healthcode==1){
                    if(healthcheker>-1 && healthcheker<16)
                    all1[k]->healthcode=1;
                    if(healthcheker>15 && healthcheker<51)
                    all1[k]->healthcode=2;
                    if(healthcheker>50 && healthcheker<76)
                    all1[k]->healthcode=3;
                    if(healthcheker>74 && healthcheker<101)
                    all1[k]->healthcode=4;
                    printf("code salamatie shoma %d mibashad\nya'ani shoma ",all1[k]->healthcode);
                if(all1[k]->healthcode==1) puts("salem hastid");
                if(all1[k]->healthcode==2) puts("mashkook be dashtane bimari hastid");
                if(all1[k]->healthcode==3) puts("khatarnaak hastid(be ehtemaale ziad bimaar hastid)");
                if(all1[k]->healthcode==4) puts("bimaar hastid :(");
getchar();
getchar();
for(int i=0;i<10;i++){
                  if(all1[k]->times1[i]==0){
                      all1[k]->times1[i]=time(0);
                      all1[k]->healthcodes[i]=all1[k]->healthcode;
                      break;
                  }
              }
                    }
else{
    puts("code salamatie shoma 1 nist\nbe hamin khater nmitavanid codesalamti khod ra fe'lan taqir dahid :(");
    getchar();
    getchar();
}


                 system("cls");
                }
                if(menu==3){
                    system("cls");
                    int i=0;
                    char *c=(char *)malloc(50*sizeof(char));
                    time_t temp;
                    printf("shomare tarikh                   codesalamti\n");
                  while(all1[k]->times1[i]!=0){
                      printf(" %-7d",i+1);
                      temp=all1[k]->times1[i];
                      c=ctime(&(temp));
                      c[strlen(c)-1]='\0';
                      printf("%-25s",c);
                      printf("   %d\n",all1[k]->healthcodes[i]);
                      i++;
                  }

                     getchar();
                    getchar();

                }
                if(menu==4){
                        system("cls");
                    puts("codemelli shakhse morede nazar ra vared konid");
                    char temp[50];
                    scanf("%s",temp);
                    int i=0;
                    while(all1[k]->times2[i])
                    i++;
                    // i--;  //?????
                    strcpy(all1[k]->codemellies[i],temp);
                    all1[k]->times2[i]=time(0);
                    puts("anjam shod!");
                    getchar();
                    getchar();
                    int o=0;
                    while(strcmp(all1[o]->codemelli,temp)){
                          o++;
                          }
                          if(all1[o]->healthcode==2)
                            all1[k]->healthcode=1;
                    if(all1[o]->healthcode==3)
                            all1[k]->healthcode=2;
                            if(all1[o]->healthcode==4)
                            all1[k]->healthcode=3;
                    //  if(!strcmp(all1[i]->codemelli,temp)){
                    //      if(all1[i]->healthcode==4)
                    //       all1[k]->healthcode=3;
                    //       if(all1[i]->healthcode==3)
                    //       all1[k]->healthcode=2;

                    //  }

                }
                if(menu==5){
                    system("cls");
                    int i=0;
                    char *c=(char *)malloc(50*sizeof(char));
                    time_t temp;
                    printf("shomare codemelli       tarikh                   codesalamti\n");
                  while(all1[k]->times2[i]!=0){
                      printf(" %-7d",i+1);
                      temp=all1[k]->times1[i];
                      c=ctime(&(temp));
                      printf("%-16s",all1[k]->codemellies[i]);
                      c[strlen(c)-1]='\0';
                      printf("%-25s",c);
                      char temp2[50];
                      strcpy(temp2,all1[k]->codemellies[i]);
                      int l=0;
                      while(strcmp(all1[l]->codemelli,temp2))
                            l++;
                      printf("   %d\n",all1[l]->healthcode);
                      i++;
                  }

                     getchar();
                    getchar();


                }
                if(menu==6){
                    char temp[50];
                    puts("esme makaane morede nazare khod ra vared konid");
                    scanf("%s",temp);
                    int i=0;
                    while(strcmp(all2[i]->namemakan,temp) && i<10)
                    i++;
                    int r=0;
                    while(all1[k]->times3[r])
                    r++;
                    if(i==10){
                    puts("esme vared shode eshtebah ast");
                    getchar();
                    getchar();
                    return;
                    }
                    if(all2[i]->plchealth==1){
                        puts("vaziate makaane morede nazare shoma qermez ast\naz raftan be in makan motmaEnid?\n1-bale 2-kheir");
                        int chek1;
                        scanf("%d",&chek1);
                        if(chek1){
                            puts("sabt shod!");
                            if(all1[k]->healthcode==1)
                            all1[k]->healthcode=2;
                            strcpy(all1[k]->plcnames[r],temp);
                            all1[k]->times3[r]=time(0);
                        }
                        if(!chek1){
                            puts("az hamkaarie shoma mamnoonim ! :)");
                        }
                    }
                    else{
                     strcpy(all1[k]->plcnames[r],temp);
                     all1[k]->times3[r]=time(0);
                             puts("sabt shod!");

                    }
                    getchar();
                    getchar();
                }
                if(menu==7){
                     system("cls");
                    int i=0;
                    char *c=(char *)malloc(50*sizeof(char));
                    time_t temp;
                    printf("shomare tarikh                   naame makaan\n");
                  while(all1[k]->times3[i]!=0){
                      printf(" %-7d",i+1);
                      temp=all1[k]->times3[i];
                      c=ctime(&(temp));
                      c[strlen(c)-1]='\0';
                      printf("%-25s",c);
                    //   printf("   %d\n",all1[k]->healthcodes[i]);
                     printf("%s",all1[k]->plcnames[i]);

                      i++;
                  }

                     getchar();
                    getchar();

                }
                if(menu==8){
                    int i=0;
                    printf("shomare esm             tarikhe ebtela\n");
                    for(i=0;i<counter1;i++){

                     if(all1[i]->healthcode==4){
                         printf(" %-7d",i+1);
                         printf("%-16s",all1[i]->name);
                         int r=0;
                         while(all1[i]->times1[r])
                         r++;
                         r--;
                         time_t temp3;
                         temp3=all1[i]->times1[r];
                         printf("%d\n",ctime(&temp3));
                     }
                    }

                    getchar();
                    getchar();
                }
                if(menu==9){
//                    allhospitals();
printf("shomare esm             shahr           mantaqe\n");
for(int i=0;i<counter3;i++){
    printf(" %-7d",i+1);
    printf("%-16s",all3[i]->name);
    printf("%-16s",all3[i]->shahr);
    printf(" %d\n",all3[i]->mantaqe);

}
getchar();
getchar();
                }
                if(menu==10)
                flag2=0;
                if(menu==11)
                flag1=0;
                if(menu!=1 && menu!=2 && menu!=3 && menu!=4 && menu!=5 && menu!=11){
                if(menu!=6 && menu!=7 && menu!=8 && menu!=9 && menu!=10 && menu!=12){
                    system("cls");
                    puts("adade vared shode sahih nist :( , lotfan dobare talash konid...");
getchar();
getchar();
}
                }

    }
    return;
}
void showmenu2(int k,supacc **all2){
                system("cls");
                int menu;
                while(flag1 && flag2 && flag3){
                        system("cls");
                printf("salam %s , be \"imeno+\" khoosh omadi ! :)\n",all2[k]->name);
                printf("vaaziate makaane shoma ");
                if(all2[k]->plchealth==0) puts("sefid mibashad");
                if(all2[k]->plchealth==1) puts("qermez mibashad");
                printf("\nbaraye edame , code morede nazare khod ra vared nama'Ed :\n");
                puts("1-moshahedeye v'Aziate makaan");
                puts("2-etel'A daadan baraye zedde ofooni");
                puts("3-te'daad afraad mobtalaa");
                puts("4-qofl kardan(khorooj az hesaabe kaarbari)");
                puts("5-khorooj az barname");
                scanf("%d",&menu);
                if(menu==1){
                 system("cls");
                 printf("vaaziate makaane shoma ");
                if(all2[k]->plchealth==0) puts("sefid mibashad");
                if(all2[k]->plchealth==1) puts("qermez mibashad");
                }
                if(menu==2){
                    system("cls");
                    puts("sabt shod...");
getchar();
getchar();
puts("vaaziate makane shoma , sefid shod");
                  all2[k]->plchealth=0;
getchar();
getchar();
}
                if(menu==3){
                    system("cls");
                    printf("num name      lastname        codemelli       healthcode\n");
                    int n=0;
                    for(int j=2;j<5;j++)
                    for(int i=0;i<counter1;i++){
//                    if(*(all1[i]->name))
                    if(all1[i]->healthcode==j){
                            for(int d=0;d<10;d++){
                                if(!strcmp(all1[i]->plcnames[d],all2[k]->name)){
                                printf("%-4d",n+1);
                        printf("%-10s",all1[i]->name);
                        printf("%-16s",all1[i]->lastname);
                        printf("%-16s",all1[i]->codemelli);
                        printf("  %d\n",j);
                        n++;
                                }
                            }
//                        printf("%-4d",n+1);
//                        printf("%-10s",all1[i]->name);
//                        printf("%-16s",all1[i]->lastname);
//                        printf("%-16s",all1[i]->codemelli);
//                        printf("  %d\n",j);
//                        n++;
                    }
                    }
                    getchar();
                    getchar();
                system("cls");
                }
                if(menu==4)
                flag2=0;
                if(menu==5)
                flag1=0;
                if(menu!=1 && menu!=2 && menu!=3 && menu!=4 && menu!=5){
                    system("cls");
                    puts("adade vared shode sahih nist :( , lotfan dobare talash konid...");
getchar();
getchar();
}
                }
    return;
}
void showmenu3(hospital **all3){

                int menu;
                while(flag1 && flag2 && flag3){
                      system("cls");
                printf("salam admin , be \"imeno+\" khoosh omadi ! :)\n");
                printf("baraye edame , code morede nazare khod ra vared nama'Ed :\n");
                puts("1-vared kardane bimaarestaan");
                puts("2-moshahedeye Aamaar");
                puts("3-vaared kardane afraade behbood yaafte");
                puts("4-moshaahedeye tamaamiye kaarbaraan");
                puts("5-moshaahedeye foot shodegaan");
                puts("6-moshaahedeye tamaamiye kasb o kar haaye sabt shode");
                puts("7-moshaahedeye bimarestaan haaye sabt shode");
                puts("8-qofl kardan(khorooj az hesaabe kaarbari)");
                puts("9-khorooj az barname");
                scanf("%d",&menu);
                if(menu==1){
                addhospital(all3);
                }
                if(menu==2){
                    system("cls");
                    printf("num name      lastname        codemelli\n");
                    for(int i=0;i<TOTALNORMACC;i++)
                    if(all1[i]->healthcode==4){
                        printf("%-4d",i+1);
                        printf("%-10s",all1[i]->name);
                        printf("%-16s",all1[i]->lastname);
                        printf("  %s\n",all1[i]->codemelli);
                    }
                    getchar();
                    getchar();
                }
                if(menu==3){
                    puts("1-ezafe kardan afraade behbood yaafte\n2-ezafe kardan afraade fot shode");
                    int menu1;
                    scanf("%d",&menu1);
                     puts("codemelli shakhse morede nazar raa vared konid");
                        char temp[50];
                        scanf("%s",temp);
                        int k;
                        for(int i=0;i<TOTALNORMACC;i++){
                            if(!strcmp(all1[i]->codemelli,temp)){
                                k=i;
                            break;
                            }
                        }
                    if(menu1==1){
                        all1[k]->healthcode=2;
                        puts("anjam shod!");
                        getchar();
                        getchar();

                    }
                    else{
                        FILE *fptr4;
                        fptr4=fopen("data4.txt","w+");
                        strcpy(all4[counter4]->name,all1[k]->name);
                        strcpy(all4[counter4]->lastname,all1[k]->lastname);
                        strcpy(all4[counter4]->codemelli,all1[k]->codemelli);
                        strcpy(all4[counter4]->namekaarbari,all1[k]->namekaarbari);
                        strcpy(all4[counter4]->ramz,all1[k]->ramz);
                        strcpy(all4[counter4]->email,all1[k]->email);
                        strcpy(all4[counter4]->khoon,all1[k]->khoon);
                        all4[counter4]->sen=all1[k]->sen;
                        all4[counter4]->qad=all1[k]->qad;
                        all4[counter4]->vazn=all1[k]->vazn;
for(int i=k;i<counter1-1;i++)
all1[i]=all1[i+1];
all1[counter1-1]=all1[99];
counter4++;
    stctofile();
                    }
                }
                if(menu==4){
                    allmember();
                }
                if(menu==5){
                system("cls");
    FILE *fptr4;
    fptr4=fopen("data4.txt","r+");
    char *temp1=(char *)malloc(200*sizeof(char));
    char *temp2=(char *)malloc(200*sizeof(char));
    printf("num name        lastname      codemelli\n");
    for(int i=0;i<counter4;i++){
        printf("%-4d",i+1);
        fgets(temp1,200,fptr4);
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        printf("%-12s",temp2);
        temp2=between(strnchr(temp1,'#',2),strnchr(temp1,'#',3));
        printf("%-14s",temp2);
        temp2=between(strnchr(temp1,'#',3),strnchr(temp1,'#',4));
        printf("%s",temp2);

    }
        getchar();
        getchar();
        system("cls");
}
                if(menu==6)
                allplaces();
                if(menu==7)
                allhospitals();
                if(menu==8)
                flag2=0;
                if(menu==9)
                flag1=0;
                if(menu!=1 && menu!=2 && menu!=3 && menu!=4 && menu!=5){
                if(menu!=6 && menu!=7 && menu!=8 && menu!=9){
                    system("cls");
                    puts("adade vared shode sahih nist :( , lotfan dobare talash konid...");
getchar();
getchar();
}
                }

                }

    return;
}
void allmember(void){
    FILE *fptr1;
    fptr1=fopen("data1.txt","r+");
    char *temp1=(char *)malloc(200*sizeof(char));
    char *temp2=(char *)malloc(200*sizeof(char));
    printf("num name        lastname      codemelli       healthcode\n");
    for(int i=0;i<counter1;i++){
        printf("%-4d",i+1);
        fgets(temp1,200,fptr1);
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        printf("%-12s",temp2);
        temp2=between(strnchr(temp1,'#',2),strnchr(temp1,'#',3));
        printf("%-14s",temp2);
        temp2=between(strnchr(temp1,'#',3),strnchr(temp1,'#',4));
        printf("%-15s",temp2);
         temp2=between(strnchr(temp1,'#',11),temp1+strlen(temp1));
        int a=atoi(temp2);
        printf("%d\n",a);

    }
        getchar();
        getchar();
        system("cls");
    return ;
}
void allplaces(void){
    FILE *fptr2;
    fptr2=fopen("data2.txt","r+");
    char *temp1=(char *)malloc(200*sizeof(char));
    temp1[0]='\0';
    char *temp2=(char *)malloc(200*sizeof(char));
    temp2[0]='\0';
    printf("num name        codemelli      placehealthcode\n");
    for(int i=0;i<counter2;i++){
            fgets(temp1,200,fptr2);
                    if(temp1[0]){
        printf("%-4d",i+1);

        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        printf("%-12s",temp2);
        temp2=between(strnchr(temp1,'#',3),strnchr(temp1,'#',4));
        printf("%-14s",temp2);
         temp2=between(strnchr(temp1,'#',10),temp1+strlen(temp1));
        int a=atoi(temp2);
        printf("%d\n",a);
                    }
    }
        getchar();
        getchar();
        system("cls");
    return ;
}
void allhospitals(void){
    FILE *fptr3;
    fptr3=fopen("data3.txt","r+");
    char *temp1=(char *)malloc(200*sizeof(char));
    char *temp2=(char *)malloc(200*sizeof(char));
    printf("num name        city      region\n");
    temp1[0]='\0';
    temp2[0]='\0';
    for(int i=0;i<counter3;i++){
                    fgets(temp1,200,fptr3);
    if(temp1[0]){
        printf("%-4d",i+1);
        temp1[strlen(temp1)-1]='\0';
        temp2=between(strnchr(temp1,'#',1),strnchr(temp1,'#',2));
        printf("%-12s",temp2);
        temp2=between(strnchr(temp1,'#',2),strnchr(temp1,'#',3));
        printf("%-10s",temp2);
         temp2=between(strnchr(temp1,'#',3),temp1+strlen(temp1));
        int a=atoi(temp2);
        printf("%d\n",a);
    }

    }
        getchar();
        getchar();
        system("cls");
    return ;
}
void login(void){
      int loginchek=0;
             // placehealthcode ha ---> 0=sefid , 1=qermez
             for(int i=0;i<counter1;i++)
             if(!strcmp(chek[0],all1[i]->namekaarbari))
              if(!strcmp(chek[1],all1[i]->ramz)){
                showmenu1(i,all1);
                loginchek=1;
                flag2=0;
                break;
              }
            for(int i=0;i<counter2;i++)
             if(!strcmp(chek[0],all2[i]->namekaarbari))
              if(!strcmp(chek[1],all2[i]->ramz)){
                showmenu2(i,all2);
                loginchek=1;
                flag2=0;
                break;
              }
              if(!strcmp(admin[0],chek[0]))
               if(!strcmp(admin[1],chek[1])){
               showmenu3(all3);
               loginchek=1;
               flag2=0;
            //   break;
               }
            if(loginchek==0){
                system("cls");
            puts("username va ya password sahih nist :( , lotfan dobare emtehan konid");
getchar();
getchar();

            }
return ;
}
char* starpass(char password[51]){
    int count = 0;
    while (1)
    {
        password[count] = getch();
        if (password[count] == '\b' && count > 0)
        {
            printf("\b \b");
            count--;
        }
        else if (password[count] == '\b' && count == 0)
        {
            printf("\b \b");
        }
        else if (password[count] != '\r')
        {
            printf("*");
            count++;
        }
        else if (password[count] == '\r')
        {
            count++;
            break;
        }
    }
    password[count - 1] = '\0';

    return password;
}





