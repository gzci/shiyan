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
//������ ��Ҫ��Ա���� �� ������ ����������ָ��
//�������ʵ�������ӡ һ�������� 
class tree{

	private:

		int data;

		tree* leftchild=NULL;

		tree* rightchild=NULL;

	public:
		void SGprint(); 
//�޲��������� 
		void UNRPorder(tree *s); 
		void print(tree *T,int n);
		tree(){

		}
//������������ 
		tree(int data,tree* leftchild,tree* rightchild){

			this->data=data;

			this->leftchild=leftchild;

			this->rightchild=rightchild;

			

		}

		tree* insert(int x,tree*s );

		void preorder(tree *s);

		tree* swap(tree *s);

}; 
void space(int n)
{
 for(int i=0; i<n; i++)
  cout << ' ';
}
/* �� 
*������
*��
*������
*����ʽ��ӡ
*/
void tree:: print(tree *T,int n)
{
 if(!T)return;
 print(T->rightchild, n+2);
 space(n);
 cout << T->data << endl;
 print(T->leftchild, n+2);
}
//����һ�ò����� 

tree* tree::insert(int x,tree* p){

	

	if(!p){

		p=new tree(x,NULL,NULL);

	}else{

		if(x<p->data) p->leftchild=insert(x,p->leftchild);

		else if(x>p->data) p->rightchild=insert(x,p->rightchild);

		

		

			

		return p;

		

	}

}


// ǰ������������Ԫ��
 void tree::UNRPorder(tree *T){
 	stack<tree*> Stack;

	 while(T || !Stack.empty())  
    {  
        while(T)  
        {  
            Stack.push(T);  
            cout<<T->data<<" "; 
            T=T->leftchild;  
        }  
        T=Stack.top(); 
		 
        Stack.pop(); 
		cout<<T->data<<" ";           
             T=T->rightchild;          
    }                                                                                                                                     
}  
	 
		  
 	 
 
void tree::preorder(tree *s){

	if(s) {

		cout<<s->data<<" ";

		preorder(s->leftchild);

		preorder(s->rightchild);	

	}

	

	

}
//�������� ��ǰ�� ��ʵ�� 
tree* tree::swap(tree *s){

	tree *temp=NULL;

		if(s->leftchild&&s->rightchild) {

//			cout<<"you "<<s->rightchild<<"zuo "<<s->leftchild<<endl;

			temp=s->rightchild;

			s->rightchild=s->leftchild;

			s->leftchild=temp;

//			cout<<"you "<<s->rightchild<<"zuo "<<s->leftchild<<endl; 

		swap(s->leftchild);

		swap(s->rightchild);	

	}

	

}
//������ s �����ĸ��ڵ� 
int main(){

	int a;

	tree *s=NULL;
//�� ����Ĳ������� ѭ����ֹͣ 
	while(cin>>a)

	s=s->insert(a,s);

	cin.clear();
	//�ǵݹ�ǰ����� 
	s->UNRPorder(s); 
	//�ݹ�ǰ����� 
//	s->preorder(s);
//	s->print(s,0);
//	cout<<"********************"<<endl;
//	s->swap(s);

//	s->preorder(s);
//	s->print(s,0);
	

}
