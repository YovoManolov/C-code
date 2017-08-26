#include<stdio.h>
//masiv 
int main(){
}
int n ;
print("N=");
scanf("%d",&n);

int a[n];
int i=0;
int sumpol=0;
int sumotr=0;
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
	if((a[i]%2)==0)sumpol=sumpol+a[i];
	else((a[i]%2)!=0)sumotr=sumotr+a[i];
	else((a[i]%2)!=0)sumotr=sumotr+a[i];
}
printf("polojitelni %d\n",sumpol);
printf("otricatelni %d\n"sumotr);

return 0;
}
