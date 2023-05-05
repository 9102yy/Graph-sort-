#include<iostream>
#include<algorithm>
#define BinNodePosi(T) BinNode<T>* 
#define stature(p) ((p) ? (p)->height : -1) 

/******************************************************************************************
 * BinNode状态与性质的判断 
 ******************************************************************************************/
#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //至少拥有一个孩子
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //同时拥有两个孩子
#define IsLeaf(x) ( ! HasChild(x) )

/******************************************************************************************
 * 与BinNode具有特定关系的节点及指针
 ******************************************************************************************/
#define sibling( p ) ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc ) /*兄弟*/
#define uncle( x ) ( sibling( (x)->parent ) ) /*叔叔*/
#define FromParentTo( x ) /*来自父亲的引用*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )

template <typename T> struct BinNode { //二叉树节点模板类 
public:
   T data; //数值 
   BinNodePosi(T) parent;BinNodePosi(T) lc;BinNodePosi(T) rc; //父节点及左、右孩子  
   int height; //高度（通用） 
   int npl; //Null Path Length（左式堆，也可直接用 height代替） 
// 构造函数  
   BinNode() : data(NULL), parent( NULL ), lc( NULL ), rc( NULL ), height( 0 ), npl( 1 ){}
   BinNode( T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL,
            BinNodePosi(T)  rc = NULL, int h = 0, int l = 1)
      : data( e ), parent( p ), lc( lc ), rc( rc ), height( h ), npl( l ) {}
// 操作接口
   int size(); //统计当前节点后代总数，亦即以其为根的子树的规模
   BinNodePosi(T) insertAsLC( T const& e)
   {
   		return lc = new BinNode (e, this);
   } //作为当前节点的左孩子插入新节点
   BinNodePosi(T) insertAsRC( T const& e)
   {
   		return rc = new BinNode (e, this); 
   } //作为当前节点的右孩子插入新节点
   BinNodePosi(T) succ(); //取当前节点的直接后继
   template <typename VST> void travLevel( VST& ); //子树层次遍历
   template <typename VST> void travPre( VST& ); //子树先序遍历
   template <typename VST> void travIn( VST& ); //子树中序遍历
   template <typename VST> void travPost( VST& ); //子树后序遍历
// 比较器、判等器（各列其一，其余自行补充）
   bool operator< ( BinNode const& bn ) { return data < bn.data; } //小于
   bool operator== ( BinNode const& bn ) { return data == bn.data; } //等于
};
