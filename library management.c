#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct book{
	int book_id;
	char book_name[30];
	int books_available;
	struct book *blink;
}bk;
typedef struct student{
	char student_id[7];
	char student_name[30];
	struct book *book1;
	struct book *book2;
	struct book *book3;
	struct book *book4;
	struct student *slink;
	int issuedate_book1,issuedate_book2,issuedate_book3,issuedate_book4;
	int returndate_book1,returndate_book2,returndate_book3,returndate_book4;


}std;

bk* addbook(bk *p){
	bk *temp=NULL;
	bk *temp1=NULL,*temp2=NULL;
	temp1=p;
	temp=(bk*) malloc(sizeof(bk));
	printf("enter the book id\n");
	int n,ba;
	char name[30];
	scanf("%d",&n);
	printf("enter the name of the book\n");
	scanf("%s",name);
	printf("enter the no of books available\n");
	printf("%d",&ba);
	temp->book_id=n;
	strcpy(temp->book_name,name);
	temp->books_available=ba;
	if(p==NULL){
		p=temp;
		return p;
	}
	else{
		while(temp1!=NULL){
			temp2=temp1;
			if(strcmp((temp->book_name),(temp1->book_name))<=0){
				if(temp1==p){
					temp->blink=temp1;
					p=temp;
					return p;
				}
				else{
					temp->blink=temp1;
					temp2->blink=temp;
					return p;
				}
			}
		}
		if(temp1==NULL){
			temp2->blink=temp;
			return p;
		}
	}
}

std* issue(std *q);
std* reissue(std *r );
std* return_book(std *t);
bk *donate(bk *p);
void fine(std *y);
void display_book(bk *w);
void display_student(std *e);



int main(){
	printf("*********************Welcome To Library management*****************\n");
	printf("******************************NIT PATNA****************************\n");
	std *studentroot=NULL,*studentend=NULL;
	bk *bookroot=NULL;
	printf("----------------------Creation of book Database--------------------\n");
	// after creating books
	while(1){
		printf("enter the id no of student\n");
		char u[7];
		scanf("%s",u);
		std *temp=NULL,*temp2=NULL;
		std *qq=NULL;
		temp=studentroot;

		if(studentroot==NULL){
			printf("student record not found.........creating new student record\n");
			std *t=NULL;
			t=(std*) malloc(sizeof(std));
			printf("enter the name of student\n");
			char sname[30];
			scanf("%s",sname);
			strcpy(t->student_name,sname);
			strcpy(t->student_id,u);
			studentroot=t;
			qq=t;

		}
		else{
			while(temp!=NULL){
				temp2=temp;
				if(temp->student_id==u){
					qq=temp;
					break;
				}
				temp=temp->slink;
			}
			if(temp==NULL){
				std *t=NULL;
			t=(std*) malloc(sizeof(std));
			printf("enter the name of student\n");
			char sname[30];
			scanf("%s",sname);
			strcpy(t->student_name,sname);
			strcpy(t->student_id,u);
				temp2->slink=t;
				qq=t;
			}
		}

	}
}
