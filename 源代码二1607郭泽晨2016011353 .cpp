// ����ϵر�֤��
    
// ���Լ��������������������ӷ�������Ƶ���������й�����
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ������
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��

// �ڴˣ��Ҹ�л�ҵ�ͬѧ���ҵ������Ͱ���������ı����У��һ��������ᵽ
// �����ڸ����������ҵİ�����
 
// �ҵĳ������з������õ�����������ĵ�֮����
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����

// �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��

    // �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��
    
    // <����>
#include<iostream>
#include<stack>
using namespace std;
//��ϸ���ݷ�����ʵ�鱨���� 
 //ʹ��ϵͳ�Դ�STL�⺯�� 
 //����汾���ж� �����0��ʽ�� 
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
//��������ķ��� 
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
	
	//���ж�ch����ʱ ��ջҲ�ǿյ�ʱ�� ����ѭ�� 
	//this if��Ϊ�� ʽ����λֻ����( ���������ֵ��ж�  �����ж���� 
	if(isdigit(ch)||rp(ch)==6){ 
			while((ch!='#')||(op!='#')){
			if(((rp(ch)!=-1) ||isdigit(ch))){
			
			if(isdigit(ch)){
			cin.putback(ch);
			cin>>val;
			opnd.push(val);
			cin>>ch;
		//�������ȼ� �������ȼ������ж� 
		}else if(lp(op)<rp(ch)){
				optr.push(ch);
		      	cin>>ch;
		      	if(!isdigit(ch))break;//�ж�����������ǲ������� 
			
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
			//��������� 
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
			//��������� 
			opnd.push(operate(theta,a,b));
			op=optr.top(); 
			tag=1;
		}
		if(tag==1)break;
		
	}
	}

	//�жϽ���Ƿ���ȷ 
	
	int final1=opnd.top();
	opnd.pop();
	int final2=opnd.top();
cout<<final1<<"               "<<final2<<endl;
	if(final1==0){
		if(final2==0) cout<<"="<<0<<endl;
		else  cout<<"����";
	}else if(optr.top()!='#'){
		cout<<"����";
		//this if �����ж���������֮��û������� ���ִ���Ҳ���ڴ����ж���䡣 
	}else if(final2!=0){ 
		
		cout<<"����";
	}else cout<<"="<<final1;
	


 
	
}
int main(){
	calculator c;
	
	c.evaluate();

	

	 
}
