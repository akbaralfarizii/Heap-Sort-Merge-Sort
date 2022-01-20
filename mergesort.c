#include "header.h"

void MergeMin(int data[], int left, int mid, int right){
	int i, j, k;
	
    int SubArray1 = mid - left + 1;
    int SubArray2 = right - mid;
    
    int LeftArray[SubArray1+1];
    int RightArray[SubArray2+1];
    
    for(i = 1; i <= SubArray1; i++)
        LeftArray[i] = data[left + i - 1];
    for(j = 1; j <= SubArray2; j++)
        RightArray[j] = data[mid+j];
        
    LeftArray[SubArray1+1] = INT_MAX;
    RightArray[SubArray2+1] = INT_MAX;
    i = 1;
	j = 1;
	
    for(k = left; k <= right ; k++){
        if (LeftArray[i] <= RightArray[j]){
            data[k] = LeftArray[i];
            i++;
        }else{
            data[k] = RightArray[j];
            j++;
        }
    }
}

void MergeSortMin(int data[], int left, int right){

    if(left < right){
    	
        int mid = (left+right)/2;
        MergeSortMin(data, left , mid);
        MergeSortMin(data, mid+1 , right);
		MergeMin(data, left, mid, right);
    }
}

void MergeMax(int data[], int left, int mid, int right){
	int i, j, k;
	
    int SubArray1 = mid - left + 1;
    int SubArray2 = right - mid;
    
    int LeftArray[SubArray1+1];
    int RightArray[SubArray2+1];
    
    for(i = 1; i <= SubArray1; i++)
        LeftArray[i] = data[left + i - 1];
    for(j = 1; j <= SubArray2; j++)
        RightArray[j] = data[mid+j];
        
    LeftArray[SubArray1+1] = INT_MIN;
    RightArray[SubArray2+1] = INT_MIN;
    i = 1;
	j = 1;
	
    for(k = left; k <= right ; k++){
        if (LeftArray[i] >= RightArray[j]){ 
            data[k] = LeftArray[i];
            i++;
        }else{
            data[k] = RightArray[j];
            j++;
        }
    }
}

void MergeSortMax(int data[], int left, int right){

    if(left < right){
    	
        int mid = (left+right)/2;
        MergeSortMax(data, left , mid);
        MergeSortMax(data, mid+1 , right);
        MergeMax(data, left, mid, right);
        
    }
}

