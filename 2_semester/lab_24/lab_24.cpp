#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char tdata;
int i; char ch;
struct node;
typedef node * link;
struct node{ 
    tdata data;
    link left, right;
} *tree;

void printtree(link t){ 
    static int l=0;
    l++;
    if(t){ 
        printtree(t->right);
        for(i=0; i<l; i++) printf("    ");
        printf("\\__%c\n",t->data);
        printtree(t->left);
    }
    l--;
}

int isAN(){ 
    return (ch >= 'a')&&(ch <= 'z')||(ch >= '0')&&(ch <= '9');
}
int isN(char c){ 
    return (c >= '0')&&(c <= '9');
}

link mknode(char c, link l, link r){ 
    link t = new node;
    t->data=c; 
    t->left=l; 
    t->right=r;
    return t;
}
link fact();
link term();
link power();
link expr();
link power(){ 
    link pw; 
    int done; 
    char ch1;
    pw=term(); 
    done=0;
    while((ch!='\n')&&(!done)){
        ch = getchar(); 
        // scanf("%c",&ch);
        if((ch=='^')){
            ch1=ch; 
            pw=mknode(ch1,pw,term());
        }
        else if((ch=='*')||(ch=='/')){
            ch1=ch; 
            pw=mknode(ch1,pw, power());
            done=1;
        }
        else done=1;
    }
    return pw;
}

link term(){ 
    link tm; 
    int done; 
    char ch1;
    tm=fact(); 
    done=0;
    while((ch!='\n')&&(!done)){
        if((ch=='*')||(ch=='/')){
            ch1=ch; 
            tm=mknode(ch1,tm, fact());
        }
        else done=1;
    }
    return tm;
}

link fact(){ 
    link t;
    ch = getchar(); 
    // scanf("%c",&ch);
    if(ch=='('){ 
        t=expr();
		if(ch!=')') printf("ERROR: not )\n");
	}
    else if(isAN()) t=mknode(ch,0,0);
	else printf("ERROR: not AN\n");
    return t;
}

link expr(){ 
    link ex; 
    int done; 
    char ch1;
    ex=power();
    done=0;
    while((ch!='\n')&&(!done)){ 
        if((ch=='*')||(ch=='/')){
            ch1=ch; 
            ex=mknode(ch1,ex,power());
        }
        else if((ch=='+')||(ch=='-')){
            ch1=ch; 
            ex=mknode(ch1,ex,power()); 
        }
        else done=1;
    }
    return ex;
}

void tree2expr(link tree){ 
    if(tree){ 
        if((tree->data=='+')||(tree->data=='-')) printf("(");
        tree2expr(tree->left);
        printf("%c",tree->data);
        tree2expr(tree->right);
        if((tree->data=='+')||(tree->data=='-')) printf(")");
    }
}

void  transtree(link tree){ 
    char c, cl, cr;
    if(tree){
        if(tree->data=='^'){ 
            cl=tree->left->data; 
            cr=tree->right->data;
            if(isN(cl)&&isN(cr)){ 
                c = pow(cl-'0',cr-'0');
                if(c<10 && c>0){
                    tree->data=c+'0'; 
                    tree->left=0; 
                    tree->right=0; 
                    i=1;
                }
            }
        }
        if(tree->data=='+'){ 
            cl=tree->left->data; 
            cr=tree->right->data;
            if(isN(cl)&&isN(cr)){ 
                c = (cl-'0') + (cr-'0');
                if(c<10){
                    tree->data=c+'0'; 
                    tree->left=0; 
                    tree->right=0; 
                    i=1;
                }
            }
        }
        if(tree->data=='-'){ 
            cl=tree->left->data; 
            cr=tree->right->data;
            if(isN(cl)&&isN(cr)){ 
                c = (cl-'0') - (cr-'0');
                if(c<10){
                    tree->data=c+'0'; 
                    tree->left=0; 
                    tree->right=0; 
                    i=1;
                }
            }
        }
        if(tree->data=='/'){ 
            cl=tree->left->data; 
            cr=tree->right->data;
            if(isN(cl)&&isN(cr)){ 
                c = (cl-'0') / (cr-'0');
                if(c<10){
                    tree->data=c+'0'; 
                    tree->left=0; 
                    tree->right=0; 
                    i=1;
                }
            }
        }
        if(tree->data=='*'){ 
            cl=tree->left->data; 
            cr=tree->right->data;
            if(isN(cl)&&isN(cr)){ 
                c = (cl-'0') * (cr-'0');
                if(c<10){
                    tree->data=c+'0'; 
                    tree->left=0; 
                    tree->right=0; 
                    i=1;
                }
            }
        }
        transtree(tree->left);
        transtree(tree->right);
    }
}

int main(){
    int k=1;
    printf("------------------------------------\n");
    printf("Input expression:\n\n");
    
    tree=expr();
    printf("------------------------------------\n");
    while(k){ 
        printf("\n    MENU\n"
               " 0 - exit\n"
               " 1 - print tree\n"
               " 2 - tree to expression\n"
               " 3 - transform tree\n");
        printf("===> ");
        scanf("%d",&k);
        printf("------------------------------------\n");
        if(!k) break;
        if(k==1){
            if(tree){
                printtree(tree);
            }
            else 
            printf("Tree is empty\n");
            printf("------------------------------------\n");
        }
        if(k==2){
            tree2expr(tree);
            printf("\n------------------------------------\n");
        }
        if(k==3){
            i=1; 
            while(i){
                i=0; 
                transtree(tree);
            }
        }
    }
    return 0;
}