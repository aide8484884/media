#include "double_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

list *creat_list()
{
	list *l=(list*)malloc(sizeof(list));
	if(l == NULL ) return 0;
	l->head.element=0;
	l->head.last=NULL;
	l->head.next=NULL;
	return l;

}
static void free_next(node*n)
{
	
	if(n->next == NULL) return ;
	free_next(n->next);
	free(n);
}	
void destroy_list(list*l)
{
	if(l==NULL) return ;
	free_next(l->head.next);
	free(l);
	l=NULL;
}	

int push_front(list*l,ElementType *e)
{
	if(l  ==  NULL || e == 0) return 0;
	node *new =(node *)malloc(sizeof(node));
	node *head = &l->head;
	if(new==NULL) return 0;
	if(head->next==NULL)
	{
		head->next=new;
		
		new->last=head;
		new->element=*e;
		head->element++;
		return 1;
	}
	new->next=head->next;
	head->next=new;
	(new->next)->last=new;
	new->last=head;
	new->element=*e;
	l->head.element++;
	return 1;
}
static node *tail(node*n)
{
	if(n->next==NULL) return n;
	tail(n->next);
}
int push_back(list*l,ElementType *e)
{
	if(l == NULL || e == 0) return 0;
	node *tail_me=tail(&l->head);
	node *new =(node *)malloc(sizeof(node));
	if(new==NULL) return 0;
	tail_me->next=new;
	new->last=tail_me;
	new->element = *e;
	l->head.element++;

	return 1;
}
static node *previous(node * n,int index)
{
	if(n==NULL) return NULL;
	if(index==0) return n;
	previous(n->next,index-1);
}
int insert_element(list*l,ElementType *e,int index)
{
	if(l == NULL || e == 0) return 0;
	node *new = (node *)malloc(sizeof(node));
	if(new == NULL) 
	{
		return 0;
	}

		node *la= previous(&l->head,index-1);
		node *n = previous(&l->head,index);
		
		
		la->next=new;
		n->last=new;
		new->next=n;
		new->last=la;
		new->element=*e;
		l->head.element++;
		return 1;
}
int remove_front(list*l)
{
	if(l == NULL )return 0;
	
	node *second = (l->head.next)->next;
	second->last=&l->head;
	free(l->head.next);
	l->head.next = second;
    l->head.element--;	

	return 1;
}
int remove_back(list*l)
{
	if(l ==NULL)return 0;
	node *n = previous(&l->head,l->head.element-1);
	free(n->next);
	n->next=NULL;
	l->head.element--;
	return 1;
}
int remove_index(list*l,int index)
{
	if(l == NULL) return 0;
	node *n = previous(&l->head,index-1);
	node *li = previous(&l->head,index+1);
	free(n->next);
	n->next=NULL;
	n->next=li;
	li->last=n;
	l->head.element--;
	return 1;
	
}
size_t size(list*l)
{
	return l->head.element;
}
ElementType *get(list* l,int index)
{
	
	node *n = previous(&l->head,index);
	return &n->element;
}
static void out(node *n)
{
	if(n->next==NULL) return ;
	printf("%d,  ",(n->next)->element);
	out(n->next);
}

void query(list*l)
{
	out(&l->head);
	printf("\n---------------------------\n");
}





