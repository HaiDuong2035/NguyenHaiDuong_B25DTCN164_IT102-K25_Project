#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct Book{
	int bookId;
	char title [50];
	char author [50];
	int publishYear;
	int quantity;
};
struct Date{
	int day;
	int month;
	int year;
};
struct Borrow{
	int	borrowId;
	int	bookId;
	struct Date borrowDate;
	struct Date borrowReturn;
	char borrowerName [50];
	int status;
};
int isEmptyString(char str[]) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (!isspace(str[i])) {
			return 0;
		}
	}
	return 1;
}
int checkTime(int day, int month, int year){
	if (day<1){
		return 0;
	}
	if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
		if (day>31){
			return 0;
		}
	}
	if (month==4 || month==6 || month==9 || month==11){
		if (day>30){
			return 0;
		}
	}
	if (month==2){
		if ((year%4==0 && year%100!=0) || (year%400==0)){
			if (day>29){
				return 0;
			}
		} else {
			if (day>28){
				return 0;
			}
		}
	}
	if (month<1 || month>12){
		return 0;
	}
	return 1;
}
void addBook(struct Book *book, int n,int id, struct Book a[]){
	int i, checkTitle=0, checkPublishYear=0, checkQuantity=0, number;
	char publishYear [4], quantity [5], str [50];
	book->bookId=id;
	printf("\nMa sach: %d\n",book->bookId);
	do {
		checkTitle=0;
		while (1){
			printf("\nNhap tieu de: ");
			gets(book->title);
			strcpy(str,book->title);
			if(strlen(book->title)==0 || isEmptyString(str)){
				printf("\nTieu de khong duoc de trong\n");
				continue;
			} else {
				break;
			}
		}
		for (i=0; i<n; i++){
			if (strcmp(a[i].title, book->title)==0){
				printf("\nTieu de da ton tai\n");
				checkTitle=1;
				break;
			}
		}
	} while(checkTitle==1);
	while (1){
		printf("\nNhap tac gia: ");
		gets(book->author);
		strcpy(str,book->author);
		if(strlen(book->author)==0 || isEmptyString(str)){
			printf("\nTac gia khong duoc de trong\n");
			continue;
		} else {
			break;
		}
	}
	while(checkPublishYear==0){
		number=0, checkPublishYear=1;
		printf("\nNhap nam phat hanh: ");
		gets(publishYear);
		if(strlen(publishYear)==0){
			printf("\nKhong duoc de trong\n");
	        checkPublishYear=0;
		}
		for (i = 0; i < strlen(publishYear); i++) {
	        if (!isdigit(publishYear[i])){
	        	printf("\nPhai nhap so nguyen\n");
	        	checkPublishYear=0;
				break;
			}
	    }
		number = atoi(publishYear);
		if (number<1901 && checkPublishYear==1){
			printf("\nPhai nhap vao nam lon hon 1900\n");
			checkPublishYear=0;
		}
	    if (checkPublishYear==0){
	    	continue;
		}
		book->publishYear=number;
	}
	while(checkQuantity==0){
		number=0, checkQuantity=1;
		printf("\nNhap so luong sach: ");
		gets(quantity);
		if(strlen(quantity)==0){
			printf("\nKhong duoc de trong\n");
			checkQuantity=0;
		} else {
			for (i = 0; i < strlen(quantity); i++) {
		        if (!isdigit(quantity[i])){
		        	printf("\nPhai nhap so nguyen\n");
		        	checkQuantity=0;
					break;
				}
		    }
		}
		if (checkQuantity==0){
			continue;
		}
		number = atoi(quantity);
		book->quantity=number;
	}
}
void changeBook(int n, struct Book a[]){
	int checkTitle=0, checkId=0, checkFind=0, pos, id, checkPublishYear=0, checkQuantity=0, i, number;
	char publishYear [4], quantity [5], find [5], str [50];
	while (checkId==0){
		number=0, checkId=1;
		printf("\nNhap id cua sach can sua: ");
		gets(find);
		if(strlen(find)==0){
			printf("\nKhong duoc de trong");
	        checkId=0;
	    	continue;
		}
		for (i = 0; i < strlen(find); i++) {
	        if (!isdigit(find[i])){
	        	printf("\nPhai nhap so nguyen");
	        	checkId=0;
				break;
			}
	    }
		number=atoi(find);
	}
	for (i=0; i<n; i++){
		if (number==a[i].bookId){
			id=a[i].bookId;
			pos=i;
			checkFind=1;
		}
	}
	if (checkFind==0){
		printf("\nKhong tim thay sach");
		return;
	}
	printf("\n=====Thong tin sach=====");
 	printf("\nMa so sach: %d",a[pos].bookId);
    printf("\nTieu de: %s",a[pos].title);
    printf("\nTac gia: %s",a[pos].author);
    printf("\nNam phat hanh: %d",a[pos].publishYear);
    printf("\nSo luong: %d",a[pos].quantity);
    printf("\n\n=====Cap nhat thong tin sach=====");
	do {
		checkTitle=0;
		while (1){
			printf("\nNhap tieu de moi: ");
			gets(a[pos].title);
			strcpy(str,a[pos].title);
			if(strlen(a[pos].title)==0 || isEmptyString(str)){
				printf("\nTieu de khong duoc de trong\n");
				continue;
			}else{
				break;				
			}
		}
		for (i=0; i<n; i++){
			if (a[i].bookId==id){
				continue;
			}
			if (strcmp(a[i].title, a[pos].title)==0){
				printf("\nTieu de da ton tai\n");
				checkTitle=1;
				break;
			}
		}
	} while(checkTitle==1);
	while (1){
		printf("\nNhap tac gia moi: ");
		gets(a[pos].author);
			strcpy(str,a[pos].author);
		if(strlen(a[pos].author)==0 || isEmptyString(str)){
			printf("\nTac gia khong duoc de trong\n");
			continue;
		}else{
			break;				
		}
	}
	while(checkPublishYear==0){
		number=0, checkPublishYear=1;
		printf("\nNhap nam phat hanh: ");
		gets(publishYear);
		if(strlen(publishYear)==0){
			printf("\nKhong duoc de trong\n");
	        checkPublishYear=0;
	    	continue;
		}
		for (i = 0; i < strlen(publishYear); i++) {
	        if (!isdigit(publishYear[i])){
	        	printf("\nPhai nhap so nguyen\n");
	        	checkPublishYear=0;
				break;
			}
	    }
		number = atoi(publishYear);
		if (number<1901 && checkPublishYear==1){
			printf("\nPhai nhap vao nam lon hon 1900\n");
			checkPublishYear=0;
	    	continue;
		}
	    if (checkPublishYear==0){
	    	continue;
		}
		a[pos].publishYear=number;
	}
	while(checkQuantity==0){
		number=0, checkQuantity=1;
		printf("\nNhap so luong sach moi: ");
		gets(quantity);
		if(strlen(quantity)==0){
			printf("\nKhong duoc de trong\n");
			checkQuantity=0;
		} else {
			for (i = 0; i < strlen(quantity); i++) {
		        if (!isdigit(quantity[i])){
		        	printf("\nPhai nhap so nguyen\n");
		        	checkQuantity=0;
					break;
				}
		    }
		}
		if (checkQuantity==0){
			continue;
		}
		number=atoi(quantity);
		a[pos].quantity=number;
	}
}
void listBook(int n, struct Book a[]){
	int numPage=10, totalPage, out=0, page=1, i, number, j;
	char choicePage [5];
	if (n%numPage==0){
		totalPage=n/numPage;
	} else {
		totalPage=n/numPage+1;
	}
	while (out==0){
		system("cls");
		printf("\n|");
		for (j=0; j<48; j++){
			printf("-");
		}
		printf("DANH SACH");
		for (j=0; j<48; j++){
			printf("-");
		}
		printf("|");
		printf("\n|Trang %-2d/%-96d|\n",page,totalPage);
		printf("|");
		for (j=0; j<105; j++){
			printf("-");
		}
		printf("|");
		printf("\n| Ma so sach | %-30s | %-30s | Nam phat hanh | So luong |","Tieu de","Tac gia");
		for (i=(page-1)*numPage; i<page*numPage; i++){
			if (i<n){
				printf("\n|");
				for (j=0; j<105; j++){
					printf("-");
				}
				printf("|");
				printf("\n| %-10d | %-30s | %-30s | %-13d | %-8d |",a[i].bookId,a[i].title,a[i].author,a[i].publishYear,a[i].quantity);
			}
		}
		if (totalPage==1){
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-103s |","2.Quay lai menu");
			printf("\n|");
			for (i=0; i<105; i++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 2:
					out=1;
					break;
				default:
					printf("\nLua chon khong hop le");
					out=1;
					break;
			}
		} else if (page==1){
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-50s | %-50s |","2.Quay lai menu","3.Trang sau");
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 2:
					out=1;
					break;
				case 3:
					page++;
					break;
				default:
					printf("Lua chon khong hop le");
					out=1;
					break;
			}
		} else if (page==totalPage){
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-50s | %-50s |","1.Trang truoc","2.Quay lai menu");
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 1:
					page--;
					break;
				case 2:
					out=1;
					break;
				default:
					printf("Lua chon khong hop le");
					out=1;
					break;
			}
		} else {
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-32s | %-33s | %-32s |","1.Trang truoc","2.Quay lai menu","3.Trang sau");
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 1:
					page--;
					break;
				case 2:
					out=1;
					break;
				case 3:
					page++;
					break;
				default:
					printf("Lua chon khong hop le");
					out=1;
					break;
			}
		}
	}
}
void deleteBook(int *nBo, struct Book book[], struct Borrow borrow[], int nBr){
	int checkId=0, i, number, checkFind=0, pos, out=0, numConfirm;
	char find [5], confirm [5];
	while (checkId==0){
		number=0, checkId=1;
		printf("\nNhap id cua sach can xoa: ");
		gets(find);
		if(strlen(find)==0 || strcmp(find," ")==0){
			printf("\nKhong duoc de trong\n");
	        checkId=0;
	    	continue;
		}
		for (i = 0; i < strlen(find); i++) {
	        if (!isdigit(find[i])){
	        	printf("\nPhai nhap so nguyen\n");
	        	checkId=0;
				break;
			}
	    }
		number=atoi(find);
	}
	for (i=0; i<(*nBo); i++){
		if (number==book[i].bookId){
			pos=i;
			checkFind=1;
		}
	}
	if (checkFind==0){
		printf("\nKhong tim thay sach");
		return;
	}
	for (i=0; i<nBr; i++){
		if (borrow[i].bookId==book[pos].bookId){
			if (borrow[i].status==1){
				printf("\nKhong the xoa sach vi co nguoi dang muon");
				return;
			}
		}
	}
	printf("\n========================================");
	printf("\nMa so sach   : %d",book[pos].bookId);
    printf("\nTieu de      : %s",book[pos].title);
    printf("\nTac gia      : %s",book[pos].author);
    printf("\nNam phat hanh: %d",book[pos].publishYear);
    printf("\nSo luong     : %d\n",book[pos].quantity);
	while (out==0){
		printf("\n========================================");
		printf("\nBan chac chan muon xoa khong?");
		printf("\n1.Huy");
		printf("\n2.Xoa");
		printf("\nNhap lua chon: ");
		fgets(confirm,sizeof(confirm),stdin);
		confirm[strcspn(confirm,"\n")]='\0';
		numConfirm=atoi(confirm);
		printf("\n========================================");
		switch (numConfirm){
			case 1:
				printf("\n\nThoat ra menu");
				return;
				break;
			case 2:
				out=1;
				break;
			default:
				printf("\n\nLua chon khong hop le\n");
				break;
		}
	}
	for (i=pos; i<(*nBo)-1; i++){
	 	book[i]=book[i+1];
	}
	(*nBo)--;
	printf("\n\nXoa sach thanh cong");
}
void findBook(struct Book a[], int n){
	int i, j, checkFind=0;
	char find [50], temp [50];
	while (1){
		printf("\nNhap tieu de sach can tim: ");
		gets(find);
		if(strlen(find)==0 || isEmptyString(find)){
			printf("\nKhong duoc de trong");
			continue;
		}else{
			break;
		}
	}
	for (i=0; find[i]!='\0'; i++){
		find[i]=tolower(find[i]);
	}
	for (i=0; i<n; i++){
		strcpy(temp,a[i].title);
		for (j=0; temp[j]!='\0'; j++){
			temp[j]=tolower(temp[j]);
		}
		if (strstr(temp,find)){
			checkFind=1;
		}
	}
	if (checkFind==0){
		printf("\nKhong tim thay sach");
		return;
	}
	printf("\n|");
	for (j=0; j<45; j++){
		printf("-");
	}
	printf("SACH TRUNG KHOP");
	for (j=0; j<45; j++){
		printf("-");
	}
	printf("|");
	for (i=0; i<n; i++){
		strcpy(temp,a[i].title);
		for (j=0; temp[j]!='\0'; j++){
			temp[j]=tolower(temp[j]);
		}
		if (strstr(temp,find)){
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-10d | %-30s | %-30s | %-13d | %-8d |",a[i].bookId,a[i].title,a[i].author,a[i].publishYear,a[i].quantity);
		}
	}
	printf("\n|");
	for (j=0; j<105; j++){
		printf("-");
	}
	printf("|");
}
int addBorrow(struct Borrow *borrow, struct Borrow listBorrow[], struct Book book[],int n, int *idBr, int idBo, int *numBr){
	int checkId=0, checkFind=0, number, i, pos, checkDay=0, checkMonth=0, checkYear=0, out=0, numConfirm;
	char find [5], day [2], month [2], year [4], confirm [5], str [50];
	borrow->borrowId=(*idBr);
	printf("\n=====Nhap thong tin phieu muon=====");
	printf("\n\nMa phieu muon: %d\n",borrow->borrowId);
	while (checkId==0){
		number=0, checkId=1;
		printf("\nNhap id cua sach can muon: ");
		gets(find);
		if(strlen(find)==0){
			printf("\nKhong duoc de trong\n");
	        checkId=0;
	    	continue;
		}
		for (i=0; i<strlen(find); i++) {
	        if (!isdigit(find[i])){
	        	printf("\nPhai nhap so nguyen\n");
	        	checkId=0;
				break;
			}
	    }
		number=atoi(find);
		borrow->bookId=number;
	}
	for (i=0; i<n; i++){
		if (number==book[i].bookId){
			pos=i;
			checkFind=1;
		}
	}
	if (checkFind==0){
		printf("\nKhong tim thay sach co ma trung khop");
		return 0;
	}
	if (book[pos].quantity==0){
		printf("\nHet sach");
		return 0;
	}
	printf("\n========================================");
	printf("\nMa so sach   : %d",book[pos].bookId);
    printf("\nTieu de      : %s",book[pos].title);
    printf("\nTac gia      : %s",book[pos].author);
    printf("\nNam phat hanh: %d",book[pos].publishYear);
    printf("\nSo luong     : %d",book[pos].quantity);
	printf("\n========================================\n");
	while (out==0){
		printf("\nBan muon cuon sach nay khong?");
		printf("\n1.Khong");
		printf("\n2.Co");
		printf("\nNhap lua chon: ");
		fgets(confirm,sizeof(confirm),stdin);
		confirm[strcspn(confirm,"\n")]='\0';
		numConfirm=atoi(confirm);
		switch (numConfirm){
			case 1:
				return;
				break;
			case 2:
				out=1;
				break;
			default:
				printf("\nLua chon khong hop le");
				break;
		}
	}
	do {
		checkDay=0, checkMonth=0, checkYear=0;
		while(checkDay==0){
			number=0, checkDay=1;
			printf("\nNhap ngay muon sach: ");
			gets(day);
			if(strlen(day)==0){
				printf("\nKhong duoc de trong\n");
				checkDay=0;
			} else {
				for (i = 0; i < strlen(day); i++) {
			        if (!isdigit(day[i])){
			        	printf("\nPhai nhap so nguyen\n");
			        	checkDay=0;
						break;
					}
			    }
			}
			if (checkDay==0){
				continue;
			}
			number=atoi(day);
			borrow->borrowDate.day=number;
		}
		while(checkMonth==0){
			number=0, checkMonth=1;
			printf("\nNhap thang muon sach: ");
			gets(month);
			if(strlen(month)==0){
				printf("\nKhong duoc de trong\n");
				checkMonth=0;
			} else {
				for (i = 0; i < strlen(month); i++) {
			        if (!isdigit(month[i])){
			        	printf("\nPhai nhap so nguyen\n");
			        	checkMonth=0;
						break;
					}
			    }
			}
			if (checkMonth==0){
				continue;
			}
			number=atoi(month);
			borrow->borrowDate.month=number;
		}
		while(checkYear==0){
			number=0, checkYear=1;
			printf("\nNhap nam muon sach: ");
			gets(year);
			if(strlen(year)==0){
				printf("\nKhong duoc de trong\n");
				checkYear=0;
			} else {
				for (i = 0; i < strlen(year); i++) {
			        if (!isdigit(year[i])){
			        	printf("\nPhai nhap so nguyen\n");
			        	checkYear=0;
						break;
					}
			    }
			}
			if (checkYear==0){
				continue;
			}
			number=atoi(year);
			borrow->borrowDate.year=number;
		}
		if((!checkTime(borrow->borrowDate.day,borrow->borrowDate.month,borrow->borrowDate.year)) || (borrow->borrowDate.year<book[pos].publishYear)){
			printf("\nNgay thang nam khong hop le\n");
		}
	} while (!checkTime(borrow->borrowDate.day,borrow->borrowDate.month,borrow->borrowDate.year) || (borrow->borrowDate.year<book[pos].publishYear));
	while (1){
		printf("\nNhap ten nguoi muon: ");
		gets(borrow->borrowerName);
		strcpy(str,borrow->borrowerName);
		if(strlen(borrow->borrowerName)==0 || isEmptyString(str)){
			printf("\nTen nguoi muon khong duoc de trong\n");
			continue;
		}else{
			break;
		}
	}
	borrow->borrowReturn.day=0;
	borrow->borrowReturn.month=0;
	borrow->borrowReturn.year=0;
	borrow->status=1;
	book[pos].quantity--;
	(*idBr)++;
	(*numBr)++;
	printf("\nThem phieu muon thanh cong");
}
void deleteBorrow(int *nBr, struct Borrow borrow[], struct Book book[], int nBo){
	int checkId=0, number, i, checkFind=0, pos, checkDay=0, checkMonth=0, checkYear=0, checkReturnTime;
	char find [5], day [2], month [2], year [4];
	while (checkId==0){
		number=0, checkId=1;
		printf("\nNhap ma phieu muon de tra: ");
		gets(find);
		if(strlen(find)==0){
			printf("\nKhong duoc de trong\n");
	        checkId=0;
	    	continue;
		}
		for (i=0; i<strlen(find); i++) {
	        if (!isdigit(find[i])){
	        	printf("\nPhai nhap so nguyen\n");
	        	checkId=0;
				break;
			}
	    }
		number=atoi(find);
	}
	for (i=0; i<(*nBr); i++){
		if (borrow[i].borrowId==number){
			checkFind=1;
			pos=i;
			break;
		}
	}
	if (checkFind==0){
		printf("\nKhong tim thay sach");
		return;
	}
	if (borrow[pos].status==0){
		printf("\nSach da duoc tra");
		return;
	}
	do {
		checkDay=0, checkMonth=0, checkYear=0, checkReturnTime=1;
		while(checkDay==0){
			number=0, checkDay=1;
			printf("\nNhap ngay tra sach: ");
			gets(day);
			if(strlen(day)==0){
				printf("\nKhong duoc de trong\n");
				checkDay=0;
			} else {
				for (i = 0; i < strlen(day); i++) {
			        if (!isdigit(day[i])){
			        	printf("\nPhai nhap so nguyen\n");
			        	checkDay=0;
						break;
					}
			    }
			}
			if (checkDay==0){
				continue;
			}
			number=atoi(day);
			borrow[pos].borrowReturn.day=number;
		}
		while(checkMonth==0){
			number=0, checkMonth=1;
			printf("\nNhap thang tra sach: ");
			gets(month);
			if(strlen(month)==0){
				printf("\nKhong duoc de trong\n");
				checkMonth=0;
			} else {
				for (i = 0; i < strlen(month); i++) {
			        if (!isdigit(month[i])){
			        	printf("\nPhai nhap so nguyen\n");
			        	checkMonth=0;
						break;
					}
			    }
			}
			if (checkMonth==0){
				continue;
			}
			number=atoi(month);
			borrow[pos].borrowReturn.month=number;
		}
		while(checkYear==0){
			number=0, checkYear=1;
			printf("\nNhap nam tra sach: ");
			gets(year);
			if(strlen(year)==0){
				printf("\nKhong duoc de trong\n");
				checkYear=0;
			} else {
				for (i = 0; i < strlen(year); i++) {
			        if (!isdigit(year[i])){
			        	printf("\nPhai nhap so nguyen\n");
			        	checkYear=0;
						break;
					}
			    }
			}
			if (checkYear==0){
				continue;
			}
			number=atoi(year);
			borrow[pos].borrowReturn.year=number;
		}
		if (borrow[pos].borrowReturn.year==borrow[pos].borrowDate.year){
			if (borrow[pos].borrowReturn.month==borrow[pos].borrowDate.month){
				if (borrow[pos].borrowReturn.day<=borrow[pos].borrowDate.day){
					checkReturnTime=0;
				}
			} else if (borrow[pos].borrowReturn.month<borrow[pos].borrowDate.month){
				checkReturnTime=0;
			}
		} else if (borrow[pos].borrowReturn.year<borrow[pos].borrowDate.year){
			checkReturnTime=0;
		}
		if((!checkTime(borrow[pos].borrowReturn.day,borrow[pos].borrowReturn.month,borrow[pos].borrowReturn.year)) || (!checkReturnTime)){
			printf("\nNgay thang nam khong hop le\n");
		}
	} while ((!checkTime(borrow[pos].borrowReturn.day,borrow[pos].borrowReturn.month,borrow[pos].borrowReturn.year)) || (!checkReturnTime));
	for (i=0; i<nBo; i++){
		if (book[i].bookId==borrow[pos].bookId){
			book[i].quantity++;
		}
	}
	borrow[pos].status=0;
	printf("\nTra sach thanh cong");
}
void listBorrow(int n, struct Borrow a[]){
	int numPage=10, totalPage, out=0, page=1, i, number, j;
	char status [10], choicePage [5];
	if (n%numPage==0){
		totalPage=n/numPage;
	} else {
		totalPage=n/numPage+1;
	}
	while (out==0){
		system("cls");
		number=0;
		printf("\n|");
		for (j=0; j<48; j++){
			printf("-");
		}
		printf("DANH SACH");
		for (j=0; j<48; j++){
			printf("-");
		}
		printf("|");
		printf("\n| Trang %-2d/%-94d |",page,totalPage);
		printf("\n|");
		for (j=0; j<105; j++){
			printf("-");
		}
		printf("|");
		printf("\n| Ma phieu muon | Ma sach | Thoi gian muon | Thoi gian tra | %-31s | Trang thai |","Ten nguoi muon");
		for (i=(page-1)*numPage; i<page*numPage; i++){
			if (a[i].status==0){
				strcpy(status,"Da tra");
			} else {
				strcpy(status,"Dang muon");
			}
			if (i<n){
				printf("\n|");
				for (j=0; j<105; j++){
					printf("-");
				}
				printf("|");
				printf("\n| %-13d | %-7d | %-2d/%-2d/%-8d | %-2d/%-2d/%-7d | %-31s | %-10s |",a[i].borrowId,a[i].bookId,a[i].borrowDate.day,a[i].borrowDate.month,a[i].borrowDate.year,a[i].borrowReturn.day,a[i].borrowReturn.month,a[i].borrowReturn.year,a[i].borrowerName,status);
			}
		}
		if (totalPage==1){
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-103s |","2.Quay lai menu");
			printf("\n|");
			for (i=0; i<105; i++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 2:
					out=1;
					break;
				default:
					printf("\nLua chon khong hop le");
					out=1;
					break;
			}
		} else if (page==1){
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-50s | %-50s |","2.Quay lai menu","3.Trang sau");
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 2:
					out=1;
					break;
				case 3:
					page++;
					break;
				default:
					printf("Lua chon khong hop le");
					out=1;
					break;
			}
		} else if (page==totalPage){
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-50s | %-50s |","1.Trang truoc","2.Quay lai menu");
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 1:
					page--;
					break;
				case 2:
					out=1;
					break;
				default:
					printf("Lua chon khong hop le");
					out=1;
					break;
			}
		} else {
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\n| %-32s | %-33s | %-32s |","1.Trang truoc","2.Quay lai menu","3.Trang sau");
			printf("\n|");
			for (j=0; j<105; j++){
				printf("-");
			}
			printf("|");
			printf("\nNhap lua chon: ");
			fgets(choicePage,sizeof(choicePage),stdin);
			choicePage[strcspn(choicePage,"\n")]='\0';
			number=atoi(choicePage);
			switch (number){
				case 1:
					page--;
					break;
				case 2:
					out=1;
					break;
				case 3:
					page++;
					break;
				default:
					printf("Lua chon khong hop le");
					out=1;
					break;
			}
		}
	}
}
int main(){
	int numBook=11, idBook=12, idBorrow=12, numBorrow=11, number;
	char choice [5];
	struct Book bookList[10000] = {
		{1, "Lap Trinh C", "Nguyen Van A", 2005, 10},
	    {2, "Cau Truc Du Lieu", "Tran Thi B", 2018, 5},
	    {3, "Mang May Tinh", "Le Van C", 2020, 15},
	    {4, "He Dieu Hanh", "Pham Thi D", 2010, 8},
	    {5, "Co So Du Lieu", "Hoang Van E", 2015, 12},
	    {6, "Kinh Te Vi Mo", "Tran Van F", 2022, 10},
	    {7, "Tieng Anh Chuyen Nganh", "Le Thi G", 2019, 7},
	    {8, "Marketing Co Ban", "Nguyen Van H", 2021, 14},
	    {9, "Phap Luat Dai Cuong", "Hoang Thi K", 2017, 9},
	    {10, "Giai Tich 1", "Pham Van L", 2016, 20},
	    {11, "Giai Tich 2", "Pham Van L", 2004, 19},
	};
	struct Borrow borrowList[10000] = {
		{1, 1, {25, 11, 2025}, {10, 12, 2025}, "Pham Minh T", 1},
	    {2, 3, {10, 10, 2025}, {10, 11, 2025}, "Le Van H", 0},
	    {3, 5, {15, 11, 2025}, {15, 12, 2025}, "Tran Thi M", 0}, 
		{4, 2, {01, 9, 2025}, {15, 9, 2025}, "Nguyen Van A", 1}, 
	    {5, 4, {05, 11, 2025}, {05, 12, 2025}, "Bui Thi C", 1},
	    {6, 6, {8, 11, 2025}, {20, 12, 2025}, "Dinh Van D", 0}, 
	    {7, 7, {12, 10, 2025}, {25, 10, 2025}, "Hoang Minh E", 0},
	    {8, 9, {20, 11, 2025}, {30, 12, 2025}, "Vu Thi F", 1},
	    {9, 10, {01, 12, 2025}, {15, 01, 2026}, "Mai Van G", 1},
	    {10, 11, {03, 10, 2025}, {03, 11, 2025}, "Cao Thi H", 0}, 
	    {11, 11, {20, 8, 2025}, {29,11,2025}, "Le Thi Phuong M", 0},
	};
	while (number!=9){
		system("cls");
		number=0;
		printf("\n|---------------MENU---------------|");
		printf("\n| 1.Them moi sach                  |");
		printf("\n| 2.Cap nhat thong tin danh sach   |");
		printf("\n| 3.Hien thi danh sach             |");
		printf("\n| 4.Xoa thong tin sach             |");
		printf("\n| 5.Tim kiem sach                  |");
		printf("\n| 6.Them moi phieu muon            |");
		printf("\n| 7.Tra sach                       |");
		printf("\n| 8.Hien thi danh sach phieu muon  |");
		printf("\n| 9.Thoat                          |");
		printf("\n|----------------------------------|");
		printf("\nNhap lua chon: ");
		fgets(choice,sizeof(choice),stdin);
		choice[strcspn(choice,"\n")]='\0';
		number=atoi(choice); 
		switch (number){
			case 1:
				if (numBook==10000){
					printf("\nThem sach that bai");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				printf("\n=====Nhap thong tin sach=====");
				addBook(&bookList[numBook],numBook,idBook,bookList);
				idBook++;
				numBook++;
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 2:
				if (numBook==0){
					printf("\nCap nhat sach that bai");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				printf("\n=====Sua thong tin sach=====");
				changeBook(numBook, bookList);
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 3:
				if (numBook==0){
					printf("\nDanh sach sach trong");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				listBook(numBook, bookList);
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 4:
				if (numBook==0){
					printf("\nXoa sach that bai");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				deleteBook(&numBook, bookList,borrowList,numBorrow);
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 5:
				if (numBook==0){
					printf("\nTim sach that bai");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				findBook(bookList,numBook);
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 6:
				if (numBook==0){
					printf("\nThem moi phieu muon that bai");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				addBorrow(&borrowList[numBorrow],borrowList,bookList,numBook,&idBorrow,idBook,&numBorrow);
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 7:
				if (numBorrow==0){
					printf("\nTra sach that bai");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				deleteBorrow(&numBorrow,borrowList,bookList,numBook);
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 8:
				if (numBorrow==0){
					printf("\nDanh sach phieu muon trong");
					printf("\nNhan Enter de tiep tuc");
					getchar();
					break;
				}
				system("cls");
				listBorrow(numBorrow,borrowList);
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
			case 9:
				printf("\nKet thuc chuong trinh");
				break;
			default:
				printf("\nLua chon khong hop le");
				printf("\nNhan Enter de tiep tuc");
				getchar();
				break;
		}
	}
}

