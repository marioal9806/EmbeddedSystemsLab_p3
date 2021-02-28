#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int size, cont=0;
	char ch, ans, name[100], id[100];
	while(((ch = getopt(argc, argv, "s:")) != -1) && (ch != 255))
		switch(ch){
			case 's':
			size = atoi(optarg);	
			break;
			default:
			fprintf(stderr, "Invalid option %s", optarg);
		}
	if (ch == -1 ){
		printf("You must specify a size\n");
		return 1;
	}
	FILE *f = fopen("Datalog.txt", "w");
	if (f == NULL)
		{
		fprintf(stderr,"Error opening file!\n");
		exit(1);
		}
		while(ans != 'n'){
			printf("Enter Name:");
			scanf("%s",name);
			fprintf(f, "%s ", name);
                        printf("Enter ID:");
                        scanf("%s",id);
                        fprintf(f, "%s\n", id);
			cont++;
			if(cont>=size){
				break;
			}
                        printf("Do you wish to add more [Y/n]:");
			scanf(" %c", &ans);
		}
		fclose(f);
		printf("Students information stored in Datalog.txt\n");
return 0;
}
