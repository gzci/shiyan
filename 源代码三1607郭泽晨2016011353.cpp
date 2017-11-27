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
//树的类 主要成员变量 是 数据域 和左右两个指针
//本程序可实现缩格打印 一个二叉树 
class tree{

	private:

		int data;

		tree* leftchild=NULL;

		tree* rightchild=NULL;

	public:
		void SGprint(); 
//无参数构造器 
		void UNRPorder(tree *s); 
		void print(tree *T,int n);
		tree(){

		}
//带参数构造器 
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
/* 以 
*右子树
*根
*左子树
*的形式打印
*/
void tree:: print(tree *T,int n)
{
 if(!T)return;
 print(T->rightchild, n+2);
 space(n);
 cout << T->data << endl;
 print(T->leftchild, n+2);
}
//构造一棵查找树 

tree* tree::insert(int x,tree* p){

	

	if(!p){

		p=new tree(x,NULL,NULL);

	}else{

		if(x<p->data) p->leftchild=insert(x,p->leftchild);

		else if(x>p->data) p->rightchild=insert(x,p->rightchild);

		

		

			

		return p;

		

	}

}


// 前序输出这个树的元素
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
//交换函数 用前序 来实现 
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
//主函数 s 是树的根节点 
int main(){

	int a;

	tree *s=NULL;
//当 输入的不是数字 循环会停止 
	while(cin>>a)

	s=s->insert(a,s);

	cin.clear();
	//非递归前序遍历 
	s->UNRPorder(s); 
	//递归前序遍历 
//	s->preorder(s);
//	s->print(s,0);
//	cout<<"********************"<<endl;
//	s->swap(s);

//	s->preorder(s);
//	s->print(s,0);
	

}
