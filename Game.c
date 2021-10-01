#include <stdio.h>
#include "Std_types.h"
u8 arr[3][3] = 
	{ {1 , 2 , 3},
      {4 , 5 , 6},
	  {7 , 8 , 9}
	};
void display(void)
{   /*Function to display the game after every step.*/
    /*  1 | 2 | 3
        ---------
        4 | 5 | 6
        ---------
        7 | 8 | 9	*/
	for(u8 i = 0 ; i < 3 ; i++)
    {
	    for(u8 j = 0 ; j < 3 ; j++)
	    {
		    if(j != 2)
		    {
			    if((arr[i][j] > 0) && (arr[i][j] < 10))
			    {
	                printf("  %d  |",arr[i][j]);
			    }
			    else
			    {
				    printf("  %c  |",arr[i][j]);
			    }
		    }
		    else if(j == 2)
		    {
			    if((arr[i][j] > 0) && (arr[i][j] < 10))
			    {
	                printf("  %d  ",arr[i][j]);
			    }
			    else
			    {
				    printf("  %c  ",arr[i][j]);
			    }
		    }
	    }
	    if(i != 2)
	    {
	        printf("\n ---------------\n");
	    }
    }
}
u8 player1_Step(u8 num) 
{
	switch(num) 
	{   /*Check if the number is used before or not then replace it by 'X'(if it is not used return : 1 else : return 0).*/
		case 1 : if((arr[0][0] > 0) && (arr[0][0] < 10)) {arr[0][0] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 2 : if((arr[0][1] > 0) && (arr[0][1] < 10)) {arr[0][1] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 3 : if((arr[0][2] > 0) && (arr[0][2] < 10)) {arr[0][2] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 4 : if((arr[1][0] > 0) && (arr[1][0] < 10)) {arr[1][0] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 5 : if((arr[1][1] > 0) && (arr[1][1] < 10)) {arr[1][1] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 6 : if((arr[1][2] > 0) && (arr[1][2] < 10)) {arr[1][2] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 7 : if((arr[2][0] > 0) && (arr[2][0] < 10)) {arr[2][0] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 8 : if((arr[2][1] > 0) && (arr[2][1] < 10)) {arr[2][1] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break; 
        case 9 : if((arr[2][2] > 0) && (arr[2][2] < 10)) {arr[2][2] = 'X'; return 1;} else{printf("Busy place\n"); return 0;}break; 
        default : printf("Invalid step\n");  		
	}
}
u8 player2_Step(u8 num)
{
	switch(num)
	{   /*Check if the number is used before or not then replace it by 'O'(if it is not used return : 1 else : return 0).*/ 
		case 1 : if((arr[0][0] > 0) && (arr[0][0] < 10)) {arr[0][0] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 2 : if((arr[0][1] > 0) && (arr[0][1] < 10)) {arr[0][1] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 3 : if((arr[0][2] > 0) && (arr[0][2] < 10)) {arr[0][2] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 4 : if((arr[1][0] > 0) && (arr[1][0] < 10)) {arr[1][0] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 5 : if((arr[1][1] > 0) && (arr[1][1] < 10)) {arr[1][1] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 6 : if((arr[1][2] > 0) && (arr[1][2] < 10)) {arr[1][2] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 7 : if((arr[2][0] > 0) && (arr[2][0] < 10)) {arr[2][0] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break;
        case 8 : if((arr[2][1] > 0) && (arr[2][1] < 10)) {arr[2][1] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break; 
        case 9 : if((arr[2][2] > 0) && (arr[2][2] < 10)) {arr[2][2] = 'O'; return 1;} else{printf("Busy place\n"); return 0;}break; 
        default : printf("Invalid step\n");  		
	}
}
u8 check_rows()
{   /*Check all rows.*/
	u8 i , j , res1 = 0;
	for(i = 0 ; i < 3 ;i++)
	{
		for(j = 0 ; j < 2 ; j++)
		{
			if(arr[i][j++] != arr[i][j])
			{
				break;
			}
		}
		if((arr[i][2] == 'O' ) && (j == 2))
		{
			printf("\nWe have a Winner , player 2\n");
			res1 = 1;
			break;
		}
		if((arr[i][2] == 'X' ) && (j == 2))
		{
			printf("\nWe have a Winner , player 1\n");
		    res1 = 1;
			break;
		}
	}
	if(res1 == 1)
	{
	    return res1;
	}
}
u8 check_coloums()
{	
    u8 i , j, res2 = 0; 
	/*Check all coloums.*/
    for(i = 0 ; i < 3 ; i++)
	{
		for(j = 0 ; j < 2 ; j++)
		{
			if(arr[j++][i] != arr[j][i])
			{
				break;
			}
		}
		if((arr[2][i] == 'O' ) && (j == 2))
		{
			printf("\nWe have a Winner , player 2\n");
			res2 = 1;
			break;
		}
		if((arr[2][i] == 'X' ) && (j == 2))
		{
			printf("\nWe have a Winner , player 1\n");
			res2 = 1;
			break;
		}
	}
	if(res2 == 1)
	{
	    return res2;
	}
}
u8 check_all_elements()
{
	u8 i , j , res3 = 0;
    /*Check all elements.*/
    for(i = 0 ; i < 3 ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			if((arr[i][j] != 'O') && (arr[i][j] != 'X'))
			{
				break;
			}
		}
		if(j == 3) /*This row does not contain any number.*/
		{
			continue;
		}
		else /*There is a number in this row.*/
		{
			break;
		}
	}	
    if(i == 3 && j == 3)
	{
		printf("\nGame over\n");
        res3  = 1;		
    }
	return res3;
}