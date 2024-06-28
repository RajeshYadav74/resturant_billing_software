#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void order_details();
void generate_bill_footer(float );
void generatet_bill_header(char[],char[]);
void generate_bill_body(char *,int,float);
void invoice_history();
void search_invoice();


struct item
{
    char item_name[50];
    int quantity;
    float price;
};

struct order_info{
    char cst_name[50];
    char date[30];
    int num_item;
    struct item itm[50];
    
};

 struct order_info ord1,ord2;

 void save_details(struct order_info);

FILE *fp;

float total=0.0;
int opt;
char giv_name[50];
int flag=0;
float total1;



int main()
{   
    int choice;
    char conti='Y';

    while(conti=='Y')
    {     
          printf("\n");
          printf("\t=======Urban Bites Resturant=======\n");
          printf("1.Generate Invoice\n");
          printf("2.Show all Invoices\n");
          printf("3.Search Invoice\n");
          printf("4.Exit\n");
          printf("Your choice: ");
          scanf("%d",&choice);
          fgetc(stdin);
   
      
      switch (choice)
    {
          case 1: 
                  order_details(); break;

          case 2: 
                  invoice_history(); break;

          case 3: 
                  search_invoice();break;
    
         case 4: 
                 printf("Bye Bye");
                 exit(0);

                  
         default : 
                   printf("\nSorry invalid option");          
    
    }

             printf("To continue press Y ");
             scanf("%c",&conti);
     }
     return 0;
}



void order_details()
{            
            system("cls");
             printf("Please enter the name of the costumer:\t");
             gets(ord1.cst_name);
             strcpy(ord1.date,__DATE__);
           
             printf("\nPlease enter the number of item: ");
            
             scanf("%d",&ord1.num_item);
            
             for(int i=0;i<ord1.num_item;i++){
                 
                 fgetc(stdin);
                 printf("\nPlease enter the item %d: ",i+1);
                 gets(ord1.itm[i].item_name);

                 printf("Please enter the quantity: ");
                 scanf("%d",&ord1.itm[i].quantity);

                 printf("Please enter the unit price : ");
                 scanf("%f",&ord1.itm[i].price);

                 total+=ord1.itm[i].quantity*ord1.itm[i].price;
                 
                 }
                 generatet_bill_header(ord1.cst_name,ord1.date);

                 for(int i=0;i<ord1.num_item;i++){
                 generate_bill_body( ord1.itm[i].item_name,ord1.itm[i].quantity,ord1.itm[i].price);
               }
                 generate_bill_footer(total );
                 printf("\nDo you want to save the invoice,if yes press Y ");
                 scanf("%c",&opt);
                 save_details( ord1);              
             }

    

  void generatet_bill_header(char *name,char *dt)
 { 
         
         printf("\n\t Urban Bites Resturant");
         printf("\n");
         for(int i=0;i<40;i++){
           printf("-");
        }

               printf("\n");
               printf("Date: %s",dt);
               printf("\nInvoice To: %s",name);
               printf("\n");
               for(int i=0;i<40;i++){
                    printf("-");
              }

            printf("\nItem\t\t");
            printf("Qty\t\t");
            printf("Total\t\t");
            printf("\n");
            for(int i=0;i<40;i++){
            printf("-");
   }
   printf("\n");
   
   }


    void generate_bill_body(char *it_name,int qty,float price)
  {
       printf("\n%s\t\t",it_name);
       printf("%d\t\t",qty);
       printf("%.2f\t\t",qty*price);
  }


   
   void generate_bill_footer(float total)
   {
     
          float disc=0.1*total;
          float Net_total=total-disc;
          float cgst=0.09*Net_total;
          float grandtotal=Net_total+2*cgst;

           printf("\n");
           for(int i=0;i<40;i++){
                printf("-");
              }
              printf("\n");

             printf("Sub Total\t\t\t%.2f",total);
             printf("\nDiscount @10%%\t\t\t %.2f",disc);
             printf("\n");
             printf("\t\t\t\t--------");
             printf("\n");
             printf("Net Total\t\t\t%.2f",Net_total);
             printf("\ncgst @9%%\t\t\t%.2f",cgst);
             printf("\nsgst @9%%\t\t\t%.2f",cgst);
             printf("\n");
             for(int i=0;i<40;i++){
                 printf("-");
                 }
               printf("\n");

                printf("Grand Total\t\t\t %.2f",grandtotal);
                printf("\n");
               for(int i=0;i<40;i++){
                printf("-"); 
                }
                printf("\n");
  }


  void save_details(struct order_info ord1){

          fp=fopen("billhistory.txt","a+");
          fwrite(&ord1,sizeof(struct order_info),1,fp);
           if(fwrite!=0){
             printf("\nSuccesfully saved");
            }
             else{
                   printf("\nError,please try again");
                 }
         fclose(fp);

  }


  void  invoice_history()
  {         system("cls");
            fp=fopen("billhistory.txt","r");
            printf("\n\t*****Your previous invoices*****");
   
         while(fread(&ord2,sizeof(struct order_info),1,fp))
    {      
                  float total1=0.0;
                   generatet_bill_header(ord2.cst_name,ord2.date);

              for(int i=0;i<ord2.num_item;i++){
             generate_bill_body(ord2.itm[i].item_name,ord2.itm[i].quantity,ord2.itm[i].price);
             total1+=ord2.itm[i].quantity*ord2.itm[i].price;
                 }
                   generate_bill_footer( total1);
                    }
     
              fclose(fp);
       }



   void search_invoice()
   {     system("cls");       
        fp=fopen("billhistory.txt","r");
        
        printf("Please enter a name: ");
        gets(giv_name);
        printf("\n\t*****Invoice of %s*****",giv_name);
    
        while(fread(&ord2,sizeof(struct order_info),1,fp))
    {   
        
           if(strcpy(ord2.cst_name,giv_name)) {
           total1=0.0;
           generatet_bill_header(ord2.cst_name,ord2.date);

            for(int i=0;i<ord2.num_item;i++){
           generate_bill_body(ord2.itm[i].item_name,ord2.itm[i].quantity,ord2.itm[i].price);
           total1+=ord2.itm[i].quantity*ord2.itm[i].price;
                 }
                       generate_bill_footer( total1);
                       flag=1;
                       }
        }
        if(flag==0){
            printf("\nSorry Invoice of %s does not exit",giv_name);
        }
        
      fclose(fp);

   }
   


   
