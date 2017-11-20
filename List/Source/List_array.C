#include "MyStruct.h"
 #include <windows.h>

typedef struct List_Arr{
  int end ;
  char str[MAXSIZE] ;
} list ;


void createList(list *ls){
  int i ;
  ls->end = -1 ;
  ls->str[0] = '\0' ;
  for(i = 0 ; i < MAXSIZE ; i++){
    ls->str[i] = 0 ;
  }
  printCharArray(ls->str) ;
  return ;
}


int isFull(list *ls){
    if( ls->end >= MAXSIZE-1){
        printf("\n ���� �Ұ�!\n�迭�� ����á���ϴ�.\n") ;
        return TRUE ;
    }
  return FALSE ;
}

int isEmpty(list *ls){
	if(ls->end < 0){
        printf("\n ���� �Ұ�!\n�迭�� ������ϴ�.\n") ;
		return TRUE ; 
	} else{
		return FALSE ; 
	}
}

//�߰� ����
int insert(list *ls, char data, int seq){
  ls->str[seq] = data ;
  printCharArray(ls->str) ;
}

//������ ����
int insertEnd(list *ls, char data){
  if(isFull(ls)) return FALSE ;
  ls->end++;
  return insert(ls, data, ls->end) ;
}

//todo : ���� �÷��� ����
void moveArrRight(list *ls, int empty){
  int i,j ;
  for(i = (MAXSIZE-1) ; i >= empty ; i--){
    ls->str[i+1] = ls->str[i] ;
  }
}

// �������� ����
void moveArrLeft(list *ls, int empty){
	int i, j ; 
	j = ls->end ; 
	for( i = empty ; i < ls->end ; i++ ){
		ls->str[i] = ls->str[i+1] ; 
	}
	ls->str[ls->end] = '\0' ; 
}


int insertMid(list *ls, char data,int seq){
  if(isFull(ls)) return FALSE ;
  ls->end ++ ;
  moveArrRight(ls, seq) ;
  return insert(ls, data, seq) ;
}
int deleteArr(list *ls, int seq){
    if( seq < 0 || ls->end < seq ) return FALSE ; 
    if(!( ls->str[seq]) ){
        return FALSE ;
    }
	if( isEmpty(ls) ){
		return FALSE ; 
	}
	ls->end--;
	moveArrLeft(ls, seq) ; 
	printCharArray(ls->str) ;
    return TRUE;
}
int deleteArrLast(list *ls){
	if( isEmpty(ls) ){
		return FALSE ; 
	}
	ls->end--;
	moveArrLeft(ls, ls->end) ; 
	printCharArray(ls->str) ;
    return TRUE;
}


int main(){
  list ls,*pls ;
  int count_number = 0 ;
  pls = &ls ;
  createList(pls) ;

  insertEnd(pls, 'a') ;
  printf(" ==> COUNT: %d Insert ", count_number++ ) ;
  insertEnd(pls, 'b') ;
  printf(" ==> COUNT: %d Insert ", count_number++ ) ;
  insertEnd(pls, 'c') ;
  printf(" ==> COUNT: %d Insert ", count_number++ ) ;
  insertEnd(pls, 'd') ;
  printf(" ==> COUNT: %d Insert ", count_number++ ) ;

  insertMid(pls, 'e', 1) ;
  printf(" ==> COUNT: %d Insert ", count_number++ ) ;
  insertMid(pls, 'f', 1) ;
  printf(" ==> COUNT: %d Insert ", count_number++ ) ;

  
  deleteArr(pls, 1) ; 
  printf(" ==> COUNT: %d delete ", count_number++ ) ;

  deleteArrLast(pls) ; 
  printf(" ==> COUNT: %d delete ", count_number++ ) ;

  system("pause") ;

  return 0 ;
}