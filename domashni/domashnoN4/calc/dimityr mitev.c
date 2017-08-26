#include<stdio.h>//Dimitar Mitev
int main()
{
	 FILE * f;
	 int i=0,s[60][2]={0,0},c=0,fl1=0,fl2=0,br=0;
	 char t;//s[i][0]--stoinost, s[i][1]--puti sreshtnato, moje da se napravi i s 2 otdelni masiva
	 //c--segashno chislo, br--broi otkriti razlichni chisla
	 //fl1--flag za rabota s chislo, f2--dali veche go ima v masiva 's'
	 f=fopen("c:\\Users\\Iordanka\\Desktop\\text.txt","r");
	 while(fscanf(f,"%c",&t)!=EOF)
		 {
		 printf("%c",t);
		 if(t>='0'&&t<='9')//ako e cifra
			{
				 if(fl1==1)//dali produljavame ot cifra
				 {
				 c=c*10+(t-48);//murdame na lqvo i dobavqme
				 //primer c=56 , noviq simvol e 3 => c*10+t=560+3  => 563
				 }
					 else//sreshtame chislo za purvi put
					 {
					 fl1=1;//otbelqzvame che zapochvame chislo
					 c=t-48;//ot char v int
					 } 
		 	}
		 else//ako ne e cifra
				 {
				 if(fl1==1)//dali produljava ot chislo
				 for(i=0;i<br;i++)//proverka dali se sadarja
					 {
					 if(s[i][0]==c){s[i][1]++,fl2=1;}//ako se sadarja da uvelichi broika, otbelqzvame che e sreshtnato
					 }
				 if(fl2==0&&fl1==1){s[br][0]=c;s[br][1]=1;br++;}//ako ne e sreshtnato go dobavqme
				 fl1=0;//nulirame flaga za rabota s chislo
				 }
		 fl2=0;//nulirame flaga za sreshtnato
		 
		 }
	 printf("\n---------------------\n now out   br=%d\n",br);
	 for(i=0;i<br;i++)//izvejdame vsichki chisla
	 {
	 printf("%d - %d\n",s[i][0],s[i][1]);
	 }
	 fclose(f);
	 return 0;
}

