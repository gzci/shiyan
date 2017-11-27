// 我真诚地保证：
    
// 我自己独立地完成了整个程序从分析、设计到编码的所有工作。
// 如果在上述过程中，我遇到了什么困难而求教于人，那么，我将在程序实习报告中
// 详细地列举我所遇到的问题，以及别人给我的提示。

// 在此，我感谢我的同学对我的启发和帮助。下面的报告中，我还会具体地提到
// 他们在各个方法对我的帮助。
 
// 我的程序里中凡是引用到其他程序或文档之处，
// 例如教材、课堂笔记、网上的源代码以及其他参考书上的代码段,
// 我都已经在程序的注释里很清楚地注明了引用的出处。

// 我从未没抄袭过别人的程序，也没有盗用别人的程序，
// 不管是修改式的抄袭还是原封不动的抄袭。

    // 我编写这个程序，从来没有想过要去破坏或妨碍其他计算机系统的正常运转。
    
    // <郭泽晨>
#include<iostream>
#include<stack>
using namespace std;
//详细内容分析在实验报告中 
 //使用系统自带STL库函数 
 //这个版本能判断 结果是0的式子 
class calculator{
	private:
		stack<char> optr;
		stack<double> opnd;
		double value;
		public:
			calculator(){
				opnd.push(0); 
				optr.push('#');
			}
			void run();
			void evaluate();
			void clear();
			private:
				int lp(char op);
				int rp(char op);
				double operate(char theta,double a,double b);
				
				
			
};
//操作具体的方法 
double calculator::operate(char theta,double a,double b){
 	double ret;
 	switch(theta){
 		case '+':ret=a+b;break;
		case '-':ret=a-b;break;
		case '*':ret=a*b;break;
		case '/':ret=a/b;break;
			
 		
	 }
	 return ret;
	 
 }
 int calculator::lp(char ch){
 	int ret;
 	switch(ch){
 		case '+':ret=3;break;
		case '-':ret=3;break;
		case '*':ret=5;break;
		case '/':ret=5;break;
		case '(':ret=1;break;
		case ')':ret=6;break;
		case '#':ret=0;break; 
				
 		default:ret=-1;
	 }
 	return ret;
 } 
 int calculator::rp(char ch){
 	int ret;
 	switch(ch){
 		case '+':ret=2;break;
		case '-':ret=2;break;
		case '*':ret=4;break;
		case '/':ret=4;break;
		case '(':ret=6;break;
		case ')':ret=1;break;
		case '#':ret=0;break;
 		default:ret=-1;
	 }
 	return ret;
 }
void calculator::evaluate(){
	char ch,op,theta;
	double val,a,b;
	int tag=0;
	cin>>ch;
	op='#';
	
	//当判断ch结束时 堆栈也是空的时候 结束循环 
	//this if以为着 式子首位只能是( 或者是数字的判断  错误判断语句 
	if(isdigit(ch)||rp(ch)==6){ 
			while((ch!='#')||(op!='#')){
			if(((rp(ch)!=-1) ||isdigit(ch))){
			
			if(isdigit(ch)){
			cin.putback(ch);
			cin>>val;
			opnd.push(val);
			cin>>ch;
		//计算优先级 根据优先级进行判断 
		}else if(lp(op)<rp(ch)){
				optr.push(ch);
		      	cin>>ch;
		      	if(!isdigit(ch))break;//判断运算符后面是不是数子 
			
		}else if(lp(op)==rp(ch)){
			optr.pop();
		
			cin>>ch;
			
			
		}else{
			theta=optr.top();
			optr.pop(); 
			b=opnd.top();
			opnd.pop();
			a=opnd.top();
			opnd.pop();
			//运算具体结果 
			opnd.push(operate(theta,a,b));
			
		}
	
		op=optr.top(); 
		}else{
			cin>>ch;
		}
		if(ch=='#'&&(lp(op)>=3)&&(lp(op)<=5)){
			
			theta=optr.top();
			optr.pop(); 
			b=opnd.top();
			opnd.pop();
			a=opnd.top();
			opnd.pop();
			//运算具体结果 
			opnd.push(operate(theta,a,b));
			op=optr.top(); 
			tag=1;
		}
		if(tag==1)break;
		
	}
	}

	//判断结果是否正确 
	
	int final1=opnd.top();
	opnd.pop();
	int final2=opnd.top();
cout<<final1<<"               "<<final2<<endl;
	if(final1==0){
		if(final2==0) cout<<"="<<0<<endl;
		else  cout<<"错误";
	}else if(optr.top()!='#'){
		cout<<"错误";
		//this if 用于判断两个括号之间没有运算符 这种错误。也属于错误判断语句。 
	}else if(final2!=0){ 
		
		cout<<"错误";
	}else cout<<"="<<final1;
	


 
	
}
int main(){
	calculator c;
	
	c.evaluate();

	

	 
}
