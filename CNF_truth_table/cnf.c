#include <stdio.h>
#include <math.h>
#define MAX 1000
int n,m;
int clauses[MAX][MAX];
int cl_size[MAX];
int cl_ans[MAX][MAX];
int val[MAX];
int ans[MAX];

void inp(){
	// printf("Enter no. of input var : \n");
	scanf("%d",&n);
	// printf("Enter no. of clauses : \n");
	scanf("%d",&m);
	int i,j;
	for(i=0;i<m;i++){
		// printf("Enter no. of variables in clause - %d : \n",i);
		scanf("%d",&cl_size[i]);
		// printf("Enter the variables : \n");
		for(j=0;j<cl_size[i];j++)scanf("%d",&clauses[i][j]);
	}
}

void store(int cl_no,int flag){
	int loc=0,i;
	for(i=0;i<n;i++){
		int ith_bit=val[i+1];
		loc=loc|(ith_bit<<i);
	}
	cl_ans[cl_no][loc]=flag;
}

void compute(int cl_no){
	int flag=0,i;

	for(i=0;i<cl_size[cl_no];i++){
		int var=abs(clauses[cl_no][i]);
		int v=val[var];
		if(clauses[cl_no][i]<0)v=!v;
		if(v){
			flag=1;
			break;
		}
	}
	store(cl_no,flag);
}

void set_val(int cl_no,int var_no){
	if(var_no==0)compute(cl_no);
	else{
		val[var_no]=0;
		set_val(cl_no,var_no-1);
		val[var_no]=1;
		set_val(cl_no,var_no-1);
	}
}

void display(int cl_no){
	int c=1<<n,i;
	for(i=0;i<c;i++)printf("%d\n",cl_ans[cl_no][i]);
}


void combine(){
	int c=1<<n,i,j,flag=1;;
	for(i=0;i<c;i++){
		flag=1;
		for(j=0;j<m;j++){
			if(cl_ans[j][i]==0){
				flag=0;
				break;
			}
		}
		ans[i]=flag;
	}	
}

void binary(int d){
	int bin[MAX],i=-1;
	while(d){
		bin[++i]=d%2;
		d/=2;
	}
	for(i=n-1;i>=0;i--)printf("%d\t",bin[i]);
}
int main(){
	inp();
	int i;
	for(i=0;i<m;i++){
		set_val(i,n);
	}
	combine();
	printf("TRUTH TABLE\n");
	for(i=n;i>=1;i--)printf("p%d\t",i);
	printf("Ans\n");
	for(i=0;i<(1<<n);i++){
		binary(i);
		printf("%d\n",ans[i]);
	}
}