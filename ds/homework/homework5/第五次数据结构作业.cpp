#include<bits/stdc++.h>
#include<time.h>
#define ClOCKS_PER_SEC 1000;
using namespace std;

//定义常量  
#define N 30000

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
         }
     }
}

void insertionSort(int arr[], int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n){
    int minIndex;
    for(int i = 0; i < n-1; i++){
        minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }
    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


//打印数组元素  
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
//生成随机数  
void generateRandomArray(int arr[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % N + 1;
    }
}

//将数组倒置
void reverseArray(int arr[], int n){
    int temp;
    for(int i = 0; i < n/2 ;i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

//顺序情况  
void sequenceTest(){
	cout<<"顺序情况下:----------------------------------------"<<endl<<endl;
    //生成顺序数组
    int arr[N];
    for(int i = 0; i < N;i++){
        arr[i] = i + 1;
    }

    //cout << "---------------" << endl;
    //cout << "排序前:" << endl;
    //printArray(arr, N);

    time_t start_time, end_time;

    //起泡排序
    start_time=clock();
    bubbleSort(arr,N);
    end_time=clock();
    cout<<"起泡排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
   
    //插入排序
    generateRandomArray(arr, N);// 对于插入排序，需要打乱随机序列再测试，以防数据过于有序导致效率提升
    start_time=clock();
    insertionSort(arr,N);
    end_time=clock();
    cout<<"插入排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //选择排序 
    generateRandomArray(arr, N); //同理需要重新定义随机数
    start_time=clock();
    selectionSort(arr,N);
    end_time=clock();
    cout<<"选择排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //归并排序  
    generateRandomArray(arr, N);
    start_time=clock();
    mergeSort(arr,0,N-1);
    end_time=clock();
    cout<<"归并排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //快速排序  
    generateRandomArray(arr, N);
    start_time=clock();
    quickSort(arr,0,N-1);
    end_time=clock();
    cout<<"快速排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //堆排序  
    generateRandomArray(arr, N);
    start_time=clock();
    heapSort(arr,N);
    end_time=clock();
    cout<<"堆排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

}

//逆序情况
void reverseTest(){
    cout<<"逆序情况下:----------------------------------------"<<endl;
    int arr[N];
    for(int i = 0; i < N;i++){
        arr[i] = N-i;
    }

    //输出原始数组元素
//    cout << "---------------" << endl;
//    cout << "排序前:" << endl;
//    printArray(arr, N);

    time_t start_time, end_time;

    //起泡排序
    start_time=clock();
    bubbleSort(arr,N);
    end_time=clock();
    cout<<"起泡排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
   
    //插入排序
    start_time=clock();
    insertionSort(arr,N);
    end_time=clock();
    cout<<"插入排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //选择排序 
    start_time=clock();
    selectionSort(arr,N);
    end_time=clock();
    cout<<"选择排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //归并排序  
    start_time=clock();
    mergeSort(arr,0,N-1);
    end_time=clock();
    cout<<"归并排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //快速排序  
    start_time=clock();
    quickSort(arr, 0, N-1);
    end_time=clock(); 
    cout<<"快速排序使用时间:"<<((double)( end_time - start_time ))/CLOCKS_PER_SEC<<endl;

    //堆排序  
    start_time=clock();
    heapSort(arr,N);
    end_time=clock();
    cout<<"堆排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
}

//随机情况
void randomTest(){
    int arr[N];
	cout<<"随机情况下:----------------------------------------"<<endl<<endl;
    generateRandomArray(arr, N);

//    //输出原始数组元素 
//    cout << "---------------" << endl;
//    cout << "排序前:" << endl;
//    printArray(arr, N);

    time_t start_time, end_time;

    //起泡排序 
    start_time=clock();
    bubbleSort(arr,N);
    end_time=clock();
    cout<<"起泡排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
   
    //插入排序 
    generateRandomArray(arr, N);//对于插入排序，需要打乱随机序列再测试，以防数据过于有序导致效率提升
    start_time=clock();
    insertionSort(arr,N);
    end_time=clock();
    cout<<"插入排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //选择排序  
    generateRandomArray(arr, N); //同理需要重新定义随机数
    start_time=clock();
    selectionSort(arr,N);
    end_time=clock();
    cout<<"选择排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //归并排序  
    generateRandomArray(arr, N);
    start_time=clock();
    mergeSort(arr,0,N-1);
    end_time=clock();
    cout<<"归并排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //快速排序  
    generateRandomArray(arr, N);
    start_time=clock();
    quickSort(arr,0,N-1);
    end_time=clock();
    cout<<"快速排序 使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //堆排序  
    generateRandomArray(arr, N);
    start_time=clock();
    heapSort(arr,N);
    end_time=clock();
    cout<<"堆排序使用时间:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
}

int main() {
    
    sequenceTest();  //顺序测试
    reverseTest();   //逆序测试
    randomTest();    //随机测试
       
    return 0;
}
