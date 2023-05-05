#include "BinNode.h" //引入二叉树节点类
template <typename T> class BinTree { //二叉树模板类
protected:
  
public:
	int _size; BinNodePosi(T) _root; //规模、根节点
    //virtual int updateHeight( BinNodePosi(T) x ); //更新节点x的高度
    //void updateHeightAbove( BinNodePosi(T) x ); //更新节点x及其祖先的高度
   
   BinTree()    //构造函数
   {
		_size = 0;
		//T temp;
   		//_root -> data = temp;
   }
   
   //~BinTree() { if ( 0 < _size ) remove( _root ); } //析构函数
   int size() const { return _size; } //规模
   bool empty() const { return !_root; } //判空
   BinNodePosi(T) root() const { return _root; } //树根 
   BinNodePosi(T) insertAsRoot( T const& e); //插入根节点  
   BinNodePosi(T) insertAsLC( T const& e, BinNodePosi(T) x); //插入左孩子 
   BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const& e); //插入右孩子 
   
   // 重点   
   BinNodePosi(T) attachAsLC(BinNodePosi(T) x ,BinTree<T>* & S) //接入左子树 
   {
   		if(x -> lc == S -> root) x -> lc -> parent = x;
   		_size += S -> _size; updateHeightAbove(x);
   		S -> _root = NULL; S -> _size = 0;
//		    delete(S); 
			S = NULL; 
		   return x;
   }
   BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* & S) //接入右子树 
   {
   		if(x -> rc == S -> root) x -> rc -> parent = x;
   		_size += S -> _size; 
		   //updateHeightAbove(x);
   		S -> _root = NULL; S -> _size = 0; release(S); S = NULL; return x;
   }
   
   int remove ( BinNodePosi(T) x) //子树删除
   {
   		FromParentTo( *x ) = NULL;
   		//updateHeightAbove(x -> parent);
   		int n = removeAt(x); _size = n;
   		return n;
   }
   int removeAt(BinNodePosi(T) x){
   	if(!x) return 0;
   	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    //  delete(x->data); delete(x); 
	return n;
   }
   BinTree<T>* secede ( BinNodePosi(T) ); //子树分离
   
   
   
   template <typename VST> //操作器
   void travLevel( VST& visit ) { if ( _root ) _root->travLevel( visit ); } //层次遍历
   template <typename VST> //操作器
   void travPre( VST& visit ) { if ( _root ) _root->travPre( visit ); } //先序遍历
   template <typename VST> //操作器
   void travIn( VST& visit ) { if ( _root ) _root->travIn( visit ); } //中序遍历
   template <typename VST> //操作器
   void travPost( VST& visit ) { if ( _root ) _root->travPost( visit ); } //后序遍历
   bool operator<( BinTree<T> const& t ) //比较器（其余自行补充）
      { return _root && t._root && lt( _root, t._root ); }
   bool operator==( BinTree<T> const& t ) //判等器
      { return _root && t._root && ( _root == t._root ); }
}; //BinTree
