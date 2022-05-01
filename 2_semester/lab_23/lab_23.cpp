// определить число вершин двоичного дерева, имеющих ровно два поддерева 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int tdata;

int i, s, n_vert;

tdata m;

struct node;

typedef node * link;
link q;

struct node{ 
    tdata data;
    link left;
    link right;
} *tree;


void printtree(link t){ 
    static int l=0;
    l++;
    if(t){ 
        printtree(t->right);
        for(i=0;i<l;i++)printf("    ");
        printf("\\__%d\n",t->data);
        printtree(t->left);
    }
    l--;
}

void del(link &t){ 
    if(t->right) del(t->right);
    else { q->data=t->data; q=t; t=t->left;}
}

void deletetree(link &tree, tdata v){ 
    if(tree){
        if(v<tree->data) deletetree(tree->left,v);
        else if(v>tree->data) deletetree(tree->right,v);
	    else if(!(tree->right)) tree=tree->left;    
        else if(!(tree->left)) tree=tree->right;
        else{ 
            q=tree;
		    del(q->left);
		}
    }
}

void inserttree(link &t,tdata v){ 
    if(!t){
        t=new node; 
        t->data=v; 
	    t->left=0; t->right=0;
	   }
    else {  
	    if(v<t->data) inserttree(t->left,v);
	    else if(v>t->data) inserttree(t->right,v);
	}
}

void addtree(link &t, int n){ 
    for(i=0;i<n;i++){ 
        int v=rand()%50+1;
		inserttree(tree,v);
	}
}

void count(link t){
    if(t){
        count(t->right);
        s++;
        count(t->left);
    }
}

void action(link t){
    if(t){
        if(t->right && t->left){
            if((t->right->right || t->right->left) && (
                t->left->right || t->left->left)){
                n_vert++;
            }
        }
        action(t->right);
        action(t->left);
    }
}

int main(){
    time_t t; srand(time(&t)); int k=1, n;
    tree=0; tdata v;
    while(k){ 
        printf("\n    MENU\n"
               " 0 - exit\n"
               " 1 - add random tree\n"
               " 2 - print tree\n"
               " 3 - insert item\n"
               " 4 - delete item\n"
               " 5 - number of nodes\n"
               " 6 - clear tree\n"
               " 7 - action\n");
        scanf("%d",&k);
        if(!k) break;
        if(k==1){ 
            printf("\nInput number of items: ==> "); 
            scanf("%d",&n);
            addtree(tree,n);
        }
        if(k==2){
            if(tree) printtree(tree);
            else printf("\nTree is empty.\n");
        }
        if(k==3){
            printf("For insert Input v = "); 
            scanf("%d",&v);
            inserttree(tree,v);
        }
        if(k==4){
            printf("For delete Input v = "); 
            scanf("%d",&v);
            deletetree(tree,v);
        }
        if(k==5){
            s=0; 
            count(tree); 
            printf("\nNumber of nodes = %d\n",s);}
        if(k==6) tree=0;
        if(k==7){
            n_vert = 0;
            action(tree);
            printf("Number of nodes with two subtrees: %d\n", n_vert);
        }
    }
    return 0;
}