#include <stdio.h>
#include "Std_types.h"
#include "Game.h"

u8 step1 , step2 , flag1 , flag2 , res1 , res2 , res3 ;
u8 main()
{
	printf("\nPlayer 1 : Symbole X\n");
    printf("Player 2 : Symbole O\n\n\n");
    display();
	while(1)
	{
	    printf("\n\n\nPlayer 1 : Enter your step : ");
	    scanf("%d",&step1);
		flag1 = player1_Step(step1);
	    while(flag1 == 0)
		{
			printf("\nPlayer 1 : Enter your step : ");
	        scanf("%d",&step1);
			flag1 = player1_Step(step1);
		}
		display();
		res1 = check_rows(); /*Check if elements of any row are the same. */
		if(res1 == 1) /*One of the rows has the same elements," There is a Winner ".*/
		{
			break;
		}
		else /*NO Rows has the same elements.*/
		{
			res2 = check_coloums();
			if(res2 == 1) /*Check if elements of any coloum are the same. */
			{
				break;
			}
			else /*NO coloums has the same elements.*/
			{
				res3 = check_all_elements();
				if(res3 == 1) /*Check if all rows and coloums are fill of charcter "X" or "O".*/
				{
					break;
				}
			}
		} /*Repeat the last steps with player2 if it was no winner.*/
	    printf("\n\nPlayer 2 : Enter your step : ");
	    scanf("%d",&step2);
		flag2 = player2_Step(step2);
	    while(flag2 == 0)
		{
			printf("\nPlayer 2 : Enter your step : ");
	        scanf("%d",&step2);
			flag2 = player2_Step(step2);
		}		
        display();	
		res1 = check_rows();
		if(res1 == 1)
		{
			break;
		}
		else
		{
			res2 = check_coloums();
			if(res2 == 1)
			{
				break;
			}
			else 
			{
				res3 = check_all_elements();
				if(res3 == 1)
				{
					break;
				}
			}
		}
         		
	}
}