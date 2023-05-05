#include "BinNode.h" //引入二叉树节点类
template <typename T> class HuffTree { //二叉树模板类
public:
	int _size; BinNodePosi(T) _root; //规模、根节点 
	
   HuffTree()    //构造函数  
   {
		_size = 0; 
		_root -> data = NULL; 
   }
   int size() const { return _size; } //规模 
   bool empty() const { return !_root; } //判空 
   BinNodePosi(T) root() const { return _root; } //树根  
   BinNodePosi(T) insertAsRoot( T const& e); //插入根节点  
   BinNodePosi(T) insertAsLC( T const& e, BinNodePosi(T) x); //插入左孩子 
   BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const& e); //插入右孩子 
   
   // 重点   
   BinNodePosi(T) attachAsLC(BinNodePosi(T) x ,HuffTree<T>* & S) //接入左子树 
   {
   		if(x -> lc == S -> root) x -> lc -> parent = x; 
   		_size += S -> _size; updateHeightAbove(x); 
   		S -> _root = NULL; S -> _size = 0; 
//		    delete(S); 
			S = NULL; 
		   return x; 
   }
   BinNodePosi(T) attachAsRC(BinNodePosi(T) x, HuffTree<T>* & S) //接入右子树 
   {
   		if(x -> rc == S -> root) x -> rc -> parent = x;
   		_size += S -> _size; 
   		S -> _root = NULL; S -> _size = 0; release(S); S = NULL; return x;
   }
   
   int remove ( BinNodePosi(T) x) //子树删除
   {
   		FromParentTo( *x ) = NULL;
   		int n = removeAt(x); _size = n;
   		return n;
   }
   int removeAt(BinNodePosi(T) x){
   	if(!x) return 0;
   	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    //  delete(x->data); delete(x); 
	return n;
   }
   HuffTree<T>* secede ( BinNodePosi(T) ); //子树分离  
   
   bool operator<( HuffTree<T> const& t ) //比较器（其余自行补充）
      { return _root && t._root && lt( _root, t._root ); }
   bool operator==( HuffTree<T> const& t ) //判等器  
      { return _root && t._root && ( _root == t._root ); }
}; //BinTree
