/*

Author :				A.M.N.P Adikari
Registration Number :	E/14/010
Last Modified Date :	2017.03.03

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET		0
#define BRIGHT 		1
#define DEFAULT		-2

#define BLACK		0
#define RED			1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

#define ZERO 		0
#define ONE			1
#define TWO			2
#define THREE		3
#define FOUR		4
#define FIVE		5
#define SIX			6
#define	SEVEN		7
#define	EIGHT		8	
#define NINE		9
#define DOT			10

// define global variable clockColor
int clockColor;		 		           

// function prototypes
void textcolor(int , int , int );
void printDigitalFigure(int ,int );
void arrangeNumber(int digital_mat[5][6],int raw,int num_of_col);
void subStrn(char str2[],char str1[],int start,int end);
int isValidOption(char );
int isAvailableColor(char color[]);
int getColor(int argc,char **argv);
int checkErrors(int argc,char **argv);


int main(int argc,char **argv){
	
	// define local variables
	int rowCount=5,number_of_figures=8;
	int i,j;
   	time_t tim;
   	char date[20];
   	int hour,minutes,seconds;
   	struct tm *current_time;
	
	if(!checkErrors(argc,argv)){ //Cheack wheather there are errors
   	
		while(1){
   
			time(&tim);
	
			current_time= localtime( &tim); // getting the info of current date & time
   	
			hour=current_time->tm_hour ; // hour 
			minutes=current_time->tm_min;// minutes
			seconds=current_time->tm_sec ;// seconds
			
			strftime(date,20,"%Y-%m-%d",current_time);// taking date in yyyy-MM-dd format
			
   	// all figures in digital clock
			int figures[8]={hour/10,hour%10,DOT,minutes/10,minutes%10,DOT,seconds/10,seconds%10};
   	
		// get user input color 
			clockColor=getColor(argc,argv);
		
			printf("\n"); // print new line
   	
   		
			for(i=0;i<rowCount;i++){
   		
				for(j=0;j<number_of_figures;j++){
		  
					printf(" ");
					printDigitalFigure(figures[j],i); // print the digital figure 
   		
				}
   		
				printf("\n");	// print new line
			}
		
			printf("\n");	// print new line
			textcolor(RESET, clockColor,DEFAULT);
			printf("                      %s",date);
			textcolor(RESET, WHITE,DEFAULT);
			printf("\n");	// print new line
	
	
			sleep(1); // sleep the code executing by one second
	
			printf("\ec"); // reset the terminal or cmd
			
	
		}
		
	}
   	
   	return(0);
}

void textcolor(int attr, int fg, int bg){	
	
	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

void printDigitalFigure(int figure,int raw){
	
	int num_of_col=6;
	
	if(figure==DOT){ // check weather the figure is DOT
		num_of_col=4;	
	}
	
	int digitalZero[5][6]={{1,1,1,1,1,1}, // digital zero
		 		   		   {1,1,0,0,1,1},
				           {1,1,0,0,1,1},
		 		           {1,1,0,0,1,1},
		 		           {1,1,1,1,1,1}};
		 		           
	int digitalOne[5][6]={ {0,0,0,0,1,1}, // digital one
		 		   		   {0,0,0,0,1,1},
				           {0,0,0,0,1,1},
		 		           {0,0,0,0,1,1},
		 		           {0,0,0,0,1,1}};
		 		           
	int digitalTwo[5][6]={ {1,1,1,1,1,1}, // digital two
		 		   		   {0,0,0,0,1,1},
				           {1,1,1,1,1,1},
		 		           {1,1,0,0,0,0},
		 		           {1,1,1,1,1,1}};
		 		           
	int digitalThree[5][6]={{1,1,1,1,1,1}, // digital three
		 		   		   	{0,0,0,0,1,1},
				           	{1,1,1,1,1,1},
		 		           	{0,0,0,0,1,1},
		 		           	{1,1,1,1,1,1}};
		 		           
	int digitalFour[5][6]={{1,1,0,0,1,1}, // digital four
		 		   		   {1,1,0,0,1,1},
				           {1,1,1,1,1,1},
		 		           {0,0,0,0,1,1},
		 		           {0,0,0,0,1,1}};
	
	int digitalFive[5][6]={{1,1,1,1,1,1}, // digital five
		 		   		   {1,1,0,0,0,0},
				           {1,1,1,1,1,1},
		 		           {0,0,0,0,1,1},
		 		           {1,1,1,1,1,1}};
		 		           
	int digitalSix[5][6]={{1,1,1,1,1,1}, // digital six
		 		   		  {1,1,0,0,0,0},
				          {1,1,1,1,1,1},
		 		          {1,1,0,0,1,1},
		 		          {1,1,1,1,1,1}};
		 		           
	int digitalSeven[5][6]={{1,1,1,1,1,1},	// digital seven
		 		   		   	{0,0,0,0,1,1},
				           	{0,0,0,0,1,1},
		 		           	{0,0,0,0,1,1},
		 		           	{0,0,0,0,1,1}};
		 		           
	int digitalEight[5][6]={{1,1,1,1,1,1}, // digital eight
		 		   		   	{1,1,0,0,1,1},
				           	{1,1,1,1,1,1},
		 		           	{1,1,0,0,1,1},
		 		           	{1,1,1,1,1,1}};
		 		           
	int digitalNine[5][6]={{1,1,1,1,1,1},	// digital nine
		 		   		   {1,1,0,0,1,1},
				           {1,1,1,1,1,1},
		 		           {0,0,0,0,1,1},
		 		           {1,1,1,1,1,1}};
		 		           
	int digitalDot[5][6]={{0,0,0,0},	// digital Dot
		 		   		  {0,1,1,0},
				          {0,0,0,0},
		 		          {0,1,1,0},
		 		          {0,0,0,0}};
		 		          
		 	
					   
						   	 		   
	if(figure==ZERO){
		
		arrangeNumber(digitalZero,raw,num_of_col);
		
	}else if(figure==ONE){
		
		arrangeNumber(digitalOne,raw,num_of_col);
		
	}else if(figure==TWO){
		
		arrangeNumber(digitalTwo,raw,num_of_col);
	
	}else if(figure==THREE){
		
		arrangeNumber(digitalThree,raw,num_of_col);
		
	}else if(figure==FOUR){
		
		arrangeNumber(digitalFour,raw,num_of_col);
	
	}else if(figure==FIVE){
		
		arrangeNumber(digitalFive,raw,num_of_col);
		
	}else if(figure==SIX){
		
		arrangeNumber(digitalSix,raw,num_of_col);
			
	}else if(figure==SEVEN){
		
		arrangeNumber(digitalSeven,raw,num_of_col);
		
	}else if(figure==EIGHT){
		
		arrangeNumber(digitalEight,raw,num_of_col);
			
	}else if(figure==NINE){
		
		arrangeNumber(digitalNine,raw,num_of_col);
			
	}else if(figure==DOT){
		
		arrangeNumber(digitalDot,raw,num_of_col);
	}
	
}

void arrangeNumber(int digital_mat[5][6],int raw,int num_of_col){
	int i;
	for(i=0;i<num_of_col;i++){
		 		
		if(digital_mat[raw][i]==1){
			
		 	textcolor(RESET, WHITE,clockColor); // set the terminal color to clockColor
		 	printf(" ");
		 	
		}else{
			
			textcolor(RESET, WHITE,DEFAULT); // set the terminal color to default color
			printf(" ");
		}
	}
	textcolor(RESET, WHITE,DEFAULT); // set the terminal color to default color
}

int checkErrors(int argc,char **argv){
	// define local variable
	int i,error=0;
	int char_count=argc;
	char *second_arg;
	char *first_arg;
	char first_char_of_arg2;
	
	if(char_count>=2){ // cheack weather argument count is greater than or equal zero
		
		first_arg=argv[0];
		second_arg=argv[1];
		first_char_of_arg2=second_arg[0];
		int length_of_arg2=strlen(argv[1]);
		
		if(first_char_of_arg2=='-' && length_of_arg2!=1){
			
			int second_char_of_arg2=second_arg[1];
			
			if(strcmp(argv[1],"-C")){
				
				if(length_of_arg2==2){ // cheack weather argument count is two
					
					printf("%s: invalid option -- '%c'\n",first_arg,second_char_of_arg2);
					printf("usage : clock -C <black|red|green|yellow|blue|magenta|cyan|white]\n");
					error=1;
					
				}else{
					
					char thirdToEndChars[50];
					char firstTwoChars[2];
					
					subStrn(thirdToEndChars,second_arg,3,length_of_arg2);
					subStrn(firstTwoChars,second_arg,1,2);
					
					int length_ofSubstr=strlen(thirdToEndChars);
					
					if(!strcmp(firstTwoChars,"-C")){
						
						if(!isAvailableColor(thirdToEndChars)){
					
							printf(" '%s' :This is not a valid color, Please enter one of these colours: black, red, yellow, blue, magenta, cyan, white\n",thirdToEndChars);
							error=1;
						}
						
					}else{
						
						for(i=0;i<length_ofSubstr;i++){
							
							if(!isValidOption(thirdToEndChars[i])){
								
								printf("%s: invalid option -- '%c'\n",first_arg,thirdToEndChars[i]);
									
							}
							
						}
						printf("usage : clock -C <black|red|green|yellow|blue|magenta|cyan|white]\n");
						error=1;
					}
					
					
				}
				
			}else if(char_count==2){
				
				printf("%s: option requires an argument -- 'C'\n",first_arg);
				printf("usage : clock -C <black|red|green|yellow|blue|magenta|cyan|white]\n");
				error=1;
				
			}else if(!isAvailableColor(argv[2])){
				
				printf(" '%s' :This is not a valid color, Please enter one of these colours: black, red, yellow, blue, magenta, cyan, white\n",argv[2]);
				error=1;
			
			}
		}
		
	}
	
	return error;
}

void subStrn(char str2[],char str1[],int start,int end){
	
	int i;
	
	int len=end-start+2;
	str2[len-1]='\0';
	
	for(i=start;i<=end;i++){
		str2[i-start]=str1[i-1];
		
	}
}

int isValidOption(char op){
	int validity=1;
	
	if(op!='C'){
		validity=0;
	}
	
	return validity;
}

int isAvailableColor(char color[]){
	int availability=1;
	
	if(strcmp(color,"black") && strcmp(color,"red") && strcmp(color,"green") && strcmp(color,"yellow")
			&& strcmp(color,"blue") && strcmp(color,"magenta") && strcmp(color,"cyan") && strcmp(color,"white")){
				
		availability=0;
	}
	return availability;
}


int getColor(int argc,char **argv){
	
	char *color;
	int colorVal;
	if(argc>=2){
		
		if(!strcmp(argv[1],"-C")){
			
			color=argv[2];
		
		}else{
			char thirdToEndChars[50];
			char firstTwoChars[2];
			int length_of_arg2=strlen(argv[1]);
			
			subStrn(thirdToEndChars,argv[1],3,length_of_arg2);
			subStrn(firstTwoChars,argv[1],1,2);
					
			
			if(!strcmp(firstTwoChars,"-C")){
				
				color=thirdToEndChars;
				
			}else{
				color="white";
			}
			
		
		}
		
	}else{
		color="white";
	}
	
	if(!strcmp(color,"black")){	//compare with black
		colorVal=BLACK;
				
	}else if(!strcmp(color,"red")){	//compare with red
		colorVal=RED;
				
	}else if(!strcmp(color,"green")){		//compare with green
		colorVal=GREEN;
				
	}else if(!strcmp(color,"yellow")){	//compare with yellow
		colorVal=YELLOW;
				
	}else if(!strcmp(color,"blue")){	//compare with blue
		colorVal=BLUE;
				
	}else if(!strcmp(color,"magenta")){	//compare with magenta
		colorVal=MAGENTA;
				
	}else if(!strcmp(color,"cyan")){	//compare with cyan
		colorVal=CYAN;
				
	}else{ // compare with white
		colorVal=WHITE;
	}
			
	return colorVal;
}

