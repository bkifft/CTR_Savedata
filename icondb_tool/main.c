#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

const unsigned char null_entry[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

void app_title(void);
void help(char *app_name);

void main(int argc, char *argv[])
{
	if(argc != 4){
		printf("[!] Bad arguments\n");
		help(argv[0]);
		return;
	}
	FILE *idbt = fopen(argv[1],"rb");
	FILE *idb = fopen(argv[2],"rb");
	
	chdir(argv[3]);
	
	unsigned char *buffer = malloc(0x36c0);
	for(int i = 0; i < 360/*360*/; i++){
		memset(buffer,0,0x36c0);
		fseek(idbt,0x8+(0x10*i),SEEK_SET);
		fseek(idb,0x0+(0x36a0*i),SEEK_SET);
		unsigned char tmp[8];
		fread(&tmp,8,1,idbt);
		if(memcmp(&tmp,null_entry,8) != 0){
			char iconname[30];
			sprintf(iconname,"%03d_%02x%02x%02x%02x%02x%02x%02x%02x.icn",i,tmp[7],tmp[6],tmp[5],tmp[4],tmp[3],tmp[2],tmp[1],tmp[0]);
			fread(buffer,0x36c0,1,idb);
			FILE *icon = fopen(iconname,"wb");
			fwrite("SMDH",4,1,icon);
			fseek(icon,8,SEEK_SET);
			fwrite(buffer+0x20,0x2000,1,icon);
			fseek(icon,0x2040,SEEK_SET);
			fwrite(buffer+0x2020,0x2000,1,icon);
			fclose(icon);
		}
	}
	
	fclose(idbt);
	fclose(idb);
	printf("Done\n");
}

void app_title(void)
{
	printf("0xf000000b IDB Tool\n");
}

void help(char *app_name)
{
	app_title();
	printf("\nUsage: <idbt.dat> <idb.dat> <Out-Dir>\n", app_name);
}