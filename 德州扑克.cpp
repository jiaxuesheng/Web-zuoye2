#include<stdio.h>
#include<iostream>
//将牌面字符转化为整型数字 
int Change(char c)
{
	if (c == '2') 
	{
		return 2;
	}
	if (c == '3')
	{
		return 3;
	}
	if (c == '4')
	{
		return 4;
	}
	if (c == '5')
	{
		return 5;
	}
	if (c == '6')
	{
		return 6;
	}
	if (c == '7')
	{
		return 7;
	}
	if (c == '8')
	{
		return 8;
	}
	if (c == '9')
	{
		return 9;
	}
	if (c == 'T')
	{
		return 10;
	}
	if (c == 'J')
	{
		return 11;
	}
	if (c == 'Q')
	{
		return 12;
	}
	if (c == 'K')
	{
		return 13;
	}
	if (c == 'A')
	{
		return 14;
	}
}

int main()
{
	int i,j,WhiteNum[6],BlackNum[6];
	char WhiteColor[6],BlackColor[6];
	printf("******************\n");
	printf("德州扑克牌大小比较\n");
	printf("******************\n"); 
	printf("扑克牌输入规则：\n花色：方片-D 黑桃-S 红桃-H 梅花-C\n数字从小到大依次为：2 3 4 5 6 7 8 9 T J Q K A\n");
	printf("每次必须输入五张牌，牌之间以空格隔开，回车结束输入\n例如：White：2H 3D 5S 9C KD\n");
	printf("请输入白方牌型\nWhite:");
	WhiteNum[0] = 0;
	BlackNum[0] = 0;
	//读入白方牌型
	while (WhiteNum[0]<5)
	{ 
		char c = getchar();
		if (c == ' ')
		{
			c = getchar();
		}
		WhiteNum[WhiteNum[0] + 1] = Change(c);
		c = getchar();
		WhiteColor[WhiteNum[0] + 1] = c;
		WhiteNum[0] = WhiteNum[0] + 1;
	}
	char enter = getchar();//吸收回车字符
	printf("请输入黑方牌型\nBlack:");
	//读入黑方牌型
	while (BlackNum[0]<5)
	{
		char c = getchar();
		if (c == ' ')
		{
			c = getchar();
		}
		BlackNum[BlackNum[0] + 1] = Change(c);
		c = getchar();
		BlackColor[BlackNum[0] + 1] = c;
		BlackNum[0] = BlackNum[0] + 1;
	}
	//保存两幅牌牌型的变量 0-散牌 1-对子 2-两对 3-三条 4-顺子 5-同花 6-同花顺
	int W = 0;
	int B = 0;
	//复制两组牌的大小用以操作判定牌型
	int White0[6];
	int Black0[6];
	i =1;
	j =1;
	for (i = 0; i < 6; i++)
	{
		White0[i] = WhiteNum[i];
		Black0[i] = BlackNum[i];
	}
	//排序
	i = 0;
	j = 0;
	for (i = 1; i < 5; i++)
	{
		int t;
		for (j = 1; j < 6 - i; j++)
		{
			if (White0[j]<White0[j + 1])
			{
				t = White0[j];
				White0[j] = White0[j + 1];
				White0[j + 1] = t;
			}
		}
	}
	for (i = 1; i < 5; i++)
	{
		int t;
		for (j = 1; j < 6 - i; j++)
		{
			if (Black0[j]<Black0[j + 1])
			{
				t = Black0[j];
				Black0[j] = Black0[j + 1];
				Black0[j + 1] = t;
			}
		}
	}
	//判定1对子牌型
	for (i = 1; i < 5; i++)
	{
		if (White0[i] == White0[i + 1])
		{
			W = 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (Black0[i] == Black0[i + 1])
		{
			B = 1;
		}
	}
	
	//判定2两对牌型
	int W2 = 0;
	int B2 = 0;
	for (i = 1; i < 5; i++)
	{
		if (White0[i] == White0[i + 1])
		{
			W2 = W2 + 1;
			i = i + 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (Black0[i] == Black0[i + 1])
		{
			B2 = B2 + 1;
			i = i + 1;
		}
	}
	if (W2 == 2)
	{
		W = 2;
	}
	if (B2 == 2)
	{
		B = 2;
	}
	//判定3三条牌型
	for (i = 1; i < 4; i++)
	{
		if (White0[i] == White0[i + 1]&& White0[i+1]==White0[i+2])
		{
			W = 3;
		}
	}
	for (i = 1; i < 4; i++)
	{
		if (Black0[i] == Black0[i + 1]&& Black0[i+1]== Black0[i+2])
		{
			B = 3;
		}
	}
	//判定4顺子牌型
	int W4=0;
	int B4=0;
	for (i = 1; i < 5; i++)
	{
		if (White0[i] - White0[i + 1]==1 )
		{
			W4= W4 + 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (Black0[i] - Black0[i + 1] ==1)
		{
			B4 = B4 + 1;
		}
	}
	if (W4 == 4)
	{
		W = 4;
	}
	if (B4 == 4)
	{
		B = 4;
	}
	//判定5同花牌型
	int W5 = 0;
	int B5 = 0;
	for (i = 1; i < 5; i++)
	{
		if (WhiteColor[i] == WhiteColor[i + 1] )
		{
			W5 = W5 + 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (BlackColor[i] == BlackColor[i + 1])
		{
			B5 = B5 + 1;
		}
	}
	if (W5 == 4)
	{
		W = 5;
	}
	if (B5 == 4)
	{
		B = 5;
	}
	//判定6同花顺牌型
	if (W4 == 4 && W5 == 4)
	{
		W = 6;
	}
	if (B4 == 4 && B5 == 4)
	{
		B = 6;
	}
	//先按照牌型比较大小
	if (W >B)
	{
		printf("White Win");
	}
	else if (W<B)
	{
		printf("Black Win");
	}
	//牌型相同比较大小
	if (W == 0 && B == 0)
	{
		//比较牌的大小
		int c=0;
		for (i = 1; i < 6; i++)
		{
			if (White0[i] > Black0[i])
			{
				printf("White Win");
				c=1;
			}
			if (White0[i] < Black0[i])
			{
				printf("Black Win");
				c=2;
			}
		}
		if(c==0) printf("Tie");
	}
	if (W == 1 && B == 1)
	{
		int i = 0;
		int a0=0,b0=0;
		for (i = 1; i < 5; i++)
		{
			if (White0[i] == White0[i + 1])
			{
				a0 = White0[i];
				White0[i] = 0;
				White0[i + 1] = 0;
			}
		}
		for (i = 1; i < 5; i++)
		{
			if (Black0[i] == Black0[i + 1])
			{
				b0 = Black0[i];
				Black0[i] = 0;
				Black0[i + 1] = 0;
			}
		}
		if (a0>b0) printf("White Win");
		if (a0<b0) printf("Black Win");
		if(a0==b0)
		{
			int i = 0;
	        int j = 0;
	        int c = 0;
	        for (i = 1; i < 5; i++)
	        {
	     	int t;
	    	for (j = 1; j < 6 - i; j++)
	    	 {
		    	if (White0[j]<White0[j + 1])
			    {
			    	t = White0[j];
			    	White0[j] = White0[j + 1];
			    	White0[j + 1] = t;
			    }
	       	 }
        	}
           	for (i = 1; i < 5; i++)
         	{
	        	int t;
	        	for (j = 1; j < 6 - i; j++)
	        	{
		        	if (Black0[j]<Black0[j + 1])
		        	{
			        	t = Black0[j];
			        	Black0[j] = Black0[j + 1];
			        	Black0[j + 1] = t;
		        	}
	        	}
	        }
	        for (i = 1; i < 6; i++)
		    {
			   if (White0[i] > Black0[i])
			   {
			    	printf("White Win");
			    	c=1;
		    	}
			   if (White0[i] < Black0[i])
			   {
			    	printf("Black Win");
			    	c=2;
		    	}
		    }
		    if(c==0) printf("Tie");
		}
		
	}
	if (W == 2 && B == 2)
	{
		int a1,a11;
		int b1,b11;
		for (i = 1; i < 5; i++)
		{
			if (White0[i] == White0[i + 1])
			{
				a1 = White0[i];
				White0[i] = 0;
				White0[i + 1] = 0;
				i = i + 1;
			}
			if (White0[i] == White0[i + 1])
			{
				a11 = White0[i];
				White0[i] = 0;
				White0[i + 1] = 0;
				i = i + 1;
			}
		}
		for (i = 1; i < 5; i++)
		{
			if (Black0[i] == Black0[i + 1])
			{
				b1 = Black0[i];
				Black0[i] = 0;
				Black0[i + 1] = 0;
				i = i + 1;
			}
			if (Black0[i] == Black0[i + 1])
			{
				b11 = Black0[i];
				Black0[i] = 0;
				Black0[i + 1] = 0;
				i = i + 1;
			}
		}
		if(a1>b1) printf("White Win");
		if(a1<b1) printf("Black Win");
		if(a1==b1)
		{
			if(a11>b11) printf("White Win");
		    if(a11<b11) printf("Black Win");
		    if(a11==b11)
		    {
		    	int i = 0;
	            int j = 0;
	            int c = 0;
	        	for (i = 1; i < 5; i++)
	        	{
	     		int t;
	    		for (j = 1; j < 6 - i; j++)
	    		 {
		    		if (White0[j]<White0[j + 1])
			   	    {
			    		t = White0[j];
			    		White0[j] = White0[j + 1];
			    		White0[j + 1] = t;
			   		 }
	       		 }
        		}
           		for (i = 1; i < 5; i++)
         		{
	        		int t;
	        		for (j = 1; j < 6 - i; j++)
	        		{
		        		if (Black0[j]<Black0[j + 1])
		        		{
			       		 	t = Black0[j];
			       		 	Black0[j] = Black0[j + 1];
			      		  	Black0[j + 1] = t;
		        		}
	        		}
	       		 }
	        	for (i = 1; i < 6; i++)
		    	{
			   		if (White0[i] > Black0[i])
			  	 	{
			    		printf("White Win");
			    		c=1;
		    		}
			   		if (White0[i] < Black0[i])
			   		{
			    		printf("Black Win");
			    		c=2;
		    		}
		    	}
		    	if(c==0) printf("Tie");
			}
		}
		
	}
	if (W == 3 && B == 3)
	{
		int a3;
		int b3;
		for (i = 1; i < 4; i++)
		{
			if (White0[i] == White0[i + 1] && White0[i + 1] == White0[i + 2])
			{
				a3 =  White0[i];
				White0[i] = 0;
				White0[i + 1] = 0;
				White0[i + 2] = 0;
				i = i + 2;
			}
		}
		for (i = 1; i < 4; i++)
		{
			if (Black0[i] == Black0[i + 1] && Black0[i + 1] == Black0[i + 2])
			{
				b3 =  Black0[i];
				Black0[i] = 0;
				Black0[i + 1] = 0;
				Black0[i + 2] = 0;
				i = i + 2;
			}
		}
		if (a3>b3) printf("White Win");
		if (a3<b3) printf("Black Win");
		if (a3==b3)
		{
			int i = 0;
	        int j = 0;
	        int c = 0;
	        for (i = 1; i < 5; i++)
	        {
	     	int t;
	    	for (j = 1; j < 6 - i; j++)
	    	 {
		    	if (White0[j]<White0[j + 1])
			    {
			    	t = White0[j];
			    	White0[j] = White0[j + 1];
			    	White0[j + 1] = t;
			    }
	       	 }
        	}
           	for (i = 1; i < 5; i++)
         	{
	        	int t;
	        	for (j = 1; j < 6 - i; j++)
	        	{
		        	if (Black0[j]<Black0[j + 1])
		        	{
			        	t = Black0[j];
			        	Black0[j] = Black0[j + 1];
			        	Black0[j + 1] = t;
		        	}
	        	}
	        }
	        for (i = 1; i < 6; i++)
		    {
			   if (White0[i] > Black0[i])
			   {
			    	printf("White Win");
			    	c=1;
		    	}
			   if (White0[i] < Black0[i])
			   {
			    	printf("Black Win");
			    	c=2;
		    	}
		    }
		    if(c==0) printf("Tie");
		}
	}
	if (W == 4 && B == 4)
	{
		if(White0[1]> Black0[1]) printf("Whint Win");
		if(White0[1]< Black0[1]) printf("Black Win");
		if(White0[1]== Black0[1]) printf("Tie");
	}
	if (W == 5 && B == 5)
	{
		//比较牌的大小
		int c = 0;
		for (i = 1; i < 6; i++)
		{
			if (White0[i] > Black0[i])
			{
				printf("Whint Win");
				c = 1;
			}
			if (White0[i] < Black0[i])
			{
				printf("Black Win");
				c = 2;
			}
		}
	    if(c==0) printf("Tie");
	}
	if (W == 6 && B == 6)
	{
		if(White0[1]> Black0[1]) printf("Whint Win");
		if(White0[1]< Black0[1]) printf("Black Win");
		if(White0[1]== Black0[1]) printf("Tie");
	}
	system("pause");
	return 0;
}
