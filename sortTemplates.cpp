void bubbleSort(int array[], int len) {
	// 循环的次数为数组长度减一，剩下的一个数不需要排序
	for(int i=0; i<len-1; ++i)  {
		bool noswap=true;
		// 循环次数为待排序数第一位数冒泡至最高位的比较次数
		for(int j=0;j<len-i-1;++j) {
			if(array[j]>array[j+1]) {
				array[j]=array[j]+array[j+1];
				array[j+1]=array[j]-array[j+1];
				array[j]=array[j]-array[j+1];
				// 交换或者使用如下方式
				//a=a^b;
				//b=b^a;
				//a=a^b;
				noswap=false;
			}
		}
		if(noswap) break;
	}
}

//@brief: Shell排序
//@param: A：输入数组，len:数组长度，d:初始增量(分组数)
void shellSort(int A[],int len, int d) {
	//循环的次数为增量缩小至1的次数
	for(int inc=d;inc>0;inc/=2)
	{
		for(int i=inc;i<len;++i)
		{       
			//循环的次数为第一个分组的第二个元素到数组的结束
			int j=i-inc;
			int temp=A[i];
			while(j>=0&&A[j]>temp)
			{
				A[j+inc]=A[j];
				j=j-inc;
			}

			//防止自我插入
			if((j+inc)!=i)
			{
				A[j+inc]=temp;//插入记录
			}
		}
	}
}

//快速排序
//@param: a:待排序数组 low:最低位的下标 high:最高位的下标
void quickSort(int a[],int low, int high) {
	if(low>=high) return;

	int left=low;
	int right=high;
	int key=a[left];    // 用数组的第一个记录作为分界值

	// 第一趟排序
	while( left != right) {
		// 从右向左扫描，找第一个值小于 key 的记录，并放到 key 的位置
		while(left<right&&a[right]>=key) --right;
		a[left]=a[right];

		// 从左向右扫描，找第一个码值大于 key 的记录，并交换到右边下标为 right 的位置
		while(left<right&&a[left]<=key) ++left;
		a[right]=a[left];
	}
	a[left]=key;    			// 分区元素放到正确位置
	
	quickSort(a,low,left-1);	// 重复对左边分区的处理
	quickSort(a,left+1,high);	// 重复对右边分区的处理
}

//@brief: 插入排序
//@param: A：输入数组 len：数组长度
void insertSort(int A[], int len) {
	int tmp;
	for ( int i=1; i<len; i++ )
	{
	  int j=i-1;
      tmp=A[i]; 
	  //查找到要插入的位置
	  while( j >= 0 && A[j] > tmp)
	  {
          A[j+1]=A[j];
		  j--;
	  }
	  A[j+1]=tmp;	//插入到正确位置
	}
}

void selectSort(int A[],int len) {
	int i,j,k;
	for(i=0;i<len;i++){
       k=i;
	   for(j=i+1;j<len;j++){
		   if(A[j]<A[k])
			   k=j;
	   }
	   if(i!=k){
           A[i]=A[i]+A[k];
           A[k]=A[i]-A[k];
		   A[i]=A[i]-A[k];
	   }
	}
}

/************************************************
*函数名称:mergearray
*参数：a：待归并数组；first：开始下标；mid：中间下标；
*     last：结束下标；temp：临时数组
*说明：将有二个有序数列a[first...mid]和a[mid...last]合并 
*************************************************/
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1,k =0;    
    while (i <= mid && j <= last)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }    
    while (i<= mid)  
        temp[k++] = a[i++];  
      
    while (j <= last)  
        temp[k++] = a[j++];   
    for (i=0; i < k; i++)  
        a[first+i] = temp[i];  
}  
/************************************************
*函数名称:mergesort
*参数：a：待归并数组；first：开始下标；
*     last：结束下标；temp：临时数组
*说明：实现给定数组区间的二路归并排序 
*************************************************/
void mergesort(int a[], int first, int last, int temp[])  
{  
    
    if (first < last)  
    {  
        int mid = (first + last) / 2; 		
        mergesort(a, first, mid, temp);    //左边有序  
        mergesort(a, mid + 1, last, temp); //右边有序  
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并      
    }  
}
