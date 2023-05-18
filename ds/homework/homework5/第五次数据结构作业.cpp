#include<bits/stdc++.h>
#include<time.h>
#define ClOCKS_PER_SEC 1000;
using namespace std;

//���峣��  
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


//��ӡ����Ԫ��  
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
//���������  
void generateRandomArray(int arr[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % N + 1;
    }
}

//�����鵹��
void reverseArray(int arr[], int n){
    int temp;
    for(int i = 0; i < n/2 ;i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

//˳�����  
void sequenceTest(){
	cout<<"˳�������:----------------------------------------"<<endl<<endl;
    //����˳������
    int arr[N];
    for(int i = 0; i < N;i++){
        arr[i] = i + 1;
    }

    //cout << "---------------" << endl;
    //cout << "����ǰ:" << endl;
    //printArray(arr, N);

    time_t start_time, end_time;

    //��������
    start_time=clock();
    bubbleSort(arr,N);
    end_time=clock();
    cout<<"��������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
   
    //��������
    generateRandomArray(arr, N);// ���ڲ���������Ҫ������������ٲ��ԣ��Է����ݹ���������Ч������
    start_time=clock();
    insertionSort(arr,N);
    end_time=clock();
    cout<<"��������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //ѡ������ 
    generateRandomArray(arr, N); //ͬ����Ҫ���¶��������
    start_time=clock();
    selectionSort(arr,N);
    end_time=clock();
    cout<<"ѡ������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //�鲢����  
    generateRandomArray(arr, N);
    start_time=clock();
    mergeSort(arr,0,N-1);
    end_time=clock();
    cout<<"�鲢����ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //��������  
    generateRandomArray(arr, N);
    start_time=clock();
    quickSort(arr,0,N-1);
    end_time=clock();
    cout<<"��������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //������  
    generateRandomArray(arr, N);
    start_time=clock();
    heapSort(arr,N);
    end_time=clock();
    cout<<"������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

}

//�������
void reverseTest(){
    cout<<"���������:----------------------------------------"<<endl;
    int arr[N];
    for(int i = 0; i < N;i++){
        arr[i] = N-i;
    }

    //���ԭʼ����Ԫ��
//    cout << "---------------" << endl;
//    cout << "����ǰ:" << endl;
//    printArray(arr, N);

    time_t start_time, end_time;

    //��������
    start_time=clock();
    bubbleSort(arr,N);
    end_time=clock();
    cout<<"��������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
   
    //��������
    start_time=clock();
    insertionSort(arr,N);
    end_time=clock();
    cout<<"��������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //ѡ������ 
    start_time=clock();
    selectionSort(arr,N);
    end_time=clock();
    cout<<"ѡ������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //�鲢����  
    start_time=clock();
    mergeSort(arr,0,N-1);
    end_time=clock();
    cout<<"�鲢����ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //��������  
    start_time=clock();
    quickSort(arr, 0, N-1);
    end_time=clock(); 
    cout<<"��������ʹ��ʱ��:"<<((double)( end_time - start_time ))/CLOCKS_PER_SEC<<endl;

    //������  
    start_time=clock();
    heapSort(arr,N);
    end_time=clock();
    cout<<"������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
}

//������
void randomTest(){
    int arr[N];
	cout<<"��������:----------------------------------------"<<endl<<endl;
    generateRandomArray(arr, N);

//    //���ԭʼ����Ԫ�� 
//    cout << "---------------" << endl;
//    cout << "����ǰ:" << endl;
//    printArray(arr, N);

    time_t start_time, end_time;

    //�������� 
    start_time=clock();
    bubbleSort(arr,N);
    end_time=clock();
    cout<<"��������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
   
    //�������� 
    generateRandomArray(arr, N);//���ڲ���������Ҫ������������ٲ��ԣ��Է����ݹ���������Ч������
    start_time=clock();
    insertionSort(arr,N);
    end_time=clock();
    cout<<"��������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //ѡ������  
    generateRandomArray(arr, N); //ͬ����Ҫ���¶��������
    start_time=clock();
    selectionSort(arr,N);
    end_time=clock();
    cout<<"ѡ������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //�鲢����  
    generateRandomArray(arr, N);
    start_time=clock();
    mergeSort(arr,0,N-1);
    end_time=clock();
    cout<<"�鲢����ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //��������  
    generateRandomArray(arr, N);
    start_time=clock();
    quickSort(arr,0,N-1);
    end_time=clock();
    cout<<"�������� ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;

    //������  
    generateRandomArray(arr, N);
    start_time=clock();
    heapSort(arr,N);
    end_time=clock();
    cout<<"������ʹ��ʱ��:"<<((double)(end_time-start_time))/CLOCKS_PER_SEC<<endl;
}

int main() {
    
    sequenceTest();  //˳�����
    reverseTest();   //�������
    randomTest();    //�������
       
    return 0;
}
