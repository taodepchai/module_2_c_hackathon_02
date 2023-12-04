#include<stdio.h>
#include<string.h>
struct Contact{
    int id;
    char name[50];
    char phone[12];
    char address[50];
    int status;
};
typedef struct Contact contact;
void input(contact *temp){
    printf("nhap ma so:");
    scanf("%d",&temp->id);
    printf("nhap ten:");
    getchar();
    gets(temp->name);
    printf("nhap so dien thoai:");
    getchar();
    gets(temp->phone);
    printf("nhap dia chi:");
    getchar();
    gets(temp->address);
    printf("nhap trang thai:");
    scanf("%d",&temp->status);
}
void output( contact *temp){
    printf("ma so:%d, ten :%s, sdt :%s, dia chi:%s, trang thai:%d\n",temp->id, temp->name, temp->phone, temp->address, temp->status);
}
void name_sort(contact temp[], int index){
    for (int i=0; i<index-1; i++) {
		for (int j=0; j<index-i-1; j++) {
			if (temp[j].name > temp[j+1].name) {
				contact t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
	}
}
int main(){
    int n,i;
    contact contact_list[100];
    printf("nhap vao so nguoi co trong danh sach:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
        input(&contact_list[i]);
    int index = n;
    int choice;
    int check;
    do{
        printf("\n************************MENU**************************\n");
        printf("1.in ra danh sach\n");
        printf("2.them moi vao vi tri cuoi cua danh sach\n");
        printf("3.cap nhat thong tin theo ten cua 1 nguoi trong danh sach\n");
        printf("4.xoa 1 nguoi theo ten cua nguoi do trong danh sach\n");
        printf("5.sap xep danh sach theo ten\n");
        printf("6.tim kiem theo ten(yeu cau chay chuc nang thu 5 truoc)\n");
        printf("7.tim kiem theo status\n");
        printf("8.thoat\n");
        printf("nhap lua chon\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                for (i=0;i<index;i++){
                    printf("%d:",i+1);
                    output(&contact_list[i]);
                }
                break;
            case 2:
                input(&contact_list[index]);
                index++;
                break;
            case 3:
                check = 0;
                char update_name[50];
                printf("nhap vao ten muon cap nhat thong tin:");
                getchar();
                gets(update_name);
                for (i=0;i<index;i++){
                    if ( strcmp(contact_list[i].name,update_name) == 0 ){
                        input(&contact_list[i]);
                        check = 1;
                    }
                }
                if (check == 0) 
                    printf("khong tim thay\n");
                break;
            case 4:
                check = 0;
                char delete_name[50];
                printf("nhap ten nguoi muon xoa:");
                getchar();
                gets(delete_name);
                for (i=0;i<index;i++){
                    if ( strcmp(contact_list[i].name,delete_name) == 0 ){
                        for (int j=i;j<index-1;j++)
                            contact_list[j] = contact_list[j+1];
                            check = 1;
                    }
                }
                index--;
                if (check == 0) 
                    printf("khong tin thay");
                break;
            case 5:
                name_sort(contact_list,index);
                break;
            case 6:
                printf("nhap ten can tim kiem:");
                int find_name[50];
                getchar();
                gets(find_name);
                int start = 0;
                int end = index;
                int mid;
                while( start<=end ) {
                    mid = (start+end) / 2;
                    if ( strcmp(contact_list[mid].name,find_name) == 0 ){
                        break;
                    } else if (contact_list[mid].name < find_name) {
                        start = mid+1;
                    } else {
                        end = mid-1;
                    }
                }
                if ( strcmp(contact_list[mid].name,find_name) == 0 ) {
                    output(&contact_list[mid]);
                } else {
                    printf("Khong tim thay ");
                }
                break;
            case 7:
                check = 0;
                int find_status;
                printf("nhap vao gia tri status can tim:");
                scanf("%d",&find_status);
                for (i=0;i<index;i++){
                    if (find_status == contact_list[i].status){
                        output(&contact_list[i]);
                        check = 1;
                    }
                }
                if (check == 0 )
                    printf("khong tin thay");
                break;
            case 8:
                printf("thoat\n");
            default:
                printf("khong hop le\n");
        }
    } while(choice != 8);   
}