#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <processthreadsapi.h>

//program struct data mahasiswa dengan tambahan pengurutan data berdasarkan NPM paling kecil
//github : https://github.com/arifwidiasan
//repository CRUD : https://github.com/arifwidiasan/crud-ArrayofStruct-C
//repository sorting : https://github.com/arifwidiasan/Sorting-struct-c
//repository advance sorting : https://github.com/arifwidiasan/advance-sorting-struct-c (prjoct ini)

struct data_mahasiswa{
	char npm[12];
	char nama[50];
	char kota[50];
	char nohp[50];
	char umur[4];
	char jurusan[50];
	char semester[4];
};
typedef struct data_mahasiswa mhs;

mhs data[50],tmp;

int size=0,x;
void tambah(char npm[12],char nama[50],char kota[50], char nohp[50], char umur[4], char jurusan[50], char semester[4]){
	strcpy(data[size].npm,npm);
	strcpy(data[size].nama,nama);
	strcpy(data[size].kota,kota);
	strcpy(data[size].nohp,nohp);
	strcpy(data[size].umur,umur);
	strcpy(data[size].jurusan,jurusan);
	strcpy(data[size].semester,semester);
	size++;
}

void tampil(){
	int i;
	if(size>0){
		for(i=0;i<size;i++){
			x=strlen(data[i].npm);
			if(x>=1){
			printf("\nMahasiswa ke - [%d]\n",i);
			printf("NPM \t\t\t: %s\n",data[i].npm);	
			printf("Nama \t\t\t: %s\n",data[i].nama);
			printf("Kota \t\t\t: %s\n",data[i].kota);
			printf("No HP \t\t\t: %s\n",data[i].nohp);
			printf("Umur \t\t\t: %s\n",data[i].umur);
			printf("Jurusan \t\t: %s\n",data[i].jurusan);
			printf("Semester \t\t: %s\n\n",data[i].semester);	
			}
		}
	}
}
int main() {
	size = sizeof(mhs)/sizeof(data[0]);
	int i=1,y,z,coba,m,n,indexNilaiMinimal,pilih_data;
	int pilih=0,pilih_edit,pilih_sort=0,asc_desc=0;
	char npm[12],nama[50],kota[50],nohp[14],umur[4],jurusan[50],semester[3];
	awal:
	printf("====== Data Mahasiswa ======\n");
	printf("Menu :\n1. Tampil Data\n2. Tambah Data\n3. Update Data\n4. Hapus Data\n5. Pengurutan Data\n6. Keluar\nPilih menu : ");
	scanf("%d",&pilih);
	if(pilih==1){
		printf("List Data Mahasiswa: \n\n");
		tampil();
		printf("\nTekan sembarang tombol untuk lanjut");
		getch();
		system("cls");
		goto awal;
	}
	else if(pilih==2){
		printf("\nNPM : ");
		scanf("%s",&npm);
		printf("Nama : ");
		scanf(" %[^\n]s",&nama);
		printf("Kota : ");
		scanf("%s",&kota);
		printf("No HP : ");
		scanf("%s",&nohp);
		printf("Umur : ");
		scanf("%s",&umur);
		printf("Jurusan : ");
		scanf("%s",&jurusan);
		printf("Semester : ");
		scanf("%s",&semester);
		tambah(npm,nama,kota,nohp,umur,jurusan,semester);
		printf("\nData Berhasi Ditambahkan!");
		getch();
		system("cls");
		goto awal;	
	}else if(pilih==3){
		int no;
		tampil();
		printf("Masukkan nomor data mahasiswa ke-[x] yang ingin diedit : ");
		inputedit:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data mahasiswa nomor ke %d, mohon masukkan nomor kembali : ");
			goto inputedit;
		}else{
			system("cls");
			printf("======Pengeditan Data Mahasiswa======");
			printf("\nNPM \t\t\t: %s\n",data[no].npm);	
			printf("Nama \t\t\t: %s\n",data[no].nama);
			printf("Kota \t\t\t: %s\n",data[no].kota);
			printf("No HP \t\t\t: %s\n",data[no].nohp);
			printf("Umur \t\t\t: %s\n",data[no].umur);
			printf("Jurusan \t\t: %s\n",data[no].jurusan);
			printf("Semester \t\t: %s\n\n",data[no].semester);
			printf("\nPilih data yang ingin diedit sesuai nomor (1.npm;2.nama;3.kota;4.no hp;5.umur;6.jurusan;7.semester) = ");
			scanf("%d",&pilih_edit);
			if(pilih_edit==1){
				printf("\nNPM : ");
				scanf(" %[^\n]%*c",data[no].npm);
			}
			else if(pilih_edit==2){
				printf("\nNama : ");
				scanf(" %[^\n]%*c",data[no].nama);	
			}
			else if(pilih_edit==3){
				printf("\nKota : ");
				scanf(" %[^\n]%*c",data[no].kota);	
			}
			else if(pilih_edit==4){
				printf("\nNo HP : ");
				scanf(" %[^\n]%*c",data[no].nohp);	
			}
			else if(pilih_edit==5){
				printf("\nUmur : ");
				scanf(" %[^\n]%*c",data[no].umur);	
			}
			else if(pilih_edit==6){
				printf("\nJurusan : ");
				scanf(" %[^\n]%*c",data[no].jurusan);	
			}
			else if(pilih_edit==7){
				printf("\nSemester : ");
				scanf(" %[^\n]%*c",data[no].semester);	
			}else{
				printf("\npilihan salah");
			}
			printf("\nData berhasil diedit !");
			getch();
			system("cls");
			goto awal;
		}
	}else if(pilih==4){
		int no;
		tampil();
		printf("\nMasukkan nomor data yang akan dihapus : ");
		inputhapus:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data mahasiswa nomor ke %d, mohon masukkan kembali : ");
			goto inputhapus;
		}else{
			for(no;no<size;no++){
			strcpy(data[no].npm,data[no+1].npm);
			strcpy(data[no].nama,data[no+1].nama);
			strcpy(data[no].kota,data[no+1].kota);
			strcpy(data[no].nohp,data[no+1].nohp);
			strcpy(data[no].umur,data[no+1].umur);
			strcpy(data[no].jurusan,data[no+1].jurusan);
			strcpy(data[no].semester,data[no+1].semester);
		}
			printf("data berhasil dihapus");
			getch();
			system("cls");
			goto awal;
		}
	}else if(pilih==5){
		//pemilihan bubble sort atau selection sort
		printf("\nPilih metode yang digunakan! (1.Bubble Sort, 2.Selection Sort) = ");
		scanf(" %d",&pilih_sort);
		if(pilih_sort==1){
			//pemilihan ascending atau descending pada bubble sort
			printf("\nPilih model pengurutan ! (1.Ascending, 2.Descending) = ");
			scanf(" %d",&asc_desc);
			printf("\nPilih ingin mengurutkan berdasarkan data apa \n1.NPM \n2.Nama \n3.Kota \n4.No HP \n5.umur \n6.jurusan \n7.semester\n = ");
			scanf(" %d",&pilih_data);
			//ascending bubble sort
			if(asc_desc==1){
				if(pilih_data==1){
					//mengurutkan berdasarkan npm
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].npm, data[z+1].npm) > 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan NPM terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==2){
					//mengurutkan berdasarkan nama
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].nama, data[z+1].nama) > 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Nama terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==3){
					//mengurutkan berdasarkan kota
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].kota, data[z+1].kota) > 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Kota terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==4){
					//mengurutkan berdasarkan no.hp
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].nohp, data[z+1].nohp) > 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan No.hp terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==5){
					//mengurutkan berdasarkan umur
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].umur, data[z+1].umur) > 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Umur terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==6){
					//mengurutkan berdasarkan jurusan
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].jurusan, data[z+1].jurusan) > 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Jurusan terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==7){
					//mengurutkan berdasarkan semester
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].semester, data[z+1].semester) > 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Semester terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else{
					printf("\nPILIHAN SALAH/TIDAK TERSEDIA!");
					getch();
					system("cls");
					goto awal;
				}
			//descending bubble sort
			}else if(asc_desc==2){
				if(pilih_data==1){
					//mengurutkan berdasarkan npm
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].npm, data[z+1].npm) < 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan NPM terbesar, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==2){
					//mengurutkan berdasarkan nama
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].nama, data[z+1].nama) < 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Nama terbesar, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==3){
					//mengurutkan berdasarkan kota
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].kota, data[z+1].kota) < 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Kota terbesar, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==4){
					//mengurutkan berdasarkan nohp
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].nohp, data[z+1].nohp) < 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan No.hp terbesar, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==5){
					//mengurutkan berdasarkan umur
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].umur, data[z+1].umur) < 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Umur terbesar, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==6){
					//mengurutkan berdasarkan jurusan
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].jurusan, data[z+1].jurusan) < 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Jurusan terbesar, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==7){
					//mengurutkan berdasarkan semester
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(y=0;y<size;y++){
						for(z=0;z<size-1;z++){
							if(strcmp(data[z].semester, data[z+1].semester) < 0){
							tmp = data[z];
							data[z] = data[z+1];
							data[z+1] = tmp;
							}
						}
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Semester terbesar, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else{
					printf("\nPILIHAN SALAH/TIDAK TERSEDIA!");
					getch();
					system("cls");
					goto awal;
				}
			}else{
				printf("\nPILIHAN SALAH/TIDAK TERSEDIA!");
				getch();
				system("cls");
				goto awal;
			}
		}else if(pilih_sort==2){
			//pemilihan ascending dan descending pada selection sort
			printf("\nPilih model pengurutan ! (1.Ascending, 2.Descending) = ");
			scanf(" %d",&asc_desc);
			printf("\nPilih ingin mengurutkan berdasarkan data apa \n1.NPM \n2.Nama \n3.Kota \n4.No HP \n5.umur \n6.jurusan \n7.semester\n = ");
			scanf(" %d",&pilih_data);
			//ascending selection sort
			if(asc_desc==1){
				if(pilih_data==1){
					//mengurutkan berdasarkan npm
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].npm, data[indexNilaiMinimal].npm) < 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan NPM terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==2){
					//mengurutkan berdasarkan nama
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].nama, data[indexNilaiMinimal].nama) < 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Nama terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==3){
					//mengurutkan berdasarkan kota
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].kota, data[indexNilaiMinimal].kota) < 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Kota terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==4){
					//mengurutkan berdasarkan nohp
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].nohp, data[indexNilaiMinimal].nohp) < 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan No.hp terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==5){
					//mengurutkan berdasarkan umur
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].umur, data[indexNilaiMinimal].umur) < 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Umur terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==6){
					//mengurutkan berdasarkan jurusan
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].jurusan, data[indexNilaiMinimal].jurusan) < 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Jurusan terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==7){
					//mengurutkan berdasarkan semester
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].semester, data[indexNilaiMinimal].semester) < 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Semester terkecil!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else{
					printf("\nPILIHAN SALAH/TIDAK TERSEDIA!");
					getch();
					system("cls");
					goto awal;
				}
			}else if(asc_desc==2){
				if(pilih_data==1){
					//mengurutkan berdasarkan npm
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].npm, data[indexNilaiMinimal].npm) > 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan NPM terbesar!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==2){
					//mengurutkan berdasarkan nama
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].nama, data[indexNilaiMinimal].nama) > 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Nama terbesar!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==3){
					//mengurutkan berdasarkan kota
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].kota, data[indexNilaiMinimal].kota) > 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Kota terbesar!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==4){
					//mengurutkan berdasarkan no.hp
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].nohp, data[indexNilaiMinimal].nohp) > 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan No.hp terbesar!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==5){
					//mengurutkan berdasarkan umur
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].umur, data[indexNilaiMinimal].umur) > 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Umur terbesar!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==6){
					//mengurutkan berdasarkan jurusan
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].jurusan, data[indexNilaiMinimal].jurusan) > 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Jurusan terbesar!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else if(pilih_data==7){
					//mengurutkan berdasarkan semester
					clock_t start = clock()/CLOCKS_PER_SEC;
					for(m=0; m<size; m++){
					indexNilaiMinimal=m;
						for(n=m; n<size; n++){
							if(strcmp(data[n].semester, data[indexNilaiMinimal].semester) > 0){
								indexNilaiMinimal=n;
							}
						}
					//swap value (tukar)
						tmp=data[m];
						data[m]=data[indexNilaiMinimal];
						data[indexNilaiMinimal]=tmp;
					}
					clock_t end = clock()/CLOCKS_PER_SEC*100;
					double elapsed = (double)(end - start);
					printf("\nwaktu eksekusi = %.3f",elapsed);
					printf("\nData berhasil diurutkan berdasarkan Semester terbesar!, silakan pilih menu tampil data untuk melihat hasilnya");
					getch();
					system("cls");
					goto awal;
				}else{
					printf("\nPILIHAN SALAH/TIDAK TERSEDIA!");
					getch();
					system("cls");
					goto awal;
				}
			}else{
				printf("\nPILIHAN SALAH/TIDAK TERSEDIA!");
				getch();
				system("cls");
				goto awal;
			}
			
		}else{
			printf("\nPILIHAN SALAH/TIDAK TERSEDIA!");
			getch();
			system("cls");
			goto awal;
			
		}
	}else if(pilih==6){
		printf("\nTerima Kasih!");
	}else{
		printf("Inputan anda salah.");
	}
	return 0;
}
