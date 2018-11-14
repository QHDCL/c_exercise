#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//��ʼ��˳���
void SeqListInit(PSeqList ps, int capacity){
	assert(ps);
	ps->_pData = (DataType *)malloc(sizeof(DataType)*capacity);
	if (ps->_pData == NULL){
		exit(0);
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}


//��ӡ˳���
void PrintSeqList(PSeqList ps){
	assert(ps);
	if (ps->_size == 0){
		printf("˳���Ϊ��\n");
	}
	for (int i = 0; i <ps->_size; i++){
		printf("%d ", ps->_pData[i]);
	}
	printf("\n");
}


//β������Ԫ��data
void SeqListPushBack(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);
	ps->_pData[ps->_size] = data;
	ps->_size++;
}


//β��ɾ�����һ��Ԫ��
void SeqListPopBack(PSeqList ps){
	assert(ps);
	if (ps->_size == 0){
		printf("˳���Ϊ��\n");
	}
	else{
		ps->_size--;
	}
}


// ��˳����ͷ������Ԫ��data
void SeqListPushFront(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size ; i >=0;i--){
		ps->_pData[i] = ps->_pData[i-1];
	}
	ps->_pData[0] = data;
	ps->_size++;
}


// ɾ��˳����ͷ��Ԫ��
void SeqListPopFront(PSeqList ps){
	assert(ps);
	if (ps->_size == 0){
		printf("˳���Ϊ��\n");
	}
	else{
		for (int i = 0; i < ps->_size; i++){
			ps->_pData[i] = ps->_pData[i + 1];
		}
		ps->_size--;
	}
}


// ��˳����posλ�ò���Ԫ��data
void SeqListInsert(PSeqList ps, int pos, DataType data){
	assert(ps);
	if (pos<0 || pos>ps->_size){
		printf("λ����Ϣ����\n");
	}

	CheckCapacity(ps);

	for (int i = ps->_size-1; i >=pos; i--){
		ps->_pData[i + 1] = ps->_pData[i];
	}
	ps->_pData[pos] = data;
	ps->_size++;
	
	
}


// ɾ��˳�����posλ���ϵ�Ԫ��
void SeqListErase(PSeqList ps, int pos){
	if (pos<0 || pos>ps->_size){
		printf("λ����Ϣ����\n");
	}
	for (int i =pos+1; i<ps->_size; i++){
		ps->_pData[i - 1] = ps->_pData[i];
	}
	ps->_size--;
	
}


// ��˳�������dataԪ�ص�һ�γ��ֵ�λ��
int SeqListFind(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->_size; i++){
		if (ps->_pData[i] == data){
			return i;
		}
	}
	return -1;
}


// ɾ��˳�����ֵΪdata��Ԫ��
void SeqListRemove(PSeqList ps, DataType data){
	assert(ps);
	int pos = SeqListFind(ps,data);
	SeqListErase(ps, pos);
}


// ��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(PSeqList ps){
	assert(ps);
	return ps->_size;
}


// ��ȡ˳��������
int SeqListCapacity(PSeqList ps){
	assert(ps);
	return ps->_capacity;
}



// ��ȡ˳����е�һ��Ԫ��
DataType SeqListFront(PSeqList ps){
	assert(ps);
	return ps->_pData[0];
}

// ��ȡ˳��������һ��Ԫ��
DataType SeqListBack(PSeqList ps){
	assert(ps);
	return ps->_pData[ps->_size-1];
}


// ���˳�������ЧԪ�صĸ���
void SeqListClear(PSeqList ps){
	assert(ps);
	ps->_size = 0;
}

// ����˳���
void SeqListDestroy(PSeqList ps){
	assert(ps);
	if (ps->_pData){
		free(ps->_pData);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}


// �������
void CheckCapacity(PSeqList ps){
	assert(ps);
	if (ps->_size == ps->_capacity){
		int newCapacity = ps->_capacity * 2;

		DataType *pNew = (DataType *)malloc(sizeof(DataType));
		if (NULL == pNew){
			printf("�ڴ治��,����ʧ��!!!\n");
			exit(0);
		}
		memcpy(pNew, ps->_pData, sizeof(DataType));
	}

}



// ɾ��˳���������ֵΪdata��Ԫ��
void SeqListRemoveAll(PSeqList ps, DataType data){
	assert(ps);
	DataType *tmp = NULL;
	int count = 0;
	int i = 0;
#if 0
	for (i = 0; i < ps->size; i++){
		if (ps->data[i] == data){
			int j = 0;
			for (j = i; j < ps->size - 1; j++){
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			--i;
		}
	}
#endif


#if 0    //������ʱ�ռ�
	tmp = (DataType *)malloc(sizeof(DataType)*ps->size);
	if (tmp == NULL){
		exit(0);
	}
	for (i = 0; i < ps->size; i++){
		if (ps->data[i] != data){
			tmp[count++] = ps->data[i];
		}
	}
	memcpy(ps->data, tmp, count*sizeof(DataType));
	ps->size = count;
	free(tmp);
	tmp = NULL;
#endif

	for (i = 0; i < ps->_size; i++){
		if (ps->_pData[i] != data){
			ps->_pData[i - count] = ps->_pData[i];
		}
		else{
			count++;
		}
	}
	ps->_size -= count;
}





void Swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ��ð������ķ�ʽ��˳����е�Ԫ�ؽ�������
void BubbleSort(PSeqList ps){
	assert(ps);
	int flag = 0;
	if (ps->_size == 0){
		printf("˳���Ϊ��!!!\n");
	}
	else{
		for (int i = 0; i < ps->_size; i++){
			flag = 0;
			for (int j = 0; j<ps->_size - 1; j++){
				if (ps->_pData[j]>ps->_pData[j + 1]){
					Swap(ps->_pData + j, ps->_pData + j + 1);
					flag = 1;
				}
			}
			if (flag == 0){
				return;
			}
		}
	}
}
