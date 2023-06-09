#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef int Rank; //秩 
#define ListNodePosi(T) ListNode<T>* 

template <typename T> struct ListNode { //列表节点模板类（以双向链表形式实现） 
	// 成员 
    T data; ListNodePosi(T) pred; ListNodePosi(T) succ; //数值、前驱、后继  
	// 构造函数 
    ListNode() {} //针对 header 和 trailer的构造   
    ListNode ( T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL ) 
    	: data( e ), pred( p ), succ( s ) {} //默认构造器  
	// 操作接口  
    ListNodePosi(T) insertAsPred( T const& e ) //紧靠当前节点之前插入新节点  
    {
    	ListNodePosi(T) x = new ListNode (e, pred, this);
    	pred -> succ = x; pred = x;
    	return x;
	}
    ListNodePosi(T) insertAsSucc( T const& e ); //紧随当前节点之后插入新节点  
};

template <typename T> class Queue { //列表模板类  

 protected: 
    void init(); 
//	{ 
//		header = new ListNode<T>; 
//	    trailer = new ListNode<T>; 
//	    header -> succ = trailer; header -> pred = NULL; 
//	    trailer -> pred = header; trailer -> succ = NULL; 
//	    _size = 0; 
//			
//	}; //列表创建时的初始化  


    Rank clear(); //清除所有节点
    void copyNodes( ListNodePosi(T), Rank ); //复制列表中自位置p起的n项
    ListNodePosi(T) merge( ListNodePosi(T), Rank, Queue<T>&, ListNodePosi(T), Rank ); //归并
    void mergeSort( ListNodePosi(T)&, Rank ); //对从p开始连续的n个节点归并排序
    void selectionSort( ListNodePosi(T), Rank ); //对从p开始连续的n个节点选择排序
    void insertionSort( ListNodePosi(T), Rank ); //对从p开始连续的n个节点插入排序
    void radixSort( ListNodePosi(T), Rank ); //对从p开始连续的n个节点基数排序
 
 public:
    Rank _size; ListNodePosi(T) header; ListNodePosi(T) trailer; //规模、头哨兵、尾哨兵
 // 构造函数
    Queue() { init(); } //默认
    Queue( Queue<T> const& L ); //整体复制列表L
    Queue( Queue<T> const& L, Rank r, Rank n ); //复制列表L中自第r项起的 n项 
    Queue( ListNodePosi(T) p, Rank n ); //复制列表中自位置p起的n项 
    // 析构函数 
    //~Queue(){delete pred;delete succ;}; //释放（包含头、尾哨兵在内的）所有节点 
 // 只读访问接口
 
 // 新增三个函数效果 
	void enqueue(T const& e){
		insertAsLast( e );
	} 
	T dequeue(){
		return remove( first() );
	}
	T& front() {return first() -> data;}
    
 
    Rank size() const { return _size; } //规模
    bool empty() const { return _size <= 0; } //判空
    ListNodePosi(T) operator[]( Rank r ) const; //重载，支持循秩访问（效率低）
    ListNodePosi(T) first() const { return header->succ; } //首节点位置
    ListNodePosi(T) last() const { return trailer->pred; } //末节点位置
    bool valid( ListNodePosi(T) p ) //判断位置p是否对外合法
    { return p && ( trailer != p ) && ( header != p ); } //将头、尾节点等同于NULL
    ListNodePosi(T) find( T const& e ) const //无序列表查找
    { return find( e, _size, trailer ); }
    ListNodePosi(T) find( T const& e, Rank n, ListNodePosi(T) p ) const; //无序区间查找
    ListNodePosi(T) search( T const& e ) const //有序列表查找
    { return search( e, _size, trailer ); }
    ListNodePosi(T) search( T const& e, Rank n, ListNodePosi(T) p ) const; //有序区间查找
    ListNodePosi(T) selectMax( ListNodePosi(T) p, Rank n ); //在p及其n-个后继中选出最大者
    ListNodePosi(T) selectMax() { return selectMax( header->succ, _size ); } //整体最大者
 // 可写访问接口
    ListNodePosi(T) insertAsFirst( T const& e ); //将e当作首节点插入
    ListNodePosi(T) insertAsLast( T const& e ) //将e当作末节点插入 
    {
    	_size++; return trailer -> insertAsPred( e );
	}
    ListNodePosi(T) insert( ListNodePosi(T) p, T const& e ); //将e当作p的后继插入
    ListNodePosi(T) insert( T const& e, ListNodePosi(T) p ); //将e当作p的前驱插入
    T remove( ListNodePosi(T) p ) //删除合法位置p处的节点,返回被删除节点
    {
    	T e = p -> data;
    	p -> pred -> succ = p -> succ;
    	p -> succ -> pred = p -> pred;
    	delete p; _size++;
    	return e;
	}
    void merge( Queue<T>& L ) { merge( header->succ, _size, L, L.header->succ, L._size ); } //全列表归并
    void sort( ListNodePosi(T), Rank ); //列表区间排序
    void sort() { sort( first(), _size ); } //列表整体排序
    Rank deduplicate(); //无序去重
    Rank uniquify(); //有序去重
    void reverse(); //前后倒置（习题）
 // 遍历
    void traverse( void ( * )( T& ) ); //依次实施visit操作（函数指针）
    template <typename VST> void traverse( VST& ); //依次实施visit操作（函数对象）
    
    
    
    
 }; //Queue

template <typename T> void Queue<T>::init()
{
	    header = new ListNode<T>; 
	    trailer = new ListNode<T>; 
	    header -> succ = trailer; header -> pred = NULL; 
	    trailer -> pred = header; trailer -> succ = NULL; 
	    _size = 0; 
}
